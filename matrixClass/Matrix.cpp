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


/*×òîáû  îïðåäåëèòü ÷èñëî ñòðîê è ñòîëáöîâ, 
ñ÷èòàåì êîëè÷åñòâî ÷èñåë â ôàéëå è êîëè÷åñòâî ïðîáåëîâ íà îäíîé ñòðîêå. 

Äîïóùåíèå - ìåæäó ÷èñëàìè ìàòðèöû ðîâíî ïî îäíîìó ïðîáåëó, â êîíöå êàæäîé ñòðîêè ëèøíåãî ïðîáåëà íåò.
*/

void readFile(int &r, int &c) {
	ifstream in("input.txt");

	if (in.is_open())
	{

		int count = 0;// ÷èñëî ÷èñåë â ôàéëå
		int temp;//Âðåìåííàÿ ïåðåìåííàÿ


		while (!in.eof())// ïðîáåãàåì ïîêà íå âñòðåòèì êîíåö ôàéëà eof
		{
			in >> temp;//â ïóñòîòó ñ÷èòûâàåì èç ôàéëà ÷èñëà
			count++;// óâåëè÷èâàåì ñ÷åò÷èê ÷èñëà ÷èñåë
		}


		//Âíà÷àëå ïåðåâåäåì êàðåòêó â ïîòîêå â íà÷àëî ôàéëà
		in.seekg(0, ios::beg);
		in.clear();

		//×èñëî ïðîáåëîâ â ïåðâîé ñòðî÷êå âíà÷àëå ðàâíî 0
		int count_space = 0;
		char symbol;
		while (!in.eof())//íà âñÿêèé ñëó÷àé öèêë îãðàíè÷èâàåì êîíöîì ôàéëà
		{
			//òåïåðü íàì íóæíî ñ÷èòûâàòü íå ÷èñëà, à ïîñèìâîëüíî ñ÷èòûâàòü äàííûå
			in.get(symbol);//ñ÷èòàëè òåêóùèé ñèìâîë
			if (symbol == ' ') count_space++;//Åñëè ýòî ïðîáåë, òî ÷èñëî ïðîáåëîâ óâåëè÷èâàåì
			if (symbol == '\n') break;//Åñëè äîøëè äî êîíöà ñòðîêè, òî âûõîäèì èç öèêëà
		}


		//Îïÿòü ïåðåõîäèì â ïîòîêå â íà÷àëî ôàéëà
		in.seekg(0, ios::beg);
		in.clear();

		//Òåïåðü ìû çíàåì ñêîëüêî ÷èñåë â ôàéëå è ñêîëüêî ïðîáåëîâ â ïåðâîé ñòðîê

		r = count_space + 1; //÷èñåë â îäíîé ñòðîêå
		c = count / r; //âñåãî ñòðîê
	}

	
}
/*Ôóíêöèÿ âîçâðàùàåò ìàòðèöó ìèíîðà, êîòîðûé ïîëó÷àåòñÿ âû÷åðêèâàíèåìè èç èñõîäíîé ìàòðèöû
r-òîé ñòðîêè è c-òîãî ñòîëáöà */
Matrix* Matrix::minorMatrix(int r, int c) {
	
	int n = this->row - 1; // ÷èñëî ñòðîê è ñòîëáöîâ ìèíîðà
	double** zero_array = new double* [n];    // ìàññèâ óêàçàòåëåé
	for (int i = 0; i < n; i++) {   //
		zero_array[i] = new double[n];     // èíèöèàëèçàöèÿ óêàçàòåëåé

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			zero_array[i][j] = 0;
		}
	}
	Matrix* minor = new Matrix(n, n, zero_array);

	minor->matrix_array = new double* [n];    // ìàññèâ óêàçàòåëåé
	for (int i = 0; i < n; i++) {   //
		minor->matrix_array[i] = new double[n];     // èíèöèàëèçàöèÿ óêàçàòåëåé

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

/*Ôóíêöèÿ ñîõðàíÿåò ïîëó÷åííóþ ìàòðèöó â ôàéë output.txt*/

void Matrix::save() {

	ofstream in("output.txt");
	if (in.is_open())
	{
		//Åñëè îòêðûòèå ôàéëà ïðîøëî óñïåøíî
		
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

/*Ôóíêöèÿ, ðåàëèçóþùàÿ ìåíþ. 
Ïðè ïåðâîì âûçîâå ïðåäëàãàåò ñîçäàòü ìàòðèöó è âûçûâàåò êîíñòðóêòîð.
Ïðè ïîñëåäóþùèõ ñòàíîâÿòñÿ äîñòóïíû äðóãèå äåéñòâèÿ, â ò.÷. âûõîä èç ïðîãðàììû èëè âûáîð íîâîé ìàòðèöû*/

int menu()
{
	if (matrixExists) {
		cout << "\n\n×òî âû õîòèòå ñäåëàòü?\n" << endl;
		cout << "\n1 - Äîáàâèòü íîâóþ ìàòðèöó\n\n2 - Ñëîæåíèå\n3 - Âû÷èòàíèå\n4 - Óìíîæåíèå íà ìàòðèöó\n5 - Óìíîæåíèå íà ñêàëÿð\n6 - Äåëåíèå íà ñêàëÿð\n7 - Âîçâåäåíèå â ñòåïåíü\n8 - ñðàâíåíèå ñ äðóãîé ìàòðèöåé (ïðîâåðêà íà ðàâåíñòâî)\n 9 - Ïðîâåðêà òèïà ìàòðèöû \n10 - Òðàíñïîíèðîâàíèå\n11 - Âû÷èñëåíèå íîðìû ìàòðèöû\n12 - Âû÷èñëåíèå äåòåðìèíàíòà\n13 - Âû÷èñëåíèå îáðàòíîé ìàòðèöû\n\n14: +=\n15: -=\n16: /=\n17: *=\n\n18 - Ñîõðàíèòü ìàòðèöó â ôàéë\n\n0 - Âûéòè" << endl;

		for (;;)
		{
			cout << "\nÂàø âûáîð: ";
			cin >> v;
			cout << "\n";

			if (v < 0 || v > 18) {
				cout << "\nÏîæàëóéñòà, ââåäèòå ÷èñëà îò 0 äî 18.\n\n" << endl;
				continue;
			}

			return v;
		}
	}
	else {
		cout << "Äîáðî ïîæàëîâàòü â ïðîãðàììó! Íàæìèòå enter, ÷òîáû äîáàâèòü íîâóþ ìàòðèöó" << endl;
		v = 1;
		cin.get();
		matrixExists = true;
		return v;

	}
}

/*ïå÷àòü ìàòðèöû*/

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

/*êîíñòðóêòîð êîïèðîâàíèÿ*/



Matrix::Matrix(Matrix& m) {
	this->row = m.row;
	this->col = m.col;
//	delete[] this->matrix_array;

	this->matrix_array = new double* [row];    // ìàññèâ óêàçàòåëåé
	for (int i = 0; i < row; i++) {   //
		this->matrix_array[i] = new double[col];     // èíèöèàëèçàöèÿ óêàçàòåëåé

	}

	for (int i = 0; i < this->row; i++)   //ñòðîêè ìàññèâà
	{
		for (int j = 0; j < this->col; j++)   //ñòîëáöû ìàññèâà
		{
			this->matrix_array[i][j] = m.matrix_array[i][j];  //çàïîëíÿåì òåêóùóþ ÿ÷åéêó

		}
	}
}

/*Ôóíêöèÿ äëÿ ðó÷íîãî ââîäà ìàòðèöû ñ êëàâèàòóðû*/

double** create(int r, int c)

{
	double** matrix;

	// ñîçäàíèå
	matrix = new double* [r];    // ìàññèâ óêàçàòåëåé
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // èíèöèàëèçàöèÿ óêàçàòåëåé

	}

	for (int i = 0; i < r; i++) {
		cout << "Ââîäèì " << i + 1 << " ñòðîêó: ";
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}

	return matrix;

}


/*Ôóíêöèÿ äëÿ ðàíäîìíîãî àâòîçàïîëíåíèÿ ìàòðèöû*/

double** generate(int r, int c) {


	double** matrix;

	// ñîçäàíèå
	matrix = new double* [r];    // ìàññèâ óêàçàòåëåé
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // èíèöèàëèçàöèÿ óêàçàòåëåé

	}

	for (int i = 0; i < r; i++)   //ñòðîêè ìàññèâà
	{
		for (int j = 0; j < c; j++)   //ñòîëáöû ìàññèâà
		{
			matrix[i][j] = 1 + rand() % 9;  //çàïîëíÿåì òåêóùóþ ÿ÷åéêó

		}
	}

	return matrix;


}

/*çàãðóçêà ìàòðèöû èç ôàéëà*/

double** load(int row, int col) {
	

	//Ñîçäàåì ôàéëîâûé ïîòîê è ñâÿçûâàåì åãî ñ ôàéëîì
	ifstream in("input.txt");

	if (in.is_open()) 
	{
		double** matrix;

		// ñîçäàíèå
		matrix = new double* [row];    // ìàññèâ óêàçàòåëåé
		for (int i = 0; i < row; i++) {   //
			matrix[i] = new double[col];     // èíèöèàëèçàöèÿ óêàçàòåëåé

		}
			//Ñ÷èòàåì ìàòðèöó èç ôàéëà
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					in >> matrix[i][j];
	
		
		return matrix;
	}
	else {
		cout << "Íå óäàëîñü îòêðûòü ôàéë " << endl;
	}

}



/*Êîíñòðóêòîð */

Matrix::Matrix(int r, int c, double** array) {
	row = r; 
	col = c;

	matrix_array = new double* [row];    // ìàññèâ óêàçàòåëåé
	for (int i = 0; i < row; i++) {   //
		matrix_array[i] = new double[col];     // èíèöèàëèçàöèÿ óêàçàòåëåé

	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix_array[i][j] = array[i][j];
		}
	}
	
	
}



