#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include <initializer_list>

#include "../Node/s21_node.h"

namespace s21 {
template <typename T>
class queue {
 public:
  using element_type = T;
  using ref_type = T &;
  using const_ref_type = const T &;
  using size_type = size_t;
  using Node = Node_t<T>;

  queue();
  queue(std::initializer_list<element_type> const &items);
  queue(const queue &other_queue);
  queue(queue &&other_queue);
  ~queue();

  queue<T> &operator=(queue &&other_queue);
  queue<T> &operator=(const queue &other_queue);

  ref_type front();
  ref_type back();
  const_ref_type front() const;
  const_ref_type back() const;

  bool empty() const;
  size_type size() const;

  void push(const_ref_type value);
  void pop();
  void swap(queue &other);

  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  Node *top_;
  Node *bottom_;
  size_type size_;

  void clear();
};

};  // namespace s21

#include "s21_queue.tpp"

#endif