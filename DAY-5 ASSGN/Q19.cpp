#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    
    if (n <= 0) {
        cout << "Please enter a positive integer greater than 0." << endl;
        return 0;
    }

    cout << "Factors of " << n << " are: ";
    
    // Loop through all numbers from 1 to num
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
