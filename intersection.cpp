#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
bool isIntersected(struct Point,struct Point,struct Point,struct Point);
bool isCoolinear(struct Point,struct Point,struct Point);
int orientation(struct Point,struct Point,struct Point);

struct Point{
    int x;
    int y;
};

int main(){
    struct Point p1={1, 1}, q1={10, 1};
    struct Point p2 ={1, 2}, q2 ={10, 2};
    if(isIntersected(p1, q1, p2, q2)){
         cout << "Yes\n";
    }
    else{
         cout << "No\n";
    }
    p1 = {10, 0}, q1 = {0, 10};
    p2 = {0, 0}, q2 = {10, 10};
    if(isIntersected(p1, q1, p2, q2)){
         cout << "Yes\n";
    }
    else{
         cout << "No\n";
    }
    p1 = {-5, -5}, q1 = {0, 0};
    p2 = {1, 1}, q2 = {10, 10};
    if(isIntersected(p1, q1, p2, q2)){
         cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
}

int orientation(Point p,Point q,Point r){
   int result;
   result = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
   if(result==0){
        return 0;
   }
   return (result>0)?4:5;
}

bool isCoolinear(Point p,Point q,Point r){
    if(q.x<=max(p.x,r.x)&&q.x>=min(p.x,r.x)&&q.y<=max(p.y,r.y)&&q.y>= min(p.y,r.y)){
        return true;
    }
    return false;
}

bool isIntersected(Point p1,Point q1, Point p2,Point q2){
    int orientation1=orientation(p1,q1,p2);
    int orientation2= orientation(p1,q1,q2);
    int orientation3= orientation(p2,q2,p1);
    int orientation4= orientation(p2,q2,q1);
    if(orientation1!=orientation2&& orientation3!= orientation4 ){
        return true;
    }
    else if(orientation1==0 && isCoolinear(p1,p2,q1)){
        return true;
    }
    else if(orientation2==0 && isCoolinear(p1,q1,q2)){
        return true;
    }
    else if(orientation3==0&& isCoolinear(p2,p1,q2)){
        return true;
    }
    else if(orientation4==0&& isCoolinear(p2,q2,q1)){
        return true;
    }
    return false;
}
