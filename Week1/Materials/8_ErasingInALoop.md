# 📘 Erasing Multiple Items from a `std::vector` in a Loop
<!--TOC-->
  - [The Problem: Iterator Invalidation](#-the-problem-iterator-invalidation)
  - [Safe Pattern for Erasing in a Loop](#-safe-pattern-for-erasing-in-a-loop)
    - [✅ Example: Remove All Even Numbers](#-example-remove-all-even-numbers)
    - [🧠 Key Insight:](#-key-insight)
  - [Alternative: Reverse Iteration](#-alternative-reverse-iteration)
    - [✅ Why This Works:](#-why-this-works)
  - [🧠 Best Practices](#-best-practices)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->

In C++, `std::vector` provides the `erase()` method to remove elements. However, **erasing multiple elements in a loop** requires careful handling to avoid **iterator invalidation** and **skipped elements**.

---

## 🔹 The Problem: Iterator Invalidation

When you erase an element from a vector using `erase()`, all iterators **after the erased element** become invalid. If you're iterating through the vector and erasing elements, this can lead to:

- **Accessing invalid memory**
- **Skipping elements unintentionally**
- **Undefined behavior**

---

## 🔸 Safe Pattern for Erasing in a Loop

To safely erase multiple elements, use a **`for` loop with an iterator**, ***only increment the iterator if no erasure occurs***.

### ✅ Example: Remove All Even Numbers

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};

    for (auto it = nums.begin(); it != nums.end(); ) {
        if (*it % 2 == 0) {
            it = nums.erase(it);  // erase returns the next valid iterator
        } else {
            ++it;  // only increment if no erase
        }
    }

    // Output the result
    for (int n : nums) {
        std::cout << n << " ";
    }
    return 0;
}
```

### 🧠 Key Insight:
- `erase(it)` removes the element and returns a **valid iterator** pointing to the next element.
- If you increment the iterator after `erase()`, you skip the next element.

---

## 🔹 Alternative: Reverse Iteration

If you're removing elements based on **index** or **position**, iterating **backward** can be safer:

```cpp
for (int i = nums.size() - 1; i >= 0; --i) {
    if (nums[i] % 2 == 0) {
        nums.erase(nums.begin() + i);
    }
}
```

## 🔹 Alternative: for loop Iteration

If you're removing elements based on **index**, make sure to only increment the for loop variable when NOT erasing.

```cpp
for (int i = 0;i < nums.size(); ) //NOTE: no i++ here
{
    if (nums[i] % 2 == 0) {
        nums.erase(nums.begin() + i);
    }
    else {
        i++; //only increment i when NOT erasing
    }
}
```

---

### ✅ Why This Works:
- Erasing from the end avoids invalidating earlier indices.
- No iterator invalidation occurs for elements before the erased one.

---

## 🧠 Best Practices

- Prefer **iterator-based loops** when working with `erase()`.
- Avoid `range-based for` loops when modifying the container.


## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./8_ErasingInALoop_quiz.html)

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