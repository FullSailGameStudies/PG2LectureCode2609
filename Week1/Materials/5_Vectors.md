# 📘 Understanding `std::vector` in C++
<!--TOC-->
  - [1. Indexing](#-1-indexing)
  - [2. Adding Items](#-2-adding-items)
    - [`push_back()`](#push_back)
    - [`insert()`](#insert)
  - [3. Erasing Items](#-3-erasing-items)
    - [`pop_back()`](#pop_back)
    - [`erase()`](#erase)
  - [4. Iterating Over a Vector](#-4-iterating-over-a-vector)
    - [Using Iterators](#using-iterators)
    - [Range-Based For Loop](#range-based-for-loop)
    - [Using `auto`](#auto)
  - [5. Size](#-5-size)
    - [`size()`](#size)
  - [6. Capacity](#-6-capacity)
    - [`capacity()`](#capacity)
    - [`reserve(n)`](#reserven)
    - [`shrink_to_fit()`](#shrink_to_fit)
  - [7. Copying](#-7-copying)
    - [Copy each element manually](#copy-each-element-manually)
    - [use the assignment `=` operator](#use-the-assignment--operator)
    - [passing a vector to the constructor of the new vector](#passing-a-vector-to-the-constructor-of-the-new-vector)
  - [✅ Summary](#-summary)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->
`std::vector` is a **sequence container** in the C++ Standard Template Library (STL) that provides **dynamic array** functionality. It manages memory automatically and allows random access to elements. 
> The elements in the vector are stored **contiguously**, meaning that the elements are ordered in memory right next to each other.

---

## 🔹 1. Indexing

Vectors support **random access** via the subscript operator `[]` and the `.at()` method.

```cpp
std::vector<int> v = {10, 20, 30};
int x = v[1];       // x = 20
int y = v.at(2);    // y = 30
```

- `v[i]` is fast but **not bounds-checked**.
- `v.at(i)` is **bounds-checked** and throws `std::out_of_range` if `i` is invalid.

---

## 🔹 2. Adding Items

### `push_back()`
Adds an element to the **end** of the vector.

```cpp
v.push_back(40);  // v = {10, 20, 30, 40}
```

### `insert()`
Inserts an element at a **specific position**.

```cpp
v.insert(v.begin() + 1, 15);  // v = {10, 15, 20, 30, 40}
```

---

## 🔹 3. Erasing Items

### `clear()`
Removes all of the items in a vector.

```cpp
v.clear();
```

### `pop_back()`
Removes the **last** element.

```cpp
v.pop_back();  // v = {10, 15, 20, 30}
```

### `erase()`
Removes an element or a range.

```cpp
v.erase(v.begin() + 1);  // removes 15 → v = {10, 20, 30}
v.erase(v.begin(), v.begin() + 2);  // removes 10 and 20 → v = {30}
```

---

## 🔹 4. Iterating Over a Vector

### for loops
```cpp
for(int i=0;i<vec.size();i++)
{
   std::cout << vec[i] << "\n"; //or use vec.at(i)
}
```

### Using Iterators
```cpp
for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
```

### Range-Based For Loop
```cpp
for (int val : v) {
    std::cout << val << " ";
}
```

### `auto`
```cpp
for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
```

---

## 🔹 5. Size

### `size()`
Returns the **number of elements** in the vector.

```cpp
std::cout << v.size();  // e.g., 3
```

---

## 🔹 6. Capacity

### `capacity()`
Returns the **allocated storage** length (how big the internal array is).
size() is ALWAYS <= capacity().

Think of it like the fuel tank in your car. capacity() is how big the fuel tank is. size() is how much gas is in the fuel tank.

```cpp
std::cout << v.capacity();
```

### `reserve(n)`
Pre-allocates memory for at least `n` elements to avoid frequent reallocations.

```cpp
v.reserve(100);  // improves performance if you know the size in advance
```

### `shrink_to_fit()`
Requests the container to reduce capacity to fit its size.


## 🔹 7. Copying
There are three ways to copy one vector to another.

### Copy each element manually
```cpp
std::vector<int> scores = { 1,2,3,4,5 };
std::vector<int> scores2;
scores2.reserve(scores.size()); // reserve the space needed
for (size_t i = 0; i < scores.size(); i++)
	scores2.push_back(scores[i]);
```

### use the assignment `=` operator
```cpp
std::vector<int> scores = { 1,2,3,4,5 };
std::vector<int> scores3 = scores;
```

### passing a vector to the constructor of the new vector
```cpp
std::vector<int> scores = { 1,2,3,4,5 };
std::vector<int> scores4(scores);
```

---

## ✅ Summary

| Operation       | Method             | Notes                                 |
|----------------|--------------------|---------------------------------------|
| Indexing       | `[]`, `.at()`      | `.at()` is bounds-checked             |
| Add            | `push_back()`, `insert()` | Adds at end or specific position |
| Remove         | `pop_back()`, `erase()`  | Removes last or specific elements     |
| Iterate        | `iterator`, `range-for` | Multiple styles supported         |
| Size           | `size()`           | Number of elements                    |
| Capacity       | `capacity()`, `reserve()` | Memory management tools         |



## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./5_Vectors_quiz.html)

![Footer Separator](../../Shared/Images/separator01.png)

## 🔭 Markdown Viewer

How to view the markdown files in a browser...
- [Markdown Viewer](../../Shared/0_Setup.md)

---

## 🧠 Lecture Practices

Here are the lecture Practices...
- [Day 1](./Day01.md)
- [Day 2](./Day02.md)
- [Day 3](./Day03.md)

---

## 🔍 Lecture Quizzes

Here are the lecture quizzes...
- [Day 1](https://forms.office.com/r/CSJQvCM0fD)
- [Day 2](https://forms.office.com/r/SmyXe3ufa3)
- [Day 3](https://forms.office.com/r/fcPX1HHfRD)

---

## ⚙️ Weekly Topics

Here are the topics for the week...
- [Calling Methods](./1_CallingMethods.md)
- [Calling Methods 2](./2_CallingMethods2.md)
- [Creating Methods](./3_CreatingMethods.md)
- [Iterators](./4_Iterators.md)
- [Vectors](./5_Vectors.md)
- [References](./6_References.md)
- [Const](./7_Const.md)
- [Erasing in a Loop](./8_ErasingInALoop.md)
- [Default Parameters](./9_DefaultParameters.md)


[return to PG2 Topics](../../PG2_Topics.md)