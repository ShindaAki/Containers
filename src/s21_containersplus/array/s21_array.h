#ifndef CPP2_CONTAINERS_S21_ARRAY_H_
#define CPP2_CONTAINERS_S21_ARRAY_H_
namespace s21 {
template <typename T>
class array {
 public:
  class ArrIterator {
   public:
    ArrIterator() : our_ptr_(nullptr){};
    ArrIterator(T* ptr) : our_ptr_(ptr){};
    ArrIterator(const ArrIterator& other) : our_ptr_(other.our_ptr_){};
    ArrIterator(ArrIterator&& other) : our_ptr_(other.our_ptr_) {
      other.our_ptr_ = nullptr;
    };
    ArrIterator& operator=(const ArrIterator& other) {
      if (this != &other) {
        our_ptr_ = other.our_ptr_;
      }
      return *this;
    };
    ArrIterator& operator=(ArrIterator&& other) {
      if (this != &other) {
        our_ptr_ = other.our_ptr_;
        other.our_ptr_ = nullptr;
      }
      return *this;
    };
    ~ArrIterator() { our_ptr_ = nullptr; };
    // operators
    ArrIterator operator-(size_t n) {
      ArrIterator buff(*this);
      for (size_t it = 0; it < n; it++) {
        buff--;
      }
      return buff;
    };
    ptrdiff_t operator-(const ArrIterator& other) {
      return our_ptr_ - other.our_ptr_;
    }
    ArrIterator operator+(size_t n) {
      ArrIterator buff(*this);
      for (size_t it = 0; it < n; it++) {
        buff++;
      }
      return buff;
    };
    ArrIterator& operator-=(size_t n) {
      our_ptr_ = our_ptr_ - n;
      return *this;
    };
    ArrIterator& operator+=(size_t n) {
      our_ptr_ = our_ptr_ + n;
      return *this;
    };
    ArrIterator operator--(int) {
      ErrorCheck(our_ptr_);
      ArrIterator buff(*this);
      --our_ptr_;
      return buff;
    };
    ArrIterator operator--() {
      ErrorCheck(our_ptr_);
      --our_ptr_;
      return *this;
    };
    ArrIterator operator++(int) {
      ErrorCheck(our_ptr_);
      ArrIterator buff(*this);
      ++our_ptr_;
      return buff;
    };
    ArrIterator operator++() {
      ErrorCheck(our_ptr_);
      ++our_ptr_;
      return *this;
    };
    T& operator*() { return *our_ptr_; };
    bool operator==(const ArrIterator& other) const {
      return our_ptr_ == other.our_ptr_;
    };
    bool operator!=(const ArrIterator& other) const {
      return !(*this == other);
    }
    bool operator>(const ArrIterator& other) const {
      return (our_ptr_ > other.our_ptr_);
    }
    bool operator<(const ArrIterator& other) const {
      return (our_ptr_ < other.our_ptr_);
    }
    bool operator<=(const ArrIterator& other) const {
      return (our_ptr_ <= other.our_ptr_);
    }
    bool operator>=(const ArrIterator& other) const {
      return (our_ptr_ >= other.our_ptr_);
    }

   private:
    T* our_ptr_;
    void ErrorCheck(T* our_ptr_) {
      if (!our_ptr_) throw std::out_of_range("out of range");
    };
  };
  class ConstArrIterator {
   public:
    ConstArrIterator() : our_ptr_(nullptr){};
    ConstArrIterator(const T* ptr) : our_ptr_(ptr){};
    ConstArrIterator(const ConstArrIterator& other)
        : our_ptr_(other.our_ptr_){};
    ConstArrIterator(ConstArrIterator&& other) : our_ptr_(other.our_ptr_) {
      other.our_ptr_ = nullptr;
    };
    ConstArrIterator& operator=(const ConstArrIterator& other) {
      if (this != &other) {
        our_ptr_ = other.our_ptr_;
      }
      return *this;
    };
    ConstArrIterator& operator=(ConstArrIterator&& other) {
      if (this != &other) {
        our_ptr_ = other.our_ptr_;
        other.our_ptr_ = nullptr;
      }
      return *this;
    };
    ~ConstArrIterator() { our_ptr_ = nullptr; };
    // operator
    ConstArrIterator operator-(size_t n) {
      ConstArrIterator buff(*this);
      for (size_t it = 0; it < n; it++) {
        buff--;
      }
      return buff;
    };
    ptrdiff_t operator-(const ConstArrIterator& other) {
      return our_ptr_ - other.our_ptr_;
    }
    ConstArrIterator operator+(size_t n) {
      ConstArrIterator buff(*this);
      for (size_t it = 0; it < n; it++) {
        buff++;
      }
      return buff;
    };
    ConstArrIterator& operator-=(size_t n) {
      our_ptr_ = our_ptr_ - n;
      return *this;
    };
    ConstArrIterator& operator+=(size_t n) {
      our_ptr_ = our_ptr_ + n;
      return *this;
    };
    ConstArrIterator operator--(int) {
      ErrorCheck(our_ptr_);
      ConstArrIterator buff(*this);
      --our_ptr_;
      return buff;
    };
    ConstArrIterator operator--() {
      ErrorCheck(our_ptr_);
      --our_ptr_;
      return *this;
    };
    ConstArrIterator operator++(int) {
      ErrorCheck(our_ptr_);
      ConstArrIterator buff(*this);
      ++our_ptr_;
      return buff;
    };
    ConstArrIterator operator++() {
      ErrorCheck(our_ptr_);
      ++our_ptr_;
      return *this;
    };
    const T& operator*() { return *our_ptr_; };
    bool operator==(const ConstArrIterator& other) const {
      return our_ptr_ == other.our_ptr_;
    };
    bool operator!=(const ConstArrIterator& other) const {
      return !(*this == other);
    }
    bool operator>(const ConstArrIterator& other) const {
      return (our_ptr_ > other.our_ptr_);
    }
    bool operator<(const ConstArrIterator& other) const {
      return (our_ptr_ < other.our_ptr_);
    }
    bool operator<=(const ConstArrIterator& other) const {
      return (our_ptr_ <= other.our_ptr_);
    }
    bool operator>=(const ConstArrIterator& other) const {
      return (our_ptr_ >= other.our_ptr_);
    }

   private:
    const T* our_ptr_;
    void ErrorCheck(const T* our_ptr_) {
      if (!our_ptr_) throw std::out_of_range("out of range");
    };
  };
  using element_type = T;
  using ref_type = T&;
  using const_ref_type = const T&;
  using iterator = s21::array<T>::ArrIterator;
  using raw_pointer = T*;
  using const_normal_iterator = s21::array<T>::ConstArrIterator;
  using count_type = std::size_t;

  array();
  array(std::initializer_list<element_type> const& other);
  array(const array& other);
  array(array&& other);
  ~array();
  array<T>& operator=(const array& other);
  array<T>& operator=(array&& other);
  ref_type at(count_type pos);
  ref_type operator[](count_type pos) const;
  const_ref_type front() const;
  const_ref_type back() const;
  raw_pointer data();
  iterator begin() const;
  const_normal_iterator cbegin() const;
  iterator end() const;
  const_normal_iterator cend() const;
  bool empty();
  count_type size() const;
  count_type max_size() const;
  void swap(array& other);
  void fill(const_ref_type value);

 private:
  raw_pointer arr_;
  count_type scale_;
};
};  // namespace s21
#include "s21_array.tpp"
#endif  // CPP2_CONTAINERS_S21_ARRAY_H_