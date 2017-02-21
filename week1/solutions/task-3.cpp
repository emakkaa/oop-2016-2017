#include <iostream>

using std::cout;

const int MAX = 100;

void sequenceInMatrix(int matrix[][MAX], int rows, int cols) {
	int maxSequence = 1;
	int curSequence = 1;

	for (int row = 0; row < rows; row++)
	{
		// reset for each row
		curSequence = 1;

		for (int col = 1; col < cols; col++)
		{
			if (matrix[row][col] ==
				matrix[row][col - 1])
			{
				curSequence++;
			}
			else
			{
				// check if cursequence is longest
				if (curSequence > maxSequence)
				{
					maxSequence = curSequence;
				}
				//reset curseq
				curSequence = 1;
			}
		}

		// double check for last element on row
		if (curSequence > maxSequence)
		{
			maxSequence = curSequence;
		}
	}

	// Step 2: Check By Cols
	for (int col = 0; col < cols; col++)
	{
		// reset for each col
		curSequence = 1;

		for (int row = 1; row < rows; row++)
		{
			if (matrix[row][col] ==
				matrix[row - 1][col])
			{
				curSequence++;
			}
			else
			{
				// check if cursequence is longest
				if (curSequence > maxSequence)
				{
					maxSequence = curSequence;
				}
				//reset curseq
				curSequence = 1;
			}
		}

		// double check cursequence for last element
		if (curSequence > maxSequence)
		{
			maxSequence = curSequence;
		}
	}

	//Step 3: Check first diagonal

	//initialize temporary indexes
	int currentRow = 0;
	int currentCol = 0;

	//reset sequence
	curSequence = 1;

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++) {
			currentCol = col;
			currentRow = row;
			curSequence = 1;
			//check if it is diagonal seq
			while (currentCol < cols && currentRow < rows) {
				
				currentRow++;
				currentCol++;
				if (matrix[row][col] == matrix[currentRow][currentCol]) {
					curSequence++;
				}
				//if it is not sequence break the while loop
				else {
					break;
				}

				//check sequence
				if (curSequence > maxSequence) {
					maxSequence = curSequence;
				}
			}
		}
	}
	//reset temps
	currentRow = 0;
	currentCol = 0;

	//reset sequence
	curSequence = 1;

	//Step 4: Check the other diagonal
	for (int row = rows - 1; row >= 0; row--)
	{
		for (int col = 0; col < cols; col++) {
			currentCol = col;
			currentRow = row;
			curSequence = 1;
			//check if it is diagonal seq
			while (currentCol < cols && currentRow > 0) {
				currentRow--;
				currentCol++;
				if (matrix[row][col] == matrix[currentRow][currentCol]) {
					curSequence++;
				}
				//if it is not sequence break the while loop
				else {
					break;
				}

				//check sequence
				if (curSequence > maxSequence) {
					maxSequence = curSequence;
				}
			}
		}
	}


	cout << "The maximal sequence is " << maxSequence << "\n";
}


int main() {

	int matrix[MAX][MAX] = { { 5,2,5,1 },
							{ 3,5,1,2 },
							{ 5,2,5,12 },
							{ 1,2,3,1 } };

	sequenceInMatrix(matrix, 4, 4);

	system("pause");
	return 0;
}