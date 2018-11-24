#include "LinkList.h"
#include "BookInfo.h"
#include "bookInfo.cpp"

using namespace std;

unsortedType::unsortedType()
{
	length = 0;
	listData = NULL;
}

category::category()
{
	bookTitle = "";
	next = NULL;
}



bool unsortedType::isFull()const
{
	category* location;
	try
	{
		location = new category();
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

int unsortedType::getLength()const
{
	return length;
}

void unsortedType::makeEmpty()
{
	category* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}

string unsortedType::getItem(string item, bool& found)
{
	bool moreToSearch;
	category* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (item.comparedTo(bookTitle[location]))
		{
		case LESS:
		case GREATER: location = location->next;
			moreToSearch = (location != NULL);
			break;
		case EQUAL: found = true;
			item = location->bookTitle;
			break;
		}
	}
	return item;
}

void unsortedType::deleteItem(string item)
{
	category* location = listData;
	category* tempLocation;

	if (item == listData->bookTitle)
	{
		tempLocation = location;
		listData = listData->next;
	}
	else
	{
		while (!(item == (location->next)->bookTitle))
			location = location->next;

		tempLocation = location->next;
		location->next = (location->next) ->next;
	}
	delete tempLocation;
	length--;
}

void unsortedType::putItem(string item)
{
	category* location;

	location = new category();
	location->bookTitle = item;
	location->next = listData;

	listData = location;

	length++;
}

void unsortedType::resetList()
{
	currentPos = NULL;
}

string unsortedType::getNextItem()
{
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;

	return currentPos->bookTitle;
}

unsortedType::~unsortedType()
{
	category* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
}
