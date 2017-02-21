#include <iostream>
#include <cmath>

using std::cout;

const int MAX = 100;

void minAndMaxInArray(int array[], int n) {
	int min = array[0];
	int max = array[1];

	for (int i = 0; i < n; i++) {
		int currentElement = array[i];

		if (abs(currentElement) > abs(max)) {
			max = currentElement;
		}

		if (abs(currentElement) < abs(min)) {
			min = currentElement;
		}
	}

	cout << "The element with max absolute value in the array is " << max << "\n";
	cout << "The element with min absolute value in the array is " << min << "\n";

}

void minAndMaxOfMatrix(int matrix[][MAX], int rows, int cols) {
	int min = matrix[0][0];
	int max = matrix[0][0];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int currentElement = matrix[i][j];

			if (abs(currentElement) > abs(max)) {
				max = currentElement;
			}

			if (abs(currentElement) < abs(min)) {
				min = currentElement;
			}
		}
	}

	cout << "The element with max absolute value in the matrix is " << max << "\n";
	cout << "The element with min absolute value in the matrix is " << min << "\n";
}


int main() {
	int array[] = { -1, -10 , -50 , 25, 40 };
	int matrix[MAX][MAX] =
	{ {20,30,40,-50},
	  {50,-60,70,-20},
	  {60,30,-100,30} };

	minAndMaxInArray(array, 5);

	minAndMaxOfMatrix(matrix, 3, 4);



	system("pause");
	return 0;
}