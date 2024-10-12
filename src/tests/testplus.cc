#include "test.h"

TEST(MultisetTest, copy_operator_01) {
  s21::Multiset<char> multiset_2({'J', 'J', 'J', 'J', 'J', 'J', 'J'});
  EXPECT_EQ(multiset_2.GetRoot()->scale_, 7);
}

TEST(MultisetTest, copy_operator_02) {
  s21::Multiset<int> multiset_1({1, 2, 1});
  s21::Multiset<int> multiset_2;

  std::multiset<int> orignal_multiset_1({1, 2, 1});
  std::multiset<int> orignal_multiset_2;

  EXPECT_EQ(multiset_1.size(), 3);

  multiset_1 = multiset_2;
  orignal_multiset_1 = orignal_multiset_2;
  EXPECT_EQ(multiset_1.size(), (int)orignal_multiset_1.size());
  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);
}

TEST(MultisetTest, copy_operator_05) {
  s21::Multiset<int> multiset_1;
  s21::Multiset<int> multiset_2;

  EXPECT_EQ(multiset_1.size(), 0);

  multiset_1 = multiset_2;
  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);
}

TEST(MultisetTest, copy_operator_03) {
  s21::Multiset<int> multiset_1({1, 2, 2});
  s21::Multiset<int> multiset_2({11, 22, 33, 11});

  EXPECT_EQ(multiset_1.size(), 3);
  EXPECT_EQ(multiset_2.size(), 4);

  multiset_1 = multiset_2;
  EXPECT_EQ(multiset_1.size(), 4);
  EXPECT_EQ(multiset_2.size(), 4);

  auto it = multiset_1.begin();
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 22);
  ++it;
  EXPECT_EQ(*it, 33);
  it = multiset_1.begin();
  auto it_2 = multiset_2.begin();
  for (; it != nullptr; ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(MultisetTest, test_count) {
  s21::Multiset<int> multiset_1({1, 1, 3, 4, 5, 6, 7, 8, 4, 10, 4, 12});
  std::multiset<int> orignal_multiset_1({1, 1, 3, 4, 5, 6, 7, 8, 4, 10, 4, 12});
  EXPECT_EQ(multiset_1.size(), 12);

  auto res_test_1 = multiset_1.count(4);

  EXPECT_EQ(res_test_1, (size_t)3);
  auto orig_test_1 = orignal_multiset_1.count(4);
  EXPECT_EQ(res_test_1, orig_test_1);

  res_test_1 = multiset_1.count(1);
  EXPECT_EQ(res_test_1, (size_t)2);
  orig_test_1 = orignal_multiset_1.count(1);
  EXPECT_EQ(res_test_1, orig_test_1);

  res_test_1 = multiset_1.count(50);
  EXPECT_EQ(res_test_1, (size_t)0);
  orig_test_1 = orignal_multiset_1.count(50);
  EXPECT_EQ(res_test_1, orig_test_1);
}

TEST(MultisetTest, move_constr) {
  s21::Multiset<int> multiset_1({5, 3, 1, 2, 2, 5});
  EXPECT_EQ(multiset_1.size(), 6);
  s21::Multiset<int> multiset_2(std::move(multiset_1));

  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 6);

  std::multiset<int> orignal_multiset_1({5, 3, 1, 2, 2, 5});

  auto it = multiset_2.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 5);

  it = multiset_2.begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != nullptr; ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(MultisetTest, move_operator) {
  s21::Multiset<int> multiset_1({1, 2, 2});
  EXPECT_EQ(multiset_1.size(), 3);
  s21::Multiset<int> multiset_2({11, 22, 33, 11});
  EXPECT_EQ(multiset_2.size(), 4);

  multiset_1 = std::move(multiset_2);

  EXPECT_EQ(multiset_1.size(), 4);
  EXPECT_EQ(multiset_2.size(), 0);

  auto it = multiset_1.begin();
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 22);
  ++it;
  EXPECT_EQ(*it, 33);
}

