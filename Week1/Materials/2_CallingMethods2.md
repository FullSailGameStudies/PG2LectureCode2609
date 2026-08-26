# 📘 Return Types, Arguments, and Capturing Returned Data in C++
<!--TOC-->
  - [🔹 Function Signature](#-function-signature)
  - [🔹 Function Body](#-function-body)
  - [🔁 Return Types](#-return-types)
    - [**Definition:**](#definition)
    - [**Common Return Types:**](#common-return-types)
    - [**Example:**](#example)
  - [🧩 Function Arguments (Parameters)](#-function-arguments-parameters)
    - [**Definition:**](#definition)
    - [**Types of Parameter Passing:**](#types-of-parameter-passing)
  - [📥 Capturing Returned Data](#-capturing-returned-data)
    - [**Definition:**](#definition)
    - [**Syntax:**](#syntax)
    - [**Example:**](#example)
    - [**Why Capture Return Values?**](#why-capture-return-values)
  - [🧠 Best Practices](#-best-practices)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->

In C++, functions are fundamental building blocks that allow you to encapsulate logic and reuse code. Understanding how to define return types, pass arguments, and capture returned values is essential for writing modular and reusable code.

---

## 🔹 Function Signature

A function in C++ is defined by its **signature**, which includes:
- The **return type**
- The **function name**
- The **parameter list**

```cpp
ReturnType FunctionName(ParameterType1 param1, ParameterType2 param2, ...);
```
```cpp
int add(int a, int b) //this is the signature of the function
{  
    return a + b;
}
```

---

## 🔹 Function Body

The code for a function is in the **function body**. The body consists of the
{ } and the statements inside the curly braces.

```cpp
int add(int a, int b) 
//function body starts here
{  
    return a + b;
}
//function body ends here
```

---

## 🔁 Return Types

### **Definition:**
The **return type** specifies the type of value a function sends back to the caller.

### **Common Return Types:**
- **Primitive types**: `int`, `double`, `char`, `bool`
- **Standard library types**: `std::string`, `std::vector`, etc.
- **User-defined types**: classes or structs
- **`void`**: indicates no value is returned

### **Example:**
```cpp
int add(int a, int b) {
    return a + b;
}
```

---

## 🧩 Function Arguments (Parameters)

### **Definition:**
- **Arguments** are values passed to a function when it is called. 
- **Parameters** are the variables that receive those values.

```cpp
// Parameters: a and b
int add(int a, int b) {
    return a + b;
}

//constant arguments (5 and 2) passed to add
int sum = add(5, 2);

//variables passed as arguments
int num1 = 5, num2 = 2;
int result = add(num1, num2);
```

### **Types of Parameter Passing:**

| Method            | Syntax Example              | Behavior |
|-------------------|-----------------------------|----------|
| Pass by Value     | `void f(int x)`             | Copies the value |
| Pass by Reference | `void f(int& x)`            | Modifies the original |
| Pass by Pointer   | `void f(int* x)`            | Modifies via address |
| Const Reference   | `void f(const std::string&)`| Read-only access without copying |

---

## 📥 Capturing Returned Data

### **Definition:**
When a function returns a value, you can **capture** it by assigning the result to a variable.

### **Syntax:**
```cpp
ReturnType result = FunctionName(arguments);
```

### **Example:**
```cpp
double calculateArea(double width, double height) {
    return width * height;
}

int main() {
    double w = 5.0, h = 3.0;
    double area = calculateArea(w, h);  // Capturing the return value
    std::cout << "Area: " << area << std::endl;
    return 0;
}
```

### **Why Capture Return Values?**
- To store results for later use
- To pass results into other functions
- To make decisions based on returned data

---

## 🧠 Best Practices

- Always **match the return type** of the function with the type of the variable capturing the result.
- Use `auto` for type inference when the return type is complex:
  ```cpp
  auto result = someFunction();
  ```
- Avoid ignoring return values unless the function is `void` or the result is truly unnecessary.



## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./2_CallingMethods2_quiz.html)

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