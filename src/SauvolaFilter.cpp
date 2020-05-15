#include "Image.hpp"
#include "SauvolaFilter.hpp"

SauvolaFilter::SauvolaFilter(){
  this->window_size = 15;
}

SauvolaFilter::SauvolaFilter(int window_size){
  this->window_size = window_size;
}

Image SauvolaFilter::filter(Image img){
  Image filtered_image{};

  return filtered_image;
}
