#define CATCH_CONFIG_MAIN

#include <iostream>
#include <chrono>

using std::chrono::system_clock;
using std::chrono::duration;

#include "catch.hpp"
#include "Image.hpp"
#include "ImageReader.hpp"
#include "SauvolaFilter.hpp"

TEST_CASE("Image Reader and Image Classes", ""){
  Image im{};
  Image filtered_im{};
  ImageReader reader{};
  im = reader.read("../data/page_photo.txt");

  // REQUIRE(im.getData() == std::vector<int> {89, 31, 25, 54, 1, 9, 100, 254, 198});
  REQUIRE(im.getName() == "page_photo");

  SauvolaFilter sF{15};
  auto start = system_clock::now();
  filtered_im = sF.filter(im);
  auto end = system_clock::now();
  std::cout << duration<double>(end - start).count() << '\n';

  reader.write(filtered_im, 613);
}
