#include <iostream>
#include <cmath> 
using namespace std;

int N, K;
int weight[101];
int happy[101];
int dp[101][100001]; //i번째 물건을 넣을 때 담을 수 있는 무게가 K인 경우의 기쁨 수치 

int max_happy = 0;

int main() {
	cin >> N >> K;
	for(int i=1; i<=N; i++){
		cin >> weight[i] >> happy[i];
	}
	/////////////////////////////////////////
	dp[0][100] = 0;
	for(int i=1; i<=N; i++){ //i번째 물품 
		for(int j=1; j<=K; j++){ //j = 남은 공간 
			if(j >= weight[i]){
			dp[i][j] = max(dp[i-1][j], happy[i]+dp[i-1][j-weight[i]]);
			} else{
				dp[i][j] = dp[i-1][j];
			}
			max_happy = max(max_happy, dp[i][j]);
		}
	}
	cout << max_happy;
}
