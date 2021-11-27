#include <bits/stdc++.h>
#define delta(a, b, c) b*b-4*a*c
#define vn "Ø"
#define vsn "ℝ"
// https://khmt.uit.edu.vn/wecode/truonganpn/assignment/30/121

using namespace std;

set<double> A;
double a,b,c;

void process(int mode) {
    if (mode == 1) {
        if (-c/b>0) {
            A.insert(sqrt(-c/b));
            A.insert(-sqrt(-c/b));
        } else if (-c/b==0) {
            A.insert(0);
        }
    }
    if (mode == 2) {
        if (-c/a>0) {
            A.insert(pow(-c/a,1/4));
            A.insert(-pow(-c/a,1/4));
        } else if (-c/a==0) {
            A.insert(0);
        }
    }
    if (mode == 4) {
        double D=delta(a,b,c);
        if (D<0) return;
        double X1=(-b+sqrt(D))/(2*a), X2=(-b-sqrt(D))/(2*a);
        if (X1==-0) X1=0;
        if (X2==-0) X2=0;
        if (X1>=0) A.insert(sqrt(X1)), A.insert(-sqrt(X1));
        if (X2>=0) A.insert(sqrt(X2)), A.insert(-sqrt(X2));
    }
}

void Out() {
    if (A.size()==0) cout<<vn;
    else {
        cout<<"{";
        for(auto i=A.begin(); i!=A.end(); ++i) {
            cout<<*i;
            if (next(i)!=A.end()) cout<<", "; else cout<<"}";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>a>>b>>c;
    if (a==0 && b==0) {
        if (c==0) {
            cout<<vsn;
        }
        else {
            cout<<vn;
        }
        return 0;
    }
    if (a==0 || b==0) {
        if (a==0) process(1); else process(2);
    } else process(4);
    Out();
    return 0;
}
