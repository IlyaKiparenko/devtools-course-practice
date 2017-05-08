// Copyright 2017 Kiparenko Ilya

#include <string>
#include "gtest/gtest.h"
#include "include/symbolic_function.h"

TEST(symbolic_derivativeTest, Can_Parse_Simple_Expression) {
  EXPECT_NO_THROW(symbolic_function sym("a + b"));
}

TEST(symbolic_derivativeTest, Can_Parse_Simple_Expression_With_Function) {
  EXPECT_NO_THROW(symbolic_function sym("a + b*c/sin(d)"));
}

TEST(symbolic_derivativeTest, Cant_Parse_Expression_With_Unknown_Token) {
  EXPECT_ANY_THROW(symbolic_function sym("a $ b"));
}

TEST(symbolic_derivativeTest, Can_Parse_Expression_With_Right_Braces) {
  EXPECT_NO_THROW(symbolic_function sym("(a + b)"));
}

TEST(symbolic_derivativeTest, Cant_Parse_Expression_With_Wrong_Braces) {
  EXPECT_ANY_THROW(symbolic_function sym("(a + b"));
}

TEST(symbolic_derivativeTest,
     Cant_Parse_Expression_With_Wrong_Number_Of_Arguments) {
  EXPECT_ANY_THROW(symbolic_function sym("a + "));
}

TEST(symbolic_derivativeTest,
     Cant_Parse_Expression_With_Wrong_Number_Of_Arguments_More) {
  EXPECT_ANY_THROW(symbolic_function sym("(a + b) c"));
}

TEST(symbolic_derivativeTest, Can_Parse_Its_Own_Representation) {
  symbolic_function sym("a/e + b*c^d");
  symbolic_function sym_2(sym.ToString());

  EXPECT_EQ(sym_2.ToString(), sym.ToString());
}

TEST(symbolic_derivativeTest, Can_Parse_Really_Complex_Expression) {
  std::string s = "1 + 3/4/sin(x+log(x)/2.0)*cos(4.0)^(5.0-x)";
  s +=            "-(1-x)^(x) + sin(2*x*3*cos(2*x))";
  symbolic_function sym(s);
  symbolic_function sym_2(sym.ToString());

  EXPECT_EQ(sym_2.ToString(), sym.ToString());
}

TEST(symbolic_derivativeTest, Derivative_Of_X_Is_One) {
  symbolic_function sym("x");
  symbolic_function sym_dx;

  EXPECT_NO_THROW(sym_dx = sym.Derivative("x"));
  EXPECT_EQ(stod(sym_dx.ToString()), 1.0);
}

TEST(symbolic_derivativeTest, Derivative_Of_Not_X_Is_Zero) {
  symbolic_function sym("a+b/c");
  symbolic_function sym_dx;

  EXPECT_NO_THROW(sym_dx = sym.Derivative("x"));

  EXPECT_EQ(std::stod(sym_dx.ToString()), 0.0);
}

TEST(symbolic_derivativeTest, Can_Differentiate_Really_Complex_Expression) {
  std::string s = "2^x*x + 3/4/sin(x+log(x)/2.0)*cos(4.0)^(5.0-x)";
  s +=            "-(1-x)^(x) + sin(2*x*3*cos(2*x))-3+2*x-4";
  symbolic_function sym(s);
  symbolic_function sym_dx;

  EXPECT_NO_THROW(sym_dx = sym.Derivative("x"));
}
