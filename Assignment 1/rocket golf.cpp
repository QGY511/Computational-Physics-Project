//
//  main.cpp
//  rocket golf
//
//  Created by QGY on 10/13/20.
//

#include <iostream>
#include <math.h>
using namespace std;
double v,c,c2,angle,u1,ux1,uy1,ux,uy,y,M,A;
int main()
{
    cout<<"Enter the speed of the ball in the rocket's frame in units of c: ";//read c from user
    cin>>c;
    cout<<"Enter the angle in degrees with the respect to the horizontal: ";//read angle from user
    cin>>angle;
    if(c<0||c>1)// to check if the unit of c is in range.
    {
        cout<<"The unit of c is not in range of [0,1]. Please try again";
        cout<<endl;
        return 0;
    }
    v=3*pow(10,8)/2.0;//this is the v in the equation which is the horizontal speed of the rocket=C*1/2
    c2=3*pow(10,8)*3*pow(10,8);//this is the value for C^2.
    u1=3*pow(10,8)*c;//this is the golf ball's speed u prime.
    ux1=u1*cos(angle*(3.14/180));//this is the x component of the speed of the ball in the rocket's frame.
    uy1=u1*sin(angle*(3.14/180));//this is the y component of the speed of the ball in the rocket's frame.
    y=1.0/sqrt(1.0-0.25);//this is the gamma value.
    ux=(ux1+v)/(1.0+(v*ux1/c2));//x components of the speed of the ball in the Earth's frame.
    uy=uy1/(y*(1.0+(v*ux1/c2)));//y components of the speed of the ball in the Earth's frame.
    M=sqrt(ux*ux+uy*uy);//magnitude of the speed of the ball in the Earth's frame.
    A=atan(uy/ux)*(180/3.14);//angle of the speed of the ball in the Earth's frame.
    cout<<"magnitude of the velocity in Earth's frame= "<<M;//output the magnitude.
    cout<<endl;
    cout<<"angle of the velocity in Earth's frame= "<<A;//output the angle.
    cout<<endl;
    return 0;
}
