#if !defined (HYBRID_H)
#define HYBRID_H

#include "QueueLinked.h"
using CSC2110::QueueLinked;
#include "SortedListDoublyLinked.h"
#include "DoubleNode.h"

template < class T >
class Hybrid
{

   private:
      //QueueLinked<T>* q;
	  QueueLinked< DoubleNode<T> >* q;
      SortedListDoublyLinked<T>* sldl;

   public:
      Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));
      ~Hybrid();

      bool isEmpty();
      void enqueue(T* item);
      T* dequeue();
      ListDoublyLinkedIterator<T>* iterator();

};

template < class T >
Hybrid<T>::Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item))
{
	q = new QueueLinked< DoubleNode<T> >();
   // bad implementation
   //q = new QueueLinked<T>();
   sldl = new SortedListDoublyLinked<T>(comp_items, comp_keys);
}

template < class T >
Hybrid<T>::~Hybrid()
{
   delete q;
   delete sldl;
}

//DO THIS
//complete the implementation for the Hybrid ADT in two different ways
//as outlined in the Lab 10 description
//simply comment the first implementation out when working on the second implementation
//use the getKey method to dequeue/remove

template < class T >
bool Hybrid<T>::isEmpty()
{
	return q->isEmpty();
}

//good
template < class T >
void Hybrid<T>::enqueue(T* item)
{
	DoubleNode<T>* node = sldl->addDN(item);
	q->enqueue(node);
}

/*bad
template < class T >
void Hybrid<T>::enqueue(T* item)
{
	q->enqueue(item);
	sldl->add(item);
}
*/

//good
template < class T >
T* Hybrid<T>::dequeue()
{
	DoubleNode<T>* node = q->dequeue();
	T* item = sldl->remove(node);

	return item;
}

/*bad
template < class T >
T* Hybrid<T>::dequeue() 
{
	T* item = q->dequeue();
	String* key = item->getKey();
	sldl->remove(key);

	return item;
}
*/


template < class T >
ListDoublyLinkedIterator<T>* Hybrid<T>::iterator()
{
	return sldl->iterator();
}

#endif
