











#include "SUStack.h"

/*
 * @Author: Ryan Rosiak
 * Default Constructor
 * No inputs or outputs
 * Allocates memory for array of type T
 */
template<class T>
SUStackArr<T>::SUStackArr() {
	arr = new T[4];
	capacity = 4;
	top = -1;
}

/*
 * @Author: Ryan Rosiak
 * enlarge Function
 * No inputs or outputs
 * Resizes the array stack and makes it bigger so more data can be stored
 */
template<class T>
void SUStackArr<T>::enlarge() {
	capacity *= 2;
	T* buff = new T[capacity];
	for (int i = 0; i <= top; i++) {
		buff[i] = arr[i];
	}
	delete [] arr;
	arr = buff;
}

/*
 * @Author: Ryan Rosiak
 * Copy Constructor
 * No inputs or outputs
 * Allocates memory for array of type T assigned from another array of type T
 */
template<class T>
SUStackArr<T>::SUStackArr(const SUStackArr& rhs) {
	arr = new T[rhs.capacity];
	capacity = rhs.capacity;
	top = -1;
	for (int i = 0; i <= rhs.top; i++) {
		push(rhs.arr[i]);
	}
}

/*
 * @Author: Ryan Rosiak
 * Destructor
 * No inputs or outputs
 * Deallocates memory of current stack array
 */
template<class T>
SUStackArr<T>::~SUStackArr() {
	delete [] arr;
}

/*
 * @Author: Ryan Rosiak
 * size Function
 * No inputs, returns an int
 * Gets the number of elements in the stack and returns the counter
 */
template<class T>
int SUStackArr<T>::size() const {
	return top + 1;
}

/*
 * @Author: Ryan Rosiak
 * isEmpty Function
 * No inputs, returns a boolean
 * Checks if the stack is empty
 */
template<class T>
bool SUStackArr<T>::isEmpty() const {
	if (top == -1) {
		return true;
	}
	return false;
}

/*
 * @Author: Ryan Rosiak
 * push Function
 * No outputs, takes a type T argument/object by reference that is pushed onto the stack array
 * Pushes an object of type T onto the stack in the array
 */
template<class T>
void SUStackArr<T>::push(const T& obj) {
	if (top == (capacity - 1)) {
		enlarge();
	}
	arr[++top] = obj;
}

/*
 * @Author: Ryan Rosiak
 * pop Function
 * No outputs, takes a type T argument reference and assigns the popped value to it
 * Assigns the popped value off the stack to the argument passed through
 */
template<class T>
void SUStackArr<T>::pop(T& assign) {
	if (top == -1) {
		std::cout << "Stack is empty" << std::endl;
		return;
	}
	assign = arr[top];
	top--;
}

/*
 * @Author: Ryan Rosiak
 * printStack Function
 * No inputs, outputs the array stack contents from top to bottom
 * Outputs the array contents from top to bottom
 */
template<class T>
void SUStackArr<T>::printStack() const {
	if (top == -1) {
		std::cout << "Stack is Empty" << std::endl;
		return;
	}
	std::cout << "Top:" << std::endl;
	for (int i = top; i >= 0; i--) {
		std::cout << arr[i] << std::endl;
	}
	std::cout << "Bottom:" << std::endl;
}

/*
 * @Author: Ryan Rosiak
 * Overloaded Assignment
 * No inputs or outputs
 * Assigns the right hand side array stack to the left hand side array stack
 */
template<class T>
SUStackArr<T>& SUStackArr<T>::operator=(const SUStackArr<T>& rhs) {
	if (this == &rhs) {
		return *this;
	}

	delete [] arr;

	arr = new T[rhs.capacity];
	capacity = rhs.capacity;
	top = -1;
	for (int i = 0; i <= rhs.top; i++) {
		push(rhs.arr[i]);
	}
	return *this;
}




















/*
 * @Author: Grant Dawson
 */

//defualt constructor
template<class DataType>
SUStackList<DataType>::SUStackList(){
}
//copy constructor
template<class DataType>
SUStackList<DataType>::SUStackList(const SUStackList &old){
  list=old.list;
}
//Deconstructor
template<class DataType>
SUStackList<DataType>::~SUStackList(){
  //delete list;
}
//returns the size of the Stack at that moment
template<class DataType>
int SUStackList<DataType>::size() const{
  return list.size();
}
//checks to see if the stack is empty or not
template<class DataType>
bool SUStackList<DataType>::isEmpty() const{
  if(list.size()==0)
    return true;
  return false;
}
//pushs a newNode to the end of the list
template<class DataType>
void SUStackList<DataType>::push(const DataType& x){
  list.putBack(x);
}
//pops the top/back of the stack off and returns the data what was in it
template<class DataType>
void SUStackList<DataType>::pop(DataType& x){
  try{
    x=list.getBack();
    std::cout<<"-----=========-------\n";
    x.printInfo();
  }catch(std::string n){
    std::string rtn="Stack is empty!";
    throw rtn;
  }catch(...){
    throw "An unknown error has occured...";
  }
}
//This will print the stack
template<class DataType>
void SUStackList<DataType>::printStack() const{
  list.display();
}
//= operator will set the data in the right into the left
template<class DataType>
SUStackList<DataType>& SUStackList<DataType>::operator=(const SUStackList<DataType>& old){
  if(this==&old){
    return *this;
  }
  list=old.list;
  return *this;
}
