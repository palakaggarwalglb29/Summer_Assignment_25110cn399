#include <iostream>

using namespace std;

// Function to reverse the array in-place
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    // Swap elements from both ends moving inward
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to print the array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, size);

    // Call reversal function
    reverseArray(arr, size);

    cout << "Reversed Array: ";
    printArray(arr, size);

    
}
