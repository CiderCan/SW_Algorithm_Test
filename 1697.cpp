#include <iostream>
#include <queue>
using namespace std;

int dp[100001] = { 0 , };
int N;
int K;
queue<int> q;

int proc(){
	q.push(N); dp[N] = 1;

	while (!q.empty()) {
		int p = q.front(); q.pop();

		if (p == K) return (dp[p] - 1);

		if (p - 1 >= 0 && dp[p - 1] == 0) {
			dp[p - 1] = dp[p] + 1;
			q.push(p - 1);
		}

		if (p + 1 <= 100000 && dp[p + 1] == 0) {
			dp[p + 1] = dp[p] + 1;
			q.push(p + 1);
		}

		if (2 * p <= 100000 && dp[2 * p] == 0) {
			dp[2 * p] = dp[p] + 1;
			q.push(2 * p);
		}
	}
}

int main() {
	cin >> N >> K;

	cout << proc() << endl;

	system("pause");
}