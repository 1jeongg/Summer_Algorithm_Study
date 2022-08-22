#include<iostream>
#include<string.h>
const int Max = 100001;
int youtube[Max][32];
using namespace std;

int ans(int cur, int rem){	
	int sum = 0;
	while(rem){		 
		if(rem%2){
		cur = youtube[cur][sum];
		}
		rem = rem/2;
		sum++;		
	}	
	return cur;
}

int main(){
	
	int N, M, K, i, j; // N = 학생 수, M = 남은 수업 시간, K = 동영상의 개수 
	int student[Max], root;

	cin >> N >> K >> M;
	for (i = 1; i <= N; ++i){ 
		cin >> student[i];
	}
	
	for (i = 1; i <= K; ++i){ 	
		cin >> youtube[i][0];	
	}

	for (j = 0; j <= 30; ++j){
		for (i = 1; i <= K; ++i){
			root = youtube[i][j];		
			youtube[i][j+1] = youtube[root][j];
		}
	}
	
	for (i = 1; i <= N; ++i){
		cout << ans(student[i],M-1) << " ";
	}
	
	return 0;
}
