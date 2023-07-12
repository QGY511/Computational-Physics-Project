//
//  main.cpp
//  lab6
//
//  Created by Guanyu Qian on 2020/12/1.
//

#include <iostream>
#include <math.h>
using namespace std;
int lab6part3()
{
    TF1* analytic = new TF1("analytic","sin(x+TMath::Pi()/2.0)",0.1,35);
    analytic->SetNpx(1000);
    TCanvas* euCnv2 = new TCanvas("euCnv2","SHOEuler",500,500);
    analytic->Draw();
    analytic->SetLineColor(1);
    double tmin=0.0;
    double tmax=35.0;
    double step=0.01;
    int Nsteps=static_cast<int>((tmax-tmin)/step);
    const int maxPoints = 3501;
    if (Nsteps>maxPoints)
    {
        cout << "Need to declare array of larger size: "<< Nsteps << endl;
        return 0;
    }
    cout << "Nsteps " << Nsteps << endl;
    double vVal[maxPoints];
    double xVal[maxPoints];
    double tVal[maxPoints];
    double vmid[maxPoints];
    double xmid[maxPoints];
    tVal[0] = tmin;
    xVal[0] = 1.0;
    vVal[0] = 0.0;
    for (int i=0; i<Nsteps; ++i)
    {
        vmid[i+1]=vVal[i]-0.5*step*xVal[i];
        xmid[i+1]=xVal[i]+0.5*step*vVal[i];
        tVal[i+1]=tVal[i]+step;
        xVal[i+1]=xVal[i]+step*vmid[i+1];
        vVal[i+1]=vVal[i]-step*xmid[i+1];
    }
    TGraph* numericalX = new
    TGraph(Nsteps,tVal,xVal);
    numericalX->SetLineColor(2);
    numericalX->Draw("L");
    TGraph* numericalV = new
    TGraph(Nsteps,tVal,vVal);
    numericalV->SetLineColor(4);
    numericalV->Draw("L");
    return 0;
}



