#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <stdexcept>

using namespace std;

// ============================================================
// HELPER FUNCTION - Safe Input Handling
// ============================================================
template <typename T>
T getValidInput(const string& prompt)
{
    T value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            return value; // Input was valid and of correct type
        }
        else
        {
            cout << "  [!] Invalid input type! Please enter a valid number.\n";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        }
    }
}

// ============================================================
// ABSTRACT BASE CLASS - Person
// ============================================================
class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n)
    {
        setAge(a);
    }

    string getName() const { return name; }
    int getAge() const { return age; }

    void setName(string n) { name = n; }

    void setAge(int a)
    {
        if (a <= 0 || a > 120)
        {
            throw invalid_argument("Age must be between 1 and 120.");
        }
        age = a;
    }

    virtual void displayInfo() const = 0;
    virtual ~Person() {}
};

// ============================================================
// CLASS - Course (stores subject name and marks)
// ============================================================
class Course
{
private:
    string courseName;
    float marks;

public:
    Course(string cn, float m) : courseName(cn)
    {
        if (m < 0 || m > 100)
        {
            throw out_of_range("Marks must be between 0 and 100.");
        }
        marks = m;
    }

    string getCourseName() const { return courseName; }
    float getMarks() const { return marks; }

    void displayCourse() const
    {
        cout << "   Subject : " << setw(20) << left << courseName
             << " | Marks : " << marks << "/100" << endl;
    }
};

// ============================================================
// DERIVED CLASS - Student (inherits from Person)
// ============================================================
class Student : public Person
{
private:
    int studentID;
    vector<Course> courses;

public:
    Student(int id, string n, int a) : Person(n, a)
    {
        if (id <= 0)
        {
            throw invalid_argument("Student ID must be a positive integer.");
        }
        studentID = id;
    }

    int getStudentID() const { return studentID; }

    void addCourse(string courseName, float marks)
    {
        try
        {
            courses.push_back(Course(courseName, marks));
            cout << "  [+] Course added successfully!\n";
        }
        catch (const out_of_range& e)
        {
            cout << "  [!] Exception: " << e.what() << endl;
        }
    }

    float calculateAverage() const
    {
        if (courses.empty())
            return 0.0;

        float total = 0;
        for (size_t i = 0; i < courses.size(); i++)
            total += courses[i].getMarks();

        return total / courses.size();
    }

    float calculateGPA() const
    {
        float avg = calculateAverage();
        if (avg >= 90) return 4.0;
        else if (avg >= 80) return 3.5;
        else if (avg >= 70) return 3.0;
        else if (avg >= 60) return 2.5;
        else if (avg >= 50) return 2.0;
        else return 1.0;
    }

    string getGrade() const
    {
        float avg = calculateAverage();
        if (avg >= 90) return "A+";
        else if (avg >= 80) return "A";
        else if (avg >= 70) return "B";
        else if (avg >= 60) return "C";
        else if (avg >= 50) return "D";
        else return "F";
    }

    bool isPassed() const
    {
        return calculateAverage() >= 50;
    }

    void displayInfo() const override
    {
        cout << "\n  ----------------------------------------\n";
        cout << "  Student ID : " << studentID << endl;
        cout << "  Name       : " << name << endl;
        cout << "  Age        : " << age << endl;

        if (courses.empty())
        {
            cout << "  No courses added yet.\n";
        }
        else
        {
            cout << "  Courses    :\n";
            for (size_t i = 0; i < courses.size(); i++)
                courses[i].displayCourse();

            cout << fixed << setprecision(2);
            cout << "  Average    : " << calculateAverage() << "%" << endl;
            cout << "  GPA        : " << calculateGPA() << " / 4.0" << endl;
            cout << "  Grade      : " << getGrade() << endl;
            cout << "  Status     : " << (isPassed() ? "PASSED" : "FAILED") << endl;
        }
        cout << "  ----------------------------------------\n";
    }

    int getCourseCount() const { return courses.size(); }
};

// ============================================================
// CLASS - GradeBook (manages all students)
// ============================================================
class GradeBook
{
private:
    vector<Student> students;

