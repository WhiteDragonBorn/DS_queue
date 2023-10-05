/* Очередь(queue) First In First Out
  Реализация на односвязном списке, но при этом держать указатель на tail.
*/

#include <iostream>
typedef int datatype;

class TQueue {
  struct Node {
    datatype data;
    Node* next;
    Node(const datatype& elem) {
      data = elem;
      next = nullptr;
    }
  };
  Node *head, *tail;
  void clear();
  bool isEmpty();

 public:
  TQueue() : head(nullptr), tail(nullptr) {}
  ~TQueue() { clear(); }
  void enque(const datatype&);
  void deque();
  datatype peek();
};

void TQueue::enque(const datatype& elem) {
  if (tail) {
    tail->next = new Node(elem);
    tail = tail->next;
  } else {
    tail = new Node(elem);
    head = tail;
  }
}

void TQueue::deque() {
  Node* p = head;
  head = head->next;
  p->next = nullptr;
  delete p;
  p = nullptr;
}

datatype TQueue::peek() { return head->data; }

bool TQueue::isEmpty() { return head == nullptr; }

void TQueue::clear() {
  while (!isEmpty()) {
    deque();
  }
}

int main() { std::cout << "Hello World!\n"; }
