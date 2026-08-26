# 📘 Understanding C++ Classes
<!--TOC-->
  - [🧠 What is a Class?](#-what-is-a-class)
  - [🧱 Syntax of a Class](#-syntax-of-a-class)
  - [🔐 Access Modifiers in C++](#-access-modifiers-in-c)
    - [1. `private`](#1-private)
    - [2. `public`](#2-public)
    - [3. `protected`](#3-protected)
  - [🧪 Example: A Simple `Car` Class](#-example-a-simple-car-class)
  - [✅ Summary Table](#-summary-table)
<!--/TOC-->

## 🧠 What is a Class?

A **class** in C++ is a **user-defined** data type that serves as a blueprint for creating **objects**. It encapsulates **member variables** (fields) and **member functions** (methods) that operate on the data, following the principles of **Object-Oriented Programming (OOP)**.

---

## 🧱 Syntax of a Class

> NOTE: classes are usually declared in header files.

```cpp
class ClassName {
  private:
    // Private data members

  protected:
    // Protected members

  public:
    // Public methods and constructors
};
```

---

## 🔐 Access Modifiers in C++

Access modifiers control the **visibility** and **accessibility** of class members (variables and functions). C++ provides three main access specifiers:

### 1. `private`
- **Default** access level for class members.
- Members are **only accessible** within the class itself.
- Used to **encapsulate** and protect internal data.

```cpp
class Example {
  private:
    int secret;

  public:
    void setSecret(int s) { secret = s; }
    int getSecret() { return secret; }
};
```

### 2. `public`
- Members are **accessible from outside** the class.
- Used to define the **interface** of the class.

```cpp
class Example {
  public:
    int id;
    void showID() { cout << "ID: " << id << endl; }
};
```

### 3. `protected`
- Members are **not accessible** from outside the class.
- But they are accessible in **derived (child) classes**.
- Useful in **inheritance** scenarios.

```cpp
class Base {
  protected:
    int value;
};

class Derived : public Base {
  public:
    void setValue(int v) { value = v; }
    int getValue() { return value; }
};
```

---


## 🧪 Example: A Simple `Car` Class

```cpp
#include <iostream>
using namespace std;

class Car {
  private:
    string brand;
    int year;

  public:
    Car(string b, int y) {
        brand = b;
        year = y;
    }

    void displayInfo() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1("Toyota", 2020);
    car1.displayInfo();

    return 0;
}
```

---

## ✅ Summary Table

| Access Modifier | Accessible Within Class | Accessible Outside Class | Accessible in Derived Class |
|------------------|--------------------------|----------------------------|------------------------------|
| `private`        | ✅ Yes                   | ❌ No                     | ❌ No                         |
| `protected`      | ✅ Yes                   | ❌ No                     | ✅ Yes                        |
| `public`         | ✅ Yes                   | ✅ Yes                    | ✅ Yes                        |

---

## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./1_Classes_quiz.html)

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