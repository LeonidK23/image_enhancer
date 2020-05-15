#define CATCH_CONFIG_MAIN

#include <iostream>

#include "catch.hpp"
#include "Image.hpp"
#include "ImageReader.hpp"
#include "SauvolaFilter.hpp"

TEST_CASE("Image Reader and Image Classes", ""){
  Image im{};
  Image filtered_im{};
  ImageReader reader{};
  im = reader.read("../data/test.txt");

  // REQUIRE(im.getData() == std::vector<int> {89, 31, 25, 54, 1, 9, 100, 254, 198});
  REQUIRE(im.getName() == "test");

  SauvolaFilter sF{1};
  filtered_im = sF.filter(im);
}
