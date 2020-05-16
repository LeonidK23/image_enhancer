#define CATCH_CONFIG_MAIN

#include <iostream>
#include <chrono>

#include "catch.hpp"
#include "Image.hpp"
#include "ImageReader.hpp"
#include "SauvolaFilter.hpp"

using std::chrono::system_clock;
using std::chrono::duration;

TEST_CASE("Image Reader and Image Classes", ""){
  Image im{};
  Image filtered_im{};
  ImageReader reader{};
  im = reader.read("../imgs/page_photo.png");

  REQUIRE(im.getName() == "page_photo");

  SauvolaFilter sF{15, 0.1};
  auto start = system_clock::now();
  filtered_im = sF.filter(im);
  auto end = system_clock::now();
  std::cout << duration<double>(end - start).count() << '\n';

  reader.write(filtered_im, 613);
}
