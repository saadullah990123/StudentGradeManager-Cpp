# 🎓 Student Grade Management System

A robust, terminal-based C++ application for managing student records, course enrollments, grade computation (GPA & percentage), and class performance analytics — built with clean OOP architecture and complete exception-safe input validation.

<div align="center">

[![C++](https://img.shields.io/badge/C%2B%2B-11%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![OOP](https://img.shields.io/badge/Architecture-OOP-brightgreen?style=for-the-badge)](#-oop-concepts--architecture)
[![Exception Safe](https://img.shields.io/badge/Input_Validation-Exception_Safe-blueviolet?style=for-the-badge)](#%EF%B8%8F-exception-handling--input-safety)
[![License](https://img.shields.io/github/license/saadullah990123/StudentGradeManager-Cpp?style=flat-square&color=blue)](LICENSE)

</div>

---

## 📖 Overview

**Student Grade Management System** is a menu-driven console application that lets you register students, enroll them in courses with marks, and automatically compute their percentage, GPA (on a 4.0 scale), and letter grade. It also provides class-wide analytics — instantly surfacing the top performer and the student who needs the most support.

The project is intentionally built to demonstrate strong C++ fundamentals: abstraction, inheritance, polymorphism, encapsulation, composition, templates, and defensive exception handling — all in a single, readable codebase.

---

## 📸 Demo

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
```

<div align="center">
  <img width="480" alt="Student Grade Management System — add student and menu" src="https://github.com/user-attachments/assets/d8aa9822-5e6e-4dc0-837b-6f81d75b9e9e" />
  &nbsp;&nbsp;
  <img width="440" alt="Student Grade Management System — student report card" src="https://github.com/user-attachments/assets/0fac7b46-2e85-4254-b42d-23346b9d803a" />
</div>

---

## ✨ Key Features

| Feature | Description |
|---|---|
| 👤 **Student Profile Management** | Register students with unique IDs, names, and validated ages (1–120). |
| 📚 **Dynamic Course Allocation** | Assign unlimited courses with marks (0–100) per student, stored dynamically via `std::vector`. |
| 📊 **Automated Grade & GPA Engine** | Computes average percentage, letter grade (A+ to F), pass/fail status, and 4.0-scale GPA automatically. |
| 🔍 **Instant ID Search** | Look up any student's complete academic transcript by ID. |
| 🏆 **Class Performance Analytics** | Instantly identifies the class topper and weakest performer by average marks. |
| 🛡️ **Crash-Proof Input Validation** | Gracefully handles invalid data types and out-of-range values without crashing or infinite-looping. |

---

## 🧬 OOP Concepts & Architecture

| Concept | Implementation in Code |
|---|---|
| **Abstraction** | Pure virtual function `virtual void displayInfo() const = 0` in the abstract `Person` base class. |
| **Inheritance** | `Student` publicly derives from `Person` (`class Student : public Person`). |
| **Polymorphism** | Runtime method overriding of `displayInfo()` across derived types. |
| **Encapsulation** | Private/protected members exposed only through getters, setters, and bounds-checked mutators. |
| **Composition** | Each `Student` owns a `std::vector<Course>`, modeling a "has-a" relationship. |
| **Templates** | Generic `getValidInput<T>()` wrapper for type-safe terminal input across `int` and `float`. |

---

## 🛡️ Exception Handling & Input Safety

The application is built with defensive programming practices throughout:

- **Stream Clearing & Error Recovery** — the templated input wrapper detects type mismatches (e.g. letters typed into a numeric field), clears the failed stream state, and re-prompts instead of crashing.
- **Domain Validation** — throws standard exceptions (`std::invalid_argument`, `std::out_of_range`) for invalid data such as negative/out-of-range ages or marks outside 0–100.
- **Duplicate Prevention** — checks for an existing student ID before allowing a new registration.
- **Graceful Degradation** — every exception is caught at the point of use and reported to the user with a clear `[!]` message, so the program never terminates unexpectedly.

---

## 🗂️ Project Structure

```
StudentGradeManager-Cpp/
├── main.cpp         # Complete C++ source implementation
├── docs/            # Screenshots and preview assets
│   └── demo.png     # Terminal execution screenshot
└── README.md        # Project documentation
```

---

## ⚙️ Getting Started

### Prerequisites

- A C++11 (or later) compatible compiler — [g++](https://gcc.gnu.org/), Clang, or MSVC.

### Build & Run

**Using g++:**
```bash
g++ -std=c++11 -o grade_manager main.cpp
./grade_manager
```

**Using Windows / MSVC (Developer Command Prompt):**
```bash
cl main.cpp
main.exe
```

---

## 🖥️ Usage

Once launched, navigate the menu using numeric input:

1. **Add New Student** — enter a unique ID, name, and age.
2. **Add Course & Marks** — attach a course and score (0–100) to an existing student ID.
3. **Display All Students** — view full transcripts for every registered student.
4. **Search Student by ID** — pull up one student's report instantly.
5. **Show Top Student** — see the highest-averaging student in the system.
6. **Show Weakest Student** — see the lowest-averaging student in the system.
0. **Exit** — close the application.

---

## 🛣️ Possible Future Enhancements

- Persist student records to a file or lightweight database between runs.
- Export individual transcripts or the full class report to CSV/PDF.
- Add a GUI front-end (Qt or a web-based dashboard) on top of the existing logic.
- Support weighted GPA calculation (credit hours per course).

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

---

## 👤 Author

 Made by **Saad Ullah  ❤️**
GitHub: [@saadullah990123](https://github.com/saadullah990123)
