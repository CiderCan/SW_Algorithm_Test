#include <iostream>
#include <string>
#include <queue>
#include <math.h>
using namespace std;

queue<pair<int, int>> spin;
bool gear[4][8];
bool visit[4] = { 0, };
int K;

void proc(int gearNum, int spinNum) {
	visit[gearNum] = true;

	if (gear[gearNum][2] != gear[gearNum + 1][6] && gearNum < 3 && !visit[gearNum + 1]) {
		int nSpinNum = (spinNum == 1) ? -1 : 1;

		proc(gearNum + 1, nSpinNum);
	}
	if (gear[gearNum][6] != gear[gearNum - 1][2] && gearNum > 0 && !visit[gearNum - 1]) {
		int nSpinNum = (spinNum == 1) ? -1 : 1;

		proc(gearNum - 1, nSpinNum);
	}

	int copy[8];
	for (int i = 0; i < 8; i++) {
		copy[i] = gear[gearNum][i];
	}

	if (spinNum == 1) {
		for (int i = 0; i < 8; i++) {
			if (i == 7) {
				gear[gearNum][0] = copy[7];
				break;
			}
			gear[gearNum][i + 1] = copy[i];
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (i == 7) {
				gear[gearNum][7] = copy[0];
				break;
			}

			gear[gearNum][i] = copy[i + 1];
		}
	}

	/*cout << gearNum << " : " << endl;
	for (int j = 0; j < 8; j++) {
		cout << gear[gearNum][j] << " ";
	}
	cout << endl;*/
}

int main() {
	for (int i = 0; i < 4; i++) {
		string s;

		cin >> s;

		for (int j = 0; j < 8; j++) {
			if (s.at(j) == '1') {
				gear[i][j] = 1;
			}
			else {
				gear[i][j] = 0;
			}
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		int gearNum, spinNum;
		cin >> gearNum >> spinNum;

		spin.push(make_pair(gearNum, spinNum));
	}

	for (int i = 0; i < K; i++) {
		int gearNum = spin.front().first;
		int spinNum = spin.front().second;
		spin.pop();

		proc(gearNum - 1, spinNum);

		for (int j = 0; j < 4; j++) {
			visit[j] = false;
		}
	}

	int result = 0;

	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1) {
			result += pow(2, i);
		}
	}

	cout << result << endl;

	system("pause");

	return 0;
}