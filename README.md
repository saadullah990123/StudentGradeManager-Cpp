# 🎓 Student Grade Management System

A robust, terminal-based C++ application designed to manage student records, course enrollments, grade computations (GPA/Percentage), and class performance analytics with complete exception safety and input validation.

<div align="center">

[![C++](https://img.shields.io/badge/C%2B%2B-11%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![OOP](https://img.shields.io/badge/Architecture-OOP-brightgreen?style=for-the-badge)](#-oop-concepts-demonstrated)
[![Exception Safe](https://img.shields.io/badge/Input_Validation-Exception_Safe-blueviolet?style=for-the-badge)](#-robustness--exception-handling)
[![License](https://img.shields.io/github/license/saadullah990123/StudentGradeManager-Cpp?style=flat-square&color=blue)](LICENSE)

</div>

---

## 📸 Application Demo

```text
  ==========================================
     STUDENT GRADE MANAGEMENT SYSTEM
  ==========================================

  -------- MAIN MENU --------
  1. Add New Student
  2. Add Course & Marks
  3. Display All Students
  4. Search Student by ID
  5. Show Top Student
  6. Show Weakest Student
  0. Exit
  Enter choice: 1

  Enter Student ID  : 101
  Enter Name        : Saad Ullah
  Enter Age         : 21
  [+] Student added successfully!

  ✨ Key Features & Functional Highlights
👤 Student Profile Management: Register students with unique IDs, names, and validated ages.
📚 Dynamic Course Allocation: Assign multiple courses with marks ($0 - 100$) per student dynamically using std::vector.
📊 Automated Grade & GPA Engine: Computes percentages, letter grades (A+ to F), pass/fail statuses, and $4.0$ GPA scale metrics automatically.
🔍 Instant ID Search: Lookup functionality to retrieve complete academic transcripts by student ID.
🏆 Class Performance Analytics: Instantly identifies class toppers and weakest performers based on weighted averages.
🛡️ Crash-Proof Input Validation: Robust handling of invalid data types, preventing infinite loops or unexpected crashes.

🧬 OOP Concepts & Architecture

Concept               Implementation in Code

Abstraction            Pure virtual function virtual void displayInfo() const = 0 inside the abstract Person class.

Inheritance            Student class derives publicly from the base Person class (class Student : public Person).

Polymorphism           Runtime method overriding of displayInfo() across derived types.

Encapsulation           Private/protected members guarded with getters, setters, and explicit bounds checking.

Composition              Course objects managed within a std::vector<Course> container inside Student.

Templates                  Generic stream wrapper getValidInput<T>() for type-safe terminal data entry.



🛡️ Exception Handling & Input Safety

This application is built with defensive programming practices:

Stream Clearing & Error Recovery: Custom template wrapper handles type mismatches (e.g., entering letters into numerical fields) without crashing the stream buffer.

Domain Validations: Throws standard C++ exceptions (std::invalid_argument, std::out_of_range) for out-of-bounds inputs like negative ages or invalid mark values.

Duplicate Prevention: Checks for existing student IDs before allocation.


StudentGradeManager-Cpp/
├── main.cpp         # Complete C++ source implementation
├── docs/            # Screenshots and preview assets
│   └── demo.png     # Terminal execution screenshot
└── README.md        # Project documentation


<img width="548" height="800" alt="image" src="https://github.com/user-attachments/assets/d8aa9822-5e6e-4dc0-837b-6f81d75b9e9e" />
<img width="500" height="818" alt="image" src="https://github.com/user-attachments/assets/0fac7b46-2e85-4254-b42d-23346b9d803a" />


