#include <iostream>
using namespace std;
// function to reverse a part of the array
void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}

// Function to right rotate the array by K positions
void rotateRight(int arr[], int n, int k) {
    // Handle cases where K is larger than the array size
    k = k % n; 
    
    // Step 1: Reverse the last K elements
    reverseArray(arr, n - k, n - 1);
    
    // Step 2: Reverse the first N - K elements
    reverseArray(arr, 0, n - k - 1);
    
    // Step 3: Reverse the entire array
    reverseArray(arr, 0, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // Number of positions to rotate right

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Perform right rotation
    rotateRight(arr, n, k);

    cout << "Rotated array right by " << k << " places: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
