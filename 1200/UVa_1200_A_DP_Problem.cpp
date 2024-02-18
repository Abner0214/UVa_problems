#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string equ;
        cin >> equ;
        int X_coe = 0;
        int cons = 0;
        bool leftSide = true;
        int sign = 1;
        int num = 0;
        for (int i = 0;  i < equ.size();  i++) {
            if (leftSide) {
                while (i < equ.size()  &&  equ[i] <= '9'  &&  equ[i] >= '0') {
                    num = num*10 + (equ[i] - '0');
                    i++;
                    if (i == equ.size()) break;
                }
                if (equ[i] == '-') {
                    if (i > 0  &&  equ[i-1] <= '9'  &&  equ[i-1] >= '0') {
                        num *= sign;
                        cons += -(num);
                        num = 0;
                    }
                    sign = -1;
                    continue;
                }
                else if (equ[i] == '+') {
                    if (i > 0  &&  equ[i-1] <= '9'  &&  equ[i-1] >= '0') {
                        num *= sign;
                        cons += -(num);
                        num = 0;
                    }
                    sign = 1;
                    continue;
                }
                else if (equ[i] == 'x') {
                    if (i == 0 || !(equ[i-1] >= '0' && equ[i-1] <= '9'))
                        num = 1;
                    num *= sign;
                    X_coe += num;
                    num = 0;
                    continue;
                }
                else if (equ[i] == '=') {
                    leftSide = false;
                    num *= sign;
                    if (equ[i-1] <= '9'  &&  equ[i-1] >= '0') {
                        cons += -(num);
                    }
                    else if (equ[i-1] == 'x') {
                        X_coe += num;
                    }
                    num = 0;
                    sign = 1;
                    continue;
                }
            }
            else {  ////////////////////////////////// '=' right side ////////////////////////////////// 

                while (equ[i] <= '9'  &&  equ[i] >= '0') {
                    num = num*10 + (equ[i] - '0');
                    if (i == equ.size()-1  &&  equ[i] <= '9'  &&  equ[i] >= '0') {
                        num *= sign;
                        cons += num;
                        sign = 1;
                        break;
                    }
                    i++;
                    if (i == equ.size()-1  &&  equ[i] == 'x') break;  // deal with the last char is 'x'
                }
                if (equ[i] == '-') {
                    if (equ[i-1] <= '9'  &&  equ[i-1] >= '0') {
                        num *= sign;
                        cons += num;
                        num = 0;
                    }
                    sign = -1;
                    continue;
                }
                else if (equ[i] == '+') {
                    if (equ[i-1] <= '9'  &&  equ[i-1] >= '0') {
                        num *= sign;
                        cons += num;
                        num = 0;
                    }
                    sign = 1;
                    continue;
                }
                else if (equ[i] == 'x') {
                    if (i == 0 || !(equ[i-1] >= '0' && equ[i-1] <= '9'))
                        num = 1;
                    num *= sign;
                    X_coe += -(num);
                    num = 0;
                    continue;
                }
            }
        }
        if (X_coe == 0  &&  cons == 0)
            cout << "IDENTITY\n";
        else if (X_coe == 0  &&  cons != 0)
            cout << "IMPOSSIBLE\n";
        else {
            int x = (int)floor((double) cons / X_coe) + 0;
            cout << x << '\n';
        }
    }

    return 0;
}

