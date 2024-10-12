#include "test.h"

/*--->stack tests<---*/

TEST(stack, Constr_Default) {
  s21::stack<int> our_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(stack, Constr_List) {
  s21::stack<int> our_stack;
  our_stack.push(1);
  our_stack.push(2);
  our_stack.push(3);
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  EXPECT_EQ(our_stack.top(), std_stack.top());
}

TEST(stack, Constr_Copy) {
  s21::stack<int> our_stack;
  our_stack.push(1);
  our_stack.push(2);
  our_stack.push(3);
  s21::stack<int> our_copy(our_stack);
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std::stack<int> std_copy(std_stack);
  EXPECT_EQ(our_copy.top(), std_copy.top());
}

TEST(stack, Operator_Copy) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  our_stack_empty = our_stack_int;
  std_stack_empty = std_stack_int;
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}

TEST(stack, Constr_Move) {
  s21::stack<int> our_stack = {1, 2, 3};
  s21::stack<int> our_move(std::move(our_stack));
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std::stack<int> std_move(std::move(std_stack));
  EXPECT_EQ(our_move.top(), std_move.top());
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(stack, top) {
  s21::stack<int> our_stack_int;
  our_stack_int.push(1);
  our_stack_int.push(2);
  our_stack_int.push(3);
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<double> our_stack_double;
  our_stack_double.push(1.1f);
  our_stack_double.push(2.1f);
  our_stack_double.push(3.1f);
  std::stack<double> std_stack_double;
  std_stack_double.push(1.1f);
  std_stack_double.push(2.1f);
  std_stack_double.push(3.1f);
  s21::stack<std::string> our_stack_string;
  our_stack_string.push("abc");
  our_stack_string.push("def");
  our_stack_string.push("ghf");
  std::stack<std::string> std_stack_string;
  std_stack_string.push("abc");
  std_stack_string.push("def");
  std_stack_string.push("ghf");
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
  EXPECT_EQ(our_stack_double.top(), std_stack_double.top());
  EXPECT_EQ(our_stack_string.top(), std_stack_string.top());
}

TEST(stack, empty) {
  s21::stack<int> our_stack_int;
  our_stack_int.push(1);
  our_stack_int.push(2);
  our_stack_int.push(3);
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  EXPECT_EQ(our_stack_empty.empty(), std_stack_empty.empty());
}

TEST(stack, size) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(our_stack_int.size(), std_stack_int.size());
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  EXPECT_EQ(our_stack_empty.size(), std_stack_empty.size());
}

TEST(stack, push) {
  s21::stack<int> our_stack_int = {1, 2, 3};
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
}

TEST(stack, pop) {
  s21::stack<int> our_stack_int;
  our_stack_int.push(1);
  our_stack_int.push(2);
  our_stack_int.push(3);
  our_stack_int.pop();
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.top(), std_stack_int.top());
  our_stack_int.pop();
  our_stack_int.pop();
  std_stack_int.pop();
  std_stack_int.pop();
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}

TEST(stack, swap) {
  s21::stack<int> our_stack_int;
  our_stack_int.push(1);
  our_stack_int.push(2);
  our_stack_int.push(3);
  std::stack<int> std_stack_int;
  std_stack_int.push(1);
  std_stack_int.push(2);
  std_stack_int.push(3);
  s21::stack<int> our_stack_empty;
  std::stack<int> std_stack_empty;
  our_stack_empty.swap(our_stack_int);
  std_stack_empty.swap(std_stack_int);
  EXPECT_EQ(our_stack_empty.top(), std_stack_empty.top());
  EXPECT_EQ(our_stack_int.empty(), std_stack_int.empty());
}
TEST(Stack, InsertManyFront) {
  s21::stack<int> our_stack_int;
  our_stack_int.insert_many_front(1, 2, 3);
  EXPECT_EQ(our_stack_int.top(), 3);
}

// Vector

TEST(VectorTest, DefaultConstr) {
  std::cout << "\n\n\033[1;32m";
  std::cout << "VECTOR TESTS";
  std::cout << "\033[0m\n\n";
  s21::Vector<int> s21_vec_int;
  s21::Vector<double> s21_vec_double;
  s21::Vector<std::string> s21_vec_string;

  EXPECT_EQ(s21_vec_int.size(), 0);
  EXPECT_EQ(s21_vec_int.capacity(), 0);
  EXPECT_EQ(s21_vec_int.data(), nullptr);

  EXPECT_EQ(s21_vec_double.size(), 0);
  EXPECT_EQ(s21_vec_double.capacity(), 0);
  EXPECT_EQ(s21_vec_int.data(), nullptr);

  EXPECT_EQ(s21_vec_string.size(), 0);
  EXPECT_EQ(s21_vec_string.capacity(), 0);
  EXPECT_EQ(s21_vec_int.data(), nullptr);
}

TEST(VectorTest, sizeConstr) {
  s21::Vector<int> int_size_Constr(5);
  s21::Vector<double> double_size_Constr(5);
  s21::Vector<std::string> char_size_Constr(5);

  EXPECT_EQ(int_size_Constr.size(), 5);
  EXPECT_EQ(int_size_Constr.capacity(), 5);
  EXPECT_EQ(int_size_Constr.front(), 0);
  EXPECT_EQ(int_size_Constr.back(), 0);
  int_size_Constr = {1, 2, 3, 4, 5};
  EXPECT_EQ(int_size_Constr.front(), 1);
  EXPECT_EQ(int_size_Constr.back(), 5);
  for (size_t i = 0; i < int_size_Constr.size(); i++)
    EXPECT_EQ(int_size_Constr[i], i + 1);

  EXPECT_EQ(double_size_Constr.size(), 5);
  EXPECT_EQ(double_size_Constr.capacity(), 5);
  EXPECT_EQ(double_size_Constr.front(), 0);
  EXPECT_EQ(double_size_Constr.back(), 0);
  double_size_Constr = {1.2, 2.3, 3.4, 4.5, 5.6};
  double test_double[] = {1.2, 2.3, 3.4, 4.5, 5.6};
  EXPECT_EQ(double_size_Constr.front(), 1.2);
  EXPECT_EQ(double_size_Constr.back(), 5.6);
  for (size_t i = 0; i < double_size_Constr.size(); i++)
    EXPECT_EQ(double_size_Constr[i], test_double[i]);

  EXPECT_EQ(char_size_Constr.size(), 5);
  EXPECT_EQ(char_size_Constr.capacity(), 5);
  EXPECT_EQ(char_size_Constr.front(), "");
  EXPECT_EQ(char_size_Constr.back(), "");
  char_size_Constr = {"one", "two", "three", "four", "five"};
  std::string test_string[] = {"one", "two", "three", "four", "five"};
  EXPECT_EQ(char_size_Constr.front(), "one");
  EXPECT_EQ(char_size_Constr.back(), "five");
  for (size_t i = 0; i < char_size_Constr.size(); i++)
    EXPECT_EQ(char_size_Constr[i], test_string[i]);
}

TEST(VectorTest, InitializerListConstr) {
  s21::Vector<int> init_int{1, 2, 3, 4, 5};
  s21::Vector<double> init_double{1.2, 2.3, 3.4, 4.5, 5.6};
  s21::Vector<std::string> init_string{"one", "two", "three", "four", "five"};

  EXPECT_EQ(init_int.size(), 5);
  EXPECT_EQ(init_int.capacity(), 5);
  EXPECT_EQ(init_int.front(), 1);
  EXPECT_EQ(init_int.back(), 5);
  for (size_t i = 0; i < init_int.size(); i++) EXPECT_EQ(init_int[i], i + 1);

  EXPECT_EQ(init_double.size(), 5);
  EXPECT_EQ(init_double.capacity(), 5);
  double test_double[] = {1.2, 2.3, 3.4, 4.5, 5.6};
  EXPECT_EQ(init_double.front(), 1.2);
  EXPECT_EQ(init_double.back(), 5.6);
  for (size_t i = 0; i < init_double.size(); i++)
    EXPECT_EQ(init_double[i], test_double[i]);

  EXPECT_EQ(init_string.size(), 5);
  EXPECT_EQ(init_string.capacity(), 5);
  std::string test_string[] = {"one", "two", "three", "four", "five"};
  EXPECT_EQ(init_string.front(), "one");
  EXPECT_EQ(init_string.back(), "five");
  for (size_t i = 0; i < init_string.size(); i++)
    EXPECT_EQ(init_string[i], test_string[i]);
}

TEST(VectorTest, CopyConstr) {
  s21::Vector<int> copy_int{1, 2, 3, 4, 5};
  s21::Vector<int> copy_int_2(copy_int);
  s21::Vector<double> copy_double{1.2, 2.3, 3.4, 4.5, 5.6};
  s21::Vector<double> copy_double_2(copy_double);
  s21::Vector<std::string> copy_string{"one", "two", "three", "four", "five"};
  s21::Vector<std::string> copy_string_2(copy_string);

  EXPECT_EQ(copy_int.size(), copy_int_2.size());
  EXPECT_EQ(copy_int.capacity(), copy_int_2.capacity());
  EXPECT_EQ(copy_int.front(), copy_int.front());
  EXPECT_EQ(copy_int.back(), copy_int.back());
  for (size_t i = 0; i < copy_int.size(); ++i)
    EXPECT_EQ(copy_int[i], copy_int_2[i]);

  EXPECT_EQ(copy_double.size(), copy_double_2.size());
  EXPECT_EQ(copy_double.capacity(), copy_double_2.capacity());
  EXPECT_EQ(copy_double.front(), copy_double_2.front());
  EXPECT_EQ(copy_double.back(), copy_double_2.back());
  for (size_t i = 0; i < copy_double_2.size(); ++i)
    EXPECT_EQ(copy_double[i], copy_double_2[i]);

  EXPECT_EQ(copy_string.size(), copy_string_2.size());
  EXPECT_EQ(copy_string.capacity(), copy_string_2.capacity());
  EXPECT_EQ(copy_string.front(), copy_string_2.front());
  EXPECT_EQ(copy_string.back(), copy_string_2.back());
  for (size_t i = 0; i < copy_string_2.size(); ++i)
    EXPECT_EQ(copy_string[i], copy_string_2[i]);
}

TEST(VectorTest, MoveConstr) {
  s21::Vector<int> move_int{1, 2, 3, 4, 5};
  s21::Vector<double> move_double{1.2, 2.3, 3.4, 4.5, 5.6};
  s21::Vector<std::string> move_string{"one", "two", "three", "four", "five"};

  s21::Vector<int> move_int_2(std::move(move_int));
  s21::Vector<double> move_double_2(std::move(move_double));
  s21::Vector<std::string> move_string_2(std::move(move_string));

  EXPECT_EQ(move_int.size(), 0);
  EXPECT_EQ(move_int_2.size(), 5);
  EXPECT_EQ(move_int.data(), nullptr);
  for (size_t i = 0; i < move_int.size(); i++) EXPECT_EQ(move_int_2[i], i);

  EXPECT_EQ(move_double.size(), 0);
  EXPECT_EQ(move_double_2.size(), 5);
  EXPECT_EQ(move_double.data(), nullptr);
  for (size_t i = 0; i < move_double.size(); i++)
    EXPECT_EQ(move_double_2[i], i);

  EXPECT_EQ(move_string.size(), 0);
  EXPECT_EQ(move_string_2.size(), 5);
  EXPECT_EQ(move_string.data(), nullptr);
  std::string test_string[] = {"one", "two", "three", "four", "five"};
  for (size_t i = 0; i < move_string.size(); i++)
    EXPECT_EQ(move_string_2[i], test_string[i]);
}

TEST(VectorTest, at_checking) {
  s21::Vector<int> move_int{1, 2, 3, 4, 5};
  s21::Vector<double> move_double{1.2, 2.3, 3.4, 4.5, 5.6};
  s21::Vector<std::string> move_string{"one", "two", "three", "four", "five"};

  for (size_t i = 0; i < move_int.size(); i++) EXPECT_EQ(move_int.at(i), i + 1);

  double test_double[] = {1.2, 2.3, 3.4, 4.5, 5.6};
  for (size_t i = 0; i < move_double.size(); i++)
    EXPECT_EQ(move_double.at(i), test_double[i]);

  std::string test_string[] = {"one", "two", "three", "four", "five"};
  for (size_t i = 0; i < move_string.size(); i++)
    EXPECT_EQ(move_string.at(i), test_string[i]);
}

TEST(VectorTest, operator1) {
  s21::Vector<int> operator1_int(2);
  s21::Vector<double> operator1_double(2);
  s21::Vector<std::string> operator1_string(2);

  operator1_int[0] = 1;
  operator1_int[1] = 2;
  for (size_t i = 0; i < operator1_int.size(); i++)
    EXPECT_EQ(operator1_int.at(i), i + 1);

  operator1_double[0] = 1.2;
  operator1_double[1] = 2.3;
  double test_double[] = {1.2, 2.3};
  for (size_t i = 0; i < operator1_double.size(); i++)
    EXPECT_EQ(operator1_double[i], test_double[i]);

  operator1_string[0] = "one";
  operator1_string[1] = "two";
  std::string test_string[] = {"one", "two"};
  for (size_t i = 0; i < operator1_string.size(); i++)
    EXPECT_EQ(operator1_string[i], test_string[i]);
}

TEST(VectorTest, Erase_Beginning) {
  s21::Vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin());
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[0], 2);
}

TEST(VectorTest, Erase_Middle) {
  s21::Vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin() + 1);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[1], 3);
}

TEST(VectorTest, Erase_End) {
  s21::Vector<int> v = {1, 2, 3, 4};
  v.erase(v.end() - 1);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, erase_checking) {
  s21::Vector<int> vec_int{1, 2, 3, 4, 5};
  vec_int.erase(vec_int.begin() + 2);
  size_t expected_int[] = {1, 2, 4, 5};
  ASSERT_EQ(vec_int.size(), 4);
  for (size_t i = 0; i < vec_int.size(); i++) {
    EXPECT_EQ(vec_int.at(i), expected_int[i]);
  }

  s21::Vector<double> vec_double{1.2, 2.3, 3.4, 4.5, 5.6};
  vec_double.erase(vec_double.begin() + 2);
  double expected_double[] = {1.2, 2.3, 4.5, 5.6};
  ASSERT_EQ(vec_double.size(), 4);
  for (size_t i = 0; i < vec_double.size(); i++) {
    EXPECT_EQ(vec_double.at(i), expected_double[i]);
  }

  s21::Vector<std::string> vec_string{"one", "two", "three", "four", "five"};
  vec_string.erase(vec_string.begin() + 2);
  std::string expected_string[] = {"one", "two", "four", "five"};
  ASSERT_EQ(vec_string.size(), 4);
  for (size_t i = 0; i < vec_string.size(); i++) {
    EXPECT_EQ(vec_string.at(i), expected_string[i]);
  }
}

