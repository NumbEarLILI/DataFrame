#include "DataFrame.h"


int main()
{

	list<list<double>> xx = { {1,1,1},{2,2,2},{3,3,3} };
	auto iter = xx.begin();
	list<double> b = *iter;
	double a = *b.begin();

	list<char> yy = { 'a','b','c' };
	DataFrame dataset(xx, yy);
	DataFrame other(xx, yy);
	list<double> aaa = dataset.iloc(0);
	auto iii = aaa.begin();
	for (; iii != aaa.end(); ++iii)
	{
		cout << *iii << ' ';
	}
	cout << '\n' << endl;
	cout << dataset.get_nrow() << endl;
	dataset.append(other);
	cout << dataset.get_nrow() << endl;
	list<double> bbb = dataset.irow(4);
	auto ii = bbb.begin();
	for (; ii != bbb.end(); ++ii)
	{
		cout << *ii << ' ';
	}
	cout << '\n' << endl;
	system("pause");
	return 0;
}
