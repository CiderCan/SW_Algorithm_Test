#include <iostream>
using namespace std;

long long int dp[91];

int main() {
	int N;

	cin >> N;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;

	for (int i = 4; i <= N; i++) {
		for (int j = i - 2; j > 0; j--) {
			dp[i] += dp[j];
		}
		dp[i]++;
	}

	cout << dp[N] << endl;
}