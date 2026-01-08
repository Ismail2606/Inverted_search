# 🔍 Inverted Search Engine (C)

A **menu-driven command-line application** written in **C** that builds an **inverted index** from multiple text files and allows fast word searching using **hash tables and linked lists**.

---

## 📌 Project Overview

Inverted Search is a technique used by search engines to efficiently locate words across multiple documents.
Instead of searching each file repeatedly, this project builds an **inverted index** that maps each word to the files in which it appears along with its frequency.

This project is developed as part of the **Data Structures and Algorithms**.

---

## 🎯 Objectives

- Implement **hash tables** for fast searching
- Use **linked lists** to handle collisions
- Understand real-world **search engine indexing**
- Practice file handling and modular programming in C

---

## 🛠️ Technologies Used

- **Language:** C  
- **Concepts:**
  - Hash Tables
  - Linked Lists
  - File Handling
  - Dynamic Memory Allocation
  - Modular Programming

---

## ✨ Features

- Supports indexing of **multiple text files**
- Builds an **inverted index**
- Displays indexed data
- Searches for a word and shows:
  - Files containing the word
  - Number of occurrences per file
- Saves database to a file
- Updates database from saved data
- Prevents duplicate file indexing
- Menu-driven CLI interface

---

## 🗂️ Data Structures Used

### 🔹 Hash Table
- Size: **28**
- Index based on first character (`a–z` + special characters)

### 🔹 Linked Lists
- **Main Node:** Stores the word and no. of files
- **Sub Node:** Stores file name and word count

### 🔹 File Linked List
- Tracks already indexed files
- Prevents duplicate indexing

---
### bash
./inverted_search file1.txt file2.txt file3.txt

---

## 👤 Author

### Ismail Pasha
Embedded Systems & C Programmer

