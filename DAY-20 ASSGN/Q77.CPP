#include <iostream>

using namespace std;

int main() {
    int r1, c1, r2, c2;

    // Get dimensions for the first matrix
    cout << "Enter rows and columns for the first matrix: ";
    cin >> r1 >> c1;

    // Get dimensions for the second matrix
    cout << "Enter rows and columns for the second matrix: ";
    cin >> r2 >> c2;

    // Rule check: Columns of the first matrix must match rows of the second matrix
    if (c1 != r2) {
        cout << "\nError: Matrices cannot be multiplied! "
             << "Columns of the 1st matrix (" << c1 
             << ") must equal rows of the 2nd matrix (" << r2 << ")." << endl;
        return 1;
    }

    // Declare 2D arrays with a fixed upper bound capacity (e.g., max 10x10)
    int A[10][10], B[10][10], C[10][10];

    // Input elements for Matrix A
    cout << "\nEnter elements of the first matrix (" << r1 << "x" << c1 << "):\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << "Element A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    // Input elements for Matrix B
    cout << "\nEnter elements of the second matrix (" << r2 << "x" << c2 << "):\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << "Element B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    // Initialize the result matrix C elements to 0 and perform multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0; // Reset sum element
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display the resulting product matrix
    cout << "\nResultant Product Matrix (" << r1 << "x" << c2 << "):\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << "\t";
        }
        cout << "\n";
    }

    
}
