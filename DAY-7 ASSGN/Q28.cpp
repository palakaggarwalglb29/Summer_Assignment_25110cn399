#include <iostream>
using namespace std;


int reverseRecursive(int n, int rev = 0) {
    //  when the remaining number becomes 0
    if (n == 0) {
        return rev;
    }
    
    
    int lastDigit = n % 10;
    rev = (rev * 10) + lastDigit;
    
    
    return reverseRecursive(n / 10, rev);
}

int main() {
    int num;
    cin>> num;
    int reversedNum = reverseRecursive(num);
    
    cout << "Original: " << num << endl;
    cout << "Reversed: " << reversedNum << endl;
    
    
}
