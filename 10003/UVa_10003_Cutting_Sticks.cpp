#include <bits/stdc++.h>

using namespace std;

int main(){

    int l;
    while (cin >> l  &&  l != 0){
        int n;
        cin >> n;
        n += 2;
        int *points = new int[n];
        points[0] = 0;
        points[n-1] = l;
        for (int i = 1;  i < n-1;  i++){
            cin >> points[i];
        }
        int dp[n][n] = {0};
        for (int len = 0;  len < n;  len++){
            for (int head = 0;  head < n;  head++){
                int tail = head + len;
                if (tail >= n) break;
                int c = INT_MAX;
                for (int cut = head+1;  cut < tail;  cut++){
                    c = min(c, dp[head][cut] + dp[cut][tail]);
                }
                if (tail - head <= 1) dp[head][tail] = 0;
                else dp[head][tail] = c + points[tail] - points[head];
            }
        }
        cout << "The minimum cutting is " << dp[0][n-1] << "." << '\n';
        delete [] points;
    }

    return 0;
}