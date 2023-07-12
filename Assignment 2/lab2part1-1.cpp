//
//  main.cpp
//  derivative
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
    cout<<"Enter the value for the x in radian to calculate the derivative of sin(x): ";//ask for value of x in radian.
    cin>>x;
    dx=pow(10,-5);//dx=h=10^-5
    der=(sin(x+dx)-sin(x))/dx;//this is the Discrete Forward-difference operator
    err=der-cos(x);// the actual derivative of sin(x) is cos(x). So that we can calculate the error by substracting cos(x).
    cout<<"The derivative of sin(x) at value "<<setprecision(10)<<x<<" is "<<der<<endl;//print derivative.
    cout<<"The error of the calculation is "<<setprecision(10)<<err<<endl;//print error.
    return 0;
}
// At x=1.57079632679, derivative = -5.000000414e-06. The error of the calculation is -5.000000414e-06.
