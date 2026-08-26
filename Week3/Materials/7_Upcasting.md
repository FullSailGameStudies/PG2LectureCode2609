# 📘 Upcasting in C++
<!--TOC-->
  - [🧠 What is Upcasting?](#-what-is-upcasting)
  - [✅ Key Characteristics](#-key-characteristics)
  - [🧪 Why Use Upcasting?](#-why-use-upcasting)
  - [⚠️ Limitations](#%EF%B8%8F-limitations)
  - [🧭 Summary](#-summary)
<!--/TOC-->
## 🧠 What is Upcasting?

**Upcasting** is the process of converting a pointer or reference of a **derived class** to a **base class** type. It is called "upcasting" because in a class hierarchy, the base class is conceptually higher than the derived class.

```cpp
class Animal {
public:
    virtual void speak() {
        std::cout << "Animal speaks\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Dog barks\n";
    }
};

Animal myPet = Dog();  // only copies the Animal parts of Dog to the myPet variable
Animal* aPtr = new Dog(); // 🔼 Upcasting. points aPtr to the Dog object
aPtr->speak(); // Output: Dog barks (due to polymorphism)
delete aPtr; // deallocate the Dog object
```

---

## ✅ Key Characteristics

- **Safe and implicit**: No cast operator is needed.
- **Supports polymorphism**: If the base class has virtual functions, the derived class's overridden methods will be called.
- **Loses access to derived-specific members**: Only base class members are accessible through the base class pointer/reference.

---

## 🧪 Why Use Upcasting?

### 🔄 Polymorphism
Allows writing flexible and reusable code that works with base class types but behaves according to the derived class implementation.

```cpp
void makeItSpeak(Animal* a) {
    a->speak(); // Calls the appropriate speak() method
}
```

### 🧰 Code Reusability
You can store different derived objects in a single container of base class pointers:

```cpp
std::vector<Animal*> zoo;
zoo.push_back(new Dog());
zoo.push_back(new Cat());
```

---

## ⚠️ Limitations

- You **cannot access** members that are only in the derived class.
- If you need to access derived-specific functionality, you must **downcast** (with care).

---

## 🧭 Summary

| Feature              | Upcasting |
|----------------------|-----------|
| Direction            | Derived → Base |
| Safe?                | ✅ Yes |
| Implicit?            | ✅ Yes |
| Polymorphic behavior | ✅ Yes (if virtual functions are used) |
| Access to derived members | ❌ No |


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