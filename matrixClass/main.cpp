#include <iostream>
#include<locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#include "Matrix.h"
using namespace std;


Matrix* m;


int main()
{
    setlocale(LC_ALL, "Russian");
  
	for (;;)
	{
		int v;
		v = menu();
		switch (v) {
		case 1:
			m = new Matrix();
			break;
		case 2:
			m->plus();
			break;
		case 3:
			m->minus();
			break;
		case 4:
			m->times();
			break;
		case 5:
			m->times_scal();
			break;
		case 6:
			m->divide_scal();
			break;
		case 7:
			m->pow();
			break;
		case 8:
			m->areEqual();
			break;
		case 9:
			m->checkType();
			break;
		case 10:
			m->transMatrix();
			break;
		case 11:
			m->findDet();
			break;
		case 12:
			m->invertMatrix();
			break;
		case 13:
			m->save();
			break;
		case 0:
			exit(1);
			break;
		}
		
	}

	return 0;
        
}

