#include <iostream>
#include <string>
#include <conio.h>
#include "Binary_Search_Tree_ADT.h"
#include <fstream>


using namespace std;

int main( )
{
	std::ofstream out;
	TreeType mytree;
	std::ofstream outFile;
	outFile.open("Text.txt", std::ofstream::out);
	//outFile.open();
	//mytree.MakeEmpty();

	char m = 'm';
	char e = 'e';
	char t = 't';
	char a = 'a';
	char w = 'w ';
	char i = 'i ';
	char n = 'n ';
	char o = 'o ';
	char d = 'd ';
	char s =  's';	// space box
	char l = 'l';		// delimiter



	bool finished ;
	mytree.MakeEmpty();
	/*mytree.PutItem(m);
	mytree.PutItem(l);
	mytree.PutItem(e);
	mytree.PutItem(l);
	mytree.PutItem(e);
	mytree.PutItem(l);
	mytree.PutItem(t);
	mytree.PutItem(l);
	mytree.PutItem(s);	// Puts the first < in the space venue
//	mytree.PutItem(l);
	mytree.PutItem(s);	// Puts the second < in the space venue to signify the level of travesals that space is
	mytree.PutItem(l);
	

	outFile << mytree.GetItem(m, finished) ;
	outFile << mytree.GetItem(l, finished) ;
	outFile << mytree.GetItem(e, finished) ;
	outFile << mytree.GetItem(l, finished) ;
	outFile << mytree.GetItem(e, finished) ;
	outFile << mytree.GetItem(l, finished) ;
	outFile << mytree.GetItem(t, finished) ;
	outFile << mytree.GetItem(l, finished) ;
	outFile << mytree.GetItem(s, finished) ;
	
	outFile << mytree.GetItem(s, finished) ;
	outFile << mytree.GetItem(l, finished) ;
	outFile << mytree.GetItem(m, finished) ;
	outFile << mytree.GetItem(l, finished) ;
	outFile << mytree.GetItem(e, finished) ;
	outFile << mytree.GetItem(l, finished) ;
	StringType otheritem("<>");
	mytree.Traverse(otheritem, finished);
	outFile << "\n";
	mytree.Print(outFile);		// prints the tree using the outFile in a text file called Text.txt*/
	
	if (mytree.isEmpty() == 1)	// determines whether or not the tree is empty and prints the appropriate message
		cout << "Tree is empty\n";
	else cout << "Tree is not empty";
	
	cout << "\nPlease enter a string \n";
	string userstring;
	getline(cin, userstring);	// asks for user input into the userstring string
	cout << "You entered: " << userstring << "\n";
	
	for (int i = 0; i < userstring.size(); i++)
	{
		userstring[i] = tolower(userstring[i]);		// changes every character to lowercase
		mytree.PutItem(userstring[i]);	// Puts every item the user entered in to the tree
		cout << userstring[i];	// prints out those items one by one
	}
	cout << "Sucess!! Encryption tree created with " << mytree.GetLength() << " nodes \n";

	cout << "Please enter another string. \n";
	string userstring2;
	getline(cin, userstring2);
	
	for (int i = 0; i < userstring2.size(); i++)
	{
		userstring2[i] = tolower(userstring2[i]);
		mytree.GetItem(userstring2[i], finished);		// calls the getitem function from the ADT
		cout << userstring2[i] << endl;
	}

	
	cout << "Success!! Encoded string is: " << userstring << endl;

	cout << "Now please enter the letter(s) that you would like to remove. \n";
	string userstring3;
	getline(cin, userstring3);	// asks for user input with spaces
	char * u = new char[userstring3.length()+1];
		strcpy (u, userstring3.c_str() );
	cout << u << endl;
	for (int i = 0; i < userstring3.size(); i++)
	{
		userstring3[i] = tolower(userstring3[i]);
		
	}

	mytree.DeleteItem(*u);		// deletes only one item
	
	mytree.GetLength();		// returns the number of nodes in the tree

	cout << "Success!! You have now deleted the letter(s): " << userstring3 << endl;
	
	string traverse;		// string that holds the parameter to traverse the tree
	cout << " Please enter a < > or combination to traverse the tree.\n";
	getline(cin, traverse);
	cout << "Now attempting to traverse the tree. " << endl;
	mytree.Traverse(traverse, finished);
	
	
	// pause
      cout << "\nPress any key to continue...";
      cin.sync();
       _getch();
	   outFile.close();

      // return environment variable
      return 0;
} 

