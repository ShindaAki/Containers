#ifndef S21_VECTOR_H_
#define S21_VECTOR_H_
namespace s21 {
template <typename T>
class Vector {
 public:
  class Iterator {
   public:
    Iterator() : ptr(nullptr){};
    Iterator(T* ptr) : ptr(ptr){};
    Iterator(const Iterator& other) : ptr(other.ptr){};
    Iterator(Iterator&& other) : ptr(other.ptr) { other.ptr = nullptr; };
    Iterator& operator=(const Iterator& other) {
      if (this != &other) {
        ptr = other.ptr;
      }
      return *this;
    };
    Iterator& operator=(Iterator&& other) {
      if (this != &other) {
        ptr = other.ptr;
        other.ptr = nullptr;
      }
      return *this;
    };
    ~Iterator() { ptr = nullptr; };
    Iterator operator-(size_t n) {
      Iterator buff(*this);
      for (size_t it = 0; it < n; it++) {
        buff--;
      }
      return buff;
    };
    ptrdiff_t operator-(const Iterator& other) { return ptr - other.ptr; }
    Iterator operator+(size_t n) {
      Iterator buff(*this);
      for (size_t it = 0; it < n; it++) {
        buff++;
      }
      return buff;
    };
    Iterator& operator-=(size_t n) {
      ptr = ptr - n;
      return *this;
    };
    Iterator& operator+=(size_t n) {
      ptr = ptr + n;
      return *this;
    };
    Iterator operator--(int) {
      ErrorCheck(ptr);
      Iterator buff(*this);
      --ptr;
      return buff;
    };
    Iterator operator--() {
      ErrorCheck(ptr);
      --ptr;
      return *this;
    };
    Iterator operator++(int) {
      ErrorCheck(ptr);
      Iterator buff(*this);
      ++ptr;
      return buff;
    };
    Iterator operator++() {
      ErrorCheck(ptr);
      ++ptr;
      return *this;
    };
    T& operator*() { return *ptr; };
    bool operator==(const Iterator& other) const { return ptr == other.ptr; };
    bool operator!=(const Iterator& other) const { return !(*this == other); }
    bool operator>(const Iterator& other) const { return (ptr > other.ptr); }
    bool operator<(const Iterator& other) const { return (ptr < other.ptr); }
    bool operator<=(const Iterator& other) const { return (ptr <= other.ptr); }
    bool operator>=(const Iterator& other) const { return (ptr >= other.ptr); }

   private:
    T* ptr;
    void ErrorCheck(T* ptr) {
      if (!ptr) throw std::out_of_range("out of range");
    };
  };
  class ConstIterator {
   public:
    ConstIterator() : ptr(nullptr){};
    ConstIterator(const T* ptr) : ptr(ptr){};
    ConstIterator(const ConstIterator& other) : ptr(other.ptr){};
    ConstIterator(ConstIterator&& other) : ptr(other.ptr) {
      other.ptr = nullptr;
    };
    ConstIterator& operator=(const ConstIterator& other) {
      if (this != &other) {
        ptr = other.ptr;
      }
      return *this;
    };
    ConstIterator& operator=(ConstIterator&& other) {
      if (this != &other) {
        ptr = other.ptr;
        other.ptr = nullptr;
      }
      return *this;
    };
    ~ConstIterator() { ptr = nullptr; };
    ConstIterator operator-(size_t n) {
      ConstIterator buff(*this);
      for (size_t it = 0; it < n; it++) {
        buff--;
      }
      return buff;
    };
    ptrdiff_t operator-(const ConstIterator& other) { return ptr - other.ptr; }
    ConstIterator operator+(size_t n) {
      ConstIterator buff(*this);
      for (size_t it = 0; it < n; it++) {
        buff++;
      }
      return buff;
    };
    ConstIterator& operator-=(size_t n) {
      ptr = ptr - n;
      return *this;
    };
    ConstIterator& operator+=(size_t n) {
      ptr = ptr + n;
      return *this;
    };
    ConstIterator operator--(int) {
      ErrorCheck(ptr);
      ConstIterator buff(*this);
      --ptr;
      return buff;
    };
    ConstIterator operator--() {
      ErrorCheck(ptr);
      --ptr;
      return *this;
    };
    ConstIterator operator++(int) {
      ErrorCheck(ptr);
      ConstIterator buff(*this);
      ++ptr;
      return buff;
    };
    ConstIterator operator++() {
      ErrorCheck(ptr);
      ++ptr;
      return *this;
    };
    const T& operator*() { return *ptr; };
    bool operator==(const ConstIterator& other) const {
      return ptr == other.ptr;
    };
    bool operator!=(const ConstIterator& other) const {
      return !(*this == other);
    }
    bool operator>(const ConstIterator& other) const {
      return (ptr > other.ptr);
    }
    bool operator<(const ConstIterator& other) const {
      return (ptr < other.ptr);
    }
    bool operator<=(const ConstIterator& other) const {
      return (ptr <= other.ptr);
    }
    bool operator>=(const ConstIterator& other) const {
      return (ptr >= other.ptr);
    }

   private:
    const T* ptr;
    void ErrorCheck(const T* ptr) {
      if (!ptr) throw std::out_of_range("out of range");
    };
  };
  // Member type
  using element_type = T;
  using ref_type = T&;
  using const_ref_type = const T&;
  using iterator = s21::Vector<T>::Iterator;
  using raw_pointer = T*;
  using const_normal_iterator = s21::Vector<T>::ConstIterator;
  using count_type = std::size_t;

  // Member functions
  Vector();
  Vector(count_type n);
  Vector(std::initializer_list<element_type> const& items);
  Vector(const Vector& v);
  Vector(Vector&& v);
  ~Vector();
  Vector<T>& operator=(const Vector& other);
  Vector<T>& operator=(Vector&& other);
  // Element access
  ref_type at(count_type pos);
  ref_type operator[](count_type pos) const;
  const_ref_type front() const;
  const_ref_type back() const;
  raw_pointer data() const;
  // Iterators
  iterator begin() const;
  const_normal_iterator cbegin() const;
  iterator end() const;
  const_normal_iterator cend() const;
  // Capacity
  bool empty() const;
  count_type size() const;
  count_type max_size() const;
  void reserve(count_type size);
  count_type capacity() const;
  void shrink_to_fit();
  // Modifiers_
  void clear();
  iterator insert(iterator pos, const_ref_type value);
  void erase(iterator pos);
  void push_back(const_ref_type value);
  void pop_back();
  void swap(Vector& other);
  // Bonus
  template <typename... Args>
  iterator insert_many(const_normal_iterator pos, Args&&... args);
  template <typename... Args>
  void insert_many_back(Args&&... args);

 private:
  raw_pointer vect_;
  count_type scale_;
  count_type maxscale_;
};
};  // namespace s21
#include "s21_vector.tpp"
#endif  // S21_VECTOR_H_