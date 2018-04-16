#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<pair<int, int>, int>> st;
int board[21][21] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int type[11] = { 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048 };
bool exist[11] = { 0, };
bool visit[21][21] = { 0, };
bool endProc = false;
int result;
// 0 : U ? 1 : D ? 2 : L ? 3: R

void searchNum(int x, int y, int num, int time) {
	visit[y][x] = true;

	while (time < 5) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 < nx && nx <= N && 0 < ny && ny <= N && !visit[ny][nx]) {
				if (num == board[ny][nx]) {
					result = 2 * num;
					endProc = true;
					return;
				}
				else if (board[ny][nx] == 0) {
					x = nx;
					y = ny;
				}
				else {
					x = nx;
					y = ny;
				}
			}
		}
	}
}

bool cmp (const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
	return a.second > b.second;
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;

			cin >> num;

			board[i][j] = num;
		
			for (int d = 0; d < 11; d++) {
				if (type[d] == num && !exist[d]) {
					st.push_back(make_pair(make_pair(j, i), num));
					exist[d] = true;
				}
			}
		}
	}

	sort(st.begin(), st.end(), cmp);
	int max = st.begin()->second;

	for(vector<pair<pair<int, int>, int>>::iterator it = st.begin(); it != st.end(); it++){
		pair<int, int> search = it->first;
		int posx = search.first;
		int posy = search.second;
		int num = board[posy][posx];
		result = 0;
		searchNum(posx, posy, num, 4);

		if(result){
			break;
		}
	}

	if (result < max) {
		cout << max << endl;
	}
	else {
		cout << result << endl;
	}
	

	system("pause");

	return 0;
}