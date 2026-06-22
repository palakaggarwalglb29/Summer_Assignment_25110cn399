#include <iostream>

using namespace std;

int main() {
    int rows, cols;

    // Get matrix dimensions from user
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    // Declare static 2D arrays with a maximum size limit
    const int MAX = 100;
    int matrix[MAX][MAX];
    int transpose[MAX][MAX];

    // Input original matrix elements
    cout << "\nEnter elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Display the original matrix
    cout << "\nOriginal Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Compute the transpose matrix
    // The original row index 'i' becomes the column index in transpose
    // The original column index 'j' becomes the row index in transpose
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Display the transposed matrix
    // Note: The loop limits are swapped because dimensions are now (cols x rows)
    cout << "\nTransposed Matrix:" << endl;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
