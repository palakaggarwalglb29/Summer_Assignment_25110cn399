#include <iostream>
#include <string>
using namespace std;
string compressString(const string& str) {
    // Return empty string if input is empty
    if (str.empty()) {
        return "";
    }

    string compressed = "";
    int count = 1;

    // Traverse the string
    for (size_t i = 0; i < str.length(); i++) {
        // If the next character is the same, increase the count
        if (i + 1 < str.length() && str[i] == str[i + 1]) {
            count++;
        } else {
            // Append character and its count to the result
            compressed += str[i];
            compressed += to_string(count);
            // Reset the count for the next unique character
            count = 1;
        }
    }

    // Return the original string if compression doesn't save space
    return (compressed.length() < str.length()) ? compressed : str;
}

int main() {
    string input1 = "aaabbbccc";
    string input2 = "abcd";

    cout << "Original: " << input1 << " -> Compressed: " << compressString(input1) << endl;
    cout << "Original: " << input2 << " -> Compressed: " << compressString(input2) << endl;

    return 0;
}
