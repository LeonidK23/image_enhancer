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

Image::Image(){}

Image::Image(std::vector<int> data): data(data){}

Image::Image(std::string name, std::vector<int> data): data(data), name(name){}
