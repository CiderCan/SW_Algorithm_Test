#include <iostream>
using namespace std;

int Narray[1000001] = { 0, };

void solu(int num) {
	if (num == 1) {
		Narray[1] = 0;
	}

	if (num % 3 == 0) {
		if (Narray[num / 3] + 1 < Narray[num]) {
			Narray[num] = Narray[num / 3] + 1;
		}
	}

	if (num % 2 == 0) {
		if (Narray[num / 2] + 1 < Narray[num]) {
			Narray[num] = Narray[num / 2] + 1;
		}
	}
	
	if (Narray[num - 1] + 1 < Narray[num]) {
		Narray[num] = Narray[num - 1] + 1;
	}
}

int main() {
	int input;

	for (int i = 1; i < 1000001; i++) {
		Narray[i] = 1000000;
		solu(i);
	}

	cin >> input;
	cout << Narray[input] << endl;

	return 0;
}