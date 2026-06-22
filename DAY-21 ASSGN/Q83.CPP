#include <iostream>
#include <string>
#include <cctype> // For tolower and isalpha
using namespace std;
int main() {
    string str;
    int vowels = 0;
    int consonants = 0;

    cout << "Enter a string: ";
    // Use getline to read the entire line, including spaces
    getline(cin, str);

    // Iterate through each character in the string
    for (char ch : str) {
        // Convert character to lowercase to handle both case types uniformly
        ch = tolower(ch);

        // Check if the character is an alphabet letter
        if (isalpha(ch)) {
            // Check if the letter is a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                // If it's an alphabet letter and not a vowel, it's a consonant
                consonants++;
            }
        }
    }

    // Output the results
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;

    
}
