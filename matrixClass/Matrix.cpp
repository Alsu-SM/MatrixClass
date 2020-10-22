#include <iostream>
#include<locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <fstream>
#include "Matrix.h"

using namespace std;
int v = 0;
bool matrixExists = false;


 

/*����� ���������� ����� ����� � ��������, 
������� ���������� ����� � ����� � ���������� �������� �� ����� ������. 

��������� - ����� ������� ������� ����� �� ������ �������, � ����� ������ ������ ������� ������� ���.
*/

void readFile(int &r, int &c) {
	ifstream in("input.txt");

	if (in.is_open())
	{

		int count = 0;// ����� ����� � �����
		int temp;//��������� ����������


		while (!in.eof())// ��������� ���� �� �������� ����� ����� eof
		{
			in >> temp;//� ������� ��������� �� ����� �����
			count++;// ����������� ������� ����� �����
		}


		//������� ��������� ������� � ������ � ������ �����
		in.seekg(0, ios::beg);
		in.clear();

		//����� �������� � ������ ������� ������� ����� 0
		int count_space = 0;
		char symbol;
		while (!in.eof())//�� ������ ������ ���� ������������ ������ �����
		{
			//������ ��� ����� ��������� �� �����, � ����������� ��������� ������
			in.get(symbol);//������� ������� ������
			if (symbol == ' ') count_space++;//���� ��� ������, �� ����� �������� �����������
			if (symbol == '\n') break;//���� ����� �� ����� ������, �� ������� �� �����
		}


		//����� ��������� � ������ � ������ �����
		in.seekg(0, ios::beg);
		in.clear();

		//������ �� ����� ������� ����� � ����� � ������� �������� � ������ �����

		r = count_space + 1; //����� � ����� ������
		c = count / r; //����� �����
	}

	
}
/*������� ���������� ������� ������, ������� ���������� �������������� �� �������� �������
r-��� ������ � c-���� ������� */
Matrix* Matrix::minorMatrix(int r, int c) {
	
	int n = this->row - 1; // ����� ����� � �������� ������
	
	Matrix* minor = new Matrix(n, n, 0);

	minor->matrix_array = new double* [n];    // ������ ����������
	for (int i = 0; i < n; i++) {   //
		minor->matrix_array[i] = new double[n];     // ������������� ����������

	}
	
	int minor_i = 0, minor_j = 0;
	
	for (int i = 0; i < this->row; i++)
	{
		if (i == r) {
			//i++;
			continue;
		}
		for (int j = 0; j < this->col; j++)
		{
			if (j == c) {
				//j++;
				continue;
			}

			minor->matrix_array[minor_i][minor_j] = this->matrix_array[i][j];
			//minor_i++;
			minor_j++;
			if (minor_j == n) {
				minor_j = 0;
				minor_i++;
			}

		}
	}
	
	return minor;


}

/*������� ��������� ���������� ������� � ���� output.txt*/

void Matrix::save() {

	ofstream in("output.txt");
	if (in.is_open())
	{
		//���� �������� ����� ������ �������
		
		for (int i = 0; i < row; i++)
		{
			if (i>0)
				in << "\n";
			for (int j = 0; j < col; j++)
				in << matrix_array[i][j] << " ";
		}
		
	}
	else 
		cout << "�� ������� ������� ���� " << endl;
}

/*�������, ����������� ����. 
��� ������ ������ ���������� ������� ������� � �������� �����������.
��� ����������� ���������� �������� ������ ��������, � �.�. ����� �� ��������� ��� ����� ����� �������*/

int menu()
{
	if (matrixExists) {
		cout << "\n\n��� �� ������ �������?\n" << endl;
		cout << "\n1 - �������� ����� �������\n\n2 - ��������\n3 - ���������\n4 - ��������� �� �������\n5 - ��������� �� ������\n6 - ������� �� ������\n7 - ���������� � �������\n8 - ��������� � ������ �������� (�������� �� ���������)\n 9 - �������� ���� ������� \n10 - ����������������\n11 - ���������� ������������\n12 - ���������� �������� �������\n\n13 - ��������� ������� � ����\n\n0 - �����" << endl;

		for (;;)
		{
			cout << "\n��� �����: ";
			cin >> v;
			cout << "\n";

			if (v < 0 || v > 13) {
				cout << "\n����������, ������� ����� �� 0 �� 13.\n\n" << endl;
				continue;
			}

			return v;
		}
	}
	else {
		cout << "����� ���������� � ���������! ������� enter, ����� �������� ����� �������" << endl;
		v = 1;
		cin.get();
		matrixExists = true;
		return v;

	}
}

/*������ �������*/

void Matrix::printMatrix() {


	for (int i = 0; i < this->row; i++) {
		{
			cout << "\n";
			for (int j = 0; j < this->col; j++) {
				
					cout << this->matrix_array[i][j] << " ";
				
			}
		}
	}
}

/*������� ��� ������ �������� �������. 
����� �������� ����� �������, � ����� �������� ���������� ��������, - �������������� ��� ��������.
���� �������� ��������, ������ �� ��������. 
��� ������ �������������� - ������ ���� ������� m � ������������ ������ matrix_array*/

