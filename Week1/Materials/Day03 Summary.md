# 📘 Part C-1 Summary

## 💻 Default Parameter
> The default parameters must appear at the end of the parameter list

> The default value can `ONLY` be in the declaration.

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



---

# 📘 Part C-2 Summary

## 💻 Copying Vectors

### Copy each element manually
```cpp
std::vector<int> scores = { 1,2,3,4,5 };
std::vector<int> scores2;
scores2.reserve(scores.size()); // reserve the space needed
for (size_t i = 0; i < scores.size(); i++)
	scores2.push_back(scores[i]);
```

### use the assignment `=` operator
```cpp
std::vector<int> scores = { 1,2,3,4,5 };
std::vector<int> scores3 = scores;
```

### passing a vector to the constructor of the new vector
```cpp
std::vector<int> scores = { 1,2,3,4,5 };
std::vector<int> scores4(scores);
```
