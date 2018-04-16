#include <iostream>
#include <vector>
using namespace std;

int people[20][20];
bool check[20];
vector<int> A;
vector<int> B;
int N;
int minNum = 20000000;

void proc(int k, int pos) {
	if (k == N / 2) {
		int as = 0;
		int bs = 0;

		for (int i = 0; i < N; i++) {
			if (check[i]) {
				A.push_back(i);
			}
			else {
				B.push_back(i);
			}
		}

		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				as += people[A[i]][A[j]] + people[A[j]][A[i]];
				bs += people[B[i]][B[j]] + people[B[j]][B[i]];
			}
		}

		int abs = (as - bs < 0) ? (bs - as) : (as - bs);
		minNum = (minNum < abs) ? minNum : abs;

		while (!A.empty()) {
			A.pop_back();
			B.pop_back();
		}

		return;
	}

	for (int i = pos + 1; i < N; i++) {
		if (check[i]) {
			continue;
		}
		check[i] = true;
		proc(k + 1, i);
		check[i] = false;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;

			people[i][j] = num;
		}
	}

	check[0] = true;
	proc(1, 0);
	check[0] = false;

	cout << minNum << endl;

	system("pause");

	return 0;
}