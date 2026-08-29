# 🎓 Student Grade Management System

A C++ project designed to manage student records, course enrolments, grade computations (GPA/Percentage), and class performance analytics.

<div align="center">

[![C++](https://img.shields.io/badge/C%2B%2B-11-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![OOP](https://img.shields.io/badge/Architecture-OOP-brightgreen?style=for-the-badge)](#-oop-concepts-demonstrated)
[![License](https://img.shields.io/github/license/saadullah990123/StudentGradeManager-Cpp?style=flat-square&color=blue)](LICENSE)

</div>

---

## ✨ Features & Functional Highlights

* 👤 **Student Profile Management:** Register students with unique IDs, names, and ages.
* 📚 **Dynamic Course Allocation:** Assign multiple courses with marks (0–100) per student dynamically using standard library containers (`std::vector`).
* 📊 **Automated Grade & GPA Calculation:** Computes percentages, letter grades (`A+` to `F`), pass/fail statuses, and 4.0 GPA scale metrics on the fly.
* 🔍 **ID Search Engine:** Fast lookup functionality to retrieve complete academic transcripts by student ID.
* 🏆 **Class Analytics:** Identifies class toppers and weakest performers based on weighted average mark computations.

---

## 🧬 OOP Concepts Demonstrated

| Concept | Implementation in Code |
| :--- | :--- |
| **Abstraction** | Pure virtual function `virtual void displayInfo() const = 0` inside the abstract `Person` class. |
| **Inheritance** | `Student` class derives publicly from the `Person` base class (`class Student : public Person`). |
| **Polymorphism** | Runtime method overriding of `displayInfo()` across derived types. |
| **Encapsulation** | Protected and private members (`name`, `courses`, `studentID`) exposed safely via public getters/setters. |
| **Composition** | `Course` objects managed within a `std::vector<Course>` inside the `Student` lifecycle. |

---

## 📂 Project Structure

```text
StudentGradeManager-Cpp/
├── .cpp       # Main C++ source file containing all classes and execution menu
└── README.md      # Repository documentation
