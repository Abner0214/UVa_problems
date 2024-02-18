//uva 12908
#include <bits/stdc++.h>

using namespace std;


int main(){
	int num, i;
	while (cin >> num && num > 0) {
		int temp;
		for (i = sqrt(num * 2) - 1;; ++i) {
			temp = num < (1+i) * i/2;
			if(temp) break;
		}
			
		cout << temp - num << " " << i << endl;
	}

	return 0;
}

