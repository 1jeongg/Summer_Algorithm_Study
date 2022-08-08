#include <iostream>
#include <algorithm>

using namespace std;
long long N,M,A, accumulated, answer;
long long num[1000001];
long long m_array[1001] = {0};

void getInput(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for (long long i=0; i<N; i++){
		cin >> A;
		if (i > 0) num[i] = A + num[i-1];
		else num[i] = A;
		
		m_array[num[i] % M] += 1;
	}
}
void solve () {

	for (long long i=0; i<M; i++){
		answer += m_array[i] * (m_array[i] - 1) / 2;
	}
	answer += m_array[0];
	cout << answer;
}


int main(void) {
	getInput();
	solve();
	return 0;
}
