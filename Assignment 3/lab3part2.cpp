//
//  main.cpp
//  test
//
//  Created by QGY on 10/27/20.
//

#include <iostream>
#include <cmath>
using namespace std;

double integrand(double aX)
{
    return aX*aX*aX;
}


double trapezoidal(double leftL, double rightL, int n, double integrand(double))
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
    result=dx*(sum1+sum2-integrand(x)+integrand(x+n*dx))/3.0;
    return result;
}

int lab3part2()
{
    double actual,error_t,error_s,et[1024],es[1024],ne[1024],ns[1024];
    actual=0.25;
    for(int n=1;n<1024;n++)
    {
        error_t=actual-trapezoidal(0,1,n,integrand);
        et[n-1]=error_t;
        ne[n-1]=(double)1.0/n;
    }
    for (int k=1;k<1024;k++)
    {
        error_s=actual-simpsons(0,1,2*k,integrand);
        es[k-1]=error_s;
        ns[k]=(double)1.0/(2*k);
    }
    TCanvas *c1 = new TCanvas("c1","Simpons error",200,10,700,500);// create canvas for y(t)
    double x[1024], y[1024];
    for (int i=0;i<1024;i++)
    {
        x[i] =ns[i];
        y[i] =es[i];
    }
    TGraph* gr = new TGraph(300,x,y);
    gr->SetMaximum(1.);//set the range for y axis
    gr->SetMinimum(-1.);
    gr->Draw("AC*");
    
    TCanvas *c2 = new TCanvas("c2","Trapezoidal error",200,10,700,500);// create canvas for y(t)
    double x2[1024], y2[1024];
    for (int j=0;j<1024;j++)
    {
        x2[j] =ne[j];
        y2[j] =et[j];
    }
    TGraph* gr2 = new TGraph(300,x2,y2);
    gr2->Draw("AC*");
    return 0;
}
// For trapezoidal, their error are converging to 0 as N increases.
// For simpsons, it has no error in this case
