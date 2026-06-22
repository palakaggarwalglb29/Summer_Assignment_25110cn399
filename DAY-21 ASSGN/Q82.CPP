#include <iostream>
#include <string>
#include <algorithm> // Required for reverse
using namespace std;
int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str); // Reads the whole line, including spaces

    // Reverses the string in-place using iterators
    reverse(str.begin(), str.end());

    cout << "Reversed string: " << str << endl;

    
}
