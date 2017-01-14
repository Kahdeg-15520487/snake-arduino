#ifndef VECTOR2D_H
#define VECTOR2D_H
	class vector2d{
		int x,y;
		public:
    
		vector2d(){};
		vector2d(int X,int Y);
		vector2d(const vector2d& vt);
		~vector2d(){};
		
		void SetX(int X){ x=X;};
		void SetY(int Y){ y=Y;};
		void SetVT(vector2d& vt){ x= vt.GetX(); y= vt.GetY();};
		
		int GetX(){ return x;};
		int GetY(){ return y;};
		vector2d GetVT(){ return vector2d(x,y);};
		
		vector2d operator+(const vector2d& vt);
		vector2d operator-(const vector2d& vt);
		vector2d operator+=(const vector2d& vt);
		vector2d operator-=(const vector2d& vt);
    vector2d operator=(const vector2d& vt);
    bool operator==(const vector2d& vt);
	};
#endif
