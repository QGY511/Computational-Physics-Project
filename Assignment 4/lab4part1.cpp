//
//  lab4part1.cpp
//  lab4
//
//  Created by QGY on 11/10/20.
//

#include <iostream>
#include <math.h>
double functionx(double aX)
{
    return exp(aX)*log(aX)-cos(aX);
}
int lab4part1()
{
    TF1* func = new TF1("func","exp(x)*log(x)-cos(x)",0,4);
    func->SetNpx(1000);
    TCanvas* funcCnv = new
    TCanvas("funcCnv","Bisection Method",500,500);
    func->Draw();
    TLine* xaxis = new TLine(0,0,4,0);
    xaxis->Draw();
    double lowLim=0;
    double uppLim=4;
    double x_root = uppLim;
    size_t iteration = 0;
    double delta = 1e-8;
    while (fabs(functionx(x_root))>delta)
    {
        ++iteration;
        x_root=(lowLim+uppLim)/2.0;
        cout << "x_" <<iteration <<" = " << x_root;
        cout << ", f(x)= " << functionx(x_root) << endl;
        if (functionx(x_root)==0.0) break;
        if (functionx(x_root)*functionx(lowLim)<0)
        {
            uppLim=x_root;
        }
        else
        {
            lowLim=x_root;
        }
    }
    TMarker* rootMarker =new TMarker(x_root,functionx(x_root),20);
    rootMarker->SetMarkerColor(4);
    rootMarker->SetMarkerSize(1.5);
    rootMarker->SetMarkerStyle(21);
    rootMarker->Draw("same");
    return 0;
}
