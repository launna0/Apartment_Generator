#ifndef MATRIX_H
#define MATRIX_H



#include <iosfwd>
#include <vector>

// Representation of a 2D matrix of chars 
// this class is inspired by Matrix.cpp in HW 2 but contains modifications 
// so that the class works for this project 
class Matrix final {
public:
  // Create an empty Matrix
  Matrix();

  // Create a Matrix with the given dimensions and
  // with each cell initialized to 'E'.
  Matrix(int width, int height);

  // Create a Matrix with the given dimensions and
  // with each cell initialized to the char value specified by fill_value.
  Matrix(int width, int height, char fill_value);

  // gives width of Matrix.
  int get_width() const;

  // gives height of Matrix.
  int get_height() const;

  // gives a modifiable reference to the cell at the given row and column.
  // if out of range the function will return 'E'
  char& at(int row, int column);

  // gives a non-modifiable reference to the cell at the given row and column.
  // if out of range the function will return 'E'
  const char& at(int row, int column) const;

private:

  int m_width;
  int m_height;
  std::vector<char> m_data;
};

#endif // MATRIX_H
