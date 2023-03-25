#include <graphics.h>
#include<iostream>
#include <math.h>
using namespace std;


int fact(int n){
    if (n<=1)
        return 1;
    else
        return n*fact(n-1);

}

void bezierCurve(int *x,int *y,int n){
    double pX,pY,deg,degFact,u,b;
    deg = n-1;
    degFact = fact(deg);
    putpixel(x[0],y[0],GREEN);
    putpixel(x[n-1],y[n-1],BLUE);

    for (u=0.00;u<=1;u+=0.001){
        pX = 0 ;
        pY = 0;
        for (int i=0;i<=deg;i++){
            b = degFact*pow(u,i)*pow((1-u),deg-i)/ (fact(i)*fact(deg-i));
            pX+=b*x[i];
            pY+=b*y[i];
        }
        putpixel(pX,pY,LIGHTBLUE);
        delay(1);
    }

    for (int i=0;i<=deg;i++){
        circle(x[i],y[i],n);
    }
}




int main(){
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    int n;

    cout<<"Enter the number of control points: "<<endl;
    cin>>n;
    int x[n],y[n]; // 200 300 300 400 300 300 100 200
    cout<<"Enter the controls points: "<<endl;
    for (int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }


    bezierCurve(x,y,n);
    getch();

}
/*
10 10
80 150
150 300
400 100
*/
