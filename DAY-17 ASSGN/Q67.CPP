#include <iostream>
using namespace std;
int main() {
    // Define two input arrays
    int arr1[] = {4, 2, 9, 2, 4, 6, 8};
    int arr2[] = {2, 3, 4, 4, 1, 6};

    // Calculate sizes of the arrays
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // The maximum possible intersection size is the size of the smaller array
    int maxIntersectionSize = (size1 < size2) ? size1 : size2;
    int intersection[maxIntersectionSize];
    int intersectionCount = 0;

    // Loop through each element of the first array
    for (int i = 0; i < size1; i++) {
        bool foundInArr2 = false;

        // Step 1: Check if the current element exists in the second array
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                foundInArr2 = true;
                break; // Element found, exit inner loop
            }
        }

        // Step 2: If found, check if it's already added to the intersection array (to avoid duplicates)
        if (foundInArr2) {
            bool isDuplicate = false;
            for (int k = 0; k < intersectionCount; k++) {
                if (arr1[i] == intersection[k]) {
                    isDuplicate = true;
                    break; // Already recorded, skip
                }
            }

            // Step 3: If it's a unique common element, add it to our results
            if (!isDuplicate) {
                intersection[intersectionCount] = arr1[i];
                intersectionCount++;
            }
        }
    }

    // Print the final intersection list
    cout << "Intersection of the two arrays: ";
    if (intersectionCount == 0) {
        cout << "No common elements.";
    } else {
        for (int i = 0; i < intersectionCount; i++) {
            cout << intersection[i] << " ";
        }
    }
    cout << endl;

    
}
