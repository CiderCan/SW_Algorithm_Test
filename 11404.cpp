#include <iostream>
using namespace std;

int fee[101][101] = { 0, };
int D[101][101] = { 0, };
int link[101][101] = { 0, };

int main() {
	int N, M;

	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			fee[i][j] = 20000000;
		}
	}

	for (int j = 1; j <= M; j++) {
		int line1;
		int line2;
		int charge;

		cin >> line1;
		cin >> line2;
		cin >> charge;

		if (fee[line1][line2] > charge) {
			fee[line1][line2] = charge;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			D[i][j] = fee[i][j];
			link[i][j] = -1;
		}
		D[i][i] = 0;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[i][k] + D[k][j];

					if (link[k][j] == -1) {
						link[i][j] = k;
					}
					else {
						link[i][j] = link[k][j];
					}
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << D[i][j] << " ";
		}
		cout << endl;
	}
}