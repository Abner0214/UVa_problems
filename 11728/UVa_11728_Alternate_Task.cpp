//uva 11728
#include <iostream>
#include <vector>
using namespace std;


int main(){
	
	int S;
	bool match;
	long long int sum;
	vector<long long int> output;
	
	int i;
	
	while(1){
		
		cin >> S;
		if (S == 0) break;
		
		for (i = S;  i > 0;  i--){
			match = false;
			sum = 0;
			for (int j = 1;  j <= S;  j++){
				if (i % j == 0)
				sum += j;
			}
			if (sum == S){
				match = true;
				break;
			}
		}
		
		if (match){
			output.push_back(i);
		}
		else {
			output.push_back(-1); 
		}
	}
	
	for (int i = 0;  i < output.size();  i++){
		cout << "Case " << i+1 << ": " << output[i] << endl;
	}
	
	
	return 0;
}
