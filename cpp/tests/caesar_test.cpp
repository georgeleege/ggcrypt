#include "substitution.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Caesar shift of 0 returns same", "[caesar]") {
  REQUIRE(caesar_shift(0, "Hello World!") == "Hello World!");
}

TEST_CASE("Caesar shift of 1", "[caesar]") {
  REQUIRE(caesar_shift(1, "Hello World!") == "Ifmmp!Xpsme\"");
}

TEST_CASE("Caesar shift of -1", "[caesar]") {
  REQUIRE(caesar_shift(-1, "Ifmmp!Xpsme\"") == "Hello World!");
}

// There are 95 printable ASCII characters
TEST_CASE("Caesar shift of 95", "[caesar]") {
  REQUIRE(caesar_shift(95, "Hello World!") == "Hello World!");
}

TEST_CASE("Caesar shift of 94", "[caesar]") {
  REQUIRE(caesar_shift(94, "Hello World!") == "Gdkkn~Vnqkc ");
}

TEST_CASE("Caesar shift of -94", "[caesar]") {
  REQUIRE(caesar_shift(-94, "Gdkkn~Vnqkc ") == "Hello World!");
}

TEST_CASE("Caesar shift of 96", "[caesar]") {
  REQUIRE(caesar_shift(96, "Hello World!") == "Ifmmp!Xpsme\"");
}

TEST_CASE("Caesar shift of -96", "[caesar]") {
  REQUIRE(caesar_shift(-96, "Ifmmp!Xpsme\"") == "Hello World!");
}

TEST_CASE("Caesar shift testing bounds", "[caesar]") {
  REQUIRE(caesar_shift(94, "~~~~~") == "}}}}}");
}

TEST_CASE("Caesar shift of testing bounds decrypt", "[caesar]") {
  REQUIRE(caesar_shift(-94, "}}}}}") == "~~~~~");
}

// tests for when characters are out not printable
// e.g.\r\n

TEST_CASE("Caesar shift of newline with key 0", "[caesar]") {
  REQUIRE(caesar_shift(0, "\n") == "\n");
}

TEST_CASE("Caesar shift of newline with key 1", "[caesar]") {
  REQUIRE(caesar_shift(1, "\n") == "\n");
}

TEST_CASE("Caesar shift with newline of 0 returns same", "[caesar]") {
  REQUIRE(caesar_shift(0, "Hello\r\nWorld!") == "Hello\r\nWorld!");
}

TEST_CASE("Caesar shift with newline of 1", "[caesar]") {
  REQUIRE(caesar_shift(1, "Hello\r\nWorld!") == "Ifmmp\r\nXpsme\"");
}

TEST_CASE("Caesar shift with newline  of -1", "[caesar]") {
  REQUIRE(caesar_shift(-1, "Ifmmp\r\nXpsme\"") == "Hello\r\nWorld!");
}
