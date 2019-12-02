
#include "SUQueue.h"

/*
 * @Author: Ryan Rosiak
 * Default Constructor
 * No inputs or outputs
 * Initializes all values to default in queue
 */
template<class T>
SUQueueArr<T>::SUQueueArr() {
	arr = new T[4];
	capacity = 4;
	front = -1;
	rear = -1;
}

/*
 * @Author: Ryan Rosiak
 * enlarge Function
 * No inputs or outputs
 * Dynamically allocates more space for the queue
 */
template<class T>
void SUQueueArr<T>::enlarge() {
	capacity *= 2;
	T* buff = new T[capacity];
	for (int i = 0; i <= rear; i++) {
		buff[i] = arr[i];
	}
	delete [] arr;
	arr = buff;
}

/*
 * @Author: Ryan Rosiak
 * moveUp Function
 * No inputs or ouputs
 * Shifts all of the elements in the queue array to the front of the allocated array space
 */
template<class T>
void SUQueueArr<T>::moveUp() {
	T* buff = new T[capacity];
	for (int i = 0; i <= rear; i++) {
		buff[i] = arr[i + 1];
	}
	delete [] arr;
	arr = buff;
}

/*
 * @Author: Ryan Rosiak
 * Copy Constructor
 * No inputs or outputs
 * Copies the initialized queue into another queue
 */
template<class T>
SUQueueArr<T>::SUQueueArr(const SUQueueArr& rhs) {
	arr = new T[rhs.capacity];
	capacity = rhs.capacity;
	front = -1;
	rear = -1;
	for (int i = 0; i <= rhs.rear; i++) {
		enqueue(rhs.arr[i]);
	}
}

/*
 * @Author: Ryan Rosiak
 * Destructor
 * No inputs or outputs
 * Deallocates dynamic memory
 */
template<class T>
SUQueueArr<T>::~SUQueueArr() {
	delete [] arr;
}

/*
 * @Author: Ryan Rosiak
 * size Function
 * No inputs, returns an int
 * Gets the number of elements int the queue and returns an int
 */
template<class T>
int SUQueueArr<T>::size() const {
	return rear + 1;
}

/*
 * @Author: Ryan Rosiak
 * isEmpty Function
 * No inputs, returns a boolean
 * Checks to see if the queue is empty or not
 */
template<class T>
bool SUQueueArr<T>::isEmpty() const {
	if (front == -1) {
		return true;
	}
	return false;
}

/*
 * @Author: Ryan Rosiak
 * enqueue Function
 * No outputs, input a class T data member to be put in the back of the queue
 * Places an item to the back of the queue
 */
template<class T>
void SUQueueArr<T>::enqueue(const T& obj) {
	if (rear == (capacity - 1)) {
		enlarge();
	}
	if (front == -1) {
		front++;
	}
	arr[++rear] = obj;
}

/*
 * @Author: Ryan Rosiak
 * dequeue Function
 * No outputs, takes a reference to a class T data member and assigns the first value in the
 * queue to it
 * Dequeue's the front value from the queue
 */
template<class T>
void SUQueueArr<T>::dequeue(T& assign) {
	if (front == -1) {
		std::cout << "Queue is empty" << std::endl;
		return;
	}
	assign = arr[front];
	if (rear >= 1) {
		moveUp();
	}
	rear--;
	if (rear == -1) {
		front = -1;
	}
}

/*
 * @Author: Ryan Rosiak
 * printQueue Function
 * No inputs, outputs the queue to the screen
 * Prints the contents of the queue to the screen
 */
template<class T>
void SUQueueArr<T>::printQueue() const {
	if (front == -1) {
		std::cout << "Queue is Empty" << std::endl;
		return;
	}
	std::cout << "Front:" << std::endl;
	for (int i = front; i <= rear; i++) {
		std::cout << arr[i] << std::endl;
	}
	std::cout << "Back:" << std::endl;
}

/*
 * @Author: Ryan Rosiak
 * Overloaded Assigment
 * No outputs, takes a reference to a queue array of the same type
 * Deallocates memory for queue being assigned to and then input paramter is copied over
 */
template<class T>
SUQueueArr<T>& SUQueueArr<T>::operator=(const SUQueueArr<T>& rhs) {
	if (this == &rhs) {
		return *this;
	}

	delete [] arr;

	arr = new T[rhs.capacity];
	capacity = rhs.capacity;
	front = -1;
	rear = -1;
	for (int i = 0; i <= rhs.rear; i++) {
		enqueue(rhs.arr[i]);
	}
	return *this;
}


/*
 * @Author: Grant Dawson
 */

//defualt constructor
template<class DataType>
SUQueueList<DataType>::SUQueueList(){}

//Deconstructor
template<class DataType>
SUQueueList<DataType>::~SUQueueList(){
  //delete list;
}

//Copy constructor
template<class DataType>
SUQueueList<DataType>::SUQueueList(const SUQueueList &old){
  list=old.list;
}

//returns th current size of the queue at the time of call
template<class DataType>
int SUQueueList<DataType>::size() const{
  return list.size();
}

//This will return if the queue is empty or not
template<class DataType>
bool SUQueueList<DataType>::isEmpty() const{
  if(list.size()==0)
    return true;
  return false;
}

//This will add a new Node to the front of the queue
template<class DataType>
void SUQueueList<DataType>::enqueue(const DataType& x){
   list.putBack(x);
}
//This will pop the front of the queue off and return it
template<class DataType>
void SUQueueList<DataType>::dequeue(DataType& x){
  try{
    x=list.getFront();
  }catch(std::string n){
      std::string rtn="Queue is empty!";
      throw rtn;
  }catch(...){
    throw "An unknown error has occured...";
  }
}

//This will print the qholw queue
template<class DataType>
void SUQueueList<DataType>::printQueue() const{
  list.display();
}

//
template<class DataType>
SUQueueList<DataType>& SUQueueList<DataType>::operator=(const SUQueueList<DataType> &old){
  if(this==old){
    return *this;
  }
  list=old.list;
  return *this;
}
