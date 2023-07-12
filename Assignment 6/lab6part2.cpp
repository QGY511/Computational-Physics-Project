//
//  main.cpp
//  lab6
//
//  Created by Guanyu Qian on 2020/12/1.
//

#include <iostream>
#include <math.h>
using namespace std;
int lab6part2()
{
    TF1* analytic = new TF1("analytic","x*(-3*log(x)+1)^(1.0/3.0)",0,1.3956);
    analytic->SetNpx(1000);
    TCanvas* euCnv1 = new TCanvas("euCnv1","ODE",500,500);
    analytic->Draw();
    analytic->SetLineColor(1);
    double xmin=1.0;
    double xmax=1.4;
    double step=0.05;//change this value to 0.05, 0.1, and 0.2.
    int Nsteps=20; //maximum steps in this case is 20. for simplicity, I choose Nsteps=20 for all steps.
    const int maxPoints = 1000;
    if (Nsteps>maxPoints)
    {
        cout << "Need to declare array of larger size: " << Nsteps << endl;
        return 0;
    }
    cout << "Nsteps " << Nsteps << endl;
    double yVal[maxPoints];
    double xVal[maxPoints];
    double y1Val[maxPoints];
    double x1Val[maxPoints];
    xVal[0] = xmin;
    yVal[0] = 1.0;
    x1Val[0] = 1.0;
    y1Val[0] = 1.0;
    for (int i=0; i<=Nsteps; ++i)
    {
        xVal[i+1]=xVal[i]+step;
        x1Val[i+1]=x1Val[i]+0.5*step;
        yVal[i+1]=yVal[i]+0.5*step*(yVal[i]/xVal[i]-pow(xVal[i]/yVal[i],2.0));
        y1Val[i+1]=y1Val[i]+step*(yVal[i+1]/(x1Val[i+1])-pow((x1Val[i+1])/yVal[i+1],2.0));
    }
    TGraph* numerical = new TGraph(Nsteps,xVal,y1Val);
    numerical->SetLineColor(2);
    numerical->Draw("L");
    xVal[0] = xmin;
    yVal[0] = 1.0;
    x1Val[0] = xmin;
    y1Val[0] = 1.0;
    for (int i=0; i<=Nsteps; ++i)
    {
        xVal[i+1]=xVal[i]-step;
        x1Val[i+1]=xVal[i]-0.5*step;
        yVal[i+1]=yVal[i]-0.5*step*(yVal[i]/xVal[i]-pow(xVal[i]/yVal[i],2.0));
        y1Val[i+1]=y1Val[i]-step*(yVal[i+1]/(x1Val[i+1])-pow((x1Val[i+1])/yVal[i+1],2.0));
    }
    TGraph* numerical2 = new TGraph(Nsteps,xVal,y1Val);
    numerical2->SetLineColor(3);
    numerical2->Draw("L");
    return 0;
}



