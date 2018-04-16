#include <iostream>
using namespace std;

int stair[301] = { 0, };
int ans[301] = { 0, };

void solu(int pos) {
	if (ans[pos - 3] + stair[pos - 1] > ans[pos - 2]) {
		ans[pos] = stair[pos] + ans[pos - 3] + stair[pos - 1];
	}
	else {
		ans[pos] = stair[pos] + ans[pos - 2];
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int score;
		cin >> score;
		stair[i] = score;
		ans[i] = score;
	}

	for (int i = 1; i <= N; i++) {
		if (i < 3) {
			ans[i] = stair[i] + ans[i - 1];
		}
		else {
			solu(i);
		}
	}

	cout << ans[N] << endl;
	/*for (int i = 1; i <= N; i++) {
		cout << "[" << stair[i] << "]  " << i << " ¹øÂ° : " << ans[i] << endl;
	}
	*/
	//system("pause");
	return 0;
}