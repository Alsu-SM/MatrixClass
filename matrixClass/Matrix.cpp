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

/*Функция возвращает матрицу минора, который получается вычеркиваниеми из исходной матрицы r-той строки и c-того столбца
* Используется при нахождении обратной матрицы
*/ 


double **Matrix::minorMatrix(int r, int c, Matrix m) {
	
	int n = m.row - 1; // число строк и столбцов минора

	double** minor_matrix_array = new double* [n];    // массив указателей
	for (int i = 0; i < n; i++) {   //
		minor_matrix_array[i] = new double[n];     // инициализация указателей

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
		cout << "Матрица успешно сохранена в файле \'output.txt\'" << endl;
	}
	else 
		cout << "Не удалось открыть файл " << endl;
}

/*Функция, реализующая меню. 
При первом вызове предлагает создать матрицу и вызывает конструктор.
При последующих становятся доступны другие действия, в т.ч. выход из программы или выбор новой матрицы*/

int menu()
{
	if (matrixExists) {
		cout << "\n\nЧто вы хотите сделать?\n" << endl;
		cout << "\n1 - Добавить новую матрицу\n\n2 - Сложение\n3 - Вычитание\n4 - Умножение на матрицу\n5 - Умножение на скаляр\n6 - Деление на скаляр\n7 - Возведение в степень\n8 - сравнение с другой матрицей (проверка на равенство)\n 9 - Проверка типа матрицы \n10 - Транспонирование\n11 - Вычисление детерминанта\n12 - Вычисление обратной матрицы\n\n13 - Сохранить матрицу в файл\n\n0 - Выйти" << endl;

		for (;;)
		{
			cout << "\nВаш выбор: ";
			cin >> v;
			cout << "\n";

			if (v < 0 || v > 13) {
				cout << "\nПожалуйста, введите числа от 0 до 13.\n\n" << endl;
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
/*Функция, печатающая принимаемую матрицу
Она получает доступ к полям объекта m и проходит по двум циклам, поэлементно печатая матрицу*/

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

/*Функция для выбора основной матрицы. 
После операций можно выбрать, с какой матрицей продолжать работать, - результирующей или исходной.
Если выбираем исходную, ничего не меняется. 
При выборе результирующей - меняем поля матрицы m и переписываем массив matrix_array*/

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

/*Функция для ручного ввода матрицы с клавиатуры
Первый вариант - с выбором количества строк и столбцов матрицы*/

double** Matrix::create()

{
	cout << "\nВведите количество строк и столбцов вашей новой матрицы: ";

	cin >> row;
	cin >> col;

	this->row = row;
	this->col = col;

	double** matrix;

	// создание
	matrix = new double* [row];    // массив указателей
	for (int i = 0; i < row; i++) {   //
		matrix[i] = new double[col];     // инициализация указателей

	}

	for (int i = 0; i < row; i++) {
		cout << "Вводим " << i + 1 << " строку: ";
		for (int j = 0; j < col; j++) {
			cin >> matrix[i][j];
		}
	}

	return matrix;

}

/*Функция для ручного ввода матрицы с клавиатуры
Второй вариант - если количество строк и столбцов уже определены выбранными операциями*/

double** Matrix::create(int r, int c)

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

/*Функция для рандомного автозаполнения матрицы
Первый вариант - с выбором количества строк и столбцов матрицы*/

double** Matrix::generate() {

	cout << "\nВведите количество строк и столбцов вашей новой матрицы: ";

	cin >> row;
	cin >> col;

	this->row = row;
	this->col = col;

	double** matrix;

	// создание
	matrix = new double* [row];    // массив указателей
	for (int i = 0; i < row; i++) {   //
		matrix[i] = new double[col];     // инициализация указателей

	}

	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			matrix[i][j] = 1 + rand() % 9;  //заполняем текущую ячейку

		}
	}

	return matrix;


}

/*Функция для рандомного автозаполнения матрицы
Второй вариант - если количество строк и столбцов уже определены выбранными операциями*/

double** Matrix::generate(int r, int c) {


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

/*Функция для считывания матрицы из файла
Чтобы определить число строк и столбцов, 
считаем количество чисел в файле и количество пробелов на одной строке. 

Допущение - между числами матрицы ровно по одному пробелу, в конце каждой строки лишнего пробела нет.

*/

double** Matrix::load() {
	cout << "\nЗагружаю матрицу из файла..." << endl;


	//Создаем файловый поток и связываем его с файлом
	ifstream in("input.txt");

	if (in.is_open()) 
	{

		int count = 0;// число чисел в файле
		int temp;//Временная переменная


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

		checkFile[1]=col = count_space + 1; //чисел в одной строке
		checkFile[0] = row = count / col; //всего строк

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



/*Конструктор 1 
Предоставляет три варианта заполнения матрицы. 
После выбора вызываются соответствующие методы.
Если конструктор был вызван из меню пунктом 1) (добавить новую матрицу), выводится сообщение и печатается матрица.
*/

Matrix::Matrix() {
	
	cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\n3 - загрузить из файла\n" << endl;
	int ans;
	cout << "Ваш выбор: ";
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
		cout << "\nВаша новая матрица: \n" << endl;
		printMatrix(*this);
	}
}

/*Конструктор 2
"Тихое" создание новых объектов с известным числом строк и столбцов 

Используется для создания результирующих матриц (для записи суммы, произведения и тд).

Массив этого объекта потом заполняется в соответствующем методе.

*/
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

/*Конструктор копирования

Копирует все поля выбранного объекта. 
Хотела использовать его для возведения в степень, но передумала

*/

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

/*Сложение матрицы (вызывается из меню)

Создается новый объект m2, для которого вызывается "тихий конструктор". 
Число столбцов и строк новой матрицы совпадают с исходными.

Далее уже созданный массив матрицы на выбор заполняется вручную, генерацией или загрузкой из файла.
Если матрица из файла не подходит для сложения, программа просит выбрать другой способ.

Потом "тихим конструктором" создается результирующая матрица. Заполняется внутри цикла.

В конце можно выбрать, с какой матрицей продолжать работать дальше - исходной или результирующей.

*/

void Matrix::plus() {
	cout << "Необходимо создать новый объект для действий с другой матрицей.\nУчтите, что количество строк и столбцов матриц должны совпадать.\n" << endl;
	Matrix* m2 = new Matrix(row, col);
	m2->load();
	if(checkFile[0]!=row || checkFile[1]!=col)
	{
		cout << "\n\nКак вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\nЗагрузка из файла недоступна (матрица не удовлетворяет условиям)\n" << endl;
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
		}

	}
	else {
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
			m2->matrix_array = load();
			break;
		}
	}
	


	cout << "\nИтак:\n";
	cout << "\nПервое слагаемое: \n";
	printMatrix(*this);
	cout << "\n\nВторое слагаемое: \n";
	printMatrix(*m2);

	Matrix* m3 = new Matrix(row, col);
	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			m3->matrix_array[i][j] = this->matrix_array[i][j] + m2->matrix_array[i][j];  //заполняем текущую ячейку

		}
	}
	cout << "\n\nСумма: \n";
	printMatrix(*m3);
	chooseMatrix(*m3);

}

