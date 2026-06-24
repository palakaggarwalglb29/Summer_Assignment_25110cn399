#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main() {
    string sentence;
    
    // Get the full line of text from the user
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    // Use stringstream to read word by word
    stringstream ss(sentence);
    string currentWord;
    string longestWord = "";
    
    // Loop through each word in the stream
    while (ss >> currentWord) {
        // If the current word is longer than the previous maximum
        if (currentWord.length() > longestWord.length()) {
            longestWord = currentWord;
        }
    }
    
    // Display the result
    if (longestWord.empty()) {
        cout << "No words were found." << endl;
    } else {
        cout << "The longest word is: " << longestWord << endl;
        cout << "Its length is: " << longestWord.length() << " characters." << endl;
    }
    
    return 0;
}
