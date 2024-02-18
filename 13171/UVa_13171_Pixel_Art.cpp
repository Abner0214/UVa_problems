//uva 13171
#include <iostream>
#include <string>


using namespace std;

int main(){
	
	int c;
	cin >> c;
	
	int mag, yel, cya;
	string want;
	
	while(c--){
		
		cin >> mag >> yel >> cya;
		cin >> want;
		
		for (int i = 0;  i < want.size();  i++){
			
			switch(want[i]){
				
				case 'M':
					mag--;
				break;
				case 'Y':
					yel--;
				break;
				case 'C':
					cya--;
				break;
				case 'R':
					mag--;
					yel--;
				break;
				case 'B':
					mag--;
					yel--;
					cya--;
				break;
				case 'G':
					yel--;
					cya--;
				break;
				case 'V':
					mag--;
					cya--;
				break;
				case 'W':
				break;

				default:
					break;
			}
			
		}
		if (mag >= 0  &&  yel >= 0  &&  cya >= 0){
			cout << "YES " << mag  << " " << yel  << " " << cya << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	
	
	
	return 0;
} 
