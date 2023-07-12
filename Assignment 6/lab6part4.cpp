//
//  main.cpp
//  lab6
//
//  Created by Guanyu Qian on 2020/12/1.
//

#include <iostream>
#include <math.h>
using namespace std;
int lab6part4()
{

    TF1* analytic = new TF1("analytic","sin(x)",0,20);
    analytic->SetNpx(1000);
    TCanvas* penCnv = new TCanvas("euCnv2","Pendulum Motion",500,500);
    TMarker*penMk = new TMarker(0,0,20);
    TLine*LineAnim = new TLine(0,0,1,0);
    LineAnim->SetLineWidth(1);
    analytic->Draw();
    analytic->SetLineColor(1);
    analytic->SetMaximum(10.);
    analytic->SetMinimum(-10.);
    double tmin=0.0;
    double tmax=20.0;
    double step=0.01;
    int Nsteps=static_cast<int>((tmax-tmin)/step);
    const int maxPoints = 2001;
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
    double x1[maxPoints];
    double y1[maxPoints];
    tVal[0] = tmin;
    xVal[0] = 3.14/2.0;
    vVal[0] = 0.0;
    for (int i=0; i<100; ++i)
    {
        /*
         vmid[i+1]=vVal[i]-0.5*step*xVal[i];
        xmid[i+1]=xVal[i]+0.5*step*vVal[i];
        tVal[i+1]=tVal[i]+step;
        xVal[i+1]=xVal[i]+step*vmid[i+1];
        vVal[i+1]=vVal[i]-step*sin(xmid[i+1])*9.81;
         */
        
        tVal[i+1]=tVal[i]+step;
        vVal[i+1]=vVal[i]-step*9.81*sin(xVal[i]);
        xVal[i+1]=xVal[i]+0.5*step*(vVal[i]+vVal[i+1]);
        x1[i]=sin(xVal[i]);
        y1[i]=-cos(xVal[i]);
        
    }
    /*TGraph* numericalX = new
    TGraph(Nsteps,tVal,xVal);
    numericalX->SetLineColor(2);
    numericalX->Draw("L");
    numericalX->SetMaximum(10.);
    numericalX->SetMaximum(-10.);
    TGraph* numericalV = new
    TGraph(Nsteps,tVal,vVal);
    numericalV->SetLineColor(4);
    numericalV->Draw("L");
    numericalV->SetMaximum(10.);
    numericalV->SetMaximum(-10.);
    return 0;*/
}
   /* for (size_t j=0;j<100;++j)//2000 is too large, deciedw to only see the sirst 100 values.
    {
        gPad->Clear();
        penCnv->DrawFrame(-1.5,-1.5,1.5,1.5,"Pendulum Motion");
        penMk->DrawMarker(x1[j],y1[j]);
        LineAnim->DrawLine(0,0,x1[j],y1[j]);
        TGraph*path= new TGraph(j+1,x1,y1);
        path->SetLineColor(1);
        path->Draw("L");
        penCnv->SaveAs("PM.gif+1");
    }
    return 0;
}
*/
