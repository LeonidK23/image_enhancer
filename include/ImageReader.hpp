#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <string>

#include "Image.hpp"

class ImageReader{
public:
  Image read(std::string filepath);
  void write(Image, int);
};

#endif
