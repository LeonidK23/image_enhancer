#include <fstream>
#include <string>
#include <vector>

#include "Image.hpp"
#include "ImageReader.hpp"

Image ImageReader::read(std::string filePath){
  int num;
  int filenameBegin;
  int filenameEnd;
  std::string fileName;
  Image img{};

  std::ifstream inputFile(filePath);
  std::vector<int> data;

  while (inputFile >> num){
    data.push_back(num);
  }

  filenameBegin = filePath.find_last_of("/\\") + 1;
  filenameEnd = filePath.find_last_of(".");
  fileName = filePath.substr(filenameBegin, filenameEnd - filenameBegin);

  img.setName(fileName);
  img.setData(data);

  return img;
}
