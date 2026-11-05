#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.h"

int main() {
    std::string filename;
    std::cout << "Enter input filename: ";
    std::cin >> filename;

    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    int size;
    infile >> size; // Read N first

    // Read Matrix A
    Matrix matA(size);
    matA.readFromFile(infile); // Pass stream (will read values since size is already set)
    std::cout << "\nMatrix A:" << std::endl;
    matA.display();

    // Read Matrix B
    Matrix matB(size);
    matB.readFromFile(infile);
    std::cout << "\nMatrix B:" << std::endl;
    matB.display();

    // 2. Addition
    std::cout << "\nA + B:" << std::endl;
    Matrix sumMat = matA + matB;
    sumMat.display();

    // 3. Multiplication
    std::cout << "\nA * B:" << std::endl;
    Matrix multMat = matA * matB;
    multMat.display();

    // 4. Diagonal Sums
    std::cout << "\nDiagonal sums for Matrix A:" << std::endl;
    matA.displayDiagonalSums();

    // 5. Swap Rows (0 and 2)
    std::cout << "\nProblem 5 - Rows 0 and 2 swapped:" << std::endl;
    Matrix swappedRows = matA.swapRows(0, 2);
    swappedRows.display();

    // 6. Swap Columns (0 and 2)
    std::cout << "\nProblem 6 - Columns 0 and 2 swapped:" << std::endl;
    Matrix swappedCols = matA.swapCols(0, 2);
    swappedCols.display();

    // 7. Update Matrix element (Row 1, Col 2 to 99)
    std::cout << "\nProblem 7 - Updated matrix:" << std::endl;
    Matrix updatedMat = matA.updateElement(1, 2, 99);
    updatedMat.display();

    infile.close();
    return 0;
}