/*************************************************************
file name: Matrix.h
name: Okpala Chidiebere Collins
student number:200356606
file purpose: to declare the prototypes of functions used in the program

********************************************************************/
#ifndef Matrix_h  //to avoid multiple definition of the class
#define Matrix_h
#include<iostream>
#include<iomanip>
#include<string>
 //including input and output library

using namespace std;
//for matrix A
extern int useRow; //used to store the number of row to be used
extern int useCol;//used to store the number of column to be used

//for matrix b
extern int useRow2; //used to store the number of row to be used
extern int useCol2;//used to store the number of column to be used

//global data
const signed int R_SIZE=10; //the maximun number of row the program can run
const signed int C_SIZE=10;//the maximun number of column the program can run

class array
{
 private:
  int arrayMatrix[R_SIZE][C_SIZE]; //local data to store the array used

 public:
  array(); //default constructor

  //other member functions needed
  array copy(const array&)const;  //used to add teo array
  array multiply(const array&);  //use to make each index to the power of any given number
  void readMatrix_A();  //used to get the input array from the user for matrix A
  void readMatrix_B();  //used to get the input array from the user for matrix B
  void printCopy()const; //used to print copy array to the screen
  void printResult()const; //used to print copy array to the screen
  void printA()const;  //used to print matrix A
  void printB()const;   //used to print matrix B

  
 

};
#endif
