#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 50000;
const double INF = 2000000;

struct Student {
    double X, Y, VX, VY;
    Student () {};
    Student (double X, double Y, double VX, double VY) : X(X), Y(Y), VX(VX), VY(VY) {};
};

struct Time {
    double l, r;
    Time () {};
    Time (double l, double r) : l(l), r(r) {};
};

double max (int i, double d) {
    return (double)i > d ? (double)i : d;
}

int N;
double R, BX, BY, BVX, BVY;
Student s[MAX];

int always;

vector<Time> t;

void input () {
    double Xi, Yi, VXi, VYi;
    
    cin >> N >> R >> BX >> BY >> BVX >> BVY;
    for (int i = 0; i < N; i++) {
        cin >> Xi >> Yi >> VXi >> VYi;
        s[i] = Student(Xi, Yi, VXi, VYi);
    }
    
    return ;
}

bool comp (Time t1, Time t2) {
    return t1.l == t2.l ? t1.r < t2.r : t1.l < t2.l;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    
    always = 0;
    
    double A, B, C;
    for (int i = 0; i < N; i++) {
        // At^2 + Bt + C <= 0
        A = (BVX - s[i].VX) * (BVX - s[i].VX) + (BVY - s[i].VY) * (BVY - s[i].VY);
        B = 2 * (BVX - s[i].VX) * (BX - s[i].X) + 2 * (BVY - s[i].VY) * (BY - s[i].Y);
        C = (BX - s[i].X) * (BX - s[i].X) + (BY - s[i].Y) * (BY - s[i].Y) - R * R;
        
        if (A == 0) {
            if (C <= 0) always ++; // A = 0 인 경우 dVX, dVY = 0 => B = 2(dVX * dX + dVY * dY) = 0
        } else { // A = dVX * dVX + dVY * dVY 이므로 항상 A >= 0
            double D = B * B - 4 * A * C;
            if (D >= 0) {
                double t1 = (-B - sqrt(D)) / (2 * A), t2 = (-B + sqrt(D)) / (2 * A);
                t.push_back(Time(max(0, t1), t2));
            }
        }
    }
    
    sort(t.begin(), t.end(), comp);
    
    priority_queue<double, vector<double>, greater<double>> pq;
    for (auto cur : t) {
        if (cur.l > cur.r || cur.r < 0) continue ;
        
        if (!pq.empty() && pq.top() <= cur.l) pq.pop();
        pq.push(cur.r);
    }
    
    cout << always + pq.size();
    
    return 0;
}