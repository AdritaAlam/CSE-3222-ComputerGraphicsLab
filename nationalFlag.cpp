#include <graphics.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");


    setcolor(GREEN);
    rectangle(50,50,220,150);
    //rectangle(2,2,6,4);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(51,51,GREEN);

    setcolor(WHITE);
    rectangle(40,40,50,300);
    //rectangle(1.75,2,2,6);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(41,41,WHITE);


    setcolor(RED);
    circle(130,100,30);
    setfillstyle(SOLID_FILL,RED);
    floodfill(131,101,RED);



    getch();
    return 0;

}
