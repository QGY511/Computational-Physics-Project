//
//  main.cpp
//  Lab3_continued
//
//  Created by QGY on 11/3/20.
//

#include <iostream>
#include <cmath>
using namespace std;

double integrand1(double aX)//This is the function that we need calculate the integral of
{
    double result;
    result=sqrt(8)*(1/(sqrt(cos(aX)-cos(0.1))));
    return result;
}

double integrand2(double aX)//This is the function that we need calculate the integral of
{
    double result;
    result=sqrt(8)*(1/(sqrt(cos(aX)-cos(0.523598))));
    return result;
}
double integrand3(double aX)//This is the function that we need calculate the integral of
{
    double result;
    result=sqrt(8)*(1/(sqrt(cos(aX)-cos(0.785398))));
    return result;
}
double integrand4(double aX)//This is the function that we need calculate the integral of
{
    double result;
    result=sqrt(8)*(1/(sqrt(cos(aX)-cos(1.047197))));
    return result;
}

double trapezoidal(double leftL, double rightL, int n, double integrand(double))//This defines trapazodial rule to calculate the integral
{
    double x,dx,sum,result;
    x=leftL;
    dx=(rightL-leftL)/n;
    sum=0;
    result=0;
    for(int i=1;i<n;i++)
    {
        sum+=2*integrand(x+i*dx);
    }
    result=0.5*(sum+integrand(x)+integrand(x+n*dx))*dx;
    return result;
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
    double result1,result2,result3,result4;
    int interval=100000;
    result1=simpsons(0,0.1,interval,integrand1);
    result2=simpsons(0,0.523598,interval,integrand2);
    result3=simpsons(0,0.785398,interval,integrand3);
    result4=simpsons(0,1.047197,interval,integrand4);
    cout<<"Integration of Pendulum problem at theta=0.1 equals "<<result1<<endl;
    cout<<"Integration of Pendulum problem at theta=pi/6 equals "<<result2<<endl;
    cout<<"Integration of Pendulum problem at theta=pi/4 equals "<<result3<<endl;
    cout<<"Integration of Pendulum problem at theta=pi/3 equals "<<result4<<endl;
    return 0;
}
