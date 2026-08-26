# 📘 What Is Time Complexity?
<!--TOC-->
  - [📦 Why Does It Matter?](#-why-does-it-matter)
  - [⏱️ Big-O Notation](#EF%B8%8F-big-o-notation)
  - [🧪 Example: Linear vs. Quadratic](#-example-linear-vs-quadratic)
  - [🧭 Key Takeaways](#-key-takeaways)
<!--/TOC-->

**Time complexity** is a way to describe **how the running time of an algorithm increases** as the size of the input grows.

Think of it as a **mathematical estimate** of how much time your code will take to run, especially when dealing with **large amounts of data**.

---

## 📦 Why Does It Matter?

Imagine sorting a list of 10 names vs. 10 million names. You want to know:
- Will your algorithm still be fast?
- Will it slow down a little or a lot?

Time complexity helps you **predict performance** without actually running the program.

---

## ⏱️ Big-O Notation

We use **Big-O notation** to express time complexity. It describes the **upper bound** of an algorithm’s running time.

Here are some common time complexities:

| Big-O Notation | Name              | Example Scenario                     |
|----------------|-------------------|--------------------------------------|
| O(1)      | Constant time     | Accessing an array element           |
| O(log n) | Logarithmic time  | Binary search                        |
| O(n)      | Linear time       | Looping through an array             |
| O(n log n) | Log-linear time | Merge sort, Quick sort (average)     |
| O(n^2)    | Quadratic time    | Nested loops (e.g., bubble sort)     |
| O(2^n)    | Exponential time  | Recursive algorithms (e.g., brute force) |


![Order-of Chart](BigO.png)

---

## 🧪 Example: Linear vs. Quadratic

Let’s say you have a list of `n` numbers:

- A **linear algorithm** (like finding the max) checks each number once → \( O(n) \)
- A **quadratic algorithm** (like comparing every pair) does \( n \times n \) comparisons → \( O(n^2) \)

So if `n = 1,000`:
- Linear: ~1,000 steps
- Quadratic: ~1,000,000 steps 😬

---

## 🧭 Key Takeaways

- Time complexity helps you **compare algorithms**.
- It focuses on **growth rate**, not exact time.
- **Lower time complexity = better scalability**.

![Footer Separator](../../Shared/Images/separator01.png)

## 🔭 Markdown Viewer

How to view the markdown files in a browser...
- [Markdown Viewer](../../Shared/0_Setup.md)

---

## 🧠 Lecture Practices

Here are the lecture Practices...
- [Day 4](./Day04.md)
- [Day 5](./Day05.md)
- [Day 6](./Day06.md)

---

## 🔍 Lecture Quizzes

Here are the lecture quizzes...
- [Day 4](https://forms.office.com/r/XUQYr2qrf4)
- [Day 5](https://forms.office.com/r/QRNDCnA8Fw)
- [Day 6](https://forms.office.com/r/pi9bMm1SfR)

---

## Weekly Topics
Here are the topics for the week...
- [Recursion](./1_Recursion.md)
- [Pseudocode](./2_Pseudocode.md)
- [Sorting](./3_Sorting.md)
- [Searching](./4_Searching.md)
- [Maps](./5_Maps.md)
- [Time Complexity](./6_TimeComplexity.md)


[return to PG2 Topics](../../PG2_Topics.md)