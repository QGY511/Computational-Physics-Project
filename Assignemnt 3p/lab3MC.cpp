//
//  main.cpp
//  monte carlo
//
//  Created by QGY on 11/3/20.
//

#include <iostream>
#include <cmath>
using namespace std;

double integrand(double aX)
{
    return sqrt(1-aX*aX);
}


int lab3MC()
{
    double x,y,sum,n,result,diff;
    TH1D* histoName = new TH1D("Values","MC Integration;x-axis (units);Counts",100,5,-5);
    cout<<"Enter the value of N: "<<endl;
    cin>>n;
    sum=0;
    TRandom3 rnd(100);
    for(int j=0;j<100;j++)
    {
        for(int i=0;i<n;i++)
        {
            x=rnd.Uniform(-1,1);
            y=rnd.Uniform(0,1);
            if(y<integrand(x))
            {
                sum+=1;
            }
        }
        result=2*2*(sum/n);
        diff=3.1415926-result;
        sum=0;
        histoName->Fill(diff);
    }
    histoName->Draw("e");
    return 0;
}
