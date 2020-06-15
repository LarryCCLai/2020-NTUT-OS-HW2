#include"Matrix.h"
Matrix* Matrix::MultiplyForloop(Matrix* A, Matrix* B) {
    Matrix* C = new Matrix(A->rows, B->cols);
	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < B->cols; j++) {
			double sum = 0;
			for (int idx = 0; idx < A->cols; idx++) {
				sum += A->data[i][idx] * B->data[idx][j];
			}
			C->data[i][j] = sum;
		}
	}
	return C;
}