/* Ñëîæåíèå ìàòðèöû  */
void Matrix::plus(Matrix* m2, Matrix* m3) {
	
	for (int i = 0; i < row; i++)   //ñòðîêè ìàññèâà
	{
		for (int j = 0; j < col; j++)   //ñòîëáöû ìàññèâà
		{
			m3->matrix_array[i][j] = matrix_array[i][j] + m2->matrix_array[i][j];  //çàïîëíÿåì òåêóùóþ ÿ÷åéêó

		}
	}

}

// Ïåðåãðóçêà îïåðàòîðîâ +=, -=, *=, /=

void Matrix::operator+=(Matrix* second) {
	
	if (this->row == second->row && this->col == second->col) {


		for (int i = 0; i < row; i++)   //ñòðîêè ìàññèâà
		{
			for (int j = 0; j < col; j++)   //ñòîëáöû ìàññèâà
			{
				this->matrix_array[i][j] += second->matrix_array[i][j];  //çàïîëíÿåì òåêóùóþ ÿ÷åéêó

			}
		}
	}

	
}


void Matrix::operator-=(Matrix* second) {
	if (this->row == second->row && this->col == second->col) {


		for (int i = 0; i < row; i++)   //ñòðîêè ìàññèâà
		{
			for (int j = 0; j < col; j++)   //ñòîëáöû ìàññèâà
			{
				matrix_array[i][j] -= second->matrix_array[i][j];  //çàïîëíÿåì òåêóùóþ ÿ÷åéêó

			}
		}
	}

}

