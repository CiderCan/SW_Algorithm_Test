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
1. ���� ��ġ�� û���Ѵ�.
2. ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
	1. ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
	2. ���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
	3. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
	4. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
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