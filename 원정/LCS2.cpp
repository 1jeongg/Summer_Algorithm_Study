#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string N,M;

int dp[1001][1001];

int answer_num = 0;
string answer_str = "";

void getInput(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;	
}
void solve () {
	
	int N_len = N.length();
	int M_len = M.length();
	
	for (int i=1; i<=N_len; i++){
		for (int j=1; j<=M_len; j++){
			if (N[i-1] == M[j-1]) { dp[i][j] = dp[i-1][j-1] + 1; } 
			else { dp[i][j] = max(dp[i-1][j], dp[i][j-1]); }
		}
	}
	
	answer_num = dp[N_len][M_len];
	int num1 = 0, num2 = 0;
	
	while (dp[N_len-num1][M_len-num2] > 0) 
	{
		if (dp[N_len-num1][M_len-num2] == dp[N_len-num1-1][M_len-num2]) {
			num1 += 1;
		} else if (dp[N_len-num1][M_len-num2] == dp[N_len-num1][M_len-num2-1]) {
			num2 += 1;
		} else {
			num1 += 1;
			num2 += 1;
			answer_str += N[N_len-num1];
		}
	}
	reverse(answer_str.begin(), answer_str.end());
	cout << answer_num << endl << answer_str;
	
}


int main(void) {
	getInput();
	solve();
	return 0;
}
