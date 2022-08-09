#include <iostream>
#include <string>
#include<unordered_map>

using namespace std;

unordered_map<string, int> chat;
int result;

int htom(string time) { //HH:MM 형식의 문자열을 넣으면 해당 시간을 분 단위로 환산시켜 반환 
	int hour = 0;
	int minuite = 0;
	bool behindcolon = 0;
	for (int i = 0; i < time.length(); i++) {
		if (time[i] == ':') {
			behindcolon = 1;
		}
		else if ('0' <= time[i] && time[i] <= '9') {
			if (behindcolon) { minuite = minuite * 10 + time[i] - 48; }
			else { hour = hour * 10 + time[i] - 48; }
		}
	}
	return (hour * 60 + minuite);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int start, fin_club, fin_strm;
	string st, ficl, fist;
	cin >> st >> ficl >> fist;
	start = htom(st);
	fin_club = htom(ficl);
	fin_strm = htom(fist);
	//cout << start << ", " << fin_club << ", " << fin_strm << endl;

	while (!cin.eof()) {
		string time, user_nick;
		cin >> time >> user_nick;
		if (htom(time) <= start) {
			chat[user_nick] = 1;
		}
		if (fin_club <= htom(time) && htom(time) <= fin_strm) {
			if (chat[user_nick] == 1) {
				//cout << user_nick << "은 정상적으로 출석처리 되었다." << "\n";
				chat[user_nick] = 0;
				result++;
			}
		}
	}
	cout << result;
}
