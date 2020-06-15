#ifndef MATRIX_H
#define MATRIX_H
class Matrix {
private:
public:
    double** data;
    int rows;
    int cols;
    Matrix(int _rows, int _cols);
    ~Matrix();
    static void* Mat(int rows, int cols, int size);
    static Matrix* MultiplyForloop(Matrix* A, Matrix* B);
    static Matrix* MultiplyMultithreading(Matrix* A, Matrix* B, int rowNThreads, int colNThreads);
};
#endif
