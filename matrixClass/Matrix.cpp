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
int checkFile[2];

/*������� ���������� ������� ������, ������� ���������� �������������� �� �������� ������� r-��� ������ � c-���� �������
* ������������ ��� ���������� �������� �������
*/ 


double **Matrix::minorMatrix(int r, int c, Matrix m) {
	
	int n = m.row - 1; // ����� ����� � �������� ������

	double** minor_matrix_array = new double* [n];    // ������ ����������
	for (int i = 0; i < n; i++) {   //
		minor_matrix_array[i] = new double[n];     // ������������� ����������

	}
	
	int minor_i = 0, minor_j = 0;
	
	for (int i = 0; i < m.row; i++)
	{
		if (i == r) {
			//i++;
			continue;
		}
		for (int j = 0; j < m.col; j++)
		{
			if (j == c) {
				//j++;
				continue;
			}

			minor_matrix_array[minor_i][minor_j] = m.matrix_array[i][j];
			//minor_i++;
			minor_j++;
			if (minor_j == n) {
				minor_j = 0;
				minor_i++;
			}

		}
	}
	/*	cout << "\n";

	for (int i = 0; i < n; i++) {
		{
			cout << "\n";
			for (int j = 0; j < n; j++) {
				cout << minor_matrix_array[i][j] << " ";
			}
		}
	}

	cout << "\n";

	*/


	return minor_matrix_array;


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
		cout << "������� ������� ��������� � ����� \'output.txt\'" << endl;
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
/*�������, ���������� ����������� �������
��� �������� ������ � ����� ������� m � �������� �� ���� ������, ����������� ������� �������*/

void Matrix::printMatrix(Matrix m) {


	for (int i = 0; i < m.row; i++) {
		{
			cout << "\n";
			for (int j = 0; j < m.col; j++) {
				
					cout << m.matrix_array[i][j] << " ";
				
			}
		}
	}
}

/*������� ��� ������ �������� �������. 
����� �������� ����� �������, � ����� �������� ���������� ��������, - �������������� ��� ��������.
���� �������� ��������, ������ �� ��������. 
��� ������ �������������� - ������ ���� ������� m � ������������ ������ matrix_array*/

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

/*������� ��� ������� ����� ������� � ����������
������ ������� - � ������� ���������� ����� � �������� �������*/

double** Matrix::create()

{
	cout << "\n������� ���������� ����� � �������� ����� ����� �������: ";

	cin >> row;
	cin >> col;

	this->row = row;
	this->col = col;

	double** matrix;

	// ��������
	matrix = new double* [row];    // ������ ����������
	for (int i = 0; i < row; i++) {   //
		matrix[i] = new double[col];     // ������������� ����������

	}

	for (int i = 0; i < row; i++) {
		cout << "������ " << i + 1 << " ������: ";
		for (int j = 0; j < col; j++) {
			cin >> matrix[i][j];
		}
	}

	return matrix;

}

/*������� ��� ������� ����� ������� � ����������
������ ������� - ���� ���������� ����� � �������� ��� ���������� ���������� ����������*/

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

/*������� ��� ���������� �������������� �������
������ ������� - � ������� ���������� ����� � �������� �������*/

double** Matrix::generate() {

	cout << "\n������� ���������� ����� � �������� ����� ����� �������: ";

	cin >> row;
	cin >> col;

	this->row = row;
	this->col = col;

	double** matrix;

	// ��������
	matrix = new double* [row];    // ������ ����������
	for (int i = 0; i < row; i++) {   //
		matrix[i] = new double[col];     // ������������� ����������

	}

	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			matrix[i][j] = 1 + rand() % 9;  //��������� ������� ������

		}
	}

	return matrix;


}

/*������� ��� ���������� �������������� �������
������ ������� - ���� ���������� ����� � �������� ��� ���������� ���������� ����������*/

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

/*������� ��� ���������� ������� �� �����
����� ���������� ����� ����� � ��������, 
������� ���������� ����� � ����� � ���������� �������� �� ����� ������. 

��������� - ����� ������� ������� ����� �� ������ �������, � ����� ������ ������ ������� ������� ���.

*/