    int findStudentIndex(int id) const
    {
        for (size_t i = 0; i < students.size(); i++)
            if (students[i].getStudentID() == id)
                return i;
        return -1;
    }

public:
    void addStudent(int id, string name, int age)
    {
        if (findStudentIndex(id) != -1)
        {
            cout << "  [!] Student with ID " << id << " already exists!\n";
            return;
        }

        try
        {
            students.push_back(Student(id, name, age));
            cout << "  [+] Student added successfully!\n";
        }
        catch (const invalid_argument& e)
        {
            cout << "  [!] Failed to add student: " << e.what() << endl;
        }
    }

    void addCourseToStudent(int id, string course, float marks)
    {
        int idx = findStudentIndex(id);
        if (idx == -1)
        {
            cout << "  [!] Student not found!\n";
            return;
        }

        students[idx].addCourse(course, marks);
    }

    void displayAllStudents() const
    {
        if (students.empty())
        {
            cout << "  [!] No students in the system.\n";
            return;
        }

        cout << "\n  ========== ALL STUDENTS ==========\n";
        for (size_t i = 0; i < students.size(); i++)
            students[i].displayInfo();
    }

    void searchStudent(int id) const
    {
        int idx = findStudentIndex(id);
        if (idx == -1)
            cout << "  [!] Student with ID " << id << " not found!\n";
        else
            students[idx].displayInfo();
    }

    void displayTopper() const
    {
        if (students.empty())
        {
            cout << "  [!] No students found.\n";
            return;
        }

        int topIdx = 0;
        for (size_t i = 1; i < students.size(); i++)
            if (students[i].calculateAverage() > students[topIdx].calculateAverage())
                topIdx = i;

        cout << "\n  === TOP STUDENT ===\n";
        students[topIdx].displayInfo();
    }

    void displayWeakest() const
    {
        if (students.empty())
        {
            cout << "  [!] No students found.\n";
            return;
        }

        int weakIdx = 0;
        for (size_t i = 1; i < students.size(); i++)
            if (students[i].calculateAverage() < students[weakIdx].calculateAverage())
                weakIdx = i;

        cout << "\n  === WEAKEST STUDENT ===\n";
        students[weakIdx].displayInfo();
    }
};

// ============================================================
// MAIN FUNCTION - Menu Driven Program
// ============================================================
int main()
{
    GradeBook gb;
    int choice;

    cout << "\n  ==========================================\n";
    cout << "     STUDENT GRADE MANAGEMENT SYSTEM\n";
    cout << "  ==========================================\n";

    do
    {
        cout << "\n  -------- MAIN MENU --------\n";
        cout << "  1. Add New Student\n";
        cout << "  2. Add Course & Marks\n";
        cout << "  3. Display All Students\n";
        cout << "  4. Search Student by ID\n";
        cout << "  5. Show Top Student\n";
        cout << "  6. Show Weakest Student\n";
        cout << "  0. Exit\n";

        choice = getValidInput<int>("  Enter choice: ");

        if (choice == 1)
        {
            int id = getValidInput<int>("  Enter Student ID  : ");

            cout << "  Enter Name        : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear stream before getline
            string name;
            getline(cin, name);

            int age = getValidInput<int>("  Enter Age         : ");

            gb.addStudent(id, name, age);
        }
        else if (choice == 2)
        {
            int id = getValidInput<int>("  Enter Student ID  : ");

            cout << "  Enter Course Name : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string course;
            getline(cin, course);

            float marks = getValidInput<float>("  Enter Marks (0-100): ");

            gb.addCourseToStudent(id, course, marks);
        }
        else if (choice == 3)
        {
            gb.displayAllStudents();
        }
        else if (choice == 4)
        {
            int id = getValidInput<int>("  Enter Student ID  : ");
            gb.searchStudent(id);
        }
        else if (choice == 5)
        {
            gb.displayTopper();
        }
        else if (choice == 6)
        {
            gb.displayWeakest();
        }
        else if (choice != 0)
        {
            cout << "  [!] Invalid choice! Select between 0 and 6.\n";
        }

    } while (choice != 0);

    cout << "\n  Goodbye! Good Luck in your Viva :)\n\n";

    return 0;
}