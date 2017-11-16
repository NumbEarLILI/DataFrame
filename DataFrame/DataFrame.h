#include <iostream>
#include "stdafx.h"
#include <list>  
#include <map>
using namespace std;


class DataFrame
{
public:
	DataFrame(void);
	DataFrame(list<list<double>> data, list<char> columns);
	list<double> iloc(int i);
	list<double> iloc(char col);
	list<double> irow(int i);
	list<list<double>> get_dataset();
	list<char> get_columns();
	map<char, int> get_rowmap();
	int get_nrow();
	int get_ncol();
	void append(DataFrame other);
	
	~DataFrame(){}
private:
	list<list<double>> dataset_;
	list<char> columns_;
	map<char, int> rowmap_;
	int nrow_;
	int ncol_;
};
