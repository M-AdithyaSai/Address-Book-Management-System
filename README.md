# 📒 Address Book Management System

A menu-driven **Address Book Management System** developed using C programming. This application allows users to efficiently create, search, edit, delete, and manage contact information with file-based data storage.

## 🚀 Features

- **Create Contact:** Add new contacts with name, phone number, and email address.
- **Search Contact:** Search for contacts using name, phone number, or email.
- **Edit Contact:** Modify existing contact information.
- **Delete Contact:** Delete selected contacts with confirmation.
- **List Contacts:** Display all saved contacts.
- **Sorting:** Sort contacts alphabetically by name, phone number, or email.
- **Input Validation:** Validate names, phone numbers, and email addresses.
- **Duplicate Prevention:** Prevent duplicate phone numbers and email addresses.
- **File Handling:** Save contact information to a CSV file and load it when the application starts.
- **Maximum Capacity:** Supports up to 100 contacts.

## 🛠️ Technologies & Concepts Used

- **Programming Language:** C
- Structures and Arrays
- Pointers
- Functions and Modular Programming
- String Handling
- File Handling (CSV)
- Input Validation
- Searching and Sorting Algorithms
- Bubble Sort

## 📂 Project Structure

```text
AddressBook/
│
├── main.c          # Main function and menu-driven interface
├── contact.c       # Contact listing, sorting and initialization
├── contact.h       # Structure definitions and function prototypes
├── create.c        # Creating new contacts
├── search.c        # Searching contacts
├── edit.c          # Editing existing contacts
├── delete.c        # Deleting contacts
├── validate.c      # Validating contact information
├── file.c          # Saving and loading contact data
├── file.h          # File handling function declarations
├── populate.c      # Sample contact data
├── populate.h      # Population function declaration
│
└── addbook.csv     # Contact database
```

## ⚙️ How to Compile and Run

### Prerequisites

- GCC Compiler
- Linux environment or Windows with a compatible GCC toolchain

### 1. Clone the Repository

```bash
git clone https://github.com/M-AdithyaSai/Address-Book-Management-System.git
```

### 2. Navigate to the Project Directory

```bash
cd Address-Book-Management-System
```

### 3. Compile the Source Files

```bash
gcc -D_DEFAULT_SOURCE *.c -o addressbook
```

### 4. Run the Application

```bash
./addressbook
```

## 📋 Application Menu

```text
========== Address Book Menu ==========
1. Create Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. List All Contacts
6. Exit
=======================================
Enter your choice:
```

## 💾 Data Storage

- Contact information is stored in `addbook.csv`.
- Existing contacts are loaded automatically when the application starts.
- Updated contact information is saved when the user selects the Exit option.

## 🎯 Learning Outcomes

Through this project, I gained practical experience in:

- Designing modular C applications.
- Working with structures and pointers.
- Implementing CRUD (Create, Read, Update, Delete) operations.
- Managing persistent data using file handling.
- Implementing searching and sorting techniques.
- Applying input validation and error handling.

## 👨‍💻 Author

**M Adithya Sai**

- GitHub: [M-AdithyaSai](https://github.com/M-AdithyaSai)

---

⭐ If you find this project useful, consider giving it a star!
