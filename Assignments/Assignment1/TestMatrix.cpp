/*************************************************************
file name: TestMatrix.cpp
name: Okpala Chidiebere Collins
student number:200356606
program purpose: to copy or to multiply two desired matrices
main algorithm:
The program first prompts a user to enter size of Matrix A and its values.
b) The program then prompts a user to enter size of Matrix B and its values.
c) The program displays both matrices, with a list of operations can be performed.
d) A user selects an operation to be performed.
1. Multiplication operation 
2. Copy operation
e) The result of selected operation is displayed.
f) If any of the operations cannot be performed, then program generates error message.
g) The program runs until user enters "!" to exit the program. 

********************************************************************/
#include "Matrix.h"//including user defined file .h 


int main()
{
  //local datas
	
	string choice; //use to store the number for options to run the program
  array matrix1;  //stores the first martrix
  array matrix2;  //stores the second matrix
  array matrix3;  //stores the sum of matrix1 and matrix2
 

 
  choice = "";

   
	  while (choice != "\n!")
	  {
		  //reading matrix A
		  cout << "Enter the number of rows for matrix A: "; //promts the user to enter the number of rows
		  cin >> useRow; //gets the inputs from the user
		  cout << "Enter the number of columns for matrix A: "; //promts the user to enter the number of rows
		  cin >> useCol; //gets the inputs from the user
		  cout << endl;
		  cout << "Enter the elements of matrix A row by row:" << endl; //promts the user to enter the numbers for the first matrix of size chosen
		  matrix1.readMatrix_A(); //gets the array numbers
		  cout << endl;
		  //reading matrix B
		  cout << "Enter the number of rows for matrix B: "; //promts the user to enter the number of rows
		  cin >> useRow2; //gets the inputs from the user
		  cout << "Enter the number of columns for matrix B: "; //promts the user to enter the number of rows
		  cin >> useCol2; //gets the inputs from the user
		  cout << endl;
		  cout << "Enter the elements of matrix B row by row:" << endl; //promts the user to enter the numbers for the second matrix of size chosen
		  matrix2.readMatrix_B();//gets the array numbers
		  cout << endl;
		  cout << "These are the Matrices you entered\n";
		  cout << "Matrix A:\n";
		  matrix1.printA();
		  cout << "Matrix B:\n";
		  matrix2.printB();
	  cout << "These are the list of operations\n";
	  cout << "Enter 1 for multiplication\n";
	  cout << "Enter 2 for Copy\n";
	  cout << "Enter ! for exit\n";
	  cout << "Enter the operation to be performed followed by '.', then press enter key: ";
	  getline(cin, choice, '.');
	  //error checking the option before going on
	  if ( (choice == "\n0" || choice != "\n2"||choice!="\n1")&&choice!="\n!")
	  {
		  cout << "Operation out of scope!\n";
	  }
	  else if (choice=="\n2"||choice=="\n1")
	  {

		  if (choice == "\n2")
		  {
			  if (useRow == useRow2&&useCol == useCol2) //an expressiin to check if both matrix are equal
			  { //assertion: both matrix are equal
				  matrix2 = matrix1.copy(matrix2);
				  cout << "Matrix A is being copied inside B\n";
				  cout << "Matrix A is\n";
				  matrix1.printA();
				  cout << "Matrix B is\n";
				  matrix1.printA();
			  }
			  else //assertion: both matrix are not equal
				  cout << "Dimension error!" << endl << endl;//prints out no
		  }
		  else if (choice == "\n1")
		  {
			  if (useCol == useRow2)
			  {
				  matrix3 = matrix1.multiply(matrix2);
				  cout << endl;//adds both matrices
				  matrix3.printResult();  //prints it out
				  cout << endl;
			  }
			  else
				  cout << "Dimension Error!\n";
		  }
	  }
	  cout << "do you want to quit? \n";
	  cout << "Enter ! to quit or N followed by '.' then press enter key to continue: ";
	  getline(cin, choice, '.');
	  cout << endl;
  } 
 

  return 0;
} //end main
