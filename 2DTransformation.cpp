#include <bits/stdc++.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
using namespace std;

int main(){
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");

    int x1,x2,x3,y1,y2,y3,nx1,nx2,nx3,ny1,ny2,ny3,tx,ty,option,angle,rad,sx,sy,cx,cy;

    cout<<"Program for 2D Transformation:"<<endl;
    cout<<"Enter co-ordinates for triangle"<<endl;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    setcolor(BLUE);

    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);

    //getch();

    printf("Enter \n 1:Translation\n 2:Rotation\n 3:Scaling\n 4:Exit");
    cin>>option;

    switch(option){
        case 1:
            cout<<"Enter translation factor: ";

            cin>>tx>>ty;
            nx1 = x1 + tx;
            ny1 = y1 + ty;
            nx2 = x2 + tx;
            ny2 = y2 + ty;
            nx3 = x3 + tx;
            ny3 = y3 + ty;

            line(nx1,ny1,nx2,ny2);
            line(nx2,ny2,nx3,ny3);
            line(nx3,ny3,nx1,ny1);

            getch();


        case 2:
            cout<<"Enter rotation angle: "<<endl;
            cin>>angle;
            rad = (angle*3.14)/180;

            nx1 = abs(x1*cos(rad) - y1*sin(rad));
            ny1 = abs(x1*sin(rad) + y1*cos(rad));
            nx2 = abs(x2*cos(rad) - y2*sin(rad));
            ny2 = abs(x2*sin(rad) + y2*cos(rad));
            nx3 = abs(x3*cos(rad) - y3*sin(rad));
            ny3 = abs(x3*sin(rad) + y3*cos(rad));

            line(nx1,ny1,nx2,ny2);
            line(nx2,ny2,nx3,ny3);
            line(nx3,ny3,nx1,ny1);

            getch();


        case 3:
            cout<<"Enter scaling factor: "<<endl;
            cin>>sx>>sy;

            cx = (x1+x2+x3)/3;
            cy = (y1+y2+y3)/3;

            nx1 = cx + (x1-cx)*sx;
            ny1 = cy + (y1-cy)*sy;
            nx2 = cx + (x2-cx)*sx;
            ny2 = cy + (y2-cy)*sy;
            nx3 = cx + (x3-cx)*sx;
            ny3 = cy + (y3-cy)*sy;

            line(nx1,ny1,nx2,ny2);
            line(nx2,ny2,nx3,ny3);
            line(nx3,ny3,nx1,ny1);

            getch();
        case 4:
            break;
        default:
            cout<<"Enter your choice: "<<endl;
        }
    closegraph();
}

//          50 100 100 100 100 50 20 20

//          100 200 200 300 300 200








