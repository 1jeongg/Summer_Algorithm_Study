#include <iostream>
#include <vector>

using namespace std;
long long num;
vector<long long> soil, station;

void get_input() {
	long long x;
	cin >> num;
	for (long long i=0; i<num-1; i++){
		cin >> x;
		station.push_back(x);
	}
	for (long long i=0; i<num; i++){
		cin >> x;
		soil.push_back(x);
	}
}
void solve () {
	long long sum = 0;
	long long min_soil = soil[0];
	for (long long i=0; i<num; i++){
		if (min_soil > soil[i]) min_soil = soil[i];
		sum += min_soil * station[i];
	}
	cout << sum;
}


int main(void) {
	
	get_input();
	solve();
	
	return 0;
}
