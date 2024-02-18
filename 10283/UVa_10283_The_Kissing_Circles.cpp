#include <bits/stdc++.h>

#define PI acos(-1.0)

using namespace std;

int main(){

    double R;  // the big circle radius
    double N;  // the amount of small circle
    double r;  // the small circle radius
    double I;  // the area surrounded by the kissing small circles
    double E;  // the area out side the kissing small circles but inside the larger circle
    // output: r, I, E
    while (cin >> R >> N){
        if (N == 1){
            cout << fixed << setprecision(10) << R << " " << 0.0 << " " << 0.0 << '\n';
            continue;
        }
        double ang = 2*PI/N;
        double ANG = (PI-ang)/2;
        // (R -r) * cos(ANG) = r
        // R * cos(ANG) = r + r cos(ANG)
        // r = R * cos(ANG) / (1 + cos(ANG))
        // r = R / ( 1/cos(ANG) + 1)
        r = R / (1+1/cos(ANG));
        double h = sqrt((R-r)*(R-r) - r*r);
        double triArea = 0.5 * (2*r) * h;
        double polyArea = N * triArea;
        I = polyArea - N*0.5*r*r*(2*ANG);
        E = PI*R*R - I - N*PI*r*r;

        cout << fixed << setprecision(10) << r << " " << I << " " << E << '\n';
    }

    return 0;
}