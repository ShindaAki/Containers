namespace s21 {
template <typename T>
array<T>::array() : arr_(nullptr), scale_(0){};
template <typename T>
array<T>::array(std::initializer_list<element_type> const& other) {
  arr_ = new element_type[other.size()];
  scale_ = other.size();
  std::copy(other.begin(), other.begin() + other.size(), arr_);
};
template <typename T>
array<T>::array(const array& other) {
  arr_ = new element_type[other.scale_];
  scale_ = other.scale_;
  std::copy(other.arr_, other.arr_ + other.scale_, arr_);
};
template <typename T>
array<T>::array(array&& other) {
  arr_ = other.arr_;
  scale_ = other.scale_;
  other.arr_ = nullptr;
  other.scale_ = 0;
};
template <typename T>
array<T>::~array() {
  if (arr_ != nullptr) delete[] arr_;
  scale_ = 0;
};
template <typename T>
array<T>& array<T>::operator=(const array& other) {
  if (this != &other) {
    if (arr_ != nullptr) delete[] arr_;
    arr_ = new element_type[other.scale_];
    scale_ = other.scale_;
    std::copy(other.arr_, other.arr_ + other.scale_, arr_);
  }
  return *this;
};

template <typename T>
array<T>& array<T>::operator=(array&& other) {
  if (this != &other) {
    if (arr_ != nullptr) delete[] arr_;
    arr_ = other.arr_;
    scale_ = other.scale_;
    other.arr_ = nullptr;
    other.scale_ = 0;
  }
  return *this;
};
template <typename T>
typename array<T>::ref_type array<T>::at(count_type pos) {
  if (pos >= scale_) throw std::out_of_range("out of range");
  return arr_[pos];
};
template <typename T>
typename array<T>::ref_type array<T>::operator[](count_type pos) const {
  if (pos >= scale_) throw std::out_of_range("out of range");
  return arr_[pos];
};
template <typename T>
typename array<T>::const_ref_type array<T>::front() const {
  if (arr_ == nullptr) throw std::out_of_range("out of range");
  return arr_[0];
};
template <typename T>
typename array<T>::const_ref_type array<T>::back() const {
  if (arr_ == nullptr) throw std::out_of_range("out of range");
  return arr_[scale_ - 1];
};
template <typename T>
typename array<T>::raw_pointer array<T>::data() {
  return arr_;
};
template <typename T>
typename array<T>::iterator array<T>::begin() const {
  return arr_;
};
template <typename T>
typename array<T>::iterator array<T>::end() const {
  return arr_ + scale_;
};
template <typename T>
typename array<T>::const_normal_iterator array<T>::cbegin() const {
  return arr_;
};
template <typename T>
typename array<T>::const_normal_iterator array<T>::cend() const {
  return arr_ + scale_;
};
template <typename T>
bool array<T>::empty() {
  return scale_ == 0;
};
template <typename T>
typename array<T>::count_type array<T>::size() const {
  return scale_;
};
template <typename T>
typename array<T>::count_type array<T>::max_size() const {
  return scale_;
};
template <typename T>
void array<T>::swap(array& other) {
  std::swap(scale_, other.scale_);
  std::swap(arr_, other.arr_);
};
template <typename T>
void array<T>::fill(const_ref_type value) {
  for (count_type i = 0; i < size(); i++) {
    arr_[i] = value;
  }
};
};  // namespace s21