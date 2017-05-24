// Copyright 2017 Kiparenko Ilya

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "include/interpolation_search_app.h"

int main(int argc, const char** argv) {
  printf("MainArgs ");
  for (int i = 0; i < argc; i++)
    printf("[%s] ", argv[i]);
  printf("\n");
  InterpolationSearchApp app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
