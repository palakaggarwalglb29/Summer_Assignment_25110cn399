#include <iostream>

using namespace std;

int main() {
    int rows, cols;

    // Get the dimensions of the matrices
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Declare 2D arrays based on user dimensions
    int matrix1[rows][cols];
    int matrix2[rows][cols];
    int result[rows][cols];

    // Input elements for the first matrix
    cout << "\nEnter elements for the first matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    // Input elements for the second matrix
    cout << "\nEnter elements for the second matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }

    // Perform matrix subtraction
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    // resultant matrix
    cout << "\nResultant Matrix (Matrix1 - Matrix2):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
