#include <iostream>
using namespace std;

template <class T>
class Maxheap {
public:
	Maxheap(); // 0øÝ1
	Maxheap(const int); // äÀ|  Ý1
	void Push(const T&);//\􀀀Ð 􀀀X h
	void Pop();//\􀀀Ð \􀀀Ð ­ h
	bool IsEmpty() { return heapSize == 0; }
	T Top() { return heap[1]; }
private:
	void ChangeSize1D(int);
	T *heap; // element array
	int heapSize; // #elements in heap
	int capacity; // size of the array heap
	template <class T2> friend ostream& operator<<(ostream&, Maxheap<T2>&);

};
template<class T>
Maxheap<T>::Maxheap()
{
	capacity = 1;
	heapSize = 0;
	heap = new T[capacity + 1];
}
template<class T>
Maxheap<T>::Maxheap(const int a)
{
	if (a < 1) throw "Capacity must be >=1";
	capacity = a;
	heapSize = 0;
	heap = new T[capacity + 1];
}
template<class T>
void Maxheap<T>::Push(const T& e)
{
	if (heapSize == capacity)
	{
		ChangeSize1D(2 * capacity + 1);
		capacity *= 2;//20\¼
	}
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] < e)
	{
		heap[currentNode] = heap[currentNode / 2];
		currentNode /= 2;
	}
	heap[currentNode] = e;
}
template<class T>
void Maxheap<T>::Pop()
{
	if (IsEmpty()) throw"Heap is empty. Cannot Delete";
	heap[1].~T();//è¸| ­\ä.
	
	T lastE = heap[heapSize--];
	int currentNode = 1;
	int child = 2;
	while (child <= heapSize)
	{
		if (child < heapSize&&heap[child] < heap[child + 1])child++;
		if (lastE >= heap[child]) break;
		heap[currentNode] = heap[child];
		currentNode = child;
		child *= 2;
	}
	heap[currentNode] = lastE;
}
template<class T>
void Maxheap<T>::ChangeSize1D(int a)
{
	T *temp = new T[a];
	for (int i = 0; i < capacity + 1; i++)
	{
		temp[i] = heap[i];
	}
	delete[] heap;
	heap = temp;
}

template <class T2>
ostream& operator<<(ostream& os, Maxheap<T2>& H){
	os << "<Heap Contents> ";
	for (int i = 1; i <= H.heapSize; i++) os << i << ":" << H.heap[i] << " ";
	os << endl;
}