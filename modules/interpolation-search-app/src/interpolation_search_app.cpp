/*

// Copyright 2017 Yashkov Vladislav + Kiparenko Ilya

#include <stdio.h>
#include <stdlib.h>
#include <cstdint>
#include <limits>
#include <string>
#include <vector>
#include "include/interpolation_search.h"

using std::string;

bool parseInt(const char* s, int* result) {
  char* err = 0;
  int64_t i = strtol(s, &err, 0);
  if (!err[0] &&
      i > std::numeric_limits<int>::min() &&
      i < std::numeric_limits<int>::max()) {
    *result = static_cast<int>(i);
    return true;
  }
  return false;
}

string InterpolationSearchApp:operator() (int argc, const char** argv) {
  if (argc == 1) {
    return help_message_;
  }
  if (argc == 2) {
    return "ERROR: Should be at least 2 arguments\n";
  }
  int length = argc - 1;  // all except first
  std::vector<int> data(length);

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

  bool isSorted = InterpolationSearch::isArrayValid(&data[0], length);
  if (!isSorted) {
    return "ERROR: Array is unsorted\n";
  }
  int result = InterpolationSearch::Search(key, &data[0], length);

  return "Result = " %i\n", result);
  return 0;
}

*/



// Copyright 2017 Kiparenko Ilya

#include "include/interpolation_search.h"
#include "include/interpolation_search_app.h"

#include <stdint.h>
#include <string>
#include <vector>
#include <limits>

InterpolationSearchApp::InterpolationSearchApp() : message_("") {}

void InterpolationSearchApp::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is a interpolation search app\n" +
    "Use \n\t$ " + appname + " <array> <item>\n" +
    "Where <array> is array of integers, and <item> is what you want to find\n";
}

bool InterpolationSearchApp::validateNumberOfArguments(int argc,
                                                       const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc < 3) {
    help(argv[0], "ERROR: Should be at least 2 arguments.\n\n");
    return false;
  }
  return true;
}

int parseInt(const char* arg) {
  char* end;
  int64_t value = strtol(arg, &end, 0);

  if (end[0] ||
      value < std::numeric_limits<int>::min() ||
      value > std::numeric_limits<int>::max()) {
    throw std::string("ERROR: Wrong number format! ") + arg;
  }

  return static_cast<int>(value);
}

std::string InterpolationSearchApp::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }

  std::vector<int> data;
  int key;
  int length;

  try {
    length = argc - 2;
    data.reserve(length);

    for (int i = 0; i < length; i++)
      data[i] = parseInt(argv[i + 1]);

    key = parseInt(argv[length + 1]);
  }
  catch(std::string& str) {
      return str;
  }

  bool isSorted = InterpolationSearch::isArrayValid(&data[0], length);
  if (!isSorted) {
    return "ERROR: Array is unsorted\n";
  }

  int result = InterpolationSearch::Search(key, &data[0], length);
  return "Result = " + std::to_string(result);
}
