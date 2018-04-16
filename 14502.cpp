#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> road;
vector<pair<int, int>> v;
int N, M;
int map[10][10];
int cmap[10][10];
bool visit[10][10];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
// 0 : L ? 1 : R ? 2 : U ? 3 : D

void fillVirus(int x, int y) {
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (cmap[ny][nx] == 0) {
			cmap[ny][nx] = 2;

			cnt++;

			fillVirus(nx, ny);
		}
	}

	if (cnt == 0) {
		return;
	}
}

void init() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cmap[i][j] = map[i][j];
		}
	}
}

void printMap() {
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			cout << cmap[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}

int main() {
	cin >> N >> M;

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
				map[i][j] = 1;
			}
			else {
				int num;

				cin >> num;

				map[i][j] = num;

				if (num == 0) {
					road.push_back(make_pair(i, j));
				}
				else if (num == 2) {
					v.push_back(make_pair(i, j));
				}
			}
		}
	}

	int max = 0;

	for (int i = 0; i < road.size(); i++) {
		for (int j = i + 1; j < road.size(); j++) {
			for (int d = j + 1; d < road.size(); d++) {
				// 거꾸로 하긴 함 j = x i = y다 원래
				init();

				int ix = road[i].first; int iy = road[i].second;
				int jx = road[j].first; int jy = road[j].second;
				int dx = road[d].first; int dy = road[d].second;

				cmap[ix][iy] = 1;
				cmap[jx][jy] = 1;
				cmap[dx][dy] = 1;

				for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++) {
					fillVirus(it->second, it->first);
				}

				int cnt = 0;
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= M; j++) {
						if (cmap[i][j] == 0) {
							cnt++;
						}
					}
				}

				max = (max < cnt) ? cnt : max;
			}
		}
	}

	cout << max << endl;

	system("pause");
}