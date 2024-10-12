namespace s21 {
template <typename T>
Vector<T>::Vector() : vect_(nullptr), scale_(0), maxscale_(0) {}

template <typename T>
Vector<T>::Vector(count_type n)
    : vect_(new element_type[n]), scale_(n), maxscale_(n) {
  for (count_type i = 0; i < n; i++) {
    vect_[i] = element_type();
  }
}

template <typename T>
Vector<T>::Vector(Vector&& other) {
  vect_ = other.vect_;
  scale_ = other.scale_;
  maxscale_ = other.maxscale_;
  other.vect_ = nullptr;
  other.scale_ = 0;
  other.maxscale_ = 0;
}

template <typename T>
Vector<T>::~Vector() {
  if (vect_ != nullptr) delete[] vect_;
  vect_ = nullptr;
  scale_ = 0;
  maxscale_ = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
  if (this != &other) {
    if (vect_ != nullptr) delete[] vect_;
    vect_ = new element_type[other.scale_];
    scale_ = other.scale_;
    maxscale_ = other.maxscale_;
    std::copy(other.vect_, other.vect_ + other.scale_, vect_);
  }
  return *this;
}
template <typename T>
Vector<T>::Vector(std::initializer_list<element_type> const& other) {
  vect_ = new element_type[other.size()];
  scale_ = other.size();
  maxscale_ = other.size();
  std::copy(other.begin(), other.end(), vect_);
}

template <typename T>
Vector<T>::Vector(const Vector& other) {
  vect_ = new element_type[other.scale_];
  scale_ = other.scale_;
  maxscale_ = other.maxscale_;
  std::copy(other.vect_, other.vect_ + other.scale_, vect_);
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) {
  if (this != &other) {
    if (vect_ != nullptr) delete[] vect_;
    maxscale_ = other.maxscale_;
    scale_ = other.scale_;
    vect_ = other.vect_;
    other.vect_ = nullptr;
    other.maxscale_ = 0;
    other.scale_ = 0;
  }
  return *this;
};

// Element access
template <typename T>
typename Vector<T>::ref_type Vector<T>::at(count_type pos) {
  if (pos >= maxscale_) throw std::out_of_range("out of range");
  return vect_[pos];
}

template <typename T>
typename Vector<T>::ref_type Vector<T>::operator[](count_type pos) const {
  if (pos > scale_) throw std::out_of_range("out of range");
  return vect_[pos];
}

template <typename T>
typename Vector<T>::const_ref_type Vector<T>::front() const {
  if (vect_ == nullptr) throw std::out_of_range("out of range");
  return vect_[0];
}

template <typename T>
typename Vector<T>::const_ref_type Vector<T>::back() const {
  if (vect_ == nullptr) throw std::out_of_range("out of range");
  return vect_[scale_ - 1];
}

template <typename T>
typename Vector<T>::raw_pointer Vector<T>::data() const {
  return vect_;
}

// Iterators

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() const {
  return vect_;
}

template <typename T>
typename Vector<T>::const_normal_iterator Vector<T>::cbegin() const {
  return vect_;
}
template <typename T>
typename Vector<T>::iterator Vector<T>::end() const {
  return vect_ + scale_;
}

template <typename T>
typename Vector<T>::const_normal_iterator Vector<T>::cend() const {
  return vect_ + scale_;
}
// Capacity
template <typename T>
bool Vector<T>::empty() const {
  return scale_ == 0;
}

template <typename T>
typename Vector<T>::count_type Vector<T>::size() const {
  return scale_;
}

template <typename T>
typename Vector<T>::count_type Vector<T>::max_size() const {
  return std::numeric_limits<size_t>::max() / sizeof(T);
}

template <typename T>
void Vector<T>::reserve(count_type size) {
  if (size <= maxscale_) {
    return;
  }
  if (size > max_size()) {
    throw std::out_of_range("out of range");
  }
  element_type* new_container = new element_type[size];
  std::copy(vect_, vect_ + scale_, new_container);
  delete[] vect_;
  vect_ = new_container;
  maxscale_ = size;
}

template <typename T>
typename Vector<T>::count_type Vector<T>::capacity() const {
  return maxscale_;
}

template <typename T>
void Vector<T>::shrink_to_fit() {
  maxscale_ = maxscale_ - (maxscale_ - scale_);
}

// Modifiers
template <typename T>
void Vector<T>::clear() {
  scale_ = 0;
}

template <typename T>
void Vector<T>::push_back(const_ref_type value) {
  if (scale_ >= maxscale_) {
    reserve(maxscale_ ? maxscale_ * 2 : 1);
  }
  vect_[scale_++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
  if (scale_ > 0) {
    --scale_;
  }
}

template <typename T>
typename Vector<T>::iterator Vector<T>::insert(iterator pos,
                                               const_ref_type value) {
  if (pos > end()) throw std::out_of_range("out of range");
  count_type index = pos - begin();
  if (scale_ >= maxscale_) {
    reserve(maxscale_ ? maxscale_ * 2 : 1);
  }
  iterator res = begin() + index;
  for (iterator i = end(); i != res - 1; --i) {
    if (i == res)
      *res = value;
    else
      *i = *(i - 1);
  }
  scale_++;
  return res;
}

template <typename T>
void Vector<T>::erase(iterator pos) {
  if (pos >= end()) throw std::out_of_range("out of range");
  for (iterator it = pos; it != end() - 1; ++it) {
    *it = *(it + 1);
  }
  --scale_;
}

template <typename T>
void Vector<T>::swap(Vector& other) {
  std::swap(vect_, other.vect_);
  std::swap(scale_, other.scale_);
  std::swap(maxscale_, other.maxscale_);
}

template <typename T>
template <typename... Args>
typename Vector<T>::iterator Vector<T>::insert_many(const_normal_iterator pos,
                                                    Args&&... args) {
  Vector<element_type> buffer{args...};
  iterator buffer_pos = begin() + (pos - cbegin());
  for (count_type i = 0; i < buffer.size(); i++) {
    buffer_pos = insert(buffer_pos, buffer[i]);
    buffer_pos++;
  }
  return buffer_pos;
}

template <typename T>
template <typename... Args>
void Vector<T>::insert_many_back(Args&&... args) {
  Vector<element_type> buffer{args...};
  for (count_type i = 0; i < buffer.size(); i++) {
    push_back(buffer[i]);
  }
}

};  // namespace s21