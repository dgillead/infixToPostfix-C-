// test program

#include <iostream>
#include <fstream>
#include <string>
#include "myStack.h"
#include "infixToPostfix.h"

int main()
{
	infixToPostfix infixExp;
	std::string infix;
	std::ifstream infile;
	infile.open("C:\\Users\\Darnell\\Documents\\infixData.txt");

	if (!infile)
	{
		std::cout << "Cannot open input file. Program closing." << std::endl;
		return 1;
	}

	getline(infile, infix);

	while (infile)
	{
		infixExp.getInfix(infix);
		infixExp.showInfix();
		infixExp.showPostfix();
		getline(infile, infix);
	}









	std::cin.get();
	std::cin.get();
	return 0;
}