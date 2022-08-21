#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int coin[10001];
int dp[10001];

void getInput(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for (int i=0; i<N; i++){
		cin >> coin[i];
	}	
	sort(coin, coin+N);
	dp[0] = 1;
}
void solve () {
	for (int i=0; i<N; i++) {
		for (int j=0; j<=M; j++) {
			if (coin[i] <= j) {
				dp[j] += dp[j-coin[i]];
			}
		}
	}
	cout << dp[M];
}


int main(void) {
	getInput();
	solve();
	return 0;
}
