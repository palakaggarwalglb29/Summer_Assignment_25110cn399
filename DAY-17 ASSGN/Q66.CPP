#include <iostream>
using namespace std;

// Helper function to check if a value is already present in an array
bool isPresent(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true; 
        }
    }
    return false;
}

int main() {
    // Define two input arrays
    int arr1[] = {1, 2, 4, 5, 2, 1};
    int arr2[] = {2, 3, 5, 6, 6, 7};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // The maximum possible size of the union array is the sum of both sizes
    int unionArr[100]; 
    int unionSize = 0;

    // Process the first array: add unique elements to the union array
    for (int i = 0; i < n1; i++) {
        if (!isPresent(unionArr, unionSize, arr1[i])) {
            unionArr[unionSize] = arr1[i];
            unionSize++;
        }
    }

    // Process the second array: add elements only if they aren't already in the union array
    for (int i = 0; i < n2; i++) {
        if (!isPresent(unionArr, unionSize, arr2[i])) {
            unionArr[unionSize] = arr2[i];
            unionSize++;
        }
    }

    // Print the final union array
    cout << "Union of the two arrays: ";
    for (int i = 0; i < unionSize; i++) {
        cout << unionArr[i] << " ";
    }
    cout << endl;

    
}