double** Matrix::load() {
	cout << "\n�������� ������� �� �����..." << endl;


	//������� �������� ����� � ��������� ��� � ������
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

		checkFile[1]=col = count_space + 1; //����� � ����� ������
		checkFile[0] = row = count / col; //����� �����

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



/*����������� 1 
������������� ��� �������� ���������� �������. 
����� ������ ���������� ��������������� ������.
���� ����������� ��� ������ �� ���� ������� 1) (�������� ����� �������), ��������� ��������� � ���������� �������.
*/

Matrix::Matrix() {
	
	cout << "��� �� ������ ��������� �������: \n1 - �������\n2 - ������������� �������������\n3 - ��������� �� �����\n" << endl;
	int ans;
	cout << "��� �����: ";
	cin >> ans;
	cout << "\n";
	switch (ans) {
	case 1:
		matrix_array = create();
		break;
	case 2:
		matrix_array = generate();
		break;
	case 3:
		matrix_array = load();
		break;
	}
	if (v == 1)
	{
		cout << "\n���� ����� �������: \n" << endl;
		printMatrix(*this);
	}
}

/*����������� 2
"�����" �������� ����� �������� � ��������� ������ ����� � �������� 

������������ ��� �������� �������������� ������ (��� ������ �����, ������������ � ��).

������ ����� ������� ����� ����������� � ��������������� ������.

*/
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

/*����������� �����������

�������� ��� ���� ���������� �������. 
������ ������������ ��� ��� ���������� � �������, �� ����������

*/

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

/*�������� ������� (���������� �� ����)

��������� ����� ������ m2, ��� �������� ���������� "����� �����������". 
����� �������� � ����� ����� ������� ��������� � ���������.

����� ��� ��������� ������ ������� �� ����� ����������� �������, ���������� ��� ��������� �� �����.
���� ������� �� ����� �� �������� ��� ��������, ��������� ������ ������� ������ ������.

����� "����� �������������" ��������� �������������� �������. ����������� ������ �����.

� ����� ����� �������, � ����� �������� ���������� �������� ������ - �������� ��� ��������������.

*/

void Matrix::plus() {
	cout << "���������� ������� ����� ������ ��� �������� � ������ ��������.\n������, ��� ���������� ����� � �������� ������ ������ ���������.\n" << endl;
	Matrix* m2 = new Matrix(row, col);
	m2->load();
	if(checkFile[0]!=row || checkFile[1]!=col)
	{
		cout << "\n\n��� �� ������ ��������� �������: \n1 - �������\n2 - ������������� �������������\n�������� �� ����� ���������� (������� �� ������������� ��������)\n" << endl;
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
		}

	}
	else {
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
			m2->matrix_array = load();
			break;
		}
	}
	


	cout << "\n����:\n";
	cout << "\n������ ���������: \n";
	printMatrix(*this);
	cout << "\n\n������ ���������: \n";
	printMatrix(*m2);

	Matrix* m3 = new Matrix(row, col);
	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			m3->matrix_array[i][j] = this->matrix_array[i][j] + m2->matrix_array[i][j];  //��������� ������� ������

		}
	}
	cout << "\n\n�����: \n";
	printMatrix(*m3);
	chooseMatrix(*m3);

}

/*��������� ������� (���������� �� ����)

������ �������� �� ���������

*/
void Matrix::minus() {
	cout << "���������� ������� ����� ������ ��� �������� � ������ ��������.\n������, ��� ���������� ����� � �������� ������ ������ ���������.\n" << endl;
	Matrix* m2 = new Matrix(row, col);
	m2->load();
	if (checkFile[0] != row || checkFile[1] != col)
	{
		cout << "\n\n��� �� ������ ��������� �������: \n1 - �������\n2 - ������������� �������������\n�������� �� ����� ���������� (������� �� ������������� ��������)\n" << endl;
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
		}

	}
	else {
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
			m2->matrix_array = load();
			break;
		}
	}


	cout << "\n����:\n";
	cout << "\n�����������: \n";
	printMatrix(*this);
	cout << "\n\n����������: \n";
	printMatrix(*m2);

	Matrix* m3 = new Matrix(row, col);
	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			m3->matrix_array[i][j] = this->matrix_array[i][j] - m2->matrix_array[i][j];  //��������� ������� ������

		}
	}

	cout << "\n\n��������: \n";
	printMatrix(*m3);
	chooseMatrix(*m3);
}