/*Вычитание матрицы (вызывается из меню)

Полная аналогия со сложением

*/
void Matrix::minus() {
	cout << "Необходимо создать новый объект для действий с другой матрицей.\nУчтите, что количество строк и столбцов матриц должны совпадать.\n" << endl;
	Matrix* m2 = new Matrix(row, col);
	m2->load();
	if (checkFile[0] != row || checkFile[1] != col)
	{
		cout << "\n\nКак вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\nЗагрузка из файла недоступна (матрица не удовлетворяет условиям)\n" << endl;
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
		}

	}
	else {
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
			m2->matrix_array = load();
			break;
		}
	}


	cout << "\nИтак:\n";
	cout << "\nУменьшаемое: \n";
	printMatrix(*this);
	cout << "\n\nВычитаемое: \n";
	printMatrix(*m2);

	Matrix* m3 = new Matrix(row, col);
	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			m3->matrix_array[i][j] = this->matrix_array[i][j] - m2->matrix_array[i][j];  //заполняем текущую ячейку

		}
	}

	cout << "\n\nРазность: \n";
	printMatrix(*m3);
	chooseMatrix(*m3);
}

/*Умножение матрицы (вызывается из меню)

При умножении, количество строк новой матрицы должно совпадать с количеством столбцов исходной. 
Поэтому программа запрашивает только количество столбцов второй матрицы.

Создается новый объект m2, для которого вызывается "тихий конструктор".

Далее уже созданный массив матрицы на выбор заполняется вручную, генерацией или загрузкой из файла.
Если матрица из файла не подходит для сложения, программа просит выбрать другой способ.

Потом "тихим конструктором" создается результирующая матрица. Заполняется внутри цикла.

В конце можно выбрать, с какой матрицей продолжать работать дальше - исходной или результирующей.

*/

