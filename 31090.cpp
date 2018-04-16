#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> snake;
bool apple[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int N, K, L;
int direction = 3;
queue<pair<int, char>> q;

int chgDirection(int mx, int my, char c) {
	// 0 : U ? 1 : D ? 2 : L ? 3 : R
	switch (c) {
	case 'D':
		if (mx == 1 && my == 0)
			return 1;
		else if (mx == -1 && my == 0)
			return 0;
		else if (mx == 0 && my == 1)
			return 2;
		else
			return 3;

	case 'L':
		if (mx == 1 && my == 0)
			return 0;
		else if (mx == -1 && my == 0)
			return 1;
		else if (mx == 0 && my == 1)
			return 3;
		else
			return 2;
	}
}

bool crush(int nx, int ny) {
	if (nx > N || ny > N || nx < 1 || ny < 1) {
		return 1;
	}

	queue<pair<int, int>> nq = snake;

	while (nq.size() > 1) {
		if (nx == nq.front().first && ny == nq.front().second) {
			return 1;
		}
		nq.pop();
	}

	return 0;
}
void printNode() {
	cout << "current snake position : " << endl;

	queue<pair<int, int>> nq = snake;

	while (!nq.empty()) {
		cout << "(" << nq.front().first << ", " << nq.front().second << ") <- ";
		nq.pop();
	}
	cout << endl;
}

int proc(int time) {
	int nx = snake.back().first + dx[direction];
	int ny = snake.back().second + dy[direction];

	if (crush(nx, ny)) {
		return time;
	}

	snake.push(make_pair(nx, ny));

	if (!apple[ny][nx]) {
		snake.pop();
	}
	else {
		apple[ny][nx] = false;
	}

	if (!q.empty()) {
		if (time == q.front().first) {
			direction = chgDirection(dx[direction], dy[direction], q.front().second);
			q.pop();
		}
	}

	//cout << time << " - (" << snake.back().first << ", " << snake.back().second << ") : " << direction << endl;
	//printNode();

	proc(time + 1);
}

int main() {
	snake.push(make_pair(1, 1));

	cin >> N >> K;

	while (K--) {
		int ax, ay;

		cin >> ax >> ay;

		apple[ax][ay] = true;
	}

	cin >> L;

	while (L--) {
		int second;
		char dir;

		cin >> second >> dir;

		q.push(make_pair(second, dir));
	}

	cout << proc(1) << endl;

	system("pause");

	return 0;
}