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
	cout << "\nЗагружаю матрицу из файла..." << endl;

	double** matrix;

	// создание
	matrix = new double* [r];    // массив указателей
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // инициализация указателей

	}

	//Создаем файловый поток и связываем его с файлом
	ifstream in("input.txt");

	if (in.is_open())
	{
		//Если открытие файла прошло успешно
		//Считаем матрицу из файла
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				in >> matrix[i][j];
	}


	return matrix;

}

double** generate(int r, int c) {

	double** matrix;

	// создание
	matrix = new double* [r];    // массив указателей
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // инициализация указателей

	}

	for (int i = 0; i < r; i++)   //строки массива
	{
		for (int j = 0; j < c; j++)   //столбцы массива
		{
			matrix[i][j] = 1 + rand() % 9;  //заполняем текущую ячейку

		}
	}

	return matrix;


}

int menu()
{

	cout << "\n\n\nЧто вы хотите сделать?\n" << endl;
	cout << "\n1 - Добавить новую матрицу\n\n2 - Сложение\n3 - Вычитание\n4 - Умножение на матрицу\n5 - Умножение на скаляр\n6 - Деление на скаляр\n7 - Возведение в степень\n8 - сравнение с другой матрицей (проверка на равенство)\n 9 - Вычисление определителя \n10 - Транспонирование\n11 - Вычисление обратной матрицы\n" << endl;

	for (;;)
	{
		cout << "\nВаш выбор: ";
		cin >> v;
		cout << "\n";

		if (v <= 0 || v > 10) {
			cout << "\nПожалуйста, введите числа от 1 до 10.\n\n" << endl;
			continue;
		}

		return v;
	}
}


double** create(int r, int c)

{
	double** matrix;

	// создание
	matrix = new double* [r];    // массив указателей
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // инициализация указателей

	}

	for (int i = 0; i < r; i++) {
		cout << "Вводим " << i + 1 << " строку: ";
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}



	return matrix;

}

//методы

Matrix::Matrix() {
	cout << "\nВведите количество строк и столбцов вашей новой матрицы: ";

	cin >> row;
	cin >> col;
	cout << "\n\nКак вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\n3 - загрузить из файла\n" << endl;
	int ans;
	cout << "Ваш выбор: ";
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
		cout << "\nВаша новая матрица: \n" << endl;
		printMatrix(row, col, matrix_array);
	}
}

Matrix::Matrix(int r, int c) {
	row = r;
	col = c;
	double** matrix;

	// создание
	matrix = new double* [r];    // массив указателей
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // инициализация указателей

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


//конструктор копирования:

Matrix::Matrix(const Matrix& m) {
	row = m.row;
	col = m.col;

	matrix_array = new double* [row];    // массив указателей
	for (int i = 0; i < row; i++) {   //
		matrix_array[i] = new double[col];     // инициализация указателей
	}

	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			matrix_array[i][j] = m.matrix_array[i][j];

		}
	}

}

void Matrix::plus() {
	cout << "Необходимо создать новый объект для действий с другой матрицей.\nУчтите, что количество строк и столбцов матриц должны совпадать.\n" << endl;
	Matrix* m2 = new Matrix(row, col);
	cout << "\n\nКак вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\n3 - загрузить из файла\n" << endl;
	int ans;
	cout << "Ваш выбор: ";
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


	cout << "\nИтак:\n";
	cout << "\nПервое слагаемое: \n";
	printMatrix(row, col, matrix_array);
	cout << "\n\nВторое слагаемое: \n";
	printMatrix(row, col, m2->matrix_array);

	Matrix* m3 = new Matrix(row, col);
	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			m3->matrix_array[i][j] = this->matrix_array[i][j] + m2->matrix_array[i][j];  //заполняем текущую ячейку

		}
	}
	cout << "\n\nСумма: \n";
	printMatrix(row, col, m3->matrix_array);
	chooseMatrix(*m3);

}

