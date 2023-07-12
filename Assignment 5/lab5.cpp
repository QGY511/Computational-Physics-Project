//
//  lab5.cpp
//  lab5
//
//  Created by QGY on 11/17/20.
//

#include <iostream>
using namespace std;
double recurrenceRelation(double x,double r)
{
    return r*x*(1-x);// logistic map function.
}
int lab5 ()
{
    const int n=300;//go through iternation 300 times.
    double v[n+1],x,y;
    v[0]=0.2;// inital x =0.2.
    TH2D* histo2d = new TH2D("histo2d","Histogram 2D",2000,1,4,2000,0,1);
    for (double r=1.0;r<4.0;r=r+0.0015)// total steps=2000.
    {
        x = r;
        for (int i=0;i<n;++i)
        {
            v[i+1]=recurrenceRelation(v[i],r);
            y=v[i+1];
            if(i>200)//store values after 200 iterations.
            {
                histo2d->Fill(x,y);
            }
        }
    }
    TCanvas* cnv = new TCanvas("cnv","A 2D Histogram",500,500);
    histo2d->Draw("col");
    return 0;
}
