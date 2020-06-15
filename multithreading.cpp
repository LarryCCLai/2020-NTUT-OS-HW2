#include"Matrix.h"
#include<thread>
#include<Windows.h>
#include<vector>
void MultiplyMatrix(Matrix* C, Matrix* A, Matrix* B, int rowS, int rowE, int colS, int colE) {
	for (int i = rowS; i <= rowE; i++) {
		for (int j = colS; j <= colE; j++) {
			double sum = 0;
			for (int idx = 0; idx < A->cols; idx++) {
				sum += A->data[i][idx] * B->data[idx][j];
			}
			C->data[i][j] = sum;
		}
	}
}
Matrix* Matrix::MultiplyMultithreading(Matrix* A, Matrix* B, int rowNThreads, int colNThreads) {
    Matrix* C = new Matrix(A->rows, B->cols);
	std::vector<std::thread> threads; 
	int partitionRows = A->rows / rowNThreads;
	int partitionCols = B->cols / colNThreads;
	for (int i = 0; i < A->rows; i += partitionRows) {
		for (int j = 0; j < B->cols; j += partitionCols) {
			threads.push_back(std::thread(MultiplyMatrix, C, A, B, i, i + partitionRows - 1, j, j + partitionCols - 1));
		}
	}
	for (int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
	return C;
}


