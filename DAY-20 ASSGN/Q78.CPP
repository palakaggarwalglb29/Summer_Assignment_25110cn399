#include <iostream>

using namespace std;

// Maximum size allowed for the static array
const int MAX = 100;

int main() {
    int rows, cols;

    // Step 1: Input dimensions
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Step 2: Validation for symmetry
    // A matrix can only be symmetric if it is a square matrix
    if (rows != cols) {
        cout << "The matrix is NOT symmetric (It must be a square matrix)." << endl;
        return 0;
    }

    int matrix[MAX][MAX];

    // Step 3: Input matrix elements
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Step 4: Check for symmetry
    bool isSymmetric = true;
    
    // We only need to check the elements above the main diagonal (j > i)
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = false;
                break; // Exit inner loop early if a mismatch is found
            }
        }
        if (!isSymmetric) {
            break; // Exit outer loop
        }
    }

    // Step 5: Output the result
    if (isSymmetric) {
        cout << "The matrix is a symmetric matrix." << endl;
    } else {
        cout << "The matrix is NOT a symmetric matrix." << endl;
    }

    
}
