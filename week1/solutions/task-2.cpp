#include <iostream>
#include <climits>

using std::cout;

const int MAX = 100;
const int SQUARESIZE = 3;

void MaxAndMinSquareSum(int matrix[][MAX], int rows , int cols) {
	if (rows < SQUARESIZE || cols < SQUARESIZE) {
		cout << "Invalid matrix compared to the square size";
		return;
	}

	int maxSum = INT_MIN;
	int minSum = INT_MAX;

	for (int i = 0; i <= rows - SQUARESIZE; ++i) {
		for (int j = 0; j <= cols - SQUARESIZE; ++j) {
			//can be also done with 2 nested loops
			int tempSum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] +
				matrix[i + 1][j] + matrix[i + 1][j + 1] + matrix[i + 1][j + 2] +
				matrix[i + 2][j] + matrix[i + 2][j + 1] + matrix[i + 2][j + 2];

			if (tempSum > maxSum) {
				maxSum = tempSum;
			}

			if (tempSum < minSum) {
				minSum = tempSum;
			}
		}
	}

	cout << "The maximal sum of square with size - " << SQUARESIZE << " is " << maxSum << "\n";
	cout << "The minimal sum of square with size - " << SQUARESIZE << " is " << minSum << "\n";
}

int main() {
	int matrix[MAX][MAX] = { {-20,2,6,5},
							 {1,-1,9,2},
							 {0,2,7,12},
							 {50,2,3,4} };

	MaxAndMinSquareSum(matrix, 4, 4);

	system("pause");
	return 0;
}