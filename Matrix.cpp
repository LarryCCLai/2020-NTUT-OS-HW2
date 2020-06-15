#include"Matrix.h"
void* Matrix::Mat(int rows, int cols, int size) {
	void** matrix;
	//char :1byte,  rows pointer size + rows * cols * data type size;
	matrix = (void**)new char[rows * sizeof(void*) + rows * cols * size]; 
	for (int i = 0; i < rows; i++)
		matrix[i] = ((char*)(matrix + rows)) + i * cols * size;
	return matrix;
}
Matrix::Matrix(int _rows, int _cols) {
    this->rows = _rows;
    this->cols = _cols;
    this->data = (double**)Mat(this->rows, this->cols, sizeof(double));
}
Matrix::~Matrix() {
    delete []this->data;
}
