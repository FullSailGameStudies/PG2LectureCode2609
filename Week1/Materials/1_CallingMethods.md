# 📘 Static vs. Non-Static Member Functions in C++
<!--TOC-->
  - [🔹 Non-Static Member Functions](#-non-static-member-functions)
    - [Definition:](#definition)
    - [Characteristics:](#characteristics)
    - [Example:](#example)
  - [🔹 Static Member Functions](#-static-member-functions)
    - [Definition:](#definition)
    - [Characteristics:](#characteristics)
    - [Example:](#example)
  - [🔸 Key Differences](#-key-differences)
  - [✅ When to Use What?](#-when-to-use-what)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->

In C++, member functions of a class can be either **static** or **non-static**. Understanding the difference between them is crucial for designing efficient and logical object-oriented programs.

---

## 🔹 Non-Static Member Functions

### Definition:
Non-static member functions are associated with an **instance** of a class. They can access both **instance variables** and **static variables** of the class.

### Characteristics:
- ❗Require an object to be called. ❗
- Have access to the `this` pointer (i.e., the current object).
- Can access and modify instance (non-static) data members.

### Example:

```cpp
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    void setDetails(string n, int a) {
        name = n; //non-static methods can access and modify the data members of the class
        age = a;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    //
    // Step 1. Create an object of the Student class
    Student s1;  

    //
    // Step 2. Use the Student variable to call the non-static methods
    s1.setDetails("Alice", 20); 
    s1.display();  // Output: Name: Alice, Age: 20


    return 0;
}
```

---

## 🔹 Static Member Functions

### Definition:
Static member functions are associated with the **class itself**, not with any particular object. They can only access **static data members** or other **static member functions**.

### Characteristics:
- Can be called using the class name (no object needed).
- Do **not** have access to the `this` pointer.
- Cannot access non-static members directly.

### Example:

```cpp
#include <iostream>
using namespace std;

class Counter {
private:
    static int count;

public:
    static void increment() {
        count++;
    }

    static void showCount() {
        cout << "Count: " << count << endl;
    }
};

// Definition of static member
int Counter::count = 0;

int main() {
    //
    // Use ClassName:: to call static methods
    Counter::increment();  
    Counter::increment();  
    Counter::showCount();  

    return 0;
}
```

---

## 🔸 Key Differences

| Feature                  | Non-Static Function         | Static Function               |
|--------------------------|-----------------------------|-------------------------------|
| Called using             | Object                      | Class name or object          |
| Access to `this` pointer | Yes                         | No                            |
| Access to instance data  | Yes                         | No                            |
| Access to static data    | Yes                         | Yes                           |
| Memory allocation        | Per object                  | Shared across all instances   |

---

## ✅ When to Use What?

- Use **non-static** functions when behavior depends on object-specific data.
- Use **static** functions for utility operations or when behavior is independent of object state.


## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./1_CallingMethods_quiz.html)

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