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


/*Чтобы определить число строк и столбцов, 
считаем количество чисел в файле и количество пробелов на одной строке. 

Допущение - между числами матрицы ровно по одному пробелу, в конце каждой строки лишнего пробела нет.
*/

void readFile(int &r, int &c) {
	ifstream in("input.txt");

	if (in.is_open())
	{

		int count = 0;// число чисел в файле
		int temp;//Âðåìåííàÿ ïåðåìåííàÿ


		while (!in.eof())// пробегаем пока не встретим конец файла eof
		{
			in >> temp;//в пустоту считываем из файла числа
			count++;// увеличиваем счетчик числа чисел
		}


		//Вначале переведем каретку в потоке в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//Число пробелов в первой строчке вначале равно 0
		int count_space = 0;
		char symbol;
		while (!in.eof())//на всякий случай цикл ограничиваем концом файла
		{
			//теперь нам нужно считывать не числа, а посимвольно считывать данные
			in.get(symbol);//считали текущий символ
			if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
			if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
		}

		//Опять переходим в потоке в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//Теперь мы знаем сколько чисел в файле и сколько пробелов в первой строк

		r = count_space + 1; //чисел в одной строке
		c = count / r; //всего строк
	}

	
}
/*Функция возвращает матрицу минора, который получается вычеркиваниеми из исходной матрицы
r-той строки и c-того столбца */
Matrix* Matrix::minorMatrix(int r, int c) {
	
	int n = this->row - 1;// число строк и столбцов минора
	double** zero_array = new double* [n];  // массив указателей
	for (int i = 0; i < n; i++) {   //
		zero_array[i] = new double[n];  // инициализация указателей

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			zero_array[i][j] = 0;
		}
	}
	Matrix* minor = new Matrix(n, n, zero_array);

	minor->matrix_array = new double* [n];  
	for (int i = 0; i < n; i++) {   //
		minor->matrix_array[i] = new double[n];   

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

/*Функция сохраняет полученную матрицу в файл output.txt*/

void Matrix::save() {

	ofstream in("output.txt");
	if (in.is_open())
	{
		//Если открытие файла прошло успешно
		
		for (int i = 0; i < row; i++)
		{
			if (i>0)
				in << "\n";
			for (int j = 0; j < col; j++)
				in << matrix_array[i][j] << " ";
		}
		
	}
	else 
		cout << "Íå óäàëîñü îòêðûòü ôàéë " << endl;
}

/*Функция, реализующая меню. 
При первом вызове предлагает создать матрицу и вызывает конструктор.
При последующих становятся доступны другие действия, в т.ч. выход из программы или выбор новой матрицы*/


int menu()
{
	if (matrixExists) {
		cout << "\n\nЧто вы хотите сделать?\n" << endl;
		cout << "\n1 - Добавить новую матрицу\n\n2 - Сложение\n3 - Вычитание\n4 - Умножение на матрицу\n5 - Умножение на скаляр\n6 - Деление на скаляр\n7 - Возведение в степень\n8 - сравнение с другой матрицей (проверка на равенство)\n 9 - Проверка типа матрицы \n10 - Транспонирование\n11 - Вычисление нормы матрицы\n12 - Вычисление детерминанта\n13 - Вычисление обратной матрицы\n\n14: +=\n15: -=\n16: /=\n17: *=\n\n18 - Сохранить матрицу в файл\n\n0 - Выйти" << endl;

		for (;;)
		{
			cout << "\nВаш выбор: ";
			cin >> v;
			cout << "\n";

			if (v < 0 || v > 18) {
				cout << "\nПожалуйста, введите числа от 0 до 18.\n\n" << endl;
				continue;
			}

			return v;
		}
	}
	else {
		cout << "Добро пожаловать в программу! Нажмите enter, чтобы добавить новую матрицу" << endl;
		v = 1;
		cin.get();
		matrixExists = true;
		return v;

	}
}

/*печать матрицы*/

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

/*конструктор копирования*/

Matrix::Matrix(Matrix& m) {
	this->row = m.row;
	this->col = m.col;
//	delete[] this->matrix_array;

	this->matrix_array = new double* [row];    
	for (int i = 0; i < row; i++) {   //
		this->matrix_array[i] = new double[col];     

	}

	for (int i = 0; i < this->row; i++)   
	{
		for (int j = 0; j < this->col; j++)   
		{
			this->matrix_array[i][j] = m.matrix_array[i][j];  

		}
	}
}

/*Функция для ручного ввода матрицы с клавиатуры*/

double** create(int r, int c)

{
	double** matrix;

	// ñîçäàíèå
	matrix = new double* [r];    
	for (int i = 0; i < r; i++) {   
		matrix[i] = new double[c];     

	}

	for (int i = 0; i < r; i++) {
		cout << "Вводим " << i + 1 << " строку: ";
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}

	return matrix;

}


/*Функция для рандомного автозаполнения матрицы*/


double** generate(int r, int c) {


	double** matrix;

	// ñîçäàíèå
	matrix = new double* [r];    
	for (int i = 0; i < r; i++) { 
		matrix[i] = new double[c];     
	}

	for (int i = 0; i < r; i++)   
	{
		for (int j = 0; j < c; j++)  
		{
			matrix[i][j] = 1 + rand() % 9;  

		}
	}

	return matrix;


}

/*загрузка матрицы из файла*//

double** load(int row, int col) {
	

	//Создаем файловый поток и связываем его с файлом
	ifstream in("input.txt");

	if (in.is_open()) 
	{
		double** matrix;

		// создание
		matrix = new double* [row];    // массив указателей
		for (int i = 0; i < row; i++) {   //
			matrix[i] = new double[col];     // инициализация указателей

		}
			//Считаем матрицу из файла
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					in >> matrix[i][j];
	
		
		return matrix;
	}
	else {
		cout << "Не удалось открыть файл " << endl;
	}

}


/*Конструктор */

Matrix::Matrix(int r, int c, double** array) {
	row = r; 
	col = c;

	matrix_array = new double* [row]; 
	for (int i = 0; i < row; i++) {  
		matrix_array[i] = new double[col];    

	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix_array[i][j] = array[i][j];
		}
	}
	
	
}



