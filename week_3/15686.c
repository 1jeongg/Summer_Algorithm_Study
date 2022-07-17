#include <stdio.h>

int min = 5000;
int N, M;	// N : 몇 바이 몇인지, M : 폐업시키지 않을 치킨집의 최대 개수 
int index_house = -1, index_chicken = -1; 

typedef struct matrix {
	int x, y;
}mat;
mat picked_chicken[13], chicken[13], house[100];
//picked_chicken : 조합을 통해 최종적으로 구한 치킨집 정보 저장 


void Calculate() {
	//len : 집과 치킨집 사이의 거리 
	int len = 0, dist = 0, sum = 0;		
	int i,j;
	for (i = 0; i <= index_house; i++) {
		int chicken_dist = 50 * 2;
		for (j = 0; j < M; j++) {
			len = house[i].x > picked_chicken[j].x ? house[i].x - picked_chicken[j].x : picked_chicken[j].x - house[i].x;
			len += house[i].y > picked_chicken[j].y ? house[i].y - picked_chicken[j].y : picked_chicken[j].y - house[i].y;
			dist = len;
			if (dist < chicken_dist)
				chicken_dist = dist;
		}
		sum += chicken_dist;
	}
	if (sum < min)
		min = sum;
}

void Combination(int n, int c, int r) {
	// n: 몇 번 인덱스  c: 현재 선택된 치킨집의 개수  r: 치킨집 선택 1, 치킨집 선택 안함 0 
	if (r == 1)
	picked_chicken[c - 1] = chicken[n];

	if (M == c){		//종료조건 1 : 선택한 시킨집이 M개 
		Calculate();
		return;
	}
	if (n == index_chicken)  // 종료조건 2 : 전체 치킨집을 모두 탐색 
		return;

	Combination(n+1, c+1, 1); 
	Combination(n+1, c, 0);	
}

int main()
{
	int i,j,num;
	
    scanf("%d %d", &N, &M);
    
	for (i = 0; i < N; i++)			// 치킨집의 좌표만 따로 저장. 1은 집 2는 치킨집 
		for (j = 0; j < N; j++) {
			scanf("%d", &num);
			if (num == 1) {
				index_house += 1;
				house[index_house].x = i;
				house[index_house].y = j;
			}
			else if (num == 2) {
				index_chicken += 1;
				chicken[index_chicken].x = i;
				chicken[index_chicken].y = j;
			}
		}

	Combination(-1, 0, -1);		// 아무것도 선택하지 않은 초기 상황 
	printf("%d\n", min);
	
	return 0;
}
