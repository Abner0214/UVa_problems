//uva 1260
#include <iostream>

using namespace std;

int main(){
	
	int T;
	int n;
	
	cin >> T;
	while(T--){
		
		cin >> n;
		int list[n];
		for (int i = 0;  i < n;  i++){
			cin >> list[i];
		}
		
		int sum = 0;
		for (int i = 1;  i < n;  i++){
			for (int j = i - 1;  j >= 0;  j--){
				if (list[j] <= list[i])
					sum++;
			}
		}
		
		cout << sum << "\n";
	}
	
	return 0;
}
