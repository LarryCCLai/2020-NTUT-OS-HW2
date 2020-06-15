#include<iostream>
#include<Windows.h>
#include <iomanip>
#include"Matrix.h"
using namespace std;
#define E6 1000000
#define E3 1000
int main() {
	Matrix* A = new Matrix(35, 60);
	Matrix* B = new Matrix(60, 35);
	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < A->cols; j++) {
			A->data[i][j] = 3.5 * (static_cast<double>(i) + 1) - 6.6 * (static_cast<double>(j) + 1);
			B->data[j][i] = 6.6 + 8.8 * (static_cast<double>(j) + 1) - 3.5 * (static_cast<double>(i) + 1);
		}
	}
	Matrix* C;
	int Times = 3;
	cout << "[Version1] For loop " << endl;
	LARGE_INTEGER Freq;
	LARGE_INTEGER BeginTime;
	LARGE_INTEGER EndTime;
	for (int i = 0; i < Times; i++) {
		QueryPerformanceFrequency(&Freq);
		QueryPerformanceCounter(&BeginTime);
		C = Matrix::MultiplyForloop(A,B);
		QueryPerformanceCounter(&EndTime);
		cout << "Execute time: " << static_cast<double>((EndTime.QuadPart - BeginTime.QuadPart)) * E3 / Freq.QuadPart << " ms" << endl;
	}
	cout << "[Version2] Multithreading, 25 threads, 7x7 matrix per thread" << endl;
	for (int i = 0; i < Times; i++) {
		QueryPerformanceFrequency(&Freq);
		QueryPerformanceCounter(&BeginTime);
		C = Matrix::MultiplyMultithreading(A, B, 5, 5);
		QueryPerformanceCounter(&EndTime);
		cout << "Execute time: " << static_cast<double>((EndTime.QuadPart - BeginTime.QuadPart))* E3 / Freq.QuadPart << " ms" << endl;
	}
	cout << "[Version3] Multithreading, 49 threads, 5x5 matrix per thread" << endl;
	for (int i = 0; i < Times; i++) {
		QueryPerformanceFrequency(&Freq);
		QueryPerformanceCounter(&BeginTime);
		C = Matrix::MultiplyMultithreading(A, B, 7, 7);
		QueryPerformanceCounter(&EndTime);
		cout << "Execute time: " << static_cast<double>((EndTime.QuadPart - BeginTime.QuadPart)) * E3 / Freq.QuadPart << " ms" << endl;
	}
	cout << "[Version4] Multithreading, 35 threads, 1x35 matrix per thread" << endl;
	for (int i = 0; i < Times; i++) {
		QueryPerformanceFrequency(&Freq);
		QueryPerformanceCounter(&BeginTime);
		C = Matrix::MultiplyMultithreading(A, B, 35, 1);
		QueryPerformanceCounter(&EndTime);
		cout << "Execute time: " << static_cast<double>((EndTime.QuadPart - BeginTime.QuadPart))* E3 / Freq.QuadPart << " ms" << endl;
	}
	cout << "[Version5] Multithreading, 35 threads, 35x1 matrix per thread" << endl;
	for (int i = 0; i < Times; i++) {
		QueryPerformanceFrequency(&Freq);
		QueryPerformanceCounter(&BeginTime);
		C = Matrix::MultiplyMultithreading(A, B, 1, 35);
		QueryPerformanceCounter(&EndTime);
		cout << "Execute time: " << static_cast<double>((EndTime.QuadPart - BeginTime.QuadPart))* E3 / Freq.QuadPart << " ms" << endl;
	}
	system("pause");
	return 0;
}
