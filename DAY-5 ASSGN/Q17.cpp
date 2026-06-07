#include<iostream>
using namespace std;
int main ()
{  
    int i, n, div, sum=0;
    cout << "Enter the number: ";
    cin >> n;
    for (i=1; i < n; i++)
    {
        div = n % i;
        if (div == 0)
            sum = sum + i;
    }
    if (sum == n)
        cout << "\n" << n <<" is a perfect number.";
    else
        cout << "\n" << n<<" is not a perfect number.";
    return 0;
}