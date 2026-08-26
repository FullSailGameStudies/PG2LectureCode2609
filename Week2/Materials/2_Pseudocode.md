# 📘 Understanding Pseudocode and Translating It to C++
<!--TOC-->
  - [🧠 What is Pseudocode?](#-what-is-pseudocode)
    - [🔍 Key Characteristics:](#-key-characteristics)
  - [🧱 Structure of Pseudocode](#-structure-of-pseudocode)
    - [Example:](#example)
  - [🔁 Translating Pseudocode to C++](#-translating-pseudocode-to-c)
    - [1. **Identify the structure**](#1-identify-the-structure)
    - [2. **Add C++ syntax**](#2-add-c-syntax)
  - [🧮 Example: Translating Factorial](#-example-translating-factorial)
    - [🔤 Pseudocode:](#-pseudocode)
    - [💻 C++ Code:](#-c-code)
  - [🧪 Practice Example](#-practice-example)
    - [🔤 Pseudocode:](#-pseudocode)
    - [💻 C++ Code:](#-c-code)
  - [🧠 Translating Tips](#-translating-tips)
  - [✅ Summary](#-summary)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->

## 🧠 What is Pseudocode?

**Pseudocode** is a high-level, informal way of describing an algorithm using plain language and programming-like structure. It is not bound by the syntax rules of any specific programming language, making it ideal for planning and communicating logic before implementation.

### 🔍 Key Characteristics:
- Language-agnostic
- Focuses on logic, not syntax
- Easy to read and write
- Often used in algorithm design and documentation

---

## 🧱 Structure of Pseudocode

Pseudocode typically includes:
- **Control structures**: `IF`, `ELSE`, `WHILE`, `FOR`
- **Function definitions**: `PROCEDURE`, `FUNCTION`
- **Input/Output**: `READ`, `PRINT`
- **Comments**: Often written with `//` or `#`

### Example:
```plaintext
FUNCTION Factorial(n)
    IF n == 0 THEN
        RETURN 1
    ELSE
        RETURN n * Factorial(n - 1)
    ENDIF
END FUNCTION
```

---

## 🔁 Translating Pseudocode to C++

To convert pseudocode into C++, follow these steps:

### 1. **Identify the structure**
   - Functions → `returnType functionName(parameters)`
   - Conditionals → `if`, `else`
   - Loops → `for`, `while`
   - I/O → `cin`, `cout`

### 2. **Add C++ syntax**
   - Use semicolons, braces `{}`, and proper types (`int`, `double`, etc.)
   - Include headers like `#include <iostream>`

---

## 🧮 Example: Translating Factorial

### 🔤 Pseudocode:
```plaintext
FUNCTION Factorial(n)
    IF n == 0 THEN
        RETURN 1
    ELSE
        RETURN n * Factorial(n - 1)
    ENDIF
END FUNCTION
```

### 💻 C++ Code:
```cpp
#include <iostream>
using namespace std;

int Factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * Factorial(n - 1);
}

int main() {
    int num = 5;
    cout << "Factorial of " << num << " is " << Factorial(num) << endl;
    return 0;
}
```

---

## 🧪 Practice Example

### 🔤 Pseudocode:
```plaintext
READ n
sum ← 0
FOR i ← 1 TO n DO
    sum ← sum + i
ENDFOR
PRINT sum
```

### 💻 C++ Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << "Sum is " << sum << endl;
    return 0;
}
```

---

## 🧠 Translating Tips

- go line-by-line. Don't get overwhelmed by the whole method.
- Don't change variable names until you have a working version.
- Often times, you'll have to add to it to make it fit in your application.
- := means assignment. 
- Don't change the logic of the pseudocode.
- Indention means blocks and indicates what block the code belongs to.
- It's ok to skip something and come back to it later.
- end if, end for, end procedure means `}` in C++
- If it doesn't work after translating, go back and compare your code line-by-line (sometimes character by character) with the pseudocode. Sometimes the problem is
simple translation mistake.

---

## ✅ Summary

| Pseudocode Element | C++ Equivalent |
|--------------------|----------------|
| `READ x`           | `cin >> x;`    |
| `PRINT x`          | `cout << x;`   |
| `IF`, `ELSE`       | `if`, `else`   |
| `FOR`, `WHILE`     | `for`, `while` |
| `EndIF`, `EndFor`  | `}`            |
| `EndWhile`         | `}`            |
| `EndProcedure`     | `}`            |
| `FUNCTION`         | `returnType functionName()` |

---

## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./2_Pseudocode_quiz.html)

![Footer Separator](../../Shared/Images/separator01.png)

## 🔭 Markdown Viewer

How to view the markdown files in a browser...
- [Markdown Viewer](../../Shared/0_Setup.md)

---

## 🧠 Lecture Practices

Here are the lecture Practices...
- [Day 4](./Day04.md)
- [Day 5](./Day05.md)
- [Day 6](./Day06.md)

---

## 🔍 Lecture Quizzes

Here are the lecture quizzes...
- [Day 4](https://forms.office.com/r/XUQYr2qrf4)
- [Day 5](https://forms.office.com/r/QRNDCnA8Fw)
- [Day 6](https://forms.office.com/r/pi9bMm1SfR)

---

## Weekly Topics
Here are the topics for the week...
- [Recursion](./1_Recursion.md)
- [Pseudocode](./2_Pseudocode.md)
- [Sorting](./3_Sorting.md)
- [Searching](./4_Searching.md)
- [Maps](./5_Maps.md)
- [Time Complexity](./6_TimeComplexity.md)


[return to PG2 Topics](../../PG2_Topics.md)