void Matrix::times() {
	cout << "\nНеобходимо создать новый объект для действий с другой матрицей.\nУчтите, что количество строк новой матрицы должно совпадать с количеством столбцов исходной.\n" << endl;
	
	cout << "Введите количество столбцов второй матрицы: ";
	int ans;
	cin >> ans;

	Matrix* m2;
	m2 = new Matrix(col, ans);

	m2->load();

	m2 = new Matrix(col, ans);
	if (checkFile[0] != col)
	{
		cout << "\n\nКак вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\nЗагрузка из файла недоступна (матрица не удовлетворяет условиям)\n" << endl;
		int ans;
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
		}

	}
	else {
		cout << "\n\nКак вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\n3 - загрузить из файла\n" << endl;
		int ans;
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
			m2->matrix_array = load();
			break;
		}
	}

		
	Matrix* m3 = new Matrix(this->row, m2->col);
	cout << "\n";
	cout << "\nИтак\n";
	cout << "\nПервый множитель: \n";
	printMatrix(*this);
	cout << "\n\nВторой множитель: \n";
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

	cout << "\n\nПроизведение: \n";
	printMatrix(*m3);
	chooseMatrix(*m3);
}

/*

Умножение матрицы 2

Вспомогательная функция для метода возведения в степень

Умножает объект на данную матрицу m2 и возвращает результирующий массив temp->matrix_array

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

/*Умножение матрицы на скаляр (вызывается из меню)

Поэлементно умножает матрицу на введенное с клавиатуры число. 
Можно ввести проверку на недопустимые символы.

*/
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
	printMatrix(*this);
	cout << "\nРезультирующая матрица: \n";
	printMatrix(*m3);
	chooseMatrix(*m3);



}
/*Вспомогательная функция умножения на скаляр
Используется при нахождении обратной матрицы*/

Matrix Matrix::times_scal(double scal) {
	
	Matrix* m3 = new Matrix(row, col);
	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			m3->matrix_array[i][j] = matrix_array[i][j] * scal;  //заполняем текущую ячейку

		}
	}

	return *m3;
	
}

/*Деление матрицы на скаляр

Поэлементно делит матрицу на введенное с клавиатуры число.
Есть проверка на деление на ноль.

*/

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
	printMatrix(*this);
	cout << "\nРезультирующая матрица: \n";
	printMatrix(*m3);
	chooseMatrix(*m3);

}

/*для нахождения обратной матрицы*/

void Matrix::divide_scal(double scal) {
	
	//Matrix* m3 = new Matrix(row, col);

	for (int i = 0; i < row; i++)   //строки массива
	{
		for (int j = 0; j < col; j++)   //столбцы массива
		{
			matrix_array[i][j] /= scal;  //заполняем текущую ячейку

		}
	}
	

}

/*Возведение в степень

Возведение в степень доступно только для квадратных матриц 
-> есть проверка на вид матрицы с возвращением в меню.

Есть проверка на вводимое число - оно должно быть целым и положительным.

Тихо создаем результирующий объект m3. Заполняем его произведением матрицы на себя.
Если степень = 2, возвращаем объект m3/
Если степень больше 2, вызываем вспомогательную функцию умножения в цикле и сохраняем результирующие матрицы.

*/
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
		printMatrix(*this);
		cout << "\n\nРезультирующая матрица: \n";
		printMatrix(*m3);
		chooseMatrix(*m3);

	}
}

/*Сравнение матриц 1 (для вызова из меню)

Функция сравнивает объект с новой матрицей, которая создается первым конструктором. 

Если число столбцов и строк матриц не равны, делаем вывод, что матрицы также не равны.
Иначе сравниваем их поэлементно и выходим из функцие сразу, как только найдем неравные элементы.


*/

void Matrix::areEqual() {
	cout << "С какой матрицей вы хотите сравнить исходную матрицу?\n";
	Matrix* m2 = new Matrix();
	cout << "\nСравниваем с матрцией: " << endl;
	printMatrix(*m2);
	if (row != m2->row || col != m2->col) {
		cout << "\n\nМатрицы не равны \n" << endl;
		
	}
	else {
		for (int i = 0; i < col; i++)
			for (int j = 0; j < row; j++)
			{
				if (matrix_array[i][j] != m2->matrix_array[i][j])
				{
					cout << "\n\nМатрицы не равны \n" << endl;
					return;
				}
			}

		cout << "\n\nМатрицы равны \n" << endl;
		
	}
}

