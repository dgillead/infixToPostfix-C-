#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <cassert>


template <class Type>
class myStack
{
private:
	int maxStackSize;								// Variable to store maximum stack size.
	int stackTop;									// Variable to point to the top of the stack.
	Type* list;									// Pointer to the array that holds the stack elements.
public:
	const myStack<Type>& operator=(const myStack<Type>&);				// Function to overload assignment operator.

	void initializeStack();								// Function to initialize the stack.
											// Postcondition: stackTop = 0;

	bool isEmptyStack() const;							// Function to determine if the stack is empty.
											// Postcondition: returns true if empty, false otherwise.
	bool isFullStack() const;							// Function to determine if stack is full.
											// Postcondition: returns true if stack is full, false otherwise.

	void push(const Type& newItem);							// Function to add newItem to the stack.
											// Postcondition: stack is changed and newItem is added to top of stack.

	Type top() const;								// Function to return the top element of the stack.
											// Postcondition: if stack is empty, the program terminates; otherwise, the top
											// element of the stack is returned.

	void pop();									// Function to remove the top element of the stack.
											// Postcondition: the stack is changed and the top element is removed from the stack.

	void copyStack(const myStack<Type>& otherStack);				// Function to make a copy of otherStack.
											// Postcondition: a copy of otherStack is created and assigned to this stack.

	myStack(int stackSize = 100);							// Default constructor.
											// Postcondition: stack is created and set to 100 by default if user enters invalid 
											// stacksize.

	myStack(const myStack<Type>& otherStack);					// Copy constructor.
											// Postcondition: copy of otherStack is stored in stack.

	~myStack();									// Destructor.
};



// Function to overload assignment operator.
template<class Type>
const myStack<Type>& myStack<Type>::operator=(const myStack<Type>& otherStack)
{
	if (this != &otherStack)
	{
		copyStack(otherStack);
	}
	return *this;
}

// Function to initialize the stack.
// Postcondition: stackTop = 0;
template<class Type>
void myStack<Type>::initializeStack()
{
	stackTop = 0;
}

// Function to determine if the stack is empty.
// Postcondition: returns true if empty, false otherwise.
template<class Type>
bool myStack<Type>::isEmptyStack() const
{
	return (stackTop == 0);
}

// Function to determine if stack is full.
// Postcondition: returns true if stack is full, false otherwise.
template<class Type>
bool myStack<Type>::isFullStack() const
{
	return (stackTop == maxStackSize);
}

// Function to add newItem to the stack.
// Postcondition: stack is changed and newItem is added to top of stack.
template<class Type>
inline void myStack<Type>::push(const Type & newItem)
{
	if (!isFullStack())
	{
		list[stackTop] = newItem;

		stackTop++;
	}
	else
	{
		std::cout << "Cannot add to a full stack. " << std::endl;
	}
}

// Function to return the top element of the stack.
// Postcondition: if stack is empty, the program terminates; otherwise, the top
// element of the stack is returned.
template<class Type>
Type myStack<Type>::top() const
{
	assert(stackTop != 0);

	return list[stackTop-1];
}

// Function to remove the top element of the stack.
// Postcondition: the stack is changed and the top element is removed from the stack.
template<class Type>
void myStack<Type>::pop()
{
	if (!isEmptyStack())
	{
		stackTop--;
	}
	else
	{
		std::cout << "Cannot remove from an empty stack." << std::endl;
	}
}

// Function to make a copy of otherStack.
// Postcondition: a copy of otherStack is created and assigned to this stack.
template<class Type>
void myStack<Type>::copyStack(const myStack<Type>& otherStack)
{
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;

	list = new Type[maxStackSize];

	for (int j = 0; j < stackTop; j++)
	{
		list[j] = otherStack.list[j];
	}
}

// Default constructor.
// Postcondition: stack is created and set to 100 by default if user enters invalid 
// stacksize.
template<class Type>
myStack<Type>::myStack(int stackSize)
{
	if (stackSize <= 0)
	{
		std::cout << "Size of the array to hold stack must be positive." << std::endl;
		std::cout << "Created an array of default size 100. " << std::endl;
		maxStackSize = 100;
	}
	else
	{
		maxStackSize = stackSize;
	}
	stackTop = 0;
	list = new Type[maxStackSize];
}

// Copy constructor.
// Postcondition: copy of otherStack is stored in stack.
template<class Type>
myStack<Type>::myStack(const myStack<Type>& otherStack)
{
	list = nullptr;

	copyStack(otherStack);
}

// Destructor.
template<class Type>
myStack<Type>::~myStack()
{
	delete[] list;
}


#endif MYSTACK_H
