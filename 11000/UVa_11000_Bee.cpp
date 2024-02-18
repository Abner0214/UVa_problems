//uva 11000
#include <iostream>
#include <vector>
using namespace std;


int main(){
	
	long long int N;
	
	while (cin >> N){
		if (N < 0) break;
		vector <long long int> mBee, fBee;
		fBee.push_back(1); 
		mBee.push_back(0);
		for (int i = 0;  i < N;  i++){
			
			long long int fLastNum = fBee.back();
			long long int mLastNum = mBee.back();
			
			fBee.push_back(mLastNum); 
			mBee.push_back(mLastNum + fLastNum);
		}
		
		long long int mtotal = 0, ftotal = 0;
		for (int i = 0;  i < fBee.size();  i ++){
			mtotal += mBee[i];
			ftotal += fBee[i];
		}
		cout << mtotal << " " << ftotal + mtotal << endl;
	}
	
	
	return 0;
}
