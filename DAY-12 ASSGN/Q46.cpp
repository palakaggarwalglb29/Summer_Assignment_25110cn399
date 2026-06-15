#include <iostream>
#include <cmath>
using namespace std;


bool isArmstrong(int number) {
    int originalNumber = number, remainder, sum = 0, digits = 0, temp = number;

    
    while (temp > 0) {
        temp /= 10;
        digits++;
    }

    temp = number;
    
    while (temp > 0) {
        remainder = temp % 10;
        sum += pow(remainder, digits);
        temp /= 10;
    }

    return sum == originalNumber;
}

int main() {
    int number;
    
    
    cout << "Enter a number to check: ";
    cin >> number;


    if (isArmstrong(number))
        cout << number << " is an Armstrong number.\n";
    else
        cout << number << " is not an Armstrong number.\n";

    
}