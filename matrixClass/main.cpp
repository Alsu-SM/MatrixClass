#include <iostream>
#include<locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include<Windows.h>

#include "Matrix.h"
using namespace std;

int row, col;
int col2, row2;
int col3, row3;
int file_col, file_row;
int ans;
double scal;
double** new_matrix;
double** zero_array;

Matrix* m;
Matrix* m2;
Matrix* m3;

int main()
{
    setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	readFile(file_col, file_row);

	for (;;)
	{
		int v;
		v = menu();
		switch (v) {

		case 1: //создание новой матрицы
			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\n3 - загрузить из файла\n" << endl;
			
			cout << "Ваш выбор: ";
			cin >> ans;
			cout << "\n";
			switch (ans) {
			case 1:
				cout << "\nВведите количество строк и столбцов вашей новой матрицы: ";
				cin >> row;
				cin >> col;
				new_matrix = create(row, col);
				break;

			case 2:
				cout << "\nВведите количество строк и столбцов вашей новой матрицы: ";
				cin >> row;
				cin >> col;
				new_matrix = generate(row, col);
				break;
			case 3:
				row = file_row;
				col = file_col;
				new_matrix = load(row, col);
				break;
			}
			
			
			m = new Matrix(row, col, new_matrix);
			cout << "Матрица успешно создана\n";
			m->printMatrix();
			break;


		case 2: //плюс
			
			
			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически"; 
			if (file_col != col || file_row != row) {
				cout << "\nЗагрузка из файла недоступна\n" << endl;
			}
			else {
				cout << "\n3 - загрузить из файла\n" << endl;
			}
			

			cout << "Ваш выбор: ";
			cin >> ans;
	
			switch (ans) {
			case 1:
				new_matrix = create(row, col);
				break;

			case 2:
				new_matrix = generate(row, col);
				break;
			case 3:
				new_matrix = load(row, col);
				break;
			}

			zero_array = new double* [row];    // массив указателей
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

			m2 = new Matrix(row, col, new_matrix);
		
			m3 = new Matrix(row, col, zero_array);
			
			m->plus(m2, m3);

			cout << "Результирующая матрица: \n";

			m3->printMatrix();
			
			cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
			cin >> ans;
			if (ans == 2)
				m = m3;

			cout << "\nГотово!";

			break;



		case 3: //минус

			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически";
			if (file_col != col || file_row != row) {
				cout << "\nЗагрузка из файла недоступна\n" << endl;
			}
			else {
				cout << "\n3 - загрузить из файла\n" << endl;
			}


			cout << "Ваш выбор: ";
			cin >> ans;
		
			switch (ans) {
			case 1:
				new_matrix = create(row, col);
				break;

			case 2:
				new_matrix = generate(row, col);
				break;
			case 3:
				new_matrix = load(row, col);
				break;
			}

			zero_array = new double* [row];    // массив указателей
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

			m2 = new Matrix(row, col, new_matrix);

			m3 = new Matrix(row, col, zero_array);

			m->minus(m2, m3);

			cout << "Результирующая матрица: \n";

			m3->printMatrix();

			cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
			cin >> ans;
			if (ans == 2)
				m = m3;

			cout << "\nГотово!";
			
			break;


		case 4: //умножение на матрицу

			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически";
			if (file_row != col) {
				cout << "\nЗагрузка из файла недоступна\n" << endl;
			}
			else {
				cout << "\n3 - загрузить из файла\n" << endl;
			}
			
			cout << "Ваш выбор: ";
			cin >> ans;
			
			switch (ans) {
			case 1:
				cout << "\nВведите количество столбцов второй матрицы: ";
				cin >> col2;
				row2 = col;
				new_matrix = create(row2, col2);
				break;

			case 2:
				cout << "\nВведите количество столбцов второй матрицы: ";
				cin >> col2;
				row2 = col;
				new_matrix = generate(row2, col2);
				break;
			case 3:
				col2 = file_col;
				row2 = col;
				new_matrix = load(row2, col2);
				break;
			}

			zero_array = new double* [row];    // массив указателей
			for (int i = 0; i < row; i++) {   //
				zero_array[i] = new double[col2];     // инициализация указателей

			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col2; j++)
				{
					zero_array[i][j] = 0;
				}
			}

			m2 = new Matrix(row2, col2, new_matrix);

			m3 = new Matrix(row, col2, zero_array);
			

			m->times(m2, m3);

			cout << "Результирующая матрица: \n";

			m3->printMatrix();

			cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
			cin >> ans;
			if (ans == 2)
				m = m3;

			if (ans == 2)
			{
				col = col2;
		
			}

			cout << "\nГотово!";

			break;

		case 5: //умножение на скаляр
			scal;
			cout << "\nДля умножения матрицы на скаляр, введите число: ";
			cin >> scal;
			cout << "\n\n";
			zero_array = new double* [row];    // массив указателей
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
			m3 = new Matrix(row, col, zero_array);
			m->times_scal(scal, m3);

			cout << "Результирующая матрица: \n";

			m3->printMatrix();

			cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
			cin >> ans;
			if (ans == 2)
				m = m3;

			cout << "\nГотово!";

			break;


		case 6: //деление на скаляр

			scal;
			cout << "\nДля деления матрицы на скаляр, введите число: ";
			cin >> scal;

			while (scal == 0) {
				cout << "\nДеление на ноль запрещено, введите новое число: ";
				cin >> scal;
			}
			zero_array = new double* [row];    // массив указателей
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
			m3 = new Matrix(row, col, zero_array);
		


			m->divide_scal(scal, m3);

			cout << "Результирующая матрица: \n";

			m3->printMatrix();

			cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
			cin >> ans;
			if (ans == 2)
				m = m3;

			cout << "\nГотово!";

			break;

		case 7: //возведение в степень

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
				zero_array = new double* [row];    // массив указателей
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
				m3 = new Matrix(row, col, zero_array);
				

				m->pow(pow, m3);

				cout << "Результирующая матрица: \n";

				m3->printMatrix();

				cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
				cin >> ans;
				if (ans == 2)
					m = m3;

				cout << "\nГотово!";
			}
			break;

		case 8: //сравнение с матрицей
			cout << "С какой матрицей вы хотите сравнить исходную матрицу?\n";
			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\n3 - загрузить из файла\n" << endl;

			cout << "Ваш выбор: ";
			cin >> ans;
			cout << "\n";

			switch (ans) {
			case 1:
				cout << "\nВведите количество строк и столбцов вашей новой матрицы: ";
				cin >> row3;
				cin >> col3;
				new_matrix = create(row3, col3);
				break;

			case 2:
				cout << "\nВведите количество строк и столбцов вашей новой матрицы: ";
				cin >> row3;
				cin >> col3;
				new_matrix = generate(row3, col3);
				break;
			case 3:
				row3 = file_row;
				col3 = file_col;
				new_matrix = load(row3, col3);
				break;
			}


			m2 = new Matrix(row, col, new_matrix);
		
			cout << "\nМатрица 1: \n\n";
			m->printMatrix();
			cout << "\nМатрица 2: \n\n";
			m2->printMatrix();

			if (m->areEqual(m2)) {
				cout << "\n\nМатрицы равны\n\n";
			}
			else {
				cout << "\n\nМатрицы не равны\n\n";
			}
			break;

		case 9: //проверка типа матрицы
			
			cout << "\nТип матрицы:\n\n";
			if (m->checkType()[0]) cout << "Квадратная" << endl;
			if (m->checkType()[1]) cout << "Диагональная" << endl;
			if (m->checkType()[2]) cout << "Нулевая" << endl;
			if (m->checkType()[3]) cout << "Единичная" << endl;
			if (m->checkType()[4]) cout << "Симметрическая" << endl;
			if (m->checkType()[5]) cout << "Верхняя треугольная" << endl;
			if (m->checkType()[6]) cout << "Нижняя треугольная" << endl;
			if (m->checkType()[7]) cout << "Не принадлежит ни к одному из особых типов" << endl;

			break;

		case 10: //транспонированная матрица
			zero_array = new double* [row];    // массив указателей
			for (int i = 0; i < col; i++) {   //
				zero_array[i] = new double[row];     // инициализация указателей

			}
			for (int i = 0; i < col; i++)
			{
				for (int j = 0; j < row; j++)
				{
					zero_array[i][j] = 0;
				}
			}
			m3 = new Matrix(col, row, zero_array);
			m->transMatrix(m3);

			cout << "Результирующая матрица: \n";

			m3->printMatrix();

			cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
			cin >> ans;
			if (ans == 2)
				m = m3;
			
			if (ans == 2)
			{	
				int temp = col;
				col = row;
				row = temp;
			}

			cout << "\nГотово!";

			break;

		case 11:

			if (row != col) {

				cout << "Поиск следа матрицы доступен только для квадратных матриц\nВыберите другое действие или создайте новую матрицу\n";
			}
			else {
				double Norm = m->findNorm();
				cout << "\nСлед матрицы = " << Norm << "\n";
			}

			break;

		case 12: //поиск определителя
			if (row != col) {

				cout << "Поиск определителя доступен только для квадратных матриц\nВыберите другое действие или создайте новую матрицу\n";
			}
			else {
				double Det = m->findDet();
				cout << "\nДетерминант = " << Det << "\n";
			}

			break;

		case 13: //поиск обратной матрицы

			if (row != col) {

				cout << "Поиск обратной матрицы доступен только для квадратных матриц\nВыберите другое действие или создайте новую матрицу\n";
			}
			else {

				if (m->findDet() == 0)
				{
					cout << "Матрица вырожденная, определитель равен нулю.\nОбратной матрицы не существует\nВыберите другое действие или создайте новую матрицу\n";
				}
				else {
					
					zero_array = new double* [row];    // массив указателей
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
					m3 = new Matrix(row, col, zero_array);
					m->invertMatrix(m3);
					
					cout << "Результирующая матрица: \n";

					m3->printMatrix();

					cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
					cin >> ans;
					if (ans == 2)
						m = m3;
			

					cout << "\nГотово!";
				}

			}

			break;
		case 14:

			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически";
			if (file_col != col || file_row != row) {
				cout << "\nЗагрузка из файла недоступна\n" << endl;
			}
			else {
				cout << "\n3 - загрузить из файла\n" << endl;
			}

			cout << "Ваш выбор: ";
			cin >> ans;

			switch (ans) {
			case 1:
				new_matrix = create(row, col);
				break;

			case 2:
				new_matrix = generate(row, col);
				break;
			case 3:
				new_matrix = load(row, col);
				break;
			}

			m2 = new Matrix(row, col, new_matrix);

			*m += m2;

			m->printMatrix();

			break;
		case 15:
			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически";
			if (file_col != col || file_row != row) {
				cout << "\nЗагрузка из файла недоступна\n" << endl;
			}
			else {
				cout << "\n3 - загрузить из файла\n" << endl;
			}

			cout << "Ваш выбор: ";
			cin >> ans;

			switch (ans) {
			case 1:
				new_matrix = create(row, col);
				break;

			case 2:
				new_matrix = generate(row, col);
				break;
			case 3:
				new_matrix = load(row, col);
				break;
			}

			m2 = new Matrix(row, col, new_matrix);

			*m -= m2;

			m->printMatrix();
			break;


		case 16:
			cout << "\nДля деления матрицы на скаляр, введите число: ";
			cin >> scal;

			while (scal == 0) {
				cout << "\nДеление на ноль запрещено, введите новое число: ";
				cin >> scal;
			}
			*m /= scal;
			m->printMatrix();
			break;

		case 17:
			
			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически";
			if (file_row != col) {
				cout << "\nЗагрузка из файла недоступна\n" << endl;
			}
			else {
				cout << "\n3 - загрузить из файла\n" << endl;
			}

			cout << "Ваш выбор: ";
			cin >> ans;

			switch (ans) {
			case 1:
				cout << "\nВведите количество столбцов второй матрицы: ";
				cin >> col2;
				row2 = col;
				new_matrix = create(row2, col2);
				break;

			case 2:
				cout << "\nВведите количество столбцов второй матрицы: ";
				cin >> col2;
				row2 = col;
				new_matrix = generate(row2, col2);
				break;
			case 3:
				col2 = file_col;
				row2 = col;
				new_matrix = load(row2, col2);
				break;
			}
			m2 = new Matrix(row2, col2, new_matrix);
			col = col2;
			*m *= m2;
			m->printMatrix();

			break;
		case 18: //Сохранение матрицы в файл

			m->save();
			cout << "Матрица успешно сохранена в файле \'output.txt\'" << endl;

			break; //выход из программы
		case 0:
			exit(1);
			break;
		}
		
	}

	return 0;
        
}

