// Note: you need to add compiler flag -fno-elide-constructors to
// disable copy elision (return value optimization) in order to see
// move constructor work as what you expect
#include "ECMatrix.h"
#include <iostream>

// default constructor
ECMatrix ::ECMatrix()
{
}

// create a matrix of nr rows and nc columns
ECMatrix::ECMatrix(int nr, int nc)
{
  listElements.resize(nr, std::vector<double>(nc, 0.0));
}

// Copy constructor
ECMatrix::ECMatrix(const ECMatrix &rhs)
{
  listElements = rhs.listElements;
}

//
ECMatrix ECMatrix::operator=(const ECMatrix &rhs)
{
  listElements = rhs.listElements;
  return *this;
}

// Move constructor
ECMatrix::ECMatrix(ECMatrix &&rhs)
{
  listElements = std::move(rhs.listElements);
}

// Get num of rows/columns
int ECMatrix::GetNumRows() const
{
  return listElements.size();
}

int ECMatrix ::GetNumCols() const
{
  return listElements.empty() ? 0 : listElements[0].size();
}

// Get/set an element in the matrix
double ECMatrix::GetVal(int r, int c) const
{
  return listElements[r][c];
}
void ECMatrix::SetVal(int r, int c, double val)
{
  listElements[r][c] = val;
}

// Scale by a factor
ECMatrix ECMatrix::Scale(double factor) const
{
  ECMatrix result = *this;
  for (auto &row : result.listElements)
  {
    for (auto &val : row)
    {
      val *= factor;
    }
  }
  return result;
}