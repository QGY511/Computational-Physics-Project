//
//  main.cpp
//  position
//
//  Created by QGY on 10/22/20.
//

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

double fposition (double t)
{
    double y;
    y=0.0+10.0*t+0.5*(-9.81)*t*t;
    return y;
}


double derivOperator1(double f(double),double aX,double aDel)
{
    double der1;
    der1=(f(aX+aDel)-f(aX-aDel))/(2*aDel);
    return der1; //theResultOfDerivative;
    
}
double derivOperator2(double f(double),double aX,double aDel)
{
    double der2;
    der2=(f(aX+aDel)+f(aX-aDel)-2*f(aX))/(aDel*aDel);
    return der2;
}

int main()
{
    double del=1.0e-5;
    double time[300],position[300],vel[300],acc[300];
    for (int i=0;i<300;i++)
    {
        time[i]=(double) i/100;
        position[i]=fposition((double)i/100);
        vel[i]=derivOperator1(fposition,(double) i/100,del);
        acc[i]=derivOperator2(fposition,(double) i/100,del);
        cout<<setprecision(10)<<derivOperator2(fposition,(double) i/100,del)<<endl;
    }
    return 0;
}
