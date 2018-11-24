#include "LinkList.h"
#include "Linklist.cpp"
#include "BookInfo.h"
#include "bookInfo.cpp"
#include<iostream>
#include<string>


using namespace std;

int main()
{
	int length1, temp, length2;
	unsortedType comp_science;
	category compScience;
	category statistics;
	bookinfo bookName;
	string category1, category2, name;
	char inchar = 'o';

	while (inchar != 'q')
	{
		cout << "These are the list of operations\n";
		cout << "press 'a' to add new category\n";
		cout << "press 'b' to add new book\n";
		cout << "press 'c' to delete category\n";
		cout << "press 'd' to delete book\n";
		cout << "press 's' to do a searching operation\n";

		cout << "enter any of the operations: ";
		cin >> inchar;
		if (inchar == 'a')
		{
			cout << "Enter the name of the category you want to add: ";
			getline(cin, category1, '\n');
			comp_science.resetList();
			comp_science.putItem(category1);
		}
		else if (inchar == 'b')
		{
			cout << "Enter the name of the book to add: ";
			cin >> name;
			comp_science.putItem(name);
		}
		else if (inchar == 'c')
		{
			cout << "Enter the name of the category you want to delete: ";
			cin >> category1;
			comp_science.deleteItem(category1);
		}
		else if (inchar == 'd')
		{
			cout << "Enter the name of the book to delete: ";
			cin >> name;
			comp_science.deleteItem(name);

		}
		else if (inchar == 's')
		{
			cout << "these are the operations for searching\n";
			cout << "press 'u' to search for a category\n";
			cout << "press 'v' to search for a book\n";

			cout << "enter any of the operations: ";
			cin >> inchar;
			if (inchar == 'u')
			{
				cout << "Enter the name of the category you want to search: ";
				cin >> category1;
				for (int i = 0; i < comp_science.getLength(); i++)
				{
					name = comp_science.getNextItem();
					if (category1 == name)
					{
						cout << "found\n";
						break;
					}
				}
			}
			else if (inchar == 'v')
			{
				cout << "Enter the name of the book you want to search: ";
				cin >> category1;
				for (int i = 0; i < comp_science.getLength(); i++)
				{
					name = comp_science.getNextItem();
					if (category1 == name)
					{
						cout << "found\n";
						break;
					}
				}
			}
		}
		else
			cout << "operation incprrect!\n";
	}

	return 0;

}
