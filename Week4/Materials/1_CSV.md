# 📘 CSV (Comma-Separated Values) Data Format
<!--TOC-->
  - [🧾 Overview](#-overview)
  - [📐 Structure](#-structure)
    - [Basic Example](#basic-example)
  - [🧠 Key Concepts](#-key-concepts)
    - [1. **Delimiters**](#1-delimiters)
    - [2. **Quoting**](#2-quoting)
    - [3. **Missing Values**](#3-missing-values)
  - [🛠️ Use Cases](#%EF%B8%8F-use-cases)
  - [⚠️ Limitations](#%EF%B8%8F-limitations)
  - [🎯 Quiz!](#-quiz)
<!--/TOC-->
## 🧾 Overview

**CSV** is a simple, widely-used data format for storing **tabular data** (data structured in rows and columns). Each line in a CSV file corresponds to a **row**, and each value within that line corresponds to a **column**, separated by a **delimiter**, typically a comma (`,`).

CSV is popular because it is:
- **Human-readable**
- **Lightweight**
- **Easily parsed** by programming languages and spreadsheet software (e.g., Excel, Google Sheets, Python, R)

---

## 📐 Structure

A typical CSV file has:
1. **Header row** (optional): Names of the columns.
2. **Data rows**: Each row contains values corresponding to the columns.

### Basic Example

```csv
Name,Age,Major
Alice,21,Computer Science
Bob,22,Mathematics
Charlie,20,Physics
```

This represents a table like:

| Name    | Age | Major           |
|---------|-----|------------------|
| Alice   | 21  | Computer Science |
| Bob     | 22  | Mathematics      |
| Charlie | 20  | Physics          |

---

## 🧠 Key Concepts

### 1. **Delimiters**
While commas are standard, other delimiters like semicolons (`;`) or tabs (`\t`) may be used, especially in regions where commas are used as decimal points.

### 2. **Quoting**
Fields containing commas, newlines, or quotes must be enclosed in **double quotes** (`"`). Quotes inside fields are escaped by doubling them.

```csv
Name,Comment
Alice,"Loves ""data"", math, and science"
```

### 3. **Missing Values**
Empty fields represent missing data.

```csv
Name,Age,Major
Alice,21,
Bob,,Mathematics
```

---

## 🛠️ Use Cases

- **Data exchange** between systems (e.g., exporting from a database to Excel)
- **Data ingestion** in data science and machine learning workflows
- **Configuration files** for simple applications

---

## ⚠️ Limitations

- No support for nested or hierarchical data
- No data types (everything is a string)
- Ambiguity in delimiters and quoting rules across implementations

---

## 🎯 Quiz!

Here's a short quiz on the topic: [quiz](./1_CSV_quiz.html)

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