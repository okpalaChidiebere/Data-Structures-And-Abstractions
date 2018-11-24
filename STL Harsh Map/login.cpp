//--------------------------------------------------------------------
//
//  Hash Table Application: STL unordered_map
//	Based on Laboratory 12 from 
//  A Laboratory Course in C++ Data Structures, Second Edition 
//
//  Modified by Alex Clarke on Nov. 8, 2014
//
//	Complete this program so that it:
//	1) Inserts Passwords structures into the passwords unordered_map
//	   using username as the hashkey.
//	   Print the full contents of the hashtable to confirm that it worked.
//
//  2) "Authenticates" user login attempts using the the hashtable
//
//  3) Uses a custom hash function specified in the lab notes.
//
//--------------------------------------------------------------------

#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>
 
using namespace std;


//This will be the data stored in the HashTbl (class DT)
struct UserInfo
{
    string firstname,
		   lastname,
		   password;
};

//*****************************************************************
// Step 3a: Add your own string hashing class
class stringHash
{
public:
   //this operator allows us to use stringHash objects as functions to hash strings.
   size_t operator()(const string& hashit) const
   {
      size_t val = 0;
 
      for (size_t i = 0; i < hashit.length(); i++)
         val += hashit[i];
      return val;
   }
};

//*****************************************************************
// Our special string hashing class






int main()
{
	//*************************************************************
	// Step 3b: Use your own hash function
	//*************************************************************
	//** Rewrite this line so it uses one of your string hashing
	//** objects instead of the STL string hasher.
	//** You must complete Step 3a for it to work.
	unordered_map<string, UserInfo> passwords;

	unordered_map<string, UserInfo>::iterator i;
    
	UserInfo tempInfo;

	string username,      // user-supplied name
           password;      // user-supplied password

	//*************************************************************
	// Step 1a: Read in the password file
	//*************************************************************
    ifstream passFile( "password.dat" );

    if ( !passFile )
    {
        cout << "Unable to open 'password.dat'!" << endl;
        return 1;
    }

	while (passFile >> username >> tempInfo.password 
		            >> tempInfo.firstname >> tempInfo.lastname)
    {
		//**add code here to insert user info into the unordered_map
		passwords[username]=tempInfo;
        
	}

	//*************************************************************
	// Step 1b: Show that the data is in the hash table
	//*************************************************************
	//** add code here to traverse and print the unordered_map
	cout<<"Number of entries in table: "<<passwords.size()<<endl;
	cout<<"Number of buckets: "<<passwords.bucket_count()<<endl;
  for(i=passwords.begin();i!=passwords.end();i++)
  {
	   cout << left;
       cout<<setw(10)<< i->first <<setw(4)<<passwords.bucket(i->first)<<setw(15)<< i->second.password<<setw(10) << i->second.firstname<<setw(10)<<i->second.lastname<<endl;
  }



	//*********************************************************
	// Step 2: Prompt for a Login and Password and check if valid
	//*********************************************************
    cout << "Login: ";
    while ( cin >> username )  // to quit, type CTRL Z in Visual C++
    {
        cout << "Password: ";
        cin >> password;

		//** Retrieve element based on key
		
    i = passwords.find(username);
		//** if user existed in table and
		//** if the retrieved user password matches the  
		//** input password print "Authentication succeeded."
		//** followed by the user's information
	 
		if(i!=passwords.end() && password==i->second.password)
    {
		cout<<"Authentication succeeded. Welcome ";
       cout << i->second.firstname<<setw(10)<<i->second.lastname<<endl;
		 }


		//** in all other cases print "Authentication failed."
	
    else
    {
       cout << "Authentication failed." << endl;
    }
    cout<<endl;
		cout << "Login: ";

    }	
	
    cout << endl;
	return 0;
}
