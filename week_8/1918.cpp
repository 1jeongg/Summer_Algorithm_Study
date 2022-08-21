#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int priority(char ch) {
	if (ch == '(')
		return 0;
	if (ch == '+' || ch == '-')
		return 1;
	else
		return 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	stack<char> s;

	for (char ch : str) {
		if ('A' <= ch && ch <= 'Z')
			cout << ch;
		else if ('(' == ch)
			s.push(ch);
		else if (')' == ch) {
			while (!s.empty()) {
				char tmp = s.top();
				s.pop();
				if (tmp == '(')
					break;
				cout << tmp;
			}
		}
		else {
			while (!s.empty() && priority(s.top()) >= priority(ch)) {
				cout << s.top();
				s.pop();
			}
			s.push(ch);
		}
	}
	
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}
