#include <iostream>
using namespace std;

int main() {
    // Initialize two original arrays
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6, 7};

    // Calculate sizes of the arrays
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = size1 + size2;

    // Create the third array to store merged elements
    int mergedArr[size3];

    // Copy elements of the first array
    for (int i = 0; i < size1; i++) {
        mergedArr[i] = arr1[i];
    }

    // Copy elements of the second array directly after the first
    for (int i = 0; i < size2; i++) {
        mergedArr[size1 + i] = arr2[i];
    }

    // Print the final merged array
    cout << "Merged Array: ";
    for (int i = 0; i < size3; i++) {
        cout << mergedArr[i] << " ";
    }
    cout << endl;

    
}
