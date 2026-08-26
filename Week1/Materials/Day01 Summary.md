# 📘 Part A-1 Summary


## 💻 Calling Static Methods

```cpp
// Use ClassName:: to call static methods
Counter::increment();  
Counter::increment();  
Counter::showCount();  
```

---

## 💻 Calling Non-Static Methods

```cpp
// Step 1. Create an object of the Student class
Student s1; 

// Step 2. Use the Student variable to call the non-static methods
s1.setDetails("Alice", 20); 
s1.display();  // Output: Name: Alice, Age: 20
```

---

## 💻 Handling Return Values

```cpp
double w = 5.0, h = 3.0;
// Capturing the return value by 
// assigning it to the 'area' variable
double area = calculateArea(w, h);  
```

---

## 💻 Arguments Coding

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
---

# 📘 Part A-2 Summary

## 💻 Method Declaration 

In the header file...
```cpp
class Rectangle {

public:
    double area() const;            // Method declaration
    void scale(double factor);      // Method declaration
};
```

---

## 💻 Method Definition 

> NOTE: don't forget the `classname::` on the front of the method name in the cpp file

In the cpp file...
```cpp
// Method definition using class scope
double Rectangle::area() const {
    return width * height;
}

// Another method definition using class scope
void Rectangle::scale(double factor) {
    width *= factor;
    height *= factor;
}
```

