#include <iostream>

bool concert[100][1001]; //n번째 곡이 해당 볼륨을 사용할 수 있는지 
using namespace std;

int main() {
	int N,S,M;
	cin >> N >> S >> M;
	int volume[50];
	int i,j;
	for(i=1; i<=N; i++) cin >> volume[i];
	
	concert[0][S]=1;
	
	for(i=1; i<=N; i++){//dp
		for(j=0; j<=M; j++){
			if(!concert[i-1][j]) continue;
			
			if(j+volume[i] <= M){
				concert[i][j+volume[i]]=1;
				//cout << i << "번째 공연의 볼륨/" << j+volume[i] <<endl;
			}
			if(j-volume[i] >= 0){
				concert[i][j-volume[i]]=1;
				//cout << i << "번째 공연의 볼륨/" << j-volume[i] <<endl;
			}
		}
	}
	
	i=M;
	int result = -1;
	while(i>=0){
		if(concert[N][i]){
			if(result > 0) break;
			result = i;
		}
		i--;
	}
	cout << result;
}
