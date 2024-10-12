#ifndef CPP2_SRC_CONTAINERS_MAP_S21
#define CPP2_SRC_CONTAINERS_MAP_S21

#include <vector>

#include "s21_RBTree.h"

namespace s21 {
template <typename KType, typename VType>
class Map {
 public:
  using k_type = KType;
  using mapType = VType;
  using value_type = std::pair<const k_type, mapType>;
  using size_type = size_t;
  using Allocator = std::allocator<KType>;
  using iterator = Iterator<KType, VType>;
  using const_iterator = ConstIterator<KType, VType>;
  bool isEmpty() { return tree_.IsEmpty(); }
  iterator find(const KType& key) { return iterator(tree_.Search(key)); };
  Map() : tree_() {}
  Map(std::initializer_list<value_type> const& items) {
    for (auto& item : items) {
      this->insert(item);
    }
  }
  Map(const Map& m) : tree_(m.tree_) {}
  Map(Map&& m) noexcept : tree_(std::move(m.tree_)) {}
  Map& operator=(const Map& m) {
    if (this != &m) {
      tree_ = m.tree_;
    }
    return *this;
  }
  Map& operator=(Map&& m) noexcept {
    if (this != &m) {
      tree_ = std::move(m.tree_);
    }
    return *this;
  }
  ~Map() {}

  std::pair<iterator, bool> insert(const value_type& value) {
    auto result = tree_.Insert(value.first, value.second);
    iterator it(result);
    return {it, false};
  }
  std::pair<iterator, bool> insert(const k_type& key, const mapType& obj) {
    return insert({key, obj});
  }
  void merge(Map& other) {
    if (this == &other) return;

    // Сохраняем указатель на элемент другого дерева перед очисткой
    for (Iterator<KType, VType> i = other.begin(); i != nullptr; i++) {
      // Сохраняем текущий элемент
      const KType& key = i.GetCurrent()->key_;
      const VType& value = i.GetCurrent()->value_;

      // Вставляем или обновляем элемент
      insert_or_assign(key, value);
    }

    // Освобождаем ресурсы у другого дерева
    other.clear();
    other.tree_.SetRoot(nullptr);
  }
  std::pair<iterator, bool> insert_or_assign(const KType& key,
                                             const VType& obj) {
    auto branch_search = tree_.Search(key);
    bool inserted = false;
    if (branch_search == nullptr) {
      branch_search = tree_.Insert(key, obj);
      inserted = true;
    } else {
      branch_search->second = obj;
    }
    return {iterator(branch_search), inserted};
  }
  iterator begin() { return tree_.begin(); }
  iterator end() { return tree_.end(); }
  bool empty() const { return tree_.IsEmpty(); }
  int size() { return tree_.GetSizeFriend(); }
  void clear() { tree_.Clear(tree_.GetRoot()); }
  mapType& operator[](const k_type& key) {
    auto tmp = tree_.Search(key);
    if (tmp == nullptr) {
      auto res = tree_.Insert(key, mapType());
      return res->value_;
    }
    return tmp->value_;
  }
  mapType& at(const k_type& key) {
    auto tmp = find(key);
    if (tmp == end() || tmp == nullptr) {
      throw std::out_of_range("Index out of range");
    }
    return (tmp->second);
  }
  void erase(iterator pos) {
    if (pos != nullptr) {
      tree_.Remove_node(tree_.GetRoot(), pos.GetCurrent()->key_);
    }
  }
  size_type max_size() const { return Allocator().max_size(); }
  bool contains(const KType& key) {
    bool result = (tree_.Search(key) != nullptr);
    return result;
  }
  void swap(Map& other) noexcept { tree_.Swap(other.tree_); }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
    std::vector<std::pair<iterator, bool>> results;
    insert_many_helper(results, std::forward<Args>(args)...);
    return results;
  }

  template <typename... Args>
  void insert_many_helper(std::vector<std::pair<iterator, bool>>& results,
                          KType key, VType value, Args&&... args) {
    auto result = insert({key, value});
    results.emplace_back(result);
    if constexpr (sizeof...(args) > 0) {
      insert_many_helper(results, std::forward<Args>(args)...);
    }
  }

 private:
  RBTree<k_type, mapType> tree_;
};

}  // namespace s21
#endif  // CPP2_SRC_CONTAINERS_MAP_S21
