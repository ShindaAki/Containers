#ifndef S21_LIST_H
#define S21_LIST_H

#include <initializer_list>
#include <limits>

#include "../Node/s21_node.h"
#include "../list_iterator/s21_list_iterator.h"

namespace s21 {

template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  using Node = Node_t<T>;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &list);
  list(list &&list);
  ~list();

  list<T> &operator=(list &&list);
  list<T> &operator=(const list &list);

  reference front();
  reference back();
  const_reference front() const;
  const_reference back() const;

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
  template <typename... Args>
  void insert_many_front(Args &&...args);

 private:
  Node *head_ = nullptr;
  Node *tail_ = nullptr;
  size_type size_ = 0U;
  Node *end_;

  Node *CreateEnd();
};

};  // namespace s21

#include "s21_list.tpp"

#endif