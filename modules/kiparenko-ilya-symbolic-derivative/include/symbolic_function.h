// Copyright 2017 Kiparenko Ilya

#ifndef MODULES_KIPARENKO_ILYA_SYMBOLIC_DERIVATIVE_INCLUDE_SYMBOLIC_FUNCTION_H_
#define MODULES_KIPARENKO_ILYA_SYMBOLIC_DERIVATIVE_INCLUDE_SYMBOLIC_FUNCTION_H_

#include <string>
#include <vector>
#include <unordered_map>

#include "include/types_and_consts.h"

using std::vector;
using std::string;

class symbolic_function {
 public:
  explicit symbolic_function(string s);
  string ToString();
  symbolic_function();
  symbolic_function Derivative(string variable);
  symbolic_function& operator=(const symbolic_function& sym);
  ~symbolic_function();

 private:
  Node* root_;
  vector<string> symbols_;

  Node*  Parse(string s);
  Node*  ToPostfixForm(Node* root);
  Node*  PostfixToAst(Node* root);
  Node*  Derivative(Node* root, string);
  void   DelTree(Node* root);
  Node*  CopyTree(Node* root);
  string PrintTree(Node* root);
};

#endif  // MODULES_KIPARENKO_ILYA_SYMBOLIC_DERIVATIVE_INCLUDE_SYMBOLIC_FUNCTION_H_