/*��������� ������� (���������� �� ����)

��� ���������, ���������� ����� ����� ������� ������ ��������� � ����������� �������� ��������. 
������� ��������� ����������� ������ ���������� �������� ������ �������.

��������� ����� ������ m2, ��� �������� ���������� "����� �����������".

����� ��� ��������� ������ ������� �� ����� ����������� �������, ���������� ��� ��������� �� �����.
���� ������� �� ����� �� �������� ��� ��������, ��������� ������ ������� ������ ������.

����� "����� �������������" ��������� �������������� �������. ����������� ������ �����.

� ����� ����� �������, � ����� �������� ���������� �������� ������ - �������� ��� ��������������.

*/

void Matrix::times() {
	cout << "\n���������� ������� ����� ������ ��� �������� � ������ ��������.\n������, ��� ���������� ����� ����� ������� ������ ��������� � ����������� �������� ��������.\n" << endl;
	
	cout << "������� ���������� �������� ������ �������: ";
	int ans;
	cin >> ans;

	Matrix* m2;
	m2 = new Matrix(col, ans);

	m2->load();

	m2 = new Matrix(col, ans);
	if (checkFile[0] != col)
	{
		cout << "\n\n��� �� ������ ��������� �������: \n1 - �������\n2 - ������������� �������������\n�������� �� ����� ���������� (������� �� ������������� ��������)\n" << endl;
		int ans;
		cout << "��� �����: ";
		cin >> ans;
		cout << "\n";

		switch (ans) {
		case 1:
			m2->matrix_array = create(m2->row, m2->col);
			break;
		case 2:
			m2->matrix_array = generate(m2->row, m2->col);
			break;
		}

	}
	else {
		cout << "\n\n��� �� ������ ��������� �������: \n1 - �������\n2 - ������������� �������������\n3 - ��������� �� �����\n" << endl;
		int ans;
		cout << "��� �����: ";
		cin >> ans;
		cout << "\n";

		switch (ans) {
		case 1:
			m2->matrix_array = create(m2->row, m2->col);
			break;
		case 2:
			m2->matrix_array = generate(m2->row, m2->col);
			break;
		case 3:
			m2->matrix_array = load();
			break;
		}
	}

		
	Matrix* m3 = new Matrix(this->row, m2->col);
	cout << "\n";
	cout << "\n����\n";
	cout << "\n������ ���������: \n";
	printMatrix(*this);
	cout << "\n\n������ ���������: \n";
	printMatrix(*m2);
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

	
	for (int i = 0; i < m3->row; i++)
	{
		for (int j = 0; j < m3->col; j++)
		{
			if (abs(m3->matrix_array[i][j]) < 2.22045e-13)
				m3->matrix_array[i][j] = 0;
		}
	}

	cout << "\n\n������������: \n";
	printMatrix(*m3);
	chooseMatrix(*m3);
}

/*

��������� ������� 2

��������������� ������� ��� ������ ���������� � �������

�������� ������ �� ������ ������� m2 � ���������� �������������� ������ temp->matrix_array

*/
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
	for (int i = 0; i < temp->row; i++)
	{
		for (int j = 0; j < temp->col; j++)
		{
			if (abs(temp->matrix_array[i][j]) < 2.22045e-13)
				temp->matrix_array[i][j] = 0;
		}
	}

	return temp->matrix_array;

}

/*��������� ������� �� ������ (���������� �� ����)

����������� �������� ������� �� ��������� � ���������� �����. 
����� ������ �������� �� ������������ �������.

*/
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
	printMatrix(*this);
	cout << "\n�������������� �������: \n";
	printMatrix(*m3);
	chooseMatrix(*m3);



}
/*��������������� ������� ��������� �� ������
������������ ��� ���������� �������� �������*/

Matrix Matrix::times_scal(double scal) {
	
	Matrix* m3 = new Matrix(row, col);
	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			m3->matrix_array[i][j] = matrix_array[i][j] * scal;  //��������� ������� ������

		}
	}

	return *m3;
	
}

