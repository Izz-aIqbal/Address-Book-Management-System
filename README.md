# Address Book Management System

A high-performance console application built in **C (GCC)** and **C++** leveraging core **Data Structures and Algorithms (DSA)** including **Doubly Linked Lists** and persistent file handling for seamless contact management and low-level memory control.

---

##  Project Overview

Built an Address Book application in C (GCC) and C++ leveraging DSA (Linked Lists / Hash Tables) and file handling for persistent storage, demonstrating OS-level memory management.

### Key Highlights
* **Multi-Language Architecture**: Implemented using both C (GCC) and C++ paradigms to showcase low-level pointers and Object-Oriented/procedural memory handling.
* **Data Structures**: Doubly Linked List implementation for dynamic node management and $O(1)$ pointer-based insertions/deletions.
* **Persistent Storage**: Dynamic CSV file I/O operations to write and synchronize memory records across sessions.
* **OS-Level Memory Management**: Explicit low-level heap allocation (`malloc`/`free` in C, `new`/`delete` in C++) with pointer sanitization to prevent memory leaks and dangling pointers.
* **Input Validation**: Pattern validation for phone numbers, email addresses, and contact fields.

---

##  Features & Capabilities

- **Add Contact**: Insert dynamic contact entries with automated node allocation.
- **Edit / Update**: Modify existing contact records with real-time pointer re-linking.
- **Search Functionality**: Efficient linear search and lookup across contact fields.
- **Delete Contact**: Safely remove contact nodes while preserving linked list integrity and freeing allocated memory.
- **CSV Data Persistence**: Sync runtime data directly to disk (`contacts.csv`) on startup and exit.

---

##  Data Structures & Performance Breakdown

| Module | Data Structure / Algorithm | Operational Complexity |
| :--- | :--- | :--- |
| **Node Storage** | Doubly Linked List | Space: $O(n)$ |
| **Record Insertion** | Dynamic Tail / Head Insertion | $O(1)$ |
| **Record Deletion** | Pointer Re-linking & Explicit Deallocation | $O(1)$ |
| **Search Function** | Field-based Linear Search | $O(n)$ |
| **Data Persistence** | File I/O Stream Parsing (CSV) | $O(n)$ |

---

##  Getting Started

### Prerequisites
* **Compiler**: GCC / G++ (MinGW for Windows, Clang / GCC for Linux/macOS)

### Build & Run Instructions

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/Izz-aIqbal/Address-Book-Management-System.git](https://github.com/Izz-aIqbal/Address-Book-Management-System.git)
   cd Address-Book-Management-System