TEST(VectorTest, emptyTest) {
  s21::Vector<int> empty_int;
  s21::Vector<double> empty_double;
  s21::Vector<std::string> empty_string;

  EXPECT_TRUE(empty_int.empty());
  EXPECT_TRUE(empty_double.empty());
  EXPECT_TRUE(empty_string.empty());

  empty_int.push_back(10);
  empty_double.push_back(3.14);
  empty_string.push_back("test");

  EXPECT_FALSE(empty_int.empty());
  EXPECT_FALSE(empty_double.empty());
  EXPECT_FALSE(empty_string.empty());
}

TEST(VectorTest, Reserve_IncreaseCapacity) {
  s21::Vector<int> v;
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity + 10;
  v.reserve(newCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(VectorIteratorsTest, OperatorIncrement) {
  s21::Vector<int> myVector{1, 2, 3, 4, 5};
  s21::Vector<int>::iterator iter = myVector.begin();

  EXPECT_EQ(*iter, 1);
  ++iter;
  EXPECT_EQ(*iter, 2);
}

TEST(VectorIteratorsTest, OperatorDecrement) {
  s21::Vector<int> myVector{1, 2, 3, 4, 5};
  s21::Vector<int>::iterator iter = myVector.end();
  --iter;
  EXPECT_EQ(*iter, 5);
  --iter;
  EXPECT_EQ(*iter, 4);
}

TEST(VectorIteratorsTest, OperatorMinus) {
  s21::Vector<int> myVector{1, 2, 3, 4, 5};
  s21::Vector<int>::iterator iter = myVector.end();
  iter = iter - 2;
  EXPECT_EQ(*iter, 4);
}

TEST(VectorIteratorsTest, OperatorPlus) {
  s21::Vector<int> myVector{1, 2, 3, 4, 5};
  s21::Vector<int>::iterator iter = myVector.begin();
  iter = iter + 2;

  EXPECT_EQ(*iter, 3);
}

TEST(VectorIteratorsTest, OperatorEqual) {
  s21::Vector<int> Vector1{1, 2, 3, 4, 5};
  s21::Vector<int>::iterator iterator1 = Vector1.begin();
  s21::Vector<int>::iterator iterator2 = Vector1.begin();
  EXPECT_TRUE(iterator1 == iterator2);
}

TEST(VectorIteratorsTest, OperatorNotEqual) {
  s21::Vector<int> Vector1{1, 2, 3, 4, 5};
  s21::Vector<int> Vector2{1, 2, 3, 4, 6};
  EXPECT_TRUE(Vector1.end() != Vector2.end());
}

TEST(VectorIteratorsTesst, OperatorMinusPlusInt) {
  s21::Vector<int> numbers{10, 20, 30, 40};
  s21::Vector<int>::iterator iter = numbers.begin();
  ++iter;
  EXPECT_EQ(*iter, 20);
  iter += 2;
  EXPECT_EQ(*iter, 40);
  iter -= 3;
  EXPECT_EQ(*iter, 10);
}

TEST(VectorTest, Reserve_DecreaseCapacity) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity - 2;
  v.reserve(newCapacity);
  EXPECT_LE(v.capacity(), initialCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(VectorTest, pushBackTest) {
  s21::Vector<int> push_int;
  s21::Vector<double> push_double;
  s21::Vector<std::string> push_string;

  push_int.push_back(10);
  push_double.push_back(3.14);
  push_string.push_back("test");

  EXPECT_FALSE(push_int.empty());
  EXPECT_EQ(push_int.back(), 10);

  EXPECT_FALSE(push_double.empty());
  EXPECT_EQ(push_double.back(), 3.14);

  EXPECT_FALSE(push_string.empty());
  EXPECT_EQ(push_string.back(), "test");
}

TEST(VectorTest, ShrinkToFitTest) {
  s21::Vector<int> shrink_vec{1, 2, 3, 4, 5, 6};
  shrink_vec.reserve(20);
  ASSERT_EQ(shrink_vec.capacity(), 20);

  shrink_vec.shrink_to_fit();
  EXPECT_EQ(shrink_vec.capacity(), shrink_vec.size());
}

TEST(VectorTest, InsertTest) {
  s21::Vector<int> insert_vec{1, 2, 4, 5};
  insert_vec.insert(insert_vec.begin() + 2, 3);
  EXPECT_EQ(insert_vec[2], 3);
}

TEST(VectorTest, pushBackIncreaseCapacity) {
  s21::Vector<int> v;
  size_t cap = v.capacity();
  for (size_t i = 0; i < cap + 5; i++) {
    v.push_back(i);
  }
  EXPECT_TRUE(v.capacity() > cap);
}

TEST(VectorTest, popBackDecreaseCapacity) {
  s21::Vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  size_t cap = v.capacity();
  for (size_t i = 0; i < 5; i++) {
    v.pop_back();
  }
  EXPECT_TRUE(v.size() < cap);
}

TEST(VectorTest, swapTest) {
  s21::Vector<int> v1 = {1, 2, 3, 4, 5};
  s21::Vector<int> v2 = {6, 7, 8, 9, 10};

  v1.swap(v2);
  int expected_v2[] = {1, 2, 3, 4, 5};
  int expected_v1[] = {6, 7, 8, 9, 10};

  for (size_t i = 0; i < v1.size(); i++) {
    EXPECT_EQ(v1[i], expected_v1[i]);
    EXPECT_EQ(v2[i], expected_v2[i]);
  }
}

TEST(VectorTest, AssignmentOperator) {
  s21::Vector<int> v1 = {1, 2, 3, 4, 5};
  s21::Vector<int> v2 = v1;
  EXPECT_EQ(v1.size(), v2.size());
  for (size_t i = 0; i < v1.size(); i++) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

TEST(VectorTest, At_OutOfRange) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_THROW(v.at(5), std::out_of_range);
}

TEST(VectorTest, Erase_OutOfRange) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_THROW(v.erase(v.begin() + 6), std::out_of_range);
}
TEST(VectorTest, AssignmentOperatorToItself) {
  s21::Vector<int> v1 = {1, 2, 3, 4, 5};
  s21::Vector<int> v2 = v1;
  v1 = v2;
  EXPECT_EQ(v1.size(), v2.size());
  for (size_t i = 0; i < v1.size(); i++) EXPECT_EQ(v1[i], v2[i]);
}
TEST(VectorTest, FrontBackForemptyVector) {
  s21::Vector<std::string> empty_vec;
  EXPECT_THROW(empty_vec.front(), std::out_of_range);
  EXPECT_THROW(empty_vec.back(), std::out_of_range);
}
TEST(VectorTest, CapacityInitializationCheck) {
  s21::Vector<double> vec(5);
  EXPECT_EQ(vec.capacity(), 5);
}
TEST(VectorTest, swapWithemptyVector) {
  s21::Vector<int> vec = {1, 2, 3};
  s21::Vector<int> empty_vec;
  vec.swap(empty_vec);
  EXPECT_EQ(vec.size(), 0);
  EXPECT_EQ(empty_vec.size(), 3);
}
TEST(VectorTest, InsertInemptyVector) {
  s21::Vector<int> empty_vec;
  empty_vec.insert(empty_vec.begin(), 3);
  EXPECT_EQ(empty_vec.front(), 3);
  EXPECT_EQ(empty_vec.size(), 1);
}

TEST(VectorTest, EraseInemptyVector) {
  s21::Vector<int> empty_vec;
  EXPECT_THROW(empty_vec.erase(empty_vec.begin()), std::out_of_range);
}

TEST(VectorTest, InsertAtIteratorBeyondEnd) {
  s21::Vector<int> vec = {1, 2, 3};
  EXPECT_THROW(vec.insert(vec.end() + 1, 4), std::out_of_range);
}

TEST(VectorTest, IteratorPostfixOperators) {
  s21::Vector<int> vec = {1, 2, 3, 4};
  s21::Vector<int>::iterator iter = vec.begin();
  ASSERT_EQ(*iter, 1);
  iter++;
  ASSERT_EQ(*iter, 2);
  iter--;
  ASSERT_EQ(*iter, 1);
}

TEST(VectorTest, InsertManyTest) {
  s21::Vector<int> test_Vector{0, 1, 2, 3, 4, 5};
  test_Vector.insert_many(test_Vector.cbegin() + 2, 10, 20, 30);
  ASSERT_EQ(test_Vector[2], 10);
  ASSERT_EQ(test_Vector[3], 20);
  ASSERT_EQ(test_Vector[4], 30);
  ASSERT_EQ(test_Vector[5], 2);
  ASSERT_EQ(test_Vector[6], 3);
  ASSERT_EQ(test_Vector[7], 4);
  ASSERT_EQ(test_Vector.size(), 9);
}
TEST(VectorTest, InsertManyBackTest) {
  s21::Vector<int> test_Vector{1, 2, 3, 4, 5};
  test_Vector.insert_many_back(10, 20, 30);
  ASSERT_EQ(test_Vector[0], 1);
  ASSERT_EQ(test_Vector[1], 2);
  ASSERT_EQ(test_Vector[2], 3);
  ASSERT_EQ(test_Vector[3], 4);
  ASSERT_EQ(test_Vector[4], 5);
  ASSERT_EQ(test_Vector[5], 10);
  ASSERT_EQ(test_Vector[6], 20);
  ASSERT_EQ(test_Vector[7], 30);
  ASSERT_EQ(test_Vector.size(), 8);
}
// queue
template <typename value_type>
bool check_eq(s21::queue<value_type> m_queue,
              std::queue<value_type> orig_queue) {
  bool result = true;
  if (m_queue.size() == orig_queue.size()) {
    while (!m_queue.empty() && !orig_queue.empty()) {
      if (m_queue.front() != orig_queue.front()) {
        result = false;
        break;
      }
      m_queue.pop();
      orig_queue.pop();
    }
  } else {
    result = false;
  }
  return result;
}

TEST(Queue_test, construct_def_empty) {
  s21::queue<int> lol_my;
  EXPECT_THROW(lol_my.back(), std::logic_error);

  s21::queue<int> lol_my1;
  lol_my1.push(1);
  lol_my1.push(2);
  lol_my1.push(3);
  lol_my1.push(4);

  std::queue<int> lol_orig;
  lol_orig.push(1);
  lol_orig.push(2);
  lol_orig.push(3);
  lol_orig.push(4);

  int kek = lol_my1.front();
  int kek_orig = lol_orig.front();
  int kek_back = lol_my1.back();
  int kek_orig_back = lol_orig.back();
  EXPECT_EQ(lol_my1.size(), 4U);
  EXPECT_EQ(kek, kek_orig);
  EXPECT_EQ(kek_back, kek_orig_back);
}

TEST(Queue_test, lol) {
  s21::queue<int> lol_my;
  s21::queue<int> lol_my1;
  lol_my.push(1);
  lol_my.push(2);
  lol_my.push(3);
  lol_my1.push(1);
  lol_my1.push(2);
  lol_my1.push(3);
  lol_my.pop();
  lol_my.pop();
  lol_my.front();
  lol_my.back();
  lol_my = lol_my1;
}

TEST(Queue_test, front) {
  s21::queue<int> lol_my;
  EXPECT_THROW(lol_my.front(), std::logic_error);
}

TEST(Queue_test, empty) {
  s21::queue<int> lol_my1;
  std::queue<int> lol_orig;
  EXPECT_EQ(lol_my1.empty(), lol_orig.empty());
}

TEST(Queue_test, swap) {
  s21::queue<int> kek = {1, 2, 3, 5, 6, 7};
  s21::queue<int> kek2 = {55, 22, 53, 8342, 5643, 422};
  kek.swap(kek2);
  EXPECT_EQ(kek.back(), 422);
  EXPECT_EQ(kek.front(), 55);
}

TEST(Queue_test, not_eq_length) {
  s21::queue<int> kek = {1, 2, 3, 5, 6, 7};
  s21::queue<int> kek2 = {55, 22, 53, 8342, 5643, 422, 44, 76, 33};
  kek.swap(kek2);
  EXPECT_EQ(kek.back(), 33);
  EXPECT_EQ(kek.front(), 55);
}

TEST(Queue_test, empty_swap) {
  s21::queue<int> kek;
  s21::queue<int> kek2;
  kek.swap(kek2);
  EXPECT_THROW(kek.back(), std::logic_error);
  EXPECT_THROW(kek.front(), std::logic_error);
}

TEST(Queue_test, CompareQueues) {
  s21::queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(20);
  EXPECT_TRUE(check_eq(my_queue, std_queue));
  std_queue.push(20);
  EXPECT_FALSE(check_eq(my_queue, std_queue));
}

TEST(Queue_test, pop) {
  s21::queue<int> lol{1, 3, 10, -5, 20, 21};
  std::queue<int> lol_orig;
  lol_orig.push(1);
  lol_orig.push(3);
  lol_orig.push(10);
  lol_orig.push(-5);
  lol_orig.push(20);
  lol_orig.push(21);
  lol.pop();
  lol.pop();
  lol_orig.pop();
  lol_orig.pop();
  EXPECT_TRUE(check_eq(lol, lol_orig));
  EXPECT_EQ(lol.front(), 10);

  s21::queue<int> empty_kek;
  EXPECT_THROW(empty_kek.back(), std::logic_error);
  EXPECT_THROW(empty_kek.pop(), std::logic_error);
  EXPECT_THROW(empty_kek.front(), std::logic_error);
}

TEST(Queue_test, InitializerqueueConstr_2) {
  std::initializer_list<int> b;
  s21::queue<int> lol{b};
  std::queue<int> lol_orig{b};
  EXPECT_TRUE(check_eq(lol, lol_orig));
}

TEST(Queue_test, MoveConstr) {
  std::queue<int> lol_orig;
  lol_orig.push(1);
  lol_orig.push(3);
  lol_orig.push(10);
  lol_orig.push(-5);
  lol_orig.push(20);
  lol_orig.push(21);

  s21::queue<int> lol_my;
  lol_my.push(1);
  lol_my.push(3);
  lol_my.push(10);
  lol_my.push(-5);
  lol_my.push(20);
  lol_my.push(21);
  EXPECT_TRUE(check_eq(lol_my, lol_orig));
}

TEST(Queue, Constr_Default) {
  s21::queue<int> our_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(Queue, Constr_List) {
  s21::queue<int> our_queue = {1, 2, 3};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  EXPECT_EQ(our_queue.front(), std_queue.front());
  EXPECT_EQ(our_queue.back(), std_queue.back());
}

TEST(Queue, Constr_Copy) {
  s21::queue<int> our_queue = {1, 2, 3};
  s21::queue<int> our_copy(our_queue);
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std::queue<int> std_copy(std_queue);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(Queue, Operator_Copy) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty = our_queue_int;
  std_queue_empty = std_queue_int;
  EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(Queue, Constr_Move) {
  s21::queue<int> our_queue = {1, 2, 3};
  s21::queue<int> our_move(std::move(our_queue));
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std::queue<int> std_move(std::move(std_queue));
  EXPECT_EQ(our_move.front(), std_move.front());
  EXPECT_EQ(our_move.back(), std_move.back());
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(Queue, Operator_Move) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty = std::move(our_queue_int);
  std_queue_empty = std::move(std_queue_int);
  EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(Queue, FrontAndBack) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<double> our_queue_double = {1.1f, 2.1f, 3.1f};
  std::queue<double> std_queue_double;
  std_queue_double.push(1.1f);
  std_queue_double.push(2.1f);
  std_queue_double.push(3.1f);
  s21::queue<std::string> our_queue_string = {"abc", "def", "ghf"};
  std::queue<std::string> std_queue_string;
  std_queue_string.push("abc");
  std_queue_string.push("def");
  std_queue_string.push("ghf");
  EXPECT_EQ(our_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(our_queue_double.front(), std_queue_double.front());
  EXPECT_EQ(our_queue_string.front(), std_queue_string.front());
  EXPECT_EQ(our_queue_int.back(), std_queue_int.back());
  EXPECT_EQ(our_queue_double.back(), std_queue_double.back());
  EXPECT_EQ(our_queue_string.back(), std_queue_string.back());
}

TEST(Queue, Empty) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(our_queue_empty.empty(), std_queue_empty.empty());
}

TEST(Queue, Size) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(our_queue_int.size(), std_queue_int.size());
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(our_queue_empty.size(), std_queue_empty.size());
}

TEST(Queue, Push) {
  s21::queue<int> our_queue_int;
  our_queue_int.push(1);
  our_queue_int.push(2);
  our_queue_int.push(3);
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(our_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(our_queue_int.back(), std_queue_int.back());
}

TEST(Queue, Pop) {
  s21::queue<int> our_queue_int;
  our_queue_int.push(1);
  our_queue_int.push(2);
  our_queue_int.push(3);
  our_queue_int.pop();
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  std_queue_int.pop();
  EXPECT_EQ(our_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(our_queue_int.back(), std_queue_int.back());
  our_queue_int.pop();
  our_queue_int.pop();
  std_queue_int.pop();
  std_queue_int.pop();
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(Queue, Swap) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty.swap(our_queue_int);
  std_queue_empty.swap(std_queue_int);
  EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(Queue, InsertManyBack) {
  s21::queue<int> our_queue_int;
  our_queue_int.insert_many_back(1, 2, 3);
  EXPECT_EQ(our_queue_int.front(), 1);
  EXPECT_EQ(our_queue_int.back(), 3);
}

class QueueTest : public ::testing::Test {
 protected:
  void SetUp() override {}

  s21::queue<int> s0_{1, 2, 3, 4, 5};
  s21::queue<int> s1_{};
};

TEST_F(QueueTest, default_Constr) {
  ASSERT_TRUE(s1_.empty());
  ASSERT_EQ(s1_.size(), 0U);
}

TEST_F(QueueTest, initializer_list_Constr) {
  ASSERT_EQ(s0_.back(), 5);
  ASSERT_FALSE(s0_.empty());
  ASSERT_EQ(s0_.size(), 5U);
  s0_.pop();
  ASSERT_EQ(s0_.size(), 4U);
  s0_.pop();
  ASSERT_EQ(s0_.size(), 3U);
  ASSERT_EQ(s0_.front(), 3);
  s0_.pop();
  s0_.pop();
  s0_.pop();
  ASSERT_TRUE(s0_.empty());

  // NOTE:exception test here when s21::list added
  // ASSERT_ANY_THROW(s0_.pop());
}

TEST_F(QueueTest, copy_Constr) {
  s21::queue<int> copy(s0_);
  ASSERT_EQ(copy.front(), s0_.front());
  copy.pop();
  s0_.pop();
  ASSERT_EQ(copy.front(), s0_.front());
  copy.pop();
  s0_.pop();
  ASSERT_EQ(copy.front(), s0_.front());
  copy.pop();
  s0_.pop();
  ASSERT_EQ(copy.front(), s0_.front());
  copy.pop();
  s0_.pop();
  ASSERT_EQ(copy.front(), s0_.front());
  copy.pop();
  s0_.pop();

  ASSERT_TRUE(copy.empty());
  ASSERT_TRUE(s0_.empty());

  copy.push(69);
  s0_.push(69);
  ASSERT_EQ(copy.front(), s0_.front());
  ASSERT_EQ(copy.back(), s0_.back());
}

TEST_F(QueueTest, move_Constr) {
  s21::queue<int> moved(std::move(s0_));
  ASSERT_EQ(moved.size(), 5U);
  ASSERT_EQ(moved.back(), 5);
}

TEST_F(QueueTest, copy_assignment) {
  s21::queue<int> copy;
  copy = s0_;
  ASSERT_EQ(copy.front(), s0_.front());
  copy.pop();
  s0_.pop();
  ASSERT_EQ(copy.front(), s0_.front());
  copy.pop();
  s0_.pop();
  ASSERT_EQ(copy.front(), s0_.front());
  copy.pop();
  s0_.pop();
  ASSERT_EQ(copy.front(), s0_.front());
  copy.pop();
  s0_.pop();
  ASSERT_EQ(copy.front(), s0_.front());
  copy.pop();
  s0_.pop();

  ASSERT_TRUE(copy.empty());
  ASSERT_TRUE(s0_.empty());

  copy.push(69);
  s0_.push(69);
  ASSERT_EQ(copy.front(), s0_.front());
}

TEST_F(QueueTest, move_assignment) {
  s21::queue<int> moved;
  moved = std::move(s0_);
  ASSERT_EQ(moved.size(), 5U);
  ASSERT_EQ(moved.back(), 5);
}

TEST_F(QueueTest, swap) {
  ASSERT_EQ(s1_.size(), 0U);
  ASSERT_EQ(s0_.size(), 5U);
  ASSERT_FALSE(s0_.empty());
  ASSERT_TRUE(s1_.empty());
  s0_.swap(s1_);
  ASSERT_FALSE(s1_.empty());
  ASSERT_TRUE(s0_.empty());
  ASSERT_EQ(s0_.size(), 0U);
  ASSERT_EQ(s1_.size(), 5U);
}

TEST(Queue, consts) {
  s21::queue<int> x;
  std::queue<int> y;
  int val = 69;
  x.push(val);
  y.push(val);
  x.push(val);
  x.push(val);
  y.push(val);
  y.push(val);
  const s21::queue<int> cx = x;
  const std::queue<int> cy = y;

  ASSERT_EQ(cx.front(), cy.front());
  ASSERT_EQ(cx.back(), cy.back());
}

TEST_F(QueueTest, swap_test) {
  std::queue<int> s0({1, 2, 3, 4, 5});
  ASSERT_EQ(s0_.size(), 5U);

  for (int i = 0; i < 5; ++i) {
    ASSERT_EQ(s0.front(), s0_.front());
    s0.pop();
    s0_.pop();
  }
}

TEST_F(QueueTest, push_pop_front_empty_size) {
  std::queue<int> s0;
  ASSERT_EQ(s1_.size(), 0U);
  ASSERT_TRUE(s1_.empty());

  s1_.push(1);
  s0.push(1);
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.push(2);
  s0.push(2);
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.push(3);
  s0.push(3);
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.push(4);
  s0.push(4);
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.push(5);
  s0.push(5);
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.pop();
  s0.pop();
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.pop();
  s0.pop();
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.pop();
  s0.pop();
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.pop();
  s0.pop();
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.pop();
  s0.pop();
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_TRUE(s1_.empty());
  ASSERT_TRUE(s0.empty());
}

// pop, push, size, empty, size
TEST_F(QueueTest, front_pop_push_size_empty) {
  std::queue<int> s0;
  ASSERT_EQ(s1_.size(), 0U);
  ASSERT_TRUE(s1_.empty());

  s1_.push(1);
  s0.push(1);
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.push(2);
  s0.push(2);
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.push(3);
  s0.push(3);
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.push(4);
  s0.push(4);
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.push(5);
  s0.push(5);
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.pop();
  s0.pop();
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.pop();
  s0.pop();
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.pop();
  s0.pop();
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.pop();
  s0.pop();
  ASSERT_EQ(s1_.front(), s0.front());
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_FALSE(s1_.empty());

  s1_.pop();
  s0.pop();
  ASSERT_EQ(s1_.size(), s0.size());
  ASSERT_TRUE(s1_.empty());
  ASSERT_TRUE(s0.empty());
}

// test for s21::queue copy Constr
TEST(Queue, copy_Constr) {
  s21::queue<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(4);

  s21::queue<int> s0(s1);
  ASSERT_EQ(s1.size(), s0.size());
  ASSERT_EQ(s1.front(), s0.front());
  ASSERT_FALSE(s1.empty());
  ASSERT_FALSE(s0.empty());

  s1.pop();
  s0.pop();
  ASSERT_EQ(s1.size(), s0.size());
  ASSERT_EQ(s1.front(), s0.front());
  ASSERT_FALSE(s1.empty());
  ASSERT_FALSE(s0.empty());

  s1.pop();
  s0.pop();
  ASSERT_EQ(s1.size(), s0.size());
  ASSERT_EQ(s1.front(), s0.front());
  ASSERT_FALSE(s1.empty());
  ASSERT_FALSE(s0.empty());

  s1.pop();
  s0.pop();
  ASSERT_EQ(s1.size(), s0.size());
  ASSERT_EQ(s1.front(), s0.front());
  ASSERT_FALSE(s1.empty());
  ASSERT_FALSE(s0.empty());

  s1.pop();
  s0.pop();
  ASSERT_EQ(s1.size(), s0.size());
  ASSERT_TRUE(s1.empty());
  ASSERT_TRUE(s0.empty());
}

// test for s21::queue move Constr
TEST(Queue, move_Constr) {
  s21::queue<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(4);
  s1.push(5);

  s21::queue<int> s0(std::move(s1));
  ASSERT_EQ(s1.size(), 0U);
  ASSERT_EQ(s0.size(), 5U);
  ASSERT_TRUE(s1.empty());
  ASSERT_FALSE(s0.empty());

  ASSERT_EQ(s0.front(), 1);
  s0.pop();
  ASSERT_EQ(s0.front(), 2);
  s0.pop();
  ASSERT_EQ(s0.front(), 3);
  s0.pop();
  ASSERT_EQ(s0.front(), 4);
  s0.pop();
  ASSERT_EQ(s0.front(), 5);
  s0.pop();
  ASSERT_TRUE(s0.empty());
}

// s21::queue Constr tests
TEST(Queue, Constr) {
  s21::queue<int> s0;
  ASSERT_EQ(s0.size(), 0U);
  ASSERT_TRUE(s0.empty());
}

// s21::queue copy assignment tests
TEST(Queue, copy_assignment) {
  s21::queue<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(4);

  s21::queue<int> s0;
  s0 = s1;
  ASSERT_EQ(s1.size(), s0.size());
  ASSERT_EQ(s1.front(), s0.front());
  ASSERT_FALSE(s1.empty());
  ASSERT_FALSE(s0.empty());

  s1.pop();
  s0.pop();
  ASSERT_EQ(s1.size(), s0.size());
  ASSERT_EQ(s1.front(), s0.front());
  ASSERT_FALSE(s1.empty());
  ASSERT_FALSE(s0.empty());

  s1.pop();
  s0.pop();
  ASSERT_EQ(s1.size(), s0.size());
  ASSERT_EQ(s1.front(), s0.front());
  ASSERT_FALSE(s1.empty());
  ASSERT_FALSE(s0.empty());

  s1.pop();
  s0.pop();
  ASSERT_EQ(s1.size(), s0.size());
  ASSERT_EQ(s1.front(), s0.front());
  ASSERT_FALSE(s1.empty());
  ASSERT_FALSE(s0.empty());

  s1.pop();
  s0.pop();
  ASSERT_EQ(s1.size(), s0.size());
  ASSERT_TRUE(s1.empty());
  ASSERT_TRUE(s0.empty());
}

// s21::queue move assignment tests
TEST(Queue, move_assignment) {
  s21::queue<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(4);
  s1.push(5);

  s21::queue<int> s0;
  s0 = std::move(s1);
  ASSERT_EQ(s1.size(), 0U);
  ASSERT_EQ(s0.size(), 5U);
  ASSERT_TRUE(s1.empty());
  ASSERT_FALSE(s0.empty());

  ASSERT_EQ(s0.front(), 1);
  s0.pop();
  ASSERT_EQ(s0.front(), 2);
  s0.pop();
  ASSERT_EQ(s0.front(), 3);
  s0.pop();
  ASSERT_EQ(s0.front(), 4);
  s0.pop();
  ASSERT_EQ(s0.front(), 5);
  s0.pop();
  ASSERT_TRUE(s0.empty());
}

// test for s21::queue back method
TEST(Queue, back) {
  s21::queue<int> s0;
  s0.push(1);
  s0.push(2);
  s0.push(3);
  s0.push(4);
  s0.push(5);

  ASSERT_EQ(s0.back(), 5);
  s0.pop();
  ASSERT_EQ(s0.back(), 5);
  s0.pop();
  ASSERT_EQ(s0.back(), 5);
  s0.pop();
  ASSERT_EQ(s0.back(), 5);
  s0.pop();
  ASSERT_EQ(s0.back(), 5);
  s0.pop();
  ASSERT_TRUE(s0.empty());
}
// list
TEST(LIST, case1) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  EXPECT_EQ(s21_list_int.size(), 0U);
  EXPECT_EQ(s21_list_double.size(), 0U);
  EXPECT_EQ(s21_list_string.size(), 0U);
}

TEST(LIST, case2) {
  s21::list<int> s21_list_int(5);
  s21::list<double> s21_list_double(5);
  s21::list<std::string> s21_list_string(5);

  EXPECT_EQ(s21_list_int.size(), 5U);
  EXPECT_EQ(s21_list_double.size(), 5U);
  EXPECT_EQ(s21_list_string.size(), 5U);
}

TEST(LIST, case3) {
  EXPECT_THROW(s21::list<int> s21_list_int(0), std::out_of_range);
  EXPECT_THROW(s21::list<double> s21_list_double(0), std::out_of_range);
  EXPECT_THROW(s21::list<std::string> s21_list_string(0), std::out_of_range);
}

TEST(LIST, case4) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.size(), 4U);
  EXPECT_EQ(s21_list_int.front(), 1);

  EXPECT_EQ(s21_list_double.size(), 4U);
  EXPECT_EQ(s21_list_double.front(), 1.4);

  EXPECT_EQ(s21_list_string.size(), 4U);
  EXPECT_EQ(s21_list_string.front(), "Hello");
}

TEST(LIST, case5) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int(s21_list_ref_int);

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double(s21_list_ref_double);

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string(s21_list_ref_string);

  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(LIST, case6) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int = s21_list_ref_int;

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double = s21_list_ref_double;

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string = s21_list_ref_string;

  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(LIST, case7) {
  s21::list<int> s21_list_ref_int;
  s21::list<int> s21_list_res_int = s21_list_ref_int;

  s21::list<double> s21_list_ref_double;
  s21::list<double> s21_list_res_double = s21_list_ref_double;

  s21::list<std::string> s21_list_ref_string;
  s21::list<std::string> s21_list_res_string = s21_list_ref_string;

  EXPECT_EQ(s21_list_res_int.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 0U);
}

TEST(LIST, case8) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int = std::move(s21_list_ref_int);
  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double = std::move(s21_list_ref_double);
  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string = std::move(s21_list_ref_string);
  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(LIST, case9) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int;
  s21_list_res_int = std::move(s21_list_ref_int);

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double;
  s21_list_res_double = std::move(s21_list_ref_double);

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string;
  s21_list_res_string = std::move(s21_list_ref_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(LIST, case10) {
  s21::list<int> a = {43, 43, 43, 5};
  s21::list<int> b = {1};
  a = std::move(b);
  EXPECT_EQ(a.back(), 1);
}

TEST(LIST, case11) {
  size_t n = 1e4;
  s21::list<int> lst(n);
  EXPECT_EQ(lst.size(), n);
  EXPECT_TRUE(lst.max_size() != 0);
  lst.pop_back();
  lst.pop_front();
  EXPECT_EQ(lst.size(), (n - 2));
  int back = lst.back();
  int front = lst.front();
  EXPECT_EQ(back, 0);
  EXPECT_EQ(front, 0);
}

TEST(LIST, case12) {
  s21::list<double> lst = {1.032, 2.320,    3.0,   4.0,   5.0,
                           6.0,   7.000043, 8.324, 9.343, 10.0};
  EXPECT_EQ(lst.size(), 10U);
  double front = lst.front();
  EXPECT_DOUBLE_EQ(front, 1.032);
  lst.pop_front();
  double new_front = lst.front();
  EXPECT_DOUBLE_EQ(new_front, 2.320);
  lst.pop_back();
  double back = lst.back();
  EXPECT_DOUBLE_EQ(back, 9.343);
  EXPECT_EQ(lst.size(), 8U);
  lst.clear();
  EXPECT_EQ(lst.size(), 0U);
}

TEST(LIST, case13) {
  s21::list<double> lst = {1.032, 2.32,     3.0,   4.0,   5.0,
                           6.0,   7.000043, 8.324, 9.343, 10.0};
  s21::list<double> lst_cpy(lst);
  EXPECT_EQ(lst_cpy.size(), 10U);
  double front = lst_cpy.front();
  EXPECT_DOUBLE_EQ(front, 1.032);
  lst_cpy.pop_front();
  double new_front = lst_cpy.front();
  EXPECT_DOUBLE_EQ(new_front, 2.320);
  double back = lst_cpy.back();
  EXPECT_DOUBLE_EQ(back, 10.0);
  lst_cpy.pop_back();
  back = lst_cpy.back();
  EXPECT_DOUBLE_EQ(back, 9.343);
  EXPECT_EQ(lst_cpy.size(), 8U);
}

TEST(LIST, case14) {
  s21::list<double> lst = {1.032, 2.32,     3.0,   4.0,   5.0,
                           6.0,   7.000043, 8.324, 9.343, 10.0};
  s21::list<double> lst_cpy(std::move(lst));
  EXPECT_EQ(lst_cpy.size(), 10U);
  double front = lst_cpy.front();
  EXPECT_DOUBLE_EQ(front, 1.032);
  lst_cpy.pop_front();
  double new_front = lst_cpy.front();
  EXPECT_DOUBLE_EQ(new_front, 2.320);
  double back = lst_cpy.back();
  EXPECT_DOUBLE_EQ(back, 10.0);
  lst_cpy.pop_back();
  back = lst_cpy.back();
  EXPECT_DOUBLE_EQ(back, 9.343);
  EXPECT_EQ(lst_cpy.size(), 8U);
  EXPECT_EQ(lst.size(), 0U);
}

TEST(LIST, case15) {
  std::list<int> orig_list = {};
  s21::list<int> lst = {};
  auto orig_itr_end = orig_list.end();
  auto itr_end = lst.end();
  EXPECT_EQ(*orig_itr_end, *itr_end);
}

TEST(LIST, case16) {
  std::list<int> orig_list;
  s21::list<int> lst;
  auto orig_itr = orig_list.end();
  auto itr = lst.end();
  EXPECT_EQ(*orig_itr, *itr);
}

TEST(LIST_PUSH_FRONT, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.push_front(33);
  s21_list_double.push_front(33.0);
  s21_list_string.push_front("33");

  EXPECT_EQ(s21_list_int.size(), 5U);
  EXPECT_EQ(s21_list_int.front(), 33);

  EXPECT_EQ(s21_list_double.size(), 5U);
  EXPECT_EQ(s21_list_double.front(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 5U);
  EXPECT_EQ(s21_list_string.front(), "33");
}

TEST(LIST_PUSH_FRONT, case2) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  s21_list_int.push_front(33);
  s21_list_double.push_front(33.0);
  s21_list_string.push_front("33");

  EXPECT_EQ(s21_list_int.size(), 1U);
  EXPECT_EQ(s21_list_int.front(), 33);

  EXPECT_EQ(s21_list_double.size(), 1U);
  EXPECT_EQ(s21_list_double.front(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 1U);
  EXPECT_EQ(s21_list_string.front(), "33");
}

TEST(LIST_PUSH_FRONT, case3) {
  s21::list<int> s21_list_int{1};
  s21::list<double> s21_list_double{1.0};
  s21::list<std::string> s21_list_string{"1"};

  s21_list_int.push_front(33);
  s21_list_double.push_front(33.0);
  s21_list_string.push_front("33");

  EXPECT_EQ(s21_list_int.size(), 2U);
  EXPECT_EQ(s21_list_int.front(), 33);

  EXPECT_EQ(s21_list_double.size(), 2U);
  EXPECT_EQ(s21_list_double.front(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 2U);
  EXPECT_EQ(s21_list_string.front(), "33");
}

TEST(LIST_PUSH_FRONT, case4) {
  s21::list<int> li = {1, 2, 10, 3, 4, 6, 43};
  std::list<int> li_orig = {1, 2, 10, 3, 4, 6, 43};
  li.push_front(21);
  li_orig.push_front(21);
  auto itr_orig = li_orig.begin();
  for (auto itr = li.begin(); itr != li.end(); itr++) {
    EXPECT_EQ(*itr, *itr_orig);
    itr_orig++;
  }

  s21::list<int> li1;
  std::list<int> li_orig1;
  li1.push_front(21);
  li_orig1.push_front(21);
  auto itr_orig1 = li_orig1.begin();
  for (auto itr1 = li1.begin(); itr1 != li1.end(); itr1++) {
    EXPECT_EQ(*itr1, *itr_orig1);
    itr_orig1++;
  }
}

TEST(LIST_PUSH_BACK, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.push_back(33);
  s21_list_double.push_back(33.0);
  s21_list_string.push_back("33");

  EXPECT_EQ(s21_list_int.size(), 5U);
  EXPECT_EQ(s21_list_int.back(), 33);

  EXPECT_EQ(s21_list_double.size(), 5U);
  EXPECT_EQ(s21_list_double.back(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 5U);
  EXPECT_EQ(s21_list_string.back(), "33");
}

TEST(LIST_PUSH_BACK, case2) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  s21_list_int.push_back(33);
  s21_list_double.push_back(33.0);
  s21_list_string.push_back("33");

  EXPECT_EQ(s21_list_int.size(), 1U);
  EXPECT_EQ(s21_list_int.back(), 33);

  EXPECT_EQ(s21_list_double.size(), 1U);
  EXPECT_EQ(s21_list_double.back(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 1U);
  EXPECT_EQ(s21_list_string.back(), "33");
}

TEST(LIST_PUSH_BACK, case3) {
  s21::list<int> s21_list_int{1};
  s21::list<double> s21_list_double{1.0};
  s21::list<std::string> s21_list_string{"1"};

  s21_list_int.push_back(33);
  s21_list_double.push_back(33.0);
  s21_list_string.push_back("33");

  EXPECT_EQ(s21_list_int.size(), 2U);
  EXPECT_EQ(s21_list_int.back(), 33);

  EXPECT_EQ(s21_list_double.size(), 2U);
  EXPECT_EQ(s21_list_double.back(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 2U);
  EXPECT_EQ(s21_list_string.back(), "33");
}

TEST(LIST_POP_FRONT, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.pop_front();
  s21_list_double.pop_front();
  s21_list_string.pop_front();

  EXPECT_EQ(s21_list_int.size(), 3U);
  EXPECT_EQ(s21_list_int.front(), 4);

  EXPECT_EQ(s21_list_double.size(), 3U);
  EXPECT_EQ(s21_list_double.front(), 4.8);

  EXPECT_EQ(s21_list_string.size(), 3U);
  EXPECT_EQ(s21_list_string.front(), ",");
}

TEST(LIST_POP_FRONT, case2) {
  s21::list<int> s21_list_int{1};
  s21::list<double> s21_list_double{1.0};
  s21::list<std::string> s21_list_string{"1"};

  s21_list_int.pop_front();
  s21_list_double.pop_front();
  s21_list_string.pop_front();

  EXPECT_EQ(s21_list_int.size(), 0U);
  EXPECT_EQ(s21_list_double.size(), 0U);
  EXPECT_EQ(s21_list_string.size(), 0U);
}

TEST(LIST_POP_FRONT, case3) {
  s21::list<int> li = {1, 2, 10, 3, 4, 6, 43};
  std::list<int> li_orig = {1, 2, 10, 3, 4, 6, 43};
  li.pop_front();
  li_orig.pop_front();
  auto itr_orig = li_orig.begin();
  for (auto itr = li.begin(); itr != li.end(); itr++) {
    EXPECT_EQ(*itr, *itr_orig);
    itr_orig++;
  }
}

TEST(LIST_POP_BACK, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.pop_back();
  s21_list_double.pop_back();
  s21_list_string.pop_back();

  EXPECT_EQ(s21_list_int.size(), 3U);
  EXPECT_EQ(s21_list_int.back(), 8);

  EXPECT_EQ(s21_list_double.size(), 3U);
  EXPECT_EQ(s21_list_double.back(), 8.9);

  EXPECT_EQ(s21_list_string.size(), 3U);
  EXPECT_EQ(s21_list_string.back(), "world");
}

TEST(LIST_POP_BACK, case2) {
  s21::list<int> s21_list_int{1, 2};
  s21::list<double> s21_list_double{1.0, 2.0};
  s21::list<std::string> s21_list_string{"1", "2"};

  s21_list_int.pop_back();
  s21_list_double.pop_back();
  s21_list_string.pop_back();

  EXPECT_EQ(s21_list_int.size(), 1U);
  EXPECT_EQ(s21_list_double.size(), 1U);
  EXPECT_EQ(s21_list_string.size(), 1U);
}

TEST(LIST_FRONT, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.front(), 1);
  EXPECT_EQ(s21_list_double.front(), 1.4);
  EXPECT_EQ(s21_list_string.front(), "Hello");
}

TEST(LIST_FRONT, case2) {
  s21::list<char> li = {'l', 'o', 'l'};
  std::list<char> li_orig = {'l', 'o', 'l'};
  EXPECT_EQ(li.front(), li_orig.front());
}

TEST(back, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.back(), 9);
  EXPECT_EQ(s21_list_double.back(), 9.1);
  EXPECT_EQ(s21_list_string.back(), "!");
}

TEST(swap, case1) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int{12, 13};

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double{11.0, 12.0, 13.0};

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string{"12", "13", "14", "15"};

  s21_list_ref_int.swap(s21_list_res_int);
  s21_list_ref_double.swap(s21_list_res_double);
  s21_list_ref_string.swap(s21_list_res_string);

  EXPECT_EQ(s21_list_ref_int.size(), 2U);
  EXPECT_EQ(s21_list_ref_int.front(), 12);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 3U);
  EXPECT_EQ(s21_list_ref_double.front(), 11.0);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 4U);
  EXPECT_EQ(s21_list_ref_string.front(), "12");
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(swap, case2) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int;

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double;

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string;

  s21_list_ref_int.swap(s21_list_res_int);
  s21_list_ref_double.swap(s21_list_res_double);
  s21_list_ref_string.swap(s21_list_res_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(sort, case1) {
  s21::list<int> s21_list_int{8, 1, 4, 9};
  s21::list<double> s21_list_double{9.1, 1.4, 4.8, 8.9};
  s21::list<std::string> s21_list_string{"hello", "there", "21", "school"};

  s21_list_int.sort();
  s21_list_double.sort();
  s21_list_string.sort();

  EXPECT_EQ(s21_list_int.front(), 1);
  EXPECT_EQ(s21_list_double.front(), 1.4);
  EXPECT_EQ(s21_list_string.front(), "21");
}

TEST(sort, case2) {
  s21::list<int> s21_list_int{8};
  s21::list<double> s21_list_double{9.1};
  s21::list<std::string> s21_list_string{"hello"};

  s21_list_int.sort();
  s21_list_double.sort();
  s21_list_string.sort();

  EXPECT_EQ(s21_list_int.front(), 8);
  EXPECT_EQ(s21_list_double.front(), 9.1);
  EXPECT_EQ(s21_list_string.front(), "hello");
}

TEST(merge, case1) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int{12, 13};
  std::list<int> std_list_ref_int{1, 4, 8, 9};
  std::list<int> std_list_res_int{12, 13};

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double{11.0, 12.0, 13.0};
  std::list<double> std_list_ref_double{1.4, 4.8, 8.9, 9.1};
  std::list<double> std_list_res_double{11.0, 12.0, 13.0};

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string{"12", "13", "14", "15"};
  std::list<std::string> std_list_ref_string{"Hello", ",", "world", "!"};
  std::list<std::string> std_list_res_string{"12", "13", "14", "15"};

  s21_list_res_int.merge(s21_list_ref_int);
  s21_list_res_double.merge(s21_list_ref_double);
  s21_list_res_string.merge(s21_list_ref_string);
  std_list_res_int.merge(std_list_ref_int);
  std_list_res_double.merge(std_list_ref_double);
  std_list_res_string.merge(std_list_ref_string);

  EXPECT_EQ(s21_list_ref_int.size(), std_list_ref_int.size());
  EXPECT_EQ(s21_list_res_int.size(), std_list_res_int.size());
  EXPECT_EQ(s21_list_res_int.front(), std_list_res_int.front());

  EXPECT_EQ(s21_list_ref_double.size(), std_list_ref_double.size());
  EXPECT_EQ(s21_list_res_double.size(), std_list_res_double.size());
  EXPECT_EQ(s21_list_res_double.front(), std_list_res_double.front());

  EXPECT_EQ(s21_list_ref_string.size(), std_list_ref_string.size());
  EXPECT_EQ(s21_list_res_string.size(), std_list_res_string.size());
  EXPECT_EQ(s21_list_res_string.front(), std_list_res_string.front());
}

TEST(merge, case2) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int;

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double;

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string;

  s21_list_res_int.merge(s21_list_ref_int);
  s21_list_res_double.merge(s21_list_ref_double);
  s21_list_res_string.merge(s21_list_ref_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(merge, case3) {
  s21::list<int> li = {1, 2, 10, 3, 4, 6, 43};
  std::list<int> li_orig = {1, 2, 10, 3, 4, 6, 43};
  s21::list<int> list_merge = {2, 5, 7, 9};
  std::list<int> list_merge_orig = {2, 5, 7, 9};
  li.sort();
  li_orig.sort();
  li.merge(list_merge);
  li_orig.merge(list_merge_orig);
  auto itr_orig = li_orig.begin();
  for (auto itr = li.begin(); itr != li.end(); itr++) {
    EXPECT_EQ(*itr, *itr_orig);
    itr_orig++;
  }
}

TEST(reverse, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.reverse();
  s21_list_double.reverse();
  s21_list_string.reverse();

  EXPECT_EQ(s21_list_int.front(), 9);
  EXPECT_EQ(s21_list_double.front(), 9.1);
  EXPECT_EQ(s21_list_string.front(), "!");
}

TEST(reverse, case2) {
  s21::list<int> s21_list_int{1};
  s21::list<double> s21_list_double{1.4};
  s21::list<std::string> s21_list_string{"Hello"};

  s21_list_int.reverse();
  s21_list_double.reverse();
  s21_list_string.reverse();

  EXPECT_EQ(s21_list_int.front(), 1);
  EXPECT_EQ(s21_list_double.front(), 1.4);
  EXPECT_EQ(s21_list_string.front(), "Hello");
}

TEST(unique, case1) {
  s21::list<int> s21_list_int{1, 1, 4, 4, 8, 8, 8, 9, 9, 9, 9, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 1.4, 4.8, 8.9, 9.1,
                                    1.4, 4.8, 8.9, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",",     "Hello", ",",
                                         "world", ",",     "world", "!",
                                         "!",     "world", "!"};

  s21_list_int.unique();
  s21_list_double.unique();
  s21_list_string.unique();

  EXPECT_EQ(s21_list_int.size(), 4U);
  EXPECT_EQ(s21_list_double.size(), 10U);
  EXPECT_EQ(s21_list_string.size(), 10U);
}

TEST(unique, case2) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.unique();
  s21_list_double.unique();
  s21_list_string.unique();

  EXPECT_EQ(s21_list_int.size(), 4U);
  EXPECT_EQ(s21_list_double.size(), 4U);
  EXPECT_EQ(s21_list_string.size(), 4U);
}

TEST(unique, case3) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  s21_list_int.unique();
  s21_list_double.unique();
  s21_list_string.unique();

  EXPECT_EQ(s21_list_int.size(), 0U);
  EXPECT_EQ(s21_list_double.size(), 0U);
  EXPECT_EQ(s21_list_string.size(), 0U);
}

TEST(size, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.size(), 4U);
  EXPECT_EQ(s21_list_double.size(), 4U);
  EXPECT_EQ(s21_list_string.size(), 4U);
}

TEST(size, case2) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  EXPECT_EQ(s21_list_int.size(), 0U);
  EXPECT_EQ(s21_list_double.size(), 0U);
  EXPECT_EQ(s21_list_string.size(), 0U);
}

TEST(max_size, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  std::list<int> std_list_int{1, 4, 8, 9};

  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  std::list<double> std_list_double{1.4, 4.8, 8.9, 9.1};

  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};
  std::list<std::string> std_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.max_size(), std::numeric_limits<std::size_t>::max());
  EXPECT_EQ(s21_list_double.max_size(),
            std::numeric_limits<std::size_t>::max());
  EXPECT_EQ(s21_list_string.max_size(),
            std::numeric_limits<std::size_t>::max());
}