TEST(MultisetTest, move_operator_05) {
  s21::Multiset<int> multiset_1({5, 3, 1, 2, 2, 2});
  s21::Multiset<int> multiset_2({11, 22, 33, 11});
  std::multiset<int> orignal_multiset_1({5, 3, 1, 2, 2, 2});
  std::multiset<int> orignal_multiset_2({11, 22, 33, 11});
  multiset_2 = std::move(multiset_1);
  orignal_multiset_2 = std::move(orignal_multiset_1);
  s21::Multiset<int>::iterator it = multiset_2.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 5);
  it = multiset_2.begin();
  auto it_2 = orignal_multiset_2.begin();
  for (; it != multiset_2.end() && it_2 != orignal_multiset_2.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(MultisetTest, move_operator_02) {
  s21::Multiset<int> multiset_1({1, 2, 1});
  s21::Multiset<int> multiset_2({11, 22, 33, 11});
  multiset_2 = std::move(multiset_1);
  auto it = multiset_2.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(MultisetTest, move_operator_03) {
  s21::Multiset<int> multiset_1;
  EXPECT_EQ(multiset_1.size(), 0);
  s21::Multiset<int> multiset_2;
  EXPECT_EQ(multiset_2.size(), 0);
  multiset_2 = std::move(multiset_1);
  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);
}

TEST(MultisetTest, move_operator_04) {
  s21::Multiset<int> multiset_1({1, 2});
  EXPECT_EQ(multiset_1.size(), 2);
  s21::Multiset<int> multiset_2;
  EXPECT_EQ(multiset_2.size(), 0);
  multiset_1 = std::move(multiset_2);
  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);
}

TEST(MultisetTest, test_empty) {
  s21::Multiset<int> multiset_1({2, 4, 6, 8});
  s21::Multiset<int> multiset_2;
  EXPECT_EQ(multiset_1.empty(), false);
  EXPECT_EQ(multiset_2.empty(), true);
}

TEST(MultisetTest, test_size) {
  s21::Multiset<double> multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 5.5});
  std::multiset<double> orignal_multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 5.5});
  EXPECT_EQ(multiset_1.size(), 7);
  EXPECT_EQ(multiset_1.size(), (int)orignal_multiset_1.size());
}

TEST(MultisetTest, test_clear) {
  s21::Multiset<int> multiset_1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  s21::Multiset<int> multiset_2({1});
  s21::Multiset<int> multiset_3;
  EXPECT_EQ(multiset_1.size(), 12);
  EXPECT_EQ(multiset_2.size(), 1);
  EXPECT_EQ(multiset_3.size(), 0);
  multiset_1.clear();
  multiset_2.clear();
  multiset_3.clear();
  EXPECT_EQ(multiset_1.size(), 0);
  EXPECT_EQ(multiset_2.size(), 0);
  EXPECT_EQ(multiset_3.size(), 0);
}

TEST(MultisetTest, test_insert) {
  s21::Multiset<double> multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  std::multiset<double> orignal_multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  multiset_1.insert(3.2);
  EXPECT_TRUE(multiset_1.contains(3.2));
}

TEST(MultisetTest, lower_bound_test_test_insert) {
  s21::Multiset<double> multiset_1(
      {1, 2, 4, 6, 8, 12, 15, 19, 57, 100, 111, 112});
  std::multiset<double> orignal_multiset_1(
      {1, 2, 4, 6, 8, 12, 15, 19, 57, 100, 111, 112});
  EXPECT_EQ(*(orignal_multiset_1.lower_bound(58)),
            *(multiset_1.lower_bound(58)));
}

TEST(MultisetTest, lower_bound_test_notelement_test_insert) {
  s21::Multiset<double> multiset_1(
      {1, 2, 4, 6, 8, 12, 15, 19, 57, 100, 111, 112});
  std::multiset<double> orignal_multiset_1(
      {1, 2, 4, 6, 8, 12, 15, 19, 57, 100, 111, 112});
  multiset_1.lower_bound(200);
}

TEST(MultisetTest, upper_bound_test_test_insert) {
  s21::Multiset<double> multiset_1(
      {1, 2, 4, 6, 8, 12, 15, 19, 57, 100, 111, 112});
  std::multiset<double> orignal_multiset_1(
      {1, 2, 4, 6, 8, 12, 15, 19, 57, 100, 111, 112});
  // printf("%lf", *(orignal_multiset_1.upper_bound(58)) );
  EXPECT_EQ(*(orignal_multiset_1.upper_bound(58)),
            *(multiset_1.upper_bound(58)));
}

