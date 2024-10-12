#ifndef STACK_S21_STACK_H_
#define STACK_S21_STACK_H_
#include "vector/s21_vector.h"
namespace s21 {

template <class T>
class stack {
 public:
  struct Node {
    T data;
    Node* next = nullptr;
  };

  stack() = default;

  stack(const stack& other) : stack() { copy(other); }

  stack(stack&& other) : stack() { swap(other); }

  ~stack() { clear(); }

  stack<T>& operator=(const stack& other) {
    if (this != &other) {
      clear();
      copy(other);
    }
    return *this;
  }

  const T& top() const {
    if (empty()) {
      throw std::out_of_range("Error: Empty stack");
    }
    return base->data;
  }
  stack(std::initializer_list<T> init) : stack() {
    for (const auto& value : init) {
      push(value);
    }
  }

  bool empty() const { return size_ == 0; }

  size_t size() const { return size_; }

  void push(const T& value) {
    Node* node = new Node{value};
    node->next = base;
    base = node;
    size_++;
  }

  void pop() {
    if (empty()) {
      throw std::out_of_range("Error: Empty stack");
    }
    Node* node = base->next;
    delete base;
    base = node;
    size_--;
  }

  void swap(stack& other) {
    using std::swap;
    swap(base, other.base);
    swap(size_, other.size_);
  }

  template <class... Args>
  void emplace(Args&&... args) {
    push(T(std::forward<Args>(args)...));
  }

  void clear() {
    while (!empty()) {
      pop();
    }
  }

  void copy(const stack& other) {
    clear();
    Node* node = other.base;
    stack temp_stack;
    while (node) {
      temp_stack.push(node->data);
      node = node->next;
    }
    while (!temp_stack.empty()) {
      push(temp_stack.top());
      temp_stack.pop();
    }
  }
  template <class... Args>
  void insert_many_front(Args&&... args) {
    s21::Vector<T> values = {std::forward<Args>(args)...};

    stack<T> temp_stack;

    for (const auto& value : values) {
      this->push(value);
    }
  }

 private:
  Node* base = nullptr;
  size_t size_ = 0;
};

}  // namespace s21

#endif  // STACK_S21_STACK_H_