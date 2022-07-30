#include <gtest/gtest.h>
#include "src/calculator.cpp"

TEST(CalculatorTest, ExpressionAssertion) {
  EXPECT_EQ(2, calculate("1+1"));
  EXPECT_EQ(3, calculate("1+1+1"));
  EXPECT_EQ(25, calculate("25"));
  EXPECT_EQ(125, calculate("5*5*5"));
  EXPECT_EQ(12, calculate("2+5*2"));
  EXPECT_EQ(-1, calculate("1-2"));
  EXPECT_EQ(-4, calculate("1-2-3"));
  EXPECT_EQ(-2, calculate("0-0-2"));
  EXPECT_EQ(00.3, calculate("00.3"));
  EXPECT_EQ(0.5, calculate("0.3+0.2"));
  EXPECT_EQ(0.5, calculate(".3+.2"));
  EXPECT_EQ(0, calculate(".3-0.3"));
  EXPECT_EQ(1, calculate("2/2"));
  EXPECT_EQ(1, calculate("(1+1)/2"));
  EXPECT_EQ(3, calculate("(0.9+0001.1)*2/2+1"));
  EXPECT_EQ(0, calculate("4%2"));
  EXPECT_EQ(24, calculate("4!"));
  EXPECT_EQ(1, calculate("1!"));
  EXPECT_EQ(1, calculate("0!"));
  EXPECT_EQ(2.718281828459045, calculate("e"));
  EXPECT_EQ(1, calculate("--1"));
  EXPECT_EQ(-1, calculate("---1"));
  EXPECT_EQ(2, calculate("+++1++++1"));
  EXPECT_EQ(0, calculate("+++1---1"));
  EXPECT_EQ(4, calculate("--(2+2)"));
  EXPECT_EQ(-1, calculate("-1/1"));
  EXPECT_EQ(-1, calculate("1/-1"));
  EXPECT_EQ(1, calculate("1/(-1+2)"));
  EXPECT_EQ(-1, calculate("1/(++++1---2)"));
  EXPECT_EQ(-0.25, calculate("1/-(2+2)"));;
  EXPECT_EQ(1, calculate("e/e"));;
  EXPECT_EQ(4, calculate("--4"));
  EXPECT_EQ(0, calculate("0.a"));
  EXPECT_EQ(0, calculate("-a"));
  EXPECT_EQ(6, calculate("3!"));
  EXPECT_EQ(720, calculate("6!"));
  EXPECT_EQ(4, calculate("2*2!"));
  EXPECT_EQ(4, calculate("2*2!"));
  EXPECT_EQ(12, calculate("2*3!"));
  EXPECT_EQ(12, calculate("3!*2"));
  EXPECT_EQ(3, calculate("   1 + 1 +   1  "));
  EXPECT_EQ(4, calculate("2**2"));
  EXPECT_EQ(1, calculate("cos(0)"));
  EXPECT_EQ(3.14159265358979, calculate("pi"));
  EXPECT_EQ(1, calculate("sin(pi/2)"));
}

TEST(CalculatorTest, NumberAssertion) {
  EXPECT_EQ(123, calculate("123"));
  EXPECT_EQ(-123, calculate("-123"));
  EXPECT_EQ(56414, calculate("56414"));
  EXPECT_EQ(33.3, calculate("33.3"));
  EXPECT_EQ(33, calculate("33."));
  EXPECT_EQ(0, calculate("0."));
  EXPECT_EQ(1, calculate("01."));
  EXPECT_EQ(1, calculate("00000001.0000"));
  EXPECT_EQ(0, calculate(".0000"));
  EXPECT_EQ(0.55, calculate(".5500"));
  EXPECT_EQ(12.55, calculate("----12.55"));
}