/* Сложение матрицы  */
void Matrix::plus(Matrix* m2, Matrix* m3) {
	
	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			m3->matrix_array[i][j] = matrix_array[i][j] + m2->matrix_array[i][j];  //заполняем текущую ячейку

		}
	}

}

// Перегрузка операторов +=, -=, *=, /=

void Matrix::operator+=(Matrix* second) {
	
	if (this->row == second->row && this->col == second->col) {


		for (int i = 0; i < row; i++)   //строки массива
		{
			for (int j = 0; j < col; j++)   //столбцы массива
			{
				this->matrix_array[i][j] += second->matrix_array[i][j];  //заполняем текущую ячейку

			}
		}
	}

	
}


void Matrix::operator-=(Matrix* second) {
	if (this->row == second->row && this->col == second->col) {


		for (int i = 0; i < row; i++)   //строки массива
		{
			for (int j = 0; j < col; j++)   //столбцы массива
			{
				matrix_array[i][j] -= second->matrix_array[i][j];  //заполняем текущую ячейку

			}
		}
	}

}

void Matrix::operator/=(double scal) {
	if (scal != 0)
	{
		for (int i = 0; i < row; i++)   //строки массива
		{
			for (int j = 0; j < col; j++)   //столбцы массива
			{
				this->matrix_array[i][j] /= scal;  //заполняем текущую ячейку

			}
		}
	}
}

void Matrix::operator*=(Matrix* second) {

	if (this->col == second->row) {
		
		
		double** temp = new double* [this->row];    // массив указателей
		for (int i = 0; i < this->row; i++) {   //
			temp[i] = new double[second->col];     // инициализация указателей
		}

		for (int i = 0; i < this->row; i++)
			for (int j = 0; j < second->col; j++)
				temp[i][j] = 0;

		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < second->col; j++)
			{
				for (int k = 0; k < this->col; k++)
				{
					temp[i][j] += this->matrix_array[i][k] * second->matrix_array[k][j];

				}
			}
		}

		
		this->col = second->col;
		delete[] this->matrix_array;

		this->matrix_array = new double* [this->row];    // массив указателей
		for (int i = 0; i < this->row; i++) {   //
			this->matrix_array[i] = new double[this->col];     // инициализация указателей

		}

		for (int i = 0; i < this->row; i++)   //строки массива
		{
			for (int j = 0; j < this->col; j++)   //столбцы массива
			{
				this->matrix_array[i][j] = temp[i][j];  //заполняем текущую ячейку
				if (abs(this->matrix_array[i][j]) < 2.22045e-13)
					this->matrix_array[i][j] = 0;

			}
		}

	}

}



/*Вычитание матрицы */

