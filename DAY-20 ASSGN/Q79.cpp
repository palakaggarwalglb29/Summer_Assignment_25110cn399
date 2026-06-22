#include <iostream>

using namespace std;

int main() {
    // Define maximum dimensions for the raw 2D array
    const int MAX_ROWS = 100;
    const int MAX_COLS = 100;
    int matrix[MAX_ROWS][MAX_COLS];
    
    int rows, cols;
    
    // Get user input for dimensions
    cout << "Enter number of rows (max " << MAX_ROWS << "): ";
    cin >> rows;
    cout << "Enter number of columns (max " << MAX_COLS << "): ";
    cin >> cols;
    
    // Input validation
    if (rows > MAX_ROWS || cols > MAX_COLS || rows <= 0 || cols <= 0) {
        cout << "Invalid dimensions entered." << endl;
        return 1;
    }
    
    // Accept matrix elements from the user
    cout << "\nEnter elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    // Calculate and display row-wise sum
    cout << "\n--- Row-wise Sums ---" << endl;
    for (int i = 0; i < rows; i++) {
        int rowSum = 0; // Reset sum for each new row
        
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j]; // Accumulate elements in the current row
        }
        
        cout << "Sum of Row " << i + 1 << " = " << rowSum << endl;
    }
    
    
}
