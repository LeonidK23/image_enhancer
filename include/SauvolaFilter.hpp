#include "Image.hpp"
#include "ImageFilter.hpp"

class SauvolaFilter: public ImageFilter{
private:
  std::vector<int> getWindowFrame(int*, int, int, int);
public:
  SauvolaFilter();
  SauvolaFilter(int);
  Image filter(Image);
};
