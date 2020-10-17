#include <iostream>
#include<locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Matrix.h"

using namespace std;
int v = 0;
bool matrixExists = false;

/*�������, ����������� ����. 
��� ������ ������ ���������� ������� ������� � �������� �����������.
��� ����������� ���������� �������� ������ ��������, � �.�. ����� �� ��������� ��� ����� ����� �������*/

int menu()
{
	if (matrixExists) {
		cout << "\n\n��� �� ������ �������?\n" << endl;
		cout << "\n1 - �������� ����� �������\n\n2 - ��������\n3 - ���������\n4 - ��������� �� �������\n5 - ��������� �� ������\n6 - ������� �� ������\n7 - ���������� � �������\n8 - ��������� � ������ �������� (�������� �� ���������)\n 9 - �������� ���� ������� \n10 - ����������������\n11 - ���������� �������� �������\n12 - ���������� ������������\n\n13 - ��������� ������� � ����\n\n0 - �����" << endl;

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

	col = count_space + 1; //����� � ����� ������
	row = count / col; //����� �����

	double** matrix;

	// ��������
	matrix = new double* [row];    // ������ ����������
	for (int i = 0; i < row; i++) {   //
		matrix[i] = new double[col];     // ������������� ����������

	}

	if (in.is_open())
	{
		//���� �������� ����� ������ �������
		//������� ������� �� �����
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				in >> matrix[i][j];
	}


	return matrix;

}


/*����������� 1 
������������� ��� �������� ���������� �������. 
����� ������ ���������� ��������������� ������.
���� ����������� ��� ������ �� ���� ������� 1) (�������� ����� �������), ��������� ��������� � ���������� �������.
*/

Matrix::Matrix() {
	
	cout << "\n\n��� �� ������ ��������� �������: \n1 - �������\n2 - ������������� �������������\n3 - ��������� �� �����\n" << endl;
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

/*�������� �������

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

/*��������� �������

������ �������� �� ���������

*/
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
		m2->matrix_array = load();
		break;
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

/*��������� �������

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

	Matrix* m2 = new Matrix(col, ans);
	cout << "\n\n��� �� ������ ��������� �������: \n1 - �������\n2 - ������������� �������������\n3 - ��������� �� �����\n" << endl;

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

	return temp->matrix_array;

}

/*��������� ������� �� ������

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

/*������� ������� �� ������

����������� ����� ������� �� ��������� � ���������� �����.
���� �������� �� ������� �� ����.

����� ������ �������� �� ������������ �������.

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
	if (row != m2->row || col != m2->col) {
		cout << "\n������� �� ����� \n" << endl;
		
	}
	else {
		for (int i = 0; i < col; i++)
			for (int j = 0; j < row; j++)
			{
				if (matrix_array[i][j] != m2->matrix_array[i][j])
				{
					cout << "\n������� �� ����� \n" << endl;
					return;
				}
			}

		cout << "\n������� ����� \n" << endl;
		
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

void Matrix::findDet() {
	if (row != col) {

		cout << "����� ������������ �������� ������ ��� ���������� ������\n�������� ������ �������� ��� �������� ����� �������\n";
	}
	else {


	}
}



void Matrix::invertMatrix() {
	if (row != col) {

		cout << "����� ������������ �������� ������ ��� ���������� ������\n�������� ������ �������� ��� �������� ����� �������\n";
	}
	else {
		Matrix* m3 = new Matrix(row, col);



		// ��������
		double** matrix;

		// ��������
		matrix = new double* [row];    // ������ ����������
		for (int i = 0; i < row; i++) {   //
			matrix[i] = new double[col];     // ������������� ����������

		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (i == j)
					matrix[i][j] = 1;
				else
					matrix[i][j] = 0;
			}
		}

		m3->matrix_array = matrix;


		printMatrix(*m3);
		// converting matrix to e

		
		for (int i = 0; i < row; i++)

		{

			// normalizing row (making first element =1)

			long double temp = matrix_array[i][0];

			for (int j = row - 1; j >= 0; j--)

			{

				m3->matrix_array[i][j] /= temp;

				matrix_array[i][j] /= temp;

			}

			// excluding i-th element from each row except i-th one

			for (int j = 0; j < row; j++)

				if (j != i)

				{

					temp = matrix_array[i][j];

					for (int k = row - 1; k >= 0; k--)

					{

						m3->matrix_array[j][k] -= m3->matrix_array[i][k] * temp;

						matrix_array[j][k] -= matrix_array[i][k] * temp;

					}

				}

		}

		cout << "\n";
		printMatrix(*m3);
		cout << "\n";
		printMatrix(*this);


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