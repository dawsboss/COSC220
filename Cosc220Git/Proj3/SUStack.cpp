
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
  }catch(int n){
    if(n==-1)
      throw "Queue is empty!";
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
