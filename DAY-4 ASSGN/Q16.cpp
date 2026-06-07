#include<iostream>
using namespace std;
int main()
{
    int a, b, temp, noOfDigit, num, res=0, rem, pow, i;
    cin>>a>>b;
    cout <<"Armstrong Numbers Between a and b";
    while(a<=b)
    {
        temp = a;
        noOfDigit = 0;
        while(temp>0)
        {
            temp = temp/10;
            noOfDigit++;
        }
        num = a;
        while(num>0)
        {
            rem = num%10;
            pow = 1;
            i = 0;
            while(i<noOfDigit)
            {
                pow = pow*rem;
                i++;
            }
            res = res + pow;
            num = num/10;
        }
        if(res==a)
            cout<<res<<endl;
        a++;
        res = 0;
    }
    cout<<endl;
    return 0;
}