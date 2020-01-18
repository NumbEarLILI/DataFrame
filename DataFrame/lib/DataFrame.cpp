#include <iostream>
#include "DataFrame.h"

DataFrame::DataFrame(void):
	dataset_(0),
	columns_(0),
	nrow_(0),
	ncol_(0)
{
}

DataFrame::DataFrame(list<list<double> > data, list<char> columns):
	dataset_(data),
	columns_(columns)
{

	list<char>::iterator iter = columns.begin();
	int temp = 0;
	for (; iter != columns.end(); ++iter)
	{
		rowmap_.insert({ *iter,temp });
		++temp;
	}
	ncol_ = temp;
	nrow_ = data.size();
}

list<double> DataFrame::iloc(int i)
{
	list<double> temp;
	auto iter = dataset_.begin();
	for (; iter != dataset_.end(); ++iter)
	{
		list<double> tempp = *iter;
		auto iterr = tempp.begin();
		for (int j=0; j < i; j++)
		{
			++iterr;
		}
		temp.push_back(*iterr);
	}
	return temp;
}

list<double> DataFrame::iloc(char col)
{
	int i = rowmap_.at(col);
	list<double> temp;
	auto iter = dataset_.begin();
	for (; iter != dataset_.end(); ++iter)
	{
		list<double> tempp = *iter;
		auto iterr = tempp.begin();
		for (int j = 0; j < i; j++)
		{
			++iterr;
		}
		temp.push_back(*iterr);
	}
	return temp;
	
}

list<double> DataFrame::irow(int i)
{
	auto iterr = dataset_.begin();
	for (int j = 0; j < i; j++)
	{
		++iterr;
	}
	return *iterr;
}

list<list<double>> DataFrame::get_dataset()
{
	return dataset_;
}

list<char> DataFrame::get_columns()
{
	return columns_;
}

map<char, int> DataFrame::get_rowmap()
{
	return rowmap_;
}

int DataFrame::get_nrow()
{
	return nrow_;
}

int DataFrame::get_ncol()
{
	return ncol_;
}

void DataFrame::append(DataFrame other)
{
	list<list<double>> otherdata = other.get_dataset();
	list<char> othercolumns = other.get_columns();
	int othernrow = other.get_nrow();
	
	auto iter = otherdata.begin();
	for (; iter != otherdata.end(); ++iter)
	{
		dataset_.push_back(*iter);
	}
	auto iterr = othercolumns.begin();
	int temp = nrow_;
	for (; iterr != othercolumns.end(); ++iterr)
	{
		columns_.push_back(*iterr);
		rowmap_.insert({ *iterr,temp });
		++temp;
	}
	nrow_ = temp;

}

