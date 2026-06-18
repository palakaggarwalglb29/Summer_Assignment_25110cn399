#include <iostream>
using namespace std;

int main() {
    // Define two hardcoded sample arrays
    int arr1[] = {1, 2, 4, 5, 6, 2, 9};
    int arr2[] = {2, 3, 5, 7, 9, 2};

    // Calculate sizes of the arrays
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Common elements are: ";

    // Nested loops to find intersections
    for (int i = 0; i < size1; i++) {
        
        // 1. Check if the element was already processed in arr1 to avoid duplicate prints
        bool alreadyPrinted = false;
        for (int k = 0; k < i; k++) {
            if (arr1[i] == arr1[k]) {
                alreadyPrinted = true;
                break;
            }
        }

        // If it is a duplicate in the first array, skip checking it again
        if (alreadyPrinted) {
            continue;
        }

        // 2. Search for the current element of arr1 inside arr2
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                break; // Break early once a match is found to save iterations
            }
        }
    }

    cout << endl;
    
}