void Matrix::operator/=(double scal) {
	if (scal != 0)
	{
		for (int i = 0; i < row; i++)   //ñòðîêè ìàññèâà
		{
			for (int j = 0; j < col; j++)   //ñòîëáöû ìàññèâà
			{
				this->matrix_array[i][j] /= scal;  //çàïîëíÿåì òåêóùóþ ÿ÷åéêó

			}
		}
	}
}

void Matrix::operator*=(Matrix* second) {

	if (this->col == second->row) {
		
		
		double** temp = new double* [this->row];    // ìàññèâ óêàçàòåëåé
		for (int i = 0; i < this->row; i++) {   //
			temp[i] = new double[second->col];     // èíèöèàëèçàöèÿ óêàçàòåëåé
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

		this->matrix_array = new double* [this->row];    // ìàññèâ óêàçàòåëåé
		for (int i = 0; i < this->row; i++) {   //
			this->matrix_array[i] = new double[this->col];     // èíèöèàëèçàöèÿ óêàçàòåëåé

		}

		for (int i = 0; i < this->row; i++)   //ñòðîêè ìàññèâà
		{
			for (int j = 0; j < this->col; j++)   //ñòîëáöû ìàññèâà
			{
				this->matrix_array[i][j] = temp[i][j];  //çàïîëíÿåì òåêóùóþ ÿ÷åéêó
				if (abs(this->matrix_array[i][j]) < 2.22045e-13)
					this->matrix_array[i][j] = 0;

			}
		}

	}

}



/*Âû÷èòàíèå ìàòðèöû */

void Matrix::minus(Matrix* m2, Matrix* m3) {

	for (int i = 0; i < row; i++)   //ñòðîêè ìàññèâà
	{
		for (int j = 0; j < col; j++)   //ñòîëáöû ìàññèâà
		{
			m3->matrix_array[i][j] = matrix_array[i][j] - m2->matrix_array[i][j];  //çàïîëíÿåì òåêóùóþ ÿ÷åéêó

		}
	}

}




/*Óìíîæåíèå ìàòðèöû*/

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


/*Óìíîæåíèå ìàòðèöû íà ñêàëÿð */

void Matrix::times_scal(double scal, Matrix* m3) {
	
	for (int i = 0; i < row; i++)   //ñòðîêè ìàññèâà
	{
		for (int j = 0; j < col; j++)   //ñòîëáöû ìàññèâà
		{
			m3->matrix_array[i][j] = matrix_array[i][j] * scal;  //çàïîëíÿåì òåêóùóþ ÿ÷åéêó

		}
	}
}


/*Äåëåíèå ìàòðèöû íà ñêàëÿð */

void Matrix::divide_scal(double scal, Matrix* m3) {
	
	for (int i = 0; i < row; i++)   //ñòðîêè ìàññèâà
	{
		for (int j = 0; j < col; j++)   //ñòîëáöû ìàññèâà
		{
			m3->matrix_array[i][j] = matrix_array[i][j] / scal;  //çàïîëíÿåì òåêóùóþ ÿ÷åéêó

		}
	}
	
}




/* Âîçâåäåíèå â ñòåïåíü */
void Matrix::pow(int n, Matrix* m3) {
		
		this->times(this, m3);
		
		if (n > 2) {
			for (int p = 1; p < n - 1; p++) {

				m3->times(this, m3);

			}
		}
}



/*Ñðàâíåíèå ìàòðèö */

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
		cout << "Ïîèñê ñëåäà ìàòðèöû äîñòóïåí òîëüêî äëÿ êâàäðàòíûõ ìàòðèö\n";

}

