#ifndef IMAGEFILTER_H
#define IMAGEFILTER_H

#include "Image.hpp"

class ImageFilter {
protected:
  int window_size = 15;
public:
  ImageFilter();
  ImageFilter(int);
  virtual Image filter(Image) =0;
};

#endif
