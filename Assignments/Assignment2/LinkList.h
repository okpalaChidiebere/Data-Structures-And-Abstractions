#ifndef LINKLIST_H
#define LINKLISH_H
#include "BookInfo.h"
#include "bookInfo.cpp"
#include<string>

using namespace std;


struct category;


class unsortedType
{
private:
	category* listData;
	int length;
	category* currentPos;

public:
	unsortedType();
	void makeEmpty();
	bool isFull()const;
	int getLength()const;
	string getItem(string item, bool& found);
	void putItem(string item);
	void deleteItem(string item);
	void resetList();
	string getNextItem();
	~unsortedType();
};

struct category
{
	string bookTitle;
	category* next;

	category();
};
#endif
