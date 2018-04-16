#include <iostream>
#include <queue>
using namespace std;

int N, K, L; // N : map 크기 K : 사과 개수 L : 방향변환 개수
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool apple[101][101] = { 0, };
queue<pair<int, char>> q;

class Node {
public:
	int x;
	int y;
	Node * next;

	Node() {
		x = 0;
		y = 0;
		next = NULL;
	}

	Node(int x, int y) {
		this->x = x;
		this->y = y;
		next = NULL;
	}

	Node(int x, int y, Node * next) {
		this->x = x;
		this->y = y;
		this->next = next;
	}
};

struct snake {
	Node * head;
	Node * next;
	Node * tail;
	int length;
	int direction;
};

snake s;

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

	Node * travel = s.head->next;

	while (travel != NULL) {
		if (nx == travel->x && ny == travel->y) {
			//cout << "crush!! : (" << nx << ", " << ny << ")" << endl;
			return 1;
		}
		travel = travel->next;
	}

	return 0;
}

void updatePos(int mx, int my) {
	Node * travel = s.head;
	Node * delNode;

	int len = s.length - 1;

	while (len--) {
		travel = travel->next;
	}

	if (travel->next != nullptr) {
		delNode = travel->next;
		delete delNode->next;
		delNode = nullptr;
		delete delNode;
		travel->next = nullptr;
	}
}

void printNode() {
	Node * travel = s.head;

	cout << "current snake position : " << endl;

	while (travel != nullptr) {
		cout << "(" << travel->x << ", " << travel->y << ") -> ";
		travel = travel->next;
	}
	cout << endl;

	delete travel;
}

int proc(int time) {
	int nx = s.head->x + dx[s.direction];
	int ny = s.head->y + dy[s.direction];

	//cout << time << " - (" << s.head->x << ", " << s.head->y << ") : " << s.direction << endl;
	//printNode();

	if (crush(nx, ny)) {
		return time + 1;
	}
	else {
		if (apple[ny][nx]) {
			apple[ny][nx] = false;
			Node nextHead(nx, ny, s.head);
			s.head = &nextHead;
			s.length++;
		}
		else {
			Node nextHead(nx, ny, s.head);
			s.head = &nextHead;
			updatePos(dx[s.direction], dy[s.direction]);
		}
		if (!q.empty()) {
			if (time == q.front().first - 1) {
				s.direction = chgDirection(dx[s.direction], dy[s.direction], q.front().second);
				q.pop();
			}
		}
		proc(time + 1);
	}
}

int main() {
	Node head(1, 1);
	s.head = &head;
	s.next = NULL;
	s.tail = &head;
	s.length = 1;
	s.direction = 3;

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

	cout << proc(0) << endl;

	system("pause");

	return 0;
}