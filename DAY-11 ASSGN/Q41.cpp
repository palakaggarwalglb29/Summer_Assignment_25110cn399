#include <iostream>

using namespace std;
int findSum(int num1, int num2) {
    return num1 + num2;
}

int main() {
    int number1, number2, sum;

    
    cout << "Enter first number: ";
    cin >> number1;

    cout << "Enter second number: ";
    cin >> number2;

    
    sum = findSum(number1, number2);

    cout << "The sum of " << number1 << " and " << number2 << " is: " << sum << std::endl;

    
}
