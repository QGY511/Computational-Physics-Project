//
//  lab7part2.cpp
//  lab7
//
//  Created by Guanyu Qian on 2020/12/7.
//

#include <iostream>
#include <math.h>
using namespace std;
double helperFunctionvx(double vx)
{
    //definition of y’
    return -vx;
}

double helperFunctionvy(double vy)
{
    //definition of y’
    return -9.81-vy;
}

int lab7part2()
{
    double tmin=0;
    double tmax=10;
    double step=0.01;//time t.
    int Nsteps=static_cast<int>((tmax-tmin)/step);
    const int maxPoints = 10000;
    if (Nsteps>maxPoints)
    {
        cout << "Need to declare array of larger size: " << Nsteps << endl;
        return 0;
    } // Arrays to hold all x and y values.
    double tVal[maxPoints];
    double vyVal[maxPoints];
    double vxVal[maxPoints];
    double xVal[maxPoints];
    double yVal[maxPoints];
    double theta[maxPoints];
    double range[maxPoints];
    double error=pow(10,-3);
    double thetamax;
    double rangemax;
    // initial condition
    tVal[0] = 0;
    yVal[0] = 0;
    xVal[0] = 0;
    theta[0] = 0;
    range[0] = 0;
    for (int j=0; j<Nsteps;++j)
    {
        theta[j+1]=theta[j]+0.00158;//theta is in range 0 to pi/2 range.
        vxVal[0] = 30*cos(theta[j]);//initial x axis speed.
        vyVal[0] = 30*sin(theta[j]);//initial y axis speed.
        for (int i=0; i<Nsteps; ++i)
        {
            //Below is calculation for vx.
            tVal[i+1]=tVal[i]+step; //x+h
            double tValhalf=tVal[i]+step/2.; // x+h/2
            //calculate k1
            double kx1= helperFunctionvx(vxVal[i]);
            //calculate k2, use y_midpoint estimated with k1
            double kx2=helperFunctionvx(vxVal[i]+step/2.0*kx1);
            //calculate k3 use y_midpoint estimated with k2
            double kx3 = helperFunctionvx(vxVal[i]+step/2.0*kx2);
            //calculate k4, use k3 to get a first estimate of y[i+1]
            double kx4 = helperFunctionvx(vxVal[i]+step*kx3);
            //propagate through the interval to obtain final y[i+1]
            vxVal[i+1]=vxVal[i]+step*(kx1/6.0+kx2/3.+kx3/3.+kx4/6.);
            xVal[i+1]=xVal[i]+step*vxVal[i];

            //Below is calculation for vy.
            //calculate k1
            double ky1= helperFunctionvy(vyVal[i]);
            //calculate k2, use y_midpoint estimated with k1
            double ky2=helperFunctionvy(vyVal[i]+step/2.0*ky1);
            //calculate k3 use y_midpoint estimated with k2
            double ky3 = helperFunctionvy(vyVal[i]+step/2.0*ky2);
            //calculate k4, use k3 to get a first estimate of y[i+1]
            double ky4 = helperFunctionvy(vyVal[i]+step*ky3);
            //propagate through the interval to obtain final y[i+1]
            vyVal[i+1]=vyVal[i]+step*(ky1/6.0+ky2/3.+ky3/3.+ky4/6.);
            yVal[i+1]=yVal[i]+step*vyVal[i];
            if (0-error<yVal[i]<0+error)//stop if the object hits the ground y(x)=0
            {
                break;
            }
            range[j]=xVal[i];
        }
        tVal[0] = 0;//reset t to 0 after loop.
        yVal[0] = 0;//reset x to 0 after loop.
        xVal[0] = 0;//reset y to 0 after loop.
    }
    rangemax=*max_element(range,range+Nsteps);//the max range value.
    for (int k=0;k<Nsteps;++k)
    {
        if(range[k]==rangemax)
        {
            thetamax=theta[k];//coresponding theata value.
        }
    }
    TCanvas *c1 = new TCanvas("c1","R-K Method",500,500);
    TGraph* gr = new TGraph(Nsteps,theta,range);
    gr->SetMaximum(30.);
    gr->SetMinimum(0.);
    gr->SetTitle("Max Distance vs angle");
    gr->GetXaxis()->SetTitle("Angle/radian");
    gr->GetYaxis()->SetTitle("Max Range/m");
    gr->Draw();
    TMarker* rootMarker =new TMarker(thetamax,rangemax,20);//mark the maximum value.
    rootMarker->SetMarkerColor(4);
    rootMarker->SetMarkerSize(1.5);
    rootMarker->SetMarkerStyle(8);
    rootMarker->Draw();
    return 0;
}
