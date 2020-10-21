#pragma once

int menu();





class Matrix
{

public:
	
	int col;
	int row;
	double** matrix_array;

	double** minorMatrix(int, int, Matrix);

	void printMatrix(Matrix m);
	void chooseMatrix(Matrix m3);

	double** generate();
	double** generate(int, int);

	double** create();
	double** create(int, int);

	double** load();
	void save();

	Matrix();
	Matrix(int r, int c);
	Matrix(const Matrix& m);

	void plus();
	void minus();
	
	void times();
	double** times(Matrix* m2);
	void times_scal();
	Matrix times_scal(double);

	void divide_scal();
	void divide_scal(double);
	
	void pow();

	void areEqual();
	bool areEqual(Matrix m3);
	
	void findNorm();
	double findDet();
	double findDet(int, double**);
	void invertMatrix();
	
	Matrix transMatrix();
	Matrix transMatrix(Matrix m);

	void checkType();

};


