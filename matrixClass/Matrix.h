#pragma once

int menu();
void readFile(int& r, int& c);


double** generate(int, int);
double** create(int, int);
double** load(int row, int col);



class Matrix
{

private:

	int col;
	int row;
	double** matrix_array;


public:

	
	void operator+=(Matrix* second);
	void operator-=(Matrix* second);
	void operator/=(double scal);
	void operator*=(Matrix* second);

	
	Matrix* minorMatrix(int, int);

	void printMatrix();
	

	bool isSquare();

	
	void save();
	

	Matrix(int r, int c, double** array);
	Matrix(Matrix&m);

	
	void plus(Matrix *m2, Matrix *m3);
	void minus(Matrix* m2, Matrix* m3);
	
	
	void times(Matrix* m2, Matrix* m3);
	void times_scal(double, Matrix *m3);
	void divide_scal(double scal, Matrix* m3);
	void pow(int n, Matrix* m3);

	bool areEqual(Matrix *m2);
	
	double findNorm();
	double findDet();

	void invertMatrix(Matrix* m3);
	Matrix transMatrix(Matrix* m3);

	bool* checkType();

};