/*������� ������� �� ������

����������� ����� ������� �� ��������� � ���������� �����.
���� �������� �� ������� �� ����.

*/

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
	printMatrix(*this);
	cout << "\n�������������� �������: \n";
	printMatrix(*m3);
	chooseMatrix(*m3);

}

/*��� ���������� �������� �������*/

void Matrix::divide_scal(double scal) {
	
	//Matrix* m3 = new Matrix(row, col);

	for (int i = 0; i < row; i++)   //������ �������
	{
		for (int j = 0; j < col; j++)   //������� �������
		{
			matrix_array[i][j] /= scal;  //��������� ������� ������

		}
	}
	

}

/*���������� � �������

���������� � ������� �������� ������ ��� ���������� ������ 
-> ���� �������� �� ��� ������� � ������������ � ����.

���� �������� �� �������� ����� - ��� ������ ���� ����� � �������������.

���� ������� �������������� ������ m3. ��������� ��� ������������� ������� �� ����.
���� ������� = 2, ���������� ������ m3/
���� ������� ������ 2, �������� ��������������� ������� ��������� � ����� � ��������� �������������� �������.

*/
void Matrix::pow() {
	if (row != col) {

		cout << "���������� � ������� �������� ������ ��� ���������� ������\n�������� ������ �������� ��� �������� ����� �������\n";
	}
	else {

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
		printMatrix(*this);
		cout << "\n\n�������������� �������: \n";
		printMatrix(*m3);
		chooseMatrix(*m3);

	}
}

/*��������� ������ 1 (��� ������ �� ����)

������� ���������� ������ � ����� ��������, ������� ��������� ������ �������������. 

���� ����� �������� � ����� ������ �� �����, ������ �����, ��� ������� ����� �� �����.
����� ���������� �� ����������� � ������� �� ������� �����, ��� ������ ������ �������� ��������.


*/

void Matrix::areEqual() {
	cout << "� ����� �������� �� ������ �������� �������� �������?\n";
	Matrix* m2 = new Matrix();
	cout << "\n���������� � ��������: " << endl;
	printMatrix(*m2);
	if (row != m2->row || col != m2->col) {
		cout << "\n\n������� �� ����� \n" << endl;
		
	}
	else {
		for (int i = 0; i < col; i++)
			for (int j = 0; j < row; j++)
			{
				if (matrix_array[i][j] != m2->matrix_array[i][j])
				{
					cout << "\n\n������� �� ����� \n" << endl;
					return;
				}
			}

		cout << "\n\n������� ����� \n" << endl;
		
	}
}

/*��������� ������ 2
���������������, "����� �������"

����� ��� �� ���������� ��� �������, �� ������ �� ������� �� �����, � ������ ���������� ������� ��������.
������������ ��� ����������� ���� �������.

*/

bool Matrix::areEqual(Matrix m2) {
	
	if (row != m2.row || col != m2.col) {
		return false;
	}
	else {
		for (int i = 0; i < col; i++)
			for (int j = 0; j < row; j++)
			{
				if (matrix_array[i][j] != m2.matrix_array[i][j])
				{
					return false;
				}
			}

		return true;
	}
}

void Matrix::findNorm() {

}

double Matrix::findDet() {
	if (row != col) {

		cout << "����� ������������ �������� ������ ��� ���������� ������\n�������� ������ �������� ��� �������� ����� �������\n";
	}
	else {

		Matrix* m2 = new Matrix(*this);
		//printMatrix(*m2);
		//���������� ������� � ������������������ ����
		for (int step = 0; step < m2->row - 1; step++)
			for (int row_count = step + 1; row_count < m2->row; row_count++)
			{
				if (m2->matrix_array[step][step] != 0)
				{
					double coeff = -m2->matrix_array[row_count][step] / m2->matrix_array[step][step]; //����� ������

					for (int col_count = step; col_count < m2->row; col_count++)
						m2->matrix_array[row_count][col_count] += m2->matrix_array[step][col_count] * coeff;
				}
			}
		//cout << "\n";
		
		//printMatrix(*m2);

		//cout << "\n";
		//���������� ������������ ��� ������������ ��������� ������� ���������
		double Det = 1;
		for (int i = 0; i < m2->row; i++)
			Det *= m2->matrix_array[i][i];

		cout << "����������� = " << Det << endl;
		return Det;


	}
}

