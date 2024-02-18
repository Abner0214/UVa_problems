#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printPermuations(string str, string& res, int idx){
    if (res.size() == str.size()){
        cout << res << '\n';
        return;
    }
    for (int i = 0;  i < res.size()+1;  i++){
        res.insert(i, 1, str[idx]);
        idx++;
        printPermuations(str, res, idx);
        res.erase(i, 1);
        idx--;
    }
}

int main(){

    string str = "";
    int i = 0;
    while (getline(cin, str)){
        string res = "";
        if (i > 0)
            cout << '\n';
        printPermuations(str, res, 0);
        i++;
    }

    return 0;
}