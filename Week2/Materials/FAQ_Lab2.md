# ❓ Lab 2: Frequently Asked Questions
<!--TOC-->
  - [❓ Q: Do you have any tips for lab 2?](#-q-do-you-have-any-tips-for-lab-2)
  - [❓ Q: Why does my translation of the pseudo-code not work?](#-q-why-does-my-translation-of-the-pseudo-code-not-work)
  - [❓ Q: How do I do ____ with a vector?](#-q-how-do-i-do-____-with-a-vector)
<!--/TOC-->
## ❓ Q: Do you have any tips for lab 2?

### 💡 A: Of course! here they are...

#### **🧠 Pseudocode Reminders:**
* **INDENTATION MATTERS** ‼️
  * It shows scope (what's inside ifs, loops, etc.)
* `endif` means end of the `if` statement
* **All 3 while loops are required** in Merge!
* Use **`const` and references** when needed
  * Unlike Lab 1, you're not always told when to use them
* We recommend copying and pasting the pseudocode as a comment
  * You can use it as a guide for the code you are writing

#### **🧪 Merge & MergeSort:**
* Can’t test them until **`SortByAttribute`** is working
* When testing use Durability
   * Make sure **the last hero's durability is 110**

#### **🔍 BinarySearch:**
* Can’t test until **`FindHero`** is done
* Test with:
  * **Batman** → index 51
  * **Aquaman** → index 30
  * **Zoom** → last hero in vector with index 562
* `A[0..N-1]` = whole array/vector
* `FindHero` method you are creating shows you how the **search term** is built
   * This method is in the instructions on FSO BELOW BinarySearch
* Look back at Lab 1 to see how comparisons work. We expect you to compare strings the same way.

#### **👥 GroupHeroes:**
* There’s already a **map** ready for you
  * Check the **HeroesDB** file
* Strings are char arrays
  * You can grab the first letter by calling the first index of the string

#### **🗑️ RemoveHero (Map):**
* Don’t forget to remove from the **vector** too!
  * Test the results of RemoveHero by running these menu options after trying to remove a hero:
    * `FindHero`
    * `FindHeroByLetter`
    * `PrintGroupCounts`
---

## ❓ Q: Why does my translation of the pseudo-code not work?

### 💡 A: Here are some tips for finding the problem...

- Don't assume you translated it correctly. Go back and compare your code `line-by-line` with the pseudo-code. Sometimes you have to compare it character-by-character to find the issue.
- Don't assume the pseudo-code is incorrect. It is not. In many cases, the pseudo-code is actually older than you. 😊
- ***indention is critical***. Indention in pseudo-code often is the only indication you'll get what block the line of code belongs to.

---

## ❓ Q: How do I do ____ with a vector?

### 💡 A: Here are the different ways to work with a vector.
Here are some examples of working with a vector.

```cpp
 //Working with a vector...
 //create a vector
    std::vector<int> nums;

 //add to a vector
    nums.push_back(5);

 //get # of items
    int numberOfItems = nums.size();

 //get the first item in a vector
    int number = nums[0];
    number = nums.at(0);//or...
    number = nums.front();//or...
    number = *(nums.begin());//or...

 //get the item using an index
    int index = 0;
    int number = nums[index];
    number = nums.at(index);

 //erase from a vector
    nums.erase(nums.begin());//to erase the first item

 //check if a vector is empty
    bool isEmpty = nums.empty();
    //or...
    isEmpty = nums.size() == 0;

 //check if a vector is NOT empty
    bool notEmpty = !nums.empty();
    //or...
    notEmpty = nums.size() != 0;

```
---

