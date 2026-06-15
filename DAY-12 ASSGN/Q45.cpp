#include <iostream>
using namespace std;

// Returns true if num is a palindrome, false otherwise
bool isNumberPalindrome(int num) {
    
    if (num < 0) return false;

    int originalNum = num;
    int reversedNum = 0; 

    while (num > 0) {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    return originalNum == reversedNum;
}

int main() {
    int n;
    cin>>n;
    if (isNumberPalindrome(n)) {
        cout << n<< " is a palindrome." << endl;
    } else {
        cout << n << " is not a palindrome." << endl;
    }
    
}
