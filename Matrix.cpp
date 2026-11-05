#include "Matrix.h"
#include <iomanip>
#include <stdexcept>

Matrix::Matrix() : N(0) {}

Matrix::Matrix(int size) : N(size) {
    data.resize(N, std::vector<int>(N, 0));
}

void Matrix::readFromFile(std::ifstream& infile) {
    // Check if the file starts with an N, or if N is already set
    if (N == 0) {
        infile >> N;
    }
    data.resize(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            infile >> data[i][j];
        }
    }
}

void Matrix::display() const {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(3) << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (N != other.N) {
        throw std::invalid_argument("Size mismatch for addition");
    }
    Matrix result(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (N != other.N) {
        throw std::invalid_argument("Size mismatch for multiplication");
    }
    Matrix result(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

void Matrix::displayDiagonalSums() const {
    int mainSum = 0;
    int secondarySum = 0;
    for (int i = 0; i < N; ++i) {
        mainSum += data[i][i];
        secondarySum += data[i][N - 1 - i];
    }
    std::cout << "Main diagonal sum: " << mainSum << std::endl;
    std::cout << "Secondary diagonal sum: " << secondarySum << std::endl;
}

Matrix Matrix::swapRows(int row1, int row2) const {
    if (row1 < 0 || row1 >= N || row2 < 0 || row2 >= N) {
        throw std::out_of_range("Invalid row indices");
    }
    Matrix result = *this;
    std::swap(result.data[row1], result.data[row2]);
    return result;
}

Matrix Matrix::swapCols(int col1, int col2) const {
    if (col1 < 0 || col1 >= N || col2 < 0 || col2 >= N) {
        throw std::out_of_range("Invalid column indices");
    }
    Matrix result = *this;
    for (int i = 0; i < N; ++i) {
        std::swap(result.data[i][col1], result.data[i][col2]);
    }
    return result;
}

Matrix Matrix::updateElement(int row, int col, int newVal) const {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        throw std::out_of_range("Invalid indices");
    }
    Matrix result = *this;
    result.data[row][col] = newVal;
    return result;
}

int Matrix::getSize() const {
    return N;
}