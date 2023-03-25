#include <graphics.h>
#include<iostream>
#include <math.h>
using namespace std;


void bresenham(int x1,int y1,int x2,int y2){
    int dx,dy,p,j=y1;
    if (x1>x2){
        swap(x1,x2);
        swap(y1,y2);
    }
    dx = x2 -x1;
    dy = y2 - y1;
    p = 2*dy - dx ; // decision parameter

    for (int i=x1;i<=x2;i++){ // until it reaches the end point
            putpixel(i,j,LIGHTBLUE);
            i++;
            if (p<0){
                p+=2*dy;

            }
            else{
                j++;
                p+=2*dy - 2*dx;
            }
    }
}

int main(){
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    int x1,y1,x2,y2;

    cout<<"Enter the starting and end points: "<<endl;
    cin>>x1>>y1>>x2>>y2;

    bresenham(x1,y1,x2,y2);
    getch();

}


