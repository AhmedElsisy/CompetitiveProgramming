#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const double pi = acos(-1.0);
double DEG_to_RAD(double d) { return d * pi / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / pi; }

struct P {
    double x , y;
    P(){}
    P(double a , double b) : x(a) , y(b){}
    bool operator ==(P const &other){return fabs(x - other.x) <= EPS && fabs(y - other.y) <= EPS;}
    P operator -(P const &other){return P(x - other.x , y - other.y);}
    void sc() {scanf("%d%d" , &x , &y); }
    double dist(P const &other){return hypot(x - other.x , y - other.y);}
};

struct V {
    double x , y;
    V(){}
    V(double a , double b) : x(a) , y(b){}
    void sc(){scanf("%d%d" , &x , &y);}
    double dot(const V &other){return x * other.x + y * other.y;}   // a . b = |a| . |b| . cos(theta)
    double cross(const V &other){return x * other.y - other.x * y;} // a x b = |a| . |b| . sin(theta)
    double ang(){return atan2(y , x);}
    V scale(double s){return V(x * s , y * s);}
    double dist(){return hypot(x , y);}
};

double point_segment_distance(P c , P a , P b){     // segment ab , point c
    V ab(b.x - a.x , b.y - a.y) , ba(a.x - b.x , a.y - b.y);
    V ac(c.x - a.x , c.y - a.y) , bc(c.x - b.x , c.y - b.y);
    if(ab.dot(ac) < 0.0 || ba.dot(bc) < 0.0){   // the perpendicular line not included in segment
        return min(a.dist(c) , b.dist(c));
    }
    else{
        return ab.cross(ac) / a.dist(b);    // height of the triangle abc
    }
}

double point_line_distance(P c , P a , P b){        // line ab , point c
    V ab(b.x - a.x , b.y - a.y) , ba(a.x - b.x , a.y - b.y);
    V ac(c.x - a.x , c.y - a.y) , bc(c.x - b.x , c.y - b.y);
    r


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif


}
