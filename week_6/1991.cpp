#include <iostream>
using namespace std;
char arr[27][3];
void pre_circuit(char str);
void in_circuit(char str);
void post_circuit(char str);
void level_circuit(char str);

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		if (left == '.') {
			arr[root][0] = '.';
		}
		else if (left != '.') {
			arr[root][0] = left;
		}
		if (right == '.') {
			arr[root][1] = '.';
		}
		else if (right != '.') {
			arr[root][1] = right;
		}
	}
	cout << "전위 순회 : ";
	pre_circuit('A');
	cout << "\n";
	cout << "중위 순회 : ";
	in_circuit('A');
	cout << "\n";
	cout << "후위 순회 : ";
	post_circuit('A');
	cout << "\n";
	cout << "층별 순회 : ";
	cout << 'A';
	level_circuit('A');
}
void pre_circuit(char str) {
	if (str == '.') return;
	cout << str;
	pre_circuit(arr[str][0]);
	pre_circuit(arr[str][1]);
}
void in_circuit(char str) {
	if (str == '.') return;
	in_circuit(arr[str][0]);
	cout << str;
	in_circuit(arr[str][1]);
}
void post_circuit(char str) {
	if (str == '.') return;
	post_circuit(arr[str][0]);
	post_circuit(arr[str][1]);
	cout << str;
}
void level_circuit(char str) {
	if (str == '.') return;
	if (arr[str][0] != '.')
		cout << arr[str][0];
	if (arr[str][1] != '.')
		cout << arr[str][1];
	level_circuit(arr[str][0]);
	level_circuit(arr[str][1]);
}
