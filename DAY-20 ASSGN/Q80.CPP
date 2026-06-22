#include <iostream>
using namespace std;
int main() {
    // Define maximum dimensions to avoid Variable Length Arrays (VLAs)
    const int MAX_ROWS = 100;
    const int MAX_COLS = 100;
    
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;
    
    // User inputs the size of the matrix
    cout << "Enter the number of rows (max " << MAX_ROWS << "): ";
    cin >> rows;
    cout << "Enter the number of columns (max " << MAX_COLS << "): ";
    cin >> cols;
    
    // Validate inputs
    if (rows > MAX_ROWS || cols > MAX_COLS || rows <= 0 || cols <= 0) {
        cout << "Invalid matrix dimensions!" << endl;
        return 1;
    }
    
    // Populate the matrix
    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    // Display the entered matrix
    cout << "\nThe entered matrix is:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Calculate and print column-wise sums
    cout << "\nColumn-wise sums:" << std::endl;
    for (int j = 0; j < cols; ++j) {
        int colSum = 0; // Reset sum for each new column
        for (int i = 0; i < rows; ++i) {
            colSum += matrix[i][j]; // Accumulate down the column
        }
        cout << "Sum of Column " << j + 1 << " = " << colSum << std::endl;
    }
    

}
