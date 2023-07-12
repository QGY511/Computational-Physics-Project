//
//  main.cpp
//  PHY 102 Assignment 1
//
//  Created by QGY on 10/8/20.
//

#include <iostream>
#include <math.h>
using namespace std;

    int main()
    {
        int width, length, area;// declare width, length, and area as integer
        float radius;//radius is float type because it has decimal places.
        cout<<" Input the length of the rectangle : ";//read input length from user
        cin>>length;
        cout<<" Input the width of the rectangle : ";//read input width from user
        cin>>width;
        area=(length*width);
        cout<<" The area of the rectangle is : "<< area<< endl;//output the result.
        if(length==width)// when width=length. This rectangle is considered as a square.
        {
            radius=(sqrt(2)/2)*length;// to calculate the radius for the circle
            cout<<" The radius of the outscribing circle is : "<< radius<< endl;//output the result/
        }
        cout << endl;
        return 0;
    }
