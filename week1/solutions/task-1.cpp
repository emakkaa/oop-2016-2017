#include <iostream>

const int START = 1;

void NestedLoops(int n, int current) {
	if (current == n)
		return;

	for (int i = 1; i < n; ++i) {
		NestedLoops(n, current + 1);
	}
}

int main() {
	NestedLoops(5, START);

	system("pause");
	return 0;
}