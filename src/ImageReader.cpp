#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "Image.hpp"
#include "ImageReader.hpp"

Image ImageReader::read(std::string filePath){
  int num;
  int filenameBegin;
  int filenameEnd;
  std::string fileName;
  Image img{};

  // convert png to txt using python script
  std::string script = "python ../auxiliary/convert_png_to_txt.py";
  std::system((script + " " + filePath).c_str());

  std::string txtFilePath = filePath.substr(0, filePath.find_last_of(".")) + ".txt";

  // read txt file
  std::ifstream inputFile(txtFilePath);
  std::vector<int> data;

  while (inputFile >> num){
    data.push_back(num);
  }

  inputFile.close();
  std::remove(txtFilePath.c_str());

  filenameBegin = filePath.find_last_of("/\\") + 1;
  filenameEnd = filePath.find_last_of(".");
  fileName = filePath.substr(filenameBegin, filenameEnd - filenameBegin);

  img.setName(fileName);
  img.setData(data);

  return img;
}

void ImageReader::write(Image img, int N){
  std::ofstream outFile;
  std::string filePath ("../imgs/" + img.getName() + ".txt");
  outFile.open(filePath);

  std::vector<int> img_vec = img.getData();
  int m = img_vec.size() / N;

  for (int i = 0; i < m; i++){
    for (int j = 0; j < N; j++)
      outFile << img_vec[i*N + j] << ' ';
    outFile << '\n';
  }

  outFile.close();

  // convert png to txt using python script
  std::string script = "python ../auxiliary/convert_txt_to_png.py";
  std::system((script + " " + filePath).c_str());
  std::remove(filePath.c_str());
}