double Matrix::findDet(int n, double** array) {
	double Det;

	if (n == 2) {
		Det = array[0][0] * array[1][1] - array[1][0] * array[0][1];
		}
	else {
		
		double** temp = new double* [n];    // ������ ����������
		for (int i = 0; i < n; i++) {   //
			temp[i] = new double[n];     // ������������� ����������
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				temp[i][j] = array[i][j];

		//���������� ������� � ������������������ ����
		for (int step = 0; step < n - 1; step++)
			for (int row_count = step + 1; row_count < n; row_count++)
			{
				double coeff = -temp[row_count][step] / temp[step][step]; //����� ������
				for (int col_count = step; col_count < n; col_count++)
					temp[row_count][col_count] += temp[step][col_count] * coeff;
			}

		//���������� ������������ ��� ������������ ��������� ������� ���������
		Det = 1;
		for (int i = 0; i < n; i++)
			Det *= temp[i][i];
	}
		return Det;
}





void Matrix::invertMatrix() {
	if (row != col) {

		cout << "����� �������� ������� �������� ������ ��� ���������� ������\n�������� ������ �������� ��� �������� ����� �������\n";
	}
	else {

		if (findDet(row, matrix_array) == 0)
		{
			cout << "������� �����������, ������������ ����� ����.\n�������� ������� �� ����������\n�������� ������ �������� ��� �������� ����� �������\n";
		}
		else {
			Matrix* m3 = new Matrix(row, col);

			double det = findDet(row, this->matrix_array);

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
					t = findDet(row - 1, minorMatrix(i, j, *this));
					complement_matrix[i][j] = t;
					if ((i + j) % 2 == 1)
					{
						complement_matrix[i][j] *= -1;
					}


				}
			}

			//for (int i = 0; i < row; i++)
			//{
			//	cout << "\n";
			//	for (int j = 0; j < col; j++)
			//	{
			//		cout << complement_matrix[i][j] << " ";
			//	}
			//}

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					m3->matrix_array[i][j] = complement_matrix[i][j];
				}
			}

			//������������� ������� �������������� ���������� � ����� �� �� ������������ ��������
			m3 = &m3->transMatrix(*m3);
			m3->divide_scal(det);
		
			
			//�������� �� ��������� �������
			//m3->matrix_array = m3->times(this);
			printMatrix(*m3);

			chooseMatrix(*m3);

		}

	}
		
	
}

/*���������������� ������� 1 (��� ������ �� ����)

� ������ ����� ������� ������������ ������� ��������.

*/

Matrix Matrix::transMatrix() {

	Matrix* m3 = new Matrix(col, row);

	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
		{
			m3->matrix_array[i][j] = matrix_array[j][i];
		}
	cout << "\n\n�������� �������: " << endl;
	printMatrix(*this);
	cout << "\n\n����������������� �������: " << endl;
	printMatrix(*m3);

	chooseMatrix(*m3);

	return *m3;
	 
}

/*���������������� ������� 2 

� ������ ����� ������� ������������ ������� ��������.

������ �� ��������� �� �����, ������� ���������� ��������� �� ��������� �������.
������������ ��� ����������� ���� �������.

*/

Matrix Matrix::transMatrix(Matrix m) {

	Matrix* m3 = new Matrix(m.col, m.row);

	for (int i = 0; i < m.col; i++)
		for (int j = 0; j < m.row; j++)
		{
			m3->matrix_array[i][j] = m.matrix_array[j][i];
		}

	return *m3;

}

/*

�������� ����� �������
(����������� ������ �������)

*/


void Matrix::checkType() {

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

	if (this->areEqual(this->transMatrix(*this))) //���� �������� � ����������������� ������� �����
		symmetrical = true;
	
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

	cout << "\n\n��� �������:\n\n";
	if (square) cout << "����������" << endl;
	if (diagonal) cout << "������������" << endl;
	if (empty) cout << "�������" << endl;
	if (identity) cout << "���������" << endl;
	if (symmetrical) cout << "��������������" << endl;
	if (upperTriangle) cout << "������� �����������" << endl;
	if (lowerTriangle) cout << "������ �����������" << endl;
	if (ordinary) cout << "�� ����������� �� � ������ �� ������ �����" << endl;

}