#include <vector>
#include <string>

#include "Image.hpp"

void Image::setName(std::string name){
  this->name = name;
}

void Image::setData(std::vector<int> data){
  this->data = data;
}

std::string Image::getName(){
  return this->name;
}

std::vector<int> Image::getData(){
  return this->data;
}
