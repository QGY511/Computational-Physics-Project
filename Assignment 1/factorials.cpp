//
//  main.cpp
//  factorials
//
//  Created by QGY on 10/13/20.
//

#include <iostream>
using namespace std;

int factorial(int n);
int main()
{
    int n;
    cout<<"Enter an integer n:";//read input n
    cin>>n;
    if(n<0)//if n is a negative integer, there will be no factorials.
    {
        cout<<"Factorial of "<<n<< " cannot be calculated";// output error message
        
    }
    else
    {
        cout<<"Factorial of "<<n<< " equals "<<factorial(n);// continue if n is a positive integer.
        
    }
    cout<<endl;
    return 0;
}

int factorial(int n)
{
    if(n>1)
        return n*factorial(n-1);// call the function itslef.
    else
        return 1;// because factorial of 0 is 1.
}

// Note that largest n can get is 12. the reason is that the largest value can be stored is 2^32=4294967296. 13! will exceed that value. Therefore, n can only get to 12. Otherwise, it gives the wrong answer.
