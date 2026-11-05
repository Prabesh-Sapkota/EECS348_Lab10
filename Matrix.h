#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Matrix {
private:
    int N;
    std::vector<std::vector<int>> data;

public:
    Matrix();
    Matrix(int size);

    void readFromFile(std::ifstream& infile);
    void display() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    void displayDiagonalSums() const;
    Matrix swapRows(int row1 = 0, int row2 = 1) const;
    Matrix swapCols(int col1 = 0, int col2 = 1) const;
    Matrix updateElement(int row, int col, int newVal = 100) const;

    int getSize() const;
};

#endif