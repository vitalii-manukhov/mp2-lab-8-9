#ifndef _TQUEUELIST_H_
#define _TQUEUELIST_H_
#include "list.h"
#include <iostream>

using namespace std;

template <class T>
class TQueueList
{
protected:
  TList<T> list;
public:
  TQueueList(); // конструктор по умолчанию
  TQueueList(const TQueueList<T>& _v);
  ~TQueueList();
  TQueueList<T>& operator =(const TQueueList<T>& _v);

  void Put(T d); // запись элемента в очередь
  T Get(); // извлечь элемент из очереди
 

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TQueueList<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, TQueueList<T1> &A);

  int IsEmpty() const; // контроль пустоты очереди
  int IsFull() const; // контроль полноты очереди
  int GetCount(); // вернуть размер очереди
};

template<class T>
TQueueList<T>::TQueueList()
{
}

template<class T>
TQueueList<T>::TQueueList(const TQueueList<T>& _v)
{
  list = _v.list;
}

template<class T>
TQueueList<T>::~TQueueList()
{
}

template<class T>
TQueueList<T>& TQueueList<T>::operator=(const TQueueList<T>& _v)
{
  if (this == &_v)
    return *this;

  list = _v.list;

  return *this;
}

template<class T>
void TQueueList<T>::Put(T d)
{
  list.InsLast(d);
}

template<class T>
T TQueueList<T>::Get()
{
  if (list.IsEmpty())
    throw "steck is empty";

  T temp = list.GetFirst()->GetData();
  list.DelFirst();

  return temp;
}

template<class T>
int TQueueList<T>::IsEmpty() const
{
  return list.IsEmpty();
}

template<class T>
int TQueueList<T>::IsFull() const
{
  return list.IsFull();
}

template<class T>
int TQueueList<T>::GetCount()
{
  return list.GetCount();
}

template<class T1>
ostream& operator<<(ostream& ostr, const TQueueList<T1>& A)
{
  return ostr << A.list;
}

template<class T1>
istream& operator>>(istream& istr, TQueueList<T1>& A)
{
  return istr >> A.list;
}


#endif // !_TQUEUELIST_H_