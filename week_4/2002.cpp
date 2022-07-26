#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int howmany;
	cin >> howmany;

	unordered_map<string, int> goingIn;

	string numPad;

	for (int repeat = 0; repeat < howmany; repeat++) {
		cin >> numPad;
		goingIn.insert({ numPad,  repeat });
	}

	int result = 0;
	vector<string> comingOut(howmany);

	for (int repeat = 0; repeat < howmany; repeat++) {
		cin >> numPad;
		comingOut[repeat] = numPad;
	}

	for (int i = 0; i < howmany; i++) {
		for (int j = i + 1; j < howmany; j++) {
			if (goingIn[comingOut[i]] > goingIn[comingOut[j]]) {
				result++;
				break;
			}
		}
	}

	cout << result << "\n";

	return 0;
}
