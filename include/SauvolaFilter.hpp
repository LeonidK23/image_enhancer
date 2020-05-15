#include "Image.hpp"
#include "ImageFilter.hpp"

class SauvolaFilter: public ImageFilter{
public:
  SauvolaFilter();
  SauvolaFilter(int);
  Image filter(Image);
};
