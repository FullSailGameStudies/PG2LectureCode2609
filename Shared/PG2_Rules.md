# 🧾 PG2 Rules
<!--TOC-->
  - [⚠️ GitHub Requirements](#-github-requirements)
  - [⚠️ Debugging Expectations](#-debugging-expectations)
  - [❌ Code Restrictions: What is NOT allowed in PG2](#-code-restrictions-what-is-not-allowed-in-pg2)
    - [🚫 lambda statements](#-lambda-statements)
    - [🚫 goto](#-goto)
    - [🚫 techniques not discussed](#-techniques-not-discussed)
  - [🌟 Code Restrictions: What IS allowed in PG2](#-code-restrictions-what-is-allowed-in-pg2)
    - [✅ auto keyword](#-auto-keyword)
    - [✅ const keyword](#-const-keyword)
    - [✅ references](#-references)
    - [✅ member initialization list](#-member-initialization-list)
- [🧪 Campus Lab Rules](#-campus-lab-rules)
  - [🧠 Collaboration & Learning](#-collaboration-learning)
  - [📣 Lab Attendance & Communication](#-lab-attendance-communication)
<!--/TOC-->
## ⚠️ GitHub Requirements

### 📥 Committing your code
You **MUST commit and push your code** to GitHub after completing ***each section for each part of the lab***. For instance, if part A has 3 sections. You must commit and push after completing each section which would mean you end up with 3 separate commits for part A.

#### 🚨 could be deducted up to `15 points`
If you do not commit and push for every section, you ***could be deducted up to 15 points*** for the lab.

#### 📘 GitHub FAQ
Refer to the GitHub FAQ on how to commit + push
[GitHub FAQ](./FAQ_GitHub.md)

---

## ⚠️ Debugging Expectations
We expect students to ***run the code through the debugger*** quite a few times during the development process. 
For example, someone who does really well on the labs actually run the labs `50-100 times`. 

### 🔂 A typical development process
A typical development process is to **code**, **test**, **fix**, **test**, **repeat**. 
Usually, **especially for new students**, you would need to run the lab several times per section. 

#### ⚡Run counts less than 20 
Run counts less than 20 would result in a **point deduction** for the lab. The severity would depend on the number of runs.

### 📥 Submitting the required files
Our projects generate log files that must be committed and pushed with the rest of your code.
Failure to submit these log files will result in ⚠️ automatic deductions of up to 20 points ⚠️.

---

## ❌ Code Restrictions: What is NOT allowed in PG2

### 🚫 lambda statements
C++ lambda expressions (or lambda functions) are a feature introduced in C++11 that allow you to define anonymous functions—functions without a name—directly in your code. They are especially useful for short, throwaway functions that are passed as arguments to algorithms or used in event handling.

#### ⚠️ Why Beginning Students Should Avoid Lambdas (Initially)
While lambdas are powerful, they can be confusing for beginners. Here’s why:

* Complex Syntax: The combination of capture lists, parameter lists, and return types can be overwhelming.
* Hidden Behavior: Capturing variables by value or reference can lead to subtle bugs if not well understood.
* Not Essential Early On: Beginners should focus on mastering functions, loops, conditionals, and classes before diving into more advanced features.
* Harder to Debug: Anonymous functions can make stack traces and debugging more difficult for newcomers.

#### 🚨 some places where lambdas are used that you `should avoid`
 * std::for_each
 * std::sort
 * std::transform
 * std::find_if
 * std::remove_if
 
 ---

### 🚫 goto
The goto statement provides a way to jump to another line in the program marked by a label. It allows unconditional jumps in the control flow.

#### ⚠️ Why to Avoid goto
While goto is legal in C++, it's almost always discouraged in modern programming. Here's why:

1. ***Spaghetti Code***: 
goto can make the control flow hard to follow, especially in large programs.
It leads to tangled logic that’s difficult to debug or maintain.
2. ***Breaks Structured Programming***: 
Modern C++ encourages structured control flow using loops (for, while), conditionals (if, switch), and functions.
goto bypasses these structures, making code less readable.
3. ***Harder to Maintain***: 
If you revisit code months later, goto jumps can be confusing.
Refactoring becomes riskier because it's easy to miss where jumps land or originate.
4. ***Better Alternatives Exist***: 
Use break, continue, return, or exceptions for control flow.
Use loops and functions to encapsulate logic cleanly.

---

### 🚫 techniques not discussed
#### 💫 Best Practice for Students
> “Master the rules before you break them.”

Using techniques not discussed in class—even if they are technically correct—can be problematic in an educational setting for several important reasons:

#### 🎯 1. Misalignment with Learning Objectives
Instructors design assignments to reinforce specific concepts.
Using advanced or unrelated techniques may bypass the intended learning process.
It can signal that the student didn’t understand or follow the assignment’s goals.
#### 🧩 2. Assessment Fairness
Grading rubrics are typically based on the material taught.
If a student uses unfamiliar methods, the instructor may not be able to fairly assess the work.
It can also create unfair advantages over peers who followed the guidelines.
#### 🧠 3. Shallow Understanding
Students might copy or use advanced techniques without fully understanding them.
This leads to surface-level learning and can cause confusion later when foundational knowledge is missing.
#### 🧑‍🏫 4. Breaks Communication with the Instructor
Assignments are a form of dialogue between student and teacher.
Using off-topic methods can make it harder for instructors to track progress and provide meaningful feedback.
#### 🛠️ 5. Debugging and Support Becomes Harder
If a student asks for help with unfamiliar code, the instructor may not be able to assist effectively.
This can lead to frustration and lost learning opportunities.

---

## 🌟 Code Restrictions: What IS allowed in PG2

### ✅ auto keyword
The `auto` keyword tells the compiler to **automatically deduce the type** of a variable from its initializer.

#### 🔸 Example:
```cpp
auto x = 42;        // int
auto y = 3.14;      // double
auto name = "John"; // const char*
```

Instead of explicitly writing the type, you let the compiler figure it out.

#### ❓ Why `auto` is Good to Use

##### 1. **Reduces Typing and Clutter**
Especially useful with long or complex types:
```cpp
std::vector<std::pair<int, std::string>> data;
// Without auto:
std::vector<std::pair<int, std::string>>::iterator it = data.begin();
// With auto:
auto it = data.begin();
```

##### 2. **Improves Readability**
- Keeps code **cleaner and more focused** on logic rather than types.
- Especially helpful in **generic programming** and **template-heavy code**.

##### 3. **Avoids Type Mismatches**
- Ensures the variable has **exactly the type** of the initializer.
- Reduces bugs from incorrect or unintended type declarations.


#### 💫 Best Practice:
> Use `auto` when the type is **obvious** or **unwieldy**, but avoid it when the type is **critical to understanding** the code.

---

### ✅ const keyword
The const keyword in C++ is used to declare something as constant, meaning its value cannot be changed after it's initialized. It’s a powerful tool for writing safer, more predictable code.

❓ Why Use const?
 * Protects data from accidental modification.
 * Improves code clarity—you know what won’t change.
 * Enables compiler optimizations.
 * Allows usage with const objects (e.g., passing objects to functions without copying).

 We'll cover the proper way to use const during lecture 02.
 Students **will be expected to use const** in the proper ways. This starts with part B of lab 1 and applies to all parts of labs 2,3, and 4.
We'll cover const on day 2 of the month.

#### ✨Refer to the `Lecture 02 in week 1` as a guide for how and when to use const.

#### ⚡Points will be deducted if not used appropriately.
---

### ✅ references
#### ❓ Why Use References?
* To avoid copying large objects.
* To modify arguments passed to functions.
* To return multiple values from functions.

In C++, the ampersand symbol (&) has two primary meanings, depending on the context.
#### 🔹 1. Reference Operator (when used in declarations)
Students **will be expected to use &** in the proper ways. This starts with part B of lab 1 and applies to all parts of labs 2,3, and 4.
We'll cover references on day 2 of the month.
##### ✨Refer to the `Lecture 02 in week 1` as a guide for how and when to use pass by reference.


#### 🔹 2. Address-of Operator (when used in expressions)
We'll start discussing pointers in `week 3` at which point you'll need to use the address-of operator.

#### ⚡Points will be deducted if not used appropriately.

---

### ✅ member initialization list
In C++, member initialization lists are a way to initialize class member variables before the constructor body runs. They are especially important for initializing const members, reference members, and base classes.

#### Week 3
We'll cover member initialization lists in `week 3`.

---

# 🧪 Campus Lab Rules

To ensure a productive and respectful environment for everyone, please follow these guidelines during lab:

## 🧠 Collaboration & Learning
- **Use the whiteboards** for:
  - Debugging
  - Visualizing concepts
  - Peer programming and brainstorming

- **Support your peers**, but:
  - **Do not write code for another student**
  - Focus on guiding, not doing

## 📣 Lab Attendance & Communication
- **Always inform a lab instructor** before leaving the lab, even briefly.
- **If you arrive late**, notify a lab instructor as soon as you enter.

---
