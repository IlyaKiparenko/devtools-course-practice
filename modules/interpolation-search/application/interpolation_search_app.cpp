// Copyright 2017 Yashkov Vladislav + Kiparenko Ilya

#include <stdio.h>
#include <string>
#include "include/interpolation_search.h"

using std::string;

const char help_message[] =
  "This is a interpolation search app\n"
  "Use interpolation-search <array> <item>\n"
  "Where <array> is array of integers, and <item> is what you want to find\n";

bool parseInt(const char* s, int* result) {
  char* err = 0;
  int64_t i = strtol(s, &err, 0);
  if (!err[0] && i > INT_MIN && i < INT_MAX) {
    *result = static_cast<int>(i);
    return true;
  }
  return false;
}

int main(int argc, const char** argv) {
  if (argc == 1) {
    printf("%s", help_message);
    return 0;
  }
  if (argc == 2) {
    printf("ERROR: Should be at least 2 arguments\n");
    return 1;
  }
  int length = argc - 1;  // all except first and last
  int* data = new int[length];

  for (int i = 0; i < length; i++) {
    int cur = 0;
    if (parseInt(argv[i + 1], &cur)) {
      data[i] = cur;
    } else {
      printf("ERROR: Wrong number format [%s]\n", argv[i + 1]);
      return 1;
    }
  }

  int key = data[length - 1];
  length--;

  bool isSorted = InterpolationSearch::isArrayValid(data, length);
  if (!isSorted) {
    printf("ERROR: Array is unsorted\n");
    return 1;
  }
  int result = InterpolationSearch::Search(key, data, length);

  printf("Result = %i\n", result);
  return 0;
}
