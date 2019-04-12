#include<bits/stdc++.h>
using namespace std;
struct Point midPointOfLineSegment(Point,Point);

struct Point{
    int x;
    int y;

};

int main(){
    struct Point p1={4,6},p2={8,16};
    struct Point midPoint;
    midPoint=midPointOfLineSegment(p1,p2);
    cout<<"The mid Point of the line segment : "<<midPoint.x<<" "<<midPoint.y<<endl;

}

struct Point midPointOfLineSegment(Point p1, Point p2){
   struct Point midPoint;
   midPoint.x= (p1.x+p2.x)/2.0;
   midPoint.y= (p1.y+p2.y)/2.0;
   return (midPoint);
}
