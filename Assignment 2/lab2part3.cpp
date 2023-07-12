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

double fposition (double t)// this defines the fuction y(t).
{
    double y;
    y=0.0+10.0*t+0.5*(-9.81)*t*t;//here I choose y0=0,v0=10,a=-9.81.
    return y;
}


double derivOperator1(double f(double),double aX,double aDel)//same as part2.
{
    double der1;
    der1=(f(aX+aDel)-f(aX-aDel))/(2*aDel);
    return der1;
    
}
double derivOperator2(double f(double),double aX,double aDel)//same as part 2.
{
    double der2;
    der2=(f(aX+aDel)+f(aX-aDel)-2*f(aX))/(aDel*aDel);
    return der2;
}

int lab2part3()
{
    double del=1.0e-5;
    double time[300],position[300],vel[300],acc[300];//create arrays.
    for (int i=0;i<300;i++)//for 300 points, each separated by 0.01 second.
    {
        time[i]=(double) i/100;//arry for t.
        position[i]=fposition((double)i/100);//array for y(t).
        vel[i]=derivOperator1(fposition,(double) i/100,del);//array for v(t).
        acc[i]=derivOperator2(fposition,(double) i/100,del);//array for a(t).
    }
    TCanvas *c1 = new TCanvas("c1","y(t) v t",200,10,700,500);// create canvas for y(t)
    double x[300], y[300];
    for (int j=0;j<300;j++)
    {
        x[j] =time[j];
        y[j] =position[j];
    }
    TGraph* gr = new TGraph(300,x,y);
    gr->Draw("AC*");
    
    TCanvas *c2 = new TCanvas("c2","v(t) v t",200,10,700,500);// create canvas for v(t)
    double x2[300], y2[300];
    for (int k=0;k<300;k++)
    {
        x2[k] =time[k];
        y2[k] =vel[k];
    }
    TGraph* gr2 = new TGraph(300,x2,y2);
    gr2->Draw("AC*");
    
    TCanvas *c3 = new TCanvas("c3","a(t) v t",200,10,700,500);// create canvas for a(t)
    double x3[300], y3[300];
    for (int l=0;l<300;l++)
    {
        x[l] =time[l];
        y[l] =acc[l];
    }
    TGraph* gr3 = new TGraph(300,x,y);
    gr3->SetMaximum(-5.);//set the range for y axis
    gr3->SetMinimum(-15.);
    gr3->Draw("AC*");
    return 0;
}

