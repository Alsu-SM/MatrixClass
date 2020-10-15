#include <iostream>
#include<locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Matrix.h"

using namespace std;
int v = 0;


void printMatrix(int r, int c, double** matrix) {


	for (int i = 0; i < r; i++) {
		{
			cout << "\n";
			for (int j = 0; j < c; j++) {
				cout << matrix[i][j] << " ";
			}
		}
	}
}

double** load(int r, int c) {
	cout << "\n�������� ������� �� �����..." << endl;

	double** matrix;

	// ��������
	matrix = new double* [r];    // ������ ����������
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // ������������� ����������

	}

	//������� �������� ����� � ��������� ��� � ������
	ifstream in("input.txt");

	if (in.is_open())
	{
		//���� �������� ����� ������ �������
		//������� ������� �� �����
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				in >> matrix[i][j];
	}


	return matrix;

}

double** generate(int r, int c) {

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

int menu()
{

	cout << "\n��� �� ������ �������?\n" << endl;
	cout << "\n1 - �������� ����� �������\n\n2 - ��������\n3 - ���������\n4 - ��������� �� �������\n5 - ��������� �� ������\n6 - ������� �� ������\n7 - ���������� � �������\n8 - ���������� ������������ \n9 - ����������������\n10 - ���������� �������� �������\n" << endl;

	for (;;)
	{
		cout << "\n��� �����: ";
		cin >> v;
		cout << "\n";

		if (v <= 0 || v > 10) {
			cout << "\n����������, ������� ����� �� 1 �� 10.\n\n" << endl;
			continue;
		}

		return v;
	}
}


double** create(int r, int c)

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

//������

Matrix::Matrix() {
	cout << "\n������� ���������� ����� � �������� ����� ����� �������: ";

	cin >> row;
	cin >> col;
	cout << "\n\n��� �� ������ ��������� �������: \n1 - �������\n2 - ������������� �������������\n3 - ��������� �� �����\n" << endl;
	int ans;
	cout << "��� �����: ";
	cin >> ans;
	cout << "\n";
	switch (ans) {
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
	if (v == 1)
	{
		cout << "\n���� ����� �������: \n" << endl;
		printMatrix(row, col, matrix_array);
	}
}

Matrix::Matrix(int r, int c) {
	row = r;
	col = c;
	double** matrix;

	// ��������
	matrix = new double* [r];    // ������ ����������
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // ������������� ����������

	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			matrix[i][j] = 0;
		}
	}
	matrix_array = matrix;
}


//����������� �����������:

Matrix::Matrix(const Matrix& m) {
	row = m.row;
	col = m.col;

	matrix_array = new double* [row];    // ������ ����������
	for (int i = 0; i < row; i++) {   //
		matrix_array[i] = new double[col];     // ������������� ����������
	}

	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			matrix_array[i][j] = m.matrix_array[i][j];

		}
	}

}

void Matrix::plus() {
	cout << "���������� ������� ����� ������ ��� �������� � ������ ��������.\n������, ��� ���������� ����� � �������� ������ ������ ���������.\n" << endl;
	Matrix* m2 = new Matrix(row, col);
	cout << "\n\n��� �� ������ ��������� �������: \n1 - �������\n2 - ������������� �������������\n3 - ��������� �� �����\n" << endl;
	int ans;
	cout << "��� �����: ";
	cin >> ans;
	cout << "\n";

	switch (ans) {
	case 1:
		m2->matrix_array = create(row, col);
		break;
	case 2:
		m2->matrix_array = generate(row, col);
		break;
	case 3:
		m2->matrix_array = load(row, col);
		break;
	}


	cout << "\n����:\n";
	cout << "\n������ ���������: \n";
	printMatrix(row, col, matrix_array);
	cout << "\n\n������ ���������: \n";
	printMatrix(row, col, m2->matrix_array);

	Matrix* m3 = new Matrix(row, col);
	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			m3->matrix_array[i][j] = this->matrix_array[i][j] + m2->matrix_array[i][j];  //��������� ������� ������

		}
	}
	cout << "\n\n�����: \n";
	printMatrix(row, col, m3->matrix_array);
	chooseMatrix(*m3);

}

void Matrix::minus() {
	cout << "\n���������� ������� ����� ������ ��� �������� � ������ ��������.\n������, ��� ���������� ����� � �������� ������ ������ ���������.\n" << endl;
	Matrix* m2 = new Matrix(row, col);
	cout << "\n\n��� �� ������ ��������� �������: \n1 - �������\n2 - ������������� �������������\n3 - ��������� �� �����\n" << endl;
	int ans;
	cout << "��� �����: ";
	cin >> ans;
	cout << "\n";

	switch (ans) {
	case 1:
		m2->matrix_array = create(row, col);
		break;
	case 2:
		m2->matrix_array = generate(row, col);
		break;
	case 3:
		m2->matrix_array = load(row, col);
		break;
	}

	cout << "\n����:\n";
	cout << "\n�����������: \n";
	printMatrix(row, col, matrix_array);
	cout << "\n\n����������: \n";
	printMatrix(row, col, m2->matrix_array);

	Matrix* m3 = new Matrix(row, col);
	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			m3->matrix_array[i][j] = this->matrix_array[i][j] - m2->matrix_array[i][j];  //��������� ������� ������

		}
	}

	cout << "\n\n��������: \n";
	printMatrix(row, col, m3->matrix_array);
	chooseMatrix(*m3);
}

