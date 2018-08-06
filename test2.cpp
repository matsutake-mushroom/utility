#include "linear.cpp"

int main(){
	Matrix a;
	Matrix b(2,2);
	Matrix b2(2,2);
	Matrix b3(2,2);
	Matrix c(2,2);

	b.rand();
	b2.rand();
	b.show();
	b2.show();
	b3 = b2;
	b3.show();
	(b+b2+b3).show();
	b.show();
	c.set(0,0,1.0);
	c.set(0,1,2.0);
	c.set(1,0,3.0);
	c.set(1,1,4.0);	
	(c*c).show();
	return 0;
}
