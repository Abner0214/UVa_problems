#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    while (cin >> n >> m){
        vector<int> list(n, 0);
        for (int i = 0;  i < n;  i++){
            list[i] = i+1;
        }
        for (int i = 0;  i < m;  i++){
            int start, end;
            cin >> start >> end;
            int len = end-start + 1;
            for (int j = 0;  j < len;  j++){
                list.push_back(list[end-1]);
                list.erase(list.begin() + end-1);
                --end;
            }
        }
        for (auto l : list)
            cout << l << '\n';
    }

    return 0;
}