TEST(LIST_EMPTY, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.empty(), 0);
  EXPECT_EQ(s21_list_double.empty(), 0);
  EXPECT_EQ(s21_list_double.empty(), 0);
}

TEST(LIST_EMPTY, case2) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  EXPECT_EQ(s21_list_int.empty(), 1);
  EXPECT_EQ(s21_list_double.empty(), 1);
  EXPECT_EQ(s21_list_double.empty(), 1);
}

TEST(LIST_EMPTY, case3) {
  s21::list<int> li;
  std::list<int> li_orig;
  EXPECT_EQ(li.front(), li_orig.front());
}

TEST(LIST_EMPTY, case4) {
  s21::list<int> li;
  std::list<int> li_orig;
  EXPECT_EQ(li.back(), li_orig.back());
}

TEST(LIST_INSERT, case1) {
  s21::list<int> s21_list_int{1, 4, 8, 9};
  s21::list<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::list<std::string> s21_list_string{"Hello", ",", "world", "!"};

  auto it_int = s21_list_int.begin();
  it_int = s21_list_int.insert(it_int, 13);
  ++it_int;
  ++it_int;
  it_int = s21_list_int.insert(it_int, 13);
  it_int = s21_list_int.begin();
  ++it_int;
  ++it_int;
  EXPECT_EQ(s21_list_int.front(), 13);
  EXPECT_EQ(*it_int, 13);

  auto it_double = s21_list_double.begin();
  it_double = s21_list_double.insert(it_double, 21.0);
  ++it_double;
  ++it_double;
  it_double = s21_list_double.insert(it_double, 21.0);
  it_double = s21_list_double.begin();
  ++it_double;
  ++it_double;
  EXPECT_EQ(s21_list_double.front(), 21.0);
  EXPECT_EQ(*it_double, 21.0);

  auto it_string = s21_list_string.begin();
  it_string = s21_list_string.insert(it_string, "HI");
  ++it_string;
  ++it_string;
  it_string = s21_list_string.insert(it_string, "HI");
  it_string = s21_list_string.begin();
  ++it_string;
  ++it_string;
  EXPECT_EQ(s21_list_string.front(), "HI");
  EXPECT_EQ(*it_string, "HI");
}

