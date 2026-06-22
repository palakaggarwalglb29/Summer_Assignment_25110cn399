#include <iostream>
using namespace std;
int main() {
    int n;

    // Get the size of the square matrix
    cout << "Enter the size of the square matrix (N x N): ";
    cin >> n;

    // Declare a standard 2D built-in array
    int matrix[n][n];

    // Input matrix elements from the user
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int primarySum = 0;
    int secondarySum = 0;

    // Calculate diagonal sums using a single efficient loop
    for (int i = 0; i < n; i++) {
        primarySum += matrix[i][i];            // Condition: row == column
        secondarySum += matrix[i][n - 1 - i];  // Condition: row + column == n - 1
    }

    // Display the results
    cout << "\nSum of Primary Diagonal: " << primarySum << endl;
    cout << "Sum of Secondary Diagonal: " << secondarySum << endl;
    cout << "Total Diagonal Sum: " << (primarySum + secondarySum) << endl;

    return 0;
}
