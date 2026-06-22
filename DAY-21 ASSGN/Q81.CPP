#include <iostream>
using namespace std;
int main() {
    // Declare a character array to store the input string
    char str[100];
    int length = 0;

    cout << "Enter a string: ";
    // cin.getline ensures spaces are counted properly
    cin.getline(str, 100);

    // Loop until the null character '\0' is encountered
    while (str[length] != '\0') {
        length++; // Increment count for each character
    }

    cout << "The length of the string is: " << length << endl;

    
}
