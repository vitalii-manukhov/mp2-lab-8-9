#pragma once
#include <iostream>

using namespace std;

template<class T>
class TListElem
{
protected:
  T data;
  TListElem<T>* next;
  TListElem<T>* prev;
public:
  TListElem(T _data);
  ~TListElem();

  T GetData();
  TListElem<T>* GetNext();
  TListElem<T>* GetPrev();

  void SetData(T _data);
  void SetNext(TListElem<T>* _next);
  void SetPrev(TListElem<T>* _prev);

  template <class T1>
  friend ostream& operator << (ostream& ostr, const TListElem<T1>& A);
  template <class T1>
  friend istream& operator >> (istream& istr, const TListElem<T1>& A);
};

template <class T>
class TList
{
protected:
  TListElem<T>* root; // корень списка
  TListElem<T>* end; // конец списка (индекс последнего элемента)
  int count; // количество элементов списка

public:
  TList(); // конструктор по умолчанию
  TList(const TList<T>& _v); // конструктор копирования
  ~TList();

  TList<T>& operator =(const TList<T>& _v); // оператор сравнения

  void InsFirst(T d); // запись элемента в стек
  void InsLast(T d);
  void Ins(TListElem<T>* e, T d); // вставка в список после указанного элемента
  
  TListElem<T>* GetFirst(); // извлечь элемент
  TListElem<T>* GetLast();
  
  void DelFirst();
  void DelLast();
  void Del(TListElem<T>* e);

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TList<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, TList<T1> &A);

  bool IsFull() const;
  bool IsEmpty() const;
  int GetCount(); // количество элементов
};

template<class T1>
ostream& operator<<(ostream& ostr, const TListElem<T1>& A)
{
  ostr << A.data;
}

template<class T1>
istream& operator>>(istream& istr, const TListElem<T1>& A)
{
  istr >> A.data;
}

template <class T1>
ostream& operator<< (ostream& ostr, const TList<T1> &A)
{
  TListElem<T1>* i = A.root;

  while (i != nullptr)
  {
    ostr << *i << endl;
    i = i->GetNext();
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TList<T1> &A) {
  int count;
  istr >> count;
  for (int i = 0; i < count; i++) 
  {
    T1 d;
    istr >> d;
    A.InsLast(d);
  }
  return istr;
}

template<class T>
TList<T>::TList()
{
  root = nullptr;
  end = nullptr;
  count = 0;
}

template <class T>
TList<T>::TList(const TList<T>& _v)
{
  count = _v.count;

  TListElem<T>* i = _v.root; // индекс пришедшего списка
  TListElem<T>* j = this->root; // корень несуществующего списка
  TListElem<T>* p = nullptr; // указатель на предка

  while (i != nullptr) // копируем список
  {
    j = new TListElem(*i);
    j->SetNext(0);
    if (p != nullptr)
    {
      p->SetNext(j);
      j->SetPrev(p);
    }

    p = j; // переход

    if (root == nullptr) // если не было корня
      root = j;

    i = i->next;
  }
}

template <class T>
TList<T>::~TList()
{
  if (this->root != nullptr)
  {
    TListElem<T>* i = this->root;
    TListElem<T>* p = nullptr;

    while (i != nullptr)
    {
      p = i;
      i = i->GetNext();
      delete p;
    }

    this->root = nullptr;
    this->end = nullptr;
    count = 0;
  }
}

template <class T>
TList<T>& TList<T>::operator =(const TList<T>& _v)
{
  if (this == &_v)
    return *this;

  if (this->root != nullptr)
  {
    TListElem<T>* i = this->root;
    TListElem<T>* p = nullptr;

      while (i != nullptr)
      {
        p = i;
        i = i->GetNext();
        delete p;
      }

    this->root = nullptr;
    this->end = nullptr;
    count = 0;
  }

  count = _v.count;

  TListElem<T>* i = _v.root; // индекс пришедшего списка
  TListElem<T>* j = this->root; // корень несуществующего списка
  TListElem<T>* p = nullptr; // указатель на предка

  while (i != nullptr) // копируем список
  {
    j = new TListElem<T>(*i);
    j->SetNext(0);
    if (p != nullptr)
    {
      p->SetNext(j);
      j->SetPrev(p);
    }

    p = j; // переход

    if (root == nullptr) // если не было корня
      root = j;

    i = i->GetNext();
  }

  return *this;

}

template<class T>
void TList<T>::InsFirst(T d)
{
  if (this->IsFull())
    throw "stack overflow";

  TListElem<T>* temp = new TListElem<T>(d); // создаем новый элемент списка от d
  temp->SetNext(root); // в качестве следующего указали root
  root = temp; // переписали root
  if (end == nullptr)
    end = temp;
  count++;
}

template<class T>
void TList<T>::InsLast(T d)
{
  if (this->IsFull())
    throw "stack overflow";

  if (end == 0)
    end = new TListElem<T>(d);
  else
  {
    TListElem<T>* temp = new TListElem<T>(d); // создаем новый элемент списка от d
    temp->SetNext(end); // в качестве следующего указали end
    end = temp;
  }
  if (root == nullptr)
    root = end;
  count++;
}

template<class T>
void TList<T>::Ins(TListElem<T>* e, T d)
{
  // указанный элемент принадлежит списку
  TListElem<T>* temp = new TListElem<T>(d);
  temp->SetNext(e->GetNext()); // следующий от нового, который идет за e
  temp->SetPrev(e); // предыдущему нового положили e
  e->GetNext()->SetPrev(temp); // предыдущему, который идет за e, указали tmp
  e->SetNext(temp); // следущий за e ---> tmp
  count++;
}

template<class T>
TListElem<T>* TList<T>::GetFirst()
{
  return root;
}

template<class T>
TListElem<T>* TList<T>::GetLast()
{
  return end;
}

template<class T>
void TList<T>::DelFirst()
{
  // переопределяем корень и удаляем уже бывший корень
  TListElem<T>* i = root;
  root = root->GetNext();
  count--;
  delete i;
}

template<class T>
void TList<T>::DelLast()
{
  TListElem<T>* i = end;
  end = end->GetPrev();
  count--;
  delete i;
}

template<class T>
void TList<T>::Del(TListElem<T>* e)
{
  e->GetPrev()->SetNext(e->GetNext()); // следующий от предыдущего будет наш следующий
  e->GetNext()->SetPrev(e->GetPrev());
  count--;
  delete e;
}


template<class T>
bool TList<T>::IsFull() const
{
  try
  {
    TListElem<T>* temp = new TListElem<T>(1);
    delete temp;
    return false;
  }
  catch (...)
  {
    return true;
  }
}

template<class T>
bool TList<T>::IsEmpty() const
{
  return (count == 0);
}

template<class T>
int TList<T>::GetCount()
{
  return count;
}

template<class T>
TListElem<T>::TListElem(T _data)
{
  data = _data;
  next = nullptr;
  prev = nullptr;
}

template<class T>
TListElem<T>::~TListElem()
{
  next = nullptr;
  prev = nullptr;
}

template<class T>
T TListElem<T>::GetData()
{
  return data;
}

template<class T>
TListElem<T>* TListElem<T>::GetNext()
{
  return next;
}

template<class T>
TListElem<T>* TListElem<T>::GetPrev()
{
  return prev;
}

template<class T>
void TListElem<T>::SetData(T _data)
{
  data = _data;
}

template<class T>
void TListElem<T>::SetNext(TListElem<T>* _next)
{
  next = _next;
}

template<class T>
void TListElem<T>::SetPrev(TListElem<T>* _prev)
{
  prev = _prev;
}


