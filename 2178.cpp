#include <iostream>
#include <queue>
using namespace std;

bool map[101][101] = { 0, };
bool visit[101][101] = { 0, };
int N;
int M;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<pair<int, int>, int>> q;

void process(int x, int y, int step) {
	//cout << "(" << x << ", " << y << ")" << " : " << step << endl;
	if (x == N - 1 && y == M - 1) {
		cout << step << endl;
	}

	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];

		if (map[mx][my] && !visit[mx][my]) {
			q.push(make_pair(make_pair(mx, my), step + 1));
			visit[mx][my] = true;
		}
	}

	if (!q.empty()) {
		pair<pair<int, int>, int> next = make_pair(make_pair(q.front().first.first, q.front().first.second), q.front().second);
		q.pop();

		process(next.first.first, next.first.second, next.second);
	}
}

int main() {
	cin >> N >> M;

	getchar();

	for (int i = 0; i < N; i++) {
		char * line = new char[M + 1];

		cin.getline(line, M + 1);

		for (int j = 0; j < M; j++) {
			if (line[j] == '1') {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 0;
			}
		}
	}

	visit[0][0] = true;
	process(0, 0, 1);

	system("pause");

	return 0;
}