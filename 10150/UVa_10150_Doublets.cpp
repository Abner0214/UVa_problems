#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;

const int MAX_N = 26000;

string words[MAX_N];
vector<int> adj[MAX_N];
int dist[MAX_N];
int parent[MAX_N];

bool is_doublet(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    int diff_count = 0;
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] != s2[i]) {
            ++diff_count;
            if (diff_count > 1) {
                return false;
            }
        }
    }
    return diff_count == 1;
}

void build_graph(int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            if (is_doublet(words[i], words[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

void bfs(int start_id) {
    memset(dist, -1, sizeof(dist));
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(start_id);
    dist[start_id] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

void print_path(int u) {
    if (u == -1) {
        return;
    }
    print_path(parent[u]);
    cout << words[u] << "\n";
}

int main() {
    unordered_map<string, int> word_to_id;
    int N = 0;
    while (getline(cin, words[N])) {
        if (words[N] == "") {
            break;
        }
        word_to_id[words[N]] = N;
        ++N;
    }
    build_graph(N);
    bool first_query = true;
    string start, endd;
    while (cin >> start >> endd) {
        if (!first_query) {
            cout << "\n";
        }
        first_query = false;
        if (word_to_id.find(start) == word_to_id.end() ||
            word_to_id.find(endd) == word_to_id.end()) {
            cout << "No solution.\n";
            continue;
        }
        int start_id = word_to_id[start];
        int end_id = word_to_id[endd];
        bfs(start_id);
        if (dist[end_id] == -1) {
            cout << "No solution.\n";
        } else {
            print_path(end_id);
        }
    }
    return 0;
}
