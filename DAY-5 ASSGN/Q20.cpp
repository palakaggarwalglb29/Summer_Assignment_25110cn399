

#include <iostream>
using namespace std;

int largestPrimeFactor(int n) {

    int largestPrime = -1;

    // Checking for factors of 2
    while (n % 2 == 0) {
        largestPrime = 2;
        n /= 2;
    }

    // Check for odd factors starting from 3
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0)  {
            largestPrime = i;
            n /= i;
        }
    }

    // If n is still greater than 2, it is
    // a prime number
    if (n > 2) {
        largestPrime = n;
    }

    return largestPrime;
}

int main() {
    int n = 15;
    int res = largestPrimeFactor(n);
    cout << res << endl;


}