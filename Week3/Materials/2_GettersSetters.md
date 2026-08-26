# 📘 Getters and Setters in C++
<!--TOC-->
  - [🧠 What Are They?](#-what-are-they)
  - [🔒 Why Use Them?](#-why-use-them)
  - [🧱 Syntax and Example](#-syntax-and-example)
    - [Example Class: `Student`](#example-class-student)
  - [🧪 Usage](#-usage)
  - [🧩 Notes](#-notes)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->

## 🧠 What Are They?

In C++, **getters** and **setters** are special member functions used to **access** and **modify** private data members of a class. They are part of the **encapsulation** principle in object-oriented programming, which promotes **data hiding** and **controlled access** to class members.

---

## 🔒 Why Use Them?

1. **Encapsulation**: Keeps internal data safe from unintended interference.
2. **Validation**: Setters can include logic to validate data before modifying a member.
3. **Read-only or Write-only Access**: You can expose only a getter or a setter.
4. **Abstraction**: Hides implementation details from the user.

---

## 🧱 Syntax and Example

### Example Class: `Student`

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // Constructor
    Student(string n, int a) {
        name = n;
        setAge(a); // Use setter to apply validation
    }

    // Getter for name
    string getName() const {
        return name;
    }

    // Setter for name
    void setName(const string& n) {
        name = n;
    }

    //
    //ALTERNATIVE naming: do NOT use the 'get' or 'set' prefix
    //
    // Getter for age
    int Age() const {
        return age;
    }

    // Setter for age with validation
    void Age(int a) {
        if (a > 0 && a < 150) {
            age = a;
        } else {
            cout << "Invalid age. Setting to default (18)." << endl;
            age = 18;
        }
    }
};
```

---

## 🧪 Usage

```cpp
int main() {
    Student s("Alice", 20);

    // Accessing data using getters
    cout << "Name: " << s.getName() << endl;
    cout << "Age: " << s.Age() << endl;

    // Modifying data using setters
    s.setName("Bob");
    s.Age(200); // Invalid, triggers validation

    cout << "Updated Name: " << s.getName() << endl;
    cout << "Updated Age: " << s.Age() << endl;

    return 0;
}
```

---

## 🧩 Notes

- **Const correctness**: Getters are often marked `const` because they don’t modify the object.
- **Inline functions**: Getters and setters can be defined inline for simplicity.
- **Performance**: Modern compilers optimize simple getters/setters well, so there's usually no performance penalty.

---

## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./2_Fields_quiz.html)

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