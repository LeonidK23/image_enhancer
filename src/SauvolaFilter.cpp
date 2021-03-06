#include <iostream>
#include <numeric>
#include <cmath>
#include <omp.h>

#include "Image.hpp"
#include "SauvolaFilter.hpp"

SauvolaFilter::SauvolaFilter(){
  this->window_size = 15;
  this->k = 0.1;
}

SauvolaFilter::SauvolaFilter(int window_size){
  this->window_size = window_size;
  this->k = 0.1;
}

SauvolaFilter::SauvolaFilter(int window_size, double k){
  this->window_size = window_size;
  this->k = k;
}

Image SauvolaFilter::filter(Image img){
  int m, n;
  int img_size;
  int wnd_size;
  int* image_arr;
  std::vector<int> image_vec;
  std::vector<int> shape;
  std::vector<int> pixel_coords;
  std::vector<int> total_filtered_vec;

  image_vec = img.getData();
  img_size = image_vec.size();
  image_arr = new int[img_size];
  wnd_size = this->window_size;
  shape = img.getShape();
  m = shape[0];
  n = shape[1];

  std::copy(image_vec.begin(), image_vec.end(), image_arr);

  #pragma omp parallel
  {
    int n_threads;
    double mean, std, sq_sum;
    double sauvola_threshold;
    int current_pixel;

    std::vector<int> filtered_image_vec;
    std::vector<int> window_frame;

    n_threads = omp_get_num_threads();
    filtered_image_vec.reserve((m - 2*wnd_size)*(n - 2*wnd_size)/n_threads);

    #pragma omp for
    for (int i = wnd_size; i < m - wnd_size; i++){
      for (int j = wnd_size; j < n - wnd_size; j++){
        window_frame = this->getWindowFrame(image_arr, i, j, n);

        mean = std::accumulate(window_frame.begin(), window_frame.end(), 0) / window_frame.size();
        sq_sum = std::inner_product(window_frame.begin(), window_frame.end(), window_frame.begin(), 0.0);
        std = std::sqrt(sq_sum / window_frame.size() - mean * mean);
        sauvola_threshold = mean*(1 - this->k*(1 - std/128));
        current_pixel = window_frame[wnd_size*(wnd_size*2 + 1) + wnd_size];

        filtered_image_vec.push_back(255*(current_pixel > sauvola_threshold));
      }
    }


    for (int i = 0; i < n_threads; i++){
      #pragma omp barrier
      if (omp_get_thread_num() == i){
        total_filtered_vec.insert(total_filtered_vec.end(), filtered_image_vec.begin(), filtered_image_vec.end());
      }
    }
  }

  Image filtered_image {img.getName() + "_filtered", total_filtered_vec};

  return filtered_image;
}


std::vector<int> SauvolaFilter::getWindowFrame(int* img_arr, int i_coord, int j_coord, int N){
  int window_frame_size;
  int window_size_dim;
  int global_idx;
  std::vector<int> window_frame;

  window_size_dim = this->window_size * 2 + 1;
  window_frame_size = window_size_dim*window_size_dim;

  window_frame.reserve(window_frame_size);

  for (int i = i_coord - this->window_size; i <= i_coord + this->window_size; i++){
    for (int j = j_coord - this->window_size; j <= j_coord + this->window_size; j++){
      global_idx = j + i*N;
      window_frame.push_back(img_arr[global_idx]);
    }
  }

  return window_frame;
}
