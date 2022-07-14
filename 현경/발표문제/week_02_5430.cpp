#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

void Delete(deque<int>& dq, bool reverse) {
	 
	if (reverse == false) {
		dq.pop_front();
	}
	else { // 반대로 뒤집혀있으니, 뒤에서 지우면 된다.
		dq.pop_back();
	}

}
void print_forward(deque<int>& dq) {
	for (auto iter = dq.begin(); iter != dq.end(); iter++) {
		if (iter == dq.end() - 1) {
			cout << *iter;
		}
		else {
			cout << *iter << ",";
		}
	}
}
void print_backward(deque<int>& dq) {
	for (auto iter = dq.rbegin(); iter != dq.rend(); iter++) {
		if (iter == dq.rend() - 1) {
			cout << *iter;
		}
		else {
			cout << *iter << ",";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string order; // 명령어들
		int n;
		string arr; // 숫자 배열
		deque<int> dq;
		bool err = false; // 에러 발생 여부
		cin >> order >> n >> arr;

		string s = "";
		bool reverse = false;
		for (int i = 0; i < arr.length();i++) {
			if (isdigit(arr[i])) { // 숫자라면 추가하기
				s += arr[i];
			}
			else {
				if (!s.empty()) {
					dq.push_back(stoi(s)); // 덱에 수 넣기
					s.clear(); // 문자열 초기화
				}
			}
		}
		for (auto o : order) {
			if (o == 'R') {
				if (reverse)
					reverse = false;
				else
					reverse = true;
			}
			else {
				if (dq.empty()) { // 덱이 비어있는데 D 명령어 입력받으면, 에러 발생
					cout << "error" << endl;
					err = true;
					break; // 여기서 에러 처리를 빨리 해주고, for문을 break 까지 해줘야 시간 초과가 발생하지 않음.
				}
				Delete(dq, reverse);
			}
		}
		if (!err) {
			cout << '[';
		}
		if (reverse && !dq.empty()) { // 역방향 출력
			print_backward(dq);
		}
		else if (!reverse && !dq.empty()) { // 정방향 출력
			print_forward(dq);
		}
		if (!err)
			cout << ']' << endl;
	}
}
