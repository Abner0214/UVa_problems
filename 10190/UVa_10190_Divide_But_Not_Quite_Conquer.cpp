//uva 10190
#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;
long long power(long long a, long long n){
	long long res = 1;
	for (long long i = 0;  i < n;  ++i) {
		res *= a;
	}
	return res;
}
int main() {
	
    long long n, m;

    while (cin >> n >> m) {
		
		vector <long long> display;
		long long test = 1;
		
		display.push_back(test);
		for (int i = 1; test < n && m > 1;  i++){
			
			test = power(m, i);
			display.push_back(test);
		}
		if (m == 0) {
			cout << "Boring!\n";
			continue;
		}
		if (n == m  &&  m == 1){
			cout << "Boring!\n";
		}
		else if (display.back() == n){
			
			for (int i = display.size(); i > 0;  i--){
				cout << display[i-1];
				if (i != 0) cout << " ";
			}
			cout << endl;
		}
		else {	
			cout << "Boring!\n";
		}
    }
    return 0;
}
