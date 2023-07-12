//
//  main.cpp
//  monte carlo
//
//  Created by QGY on 11/3/20.
//

#include <iostream>
#include <cmath>
using namespace std;

double integrand(double aX)
{
    return sqrt(1-aX*aX);
}
double simpsons(double leftL, double rightL, int n, double integrand(double))//This defines simpsons rule to calculate the integral
{
    double x,dx,sum1,sum2,result;
    x=leftL;
    dx=(rightL-leftL)/n;
    sum1=0;
    sum2=0;
    result=0;
    for(int i=1;i<n;i=i+2)//choose to use n/2 and 2i to avoid overlaps.
    {
        sum1+=4*integrand(x+i*dx);
    }
    for(int j=0;j<n;j=j+2)
    {
        sum2+=2*integrand(x+j*dx);
    }
    result=dx*(sum1+sum2-integrand(x))/3.0;
    return result;
}
int main()
{
    double x,y,lower,upper,sum,n;
    cout<<"Enter the value of N: "<<endl;
    cin>>n;
    sum=0;
    lower=-1;
    upper=1;
    //TRandom3 rnd(seed);
    for(int i=0;i<n;i++)
    {
        x=rnd.Uniform(lower,upper);
        y=rnd.Uniform(lower,upper);
        if(y<integrand(x))
        {
            sum+=1;
        }
    }
    cout<<sum;
    return 0;
}
