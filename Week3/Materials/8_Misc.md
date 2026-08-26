# 📘 Misc. OOP Concepts in C++
<!--TOC-->
  - [🧩 Nested Classes](#-nested-classes)
  - [🧱 Abstract Base Class](#-abstract-base-class)
  - [📌 Static](#-static)
  - [🛑 Final](#-final)
  - [🤝 Friends](#-friends)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->
## 🧩 Nested Classes

A **nested class** is a class defined within another class. It helps encapsulate helper classes that are only relevant to the outer class.

```cpp
class Outer {
private:
    int number;
public:
    class Inner {
    public:
        void display(const Outer& outer) {
            std::cout << "Inside Inner class\n" << outer.number;
        }
    };
};

```

### ✅ Use Cases:
- Logical grouping of classes
- Encapsulation of helper functionality

### 🔒 Access:
- The nested class has access to the outer class's members!

---

## 🧱 Abstract Base Class

An **abstract base class** is a class that contains at least one **pure virtual function**. It cannot be instantiated and is used to define an interface.

```cpp
class Animal {
public:
    virtual void speak() = 0; // Pure virtual function
};
```

### 🧠 Purpose:
- Enforce a contract for derived classes
- Enable **polymorphism**

### 🧰 Example:
```cpp
class Dog : public Animal {
public:
    //derived classes must override the pure virtual function
    //if they do not, the derived class will become abstract too
    void speak() override {
        std::cout << "bark bark\n";
    }
};
```

---

## 📌 Static

The `static` keyword has different meanings depending on context:

### 🧮 Static Variable (Inside Function)
- Retains its value between function calls

```cpp
void counter() {
    static int count = 0;
    count++;
    std::cout << count << "\n";
}
```

### 🏛️ Static Member (Inside Class)
- Shared across all instances of the class

```cpp
class MyClass {
public:
    static int count;
};
int MyClass::count = 0;
```

---

## 🛑 Final

The `final` specifier prevents further overriding or inheritance.

### 🚫 Prevent Overriding:
```cpp
class Base {
public:
    virtual void show() final {
        std::cout << "Base show\n";
    }
};
```

### 🚫 Prevent Inheritance:
```cpp
class FinalClass final {
    // Cannot be inherited
};
```

---

## 🤝 Friends

A `friend` function or class can access the **private** and **protected** members of another class.

### 👥 Friend Function:
```cpp
class MyClass {
private:
    int secret = 42;
    friend void reveal(MyClass);
};

void reveal(MyClass obj) {
    std::cout << obj.secret << "\n";
}
```

### 🧑‍🤝‍🧑 Friend Class:
```cpp
class A {
    friend class B;
private:
    int data = 100;
};

class B {
public:
    void show(A a) {
        std::cout << a.data << "\n";
    }
};
```

---

## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./8_Misc_quiz.html)

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