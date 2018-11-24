/*************************************************************
file name: Matrix.cpp
name: Okpala Chidiebere Collins
student number:200356606
file purpose: to define the functions prototypes in the .h file
********************************************************************/
#include "Matrix.h"  //including user defined file .h 

//for matrix A
int useRow; //the maximun number of row the program can run
int useCol; //the maximun number of column the program can run
//for matrix B
int useRow2; //the maximun number of row the program can run
int useCol2; //the maximun number of column the program can run



array::array()  //function definition for the constructor
{ //uses two for loop to go through the rows and column
  for(int i=0;i<R_SIZE;i++)
    for(int j=0;j<C_SIZE;j++)
      arrayMatrix[i][j]=0; //initializes all the index to zero
}



void array::readMatrix_A()  //a function definition to get the input from the user
{//uses two for loop to go through the rows and column
  for(int i=0;i<useRow;i++)
    for(int j=0;j<useCol;j++)
      cin>>arrayMatrix[i][j]; //initializes all the index to according to loop
}

void array::readMatrix_B()  //a function definition to get the input from the user
{//uses two for loop to go through the rows and column
	for (int i = 0; i<useRow2; i++)
		for (int j = 0; j<useCol2; j++)
			cin >> arrayMatrix[i][j]; //initializes all the index to according to loop
}
//function definition for the add array
array array::copy(const array& a)const 
{
  
	array temp;
  //uses two for loop to go through the rows and column
  for(int i=0;i<useRow;i++)
    for(int j=0;j<useCol;j++)
		temp.arrayMatrix[i][j] = a.arrayMatrix[i][j]; //sums the two array and initializes it to th
  return temp;
}


array array::multiply(const array& a)
{	
  array temp; //local data

  //uses two for loop to go through the rows and column
  for(int i=0;i<useRow;i++)
    {
      for(int j=0;j< useCol2;j++)
	{
	
	 for(int k=0;k<useCol;k++)
		temp.arrayMatrix[i][j]=temp.arrayMatrix[i][j]+(arrayMatrix[i][k]*a.arrayMatrix[k][j]); //calculation for each number in the result matrix
	 //assertion: a number is done from the result matrix 
	}
    }
  return temp; //returns the temp array after calulation done
}

void array::printCopy()const
{//uses two for loop to go through the rows and column
  for(int i=0;i<useRow;i++)
    {
      for(int j=0;j<useCol;j++)
	{
	  cout<<setw(3)<<left<<arrayMatrix[i][j];  //prints the given index to the screen
	}
      cout<<endl;  //goes to the next line
    }
}

void array::printResult()const
{//uses two for loop to go through the rows and column
	for (int i = 0; i<useRow; i++)
	{
		for (int j = 0; j<useCol2; j++)
		{
			cout << setw(3) << left << arrayMatrix[i][j];  //prints the given index to the screen
		}
		cout << endl;  //goes to the next line
	}
}

void array::printA()const
{//uses two for loop to go through the rows and column
	for (int i = 0; i<useRow; i++)
	{
		for (int j = 0; j<useCol; j++)
		{
			cout << setw(3) << left << arrayMatrix[i][j];  //prints the given index to the screen
		}
		cout << endl;  //goes to the next line
	}
}

void array::printB()const
{//uses two for loop to go through the rows and column
	for (int i = 0; i<useRow2; i++)
	{
		for (int j = 0; j<useCol2; j++)
		{
			cout << setw(3) << left << arrayMatrix[i][j];  //prints the given index to the screen
		}
		cout << endl;  //goes to the next line
	}
}

