#include <iostream>

using namespace std;

int T, n;
int cnt = 0;
int dp[12] = { 0, };

int main() {

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cnt = 0;
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << endl;
		
	}

	return 0;
}
