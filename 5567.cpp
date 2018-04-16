#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool friends[501][501] = { 0, };
bool visit[501] = { 0, };


int main() {
	int N, M;
	int cnt = 0;
	vector<int> searchVec;

	cin >> N;
	cin >> M;

	while (M--) {
		int f1, f2;
		cin >> f1 >> f2;

		if (f1 == 1) {
			searchVec.push_back(f2);
			visit[1] = true;
			visit[f2] = true;
			cnt++;
		}

		friends[f1][f2] = true;
		friends[f2][f1] = true;
	}

	sort(searchVec.begin(), searchVec.end());

	for (vector<int>::iterator it = searchVec.begin(); it != searchVec.end(); it++) {
		for (int i = 1; i <= N; i++) {
			if (friends[*it][i] && !visit[i]) {
				cnt++;
				visit[i] = true;
			}
		}
	}

	cout << cnt << endl;

	//system("pause");
}