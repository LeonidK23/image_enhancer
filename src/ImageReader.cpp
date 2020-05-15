#include <fstream>
#include <string>
#include <vector>
#include <iostream>

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

void ImageReader::write(Image img, int N){
  std::ofstream myfile;
  std::string filename ("../data/" + img.getName() + ".txt");
  myfile.open(filename);

  std::vector<int> img_vec = img.getData();
  int m = img_vec.size() / N;

  for (int i = 0; i < m; i++){
    for (int j = 0; j < N; j++)
      myfile << img_vec[i*N + j] << ' ';
    myfile << '\n';
  }
}
