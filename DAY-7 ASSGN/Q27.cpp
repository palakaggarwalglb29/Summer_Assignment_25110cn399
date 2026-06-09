#include <iostream>
using namespace std;

// Recursive function 
int sumOfDigits(int n) {
    // if the number becomes 0, stop the recursion
    if (n == 0) {
        return 0;
    }
    
    // Recursive case: last digit + sum of remaining digits
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int n;
    cin>>n;
    
cout << "The sum of digits of " << n
              << " is: " << sumOfDigits(n) << endl;
              
              
    
}