void Matrix::chooseMatrix(Matrix* m3, int ans) {
	
	if (ans == 2) {
		row = m3->row;
		col = m3->col;
		delete[] matrix_array;

		matrix_array = new double* [row];    // ������ ����������
		for (int i = 0; i < row; i++) {   //
			matrix_array[i] = new double[col];     // ������������� ����������

		}

		for (int i = 0; i < row; i++)   //������ �������
		{
			for (int j = 0; j < col; j++)   //������� �������
			{
				matrix_array[i][j] = m3->matrix_array[i][j];  //��������� ������� ������

			}
		}

	}
}


/*������� ��� ������� ����� ������� � ����������*/

double** Matrix::create(int r, int c)

{
	double** matrix;

	// ��������
	matrix = new double* [r];    // ������ ����������
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // ������������� ����������

	}

	for (int i = 0; i < r; i++) {
		cout << "������ " << i + 1 << " ������: ";
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}

	return matrix;

}


/*������� ��� ���������� �������������� �������*/

double** Matrix::generate(int r, int c) {


	double** matrix;

	// ��������
	matrix = new double* [r];    // ������ ����������
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // ������������� ����������

	}

	for (int i = 0; i < r; i++)   //������ �������
	{
		for (int j = 0; j < c; j++)   //������� �������
		{
			matrix[i][j] = 1 + rand() % 9;  //��������� ������� ������

		}
	}

	return matrix;


}

/*�������� ������� �� �����*/

double** Matrix::load(int row, int col) {
	

	//������� �������� ����� � ��������� ��� � ������
	ifstream in("input.txt");

	if (in.is_open()) 
	{
		double** matrix;

		// ��������
		matrix = new double* [row];    // ������ ����������
		for (int i = 0; i < row; i++) {   //
			matrix[i] = new double[col];     // ������������� ����������

		}
			//������� ������� �� �����
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					in >> matrix[i][j];
	
		
		return matrix;
	}
	else {
		cout << "�� ������� ������� ���� " << endl;
	}

}



/*����������� */

Matrix::Matrix(int r, int c, int ans) {
	row = r; 
	col = c;

	matrix_array = new double* [row];    // ������ ����������
	for (int i = 0; i < row; i++) {   //
		matrix_array[i] = new double[col];     // ������������� ����������

	}

	switch (ans) {
	case 0:
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix_array[i][j] = 0;
			}
		}
		break;
	case 1:
		matrix_array = create(row, col);
		break;
	case 2:
		matrix_array = generate(row, col);
		break;
	case 3:
		matrix_array = load(row, col);
		break;
	}
}



/* �������� �������  */
void Matrix::plus(Matrix* m2, Matrix* m3) {
	
	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			m3->matrix_array[i][j] = matrix_array[i][j] + m2->matrix_array[i][j];  //��������� ������� ������

		}
	}

}

/*��������� ������� */

void Matrix::minus(Matrix* m2, Matrix* m3) {

	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			m3->matrix_array[i][j] = matrix_array[i][j] - m2->matrix_array[i][j];  //��������� ������� ������

		}
	}

}




/*��������� �������*/

void Matrix::times(Matrix* m2, Matrix* m3) {
	
	
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < m2->col; j++)
		{
			for (int k = 0; k < this->col; k++)
			{
				m3->matrix_array[i][j] += this->matrix_array[i][k] * m2->matrix_array[k][j];

			}
		}
	}

	
	for (int i = 0; i < m3->row; i++)
	{
		for (int j = 0; j < m3->col; j++)
		{
			if (abs(m3->matrix_array[i][j]) < 2.22045e-13)
				m3->matrix_array[i][j] = 0;
		}
	}
	
}


/*��������� ������� �� ������ */

void Matrix::times_scal(double scal, Matrix* m3) {
	
	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			m3->matrix_array[i][j] = matrix_array[i][j] * scal;  //��������� ������� ������

		}
	}
}


/*������� ������� �� ������ */

void Matrix::divide_scal(double scal, Matrix* m3) {
	
	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			m3->matrix_array[i][j] = matrix_array[i][j] / scal;  //��������� ������� ������

		}
	}
	
}




/* ���������� � ������� */
void Matrix::pow(int n, Matrix* m3) {
		
		this->times(this, m3);
		
		if (n > 2) {
			for (int p = 1; p < n - 1; p++) {

				m3->times(this, m3);

			}
		}
}



/*��������� ������ */

bool Matrix::areEqual(Matrix *m2) {
	
	if (row != m2->row || col != m2->col) {
		return false;
	}
	else {
		for (int i = 0; i < col; i++)
			for (int j = 0; j < row; j++)
			{
				if (matrix_array[i][j] != m2->matrix_array[i][j])
				{
					return false;
				}
			}

		return true;
	}
}

void Matrix::findNorm() {

}

/*����� ������������*/