TEST(LIST_INSERT, case2) {
  s21::list<int> s21_list_int;
  s21::list<double> s21_list_double;
  s21::list<std::string> s21_list_string;

  auto it_int = s21_list_int.begin();
  it_int = s21_list_int.insert(it_int, 13);
  EXPECT_EQ(s21_list_int.front(), 13);

  auto it_double = s21_list_double.begin();
  it_double = s21_list_double.insert(it_double, 21.0);
  EXPECT_EQ(s21_list_double.front(), 21.0);

  auto it_string = s21_list_string.begin();
  it_string = s21_list_string.insert(it_string, "HI");
  EXPECT_EQ(s21_list_string.front(), "HI");
}

TEST(LIST_INSERT, case3) {
  s21::list<int> s21_list_int{1};
  s21::list<double> s21_list_double{1.0};
  s21::list<std::string> s21_list_string{"1"};

  auto it_int = s21_list_int.begin();
  it_int = s21_list_int.insert(it_int, 13);
  EXPECT_EQ(s21_list_int.front(), 13);

  auto it_double = s21_list_double.begin();
  it_double = s21_list_double.insert(it_double, 21.0);
  EXPECT_EQ(s21_list_double.front(), 21.0);

  auto it_string = s21_list_string.begin();
  it_string = s21_list_string.insert(it_string, "HI");
  EXPECT_EQ(s21_list_string.front(), "HI");
}

