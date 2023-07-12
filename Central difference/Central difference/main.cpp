//
//  main.cpp
//  Central difference
//
//  Created by QGY on 10/22/20.
//
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    double x,dx,der,err;
    cout<<"Enter the value for the x in radian to calculate the derivative of sin(x):"<<endl;
    cin>>x;
    dx=pow(10,-5);
    der=(sin(x+dx)-sin(x-dx))/(2*dx);
    err=der-cos(x);
    cout<<"The derivative of sin(x) at value "<<setprecision(10)<<x<<" is "<<der<<endl;
    cout<<"The error of the calculation is "<<setprecision(10)<<err<<endl;
    return 0;
}
