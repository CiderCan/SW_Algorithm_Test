#include <iostream>
#include <queue>
using namespace std;

const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,-1,0,1 };

struct ABC { int cnt, rx, ry, bx, by; };
queue<ABC> que;

int n, m, rx, ry, bx, by;
bool chk[11][11][11][11];
char toy[12][12];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> toy[i];

		for (int j = 0; j < m; j++) {
			if (toy[i][j] == 'R') rx = i, ry = j;
			if (toy[i][j] == 'B') bx = i, by = j;
		}
	}

	chk[rx][ry][bx][by] = 1;
	que.push({ 0,rx,ry,bx,by });
	while (!que.empty()) {
		ABC now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nrx = now.rx, nry = now.ry;
			int nbx = now.bx, nby = now.by;
			int cr = 0, cb = 0;

			while (toy[nrx + dx[i]][nry + dy[i]] != '#' && toy[nrx][nry] != 'O')
				nrx += dx[i], nry += dy[i], cr++;
			while (toy[nbx + dx[i]][nby + dy[i]] != '#' && toy[nbx][nby] != 'O')
				nbx += dx[i], nby += dy[i], cb++;

			if (nrx == nbx && nry == nby) {
				if (toy[nrx][nry] == 'O') continue;
				cr < cb ? (nbx-=dx[i],nby-=dy[i]) : (nrx-=dx[i],nry-=dy[i]);
			}

			if (toy[nbx][nby] == 'O') continue;
			if (toy[nrx][nry] == 'O') return;  printf("%d\n", now.cnt + 1);

			if (chk[nrx][nry][nbx][nby]) continue;
			if (now.cnt < 9) {
				chk[nrx][nry][nbx][nby] = 1;
				que.push({ now.cnt+1,nrx,nry,nbx,nby });
			}
		}
	}

	printf("-1\n");

	return 0;
}