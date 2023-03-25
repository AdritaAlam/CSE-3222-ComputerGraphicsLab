#include <graphics.h>
#include<iostream>
#include <math.h>
using namespace std;

void circleDrawing(int xc,int yc,int x,int y){

    putpixel(xc+x,yc+y,LIGHTCYAN);
    putpixel(xc+y,yc+x,LIGHTCYAN);
    putpixel(xc+x,yc-y,LIGHTCYAN);
    putpixel(xc-y,yc+x,LIGHTCYAN);
    putpixel(xc-x,yc-y,LIGHTCYAN);
    putpixel(xc-y,yc-x,LIGHTCYAN);
    putpixel(xc-x,yc+y,LIGHTCYAN);
    putpixel(xc+y,yc-x,LIGHTCYAN);

}

void circleBresenham(int xc,int yc,int r){
    int p,x = 0,y = r;
    p = 3-2*r; // initial decision parameter

    while (x<=y){
        x++;
        if (p>=0){
            y--;
            p+=4*(x-y)+10;
        }
        else{
            p+=4*x+6;
        }
    circleDrawing(xc,yc,x,y);
    delay(50);
    }
}

int main(){
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");

    int xc,yc,r;

    cout<<"Enter center co-ordinates: "<<endl;
    cin>>xc>>yc;

    cout<<"Enter the radius: "<<endl;
    cin>>r;

    circleBresenham(xc,yc,r);
    getch();

}



