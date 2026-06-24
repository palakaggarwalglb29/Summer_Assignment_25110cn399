#include <iostream>
#include <string>
#include <algorithm> // Required for std::sort and std::unique
using namespace std;
int main() {
    string input = "programming";

    // Step 1: Sort the string because std::unique only handles adjacent duplicates
    sort(input.begin(), input.end());

    // Step 2: std::unique moves duplicates to the end and returns an iterator to the new end
    auto newEnd = unique(input.begin(), input.end());

    // Step 3: Erase the leftover duplicate characters from the string tail
    input.erase(newEnd, input.end());

    cout << "After Removing Duplicates (Sorted): " << input << endl;

    
}
