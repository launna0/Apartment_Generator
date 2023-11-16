#include "Matrix.hpp"
#include "unit_test_framework.h"
#include<iostream>
#include<string>
#include<vector>



TEST(test_get_width)
{
  auto mat = Matrix(3, 6, 'C');
  int expected = mat.get_width();
  const int actual = 3;

  ASSERT_EQUAL(expected, actual);
}

TEST(test_get_width_two)
{
  auto mat = Matrix();
  int expected = mat.get_width();
  const int actual = 0;

  ASSERT_EQUAL(expected, actual);
}

TEST(test_get_height)
{
  auto mat = Matrix(3, 6, 'C');
  int expected = mat.get_height();
  const int actual = 6;

  ASSERT_EQUAL(expected, actual);
}

TEST(test_get_height_two)
{
  auto mat = Matrix();
  int expected = mat.get_height();
  const int actual = 0;

  ASSERT_EQUAL(expected, actual);
}

TEST(test_Matrix_at)
{
  const int width = 8;
  const int height = 10;
  const int value = 'C';
  auto mat = Matrix(width, height, value);
  
  const int row = 4;
  const int column = 3;
  int at_exp = mat.at(row, column);
  int at_act = 'C';
  ASSERT_EQUAL(at_exp, at_act);

}

TEST(test_Matrix_at_two)
{
  const int width = 2;
  const int height = 2;
  const int value = 'C';
  auto mat = Matrix(width, height, value);
  
  const int row = 0;
  const int column = 0;
  int at_exp = mat.at(row, column);
  int at_act = 'C';
  ASSERT_EQUAL(at_exp, at_act);

}

TEST(test_Matrix_at_three)
{
  const int width = 2;
  const int height = 2;
  const int value = 'C';
  auto mat = Matrix(width, height, value);
  
  const int row = 0;
  const int column = 0;
  mat.at(row, column) = 'G';
  int at_exp = mat.at(row, column);
  
  int at_act = 'G';
  ASSERT_EQUAL(at_exp, at_act);

}




TEST_MAIN()



