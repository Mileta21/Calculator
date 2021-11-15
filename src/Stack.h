#pragma once

template <typename T>
class Stack
{
private:
	T* mas;
	int len, count, capacity;
	bool isStackEmpty();
	bool isStackFull();
public:
	Stack();
	Stack(int);
	Stack(const Stack<T>&);
	Stack<T>& operator = (const Stack<T>&);
	~Stack();
	//
	T& Pop();
	void Push(T);
	int GetLen();
};

template<typename T>
inline bool Stack<T>::isStackEmpty()
{
	return len == 0;
}

template<typename T>
inline bool Stack<T>::isStackFull()
{
	return len == capacity;
}

template<typename T>
inline Stack<T>::Stack() : len(0), count(-1), capacity(100)/*, mas(new T[capacity]*/
{
	mas = new T[capacity];
}

template<typename T>
inline Stack<T>::Stack(int size) : len(0), count(-1), capacity(size)/*, mas(new T[size])*/
{
	mas = new T[capacity];
}

template<typename T>
inline Stack<T>::Stack(const Stack<T>& G) : len(G.len), count(G.count), capacity(G.capacity)
{
	for (int i = 0; i < len; ++i)
		mas[i] = G.mas[i];
}

template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack<T>& G)
{
	if (this == &G)
		return *this;
	len = G.len;
	count = G.count;
	capacity = G.capacity;
	for (int i = 0; i < len; ++i)
		mas[i] = G.mas[i];
	return *this;
}

template<typename T>
inline Stack<T>::~Stack()
{
	delete[] mas;
}

template<typename T>
inline T & Stack<T>::Pop()
{
	if (!isStackEmpty())
	{
		T& tmp = mas[count];
		--count;
		--len;
		return tmp;
	}
}

template<typename T>
inline void Stack<T>::Push(T element)
{
	if (!isStackFull())
	{
		++count;
		mas[count] = element;
		++len;
	}
}

template<typename T>
inline int Stack<T>::GetLen()
{
	return len;
}


