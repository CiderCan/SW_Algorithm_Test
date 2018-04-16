#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int Tetromino[19][4][2] = {
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 3, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 0 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 2, 1 } },
	{ { 0, 0 },{ 1, -2 },{ 1, -1 },{ 1, 0 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 0 } },
	{ { 0, 0 },{ 1, 0 },{ 2, 0 },{ 2, -1 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 2 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 0 },{ 2, 0 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 1, 2 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 2, 1 } },
	{ { 0, 0 },{ 0, 1 },{ 1, -1 },{ 1, 0 } },
	{ { 0, 0 },{ 1, -1 },{ 1, 0 },{ 2, -1 } },
	{ { 0, 0 },{ 0, 1 },{ 1, 1 },{ 1, 2 } },
	{ { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 1 } },
	{ { 0, 0 },{ 1, 0 },{ 1, 1 },{ 2, 0 } },
	{ { 0, 0 },{ 1, -1 },{ 1, 0 },{ 1, 1 } },
	{ { 0, 0 },{ 1, -1 },{ 1, 0 },{ 2, 0 } },
};

int paper[501][501];
bool visit[501][501] = { 0, };
int N, M;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sum = 0;
int result = 0;
// 0 : L ? 1 : R ? 2 : U ? 3 : D

int main() {
	int max = 0;
	std::ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int num;

			cin >> num;

			paper[i][j] = num;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int t = 0; t < 19; t++) {
				int compare = 0;

				for (int d = 0; d < 4; d++) {
					int nx = j + Tetromino[t][d][0];
					int ny = i + Tetromino[t][d][1];

					if (0 < nx && nx <= M && 0 < ny && ny <= N) {
						compare += paper[ny][nx];
					}
				}

				if (max < compare) {
					max = compare;
				}
			}
		}
	}

	cout << max << endl;

	system("pause");

	return 0;
}