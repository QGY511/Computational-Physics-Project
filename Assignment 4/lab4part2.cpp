//
//  lab4part2.cpp
//  lab4
//
//  Created by QGY on 11/10/20.
//

#include <iostream>
#include <math.h>
double functionx(double aX)
{
    return aX*aX*aX-2.0*aX-2.0;
}

double derivativex(double aX)
{
    return 3.0*aX*aX-2.0;
}

int lab4part2()
{
    TF1* func = new TF1("func","x^3-2.0*x-2.0",-4,2);
    func->SetNpx(1000);
    TCanvas* funcCnv = new
    TCanvas("funcCnv","Newton's Method",500,500);
    func->Draw();
    TLine* xaxis = new TLine(-4,0,2,0);
    xaxis->Draw();
    double lowLim=-4;
    double uppLim=2;
    double x_root = uppLim;
    size_t iteration = 0;
    double delta = 1e-8;
    while (fabs(functionx(x_root))>delta)
    {
        ++iteration;
        x_root=x_root-functionx(x_root)/derivativex(x_root);
        cout << "x_" <<iteration <<" = " << x_root;
        cout << ", f(x)= " << functionx(x_root) << endl;
        if (functionx(x_root)==0.0) break;
    }
    TMarker* rootMarker =
    new TMarker(x_root,functionx(x_root),20);
    rootMarker->SetMarkerColor(2);
    rootMarker->SetMarkerSize(1.5);
    rootMarker->Draw("same");
    return 0;
}
