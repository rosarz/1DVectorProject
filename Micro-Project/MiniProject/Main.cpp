#include "Vector1D.h"

int main()
{
	Vector1D a(3);
	Vector1D b(3);
	Vector1D c;
	Vector1D e(7);
	Vector1D f(e);
	Vector1D g(3);


	a.SetIndexValue(0, 1);
	a.SetIndexValue(1, 2);
	a.SetIndexValue(2, -20);

	b.SetIndexValue(0, 1);
	b.SetIndexValue(1, 2);
	b.SetIndexValue(2, 3);

	a.GetIndexValue(0);
	a.GetIndexValue(1);
	a.GetIndexValue(2);

	a + b;
	a - b;
	a * b;
	a * 5;

	g.SetIndexValue(0, 16);
	g.SetIndexValue(1, 2);
	g.SetIndexValue(2, 3);
	
	g += a;
	g -= a;
	g *= a;

	g.Norm();
	g.Average();
	g.Max();
	g.Min();
	g.Sort();

	Vector1D d(7);

	d.SetIndexValue(0, 5);
	d.SetIndexValue(1, 9);
	d.SetIndexValue(2, 2);
	d.SetIndexValue(3, 15);
	d.SetIndexValue(4, 10);
	d.SetIndexValue(5, 55);
	d.SetIndexValue(6, 14);

	d.LinearSearch(5);
	d.HalfPartSearch(10);

}