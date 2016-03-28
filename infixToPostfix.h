#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include "myStack.h"
#include <string>


class infixToPostfix
{
private:
	std::string infx = " ";						// String to store the infix expression.
	std::string pfx = " ";						// String to store the postfix expression.
	std::string finalpfx = " ";					// String to store the final postfix expression.
public:
	void getInfix(std::string infix);				// Function which stores infix expression.
									// Postcondition: infx = infix.

	void showInfix();						// Function which prints the infix expression.

	void showPostfix();						// Function which prints the postfix expression.
									// Postcondition: finalpfx = covertToPostfix(infx), pfx = " ". 

	std::string convertToPostfix(std::string);			// Function which converts the infix expression to the postfix expression.
									// Postcondition: converted infix expression is returned.

	bool isOperator(char op);					// Function which determines if character is an operator.
									// Postcondition: true if operator, false if not operator.

	bool precedence(char op1, char op2);				// Function which determines the precedence of the operators.
									// Postcondition: true if op1 weight is great then or equal to op2 weight. 
									// false otherwise.
		
	bool isOperand(char operand);					// Function which determines if character is an operand.
									// Postcondition: true if operand, false if not operand.

	int operatorWeight(char op);					// Function which determines the weight of the operator (used to determine precedence.)
									// Postcondition: weight is returned.

	infixToPostfix();						// Default constructor.
									// Postcondition: infx = " ", pfx = " ".
};



// Function which stores infix expression.
// Postcondition: infx = infix.
void infixToPostfix::getInfix(std::string infix)
{
	infx = infix;
}

// Function which prints the infix expression.
void infixToPostfix::showInfix()
{
	std::cout << "Infix expression: " << infx << std::endl;
}

// Function which prints the postfix expression.
// Postcondition: finalpfx = covertToPostfix(infx), pfx = " ". 
void infixToPostfix::showPostfix()
{
	finalpfx = convertToPostfix(infx);
	std::cout << "Postfix expression: " << pfx << std::endl;
	std::cout << std::endl;
	pfx = " ";
}

// Function which converts the infix expression to the postfix expression.
// Postcondition: converted infix expression is returned.
std::string infixToPostfix::convertToPostfix(std::string expression)
{
	myStack<char> charStack;
	int expressionLength = expression.length();

	for (int i = 0; i < expressionLength; i++)
	{
		if (isOperator(expression[i]))
		{
			while (!charStack.isEmptyStack() && charStack.top() != '(' && precedence(charStack.top(), expression[i]))
			{
				pfx += charStack.top();
				charStack.pop();
			}
			charStack.push(expression[i]);
		}
		else if (isOperand(expression[i]))
		{
			pfx += expression[i];
		}
		else if (expression[i] == '(')
		{
			charStack.push(expression[i]);
		}
		else if (expression[i] == ')')
		{
			while (!charStack.isEmptyStack() && charStack.top() != '(')
			{
				pfx += charStack.top();
				charStack.pop();
			}
			charStack.pop();
		}
	}
	while (!charStack.isEmptyStack())
	{
		pfx += charStack.top();
		charStack.pop();
	}
	return pfx;
}

// Function which determines if character is an operator.
// Postcondition: true if operator, false if not operator.
bool infixToPostfix::isOperator(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/')
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Function which determines the precedence of the operators.
// Postcondition: true if op1 weight is great then or equal to op2 weight. 
// false otherwise.
bool infixToPostfix::precedence(char op1, char op2)
{
	int op1Weight = operatorWeight(op1);
	int op2Weight = operatorWeight(op2);

	if (op1Weight >= op2Weight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Function which determines if character is an operand.
// Postcondition: true if operand, false if not operand.
bool infixToPostfix::isOperand(char operand)
{
	if (operand >= '0' && operand <= '9')
	{
		return true;
	}
	else if (operand >= 'a' && operand <= 'z')
	{
		return true;
	}
	else if (operand >= 'A' && operand <= 'Z')
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

// Function which determines the weight of the operator (used to determine precedence.)
// Postcondition: weight is returned.
int infixToPostfix::operatorWeight(char op)
{
	int weight = 0;

	switch (op)
	{
	case '+':
		weight = 1;
		break;
	case '-':
		weight = 1;
		break;
	case '/':
		weight = 2;
		break;
	case '*':
		weight = 2;
		break;
	default:
		std::cout << "Invalid expression. " << std::endl;
		break;
	}
	return weight;
}

// Default constructor.
// Postcondition: infx = " ", pfx = " ".
infixToPostfix::infixToPostfix()
{
	infx = "";
	pfx = "";
}


#endif INFIXTOPOSTFIX_H
