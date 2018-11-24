#ifndef BOOKINFO_H
#define BOOKINFO_H
#include<iostream>
#include <string>

using namespace std;

enum relationType {LESS,GREATER,EQUAL};
class bookinfo
{
	string bookName;

public:
	bookinfo();
	void setBookName(string);
	void displayName(ostream&)const;
	relationType comparedTo(bookinfo)const;
};
#endif