TEST(MultisetTest, upper_bound_test_not_element_test_insert) {
  s21::Multiset<double> multiset_1(
      {1, 2, 4, 6, 8, 12, 15, 19, 57, 100, 111, 112});
  std::multiset<double> orignal_multiset_1(
      {1, 2, 4, 6, 8, 12, 15, 19, 57, 100, 111, 112});
  multiset_1.upper_bound(200);
}

TEST(MultisetTest, equal_range_test_insert) {
  s21::Multiset<double> multiset_1(
      {1, 2, 4, 6, 8, 12, 15, 19, 57, 100, 111, 112});
  std::multiset<double> orignal_multiset_1(
      {1, 2, 4, 6, 8, 12, 15, 19, 57, 100, 111, 112});
  auto pair_iter = orignal_multiset_1.equal_range(100);
  auto pair_iter_my = multiset_1.equal_range(100);
  EXPECT_EQ(*(pair_iter_my.first), *(pair_iter.first));
  EXPECT_EQ(*(pair_iter_my.second), *(pair_iter.second));
}
TEST(MultisetInsertManyTest, InsertMultipleUniqueElements) {
  s21::Multiset<double> multiset({1, 2, 4, 6, 8});
  std::multiset<double> original_multiset({1, 2, 4, 6, 8});

  // Вставка нескольких уникальных элементов
  auto results = multiset.insert_many(10, 12, 14);

  // Проверяем, что все элементы успешно вставлены
  EXPECT_EQ(multiset.count(1), 1);
  EXPECT_EQ(multiset.count(2), 1);
  EXPECT_EQ(multiset.count(4), 1);
  EXPECT_EQ(multiset.count(6), 1);
  EXPECT_EQ(multiset.count(8), 1);
  EXPECT_EQ(multiset.count(10), 1);
  EXPECT_EQ(multiset.count(12), 1);
  EXPECT_EQ(multiset.count(14), 1);
}

TEST(MultisetInsertManyTest, InsertMultipleWithDuplicates) {
  s21::Multiset<double> multiset({1, 2, 4, 6, 8});
  std::multiset<double> original_multiset({1, 2, 4, 6, 8});

  // Вставка чисел с дубликатами
  auto results = multiset.insert_many(4, 6, 8, 8);

  // Проверяем количество каждого элемента
  EXPECT_EQ(multiset.count(1), 1);
  EXPECT_EQ(multiset.count(2), 1);
  EXPECT_EQ(multiset.count(4), 2);  // Дубликат
  EXPECT_EQ(multiset.count(6), 2);  // Дубликат
  EXPECT_EQ(multiset.count(8), 3);  // Два дубликата
}

TEST(MultisetInsertManyTest, InsertManyElementsAndCheckCounts) {
  s21::Multiset<double> multiset;
  std::multiset<double> original_multiset;

  // Вставка чисел и проверка
  auto results = multiset.insert_many(1, 2, 3, 4, 5, 5, 6);

  EXPECT_EQ(multiset.count(1), 1);
  EXPECT_EQ(multiset.count(2), 1);
  EXPECT_EQ(multiset.count(3), 1);
  EXPECT_EQ(multiset.count(4), 1);
  EXPECT_EQ(multiset.count(5), 2);  // Дубликат
  EXPECT_EQ(multiset.count(6), 1);
}
/*--->Array tests<---*/

TEST(S21ArrayTest, TestAt) {
  std::cout << "\n\n\033[1;32m";
  std::cout << "ARRAY TESTS";
  std::cout << "\033[0m\n\n";
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  ASSERT_NO_THROW(int_array.at(3));
  ASSERT_THROW(int_array.at(5), std::out_of_range);

  s21::array<double> double_array = {1.1, 2.2, 3.3, 4.4, 5.5};
  ASSERT_NO_THROW(double_array.at(3));
  ASSERT_THROW(double_array.at(5), std::out_of_range);

  s21::array<std::string> string_array = {"one", "two", "three", "four",
                                          "five"};
  ASSERT_NO_THROW(string_array.at(2));
  ASSERT_THROW(string_array.at(5), std::out_of_range);
}

