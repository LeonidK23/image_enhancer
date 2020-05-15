#include "Image.hpp"
#include "SauvolaFilter.hpp"

#include <iostream>

SauvolaFilter::SauvolaFilter(){
  this->window_size = 15;
}

SauvolaFilter::SauvolaFilter(int window_size){
  this->window_size = window_size;
}

Image SauvolaFilter::filter(Image img){
  int m, n;
  int img_size;
  int wnd_size;
  int* image_arr;
  std::vector<int> image_vec;
  std::vector<int> shape;

  image_vec = img.getData();
  img_size = image_vec.size();
  image_arr = new int[img_size];
  wnd_size = this->window_size;
  shape = img.getShape();
  m = shape[0];
  n = shape[1];

  std::copy(image_vec.begin(), image_vec.end(), image_arr);

  for (int i = wnd_size; i < m - wnd_size; i++){
    for (int j = wnd_size; j < n - wnd_size; j++){
      std::cout << i << " " << j << '\n';
    }
  }

}
