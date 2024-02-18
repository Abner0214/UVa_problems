#include <bits/stdc++.h>

using namespace std;
int n, m, ans[33], ansd, cedit, A[6][6];
char G[6][6];

void modify(int x, int y, int &litcnt) {
    for (int i = -1;  i <= 1;  ++i) {
        for (int j = -1;  j <= 1;  ++j) {
            if (G[i+1][j+1] == '*') {
                int nx = x + i;
                int ny = y + j;
                if (nx < 0  ||  nx >= n  ||  ny < 0  ||  ny >= m) {
                    continue;
                }
                if (A[nx][ny]) {
                    A[nx][ny] = 0;
                    --litcnt;
                }
                else {
                    A[nx][ny] = 1;
                    ++litcnt;
                }
            }
        }
    }
}

bool check(int x) {
    if (x) {
        for (int j = 0;  j < m;  ++j) {
            if (!A[x-1][j]) {
                return false;
            }
        }
    }
    
    return true;
}

bool dfs(int x, int y, int litcnt) {
    if (litcnt == n*m) {
        return true;
    }
    if (y == m) {
        return check(x)  &&  dfs(x+1, 0, litcnt);
    }
    if (x == n) {
        return false;
    }
    if (dfs(x, y+1, litcnt)) {
        return true;
    }
    modify(x, y, litcnt);
    ans[ansd++] = x*m + y;
    if (dfs(x, y+1, litcnt)) {
        return true;
    }
    modify(x, y, litcnt);
    --ansd;

    return false;
}

int main()
{
    int caseCount = 0;
    for (caseCount = 1;  cin >> n >> m && n;  ++caseCount) {
        // vector<vector<bool>> switchRule(3, vector<bool>(3, 0));
        // int temp;
        // for (int i = 0;  i < 3;  i++) {
        //     for (int j = 0;  j < 3;  j++) {
        //         temp = getchar();
        //         if (temp == '*')
        //             switchRule[i][j] = true;
        //         getchar();
        //     }
        // }
        ansd = 0;
        cedit = 0;
        memset(A, 0, sizeof(A));
        for (int i = 0;  i < 3;  ++i) {
            for (int j = 0;  j < 3;  ++j) {
                cin >> G[i][j];
                if (G[i][j] == '*') {
                    ++cedit;
                }
            }
        }
        
        cout << "Case #" << caseCount << '\n';
        if (!dfs(0, 0, 0)) {
            cout << "Impossible.";
        }
        else {
            for (int i = 0;  i < ansd;  ++i) {
                cout << (i ? " " : "") << ans[i]+1;
            }
        }
        cout << '\n';
    }

    return 0;
}
