#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
    int data[SIZE][SIZE]; // 2D array for matrix data

public:
    // 1. Read values from a file into a matrix
    void readFromFile(ifstream& file);

    // 2. Display a matrix
    void display() const;

    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix& other) const;

    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix& other) const;

    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const;

    // 6. Swap matrix rows
    void swapRows(int row1, int row2);
};

// Reads matrix values from the file into the matrix
void Matrix::readFromFile(ifstream& file) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            file >> data[i][j];
        }
    }
}

// Displays the matrix in a readable format
void Matrix::display() const {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout.width(4);
            cout << data[i][j];
        }
        cout << endl;
    }
}

// Overloads + to add two matrices
Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return result;
}

// Overloads * to multiply two matrices
Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result.data[i][j] = 0;

            for (int k = 0; k < SIZE; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}

// Computes the sum of both main and secondary diagonals
int Matrix::sumOfDiagonals() const {
    int sum = 0;

    for (int i = 0; i < SIZE; i++) {
        sum += data[i][i];                 // main diagonal
        sum += data[i][SIZE - 1 - i];      // secondary diagonal
    }

    return sum;
}

// Swaps two rows if the row indices are valid
void Matrix::swapRows(int row1, int row2) {
    if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE) {
        for (int j = 0; j < SIZE; j++) {
            int temp = data[row1][j];
            data[row1][j] = data[row2][j];
            data[row2][j] = temp;
        }
    } else {
        cout << "Invalid row indices." << endl;
    }
}

int main() {
    ifstream file("matrix.txt");

    if (!file.is_open()) {
        cout << "Error: Could not open matrix.txt" << endl;
        return 1;
    }

    Matrix mat1;
    Matrix mat2;

    mat1.readFromFile(file);
    mat2.readFromFile(file);

    file.close();

    cout << "Matrix 1:" << endl;
    mat1.display();
    cout << endl;

    cout << "Matrix 2:" << endl;
    mat2.display();
    cout << endl;

    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();
    cout << endl;

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();
    cout << endl;

    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    cout << endl;

    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows 0 and 2:" << endl;
    mat1.display();

    return 0;
}