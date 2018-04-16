#include <iostream>
using namespace std;

int map[100][100];
int N, L;


int main() {
	int result = 0;

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;

			map[i][j] = num;
		}
	}

	for (int i = 0; i < N; i++) {
		int cnt = 1;
		int r, c;

		for (r = 0; r < N - 1; r++) {
			if (map[i][r] == map[i][r + 1]) {
				cnt++;
			}
			else if (map[i][r] - map[i][r + 1] == -1 && cnt >= L) {
				cnt = 1;
			}
			else if (map[i][r] - map[i][r + 1] == 1 && cnt >= 0) {
				cnt = 1 - L;
			}
			else {
				break;
			}
		}

		if (r == N - 1 && cnt >= 0) {
			result++;
		}

		cnt = 1;

		for (c = 0; c < N - 1; c++) {
			if (map[c][i] == map[c + 1][i]) {
				cnt++;
			}
			else if (map[c][i] - map[c + 1][i] == -1 && cnt >= L) {
				cnt = 1;
			}
			else if (map[c][i] - map[c + 1][i] == 1 && cnt >= 0) {
				cnt = 1 - L;
			}
			else {
				break;
			}
		}

		if (c == N - 1 && cnt >= 0) {
			result++;
		}
	}

	cout << result << endl;

	system("pause");

	return 0;
}