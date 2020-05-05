#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

class Image {
private:
  std::string name;
  std::vector<int> data;
public:
  void setName(std::string);
  void setData(std::vector<int>);
  std::vector<int> getData();
  std::string getName();
};

#endif
