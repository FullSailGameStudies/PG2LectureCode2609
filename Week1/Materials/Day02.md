# 📘 Day 02 Lecture Practices

## 💻 Pass by Reference Coding Practice

### 🧩 Part B-1.1: Add a method *declaration*
1. Open `Day2.h`
2. Add a declaration for a method called SpawnZombies to the Day2.h file
   - It should not return anything.
   - It should have 3 parameters:
	 - a PG2Graphics parameter
	 - a vector of Zombie parameter
	 - a Player parameter

### 🧩 Part B-1.2: Add a method *definition*

1. Open the `Day2.cpp` file
2. Add the SpawnZombies definition to the Day2.cpp file
   - fill the vector with 5 Zombie objects.
	 - randomize the x and y position of each zombie
		- HINT: use rand() % 10 where 10 is the size of the map
	 - make sure the zombie position does NOT match the player's position.
		- HINT: get the player's position using the GetXPosition and GetYPosition methods of the player.
	 - Example of how to create a Zombie object: Zombie zomb(engine, 0.5f, x, y); 
		- NOTE: 0.5f is the scale

### 🧩 Part B-1.3: call the method
1. Open the `Day2.cpp` file
2. In the PartB() method, call the SpawnZombies method passing the engine, mobs, and player variables.
3. Debug the PartB method and check that the mobs variable has 5 zombies in it after calling SpawnZombies.


---

## 💻 Const Coding Practice

### 🧩 Part B-2.1: create a *declaration*
1. Open `Day2.h`
2. Add a method declaration for a method called RenderZombies.
   - It should not return anything.
   - It should have 1 parameter: a vector of Zombie parameter.

### 🧩 Part B-2.2: create a *definition*
1. Open `Day2.cpp`
2. Add a method definition for RenderZombies.
   - In the method definition, call Render for each Zombie.

### 🧩 Part B-2.3: call the method
1. Open `Day2.cpp`.
2. In the PartB() method, find the comment `Part B-2.3 call RenderZombies` and call the RenderZombies method.

---

## 💻 Erasing in a Loop Coding Practice

### 🧩 Part B-3.1: create a declaration
1. Open `Day2.h`
2. Add a method declaration for a method called KillZombies.
   - It should return an int representing the number of zombies that were killed.
   - It should have 2 parameters: 
	 - a vector of Zombie parameter
	 - a Player parameter
   
### 🧩 Part B-3.2: create a definition
1. Open `Day2.cpp`
2. Add a method definition for KillZombies.
   - Inside the method, erase any zombie from the vector whose distance to the player is < 4.
	 - HINT: to calculate the distance between 2 points...distance = sqrt ( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) )
   - return the number of zombies that were erased from the vector

### 🧩 Part B-3.3: call a method
1. Open `Day2.cpp`
2. In the PartB() method, find the comment `Part B-3.3 Call KillZombies` and call the KillZombies method.
3. After calling the method, print how many zombies were killed.

---

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