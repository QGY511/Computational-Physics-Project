//
//  main.cpp
//  Stirling
//
//  Created by QGY on 10/13/20.
//

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double n,stir,pi=3.14,e=2.71;//In this case, we want all the variables in double as mentioned in the assignment. And, pi and e asre just contant.
    cout<<"Enter an integer n: ";//read input n from user.
    cin>>n;
    if(n<0)//there is no factorial for negative n.
    {
        cout<<"Stirling approximating factorials of "<<n<<" can not be calculated";
        cout<<endl;
        return 0;
    }
    stir=sqrt(2.0*pi*n) * pow((n/e), n);//this is the stirling formula for calculating factorials.
    cout<<"Stirling approximating factorials of "<<n<<" is "<<stir;//output the result.
    cout<<endl;
    return 0;
}
//As I tried, the maxmium value for n is 170. Any value larger than 170 will get inf as the result.
