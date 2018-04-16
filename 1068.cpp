#include <iostream>
#include <vector>
using namespace std;

int tree[50];
bool check[50] = { 0, };

void removeNode(int r, int N) {
	for (int i = 0; i < N; i++) {
		if (tree[i] == r) {
			removeNode(i, N);
			tree[i] = -2;
		}
	}
}

void search(int i) {
	if (!check[i]) {
		check[i] = true;
	}

	if (i == -1) {
		return;
	}

	search(tree[i]);
}

void printTree(int N) {
	for (int i = 0; i < N; i++) {
		cout << tree[i] << " ";
	}
	cout << endl;
}

int main() {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		tree[i] = num;
	}

	//printTree(N);

	int remove;
	cin >> remove;

	tree[remove] = -2;
	removeNode(remove, N);

	//printTree(N);
	
	for (int i = 0; i < N; i++) {
		if (tree[i] != -2) {
			search(tree[i]);
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		if (!check[i] && tree[i] != -2) {
			count++;
		}
	}

	cout << count << endl;

	system("pause");
}