void Matrix::minus(Matrix* m2, Matrix* m3) {

	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			m3->matrix_array[i][j] = matrix_array[i][j] - m2->matrix_array[i][j];  //заполняем текущую ячейку

		}
	}

}




/*Умножение матрицы*/

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


/*Умножение матрицы на скаляр */

void Matrix::times_scal(double scal, Matrix* m3) {
	
	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			m3->matrix_array[i][j] = matrix_array[i][j] * scal;  //заполняем текущую ячейку

		}
	}
}


/*Деление матрицы на скаляр */

void Matrix::divide_scal(double scal, Matrix* m3) {
	
	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			m3->matrix_array[i][j] = matrix_array[i][j] / scal;  //заполняем текущую ячейку

		}
	}
	
}




/* Возведение в степень */
void Matrix::pow(int n, Matrix* m3) {
		
		this->times(this, m3);
		
		if (n > 2) {
			for (int p = 1; p < n - 1; p++) {

				m3->times(this, m3);

			}
		}
}



/*Сравнение матриц */

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

bool Matrix::isSquare() {
	if (this->row == this->col)
		return true;
	else 
		return false;
}

double Matrix::findNorm() {
	
	

	if (this->isSquare()) {

		double temp = 0;
		for (int i = 0; i < this->row; i++)
			temp += this->matrix_array[i][i];
		return temp;
	}
	else
		cout << "Поиск следа матрицы доступен только для квадратных матриц\n";

}

/*поиск определителя*/

double Matrix::findDet() {
	double Det;

	if (this->isSquare()) {

		if (this->row == 2) {
			Det = this->matrix_array[0][0] * this->matrix_array[1][1] - this->matrix_array[1][0] * this->matrix_array[0][1];
		}
		else {

			double** temp = new double* [this->row];    // массив указателей
			for (int i = 0; i < this->row; i++) {   //
				temp[i] = new double[this->row];     // инициализация указателей
			}

			for (int i = 0; i < this->row; i++)
				for (int j = 0; j < this->row; j++)
					temp[i][j] = this->matrix_array[i][j];

			//приведение матрицы к верхнетреугольному виду
			for (int step = 0; step < this->row - 1; step++)
				for (int row_count = step + 1; row_count < this->row; row_count++)
				{
					double coeff = -temp[row_count][step] / temp[step][step]; //метод Гаусса
					for (int col_count = step; col_count < this->row; col_count++)
						temp[row_count][col_count] += temp[step][col_count] * coeff;
				}

			//Рассчитать определитель как произведение элементов главной диагонали
			Det = 1;
			for (int i = 0; i < this->row; i++)
				Det *= temp[i][i];
		}
		return Det;
	}
}

/*нахождение обратной матрицы*/

void Matrix::invertMatrix(Matrix* m3) {
	
	if (this->isSquare()) {

		double det = this->findDet();

		if (det != 0)
		{

			double** complement_matrix; //матрица алгебраических дополнений

			complement_matrix = new double* [this->row];    // массив указателей
			for (int i = 0; i < this->row; i++) {   //
				complement_matrix[i] = new double[this->col];     // инициализация указателей
			}

			//заполняем матрицу алгебраических дополнений определителями миноров
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

			//транспонируем матрицу алгебраических дополнений и делим ее на определитель исходной
			m3->transMatrix(m3);
			m3->divide_scal(det, m3);
		}
	}

}
	



/* Транспонирование матрицы */

Matrix Matrix::transMatrix(Matrix *m3) {

	for (int i = 0; i < this->col; i++)
		for (int j = 0; j < this->row; j++)
		{
			m3->matrix_array[i][j] = this->matrix_array[j][i];
		}

	return *m3;

}

/*Проверка типов матрицы*/


bool* Matrix::checkType() {
	
	
	double** zero_array = new double* [row];    // массив указателей
	for (int i = 0; i < row; i++) {   //
		zero_array[i] = new double[col];     // инициализация указателей

	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			zero_array[i][j] = 0;
		}
	}
	Matrix* temp = new Matrix(row, col, zero_array);

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
	//если матрица не квадратная - сразу делаем вывод, что она не диагональная, единичная, верхне- и нижнетреугольная
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
	//если матрица диагональная - дополнительная проверка на нулевую матрицу
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
	if (square) {
		this->transMatrix(temp);
		if (this->areEqual(temp)) //если исходная и транспонированная матрицы равны
			symmetrical = true;
	}
	
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
