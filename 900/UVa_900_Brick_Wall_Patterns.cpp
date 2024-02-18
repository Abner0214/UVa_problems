#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int dp[50];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2;  i < 50;  i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    int n;
    while (1){
        cin >> n;
        if (!n) break;
        cout << dp[n-1] << '\n';
    }

    return 0;
}