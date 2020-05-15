#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

class Image {
private:
  std::string name;
  std::vector<int> data;
  int m = 493, n = 643;
public:
  Image();
  Image(std::vector<int>);
  Image(std::string, std::vector<int>);
  void setName(std::string);
  void setData(std::vector<int>);
  void setData(std::vector<int>, int, int);
  std::vector<int> getData();
  std::string getName();
  std::vector<int> getShape();
};

#endif
