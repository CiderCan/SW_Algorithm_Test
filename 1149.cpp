#include <iostream>
using namespace std;

int house[1001][3] = { 0, };
int dp[1001][3] = { 0, };

int main() {
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int price;

		for (int j = 0; j < 3; j++) {
			cin >> price;
			house[i][j] = price;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			switch (j) {
			case 0:
				dp[i][j] = house[i][j] + ((dp[i - 1][1] < dp[i - 1][2]) ? dp[i - 1][1] : dp[i - 1][2]);
				break;
			case 1:
				dp[i][j] = house[i][j] + ((dp[i - 1][0] < dp[i - 1][2]) ? dp[i - 1][0] : dp[i - 1][2]);
				break;
			case 2:
				dp[i][j] = house[i][j] + ((dp[i - 1][0] < dp[i - 1][1]) ? dp[i - 1][0] : dp[i - 1][1]);
				break;
			}
		}
	}

	int min = 20000000;

	for (int i = 0; i < 3; i++) {	
		min = (dp[N][i] < min) ? dp[N][i] : min;
	}

	cout << min << endl;
}