#include <iostream>
#include <vector>

using namespace std;

int main(){

    int caseCount;
    cin >> caseCount;

    int N;
    vector<int> digits;
    while (caseCount--){
        digits.assign(10, 0);
        cin >> N;
        for (int i = 1;  i <= N;  i++){
            int nums = i;
            while (nums){
                digits[nums%10]++;
                nums /= 10;
            }
        }
        for (int i = 0;  i < 9;  i++)
            cout << digits[i] << " ";
        cout << digits[9] << endl;
    }

    return 0;
}