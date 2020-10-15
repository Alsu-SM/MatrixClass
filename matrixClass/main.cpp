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
		if (v == 1)
		{
			m = new Matrix();
		}
					
		if (v == 2)
			m->plus();
	

		if (v == 3)
			m->minus();

		if (v == 4)
			m->times();

		if (v == 5)
			m->times_scal();

		if (v == 6)
			m->divide_scal();
		
		if (v == 7)
			m->pow();

		
			
	}
	return 0;
        
}

