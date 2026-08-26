# 📘 Understanding Class Instances in C++
<!--TOC-->
  - [🧠 What is a Class Instance?](#-what-is-a-class-instance)
    - [🔑 Key Concepts:](#-key-concepts)
  - [🧱 Declaring and Creating Instances](#-declaring-and-creating-instances)
    - [🔹 Syntax](#-syntax)
    - [🧪 Example](#-example)
  - [🧬 Instances with Constructors](#-instances-with-constructors)
  - [✅ Summary](#-summary)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->

## 🧠 What is a Class Instance?

A **class instance** (also called an **object**) is a concrete realization of a class. While a class defines the **structure** and **behavior** (via fields and methods), an instance represents a **specific entity** with its own **state**.

### 🔑 Key Concepts:
- A class is like a **blueprint**.
- An instance is like a **house built from that blueprint**.
- Each instance has its own **copy of the class's fields**.

---

## 🧱 Declaring and Creating Instances

### 🔹 Syntax

```cpp
ClassName objectName;               // Default constructor
ClassName objectName(args);        // Parameterized constructor
```

### 🧪 Example

```cpp
class Car {
  public:
    string brand;
    int year;

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1;               // Instance of Car
    car1.brand = "Toyota";
    car1.year = 2020;

    car1.display();         // Output: Brand: Toyota, Year: 2020

    return 0;
}
```

---

## 🧬 Instances with Constructors

```cpp
class Student {
  private:
    string name;
    int age;

  public:
    Student(string n, int a) : name(n), age(a) {}

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s1("Alice", 20);   // Instance with parameterized constructor
    Student s2("Bob", 22);

    s1.display();              // Output: Name: Alice, Age: 20
    s2.display();              // Output: Name: Bob, Age: 22

    return 0;
}
```

---

## ✅ Summary

| Term         | Description |
|--------------|-------------|
| Class        | Blueprint for objects |
| Instance     | A specific object created from a class |
| Constructor  | Initializes an instance |

---

## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./4_Instances_quiz.html)

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