void Matrix::minus() {
	cout << "\nНеобходимо создать новый объект для действий с другой матрицей.\nУчтите, что количество строк и столбцов матриц должны совпадать.\n" << endl;
	Matrix* m2 = new Matrix(row, col);
	cout << "\n\nКак вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\n3 - загрузить из файла\n" << endl;
	int ans;
	cout << "Ваш выбор: ";
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

	cout << "\nИтак:\n";
	cout << "\nУменьшаемое: \n";
	printMatrix(row, col, matrix_array);
	cout << "\n\nВычитаемое: \n";
	printMatrix(row, col, m2->matrix_array);

	Matrix* m3 = new Matrix(row, col);
	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			m3->matrix_array[i][j] = this->matrix_array[i][j] - m2->matrix_array[i][j];  //заполняем текущую ячейку

		}
	}

	cout << "\n\nРазность: \n";
	printMatrix(row, col, m3->matrix_array);
	chooseMatrix(*m3);
}

void Matrix::times() {
	cout << "\nНеобходимо создать новый объект для действий с другой матрицей.\nУчтите, что количество строк новой матрицы должно совпадать с количеством столбцов исходной.\n" << endl;
	
	cout << "Введите количество столбцов второй матрицы: ";
	int ans;
	cin >> ans;

	Matrix* m2 = new Matrix(col, ans);
	cout << "\n\nКак вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\n3 - загрузить из файла\n" << endl;

	cout << "Ваш выбор: ";
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
		m2->matrix_array = load(m2->row, m2->col);
		break;
	}
	Matrix* m3 = new Matrix(this->row, m2->col);
	cout << "\n";
	cout << "\nИтак\n";
	cout << "\nПервый множитель: \n";
	printMatrix(row, col, matrix_array);
	cout << "\n\nВторой множитель: \n";
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

	cout << "\n\nПроизведение: \n";
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
	cout << "\nДля умножения матрицы на скаляр, введите число: ";
	cin >> scal;
	cout << "\n\n";
	Matrix* m3 = new Matrix(row, col);
	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			m3->matrix_array[i][j] = matrix_array[i][j] * scal;  //заполняем текущую ячейку

		}
	}
	cout << "\nИтак\n";
	cout << "\nИсходная матрица: \n";
	printMatrix(row, col, matrix_array);
	cout << "\nРезультирующая матрица: \n";
	printMatrix(row, col, m3->matrix_array);
	chooseMatrix(*m3);



}

void Matrix::divide_scal() {
	double scal;
	cout << "\nДля деления матрицы на скаляр, введите число: ";
	cin >> scal;

	while (scal == 0) {
		cout << "\nДеление на ноль запрещено, введите новое число: ";
		cin >> scal;
	}

	Matrix* m3 = new Matrix(row, col);
	cout << "\n\n";
	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			m3->matrix_array[i][j] = matrix_array[i][j] / scal;  //заполняем текущую ячейку

		}
	}
	cout << "\nИтак\n";
	cout << "\nИсходная матрица: \n";
	printMatrix(row, col, matrix_array);
	cout << "\nРезультирующая матрица: \n";
	printMatrix(row, col, m3->matrix_array);
	chooseMatrix(*m3);

}

void Matrix::pow() {
	if (row != col) {

		cout << "Возведение в степень доступно только для квадратных матриц\nВыберите другое действие или создайте новую матрицу\n";
	}
	else {

		int pow = -1;
		cout << "\nДля возведения матрицы в степень введите целое положительное число: ";
		cin >> pow;

		while (pow <= 0) {
			cout << "\nВведите целое положительное число: ";
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


		cout << "\nИтак\n";
		cout << "\nИсходная матрица: \n";
		printMatrix(row, col, matrix_array);
		cout << "\n\nРезультирующая матрица: \n";
		printMatrix(row, col, m3->matrix_array);
		chooseMatrix(*m3);

	}
}


void Matrix::areEqual() {
	cout << "С какой матрицей вы хотите сравнить исходную матрицу?\n";
	Matrix* m2 = new Matrix();
	if (row != m2->row || col != m2->col) {
		cout << "\nМатрицы не равны \n" << endl;
		
	}
	else {
		for (int i = 0; i < col; i++)
			for (int j = 0; j < row; j++)
			{
				if (matrix_array[i][j] != m2->matrix_array[i][j])
				{
					cout << "\nМатрицы не равны \n" << endl;
					return;
				}
			}

		cout << "\nМатрицы равны \n" << endl;
		
	}
}

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

		cout << "Поиск определителя доступен только для квадратных матриц\nВыберите другое действие или создайте новую матрицу\n";
	}
	else {


	}
}

