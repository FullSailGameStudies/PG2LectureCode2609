# 📘 Day 01 Lecture Practices

## 💻 Calling Static Methods Coding Practice

### 🧩 part A-1.0: calling methods on the Console class to print messages.
1. Open `Lectures.cpp`.
2. Add code in case 1 of the switch to call Console::Write and Console::WriteLine.
3. Print several lines. Experiment with changing the colors.

---

## 💻 Calling Non-Static Methods Coding Practice

1. 🧩 part A-1.1: move player right to spot.
    - open `Day1.cpp`
    - find the comment `Part A-1.1` in method PartA_1_1()
    - follow the instructions to complete the task
2. 🧩 part A-1.2: move player down to spot.
    - open `Day1.cpp`
    - find the comment `Part A-1.2` in method PartA_1_2()
    - follow the instructions to complete the task
3. 🧩 part A-1.3: move player to a predefined Target spot
    - open `Day1.cpp`
    - find the comment `Part A-1.3` in method PartA_1_3()
    - follow the instructions to complete the task


---

## 💻 Handling Return Values Coding Practice

### 🧩 part A-1.4: Getting return values
Ask the user to enter their name. Print the name.

1. Open `Lectures.cpp` and find the comment `part A-1.4`
2. Add code in the case to call Input::GetString.
3. Store the result in a string variable.
4. Print the name that the user enters.

> Open the Input.h file (look in Misc/Input in Solution Explorer) to see how the GetString is declared.


---

## 💻 Arguments Coding Practice

### 🧩 part A-1.5: passing arguments
Ask the user for their age. A minimum age would be 0 and a maximum age would be 120.

1. Open `Lectures.cpp` and find the comment `part A-1.5`
2. Add code in the case to call Input::GetInteger.
3. Store the result in an int variable.
4. Print the age that the user enters.

> Open the Input.h file (look in Misc/Input in Solution Explorer) to see how the GetInteger is declared.

---

## 💻 Method Declaration Coding Practice

### 🧩 Part A-2.1: method declaration
- Find the comment in the `Day1.h` file for Part A-2.1
- Add a method DECLARATION for a method called CreateTargets_PartA_2. 
  - The declaration should go in the Day1.h file.
  - The method should have 2 int parameters: mapSize and colorRange.
  - The method should return a vector that holds Target.

---

## 💻 Method Definition Coding Practice

### 🧩 Part A-2.2: method definition
- Find the comment in the `Day1.cpp` file for Part A-2.2 
- Add a method called CreateTargets_PartA_2. 
  - The definition should go in the Day1.cpp file.
  - The method should create a vector of 10 Target objects.
    - Use rand() % mapSize to pick the random position (row and col) for each target.
  - Return the vector.


---

## 💻 Method Calling Coding Practice

### 🧩 Part A-2.3: calling the method
- Find the comment in the `Day1.cpp` file for Part A-2.3 
  - Call CreateTargets_PartA_2 in the PartA_2() method. 
    - Before the loop call CreateTargets_PartA_2 and store the returned vector into the `targets` variable.

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