/*ïîèñê îïðåäåëèòåëÿ*/

double Matrix::findDet() {
	double Det;

	if (this->isSquare()) {

		if (this->row == 2) {
			Det = this->matrix_array[0][0] * this->matrix_array[1][1] - this->matrix_array[1][0] * this->matrix_array[0][1];
		}
		else {

			double** temp = new double* [this->row];    // ìàññèâ óêàçàòåëåé
			for (int i = 0; i < this->row; i++) {   //
				temp[i] = new double[this->row];     // èíèöèàëèçàöèÿ óêàçàòåëåé
			}

			for (int i = 0; i < this->row; i++)
				for (int j = 0; j < this->row; j++)
					temp[i][j] = this->matrix_array[i][j];

			//ïðèâåäåíèå ìàòðèöû ê âåðõíåòðåóãîëüíîìó âèäó
			for (int step = 0; step < this->row - 1; step++)
				for (int row_count = step + 1; row_count < this->row; row_count++)
				{
					double coeff = -temp[row_count][step] / temp[step][step]; //ìåòîä Ãàóññà
					for (int col_count = step; col_count < this->row; col_count++)
						temp[row_count][col_count] += temp[step][col_count] * coeff;
				}

			//Ðàññ÷èòàòü îïðåäåëèòåëü êàê ïðîèçâåäåíèå ýëåìåíòîâ ãëàâíîé äèàãîíàëè
			Det = 1;
			for (int i = 0; i < this->row; i++)
				Det *= temp[i][i];
		}
		return Det;
	}
}

