#include <iostream>
#include "stacklist.h"
#include "queuelist.h"

int main()
{
  TStackList<int> s;
  TQueueList<int> q;

  s.Put(10);
  s.Put(11);
  q.Put(10);
  q.Put(11);

  std::cout << s.Get() << "\n"; // выводим вершину стека
  std::cout << q.Get() << "\n"; // выводим вершину очереди

  return 0;
}
