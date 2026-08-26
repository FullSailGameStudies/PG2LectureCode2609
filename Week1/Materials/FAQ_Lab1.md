# ❓ Lab 1: Frequently Asked Questions
<!--TOC-->
  - [❓ Q: Do you have any tips for lab 1?](#-q-do-you-have-any-tips-for-lab-1)
  - [❓ Q: My method is undefined even though it is in the `.cpp` file. Why?!](#-q-my-method-is-undefined-even-though-it-is-in-the-.cpp-file.-why)
  - [❓ Q: How do I compare strings using _stricmp?](#-q-how-do-i-compare-strings-using-_stricmp)
  - [❓ Q: I'm getting a build error that says `'binary <<': no operator found...`. What is causing this?](#-q-im-getting-a-build-error-that-says-binary-no-operator-found....-what-is-causing-this)
  - [❓ Q: How do I properly use `const`?](#-q-how-do-i-properly-use-const)
<!--/TOC-->
## ❓ Q: Do you have any tips for lab 1?

### 💡 A: Of course! here they are...

#### 🧠 **Start by Reading the Code You're Given**
* **Check out** header files before you start coding.
* These files often include helpful methods and examples that will save you time and confusion.

#### 📁 **Understand File Structure (.h vs .cpp)**
* `.h` files (headers): for **declarations** — fields, constructors, method names, etc.
* `.cpp` files: for **definitions** — the actual code that runs.
  🔁 Keeping these organized makes debugging *way* easier later on.

#### 🧪 **Use the examples as a Guide**
* Garrett included examples of how to do some tasks — use them!
* Don’t try to “guess” how to start — build from working examples.

#### ⏰ **Plan Ahead & Give Yourself Time**
* Labs can take **12–24 hours** for new programmers.
* Watching lectures, Googling, and debugging can easily add **another 12–20 hours**.
  * 💬 **Start early**, and don’t wait until the last minute.

#### 📖 **Read the Instructions Carefully**
* A single missed detail can make your code fail.
* If something’s unclear — **ask a question!** That's why we're here.

#### 🛠️ **Debugging Is Part of Programming**
* Expect to run into errors.
* Read error messages, comment out sections, and test things in small pieces.
  💡 If your code is breaking, don’t panic — break it down and isolate the issue.

#### 💬 **Use Print Statements to Understand What’s Happening**
* Adding `std::cout` statements inside your methods helps you see if they’re being called or what values you’re working with.

#### 🧘 **Take Breaks! Seriously.**
* Every **45–60 mins**, take a **5–15 min break** away from the screen.
* Your brain will process things better when you come back.

#### 🔁 **Test As You Go**
* Don’t write 500 lines and then test — write a little, then make sure it works.
* Build and test incrementally to avoid giant messes.
---

## ❓ Q: My method is undefined even though it is in the `.cpp` file. Why?!

### 💡 A: Maybe a typo or you're missing a scope resolution

If you've declared the method in the header file and defined it in the `.cpp` file, but you're still getting a build error saying the method is undefined, there are a couple of common reasons this might happen:


### ✅ **1. Check for Typos**

C++ is **case-sensitive**, so make sure the method name is spelled **exactly** the same in both the header and the `.cpp` file. A small typo can cause the compiler to think the method doesn't exist.

> 💡 **Tip:** Copy and paste the method name from the header file to avoid mistakes.


### ✅ **2. Missing Class Scope in Definition**

Even if the method is declared in the header, the definition in the `.cpp` file must include the **class name** to indicate which class the method belongs to.

#### Example:

**In the header file (`MyClass.h`):**
```cpp
class MyClass {
public:
    void doSomething();
};
```

**In the source file (`MyClass.cpp`):**
```cpp
#include "MyClass.h"

void MyClass::doSomething() {
    // method implementation
}
```

> ❗ Without the `MyClass::` prefix, the compiler doesn't know which class the method belongs to, and it will throw an "undefined" error.

---

## ❓ Q: How do I compare strings using _stricmp?

### 💡 A: Use the in returned from _stricmp

#### What is `_stricmp`?

`_stricmp` is a **case-insensitive** string comparison function provided by the C runtime library in C++. It compares two C-style strings (`char*`) and ignores the case of the characters.

#### 📌 Syntax

```cpp
int _stricmp(const char *string1, const char *string2);
```

- **Returns 0** if the strings are equal (ignoring case).
- **Returns < 0** if `string1` is less than `string2`.
- **Returns > 0** if `string1` is greater than `string2`.

#### ✅ Example

```cpp
#include <iostream>
#include <cstring> // for _stricmp

int main() {
    std::string str1 = "Hello";
    std::string str2 = "hello";

    if (_stricmp(str1.c_str(), str2.c_str()) == 0) {
        std::cout << "The strings are equal (case-insensitive)." << std::endl;
    } else {
        std::cout << "The strings are different." << std::endl;
    }

    return 0;
}
```

---

## ❓ Q: I'm getting a build error that says `'binary <<': no operator found...`. What is causing this?

### 💡 A: This error usually means you're trying to use the `<<` operator (commonly used with `std::cout`) on a type that doesn't support it.

#### 🔍 Common Scenario

You're trying to print a custom object using `std::cout` like this:

```cpp
MyClass obj;
std::cout << obj; // ❌ Error: no operator<< found
```

### 🧠 Why This Happens

C++ doesn't automatically know how to output user-defined types. You must explicitly tell it how to format your object for output streams like `std::cout`.


#### ✅ Solution 1: use the getters to access the values that can be printed

Use the getters on the object to access the data members to print them.

#### Example:

```cpp
#include <iostream>

class MyClass {
    int value;

public:

    MyClass(int v) : value(v) {}

    int GetValue() const {return value;}
};


int main() {
    MyClass obj(42);
    std::cout << obj.GetValue() << std::endl; // ✅ Now works!
    return 0;
}
```

#### ✅ Solution 2: access the values in the vector to print them

Use an index to get to the items in the vector so that you can print them.

```cpp

std::vector<int> scores = { 1200, 540, 23 };

for(int i=0;i < scores.size(); i++) {
   std::cout << scores[i] << std::endl; // ✅ Works fine
}

```
## ❓ Q: How do I properly use `const`?

### 💡 A: here are some general guidelines for using `const`
Below is a GERNERALIZED list of rules when it comest to `const` from this point on in your labs you should be thinking about what needs to be const and why and this rule set is here to help. For the most part in the first 2 weeks you will be adding `const` where needed in the parameters of your methods as a hint.

#### 1. **Constant Variables**
A `const` variable is a variable that cannot be modified. Its value cannot change, and it is what we call in programming **immutable**. If you see the word immutable, we are usually referring to something being protected from change using the `const` keyword.

Example:
```c++
const int x = 5;
```
In this example, `x` cannot be modified after it is initialized. `x` must be initialized at the time of declaration due to it being `const`.

#### 2. **Function Parameters (Const References)**
A `const &` (const reference) parameter means that the function receives a reference to the original data without copying it, and promises not to modify it. This technique reduces memory usage and improves performance while also ensuring data safety.

Example:
```cpp
void print(const std::string& s);
```
In this example, we have a function declaration named `print` that takes in a `const &` of a `std::string`. This `string` is passed by reference (so it avoids copying), and marked as `const` because the function doesn’t need to change it.

#### 3. **Const Member Functions**
A `const` member function is a function that does not modify the internal state of the object. It is indicated by placing the `const` keyword after the function signature. Only `const` member functions can be called on `const` objects.

Example:
```cpp
class MyClass {
public:
    int getValue() const;
};
```
In this example, `getValue` is a const member function, which means it cannot modify any member variables of the object (unless they are marked `mutable`).

#### 4. **Const Objects**
A `const` object is one declared with the `const` keyword, meaning it cannot be modified after creation. Only `const` member functions can be called on such objects.

Example:
```cpp
const MyClass obj;
```
In this example, we have declared a `const` object of type `MyClass`. This means that `obj` cannot be modified, and only member functions marked as `const` can be called on it (like `getValue()` in the previous example).

#### 5. **Const in Function Return Types**

Returning `const` by **value** is rarely useful and often avoided, because the returned copy is still modifiable by the caller.

Example:
```cpp
const int getVal();  // Usually discouraged
```
Returning `const` by **reference** is more useful. It avoids copying large objects and ensures the returned reference cannot be used to modify the original data.

Example:
```cpp
const std::string& getName() const;
```
In this example, the function returns a `const` reference to a string, meaning the caller can access the string but not change it.