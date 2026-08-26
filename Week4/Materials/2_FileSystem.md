# 📘 File System
<!--TOC-->
  - [Checking whether a file exists](#1-checking-whether-a-file-exists)
  - [Listing Files in a Directory](#2-listing-files-in-a-directory)
<!--/TOC-->
## 🧾 Overview

## 1. Checking Whether a File Exists

### Conceptual Overview

Checking for file existence involves querying the operating system’s file system to determine whether a given path refers to a valid object. On Windows, the **C++17’s `<filesystem>` library** provides a standardized, cross‑platform abstraction.

Prior to C++17, developers often:
- Tried opening the file using `<fstream>`
- Used Windows‑specific APIs such as `GetFileAttributes`

Today, `<filesystem>` is preferred for correctness, portability, and clarity.

---

### Using `std::filesystem::exists`

```cpp
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::path filePath = "C:\\temp\\example.txt";

    if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
        std::cout << "File exists.\n";
    } else {
        std::cout << "File does not exist.\n";
    }

    return 0;
}
```

## 2. Listing Files in a Directory

### Conceptual Overview
Listing directory contents requires iterating over file system entries. In modern C++, <filesystem> provides iterator‑based directory traversal that hides platform‑specific details.

```cpp
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::path directoryPath = "C:\\temp";

    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        std::cout << "Invalid directory.\n";
        return 1;
    }

    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        std::cout << entry.path() << '\n';
    }

    return 0;
}
```
Explanation
- fs::directory_iterator iterates over immediate directory entries.
- directory_iterator gives a std::filesystem::directory_entry object.
  - entry.path() returns the full path to the file or folder.
  - path() returns a std::filesystem::path object.
    - Useful members of the path object:
      - filename() - the name of the file without the path
      - extension() - the extension of the file

---

![Footer Separator](../../Shared/Images/separator01.png)

## 🔭 Markdown Viewer

How to view the markdown files in a browser...
- [Markdown Viewer](../../Shared/0_Setup.md)

---

## 🧠 Lecture Practices

Here are the lecture Practices...
- [Day 10](./Day10.md)
- [Day 11](./Day11.md)

---

## 🔍 Lecture Quizzes

Here are the lecture quizzes...
- [Day 10](https://forms.office.com/r/tp8VDCWS2P)
- [Day 11](https://forms.office.com/r/tp8VDCWS2P)

---

## Weekly Topics
Here are the topics for the week...
- [CSV](./1_CSV.md)
- [File System](./2_FileSystem.md)
- [Writing CSV](./2_WritingCSV.md)
- [Reading CSV](./3_ReadingCSV.md)
- [Serializing](./4_Serializing.md)
- [Deserializing](./5_Deserializing.md)


[return to PG2 Topics](../../PG2_Topics.md)