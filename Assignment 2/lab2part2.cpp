//
//  main.cpp
//  derivative operator
//
//  Created by QGY on 10/22/20.
//

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

double cube (double aD)//same as the example in the slides
{
    return pow(aD,3);
}

double linear(double aD)//same as the example in the slides
{
    return pow(aD,1);
}

double derivOperator1(double f(double),double aX,double aDel)
{
    double der1;
    der1=(f(aX+aDel)-f(aX-aDel))/(2*aDel);//central difference method to calculate the first derivative of the function.
    return der1; // return the result.
}
double derivOperator2(double f(double),double aX,double aDel)
{
    double der2;
    der2=(f(aX+aDel)+f(aX-aDel)-2.0*f(aX))/(aDel*aDel);//central difference method to calculate the second derivative of the function.
    return der2;//return the result.
}

int main()
{
    double del = 1.0e-5,x;
    int choice;
    cout<<"Choose a function:"<< endl;
    cout<<"1) cube "<< endl;
    cout<<"2) linear "<< endl;
    cin>>choice;// same as the example in the slides.
    cout<<"Enter x value: "<<endl;
    cin>>x;//ask for x value.
    switch (choice)
    {
        case 1:// if it is cube do the fllowing.
            cout<<"The first calculated derivative of x^3 at "<<x<<" is "<<setprecision(10)<<derivOperator1(cube,x,del)<<endl;//print the first derivative of x^3.
            cout<<"The second calculated derivative of x^3 at "<<x<<" is "<<setprecision(10)<<derivOperator2(cube,x,del)<<endl;//print the second derivative of x^3.
            break;
        case 2:// if it is linear do the following.
            cout<<"The first calculated derivative of x at "<<x<<" is "<<setprecision(10)<<derivOperator1(linear,x,del)<<endl;//print the first derivative of x.
            cout<<"The second calculated derivative of x at "<<x<<" is "<<setprecision(10)<<derivOperator2(linear,x,del)<<endl;//print the second derivative of x.
            break;
        default:// output error message
            cout <<"Incorrect input, exiting."<<endl;
    }
return 0;
}
//It works better when h=10^-5. When choosing h=10^-7, it will run into machine precision issues, which means calculation error is larger.
//The largest value of h that I can choose is h=10^-8. When I choose h=10^-9, it runs into serious machine precision issue.
