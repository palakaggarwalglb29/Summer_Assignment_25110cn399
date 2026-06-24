#include <iostream>
#include <string>
using namespace std;
// Function to check if str2 is a rotation of str1
bool isRotation(const string& str1, const string& str2) {
    // If lengths are not equal, they cannot be rotations of each other
    if (str1.length() != str2.length()) {
        return false;
    }

    // Concatenate str1 with itself
    string temp = str1 + str1;

    // Check if str2 is a substring of the concatenated string
    // std::string::npos is returned if the substring is not found
    return (temp.find(str2) != string::npos);
}

int main() {
    string str1 = "AACD";
    string str2 = "ACDA";

    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    if (isRotation(str1, str2)) {
        cout << "Result: Yes, strings are rotations of each other." << endl;
    } else {
        cout << "Result: No, strings are not rotations of each other." << endl;
    }

    return 0;
}
