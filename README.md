<div align="center">

# 📚 Library Management System

![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B)
![Project Type](https://img.shields.io/badge/Project-Console%20Application-orange?style=for-the-badge)

![Contributions](https://img.shields.io/badge/Contributions-Welcome-brightgreen?style=for-the-badge)

**A powerful, efficient, and user-friendly console application for managing library inventories.**

[Getting Started](#-getting-started) •
[Features](#-features) •
[Technical Highlights](#-technical-highlights) •
[Usage](#-usage) •
[Contributing](#-contributing)

---

</div>

## 📖 Overview

The **Library Management System** is a robust C++ mini-project designed to simulate the core operations of a real-world library. It provides a clean, menu-driven interface for librarians to manage books, track issued items, and maintain an organized catalog.

Whether you're exploring C++ data structures or looking for a solid reference implementation of file handling logic, this project serves as an excellent educational resource.

## ✨ Features

Experience a seamless workflow with these key functionalities:

- **➕ Add New Books**: Effortlessly expand your library database with unique IDs, titles, and author names.
- **🚫 Duplicate Prevention**: Smart validation ensures no two books share the same ID.
- **📖 Issue Management**: Track which books are currently out on loan with a simple status toggle.
- **↩️ Easy Returns**: Process returns instantly and update book availability in real-time.
- **🔍 Powerful Search**: Find any book instantly by **Title** or **Author** using case-insensitive search.
- **❌ Inventory Control**: Permanently remove outdated or lost books from the system.
- **📊 Live Dashboard**: View the complete list of books with their current status (Available/Issued) at a glance.

## 🛠️ Technical Highlights

This project showcases modern C++ programming concepts:

- Utilizes `struct Book` to encapsulate book data (`id`, `title`, `author`, `isIssued`).
- **Modular Architecture**: Clean code separation with dedicated functions for each operation (`addBook`, `issueBook`, `searchBook`).
- **Input Validation**: Robust handling of user inputs to prevent crashes and ensure data integrity.

## 🚀 Getting Started

### Prerequisites

All you need is a C++ compiler. Popular options include:

- **GCC/G++** (Standard on Linux/macOS)
- **Clang**
- **MinGW** (for Windows)
- **MSVC** (Visual Studio)

3.  **Run the Application**:
    - **macOS/Linux:**
      ```bash
      ./LibrarySystem
      ```
    - **Windows:**
      ```cmd
      LibrarySystem.exe
      ```

## 📸 Usage

Upon launching, you will be greeted by an interactive menu. Enter the number corresponding to your desired action.

```text
------------------------------------------------------------
-                 LIBRARY MANAGEMENT SYSTEM                -
------------------------------------------------------------
------------------------------------------------------------
  [1] Add New Book
  [2] Issue Book
  [3] Return Book
  [4] Display All Books
  [5] Search Book
  [6] Delete Book
  [7] Exit
------------------------------------------------------------
  Enter your choice:
```

### Example Workflow

1.  **Add a Book**: Select `1`, enter ID `101`, Title `The Alchemist`, Author `Paulo Coelho`.
2.  **Search**: Select `5`, type `Alchemist`.
3.  **Issue**: Select `2`, enter ID `101`.
4.  **Display**: Select `4` to see that `101` is now **Issued**.

## 🔮 Future Roadmap

We are constantly working to improve this project! Here's what's coming next:

- [ ] **💾 File Persistence**: Save and load library data from a file so records aren't lost when the program closes.
- [ ] **🔐 User Authentication**: Separate login portals for Librarians (Admin) and Students (User).
- [ ] **📅 Due Dates & Fines**: Implement date tracking to calculate fines for late returns.
- [ ] **🎨 GUI Version**: Port the application to a graphical interface using Qt or wxWidgets.

## 🤝 Contributing

Contributions make the open-source community an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1.  Fork the Project
2.  Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3.  Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4.  Push to the Branch (`git push origin feature/AmazingFeature`)
5.  Open a Pull Request

<div align="center">
  <p>Made by Ankitraj Jha</p>
</div>
