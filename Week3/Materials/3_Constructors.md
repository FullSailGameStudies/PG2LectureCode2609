# 📘 Understanding Constructors in C++
<!--TOC-->
  - [🧠 What is a Constructor?](#-what-is-a-constructor)
    - [🔑 Key Characteristics:](#-key-characteristics)
  - [🔄 Types of Constructors](#-types-of-constructors)
  - [🧱 Constructor Syntax](#-constructor-syntax)
  - [🧪 Example: Default and Parameterized Constructors](#-example-default-and-parameterized-constructors)
  - [🧬 Member Initialization Lists](#-member-initialization-lists)
    - [🔍 What is a Member Initialization List?](#-what-is-a-member-initialization-list)
    - [✅ Syntax](#-syntax)
    - [🧪 Example with Initialization List](#-example-with-initialization-list)
    - [⚙️ Why Use Initialization Lists?](#%EF%B8%8F-why-use-initialization-lists)
    - [🧪 Example with `const` and `reference`](#-example-with-const-and-reference)
  - [✅ Summary](#-summary)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->

## 🧠 What is a Constructor?

A **constructor** is a special member function of a class in C++ that is **automatically called** when an object of the class is created. Its primary purpose is to **initialize the fields** (data members) of the object.

### 🔑 Key Characteristics:
- Has the **same name** as the class.
- **No return type**, not even `void`.
- Can be **overloaded** (multiple constructors with different parameters).
- Can be **default**, **parameterized**, or **copy constructors**.

---

## 🔄 Types of Constructors

| Type                 | Description |
|----------------------|-------------|
| **Default**          | No parameters; initializes with default values. |
| **Parameterized**    | Takes arguments to initialize fields. |
| **Copy Constructor** | Initializes a new object as a copy of an existing one. |
| **Delegating**       | One constructor calls another constructor in the same class. |
| **Explicit**         | Prevents implicit conversions for single-argument constructors. |

---

## 🧱 Constructor Syntax

```cpp
class ClassName {
  public:
    ClassName();               // Default constructor
    ClassName(int x);          // Parameterized constructor
    ClassName(const ClassName&); // Copy constructor
};
```

---

## 🧪 Example: Default and Parameterized Constructors

```cpp
class Student {
  private:
    string name;
    int age;

  public:
    Student() {
        name = "Unknown";
        age = 0;
    }

    Student(string n, int a) {
        name = n;
        age = a;
    }
};
```

---

## 🧬 Member Initialization Lists

### 🔍 What is a Member Initialization List?

A **member initialization list** is a more efficient and idiomatic way to initialize class fields, especially for:

- **Const** members
- **Reference** members
- **Base class constructors**
- **Fields with non-trivial constructors**

### ✅ Syntax

```cpp
ClassName(type1 arg1, type2 arg2) : field1(arg1), field2(arg2) {
    // constructor body (optional)
}
```

### 🧪 Example with Initialization List

```cpp
class Student {
  private:
    string name;
    int age;

  public:
    Student(string n, int a) : name(n), age(a) {
        // Initialization done before body executes
    }
};
```

### ⚙️ Why Use Initialization Lists?

| Benefit | Explanation |
|--------|-------------|
| **Performance** | Avoids default construction followed by assignment. |
| **Required for const/reference** | These must be initialized at declaration. |
| **Clarity** | Makes initialization intent explicit. |

### 🧪 Example with `const` and `reference`

```cpp
class Book {
  private:
    const int id;
    string& title;

  public:
    Book(int i, string& t) : id(i), title(t) {}
};
```

---

## ✅ Summary

| Concept | Description |
|--------|-------------|
| Constructor | Initializes object fields |
| No return type | Constructors do not return values |
| Overloading    | Multiple constructors with different parameters |
| Copy constructor | Creates a new object as a copy of another |
| Initialization List | Preferred way to initialize fields |
|  | Avoids unnecessary default construction |
|  | Required for `const`, references, and base classes |

---

## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./3_Constructors_quiz.html)

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