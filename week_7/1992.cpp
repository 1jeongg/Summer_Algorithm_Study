#include <iostream>
using namespace std;

int N;
char image[65][65];

bool same_image(int n, int x, int y){ //같으면(=압축가능) true 다르면 false 
	int defa = image[x][y];
	for(int i=x; i<x+n; i++){
		for(int j=y; j<y+n; j++){
			if(defa != image[i][j]) {
				//cout << "different" << "\n";
				return false;
			}
		}
	}
	//cout << "same" << "\n";
	return true;
} 

void cut(int n, int x, int y){
	//cout << n << "case의 압축 시도" << "\n";
	if(!same_image(n,x,y)){ //분할 case
		//cout << "분-할" << endl;
		if(n>= 2){
			cout << "(";
		  	for(int i=x; i<x+n; i+=(n/2)){
		  		for(int j=y; j<y+n; j+=(n/2)){
		  			cut(n/2, i, j);
				}
			}
			cout << ")";
	    }
	} else { //압축 가능 
		cout << image[x][y];
		//출력 
	}
}

int main() {
	cin >> N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> image[i][j];
		}
	}
	cut(N,1,1);
	
}
