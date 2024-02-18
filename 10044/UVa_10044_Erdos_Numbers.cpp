#include <bits/stdc++.h>

using namespace std;

int main(){
    int sce;
    cin >> sce;
    for (int sss = 0; sss < sce; ++sss){
        int p,n;
        cin >> p >> n;
        cin.ignore();
        unordered_map<string, int> nums;  // each person's number
        int numcnt = 0;  // number of people
        vector<vector<int>> graph;
        for (int i = 0; i < p; ++i){
            string s;
            getline(cin, s);
            int cnt = 0;
            int pos = 0;
            
            vector<int> vec;
            for (int j = 0; j < s.length(); ++j){
                // between person and person ',' between last name and first name','
                // use cnt to differentiate','
                if (s[j] == ',')++cnt;
                // find a person
                if (s[j] == ',' && cnt % 2 == 0 && cnt != 0){
                    // if is a new person, add into the map, and give him a number and graph
                    if(nums.find(s.substr(pos, j-pos)) == nums.end()){
                        nums[s.substr(pos, j-pos)] = numcnt++;
                        graph.push_back(vector<int>());
                    }
                    vec.push_back(nums[s.substr(pos, j-pos)]);
                    pos=j+2;
                }
                // There is a person before':'
                if (s[j] == ':'){
                    if(nums.find(s.substr(pos, j-pos)) == nums.end()){
                        nums[s.substr(pos,j-pos)] = numcnt++;
                        graph.push_back(vector<int>());
                    }
                    vec.push_back(nums[s.substr(pos, j-pos)]);
                    break;
                }
            }
            for(int i = 0; i < vec.size(); ++i){
                for(int j = i+1; j < vec.size(); ++j){
                    // make undirected graph
                    graph[vec[i]].push_back(vec[j]);
                    graph[vec[j]].push_back(vec[i]);
                }
            }
        }
        queue<int> q;
        // distance, -1 mean two independent graph
        vector<int> erdnums(numcnt, -1);
        // bfs 
        vector<bool> visited(numcnt, false);
        int erdnum=0;
        // Erdos set to 0, BFS's start point
        q.push(nums["Erdos, P."]);
        visited[nums["Erdos, P."]] = true;
        while(!q.empty()){
            
            int t = q.size();
            for(int i = 0; i< t; ++i){
                int person = q.front();q.pop();                
                erdnums[person] = erdnum;
                for(auto& x : graph[person]){
                    if(!visited[x]){
                        visited[x] = true;
                        q.push(x);
                    }
                }
            }
            ++erdnum;
        }
        cout << "Scenario " << sss+1 << endl;
        vector<int> tar(n);
        for(auto& x : tar){
            string s;
            getline(cin, s);
            if(nums.find(s) != nums.end() && erdnums[nums[s]] != -1) cout << s << " " << erdnums[nums[s]] << endl;
            else cout << s << " infinity"<< endl;
        }
    }
}