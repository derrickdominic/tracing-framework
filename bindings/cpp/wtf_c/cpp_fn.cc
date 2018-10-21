#include "cpp_fn.h"

#include <iostream>

extern "C" void c_fn(const char* str) {
  cpp_fn(std::string(str));
}

void cpp_fn(const std::string& str) {
  std::cout << str << std::endl;
}
