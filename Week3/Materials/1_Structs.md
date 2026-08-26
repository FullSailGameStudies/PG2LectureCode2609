# 📘 C++ `struct` vs `class` 
<!--TOC-->
  - [What is a `struct`?](#-what-is-a-struct)
    - [✅ Characteristics of `struct`:](#-characteristics-of-struct)
  - [What is a `class`?](#-what-is-a-class)
    - [✅ Characteristics of `class`:](#-characteristics-of-class)
  - [⚖️ Key Differences](#%EF%B8%8F-key-differences)
  - [🧠 When to Use What?](#-when-to-use-what)
  - [🧪 Fun Fact](#-fun-fact)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->
In C++, both `struct` and `class` are used to define **user-defined types** that can hold **data** and **functions**. While they are **very similar**, there are a few key differences that are important to understand.

---

## 🔹 What is a `struct`?

A `struct` (short for **structure**) is a way to group related variables (and optionally functions) under one name.

```cpp
struct Point {
    double x;
    double y;

    void print() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};
```

### ✅ Characteristics of `struct`:
- **Default access modifier**: `public` 🔓
- Typically used for **plain-old-data (POD)** types.
- Supports **member functions**, **constructors**, **destructors**, **inheritance**, and **polymorphism** (just like classes).
- Often used in **C-style programming** or for **simple data containers**.

---

## 🔸 What is a `class`?

A `class` is a more formal and flexible way to define objects in C++. It encapsulates **data** and **behavior** and is the foundation of **object-oriented programming (OOP)** in C++.

```cpp
class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const {
        return 3.14159 * radius * radius;
    }
};
```

### ✅ Characteristics of `class`:
- **Default access modifier**: `private` 🔒
- Designed for **encapsulation**, **abstraction**, **inheritance**, and **polymorphism**.
- Encourages **data hiding** and **modular design**.
- Ideal for **complex systems** and **OOP design patterns**.

---

## ⚖️ Key Differences

| Feature                  | `struct` 🧱                | `class` 🏛️                |
|--------------------------|----------------------------|----------------------------|
| Default access modifier  | `public` 🔓                | `private` 🔒               |
| Inheritance default      | `public`                  | `private`                 |
| Use case                 | Simple data containers     | Full OOP design            |
| Syntax                   | `struct Name { ... };`     | `class Name { ... };`      |
| Functionality            | Same as class              | Same as struct             |

---

## 🧠 When to Use What?

- Use **`struct`** when:
  - You need a **simple data structure**.
  - You want **public access** by default.
  - You're working with **interfacing C code**.

- Use **`class`** when:
  - You need **encapsulation** and **data hiding**.
  - You're building **complex systems**.
  - You want to leverage **OOP principles**.

---

## 🧪 Fun Fact

In C++, the only **technical difference** between `struct` and `class` is the **default access level**. Everything else—constructors, destructors, inheritance, etc.—works the same!


---

## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./1_Structs_quiz.html)

![Footer Separator](../../Shared/Images/separator01.png)

## 🔭 Markdown Viewer

How to view the markdown files in a browser...
- [Markdown Viewer](../../Shared/0_Setup.md)

---

## 🧠 Lecture Practices

Here are the lecture Practices...
- [Day 7](./Day07.md)
- [Day 8](./Day08.md)
- [Day 9](./Day09.md)

---

## 🔍 Lecture Quizzes

Here are the lecture quizzes...
- [Day 7](https://forms.office.com/r/s02tg66qFm)
- [Day 8](https://forms.office.com/r/0bGwGBWENi)
- [Day 9](https://forms.office.com/r/Yc5p0bEgB8)

---

## Weekly Topics
Here are the topics for the week...
- [Classes](./1_Classes.md)
- [Structs](./1_Structs.md)
- [Fields](./2_Fields.md)
- [Getters and Setters](./2_GettersSetters.md)
- [Constructors](./3_Constructors.md)
- [Instances](./4_Instances.md)
- [Inheritance](./5_Inheritance.md)
- [Polymorphism](./6_Polymorphism.md)
- [Pointers](./7_Pointers.md)
- [Destructors](./9_Destructors.md)
- [Upcasting](./7_Upcasting.md)
- [Misc. Concepts](./8_Misc.md)
- [4 Pillars of OOP](./1_FourPillars.md)


[return to PG2 Topics](../../PG2_Topics.md)