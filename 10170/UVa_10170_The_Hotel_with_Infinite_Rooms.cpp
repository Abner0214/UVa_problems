#include <iostream>
#include <vector>

using namespace std;

int main(){

    int S;
    long int D;
    while (cin >> S >> D){
        long int count = 0;
        long int ans;
        for (ans = S;  count < D;  ans++)
            count += ans;
        --ans;
        cout << ans << '\n';
    }

    return 0;
}