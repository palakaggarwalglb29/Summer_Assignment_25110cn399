#include <iostream>
using namespace std;

int main()
{
	int i, n, temp, reminder;
	long sum = 0, factorial = 1;
	
	cout << "\nPlease Enter the Number to Check for Strong Number =  ";
	cin >> n;
	
	for(temp = n; temp > 0; temp =  temp / 10 )
	{
		factorial = 1;  
		reminder = temp % 10;
		
		for (i = 1; i <= reminder; i++)
		{
			factorial = factorial * i;
		}
		cout << "\nThe Factorial of "<< reminder << " = " << factorial;
		sum = sum + factorial;
	}	
	cout << "\n\nThe Sum of the Factorials of " << n << " is = " << sum << "\n\n";
			
	if(n == sum)
	{
		cout << n << " is a Strong Number";
	}
	else
	{
		cout << n << " is Not a Strong Number";
	}

 	
}
