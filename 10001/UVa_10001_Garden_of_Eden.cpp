#include <bits/stdc++.h>

using namespace std;

// Use DFS to find the original New States
bool dfs(string target_state, int new_state[], int res_state[], int left_idx, int n);

int main()
{
    int id, N;
    string target_state;
    while (cin >> id >> N >> target_state) {

        int new_state[8] = {0};
        for (int i = 0;  i < 8;  i++) {
            new_state[i] = id % 2;
            id /= 2;
        }
        int res_state[N+2] = {0};

        if (dfs(target_state, new_state, res_state, 0, N)) {
            cout << "REACHABLE\n";
        }
        else {
            cout << "GARDEN OF EDEN\n";
        }  
    }

    return 0;
}
bool dfs(string target_state, int new_state[], int res_state[], int left_idx, int n) {

    if (left_idx >= n) {
        return (res_state[n] == res_state[0])  &&  (res_state[n+1] == res_state[1]);
    }
    int all_states[8][3] = {{0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};
    for (int i = 0;  i < 8;  i++) {
        if ((target_state[left_idx]-'0') == new_state[i]  &&  left_idx == 0) {
            res_state[0] = all_states[i][0];
            res_state[1] = all_states[i][1];
            res_state[2] = all_states[i][2];
            if (dfs(target_state, new_state, res_state, left_idx+1, n)) {
                return true;
            }
        }
        else if ((target_state[left_idx]-'0') == new_state[i]  &&  res_state[left_idx] == all_states[i][0]  &&  res_state[left_idx+1] == all_states[i][1]) {
            res_state[left_idx+2] = all_states[i][2];
            if (dfs(target_state, new_state, res_state, left_idx+1, n)) {
                return true;
            }
        }
    }

    return false;
}
