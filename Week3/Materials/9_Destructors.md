# 📘 Understanding Destructors in C++
<!--TOC-->
  - [🧠 What is a Destructor?](#-what-is-a-destructor)
  - [Syntax and Basics](#syntax-and-basics)
  - [RAII and Why Destructors Matter](#raii-and-why-destructors-matter)
  - [Virtual vs. Non‑Virtual Destructors](#virtual-vs-nonvirtual-destructors)
  - [Implicitly‑Declared, Defaulted, and Deleted Destructors](#implicitlydeclared-defaulted-and-deleted-destructors)
  - [Destruction Order and Lifetime Nuances](#destruction-order-and-lifetime-nuances)
  - [Exceptions and noexcept in Destructors](#exceptions-and-noexcept-in-destructors)
  - [Pure Virtual Destructors with a Definition](#pure-virtual-destructors-with-a-definition)
  - [Common Pitfalls](#common-pitfalls)
  - [Examples](#examples)
  - [Best Practices Summary](#best-practices-summary)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->


## 🧠 What is a Destructor?

A **destructor** is a special member function that runs automatically when an object's lifetime ends. Its job is to release resources (memory, file handles, sockets, mutexes, etc.) and restore invariants. 

***

## Syntax and Basics

*   Name: `~ClassName()`
*   Parameters: **none** (cannot be overloaded or templated in parameter list)
*   Qualifiers: can be `virtual`, `override` (for virtual), `= default`, `= delete`, and specified `noexcept` (implicitly `noexcept(true)` unless you declare otherwise)
*   Returns: nothing

```cpp
struct File {
    File(const char* path);
    ~File();              // destructor
    // ...
};
```

**When it runs:**

*   For **automatic** (stack) objects: when the object goes out of scope (including by exception unwinding).
*   For **members**: after the containing object's destructor body finishes, members are destroyed in **reverse** order of declaration.
*   For **bases**: base class subobjects are destroyed **after** the most‑derived's destructor body, again in reverse inheritance order.
*   For **dynamic** objects (`new`): when you call `delete` (or `delete[]` for arrays).
*   For **static storage duration** (e.g., global objects): after `main()` finishes, in reverse order of construction.
*   For **temporary** objects: at the end of the full-expression that created them (unless lifetime is extended by binding to a `const&`).

***

## RAII and Why Destructors Matter

With RAII (Resource Acquisition Is Initialization), you **acquire** resources in constructors and **always** release them in destructors. This guarantees cleanup even if exceptions are thrown.

```cpp
class ScopedHandle {
public:
    ScopedHandle(int fd) : fd_(fd) {}
    ~ScopedHandle() { if (fd_ >= 0) ::close(fd_); } // always runs

private:
    int fd_{-1};
};
```

Prefer **smart pointers** (`std::unique_ptr`, `std::shared_ptr`) over manual `new/delete`. They encode ownership and make correct destruction far easier.

***

## Virtual vs Non‑Virtual Destructors

*   Use a **virtual destructor** when a class is intended to be used **polymorphically** (i.e., deleted through a base pointer/reference).

```cpp
struct Base {
    virtual ~Base() = default;  // virtual because we expect polymorphic use
};

struct Derived : Base {
    ~Derived() override { /* free Derived-specific resources */ }
};

Base* p = new Derived{};
delete p;  // Calls Derived::~Derived() then Base::~Base() — correct due to virtual dtor
```

*   If you delete a `Derived` object through a non-virtual `Base*` and `Base`'s destructor isn't virtual, behavior is **undefined** (typically only the base subobject is destroyed).

*   If a class is **not** meant for polymorphism, a non-virtual destructor is fine (and slightly smaller/faster).

***

## Implicitly‑Declared, Defaulted, and Deleted Destructors

*   If you don't declare a destructor, the compiler generates one. It:
    *   Destroys bases and members (recursively).
    *   Is `noexcept(true)` by default.
    *   Is **trivial** if all bases/members have trivial destructors and certain conditions hold.

*   You can explicitly ask for the synthesized behavior:
    ```cpp
    ~X() = default;      // request compiler-generated destructor
    ```

*   You may **delete** a destructor to forbid destruction (rare; mostly for special framework patterns):
    ```cpp
    ~X() = delete;       // object cannot be destroyed (almost never what you want)
    ```

***


## Destruction Order and Lifetime Nuances

*   **Members** are destroyed in the **reverse order** of declaration in the class.
*   **Base classes** are destroyed **after** the most-derived destructor body, also in reverse base order.
*   **Arrays**: `delete[]` must be used for memory allocated with `new[]`, otherwise undefined behavior and likely leaks or partial destruction.
    ```cpp
    Widget* a = new Widget[10];
    delete[] a; // calls ~Widget() 10 times
    ```
*   **Static objects**: Destruction order across translation units is unspecified; avoid cross‑TU dependencies at destruction time (or use the “construct on first use” idiom with function‑local statics).

***

## Exceptions and noexcept in Destructors

*   A destructor is implicitly `noexcept(true)` unless you declare otherwise.
*   **Never let exceptions escape a destructor** called during stack unwinding from another exception—this calls `std::terminate()`.

```cpp
struct Logger {
    ~Logger() noexcept {
        try {
            // operations that might throw
        } catch (...) {
            // swallow/log; do not rethrow
        }
    }
};
```

If a destructor genuinely may need to report failure, provide an explicit `close()`/`commit()` member that can throw/return a status, and keep the destructor non-throwing.

***

## Pure Virtual Destructors with a Definition

You can make a class abstract by declaring a **pure virtual destructor**, but you **must still provide a definition** because base subobjects must be destructible.

```cpp
struct Interface {
    virtual ~Interface() = 0; // pure, makes class abstract
};

Interface::~Interface() = default; // required definition
```

***

## Common Pitfalls

1.  **Forgetting `virtual`** on base classes used polymorphically.
2.  **Throwing from destructors**, especially during stack unwinding.
3.  **Mismatched `new`/`delete`** vs. `new[]`/`delete[]`.
4.  **Manual memory management**: double-delete, leaks, or missing copy/move logic. Prefer `std::unique_ptr` / `std::shared_ptr` / containers.
5.  **Use‑after‑free** bugs if pointers/references outlive the object.
6.  **Static deinit order** across translation units (avoid cross‑unit dependencies during teardown).

***

## Examples

**Polymorphic cleanup with virtual destructor**

```cpp
#include <memory>
#include <iostream>

struct Shape {
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

struct Circle : Shape {
    Circle(double r) : r(r) {}
    ~Circle() override { std::cout << "~Circle\n"; }
    double area() const override { return 3.14159 * r * r; }
    double r;
};

int main() {
    std::unique_ptr<Shape> s = std::make_unique<Circle>(2.0);
    std::cout << s->area() << "\n";
} // ~Circle runs automatically, then ~Shape
```


***

## Best Practices Summary

*   Tie ownership to objects (RAII). Prefer **smart pointers** and standard containers.
*   Mark destructors **virtual** on polymorphic bases.
*   Keep destructors **`noexcept`**; never let them throw.
*   Ensure **delete symmetry** (`new`↔`delete`, `new[]`↔`delete[]`).
*   Be mindful of **destruction order** (members reverse declaration; bases after derived body).

***


---

## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./9_Destructors_quiz.html)

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
- [Day 9](https://forms.office.com/r/BQFdNAsBB0)

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