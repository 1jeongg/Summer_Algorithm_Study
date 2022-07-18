#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int x;
vector<int> people;

void get_input() {
	int money;
	cin >> x;
	for (int i=0; i<x; i++){
		cin >> money;
		people.push_back(money);
	}
	sort(people.begin(), people.end());
}
void solve () {
	int sum = 0;
	for (int i=0; i<x; i++){
		sum += people[i] * (x-i);
	}
	cout << sum;
}


int main(void) {
	
	get_input();
	solve();
	
	return 0;
}