TEST(LIST_INSERT, case4) {
  s21::list<int> li;
  std::list<int> li_orig;
  auto itr = li.begin();
  auto itr_orig = li_orig.begin();
  itr = li.insert(itr, 21);
  itr_orig = li_orig.insert(itr_orig, 21);
  EXPECT_EQ(*itr, *itr_orig);

  s21::list<int> li1 = {1, 2, 3, 4, 6, 43};
  std::list<int> li_orig1 = {1, 2, 3, 4, 6, 43};
  auto itr1 = li1.begin();
  auto itr_orig1 = li_orig1.begin();
  itr1 = li1.insert(itr1, 21);
  itr_orig1 = li_orig1.insert(itr_orig1, 21);
  auto end1 = li1.end();
  auto end_orig1 = li_orig1.end();
  while (itr1 != end1 && itr_orig1 != end_orig1) {
    EXPECT_EQ(*itr1, *itr_orig1);
    itr1++;
    itr_orig1++;
  }

  s21::list<int> li2 = {1, 2, 3, 4, 6, 44};
  std::list<int> li_orig2 = {1, 2, 3, 4, 6, 44};
  auto itr2 = li2.end();
  auto itr_orig2 = li_orig2.end();
  itr2 = li2.insert(itr2, 21);
  itr_orig2 = li_orig2.insert(itr_orig2, 21);
  itr2--;
  itr_orig2--;
  while (itr2 != li2.begin() && itr_orig2 != li_orig2.begin()) {
    EXPECT_EQ(*itr2, *itr_orig2);
    itr2--;
    itr_orig2--;
  }
}

TEST(LIST_SPLICE, case1) {
  s21::list<int> s21_list_ref_int{3, 5};
  s21::list<int> s21_list_res_int{1, 4, 8, 9};

  s21::list<double> s21_list_ref_double{5.6, 7.1};
  s21::list<double> s21_list_res_double{1.4, 4.8, 8.9, 9.1};

  s21::list<std::string> s21_list_ref_string{"Hi"};
  s21::list<std::string> s21_list_res_string{"Hello", ",", "world", "!"};

  auto it_int = s21_list_res_int.begin();
  s21_list_res_int.splice(it_int, s21_list_ref_int);
  EXPECT_EQ(*(s21_list_res_int.begin()), 3);
  EXPECT_EQ(*(++(s21_list_res_int.begin())), 5);

  auto it_double = s21_list_res_double.begin();
  s21_list_res_double.splice(it_double, s21_list_ref_double);
  EXPECT_EQ(*(s21_list_res_double.begin()), 5.6);
  EXPECT_EQ(*(++(s21_list_res_double.begin())), 7.1);

  auto it_string = s21_list_res_string.begin();
  s21_list_res_string.splice(it_string, s21_list_ref_string);
  EXPECT_EQ(*(s21_list_res_string.begin()), "Hi");
}

TEST(LIST_SPLICE, case2) {
  s21::list<int> s21_list_ref_int;
  s21::list<int> s21_list_res_int{1, 4, 8, 9};

  s21::list<double> s21_list_ref_double;
  s21::list<double> s21_list_res_double{1.4, 4.8, 8.9, 9.1};

  s21::list<std::string> s21_list_ref_string;
  s21::list<std::string> s21_list_res_string{"Hello", ",", "world", "!"};

  auto it_int = s21_list_res_int.begin();
  s21_list_res_int.splice(it_int, s21_list_ref_int);
  EXPECT_EQ(*(s21_list_res_int.begin()), 1);

  auto it_double = s21_list_res_double.begin();
  s21_list_res_double.splice(it_double, s21_list_ref_double);
  EXPECT_EQ(*(s21_list_res_double.begin()), 1.4);

  auto it_string = s21_list_res_string.begin();
  s21_list_res_string.splice(it_string, s21_list_ref_string);
  EXPECT_EQ(*(s21_list_res_string.begin()), "Hello");
}

TEST(LIST_SPLICE, case3) {
  s21::list<int> s21_list_ref_int{1, 4, 8, 9};
  s21::list<int> s21_list_res_int;

  s21::list<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::list<double> s21_list_res_double;

  s21::list<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::list<std::string> s21_list_res_string;

  auto it_int = s21_list_res_int.begin();
  s21_list_res_int.splice(it_int, s21_list_ref_int);
  EXPECT_EQ(*(s21_list_res_int.begin()), 1);

  auto it_double = s21_list_res_double.begin();
  s21_list_res_double.splice(it_double, s21_list_ref_double);
  EXPECT_EQ(*(s21_list_res_double.begin()), 1.4);

  auto it_string = s21_list_res_string.begin();
  s21_list_res_string.splice(it_string, s21_list_ref_string);
  EXPECT_EQ(*(s21_list_res_string.begin()), "Hello");
}

TEST(LIST_ITERATOR, case1) {
  s21::list<int> li = {1, 2, 3, 4, 6, 43};
  std::list<int> li_orig = {1, 2, 3, 4, 6, 43};
  unsigned int n = li.size();
  unsigned int n_orig = li_orig.size();
  EXPECT_EQ(n, n_orig);
  auto itr = li.begin();
  auto itr_orig = li_orig.begin();
  auto end = li.end();
  auto end_orig = li_orig.end();
  while (itr != end && itr_orig != end_orig) {
    EXPECT_EQ(*itr, *itr_orig);
    itr++;
    itr_orig++;
  }
}