/*íàõîæäåíèå îáðàòíîé ìàòðèöû*/

void Matrix::invertMatrix(Matrix* m3) {
	
	if (this->isSquare()) {

		double det = this->findDet();

		if (det != 0)
		{

			double** complement_matrix; //ìàòðèöà àëãåáðàè÷åñêèõ äîïîëíåíèé

			complement_matrix = new double* [this->row];    // ìàññèâ óêàçàòåëåé
			for (int i = 0; i < this->row; i++) {   //
				complement_matrix[i] = new double[this->col];     // èíèöèàëèçàöèÿ óêàçàòåëåé
			}

			//çàïîëíÿåì ìàòðèöó àëãåáðàè÷åñêèõ äîïîëíåíèé îïðåäåëèòåëÿìè ìèíîðîâ
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

			//òðàíñïîíèðóåì ìàòðèöó àëãåáðàè÷åñêèõ äîïîëíåíèé è äåëèì åå íà îïðåäåëèòåëü èñõîäíîé
			m3->transMatrix(m3);
			m3->divide_scal(det, m3);
		}
	}

}
	



/* Òðàíñïîíèðîâàíèå ìàòðèöû */

Matrix Matrix::transMatrix(Matrix *m3) {

	for (int i = 0; i < this->col; i++)
		for (int j = 0; j < this->row; j++)
		{
			m3->matrix_array[i][j] = this->matrix_array[j][i];
		}

	return *m3;

}

/*Ïðîâåðêà òèïîâ ìàòðèöû*/


bool* Matrix::checkType() {
	
	
	double** zero_array = new double* [row];    // ìàññèâ óêàçàòåëåé
	for (int i = 0; i < row; i++) {   //
		zero_array[i] = new double[col];     // èíèöèàëèçàöèÿ óêàçàòåëåé

	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			zero_array[i][j] = 0;
		}
	}
	Matrix* temp = new Matrix(row, col, zero_array);

	bool square = false; // êâàäðàòíàÿ
	bool diagonal = true; // äèàãîíàëüíàÿ
	bool empty = true; // íóëåâàÿ 
	bool identity = true; //åäèíè÷íàÿ
	bool symmetrical = false; // ñèììåòðè÷åñêàÿ 
	bool upperTriangle = true; // âåðõíÿÿ òðåóãîëüíàÿ
	bool lowerTriangle = true; // íèæíÿÿ òðåóãîëüíàÿ
	bool ordinary = true;

	//ïðîâåðêà íà êâàäðàòíóþ ìàòðèöó
	if (row == col)
		square = true;

	//ïðîâåðêà íà äèàãîíàëüíóþ ìàòðèöó, åñëè íàõîäèì íåíóëåâîé ýëåìåíò âíå ãëàâíîé äèàãîíàëè - âûõîäèì èç öèêëà
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
	//åñëè ìàòðèöà íå êâàäðàòíàÿ - ñðàçó äåëàåì âûâîä, ÷òî îíà íå äèàãîíàëüíàÿ, åäèíè÷íàÿ, âåðõíå- è íèæíåòðåóãîëüíàÿ
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
	//åñëè ìàòðèöà äèàãîíàëüíàÿ - äîïîëíèòåëüíàÿ ïðîâåðêà íà íóëåâóþ ìàòðèöó
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
	// ïðîâåðêà íà åäèíè÷íóþ ìàòðèöó
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

	//ïðîâåðêà íà ñèììåòðè÷åñêóþ ìàòðèöó
	if (square) {
		this->transMatrix(temp);
		if (this->areEqual(temp)) //åñëè èñõîäíàÿ è òðàíñïîíèðîâàííàÿ ìàòðèöû ðàâíû
			symmetrical = true;
	}
	
	// ïðîâåðêà íà íèæíþþ òðåóãîëüíóþ ìàòðèöó 

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

	// ïðîâåðêà íà âåðõíþþ òðåóãîëüíóþ ìàòðèöó 

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