void Matrix::chooseMatrix(Matrix m3) {
	cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
	int ans;
	cin >> ans;

	if (ans == 2) {
		row = m3.row;
		col = m3.col;
		delete[] matrix_array;

		matrix_array = new double* [row];    // массив указателей
		for (int i = 0; i < row; i++) {   //
			matrix_array[i] = new double[col];     // инициализация указателей

		}

		for (int i = 0; i < row; i++)   //строки массива
		{
			for (int j = 0; j < col; j++)   //столбцы массива
			{
				matrix_array[i][j] = m3.matrix_array[i][j];  //заполняем текущую ячейку

			}
		}

	}
	cout << "\nГотово!\n" << endl;
}

void Matrix::invertMatrix() {
	if (row != col) {

		cout << "Поиск определителя доступен только для квадратных матриц\nВыберите другое действие или создайте новую матрицу\n";
	}
	else {
		Matrix* m3 = new Matrix(row, col);



		// создание
		double** matrix;

		// создание
		matrix = new double* [row];    // массив указателей
		for (int i = 0; i < row; i++) {   //
			matrix[i] = new double[col];     // инициализация указателей

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


		printMatrix(row, col, m3->matrix_array);
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
		printMatrix(row, col, m3->matrix_array);
		cout << "\n";
		printMatrix(row, col, matrix_array);


	}
}

Matrix Matrix::transMatrix() {

	Matrix* m3 = new Matrix(col, row);

	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
		{
			m3->matrix_array[i][j] = matrix_array[j][i];
		}
	cout << "\n\nИсходная матрица: " << endl;
	printMatrix(row, col, matrix_array);
	cout << "\n\nТранспонированная матрица: " << endl;
	printMatrix(m3->row, m3->col, m3->matrix_array);

	chooseMatrix(*m3);

	return *m3;
	 
}



void Matrix::checkType() {

	bool square = false; // квадратная
	bool diagonal = true; // диагональная
	bool empty = true; // нулевая 
	bool identity = true; //единичная
	bool symmetrical = false; // симметрическая 
	bool upperTriangle = true; // верхняя треугольная
	bool lowerTriangle = true; // нижняя треугольная
	bool ordinary = true;

	//проверка на квадратную матрицу
	if (row == col)
		square = true;

	//проверка на диагональную матрицу, если находим ненулевой элемент вне главной диагонали - выходим из цикла

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

	//если матрица диагональная - дополнительная проверка на нулевую матрицу
	if (diagonal == true) {
		upperTriangle = true;
		lowerTriangle = true;
		
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
	// проверка на единичную матрицу
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

	//проверка на симметрическую матрицу

	if (this->areEqual(this->transMatrix())) //если исходная и транспонированная матрицы равны
		symmetrical = true;
	
	// проверка на нижнюю треугольную матрицу 

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

	// проверка на верхнюю треугольную матрицу 

	if (square == true && diagonal == false) {

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
		ordinary == false;

	cout << "\n\nТип матрицы:\n";
	if (square) cout << "Квадратная" << endl;
	if (diagonal) cout << "Диагональная - " << endl;
	if (empty) cout << "Нулевая - " << endl;
	if (identity) cout << "Единичная - " << endl;
	if (symmetrical) cout << "Симметрическая - " << endl;
	if (upperTriangle) cout << "Верхняя треугольная" << endl;
	if (lowerTriangle) cout << "Верхняя треугольная" << endl;
	if (ordinary) cout << "Не принадлежит ни к одному из особых типов" << endl;

	

}