/*Сравнение матриц 2
Вспомогательная, "тихая функция"

Точно так же сравнивает две матрицы, но ничего не выводит на экран, а просто возвращает булевое значение.
Используется для определения типа матрицы.

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

		cout << "Поиск определителя доступен только для квадратных матриц\nВыберите другое действие или создайте новую матрицу\n";
	}
	else {

		Matrix* m2 = new Matrix(*this);
		//printMatrix(*m2);
		//приведение матрицы к верхнетреугольному виду
		for (int step = 0; step < m2->row - 1; step++)
			for (int row_count = step + 1; row_count < m2->row; row_count++)
			{
				if (m2->matrix_array[step][step] != 0)
				{
					double coeff = -m2->matrix_array[row_count][step] / m2->matrix_array[step][step]; //метод Гаусса

					for (int col_count = step; col_count < m2->row; col_count++)
						m2->matrix_array[row_count][col_count] += m2->matrix_array[step][col_count] * coeff;
				}
			}
		//cout << "\n";
		
		//printMatrix(*m2);

		//cout << "\n";
		//Рассчитать определитель как произведение элементов главной диагонали
		double Det = 1;
		for (int i = 0; i < m2->row; i++)
			Det *= m2->matrix_array[i][i];

		cout << "Детерминант = " << Det << endl;
		return Det;


	}
}

double Matrix::findDet(int n, double** array) {
	double Det;

	if (n == 2) {
		Det = array[0][0] * array[1][1] - array[1][0] * array[0][1];
		}
	else {
		
		double** temp = new double* [n];    // массив указателей
		for (int i = 0; i < n; i++) {   //
			temp[i] = new double[n];     // инициализация указателей
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				temp[i][j] = array[i][j];

		//приведение матрицы к верхнетреугольному виду
		for (int step = 0; step < n - 1; step++)
			for (int row_count = step + 1; row_count < n; row_count++)
			{
				double coeff = -temp[row_count][step] / temp[step][step]; //метод Гаусса
				for (int col_count = step; col_count < n; col_count++)
					temp[row_count][col_count] += temp[step][col_count] * coeff;
			}

		//Рассчитать определитель как произведение элементов главной диагонали
		Det = 1;
		for (int i = 0; i < n; i++)
			Det *= temp[i][i];
	}
		return Det;
}





void Matrix::invertMatrix() {
	if (row != col) {

		cout << "Поиск обратной матрицы доступен только для квадратных матриц\nВыберите другое действие или создайте новую матрицу\n";
	}
	else {

		if (findDet(row, matrix_array) == 0)
		{
			cout << "Матрица вырожденная, определитель равен нулю.\nОбратной матрицы не существует\nВыберите другое действие или создайте новую матрицу\n";
		}
		else {
			Matrix* m3 = new Matrix(row, col);

			double det = findDet(row, this->matrix_array);

			double** complement_matrix; //матрица алгебраических дополнений

			complement_matrix = new double* [this->row];    // массив указателей
			for (int i = 0; i < row; i++) {   //
				complement_matrix[i] = new double[col];     // инициализация указателей
			}

			//заполняем матрицу алгебраических дополнений определителями миноров
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

			//транспонируем матрицу алгебраических дополнений и делим ее на определитель исходной
			m3 = &m3->transMatrix(*m3);
			m3->divide_scal(det);
		
			
			//проверка на единичную матрицу
			//m3->matrix_array = m3->times(this);
			printMatrix(*m3);

			chooseMatrix(*m3);

		}

	}
		
	
}

/*Транспонирование матрицы 1 (для вызова из меню)

В строки новой матрицы записываются столбцы исходной.

*/

Matrix Matrix::transMatrix() {

	Matrix* m3 = new Matrix(col, row);

	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
		{
			m3->matrix_array[i][j] = matrix_array[j][i];
		}
	cout << "\n\nИсходная матрица: " << endl;
	printMatrix(*this);
	cout << "\n\nТранспонированная матрица: " << endl;
	printMatrix(*m3);

	chooseMatrix(*m3);

	return *m3;
	 
}

/*Транспонирование матрицы 2 

В строки новой матрицы записываются столбцы исходной.

Ничего не выводится на экран, функция возвращает указатель на созданную матрицу.
Используется при определении типа матрицы.

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

Проверка типов матрицы
(комментарии внутри функции)

*/


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

	if (this->areEqual(this->transMatrix(*this))) //если исходная и транспонированная матрицы равны
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

	cout << "\n\nТип матрицы:\n\n";
	if (square) cout << "Квадратная" << endl;
	if (diagonal) cout << "Диагональная" << endl;
	if (empty) cout << "Нулевая" << endl;
	if (identity) cout << "Единичная" << endl;
	if (symmetrical) cout << "Симметрическая" << endl;
	if (upperTriangle) cout << "Верхняя треугольная" << endl;
	if (lowerTriangle) cout << "Нижняя треугольная" << endl;
	if (ordinary) cout << "Не принадлежит ни к одному из особых типов" << endl;

}