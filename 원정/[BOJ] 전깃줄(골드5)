#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int x;
vector <pair<int,int>> elec;

void get_input() {
	cin >> x;
	for (int i=0; i<x; i++){
		int a,b;
		cin >> a >> b;
		elec.push_back(pair<int,int>(a,b));
	}
	sort(elec.begin(), elec.end());
}
void solve () {
	
	int dp[501] = {0};
	int not_interchange = 0;
	for (int i=0; i<x; i++){
		dp[i] = 1;
		for (int j=0; j<x; j++) {
			if (elec[j].second < elec[i].second){
				dp[i] = max(dp[i], dp[j]+1);
			}
			not_interchange = max(not_interchange, dp[i]);
		}	
	}
	cout << x - not_interchange;
}


int main(void) {
	
	get_input();
	solve();
	
	return 0;
}
