#include <fstream>
#include <string>
#include <vector>

#include "Image.hpp"
#include "ImageReader.hpp"

Image ImageReader::read(std::string file_path){
  Image img{};
  int num;

  std::ifstream inputFile(file_path);
  std::vector<int> data;

  while (inputFile >> num){
    data.push_back(num);
  }

  int filename_begin = file_path.find_last_of("/\\") + 1;
  int filename_end = file_path.find_last_of(".");
  std::string file_name = file_path.substr(filename_begin, filename_end - filename_begin);
  img.setName(file_name);
  img.setData(data);

  return img;
}
