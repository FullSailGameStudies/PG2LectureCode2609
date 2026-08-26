# 📘 Part B-1 Summary

## 💻 Pass by Reference 
```cpp
//& prevents a copy. 
//when called in main, x refers to the 'a' variable in main
void increment(int& x) //pass-by reference. prevents a COPY!
{
    x++; // updates 'a' in main
}

int main() {
    int a = 5;
    increment(a);
    cout << a << endl;  // Output: 6
}
```

## 💻 Range-based Loops 
```cpp
//the loop variable, n, is a reference to the int in the vector
//it is NOT a copy of each int
for(int& n : nums) {
    cout << n << " "; 
} 
```

---

# 📘 Part B-2 Summary

## 💻 Const Parameters
`MinMaxSum` cannot modify the `numbers` parameter.
```cpp
int MinMaxSum(const std::vector<int>& numbers, int& min, int& max)
{ 
    int sum = 0;
    min = max = numbers[0];
    for(int i=1;i<numbers.size();i++)  {
        if(min > numbers[i]) min = numbers[i];
        if(max < numbers[i]) max = numbers[i];
        sum += numbers[i];
    }
    returm sum;
}
```

---

## 💻 Const Methods 

Put `const` after the `()` and before the `;` in the declaration.
```cpp
class MyClass {
public:
    int getValue() const; //cannot modify the "price" field of the class.
private:
    double price;
};
```

---

# 📘 Part B-3 Summary

## 💻 Erasing in a Loop
1. Reverse loop
```cpp
for (int i = nums.size() - 1; i >= 0; --i) {
    if (nums[i] % 2 == 0) {
        nums.erase(nums.begin() + i);
    }
}
```

2. Iterator loop
```cpp
for (auto it = nums.begin(); it != nums.end(); ) {
    if (*it % 2 == 0) {
        it = nums.erase(it);  // erase returns the next valid iterator
    } else {
        ++it;  // only increment if no erase
    }
}
```
