//uva 10642
#include <iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	int coo[n][4];
	for (int i = 0;  i < n;  i++){
		for (int j = 0;  j < 4;  j++){
			cin >> coo[i][j];
		}
	}
	
	long long int sum1 = 0;
	long long int sum2 = 0;
	long long int result[n];
	
	for (int i = 0;  i < n;  i++){
		
		sum1 = coo[i][0] + coo[i][1];
		sum2 = coo[i][2] + coo[i][3];
		
		for (int j = 1; j <= coo[i][0] + coo[i][1];  j++){
			sum1 += j;
		}
		if (sum1 > coo[i][1]) sum1 -= coo[i][1];
		for (int j = 1; j <= coo[i][2] + coo[i][3];  j++){
			sum2 += j;
		}
		if (sum2 > coo[i][3]) sum2 -= coo[i][3];
		result[i] = sum2 - sum1;
	}
	
	
	
	for (int i = 0;  i < n;  i++){
		cout << "Case " << i+1 << ": " << result[i] << endl;
	}
	
	
	return 0;
}
