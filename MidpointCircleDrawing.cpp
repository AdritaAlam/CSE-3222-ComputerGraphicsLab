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

void midpoint(int xc,int yc,int r){
    int p,x = 0,y = r;
    p = 1-r; // initial decision parameter

    while (x<=y){
        x++;
        if (p>=0){
            y--;
            p+=2*x-2*y+1;
        }
        else{
            p+=2*x+1;
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

    cout<<"Enter center coordinates: "<<endl;
    cin>>xc>>yc;

    cout<<"Enter the radius: "<<endl;
    cin>>r;

    midpoint(xc,yc,r);
    getch();

}




