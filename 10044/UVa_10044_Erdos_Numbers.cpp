#include <bits/stdc++.h>

using namespace std;

int main(){
    int sce;
    cin >> sce;
    for (int sss = 0; sss < sce; ++sss){
        int p,n;
        cin >> p >> n;
        cin.ignore();
        unordered_map<string, int> nums;  // 每個人的編號
        int numcnt = 0;  // 人數
        vector<vector<int>> graph;
        for (int i = 0; i < p; ++i){
            string s;
            getline(cin, s);
            int cnt = 0;
            int pos = 0;
            
            vector<int> vec;
            for (int j = 0; j < s.length(); ++j){
                // 有人和人之間的','和名與姓的','，cnt用來判定是哪一種','
                if (s[j] == ',')++cnt;
                // 找到一個人
                if (s[j] == ',' && cnt % 2 == 0 && cnt != 0){
                    //將若是新人，將他加入一個map裡面，給他一個編號和graph
                    if(nums.find(s.substr(pos, j-pos)) == nums.end()){
                        nums[s.substr(pos, j-pos)] = numcnt++;
                        graph.push_back(vector<int>());
                    }
                    vec.push_back(nums[s.substr(pos, j-pos)]);
                    pos=j+2;
                }
                // ':'前面也有一個人
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
                    // 製作無向圖
                    graph[vec[i]].push_back(vec[j]);
                    graph[vec[j]].push_back(vec[i]);
                }
            }
        }
        queue<int> q;
        // 每個人離那傢伙有多遠，-1代表完全在圖內是完全分開的圖
        vector<int> erdnums(numcnt, -1);
        // bfs內用來確定已經走過，走過就不要再走了
        vector<bool> visited(numcnt, false);
        int erdnum=0;
        // Erdos 當成 0，BFS的起點
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