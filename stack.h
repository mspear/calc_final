#ifndef stack_h
#define stack_h
#include <cstddef>
using namespace std;

template<class T>
class Node {

  public:
    Node();
    Node(T, Node<T>*);
    ~Node();
  
    Node<T>* getNext();
    T getData();
    void setNext(Node<T>*);
    void setData(T);

  private:
    T val;
    Node<T>* next;
};

template <class T>
class Stack {
public:
	Stack();
	~Stack();
	void push(T);
	T pop();
	bool isEmpty();
	T peek();
	/* data */
private:
	Node<T>* head;
};


template<class T>
Node<T>::Node() {
  this->next = nullptr;
}
template<class T>
Node<T>::Node(T x, Node* next) {
  val = x;
  this->next = next;
}
template<class T>
Node<T>::~Node() {

#ifdef debug
  cout << "Deleting Node " << this->val << endl;
#endif

  if (next == nullptr) 
    return;

  try {
    delete next;
  } catch(...) {}  
}
template<class T>
void Node<T>::setNext(Node<T>* next) {
  this->next = next;
}

template<class T>
Node<T>* Node<T>::getNext() {
  return next;
}

template<class T>
void Node<T>::setData(T val) {
  this->val = val;
}

template<class T>
T Node<T>::getData() {
  return val;
}

template<class T>
Stack<T>::Stack(){
	head = nullptr;
}
template<class T>
Stack<T>::~Stack(){
	try {
		delete head;
	} catch (...) {}
}
template<class T>
void Stack<T>::push(T item){
	Node<T>* tmp = new Node<T>(item, head);
	head = tmp;

}
template<class T>
T Stack<T>::pop(){
	T val = head->getData();
	Node<T>* toDelete = head;
	head = toDelete->getNext();
	toDelete->setNext(nullptr);
	delete toDelete;
	return val;
	
}
template<class T>
bool Stack<T>::isEmpty(){
	return head == nullptr;
}
template<class T>
T Stack<T>::peek(){
	return head->getData();
}

#endif