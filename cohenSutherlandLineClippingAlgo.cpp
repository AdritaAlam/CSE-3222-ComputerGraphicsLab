#include <graphics.h>
#include<iostream>
#include <math.h>
using namespace std;


double xMin,xMax,yMin,yMax;

//Assign region code to each endpoints
const int inside = 0 ;       //0000
const int left1 = 1 ;       //0001
const int right1 = 2 ;     //0010
const int bottom = 4;     //0100
const int top = 8;       //1000


//compute the region code for a specific point x,y
int getCode(double x,double y){
    int codeGen = inside ;
    if (x < xMin)
        codeGen |= left1;
    else if (x > xMax)
        codeGen |= right1;
    if (y < yMin)
        codeGen |= bottom;
    else if (y > yMax)
        codeGen |= top;

    return codeGen;
}

void cohen(double x1,double y1,double x2,double y2){
    //code for point1 and point2
    int code1,code2;
    bool flag = false;
    code1 = getCode(x1,y1);
    code2 = getCode(x2,y2);

    while (true){
        if ((code1 == 0) && (code2 == 0)){ //   case1:completely inside
            flag = true;
            break;
        }
        else if (code1 & code2) break; // case2:completely outside of the window
        else{       //  case3:partially inside/outside

            int code;
            double m,x,y;
            m = (y2-y1)/(x2-x1);    //slope

            // finding the outsider point
            if (code1 != 0)
                code = code1;
            else
                code = code2;
            // finding the intersecting point
            if (code & top){
                x = x1+((yMax-y1)/m);
                y = yMax;
            }
            else if (code & bottom){
                x = x1+((yMin-y1)/m);
                y = yMin;
            }
            else if (code & left1){
                x = xMin;
                y = y1 + ((xMin-x1)*m) ;
            }
            else if (code & right1){
                x = xMax;
                y = y1 + ((xMax-x1)*m);
            }
            // replacing the outside point by intersecting point
            if (code == code1){
                x1 = x;
                y1 = y;
                code1 = getCode(x1,y1);
            }
            else {
                x2 = x ;
                y2 = y;
                code2 = getCode(x2,y2);
            }

        }
    }
    if (flag){
        setcolor(WHITE);
        rectangle(xMin,yMin,xMax,yMax);
        setcolor(BLUE);
        line(x1,y1,x2,y2);
        cout<<"Line accepted from "<<x1<<","<<y1<<"to "<<x2<<","<<y2<<endl;
    }
    else
        cout<<"The line is rejected."<<endl;
}

int main(){

    freopen("cohenInput.txt","r",stdin);
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");

    double x1,x2,y1,y2;
    int n;

    cout<<"Enter the coordinates of the rectangular area of interest: "<<endl;      //coordinates of top right and bottom left
    cin>>xMin>>yMin>>xMax>>yMax;

    cout<<"Enter the number of lines to check: "<<endl;
    cin>>n;

    cout<<"Enter the coordinates of the points: "<<endl;
    while (n--){
        cin>>x1>>y1>>x2>>y2;
        cohen(x1,y1,x2,y2);
        delay(50);
    }
    getch();

}




