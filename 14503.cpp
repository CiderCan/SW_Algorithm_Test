#include <iostream>
using namespace std;

int N, M;
int map[52][52];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
// 0 : N ? 1 : E ? 2 : S ? 3 : W

void printMap() {
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int turnLeft(int direct) {
	switch (direct) {
	case 0:
		return 3;
	case 1:
		return 0;
	case 2:
		return 1;
	case 3:
		return 2;
	}
}

int turnBack(int direct) {
	switch (direct) {
	case 0:
		return 2;
	case 1:
		return 3;
	case 2:
		return 0;
	case 3:
		return 1;
	}
}

/*
1. 현재 위치를 청소한다.
2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
	1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
	2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
	3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
	4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
*/

void proc(int x, int y, int direct) {
	static int answer = 1;
	map[y][x] = 2;

	//printMap();
	//system("pause");

	int num = 4;
	int cnt = 0;
	int nDirect = turnLeft(direct);

	while (num--) {
		int nx = x + dx[nDirect];
		int ny = y + dy[nDirect];

		if (map[ny][nx] == 0) {
			answer++;

			proc(nx, ny, nDirect);
			cnt++;

			break;
		}
		else {
			nDirect = turnLeft(nDirect);
		}
	}
	
	if (cnt == 0) {
		int nx = x + dx[turnBack(direct)];
		int ny = y + dy[turnBack(direct)];

		if (map[ny][nx] != 1) {
			proc(nx, ny, direct);
		}
		else {
			cout << answer << endl;

			return;
		}
	}
}

int main() {
	int sx, sy, direction;

	cin >> N >> M;

	cin >> sy >> sx >> direction;

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			if (i == 0 || i == N + 1 || j == 0 || j == M + 1) {
				map[i][j] = 1;
			}
			else {
				int num;
				cin >> num;

				map[i][j] = num;
			}
		}
	}

	map[sy + 1][sx + 1] = 2;

	proc(sx + 1, sy + 1, direction);

	system("pause");

	return 0;
}