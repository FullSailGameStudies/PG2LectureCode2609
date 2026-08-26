# 📘 C++ Iterators and `std::vector`
<!--TOC-->
  - [🔹 What is an Iterator?](#-what-is-an-iterator)
  - [🔹 Iterators and `std::vector`](#-iterators-and-stdvector)
    - [Basic Syntax:](#basic-syntax)
  - [🔹 Common Iterator Operations](#-common-iterator-operations)
  - [🔹 Example: Iterating Over a Vector](#-example-iterating-over-a-vector)
  - [🔹 Const Iterators](#-const-iterators)
  - [🔹 Reverse Iterators](#-reverse-iterators)
  - [🔹 Why Use Iterators?](#-why-use-iterators)
  - [✅ Summary](#-summary)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->

## 🔹 What is an Iterator?

An **iterator** in C++ is an object that acts like a pointer and allows you to **traverse** (i.e. move through) containers (like `std::vector`, `std::map`, etc.). Think of it as a **generalized pointer** that provides access to elements in a container without exposing the underlying structure.

---

## 🔹 Iterators and `std::vector`

`std::vector` is a **sequence container** that stores elements in a **contiguous memory block**. It supports **random access iterators**, which means you can move forward, backward, and jump to any position in constant time.

### Basic Syntax:
```cpp
std::vector<int>::iterator it;
```

---

## 🔹 Common Iterator Operations

| Operation         | Description                                   |
|-------------------|-----------------------------------------------|
| `begin()`         | Returns iterator to the first element         |
| `end()`           | Returns iterator to one past the last element |
| `*it`             | Dereferences iterator to access value         |
| `it++` / `++it`   | Moves to the next element                     |
| `it--` / `--it`   | Moves to the previous element                 |
| `it + n`          | Moves forward by `n` positions                |
| `it - n`          | Moves backward by `n` positions               |

---

## 🔹 Example: Iterating Over a Vector

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {10, 20, 30, 40, 50};

    // Using iterator
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        std::cout << *it << " ";
    }
    // Output: 10 20 30 40 50
}
```

---

## 🔹 Const Iterators

Use `const_iterator` when you want to **read** but not **modify** the elements.

```cpp
std::vector<int>::const_iterator it;
```

---

## 🔹 Reverse Iterators

```cpp
for (std::vector<int>::reverse_iterator rit = nums.rbegin(); rit != nums.rend(); ++rit) {
    std::cout << *rit << " ";
}
// Output: 50 40 30 20 10
```

---

## 🔹 Why Use Iterators?

- **Abstraction**: You don’t need to know how the container is implemented.
- **Generic Programming**: Algorithms like `std::sort`, `std::find`, etc., work with iterators.
- **Safety**: Iterators provide bounds-checked access when used with STL algorithms.

---

## ✅ Summary

- Iterators are like smart pointers for containers.
- `std::vector` supports **random access iterators**.
- Use `begin()` and `end()` to traverse a vector.
- Prefer `const_iterator` for read-only access.
- STL algorithms rely heavily on iterators.



## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./4_Iterators_quiz.html)

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