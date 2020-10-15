#pragma once

int menu();
void printMatrix(int, int, double**);
double** create(int, int);
double** generate(int, int);
double** load(int, int);


class Matrix
{

public:
	int col;
	int row;
	double** matrix_array;

	

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

	void chooseMatrix(Matrix m3);

	void invertMatrix();
	
	Matrix transMatrix();

	void checkType();

};


