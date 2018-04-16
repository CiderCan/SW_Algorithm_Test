#include <iostream>
#include <algorithm>
using namespace std;

int s[16][16];
int dp[16];
int N;

int main() {
	int max = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int T, P;

		cin >> T >> P;

		s[i][0] = T;
		s[i][1] = P;
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = s[i][1];
	}

	for (int i = 1; i <= N; i++) {
		if (i + s[i][0] <= N + 1) {
			for (int j = i + s[i][0]; j <= N; j++) {
				if (dp[j] < dp[i] + s[j][1]) {
					dp[j] = dp[i] + s[j][1];
				}
			}
		}
		else {
			dp[i] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		max = (dp[i] > max) ? dp[i] : max;
	}

	cout << max << endl;

	system("pause");

	return 0;
}