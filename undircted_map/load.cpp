#include"graphic.h"
void visit(edgeNode e) {
	cout << e.t1 << "<->" << e.t2 << ' ' << "weight:" << e.weight << endl;;
}

void printpath(int** path, int i, int j) {
	if (path[i][j] == -1) {
		cout << i << "<->" << j <<' ';
	}
	else {
		int mid = path[i][j];
		printpath(path, i, mid);
		printpath(path, mid, j);
	}
}

void shellSort(edgeNode* arr, int n) {
	edgeNode temp;
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap].weight > temp.weight; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

int Find(int* arr, int x) {
	int root, pos;
	pos = x;
	while (arr[x] > 0) {
		x = arr[x];
	}
	root = x;//记录代表元素下标
	//优化
	x = pos;
	while (arr[x] > 0) {
		pos = arr[x];
		arr[x] = root;
		x = pos;
	}
	return root;
}
void Union(int* arr, int x, int y) {
	int root1 = Find(arr, x), root2 = Find(arr, y);
	if (arr[root1] < arr[root2]) {
		arr[root1] += arr[root2];
		arr[root2] = root1;
	}
	else {
		arr[root2] += arr[root1];
		arr[root1] = root2;
	}
}