#include <iostream>
using namespace std;

int N;
int B, C;
int A[1000001];
long long int total = 0;

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int app;

		cin >> app;

		A[i] = app;
	}

	cin >> B >> C;

	for (int i = 1; i <= N; i++) {
		if (A[i] <= B) {
			total++;
		}
		else {
			int roomMan;

			if ((A[i] - B) % C) {
				roomMan = 2 + ((A[i] - B) / C);
			}
			else{
				roomMan = 1 + ((A[i] - B) / C);
			}

			total += roomMan;
		}
	}

	cout << total << endl;

	system("pause");

	return 0;
}