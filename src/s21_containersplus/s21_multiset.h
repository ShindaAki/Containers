#ifndef CPP2_S21_CONTAINERSPLUS_MULTISET
#define CPP2_S21_CONTAINERSPLUS_MULTISET

namespace s21 {
template <class KeyValue>
class Multiset : public Set<KeyValue> {
 public:
  using key_type = KeyValue;
  using value_type = typename Set<key_type>::value_type;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename Set<key_type>::iterator;
  using const_iterator = typename Set<key_type>::const_iterator;
  using size_type = typename Set<key_type>::size_type;
  using node_type = Branch<KeyValue, KeyValue>;
  using node_pointer = node_type*;

 public:
  Multiset() : Set<key_type>() { this->tree_.SetRepated(true); }
  Multiset(const Multiset& other) : Set<key_type>(other) {}

  Multiset& operator=(const Multiset& other) {
    if (this != &other) {
      this->tree_.SetRepated(true);
      this->tree_ = other.tree_;
    }
    return *this;
  }

  Multiset(Multiset&& other) noexcept {
    Set<KeyValue>();
    this->tree_.SetRepated(true);

    *this = std::move(other);
  }

  Multiset& operator=(Multiset&& other) noexcept {
    this->clear();
    if (this == &other) return *this;
    this->tree_.SetRepated(true);
    Set<key_type>::operator=(std::move(other));
    return *this;
  }

  Multiset(std::initializer_list<key_type> const& items) : Set<key_type>() {
    this->tree_.SetRepated(true);
    for (auto it = items.begin(); it != items.end(); it++) {
      this->insert(*it);
    }
  }

  std::pair<iterator, bool> insert(const KeyValue& key) {
    auto branch_insert = this->tree_.Insert(key, 0);  // Метод вставки в дерево
    iterator it(
        branch_insert);  // Создаем итератор на основе результата вставки

    // Предположим, что Insert возвращает nullptr, если был дубликат.
    bool is_inserted = (branch_insert != nullptr);  // Успешно ли была вставка
    return std::make_pair(it, is_inserted);
  }

  size_type count(const key_type& key) {
    size_type count = 0;
    for (auto it = this->tree_.begin(); it != nullptr; it++) {
      if (it.GetCurrent()->key_ == key) {
        count++;
      }
    }
    return count;
  }

  iterator lower_bound(const key_type& key) {
    auto it = this->tree_.begin();
    for (; it != nullptr; it++) {
      if (it.GetCurrent()->key_ >= key) {
        return it;
      }
    }
    return it;
  }

  iterator upper_bound(const key_type& key) {
    auto it = this->tree_.begin();
    for (; it != nullptr; it++) {
      if (it.GetCurrent()->key_ > key) {
        return it;
      }
    }
    return this->tree_.end();
  }

  std::pair<iterator, iterator> equal_range(const key_type& key) {
    iterator lower = this->lower_bound(key);
    iterator higher = this->upper_bound(key);
    return {lower, higher};
  }

  node_pointer GetRoot() { return this->tree_.GetRoot(); }

  template <typename... Args>
  std::vector<std::pair<typename Multiset::iterator, bool>> insert_many(
      Args&&... args) {
    std::vector<std::pair<typename Multiset::iterator, bool>> res;

    // Используем инициализацию списка для прохода по всем переданным аргументам
    (res.emplace_back(this->insert(args)),
     ...);  // Используем emplace_back для добавления пар

    return res;
  }
};

}  // namespace s21
#endif  // CPP2_S21_CONTAINERSPLUS_MULTISET