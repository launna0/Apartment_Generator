#include "Matrix.hpp"

#include<iostream>
#include<string>
#include<vector>



// an empty constructor
  Matrix::Matrix() {
    m_width = 0;
    m_height = 0;
  }

  // a constructor with only height and width
  Matrix::Matrix(int width, int height) {
    m_width = width;
    m_height = height;
    for (int i = 0; i < (width * height); i = i + 1) {
        // E represents empty spaces within the apartment
        m_data.push_back('E');
    }
  }

  // a constructor with height and width and a value to fill with
  Matrix::Matrix(int width, int height, char fill_value) {
    m_width = width;
    m_height = height;
    for (int i = 0; i < (width * height); i = i + 1) {
        m_data.push_back(fill_value);
    }
  }


// define get_width function 
int Matrix::get_width() const {
    return this->m_width;
}

// define get_height function
int Matrix::get_height() const {
    return m_height;
}

// Returns a modifiable reference to the cell at the given row and column.
char& Matrix::at(int row, int column) {

  if ((row < 0) || (row >= m_height) || (column < 0) || (column >= m_width)) {
    int corner_ref = (m_height * m_width) - 1;
    return m_data.at(corner_ref);
  }
  int ref = (row * m_width) + (m_width - (m_width - column));
  return m_data.at(ref);
}

// makes a constant reference which you cannot modify
const char& Matrix::at(int row, int column) const {
  
  if ((row < 0) || (row > m_height) || (column < 0) || (column > m_width)) {
    int corner_ref = (m_height * m_width) - 1;
    return m_data.at(corner_ref);
  }
  int ref = (row * m_width) + (m_width - (m_width - column));
  return m_data.at(ref);
}