TEST(S21ArrayTest, TestSwap) {
  s21::array<int> int_array1 = {1, 2, 3, 4, 5};
  s21::array<int> int_array2 = {6, 7, 8, 9};
  ASSERT_NO_THROW(int_array1.swap(int_array2));

  s21::array<double> double_array1 = {1.1, 2.2, 3.3, 4.4, 5.5};
  s21::array<double> double_array2 = {6.6, 7.7, 8.8, 9.9};
  ASSERT_NO_THROW(double_array1.swap(double_array2));

  s21::array<std::string> string_array1 = {"one", "two", "three", "four",
                                           "five"};
  s21::array<std::string> string_array2 = {"six", "seven", "eight", "nine"};
  ASSERT_NO_THROW(string_array1.swap(string_array2));
}

TEST(S21ArrayTest, TestFrontBack) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  ASSERT_EQ(int_array.front(), 1);
  ASSERT_EQ(int_array.back(), 5);

  s21::array<double> double_array = {1.1, 2.2, 3.3, 4.4, 5.5};
  ASSERT_EQ(double_array.front(), 1.1);
  ASSERT_EQ(double_array.back(), 5.5);

  s21::array<std::string> string_array = {"one", "two", "three", "four",
                                          "five"};
  ASSERT_EQ(string_array.front(), "one");
  ASSERT_EQ(string_array.back(), "five");

  s21::array<int> empty_array;
  ASSERT_THROW(empty_array.front(), std::out_of_range);
  ASSERT_THROW(empty_array.back(), std::out_of_range);
}

TEST(S21ArrayTest, TestFront) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  ASSERT_NO_THROW(int_array.front());
  ASSERT_EQ(int_array.front(), 1);

  s21::array<double> double_array = {1.1, 2.2, 3.3, 4.4, 5.5};
  ASSERT_NO_THROW(double_array.front());
  ASSERT_EQ(double_array.front(), 1.1);

  s21::array<std::string> string_array = {"one", "two", "three", "four",
                                          "five"};
  ASSERT_NO_THROW(string_array.front());
  ASSERT_EQ(string_array.front(), "one");
}

TEST(S21ArrayTest, TestBack) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  ASSERT_NO_THROW(int_array.back());
  ASSERT_EQ(int_array.back(), 5);

  s21::array<double> double_array = {1.1, 2.2, 3.3, 4.4, 5.5};
  ASSERT_NO_THROW(double_array.back());
  ASSERT_EQ(double_array.back(), 5.5);

  s21::array<std::string> string_array = {"one", "two", "three", "four",
                                          "five"};
  ASSERT_NO_THROW(string_array.back());
  ASSERT_EQ(string_array.back(), "five");
}

TEST(S21ArrayTest, TestBeginEnd) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  ASSERT_NE(int_array.begin(), int_array.end());

  s21::array<double> double_array = {1.1, 2.2, 3.3, 4.4, 5.5};
  ASSERT_NE(double_array.begin(), double_array.end());

  s21::array<std::string> string_array = {"one", "two", "three", "four",
                                          "five"};
  ASSERT_NE(string_array.begin(), string_array.end());
}

TEST(S21ArrayTest, TestEmpty) {
  s21::array<int> int_array;
  ASSERT_TRUE(int_array.empty());

  s21::array<double> double_array;
  ASSERT_TRUE(double_array.empty());

  s21::array<std::string> string_array;
  ASSERT_TRUE(string_array.empty());
}

TEST(S21ArrayTest, TestSize) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  ASSERT_EQ(int_array.size(), 5);

  s21::array<double> double_array = {1.1, 2.2, 3.3, 4.4, 5.5};
  ASSERT_EQ(double_array.size(), 5);

  s21::array<std::string> string_array = {"one", "two", "three", "four",
                                          "five"};
  ASSERT_EQ(string_array.size(), 5);
}

TEST(S21ArrayTest, TestFill) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  ASSERT_NO_THROW(int_array.fill(9));
  ASSERT_EQ(int_array.front(), 9);
  ASSERT_EQ(int_array.back(), 9);

  s21::array<double> double_array = {1.1, 2.2, 3.3, 4.4, 5.5};
  ASSERT_NO_THROW(double_array.fill(9.9));
  ASSERT_EQ(double_array.front(), 9.9);
  ASSERT_EQ(double_array.back(), 9.9);

  s21::array<std::string> string_array = {"one", "two", "three", "four",
                                          "five"};
  ASSERT_NO_THROW(string_array.fill("nine"));
  ASSERT_EQ(string_array.front(), "nine");
  ASSERT_EQ(string_array.back(), "nine");
}

