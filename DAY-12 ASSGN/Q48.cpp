#include <iostream>
using namespace std;

bool isPerfect(int num) {
    // Numbers less than or equal to 0 cannot be perfect
    if (num <= 0) {
        return false;
    }

    int sum = 0;

    // Iterate up to half of the number for better efficiency
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i; 
        }
    }

    
    return sum == num;
}

int main() {
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;

    
    if (isPerfect(number)) {
        cout << number << " is a perfect number." << endl;
    } else {
        cout << number << " is not a perfect number." << endl;
    }

    
}
