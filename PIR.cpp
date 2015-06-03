#include<iostream>
#include<bits/stdc++.h>
#define s(a) a*a
#define sq(a) a*a
using namespace std;
double area(double x, double y, double z)
{
    double s = (x+y+z)/2;
    return sqrt(s*(s-x)*(s-y)*(s-z));
}
int main()
{
    double a,b,c,d,e,f,ans,V, R;
    double a1, a2, a3, a4;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c>>d>>e>>f;
        ans = ( s(a)+s(b)+s(c)+s(d)+s(e)+s(f) ) * ( s(a*f) + s(b*e)+s(c*d));
        ans = ans - 2*sq(a*f)*(a*a+f*f);
        ans = ans - 2*sq(b*e)*(b*b+e*e);
        ans = ans - 2*sq(c*d)*(c*c+d*d);
        ans = ans - (((sq(a)+sq(f))*(sq(b)+sq(e))*(sq(c)+sq(d)))/2);
        ans = ans + (((sq(a)-sq(f))*(sq(b)-sq(e))*(sq(c)-sq(d)))/2);
        V = sqrt(ans) / 12.0;
        a1 = area(a,d,b);
        a2 = area(a,e,c);
        a3 = area(d,f,e);
        a4 = area(b,c,f);
        double R = 3.0*V/(a1+a2+a3+a4);
        printf("%.4lf\n",R);
    }
    return 0;
}
