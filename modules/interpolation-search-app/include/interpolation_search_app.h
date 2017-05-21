/*

// Copyright 2017 Kiparenko Ilya

#ifndef MODULES_INTERPOLATION_SEARCH_APP_INCLUDE_INTERPOLATION_SEARCH_APP_H_
#define MODULES_INTERPOLATION_SEARCH_APP_INCLUDE_INTERPOLATION_SEARCH_APP_H_

#include <string>

class InterpolationSearchApp {
 public:
  InterpolationSearchApp();
  std::string operator() (int argc, const char** argv);
 private:
  static const char help_message_[] = 
    "This is a interpolation search app\n"
    "Use interpolation-search <array> <item>\n"
    "Where <array> is array of integers, and <item> is what you want to find\n";
};

#endif  // MODULES_INTERPOLATION_SEARCH_APP_INCLUDE_INTERPOLATION_SEARCH_APP_H_

*/

// Copyright 2017 Kiparenko Ilya

#ifndef MODULES_INTERPOLATION_SEARCH_APP_INCLUDE_INTERPOLATION_SEARCH_APP_H_
#define MODULES_INTERPOLATION_SEARCH_APP_INCLUDE_INTERPOLATION_SEARCH_APP_H_

#include <string>

class InterpolationSearchApp {
 public:
  InterpolationSearchApp();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string message_;
};

#endif  // MODULES_INTERPOLATION_SEARCH_APP_INCLUDE_INTERPOLATION_SEARCH_APP_H_
