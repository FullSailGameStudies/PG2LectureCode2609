# 📘 Default Parameters in C++  
<!--TOC-->
  - [Syntax of Default Parameters](#-syntax-of-default-parameters)
  - [Default Parameters in Member Functions](#-default-parameters-in-member-functions)
    - [✅ Correct Usage](#-correct-usage)
    - [❌ Incorrect Usage](#-incorrect-usage)
  - [🧠 Key Rules and Best Practices](#-key-rules-and-best-practices)
  - [🧪 Example: Class with Default Parameters](#-example-class-with-default-parameters)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->

In C++, **default parameters** allow you to specify **default values** for function arguments. This enables functions to be called with **fewer arguments** than they are defined to accept, improving flexibility and readability.

---

## 🔹 Syntax of Default Parameters

A default parameter is specified by assigning a value in the **function declaration**:

```cpp
void greet(std::string name = "Guest");
```

This allows the function to be called with or without an argument:

```cpp
greet();           // Uses default: "Guest"
greet("Alice");    // Uses provided argument
```

---

## 🔸 Default Parameters in Member Functions

When using default parameters in **class member functions**, the default values should be specified ***only in the declaration***, not in the definition.

### ✅ Correct Usage

```cpp
// Header file or class definition
class Greeter {
public:
    void greet(std::string name = "Guest");  // Default specified here
};

// Source file
void Greeter::greet(std::string name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}
```

### ❌ Incorrect Usage

```cpp
// Header file
class Greeter {
public:
    void greet(std::string name);  // No default here
};

// Source file
void Greeter::greet(std::string name = "Guest") {  // ❌ Error!
    std::cout << "Hello, " << name << "!" << std::endl;
}
```

**Why is this incorrect?**  
C++ allows default arguments to be specified **only once**—typically in the declaration. Specifying them again in the definition leads to a **compiler error** or **ambiguity**.

---

## 🧠 Key Rules and Best Practices

- ✅ **Specify default arguments in the function declaration**, especially in header files.
- ❌ **Do not repeat default arguments in the function definition**.
- ❌ Default arguments must appear **at the end** of the parameter list. If there are any required parameters, they must appear before the default parameters in the parameter list.
- Use default parameters to simplify overloaded functions when the behavior is similar.
- Avoid using default parameters in virtual functions if polymorphism is involved, as default arguments are **statically bound**.

---

## 🧪 Example: Class with Default Parameters

```cpp
#include <iostream>
#include <string>

class Logger {
public:
    void log(std::string message, std::string level = "INFO");
};

void Logger::log(std::string message, std::string level) {
    std::cout << "[" << level << "] " << message << std::endl;
}

int main() {
    Logger logger;
    logger.log("System started");               // Uses default level "INFO"
    logger.log("Disk full", "WARNING");         // Uses provided level
    return 0;
}
```

## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./9_DefaultParameters_quiz.html)

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