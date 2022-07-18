#include <iostream>
using namespace std;
int number[51];
char oper[51];
int n = 0;


void get_input() {
	while(1) {
        cin >> number[n];
        if(cin.eof())
            break;
        cin >> oper[n];
        n++;
    }
}
void solve () {
	int sum = number[0];
	bool flag = false;
	for (int i=0; i<n; i++){
		if (oper[i] == '-' && flag == false){
			flag = !(flag);
		}
		if (flag){
			sum -= number[i+1];
		} else {
			sum += number[i+1];
		}
	}
	cout << sum;
}


int main(void) {
	
	get_input();
	solve();
	
	return 0;
}
