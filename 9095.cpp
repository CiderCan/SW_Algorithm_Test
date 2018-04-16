#include <iostream>
using namespace std;

int dp[1000000] = { 0, };
int num[1000000] = { 0, };

int main() {
	int N;
	int max = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int number;
		cin >> number;

		num[i] = number;
		max = (max > number) ? max : number;
	}

	for(int i = 1; i <= max; i++){
		switch (i) {
		case 1:
			dp[i] = 1;
			break;
		case 2:
			dp[i] = 2;
			break;
		case 3:
			dp[i] = 4;
			break;
		default:
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
			break;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << dp[num[i]] << endl;
	}

	return 0;
}