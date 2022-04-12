#pragma once
template <typename T>
class List
{
private:
	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	Node <T>*head;
	int size;
public:
	List(void);
	~List(void);
	void pushBack(T data);
	void pop_front();
	void clear();
	int getSize() { return size; }
	T& operator[](const int index);
};

template<typename T>
inline List<T>::List()
{
	head = nullptr;
	size = 0;
}


template<typename T>
List<T>::~List()
{
	clear();
	//delete
}

template<typename T>
void List<T>::pushBack(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else{
		Node<T>* cur = this->head;
		while (cur->pNext != nullptr) {
			cur = cur->pNext;
		}
		cur->pNext = new Node<T>(data);
	}
	this->size++;
}

template<typename T>
inline void List<T>::pop_front()//delete first element
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
inline void List<T>::clear()
{
	while (size) {
		pop_front();
	}
}

template<typename T>
inline T& List<T>::operator[](const int index)
{
	int count = 0;
	Node<T>* cur = this->head;
	while (cur != nullptr) {
		if (count == index) {
			return cur->data;
		}
		cur = cur->pNext;	
		count++;
	}
}
