#include "vector2d.h"
class matrix{
	char matr[40][30];
	vector2d fruit;
	public:
	matrix();
	~matrix();

  char GetVal(int x,int y){ return matr[x][y];};
};
