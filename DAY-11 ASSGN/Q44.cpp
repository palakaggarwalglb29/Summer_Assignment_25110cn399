#include <iostream>
using namespace std;


int findFactorial(int n) {
    int fact = 1;
    
    
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    
    return fact;
}

int main() {
    int num;
    
    cout << "Enter a positive integer: ";
    cin >> num;
    
    
    if (num < 0) {
        cout <<" Factorial of a negative number does not exist." << endl;
    } else {
        int result = findFactorial(num);
        cout << "Factorial of " << num << " is " << result << endl;
    }
    
    
}