double Matrix::findDet() {
	double Det;

	if (this->row == 2) {
		Det = this->matrix_array[0][0] * this->matrix_array[1][1] - this->matrix_array[1][0] * this->matrix_array[0][1];
		}
	else {
		
		double** temp = new double* [this->row];    // ������ ����������
		for (int i = 0; i < this->row; i++) {   //
			temp[i] = new double[this->row];     // ������������� ����������
		}

		for (int i = 0; i < this->row; i++)
			for (int j = 0; j < this->row; j++)
				temp[i][j] = this->matrix_array[i][j];

		//���������� ������� � ������������������ ����
		for (int step = 0; step < this->row - 1; step++)
			for (int row_count = step + 1; row_count < this->row; row_count++)
			{
				double coeff = -temp[row_count][step] / temp[step][step]; //����� ������
				for (int col_count = step; col_count < this->row; col_count++)
					temp[row_count][col_count] += temp[step][col_count] * coeff;
			}

		//���������� ������������ ��� ������������ ��������� ������� ���������
		Det = 1;
		for (int i = 0; i < this->row; i++)
			Det *= temp[i][i];
	}
		return Det;
}

/*���������� �������� �������*/

void Matrix::invertMatrix(Matrix* m3) {
	
			
	double det = this->findDet();

	double** complement_matrix; //������� �������������� ����������

	complement_matrix = new double* [this->row];    // ������ ����������
	for (int i = 0; i < row; i++) {   //
		complement_matrix[i] = new double[col];     // ������������� ����������
	}

	//��������� ������� �������������� ���������� �������������� �������
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			double t;

				t = (this->minorMatrix(i, j))->findDet();
					complement_matrix[i][j] = t;
					if ((i + j) % 2 == 1)
					{
						complement_matrix[i][j] *= -1;
					}


		}
	}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				m3->matrix_array[i][j] = complement_matrix[i][j];
			}
		}

		//������������� ������� �������������� ���������� � ����� �� �� ������������ ��������
		m3->transMatrix(m3);
		m3->divide_scal(det, m3);

}
	



/* ���������������� ������� */

Matrix Matrix::transMatrix(Matrix *m3) {

	for (int i = 0; i < this->col; i++)
		for (int j = 0; j < this->row; j++)
		{
			m3->matrix_array[i][j] = this->matrix_array[j][i];
		}

	return *m3;

}

/*�������� ����� �������*/


bool* Matrix::checkType() {

	Matrix* temp = new Matrix(row, col, 0);

	bool square = false; // ����������
	bool diagonal = true; // ������������
	bool empty = true; // ������� 
	bool identity = true; //���������
	bool symmetrical = false; // �������������� 
	bool upperTriangle = true; // ������� �����������
	bool lowerTriangle = true; // ������ �����������
	bool ordinary = true;

	//�������� �� ���������� �������
	if (row == col)
		square = true;

	//�������� �� ������������ �������, ���� ������� ��������� ������� ��� ������� ��������� - ������� �� �����
	if (square == true) {
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (i != j && matrix_array[i][j] != 0)
				{
					diagonal = false;
					empty = false;
					break;
				}
			}

			if (diagonal == false)
				break;
		}

	}
	//���� ������� �� ���������� - ����� ������ �����, ��� ��� �� ������������, ���������, ������- � ����������������
	else {
		diagonal = false;
		identity = false;
		upperTriangle = false;
		lowerTriangle = false;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (matrix_array[i][j] != 0)
				{
					empty = false;
					break;
				}
			}

			if (empty == false)
				break;
		}

	}
	//���� ������� ������������ - �������������� �������� �� ������� �������
	if (diagonal == true) {
		
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (i == j && matrix_array[i][j] != 0)
				{
					empty = false;
					break;
				}
			}

			if (empty == false)
				break;
		}

	}
	else {
		identity = false;
	}
	// �������� �� ��������� �������
	if (diagonal == true) {

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (i == j && matrix_array[i][j] != 1)
				{
					identity = false;
					break;
				}
			}

			if (identity == false)
				break;
		}
	}

	//�������� �� �������������� �������
	if (square) {
		this->transMatrix(temp);
		if (this->areEqual(temp)) //���� �������� � ����������������� ������� �����
			symmetrical = true;
	}
	
	// �������� �� ������ ����������� ������� 

	if (square == true && diagonal == false) {

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (j> i && matrix_array[i][j]!=0) {
					lowerTriangle = false;
					break;

				}
			}

			if(lowerTriangle == false)
				break;
		}

	}

	// �������� �� ������� ����������� ������� 

	if (square == true && diagonal==false) {

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (j < i && matrix_array[i][j] != 0) {
					upperTriangle = false;
					break;

				}
			}

			if (upperTriangle == false)
				break;
		}
	}


	if (square == true || diagonal == true || empty == true || identity == true || symmetrical == true || upperTriangle == true || lowerTriangle == true)
		ordinary = false;
	bool checkTypeArray[8] = { square, diagonal, empty, identity, symmetrical, upperTriangle, lowerTriangle, ordinary };
	bool* p = checkTypeArray;

	return p;



}