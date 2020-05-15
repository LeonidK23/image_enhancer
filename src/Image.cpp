#include <vector>
#include <string>

#include "Image.hpp"

void Image::setName(std::string name){
  this->name = name;
}

void Image::setData(std::vector<int> data){
  this->data = data;
}

void Image::setData(std::vector<int> data, int m, int n){
  this->data = data;
  this->m = m;
  this->n = n;
}

std::string Image::getName(){
  return this->name;
}

std::vector<int> Image::getData(){
  return this->data;
}

std::vector<int> Image::getShape(){
  return std::vector<int> {this->m, this->n};
}

Image::Image(){}

Image::Image(std::vector<int> data): data(data){}

Image::Image(std::string name, std::vector<int> data): data(data), name(name){}
