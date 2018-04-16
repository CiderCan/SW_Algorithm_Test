#include <iostream>
using namespace std;

bool island[50][50];
bool visit[50][50];
int cnt;
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			island[i][j] = false;
			visit[i][j] = false;
		}
	}

	cnt = 1;
}
void mark(int i, int j, int w, int h) {
	visit[i][j] = true;

	/*for (int a = 0; a < h; a++) {
		for (int b = 0; b < w; b++) {
			cout << visit[a][b] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	for (int d = 0; d < 8; d++) {
		int vx = j + dx[d];
		int vy = i + dy[d];

		if (0 <= vx && vx < w && 0 <= vy && vy < h) {
			if (island[vy][vx] && !visit[vy][vx]) {
				mark(vy, vx, w, h);
			}
		}
	}
}
int main() {
	int w, h;
	w = h = 1;

	while (w + h) {
		init();
		cin >> w >> h;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> island[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (island[i][j] && !visit[i][j]) {
					mark(i, j, w, h);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt - 1);
	}

	return 0;
}