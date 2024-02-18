#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;
int const INF = 123456;
int dfs(vector<vector<int>> graph, int psb, int n, vector<int> visited, int k, int num);

int main() 
{
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> population(10000, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> population[i];
        }

        Graph graph(n+1, vector<int>(n+1, 0));
        for (int i = 1;  i <= n;  ++i) {
            for (int j = 1;  j <= n;  ++j) {
                if (j == i) {
                    graph[i][i] = 0;
                    continue;
                }
                graph[i][j] = INF;
            }
        }
        for (int i = 1; i <= m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            graph[u][v] = graph[v][u] = min(graph[u][v], c);
        }

        // Try all possible combinations of rebuilding roads
        int maxAccessiblePopulation = 0;
        int all_psb = 1 << (n-1);
        int num;
        int ppl;
        for (int psb = 1; psb < all_psb; ++psb) {
            ppl = 0;
            num = 0;
            vector<int> visited(10000, 0);
            for (int j = 0;  j < n-1;  ++j) {
                if (psb & (1<<j)){
                    ++num;
                    ppl += population[j+2];
                }
            }
            if (ppl > maxAccessiblePopulation  &&
                dfs(graph, psb, n, visited, k, num) <= k) {
                    maxAccessiblePopulation = ppl;
            }
        }

        cout << population[1] + maxAccessiblePopulation << endl;
    }

    return 0;
}

int dfs(vector<vector<int>> graph, int psb, int n, vector<int> visited, int k, int num) {
    int pos = -1;
    int sum = 0;
    visited[1] = 1;
    vector<int> dst(10000, 0);
    for (int i = 1;  i <= n;  ++i) {
        dst[i] = graph[1][i];
    }
    for (int i = 0;  i < num;  ++i) {
        int min = INF;
        for (int j = 0;  j < n-1;  ++j) {
            if (!visited[j+2]  &&  dst[j+2] < min  &&  (psb & (1<<j))) {
                pos = j+2;
                min = dst[j+2];
            }
        }
        sum += min;
        if (pos == -1  ||  sum > k) {
            return k+1;
        }
        visited[pos] = 1;
        for (int j = 2;  j <= n;  ++j) {
            if (!visited[j]  &&  graph[pos][j] < dst[j]) {
                dst[j] = graph[pos][j];
            }
        }
    }

    return sum;
}