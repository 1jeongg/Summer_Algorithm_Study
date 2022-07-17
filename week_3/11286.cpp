#include <iostream>
#include<queue>
#include<cmath>
#include <vector>
using namespace std;

struct comp
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main() {
	int N;

	cin >> N;

	priority_queue< int, vector<int>, comp > pq;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num != 0) {
			pq.push(num);
		}
		else if (num == 0 && pq.empty()) {
			cout << 0 << endl;
		}
		else {
			cout << pq.top() << endl;
			pq.pop();
		}
	}
}
