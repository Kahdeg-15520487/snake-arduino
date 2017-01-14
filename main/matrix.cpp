#include "matrix.h"

matrix::matrix(){
  for (int i=0;i<40;i++)
    for (int j=0;j<30;j++)
      matr[i][j]=0;
}

matrix::~matrix(){
	for (int i=0;i<40;i++)
		delete [] matr[i];
	delete [] matr;
}