TEST(S21ArrayTest, TestOperatorBrackets) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  ASSERT_EQ(int_array[0], 1);
  ASSERT_EQ(int_array[4], 5);
  ASSERT_THROW(int_array[5], std::out_of_range);

  s21::array<double> double_array = {1.1, 2.2, 3.3, 4.4, 5.5};
  ASSERT_EQ(double_array[0], 1.1);
  ASSERT_EQ(double_array[4], 5.5);
  ASSERT_THROW(double_array[5], std::out_of_range);

  s21::array<std::string> string_array = {"one", "two", "three", "four",
                                          "five"};
  ASSERT_EQ(string_array[0], "one");
  ASSERT_EQ(string_array[4], "five");
  ASSERT_THROW(string_array[5], std::out_of_range);
}

TEST(S21ArrayTest, TestCopyAssignmentOperator) {
  s21::array<int> int_array1 = {1, 2, 3, 4, 5};
  s21::array<int> int_array2;
  ASSERT_NO_THROW(int_array2 = int_array1);
  ASSERT_EQ(int_array1[2], int_array2[2]);

  s21::array<double> double_array1 = {1.1, 2.2, 3.3, 4.4, 5.5};
  s21::array<double> double_array2;
  ASSERT_NO_THROW(double_array2 = double_array1);
  ASSERT_EQ(double_array1[2], double_array2[2]);

  s21::array<std::string> string_array1 = {"one", "two", "three", "four",
                                           "five"};
  s21::array<std::string> string_array2;
  ASSERT_NO_THROW(string_array2 = string_array1);
  ASSERT_EQ(string_array1[2], string_array2[2]);
}

TEST(S21ArrayTest, TestMoveAssignmentOperator) {
  s21::array<int> int_array1 = {1, 2, 3, 4, 5};
  s21::array<int> int_array2;
  ASSERT_NO_THROW(int_array2 = std::move(int_array1));
  ASSERT_EQ(int_array2[2], 3);
  ASSERT_EQ(int_array1.size(), 0);

  s21::array<double> double_array1 = {1.1, 2.2, 3.3, 4.4, 5.5};
  s21::array<double> double_array2;
  ASSERT_NO_THROW(double_array2 = std::move(double_array1));
  ASSERT_EQ(double_array2[2], 3.3);
  ASSERT_EQ(double_array1.size(), 0);

  s21::array<std::string> string_array1 = {"one", "two", "three", "four",
                                           "five"};
  s21::array<std::string> string_array2;
  ASSERT_NO_THROW(string_array2 = std::move(string_array1));
  ASSERT_EQ(string_array2[2], "three");
  ASSERT_EQ(string_array1.size(), 0);
}

TEST(S21ArrayTest, TestIteratorBeginEnd) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  ASSERT_EQ(*(int_array.begin()), 1);
  ASSERT_EQ(*(int_array.end() - 1), 5);
  s21::array<int> int_array_empty;
  ASSERT_EQ(int_array_empty.begin(), int_array_empty.end());

  s21::array<double> double_array = {1.1, 2.2, 3.3, 4.4, 5.5};
  ASSERT_EQ(*(double_array.begin()), 1.1);
  ASSERT_EQ(*(double_array.end() - 1), 5.5);
  s21::array<double> double_array_empty;
  ASSERT_EQ(double_array_empty.begin(), double_array_empty.end());

  s21::array<std::string> string_array = {"one", "two", "three", "four",
                                          "five"};
  ASSERT_EQ(*(string_array.begin()), "one");
  ASSERT_EQ(*(string_array.end() - 1), "five");
  s21::array<std::string> string_array_empty;
  ASSERT_EQ(string_array_empty.begin(), string_array_empty.end());
}

TEST(S21ArrayTest, TestEmptyOnEmptyArrays) {
  s21::array<int> int_array;
  ASSERT_TRUE(int_array.empty());

  s21::array<double> double_array;
  ASSERT_TRUE(double_array.empty());

  s21::array<std::string> string_array;
  ASSERT_TRUE(string_array.empty());
}