TEST(LIST_ITERATOR, case2) {
  s21::list<int> li = {1, 2, 3, 4, 6, 43};
  std::list<int> li_orig = {1, 2, 3, 4, 6, 43};
  unsigned int n = li.size();
  unsigned int n_orig = li_orig.size();
  EXPECT_EQ(n, n_orig);
  auto itr = li.end();
  auto itr_orig = li_orig.end();
  itr--;
  itr_orig--;
  auto end = li.begin();
  auto end_orig = li_orig.begin();
  while (itr != end && itr_orig != end_orig) {
    EXPECT_EQ(*itr, *itr_orig);
    itr--;
    itr_orig--;
  }
}

TEST(List, Constr_Default) {
  s21::list<int> our_list;
  std::list<int> std_list;
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Constr_Size) {
  s21::list<int> our_list(5);
  std::list<int> std_list(5);
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(List, Constr_List) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Constr_Copy) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy(our_list);
  std::list<int> std_copy(std_list);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(List, Operator_Copy) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy;
  our_copy = our_list;
  std::list<int> std_copy;
  std_copy = std_list;
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(List, Constr_Move) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy(std::move(our_list));
  std::list<int> std_copy(std::move(std_list));
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Operator_Move) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy;
  our_copy = std::move(our_list);
  std::list<int> std_copy;
  std_copy = std::move(std_list);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(List, Size) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(List, Push_Front) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_front(1);
  std_list.push_front(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_front(2);
  std_list.push_front(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_front(3);
  std_list.push_front(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Push_Back) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Pop_Front) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_front();
  std_list.pop_front();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Pop_Back) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_back();
  std_list.pop_back();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Iterator_Begin) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Iterator_BeginPlusAndMinus) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  ++our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  --our_it;
  --std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Iterator_End_Last) {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int>::iterator our_it;
  our_it = our_list.end();
  --our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.end();
  --std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Insert) {
  s21::list<int> our_list;
  std::list<int> std_list;
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  our_list.insert(our_it, 5);
  std_list.insert(std_it, 5);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.insert(our_it, 7);
  std_list.insert(std_it, 7);
  our_list.insert(our_it, 9);
  std_list.insert(std_it, 9);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Erase) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.erase(our_list.begin());
  std_list.erase(std_list.begin());
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  ++our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Splice) {
  s21::list<int> our_list_first = {1};
  s21::list<int> our_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  s21::list<int>::iterator our_it = our_list_first.begin();
  std::list<int>::iterator std_it = std_list_first.begin();
  our_list_first.splice(our_it, our_list_second);
  std_list_first.splice(std_it, std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
  EXPECT_EQ(our_list_first.back(), std_list_first.back());
}

TEST(List, Merge) {
  s21::list<int> our_list_first = {1};
  s21::list<int> our_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  our_list_first.merge(our_list_second);
  std_list_first.merge(std_list_second);
  EXPECT_EQ(our_list_first.front(), std_list_first.front());
  EXPECT_EQ(our_list_first.back(), std_list_first.back());
  EXPECT_EQ(our_list_second.empty(), std_list_second.empty());
}

TEST(List, Reverse) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.reverse();
  std_list.reverse();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
}

TEST(List, Unique) {
  s21::list<int> our_list = {1, 2, 2, 3, 3};
  std::list<int> std_list = {1, 2, 2, 3, 3};
  s21::list<int>::iterator our_it;
  std::list<int>::iterator std_it;
  our_list.unique();
  std_list.unique();
  our_it = our_list.begin();
  std_it = std_list.begin();
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Sort) {
  s21::list<int> our_list = {2, 4, 1, 3, 5};
  std::list<int> std_list = {2, 4, 1, 3, 5};
  s21::list<int>::iterator our_it;
  std::list<int>::iterator std_it;
  our_list.sort();
  std_list.sort();
  our_it = our_list.begin();
  std_it = std_list.begin();
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
  ++our_it;
  ++std_it;
  EXPECT_EQ(*our_it, *std_it);
}

TEST(List, Insert_Many) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  s21::list<int>::iterator our_it = our_list.begin();
  ++our_it;
  our_list.insert_many(our_it, 7, 8, 9);
  our_it = our_list.begin();
  EXPECT_EQ(*our_it, 1);
  ++our_it;
  EXPECT_EQ(*our_it, 7);
  ++our_it;
  EXPECT_EQ(*our_it, 8);
  ++our_it;
  EXPECT_EQ(*our_it, 9);
  ++our_it;
  EXPECT_EQ(*our_it, 2);
}

TEST(List, Insert_Many_Back) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  s21::list<int>::iterator our_it;
  our_list.insert_many_back(7, 8, 9);
  our_it = our_list.end();
  --our_it;
  EXPECT_EQ(*our_it, 9);
  --our_it;
  EXPECT_EQ(*our_it, 8);
  --our_it;
  EXPECT_EQ(*our_it, 7);
  --our_it;
  EXPECT_EQ(*our_it, 5);
  --our_it;
  EXPECT_EQ(*our_it, 4);
}

TEST(List, Insert_Many_Front) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  s21::list<int>::iterator our_it;
  our_list.insert_many_front(7, 8, 9);
  our_it = our_list.begin();
  EXPECT_EQ(*our_it, 9);
  ++our_it;
  EXPECT_EQ(*our_it, 8);
  ++our_it;
  EXPECT_EQ(*our_it, 7);
  ++our_it;
  EXPECT_EQ(*our_it, 1);
  ++our_it;
  EXPECT_EQ(*our_it, 2);
}

/*--->Map tests<---*/

TEST(MapTest, MapConstrs_Default) {
  s21::Map<int, int> own;
  std::map<int, int> orig;

  EXPECT_TRUE(own.isEmpty());
  EXPECT_TRUE(orig.empty());
}

TEST(MapTest, MapConstrs_InitializerListInt) {
  s21::Map<int, int> own = {{5, 50}, {6, 60}, {7, 70}};
  std::map<int, int> orig = {{5, 50}, {6, 60}, {7, 70}};
  EXPECT_EQ(own.begin()->first, orig.begin()->first);
}

TEST(MapTest, MapConstrs_InitializerListFloat) {
  s21::Map<float, float> own = {{5.4, 50.1}, {1.6, 6.0}, {7, 70}};
  std::map<float, float> orig = {{5.4, 50.1}, {1.6, 6.0}, {7, 70}};
  EXPECT_EQ(own.begin()->first, orig.begin()->first);
}

TEST(MapTest, MapConstrs_InitializerListString) {
  s21::Map<std::string, int> own = {
      {"Exampletest1", 50}, {"Exampletest3", 60}, {"abobus", 70}};
  std::map<std::string, int> orig = {
      {"Exampletest1", 50}, {"Exampletest3", 60}, {"abobus", 70}};
  EXPECT_EQ(own.begin()->first, orig.begin()->first);
}

TEST(MapTest, MapConstrs_CopyConstr) {
  s21::Map<int, int> A = {{5, 50}, {6, 60}, {7, 70}};
  s21::Map<int, int> copied = A;
  EXPECT_EQ(A.size(), copied.size());
}

TEST(MapTest, MapConstrs_CopyAssingent) {
  s21::Map<int, int> A = {{5, 50}, {6, 60}, {7, 70}};
  s21::Map<int, int> copied;
  copied = A;
  EXPECT_EQ(A.size(), copied.size());
}

TEST(MapTest, MapConstrs_MoveConstr) {
  s21::Map<int, int> A = {{5, 50}, {6, 60}, {7, 70}};
  s21::Map<int, int> expected = {{5, 50}, {6, 60}, {7, 70}};
  s21::Map<int, int> moved = std::move(A);
  EXPECT_EQ(expected.size(), moved.size());
}

TEST(MapTest, MapConstrs_MoveAssigment) {
  s21::Map<int, int> A = {{5, 50}, {6, 60}, {7, 70}};
  s21::Map<int, int> expected = {{5, 50}, {6, 60}, {7, 70}};
  s21::Map<int, int> moved;
  moved = std::move(A);
  EXPECT_TRUE(A.empty());
  EXPECT_EQ(expected.size(), moved.size());
}

TEST(MapTest, MapIterator_MapIteratorPlus) {
  s21::Map<int, int> A = {{5, 50}, {6, 60}, {7, 70}, {8, 80}};
  auto itr = A.begin();
  itr++;
  EXPECT_EQ(itr->first, 6);
  EXPECT_EQ(itr->second, 60);
  ++itr;
  EXPECT_EQ(itr->first, 7);
  EXPECT_EQ(itr->second, 70);
}

TEST(MapTest, MapIterator_MapIteratorMinus) {
  s21::Map<int, int> A = {{5, 50}, {6, 60}, {7, 70}, {8, 80}};
  auto itr = A.end();
  --itr;
  EXPECT_EQ(itr->first, 7);
  EXPECT_EQ(itr->second, 70);
  itr--;
  EXPECT_EQ(itr->first, 6);
  EXPECT_EQ(itr->second, 60);
}

TEST(MapTest, MapIterator_MapIteratorString) {
  s21::Map<std::string, std::string> A = {{"Exampletest1", "Exampletest2"},
                                          {"Exampletest3", "Exampletest4"},
                                          {"Exampletest5", "Exampletest6"},
                                          {"No name", "No nickname"}};
  auto itr = A.begin();
  EXPECT_EQ(itr->first, "Exampletest1");
  EXPECT_EQ(itr->second, "Exampletest2");
  ++itr;
  EXPECT_EQ(itr->first, "Exampletest3");
  EXPECT_EQ(itr->second, "Exampletest4");
}

TEST(MapTest, MapFind_FindAndModify) {
  s21::Map<std::string, std::string> A = {{"Exampletest1", "Exampletest2"},
                                          {"Exampletest3", "Exampletest4"},
                                          {"Exampletest5", "Exampletest6"},
                                          {"Exampletest7", "kek"}};
  auto it = A.find("Exampletest7");
  EXPECT_EQ(it->second, "kek");
  it->second = "lolkek";
  EXPECT_EQ(A.find("Exampletest7")->second, "lolkek");
}

TEST(MapTest, MapFind_JustFind) {
  s21::Map<int, std::string> A = {{1, "Exampletest2"},
                                  {2, "Exampletest4"},
                                  {3, "Exampletest6"},
                                  {4, "dreamcat"}};
  auto it = A.find(2);
  EXPECT_EQ(it->second, "Exampletest4");
}

TEST(MapTest, MapClear_Test1) {
  s21::Map<std::string, std::string> A = {{"Exampletest1", "Exampletest2"},
                                          {"Exampletest3", "Exampletest4"},
                                          {"Exampletest5", "Exampletest6"},
                                          {"Exampletest7", "kek"}};
  A.clear();
  EXPECT_TRUE(A.empty());
}

TEST(MapTest, MapClear_Test2) {
  s21::Map<std::string, std::string> A = {{"Exampletest1", "Exampletest2"},
                                          {"Exampletest3", "Exampletest4"},
                                          {"Exampletest5", "Exampletest6"},
                                          {"Exampletest7", "kek"}};
  A.clear();
  EXPECT_TRUE(A.empty());
}

TEST(MapTest, MapClear_ClearEmptyMap) {
  s21::Map<std::string, std::string> my_map;
  my_map.clear();
  EXPECT_TRUE(my_map.empty());
}

TEST(MapTest, MapAt_Test0) {
  s21::Map<int, int> a{{1, 10}, {2, 20}, {3, 30}};
  std::map<int, int> b{{1, 10}, {2, 20}, {3, 30}};

  EXPECT_EQ(a.at(2), b.at(2));
  EXPECT_EQ(a.at(2), 20);
  EXPECT_ANY_THROW(a.at(5));
  EXPECT_ANY_THROW(b.at(5));
}

TEST(MapTest, MapSquareBrackets_Test0) {
  s21::Map<int, int> a{{1, 10}, {2, 20}, {3, 30}};
  std::map<int, int> b{{1, 10}, {2, 20}, {3, 30}};
  b[2] = 5;
  a[2] = 5;
  EXPECT_EQ(a[2], 5);
  EXPECT_EQ(b[2], 5);
}

TEST(MapTest, MapSquareBrackets_Test1) {
  s21::Map<int, int> a{{1, 10}, {2, 20}, {3, 30}};
  std::map<int, int> b{{1, 10}, {2, 20}, {3, 30}};

  b[4] = 5;
  EXPECT_EQ(b[4], 5);
}

TEST(MapTest, MapSquareBrackets_Test2) {
  s21::Map<std::string, std::string> a = {{"Exampletest1", "Exampletest2"},
                                          {"Exampletest3", "Exampletest4"},
                                          {"Exampletest5", "Exampletest6"},
                                          {"Exampletest7", "kek"}};
  EXPECT_EQ(a["Exampletest3"], "Exampletest4");
}

TEST(MapTest, MapInsert_BaseInsert) {
  s21::Map<std::string, std::string> my_map = {
      {"Exampletest1", "Exampletest2"}};
  my_map.insert({"Exampletest3", "Exampletest4"});
  EXPECT_EQ(my_map["Exampletest3"], "Exampletest4");
}

TEST(MapTest, MapInsert_InsertExistingKey) {
  s21::Map<std::string, std::string> my_map = {
      {"Exampletest1", "Exampletest2"}, {"Exampletest3", "Exampletest4"}};
  my_map.insert({"Exampletest3", "Liyaskin"});
  EXPECT_EQ(my_map["Exampletest3"], "Exampletest4");
}

TEST(MapTest, MapInsert_InsertInEmptyMap) {
  s21::Map<std::string, std::string> my_map;
  my_map.insert({"Exampletest3", "Exampletest4"});
  EXPECT_EQ(my_map["Exampletest3"], "Exampletest4");
}

TEST(MapTest, MapInsert_InsertMultipleElements) {
  s21::Map<std::string, std::string> my_map;
  my_map.insert({"Exampletest3", "Exampletest4"});
  my_map.insert({"Exampletest1", "Exampletest2"});
  my_map.insert({"Exampletest5", "Exampletest6"});
  EXPECT_EQ(my_map["Exampletest3"], "Exampletest4");
  EXPECT_EQ(my_map["Exampletest1"], "Exampletest2");
}

TEST(MapTest, MapInsertByKeyVal_InsertExistingKey) {
  s21::Map<std::string, std::string> my_map = {
      {"Exampletest1", "Exampletest2"}, {"Exampletest3", "Exampletest4"}};
  my_map.insert({"Exampletest3", "Liyaskin"});
  EXPECT_EQ(my_map["Exampletest1"], "Exampletest2");
}

