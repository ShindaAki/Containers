#ifndef S21_NODE_H
#define S21_NODE_H

#include <iostream>

namespace s21 {

template <typename T>
class list;

template <typename T>
class queue;

template <typename T>
class ListConstIterator;

template <typename T>
class ListIterator;

template <typename T>
struct Node_t {
  T val;
  Node_t *prev = nullptr;
  Node_t *next = nullptr;

  Node_t(T val_, Node_t *prev_ = nullptr, Node_t *next_ = nullptr)
      : val(val_), prev(prev_), next(next_) {}
};

}  // namespace s21

#endif
