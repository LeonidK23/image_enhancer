#include "Image.hpp"
#include "ImageFilter.hpp"

class SauvolaFilter: public ImageFilter{
private:
  double k;
private:
  std::vector<int> getWindowFrame(int*, int, int, int);
public:
  SauvolaFilter();
  SauvolaFilter(int);
  SauvolaFilter(int, double);
  Image filter(Image);
};
