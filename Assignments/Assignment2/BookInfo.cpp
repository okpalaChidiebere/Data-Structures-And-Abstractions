#include "BookInfo.h"

bookinfo::bookinfo()
{
	bookName = "";
}

void bookinfo::setBookName(string name)
{
	bookName = name;
}


void bookinfo::displayName(ostream& ous)const
{
	cout << bookName << endl;
}

relationType bookinfo::comparedTo(bookinfo otherItem)const
{
	if (bookName < otherItem.bookName)
		return LESS;
	else if (bookName > otherItem.bookName)
		return GREATER;
	else
		return EQUAL;
}