TEST(S21ArrayTest, TestFillWithEmptyArray) {
  s21::array<int> int_array;
  ASSERT_NO_THROW(int_array.fill(9));

  s21::array<double> double_array;
  ASSERT_NO_THROW(double_array.fill(9.9));

  s21::array<std::string> string_array;
  ASSERT_NO_THROW(string_array.fill("nine"));
}

TEST(S21ArrayTest, TestSwapContents) {
  s21::array<int> int_array1 = {1, 2, 3, 4, 5};
  s21::array<int> int_array2 = {6, 7, 8};

  int_array1.swap(int_array2);

  ASSERT_EQ(int_array1[0], 6);
  ASSERT_EQ(int_array1[2], 8);
  ASSERT_EQ(int_array2[0], 1);
  ASSERT_EQ(int_array2[4], 5);
}

TEST(S21ArrayTest, TestInvalidAt) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  ASSERT_THROW(int_array.at(-1), std::out_of_range);
  ASSERT_THROW(int_array.at(50), std::out_of_range);
}

TEST(S21ArrayTest, TestInvalidOperatorBrackets) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  ASSERT_THROW(int_array[-1], std::out_of_range);
  ASSERT_THROW(int_array[50], std::out_of_range);
}

TEST(S21ArrayTest, TestFillOnEmptyArray) {
  s21::array<int> int_array;
  ASSERT_NO_THROW(int_array.fill(9));
  ASSERT_TRUE(int_array.empty());
}

TEST(S21ArrayTest, TestSwapEmptyArrays) {
  s21::array<int> int_array1;
  s21::array<int> int_array2;
  ASSERT_NO_THROW(int_array1.swap(int_array2));
  ASSERT_TRUE(int_array1.empty());
  ASSERT_TRUE(int_array2.empty());
}

TEST(S21ArrayTest, TestSwapArrayWithEmpty) {
  s21::array<int> int_array1 = {1, 2, 3, 4, 5};
  s21::array<int> int_array2;
  ASSERT_NO_THROW(int_array1.swap(int_array2));
  ASSERT_TRUE(int_array1.empty());
  ASSERT_EQ(int_array2.size(), 5);
}
TEST(S21ArrayTest, TestIteratorsIncrementDecrement) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  s21::array<int>::iterator iter = int_array.begin();
  ASSERT_EQ(*iter, 1);
  iter++;
  ASSERT_EQ(*iter, 2);
  iter--;
  ASSERT_EQ(*iter, 1);
}

TEST(S21ArrayTest, TestConstIterators) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  s21::array<int>::iterator citer = int_array.begin();
  ASSERT_EQ(*citer, 1);
  citer++;
  ASSERT_EQ(*citer, 2);
  citer--;
  ASSERT_EQ(*citer, 1);
}

TEST(S21ArrayTest, TestIteratorsEquality) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};

  s21::array<int>::iterator iter1 = int_array.begin();
  s21::array<int>::iterator iter2 = int_array.begin();

  ASSERT_TRUE(iter1 == iter2);
  iter2++;
  ASSERT_TRUE(iter1 != iter2);
}

TEST(S21ArrayTest, TestIteratorsArithmetic) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  s21::array<int>::iterator iter = int_array.begin();

  s21::array<int>::iterator adv_iter = iter + 3;
  ASSERT_EQ(*adv_iter, 4);

  s21::array<int>::iterator rev_iter = adv_iter - 2;
  ASSERT_EQ(*rev_iter, 2);

  adv_iter -= 1;
  ASSERT_EQ(*adv_iter, 3);

  rev_iter += 2;
  ASSERT_EQ(*rev_iter, 4);
}

TEST(S21ArrayTest, TestMaxSize) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  ASSERT_EQ(int_array.max_size(), 5);

  s21::array<int> empty_array;
  ASSERT_EQ(empty_array.max_size(), 0);
}

TEST(S21ArrayTest, TestData) {
  s21::array<int> int_array = {1, 2, 3, 4, 5};
  s21::array<int>::iterator data_ptr = int_array.data();
  ASSERT_TRUE(data_ptr != nullptr);
  ASSERT_EQ(*data_ptr, 1);

  s21::array<int> empty_array;
  data_ptr = empty_array.data();
  ASSERT_TRUE(data_ptr == nullptr);
}