TEST(MapTest, MapInsertByKeyVal_InsertMultipleElements) {
  s21::Map<std::string, std::string> my_map;
  my_map.insert({"Exampletest3", "Exampletest4"});
  my_map.insert({"Exampletest1", "Exampletest2"});
  my_map.insert({"Exampletest5", "Exampletest6"});
  EXPECT_EQ(my_map["Exampletest3"], "Exampletest4");
  EXPECT_EQ(my_map["Exampletest5"], "Exampletest6");
  EXPECT_EQ(my_map["Exampletest1"], "Exampletest2");
}

TEST(MapTest, MapInsertOrAssign_InsertValue) {
  s21::Map<std::string, std::string> my_map = {{"Exampletest1", "unknown"},
                                               {"Exampletest3", "unknown"}};
  auto insert_res = my_map.insert_or_assign("Exampletest5", "Exampletest6");
  EXPECT_TRUE(insert_res.second);
  EXPECT_EQ(my_map["Exampletest5"], "Exampletest6");
}

TEST(MapTest, MapErase_EmptyMap) {
  s21::Map<int, int> my_map;
  my_map.erase(my_map.begin());
  EXPECT_TRUE(my_map.empty());
}

TEST(MapTest, MapErase_ExistingElement) {
  s21::Map<int, int> my_map = {{1, 10}, {2, 20}, {3, 30}};
  my_map.erase(++my_map.begin());
  EXPECT_FALSE(my_map.contains(2));
}

TEST(MapTest, MapErase_EraseSearchedElements) {
  s21::Map<std::string, std::string> my_map = {{"Exampletest1", "Exampletest2"},
                                               {"Exampletest3", "Exampletest4"},
                                               {"Exampletest5", "Exampletest6"},
                                               {"Exampletest7", "kek"}};
  my_map.erase(my_map.find("Exampletest7"));
  EXPECT_FALSE(my_map.contains("Exampletest7"));
}

TEST(MapTest, MapContains_EmptyMap) {
  s21::Map<int, std::string> my_map;
  EXPECT_FALSE(my_map.contains(5));
}

TEST(MapTest, MapContains_SingleElementPresent) {
  s21::Map<int, std::string> my_map = {{1, "one"}};
  EXPECT_TRUE(my_map.contains(1));
}

TEST(MapTest, MapContains_SingleElementAbsent) {
  s21::Map<int, std::string> my_map = {{1, "one"}};
  EXPECT_FALSE(my_map.contains(2));
}

TEST(MapTest, MapContains_MultipleElementsPresent) {
  s21::Map<char, int> my_map = {{'a', 1}, {'b', 2}, {'c', 3}};
  EXPECT_TRUE(my_map.contains('b'));
}

TEST(MapTest, MapContains_MultipleElementsAbsent) {
  s21::Map<char, int> my_map = {{'a', 1}, {'b', 2}, {'c', 3}};
  EXPECT_FALSE(my_map.contains('d'));
}

TEST(MapTest, MapSwapTest_SwapEmptyMapWithNonEmptyMap) {
  s21::Map<int, std::string> map1;
  s21::Map<int, std::string> map2 = {{1, "one"}, {2, "two"}, {3, "three"}};
  map1.swap(map2);
  EXPECT_TRUE(map2.empty());
}

TEST(MapTest, MapSwapTest_SwapNonEmptyMapWithEmptyMap) {
  s21::Map<int, std::string> map1 = {{1, "one"}, {2, "two"}, {3, "three"}};
  s21::Map<int, std::string> map2;
  map1.swap(map2);
  EXPECT_TRUE(map1.empty());
}

TEST(MapTest, MapSwapTest_SwapNonEmptyMaps) {
  s21::Map<int, std::string> map1 = {{1, "one"}, {2, "two"}, {3, "three"}};
  s21::Map<int, std::string> map2 = {{4, "four"}, {5, "five"}};
  int size_map1 = map1.size();
  int size_map2 = map2.size();
  map1.swap(map2);
  EXPECT_EQ(map1.size(), size_map2);
  EXPECT_EQ(map2.size(), size_map1);
}

TEST(MapTest, MapSwapTest_ValidIteratorsAfterSwap) {
  s21::Map<int, std::string> map1 = {{1, "one"}, {2, "two"}, {3, "three"}};
  s21::Map<int, std::string> map2 = {{4, "four"}, {5, "five"}};
  auto it_map1_begin = map1.begin();
  auto it_map2_begin = map2.begin();
  map1.swap(map2);
  EXPECT_TRUE(it_map1_begin == map2.begin());
  EXPECT_TRUE(it_map2_begin == map1.begin());
}

TEST(MapTest, MapTestMerge_Test1) {
  s21::Map<int, std::string> a{{1, "apple"}, {5, "pear"}, {10, "banana"}};
  s21::Map<int, std::string> c{
      {2, "zorro"}, {4, "batman"}, {5, "X"}, {8, "alpaca"}};
  a.merge(c);
  EXPECT_EQ(a.size(), 6);
}

TEST(MapTest, MapTestMerge_Test2) {
  s21::Map<int, std::string> a{{1, "apple"}, {2, "test"}};
  EXPECT_EQ(a.size(), 2);
}

TEST(MapTest, MapTestMerge_Test3) {
  s21::Map<int, std::string> a{{1, "apple"}, {5, "pear"}, {10, "banana"}};
  s21::Map<int, std::string> c{
      {2, "zorro"}, {4, "batman"}, {5, "X"}, {8, "alpaca"}};
  a.merge(c);
  EXPECT_EQ(a[1], "apple");
}

TEST(MapTest, MapMergeTest_MergeEmptyMaps) {
  s21::Map<int, std::string> map1;
  s21::Map<int, std::string> map2;
  map1.merge(map2);
  EXPECT_TRUE(map1.empty());
  EXPECT_TRUE(map2.empty());
}

TEST(MapTest, MapMergeTest_MergeNonEmptyMapIntoNonEmptyMap) {
  s21::Map<int, std::string> map1 = {{1, "one"}, {2, "two"}};
  s21::Map<int, std::string> map2 = {{3, "three"}, {4, "four"}};
  map1.merge(map2);
  EXPECT_TRUE(map2.empty());
}

TEST(MapTest, MapMergeTest_SelfMerge) {
  s21::Map<int, std::string> my_map = {{1, "one"}, {2, "two"}};
  my_map.merge(my_map);
  EXPECT_EQ(my_map.size(), 2);
  EXPECT_EQ(my_map[1], "one");
  EXPECT_EQ(my_map[2], "two");
}

TEST(MapTest, MapSquareBracketsNotElement_Test0) {
  s21::Map<int, int> a{{1, 10}, {2, 20}, {3, 30}};
  a[6] = 0;
  EXPECT_EQ(a[6], 0);
}

TEST(MapTest, InsertManyTest_Test0) {
  s21::Map<int, std::string> map1;
  map1.insert_many(1, "one", 2, "two", 3, "three");
  auto it = map1.begin();
  EXPECT_EQ(it.GetCurrent()->key_, 1);
  EXPECT_EQ(it.GetCurrent()->value_, "one");
  it++;
  EXPECT_EQ(it.GetCurrent()->key_, 2);
  EXPECT_EQ(it.GetCurrent()->value_, "two");
  it++;
  EXPECT_EQ(it.GetCurrent()->key_, 3);
  EXPECT_EQ(it.GetCurrent()->value_, "three");
}
TEST(SetTest, DefaultConstr) {
  s21::Set<int> s;
  EXPECT_TRUE(s.empty());
}

TEST(SetTest, InitializerListConstr) {
  s21::Set<int> s = {1, 2, 3};
  EXPECT_TRUE(s.contains(1));
  EXPECT_TRUE(s.contains(2));
  EXPECT_TRUE(s.contains(3));
}

TEST(SetTest, CopyConstr) {
  s21::Set<int> s1 = {1, 2, 3};
  s21::Set<int> s2(s1);
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(SetTest, MoveConstr) {
  s21::Set<int> s1 = {1, 2, 3};
  s21::Set<int> s2(std::move(s1));
  EXPECT_TRUE(s2.contains(1));
  EXPECT_TRUE(s2.contains(2));
  EXPECT_TRUE(s2.contains(3));
}
TEST(SetTest, BeginEnd) {
  s21::Set<int> s{3, 5, 1, 4, 2};
  auto it = s.begin();
  ASSERT_EQ(it.GetCurrent()->key_, 1);
  it = s.end();
  ASSERT_EQ(it.GetCurrent()->key_, 5);

  s.clear();
  it = s.begin();
  ASSERT_EQ(it, nullptr);
}

TEST(SetTest, SizeMaxSize) {
  s21::Set<int> s{3, 5, 1, 4, 2};
  std::set<int> s1{3, 5, 1, 4, 2};
  ASSERT_GE(s.max_size(), s1.max_size());
}
TEST(SetTest, Erase) {
  s21::Set<int> s{1, 2, 3, 4, 5};
  auto it = s.find(3);
  s.erase(it);
  EXPECT_FALSE(s.contains(3));
}

TEST(SetTest, Swap) {
  s21::Set<int> s1{1, 2, 3};
  s21::Set<int> s2{4, 5, 6};
  s1.swap(s2);
  EXPECT_TRUE(s2.contains(1));
  EXPECT_TRUE(s1.contains(4));
}

TEST(SetTest, Merge) {
  s21::Set<int> s1{1, 2, 3};
  s21::Set<int> s2{3, 4, 5};
  s1.merge(s2);
  EXPECT_TRUE(s1.contains(4));
  EXPECT_FALSE(s2.contains(3));
}

TEST(SetTest, Find) {
  s21::Set<int> s{1, 2, 3};
  auto it1 = s.find(2);
  EXPECT_EQ(it1.GetCurrent()->key_, 2);
}

TEST(SetTest, RotateCheck) {
  s21::Set<int> s1 = {1, 2, 3, 6, 7, 8, 9, 99, -56};
  s1.insert(-1000);
  s1.insert(-10002);
  s1.insert(-100023);
  s1.insert(-100024);
  s1.insert(-100026);
  auto it1 = s1.end();
  auto it2 = s1.begin();
  EXPECT_EQ(it1.GetCurrent()->key_, 99);
  EXPECT_EQ(it2.GetCurrent()->key_, -100026);
}

TEST(SetTest, operatorpris_test1) {
  s21::Set<int> s_1{1, 2, 3};
  s21::Set<int> s_2;
  s_2 = std::move(s_1);
  auto it2 = s_2.begin();
  EXPECT_EQ(s_2.size(), 3);
  EXPECT_EQ(it2.GetCurrent()->key_, 1);
}

TEST(SetTest, insert_many_test1) {
  s21::Set<int> s_1;
  s_1.insert_many(1, 2, 3);
  auto it = s_1.begin();
  EXPECT_EQ(it.GetCurrent()->key_, 1);
  it++;
  EXPECT_EQ(it.GetCurrent()->key_, 2);
  it++;
  EXPECT_EQ(it.GetCurrent()->key_, 3);
}
template <typename KeyValue>
bool IsTypeConst() {
  return std::is_const<KeyValue>::value;
}

TEST(TreeTest, Constr_branch_test_1) {
  s21::Branch<int, char> root(1, 't');
  EXPECT_EQ(root.value_, 't');
  EXPECT_EQ(root.key_, 1);
  EXPECT_EQ(root.left_, nullptr);
  EXPECT_EQ(root.right_, nullptr);
  EXPECT_EQ(root.head_, nullptr);
  EXPECT_EQ(root.height_, 1);
  EXPECT_EQ(root.scale_, 1);
  EXPECT_EQ(root.isSentinel_, false);
}

TEST(TreeTest, Constr_branch_test_2_const) {
  const int a_key = 1;
  const char b_value = 't';
  s21::Branch<int, char> root(a_key, b_value);
  EXPECT_EQ(root.value_, 't');
  EXPECT_EQ(root.key_, 1);
  EXPECT_EQ(root.left_, nullptr);
  EXPECT_EQ(root.right_, nullptr);
  EXPECT_EQ(root.head_, nullptr);
  EXPECT_EQ(root.height_, 1);
  EXPECT_EQ(root.scale_, 1);
  EXPECT_EQ(root.isSentinel_, false);
}

TEST(TreeTest, Constr_Iterator_test_1_normal) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 0);
  test_tree.Insert(6, 0);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, 6);
  EXPECT_EQ(bebra.GetCurrent()->value_, 0);
}

TEST(TreeTest, Constr_Iterator_test_1_const) {
  const int a_key = 10;
  const int b_value = 0;
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(a_key, b_value);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, 10);
  EXPECT_EQ(bebra.GetCurrent()->value_, 0);
}

TEST(TreeTest, Constr_Iterator_copy_test_1) {
  s21::RBTree<int, int> tree;
  tree.Insert(10, 20);
  tree.Insert(5, 10);
  auto original = tree.begin();
  auto copy = original;
  EXPECT_EQ(copy.GetCurrent(), original.GetCurrent());
  ++original;
  EXPECT_NE(copy.GetCurrent(), original.GetCurrent());
}
TEST(TreeTest, Constr_Iterator_copy_pris_test_1) {
  s21::RBTree<int, int> tree;
  s21::RBTree<int, int> tree_1;
  tree.Insert(10, 20);
  tree.Insert(5, 10);
  tree_1.Insert(20, 20);
  tree_1.Insert(15, 10);
  auto original = tree.begin();
  auto copy = tree_1.begin();
  copy = original;
  EXPECT_EQ(copy.GetCurrent(), original.GetCurrent());
  ++original;
  EXPECT_NE(copy.GetCurrent(), original.GetCurrent());
}

TEST(TreeTest, Constr_Iterator_destructor_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 20);
  test_tree.Insert(5, 10);
  test_tree.~RBTree();
  EXPECT_TRUE(test_tree.IsEmpty());
}

TEST(TreeTest, CIterator_move_multi_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 0);
  test_tree.Insert(6, 0);
  test_tree.Insert(15, 0);
  test_tree.Insert(7, 0);
  test_tree.Insert(11, 0);
  test_tree.Insert(20, 0);
  test_tree.Insert(4, 0);
  auto bebra = test_tree.begin();
  bebra = bebra + 2;
  EXPECT_EQ(bebra.GetCurrent()->key_, 7);
}

TEST(TreeTest, Iterator_move_one_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 0);
  test_tree.Insert(6, 0);
  test_tree.Insert(15, 0);
  test_tree.Insert(7, 0);
  auto bebra = test_tree.begin();
  bebra++;
  EXPECT_EQ(bebra.GetCurrent()->key_, 7);
}