void Matrix::times() {
	cout << "\n���������� ������� ����� ������ ��� �������� � ������ ��������.\n������, ��� ���������� ����� ����� ������� ������ ��������� � ����������� �������� ��������.\n" << endl;
	
	cout << "������� ���������� �������� ������ �������: ";
	int ans;
	cin >> ans;

	Matrix* m2 = new Matrix(col, ans);
	cout << "\n\n��� �� ������ ��������� �������: \n1 - �������\n2 - ������������� �������������\n3 - ��������� �� �����\n" << endl;
	cout << "��� �����: ";
	cin >> ans;
	cout << "\n";

	switch (ans) {
	case 1:
		m2->matrix_array = create(row, col);
		break;
	case 2:
		m2->matrix_array = generate(row, col);
		break;
	case 3:
		m2->matrix_array = load(row, col);
		break;
	}
	Matrix* m3 = new Matrix(this->row, m2->col);
	cout << "\n";
	cout << "\n����\n";
	cout << "\n������ ���������: \n";
	printMatrix(row, col, matrix_array);
	cout << "\n\n������ ���������: \n";
	printMatrix(m2->row, m2->col, m2->matrix_array);
	for (int i = 0; i < this->row; i++)
	{

		cout << "\n";
		for (int j = 0; j < m2->col; j++)
		{

			m3->matrix_array[i][j] = 0;
			for (int k = 0; k < this->col; k++)
			{
				m3->matrix_array[i][j] += this->matrix_array[i][k] * m2->matrix_array[k][j];

			}
			//cout << m3->matrix_array[i][j] << " ";
		}
	}

	cout << "\n\n������������: \n";
	printMatrix(m3->row, m3->col, m3->matrix_array);
	chooseMatrix(*m3);
}

double** Matrix::times(Matrix* m2) {

	Matrix* temp = new Matrix(row, col);

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < m2->col; j++)
		{

			for (int k = 0; k < this->col; k++)
			{
				temp->matrix_array[i][j] += this->matrix_array[i][k] * m2->matrix_array[k][j];

			}

		}
	}

	return temp->matrix_array;

}

void Matrix::times_scal() {
	double scal;
	cout << "\n��� ��������� ������� �� ������, ������� �����: ";
	cin >> scal;
	cout << "\n\n";
	Matrix* m3 = new Matrix(row, col);
	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			m3->matrix_array[i][j] = matrix_array[i][j] * scal;  //��������� ������� ������

		}
	}
	cout << "\n����\n";
	cout << "\n�������� �������: \n";
	printMatrix(row, col, matrix_array);
	cout << "\n�������������� �������: \n";
	printMatrix(row, col, m3->matrix_array);
	chooseMatrix(*m3);



}

void Matrix::divide_scal() {
	double scal;
	cout << "\n��� ������� ������� �� ������, ������� �����: ";
	cin >> scal;

	while (scal == 0) {
		cout << "\n������� �� ���� ���������, ������� ����� �����: ";
		cin >> scal;
	}

	Matrix* m3 = new Matrix(row, col);
	cout << "\n\n";
	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			m3->matrix_array[i][j] = matrix_array[i][j] / scal;  //��������� ������� ������

		}
	}
	cout << "\n����\n";
	cout << "\n�������� �������: \n";
	printMatrix(row, col, matrix_array);
	cout << "\n�������������� �������: \n";
	printMatrix(row, col, m3->matrix_array);
	chooseMatrix(*m3);

}

void Matrix::pow() {
	int pow = -1;
	cout << "\n��� ���������� ������� � ������� ������� ����� ������������� �����: ";
	cin >> pow;

	while (pow <= 0) {
		cout << "\n������� ����� ������������� �����: ";
		cin >> pow;
	}
	Matrix* m3 = new Matrix(row, col);
	m3->matrix_array = this->times(this);
	//Matrix* m3 = this;
	//Matrix* temp = new Matrix(row, col);
	if (pow > 2) {
		for (int p = 1; p < pow - 1; p++) {

			m3->matrix_array = m3->times(this);

		}
	}


	cout << "\n����\n";
	cout << "\n�������� �������: \n";
	printMatrix(row, col, matrix_array);
	cout << "\n\n�������������� �������: \n";
	printMatrix(row, col, m3->matrix_array);
	chooseMatrix(*m3);

}



void Matrix::chooseMatrix(Matrix m3) {
	cout << "\n\n� ����� �������� ���������� ��������?\n1 - ��������\n2 - ��������������\n" << endl;
	int ans;
	cin >> ans;

	if (ans == 2) {
		row = m3.row;
		col = m3.col;
		delete[] matrix_array;

		matrix_array = new double* [row];    // ������ ����������
		for (int i = 0; i < row; i++) {   //
			matrix_array[i] = new double[col];     // ������������� ����������

		}

		for (int i = 0; i < row; i++)   //������ �������
		{
			for (int j = 0; j < col; j++)   //������� �������
			{
				matrix_array[i][j] = m3.matrix_array[i][j];  //��������� ������� ������

			}
		}

	}
	cout << "\n������!\n" << endl;
}