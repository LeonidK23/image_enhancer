#include "Image.hpp"
#include "ImageFilter.hpp"

ImageFilter::ImageFilter(){
  this->window_size = 15;
}

ImageFilter::ImageFilter(int window_size){
  this->window_size = window_size;
}
