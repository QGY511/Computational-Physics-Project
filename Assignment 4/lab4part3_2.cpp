//
//  lab4part3_2.cpp
//  lab4
//
//  Created by QGY on 11/10/20.
//

#include <iostream>
#include <math.h>
double functionx(double aX)
{
    return sqrt(20-aX*aX)+aX/tan(aX);
}

int lab4part3_2()
{
    TF1* func = new TF1("func","sqrt(20-x^2)",0,4);
    TF1* func2 =new TF1("func2","-x/tan(x)",0,4);
    func->SetNpx(1000);
    func2->SetNpx(1000);
    func->SetTitle("Intersection of two equations");
    TCanvas* funcCnv = new
    TCanvas("funcCnv","QM walls",500,500);
    func->Draw();
    func->SetLineColor(4);
    func2->Draw("same");
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
        if (functionx(x_root)==0) break;
        if (functionx(x_root)*functionx(lowLim)<0)
        {
            uppLim=x_root;
        }
        else
        {
            lowLim=x_root;
        }
    }
    cout << "Find the one root"<< " = " << x_root << endl;
    TMarker* rootMarker =
    new TMarker(x_root,functionx(x_root),20);
    rootMarker->SetMarkerColor(4);
    rootMarker->SetMarkerSize(1.5);
    rootMarker->SetMarkerStyle(21);
    rootMarker->Draw("same");
    return 0;
}


/*
double functionx(double aX)
{
    return sqrt(20-aX*aX)+aX/tan(aX);
}

double derivativex(double aX)
{
    return -aX*(1/sin(aX))*(1/sin(aX))+1/tan(aX)-aX/sqrt(20-aX*aX);
}

int lab4part3_2()
{
    TF1* func = new TF1("func","sqrt(20-x^2)",0,4);
    TF1* func2 =new TF1("func2","-x/tan(x)",0,4);
    func->SetNpx(1000);
    func2->SetNpx(1000);
    func->SetTitle("Intersection of two equations");
    TCanvas* funcCnv = new
    TCanvas("funcCnv","QM walls",500,500);
    func->Draw();
    func->SetLineColor(4);
    func2->Draw("same");
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
*/

//Above is the newton's method for QM.
