#pragma once

int menu();

class Matrix
{

public:
	
	int col;
	int row;
	double** matrix_array;

	void printMatrix(Matrix m);
	void chooseMatrix(Matrix m3);

	double** generate();
	double** generate(int, int);

	double** create();
	double** create(int, int);

	double** load();

	Matrix();
	Matrix(int r, int c);
	Matrix(const Matrix& m);

	void plus();
	void minus();
	
	void times();
	double** times(Matrix* m2);
	void times_scal();

	void divide_scal();
	
	void pow();

	void areEqual();
	bool areEqual(Matrix m3);

	void findDet();
	void invertMatrix();
	
	Matrix transMatrix();
	Matrix transMatrix(Matrix m);

	void checkType();

};