TEST(TreeTest, Iterator_move_one_post_fix_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 0);
  test_tree.Insert(6, 0);
  test_tree.Insert(15, 0);
  test_tree.Insert(7, 0);
  auto bebra = test_tree.begin();
  ++bebra;
  EXPECT_EQ(bebra.GetCurrent()->key_, 7);
}
TEST(TreeTest, Iterator_decrement_move_one_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 0);
  test_tree.Insert(6, 0);
  test_tree.Insert(15, 0);
  test_tree.Insert(7, 0);
  auto bebra = test_tree.end();
  EXPECT_EQ(bebra.GetCurrent()->key_, 15);
  bebra--;
  EXPECT_EQ(bebra.GetCurrent()->key_, 10);
  bebra--;
  EXPECT_EQ(bebra.GetCurrent()->key_, 7);
}

TEST(TreeTest, Iterator_decrement_move_one_pre_fix_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 0);
  test_tree.Insert(6, 0);
  test_tree.Insert(15, 0);
  test_tree.Insert(7, 0);
  auto bebra = test_tree.end();
  EXPECT_EQ(bebra.GetCurrent()->key_, 15);
  --bebra;
  EXPECT_EQ(bebra.GetCurrent()->key_, 10);
  --bebra;
  EXPECT_EQ(bebra.GetCurrent()->key_, 7);
}

TEST(TreeTest, Iterator_compare_test_1) {
  s21::RBTree<int, int> test_tree;
  s21::RBTree<int, int> test_tree_1;
  test_tree.Insert(10, 0);
  test_tree.Insert(6, 0);
  test_tree.Insert(15, 0);
  test_tree.Insert(7, 0);
  auto bebra = test_tree.begin();
  auto bebra_1 = test_tree.begin();
  bebra++;
  bebra_1++;
  EXPECT_TRUE(bebra == bebra_1);
}

TEST(TreeTest, Iterator_not_compare_test_1) {
  s21::RBTree<int, int> test_tree;
  s21::RBTree<int, int> test_tree_1;
  test_tree.Insert(10, 0);
  test_tree.Insert(6, 0);
  test_tree.Insert(15, 0);
  test_tree.Insert(7, 0);
  auto bebra = test_tree.begin();
  auto bebra_1 = test_tree.begin();
  bebra++;
  EXPECT_FALSE(bebra == bebra_1);
}

TEST(TreeTest, Iterator_raziemen_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 0);
  auto bebra = test_tree.begin();
  EXPECT_EQ(*bebra, 10);
}

TEST(TreeTest, Iterator_strelochka_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 20);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra->key_, 10);
  EXPECT_EQ(bebra->value_, 20);
}

TEST(TreeTest, Constr_Iterator_strelochka_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 20);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra->key_, 10);
  EXPECT_EQ(bebra->value_, 20);
}

TEST(TreeTest, find_max_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 1);
  test_tree.Insert(15, 2);
  test_tree.Insert(8, 3);
  test_tree.Insert(50, 4);
  test_tree.Insert(1, 5);
  auto bebra = test_tree.begin();
  auto root_test = bebra.GetRootIter();
  auto max_item = bebra.MaximumKey_iter(root_test);
  EXPECT_EQ(max_item->key_, 50);
}

TEST(TreeTest, get_current_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 1);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, 10);
}

TEST(TreeTest, const_iter_test_1) {
  const int a_key = 1;
  const int b_key = 2;
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(a_key, b_key);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, 1);
}

TEST(TreeTest, Constr_tree_test_1) {
  s21::RBTree<int, int> test_tree;
  EXPECT_TRUE(test_tree.IsEmpty());
}

TEST(TreeTest, Copy_tree_test_1) {
  s21::RBTree<int, int> test_tree_1;
  test_tree_1.Insert(10, 100);
  test_tree_1.Insert(20, 200);
  s21::RBTree<int, int> copied_tree = test_tree_1;
  auto iter_copied_tree = copied_tree.begin();
  EXPECT_EQ(iter_copied_tree.GetCurrent()->key_, 10);
  EXPECT_EQ(iter_copied_tree.GetCurrent()->value_, 100);
  iter_copied_tree++;
  EXPECT_EQ(iter_copied_tree.GetCurrent()->key_, 20);
  EXPECT_EQ(iter_copied_tree.GetCurrent()->value_, 200);
}

TEST(TreeTest, Destructor_tree_test_1) {
  s21::RBTree<int, int> test_tree_1;
  test_tree_1.Insert(10, 100);
  test_tree_1.Insert(20, 200);
  test_tree_1.~RBTree();
  EXPECT_TRUE(test_tree_1.IsEmpty());
}

TEST(TreeTest, Copy_oper_tree_test_1) {
  s21::RBTree<int, int> test_tree_1;
  test_tree_1.Insert(10, 100);
  test_tree_1.Insert(20, 200);
  s21::RBTree<int, int> copied_tree;
  copied_tree.Insert(30, 100);
  copied_tree.Insert(40, 200);
  copied_tree = test_tree_1;
  auto iter_copied_tree = copied_tree.begin();
  EXPECT_EQ(iter_copied_tree.GetCurrent()->key_, 10);
  EXPECT_EQ(iter_copied_tree.GetCurrent()->value_, 100);
  iter_copied_tree++;
  EXPECT_EQ((iter_copied_tree).GetCurrent()->key_, 20);
  EXPECT_EQ(iter_copied_tree.GetCurrent()->value_, 200);
}

TEST(TreeTest, CopyMove_tree_test_1) {
  s21::RBTree<int, int> tree1;
  tree1.Insert(1, 100);
  s21::RBTree<int, int> tree2;
  tree2 = std::move(tree1);
  EXPECT_EQ(tree2.GetRoot()->key_, 1);
  EXPECT_EQ(tree2.GetRoot()->value_, 100);
}

TEST(TreeTest, Insert_tree_test_1) {
  s21::RBTree<int, int> test_tree;
  int answer_list[6] = {6, 19, 10, 17, 15, 23};
  int counter = 0;
  test_tree.Insert(10, 17);
  test_tree.Insert(6, 19);
  test_tree.Insert(15, 23);
  auto bebra = test_tree.begin();
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(bebra.GetCurrent()->key_, answer_list[counter]);
    counter++;
    EXPECT_EQ(bebra.GetCurrent()->value_, answer_list[counter]);
    bebra++;
    counter++;
  }
}

TEST(TreeTest, Get_root_tree_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 17);
  EXPECT_EQ(test_tree.GetRoot()->key_, 10);
  EXPECT_EQ(test_tree.GetRoot()->value_, 17);
}

TEST(TreeTest, swap_tree_test_1) {
  s21::RBTree<int, int> tree1;
  tree1.Insert(1, 2);
  tree1.Insert(3, 4);
  s21::RBTree<int, int> tree2;
  tree2.Insert(5, 6);
  tree2.Insert(7, 8);
  tree1.Swap(tree2);
  auto bebra_1 = tree1.begin();
  auto bebra_2 = tree2.begin();
  EXPECT_EQ(bebra_1.GetCurrent()->key_, 5);
  EXPECT_EQ(bebra_1.GetCurrent()->value_, 6);
  EXPECT_EQ(bebra_2.GetCurrent()->key_, 1);
  EXPECT_EQ(bebra_2.GetCurrent()->value_, 2);
  bebra_1++;
  bebra_2++;
  EXPECT_EQ(bebra_1.GetCurrent()->key_, 7);
  EXPECT_EQ(bebra_1.GetCurrent()->value_, 8);
  EXPECT_EQ(bebra_2.GetCurrent()->key_, 3);
  EXPECT_EQ(bebra_2.GetCurrent()->value_, 4);
}

TEST(TreeTest, get_inserted_tree_test_1) {
  s21::RBTree<int, int> tree1;
  EXPECT_FALSE(tree1.GetInserted());
}

TEST(TreeTest, get_max_key_tree_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 17);
  test_tree.Insert(6, 19);
  test_tree.Insert(15, 23);
  EXPECT_EQ(test_tree.MaximumKey(test_tree.GetRoot())->key_, 15);
  EXPECT_EQ(test_tree.MaximumKey(test_tree.GetRoot())->value_, 23);
}

TEST(TreeTest, get_min_key_tree_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 17);
  test_tree.Insert(6, 19);
  test_tree.Insert(15, 23);
  EXPECT_EQ(test_tree.GetMin()->key_, 6);
  EXPECT_EQ(test_tree.GetMin()->value_, 19);
}

TEST(TreeTest, get_max_without_node_key_tree_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 17);
  test_tree.Insert(6, 19);
  test_tree.Insert(15, 23);
  EXPECT_EQ(test_tree.GetMax()->key_, 15);
  EXPECT_EQ(test_tree.GetMax()->value_, 23);
}

TEST(TreeTest, begin_tree_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 17);
  EXPECT_EQ(test_tree.begin().GetCurrent()->key_, 10);
  EXPECT_EQ(test_tree.begin().GetCurrent()->value_, 17);
}

TEST(TreeTest, end_tree_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 17);
  EXPECT_EQ(test_tree.end().GetCurrent()->key_, 10);
  EXPECT_EQ(test_tree.end().GetCurrent()->value_, 17);
}

TEST(TreeTest, Iterator_move_one_dop_test_2) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(11, 0);
  test_tree.Insert(20, 0);
  test_tree.Insert(4, 0);
  test_tree.Insert(10, 0);
  test_tree.Insert(6, 0);
  test_tree.Insert(15, 0);
  test_tree.Insert(7, 0);
  auto bebra = test_tree.begin();
  bebra++;
  EXPECT_EQ(bebra.GetCurrent()->key_, 6);
}

TEST(TreeTest, Iterator_razomin_test_2) {
  s21::RBTree<int, int> test_tree;
  auto bebra = test_tree.begin();
  EXPECT_ANY_THROW(*bebra);
}

TEST(TreeTest, decrement_helper_test_1) {
  s21::RBTree<int, int> test_tree;
  auto bebra = test_tree.begin();
  EXPECT_ANY_THROW(*bebra);
}

TEST(TreeTest, rotate_iter_test_2) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(11, 0);
  test_tree.Insert(20, 0);
  test_tree.Insert(15, 0);
  test_tree.Insert(22, 0);
  test_tree.Insert(18, 0);

  test_tree.Insert(24, 0);
  test_tree.Insert(10, 0);
  test_tree.Insert(6, 0);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, 6);
}

TEST(TreeTest, right_left_test_2) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(5, 0);
  test_tree.Insert(3, 0);
  test_tree.Insert(4, 0);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, 3);
}

TEST(TreeTest, left_right_test_2) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(5, 0);
  test_tree.Insert(8, 0);
  test_tree.Insert(6, 0);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, 5);
}

TEST(TreeTest, decrementdoper_test_2) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(10, 0);
  test_tree.Insert(8, 0);
  test_tree.Insert(9, 0);
  test_tree.Insert(12, 0);
  test_tree.Insert(1, 0);
  auto bebra = test_tree.begin();
  bebra++;
  bebra++;
  bebra++;
  EXPECT_EQ(bebra.GetCurrent()->key_, 10);
}

TEST(TreeTest, remove_test_test_2) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(5, 0);
  test_tree.Insert(8, 0);
  test_tree.Insert(7, 0);
  test_tree.Insert(1, 0);
  test_tree.Insert(6, 0);
  test_tree.Insert(10, 0);
  auto root = test_tree.GetRoot();
  test_tree.Remove_node(root, 5);
  test_tree.Remove_node(root, 10);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, 1);
}

TEST(TreeTest, remove_test_new_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(5, 0);
  test_tree.Insert(10, 0);
  test_tree.Insert(8, 0);
  test_tree.Insert(3, 0);
  test_tree.Insert(6, 0);
  test_tree.Insert(12, 0);
  test_tree.Insert(11, 0);
  test_tree.Insert(9, 0);
  auto new_root = test_tree.GetRoot();
  test_tree.Remove_node(new_root, 11);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, 3);
}

TEST(TreeTest, remove_test_new_new_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(5, 0);
  test_tree.Insert(10, 0);
  test_tree.Insert(8, 0);
  test_tree.Insert(3, 0);
  test_tree.Insert(6, 0);
  test_tree.Insert(12, 0);
  test_tree.Insert(11, 0);
  test_tree.Insert(9, 0);
  test_tree.Insert(-1, 0);
  test_tree.Insert(-30, 0);
  test_tree.Insert(-15, 0);
  test_tree.Insert(245, 0);
  test_tree.Insert(7, 0);
  test_tree.Insert(0, 0);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, -30);
}

TEST(TreeTest, remove_test_new_new_new_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(8, 0);
  test_tree.Insert(5, 0);
  test_tree.Insert(10, 0);
  auto new_root = test_tree.GetRoot();
  test_tree.Remove_node(new_root, 8);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, 5);
}

TEST(TreeTest, remove_test_new_new_2_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(8, 0);
  test_tree.Insert(5, 0);
  test_tree.Insert(10, 0);
  test_tree.Insert(11, 0);
  auto new_root = test_tree.GetRoot();
  test_tree.Remove_node(new_root, 10);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, 5);
}

TEST(TreeTest, remove_test_new_new_3_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(8, 0);
  test_tree.Insert(5, 0);
  test_tree.Insert(10, 0);
  test_tree.Insert(9, 0);
  auto new_root = test_tree.GetRoot();
  test_tree.Remove_node(new_root, 10);
  auto bebra = test_tree.begin();
  EXPECT_EQ(bebra.GetCurrent()->key_, 5);
}

TEST(TreeTest, decrement_test_test_1) {
  s21::RBTree<int, int> test_tree;
  test_tree.Insert(5, 0);
  test_tree.Insert(10, 0);
  test_tree.Insert(8, 0);
  test_tree.Insert(3, 0);
  test_tree.Insert(6, 0);
  test_tree.Insert(12, 0);
  test_tree.Insert(11, 0);
  test_tree.Insert(9, 0);
  test_tree.Insert(-1, 0);
  test_tree.Insert(-30, 0);
  test_tree.Insert(-15, 0);
  test_tree.Insert(245, 0);
  test_tree.Insert(7, 0);
  test_tree.Insert(0, 0);
  auto bebra = test_tree.begin();
  for (; bebra.GetCurrent() != nullptr; bebra++) {
    bebra--;
  }
  EXPECT_EQ(bebra.GetCurrent(), nullptr);
}