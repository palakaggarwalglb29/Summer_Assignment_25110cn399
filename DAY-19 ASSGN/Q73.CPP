#include <iostream>

using namespace std;

int main() {
    int rows, cols;

    // Get matrix dimensions 
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Declare 2D arrays with a maximum safe buffer size
    int matrixA[100][100], matrixB[100][100], sumMatrix[100][100];

    // Input elements for the first matrix
    cout << "\nEnter elements for the 1st matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at position (" << i + 1 << "," << j + 1 << "): ";
            cin >> matrixA[i][j];
        }
    }

    // Input elements for the second matrix
    cout << "\nEnter elements for the 2nd matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at position (" << i + 1 << "," << j + 1 << "): ";
            cin >> matrixB[i][j];
        }
    }

    // Perform element-wise matrix addition
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // resultant matrix
    cout << "\nResultant Sum Matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << sumMatrix[i][j] << "\t";
        }
        cout << "\n"; // Move to the next row
    }

    return 0;
}
