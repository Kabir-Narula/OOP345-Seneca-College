/*Association represents a general relationship between classes, where objects of one class are related to objects of another class. This relationship can be of various types, such as "uses," "knows," or "interacts with." Association doesn't imply ownership or containment; it simply signifies that there is some connection or interaction between the classes.*/


#include <iostream>
#include <string>
#include <vector>

class Course {
public:
    Course(const std::string& name) : name(name) {
        // Course constructor
    }
private:
    std::string name;
};

class Student {
private:
    std::vector<Course*> courses; // Association: Student is associated with Course
public:
    void EnrollInCourse(Course* course) {
        courses.push_back(course);
    }
};

int main() {
    Course* course1 = new Course("Math");
    Course* course2 = new Course("History");

    Student student1;
    student1.EnrollInCourse(course1);
    student1.EnrollInCourse(course2);

    // Courses and students can exist independently
    delete course1;
    delete course2;

    return 0;
}

/*In this example, an association between Student and Course is established. A student can enroll in courses, but the courses and students can exist independently. This represents a simple association without implying ownership or containment.*/

/* 1)What is association in object-oriented programming, and how does it differ from composition and aggregation?

Association represents a general relationship between classes without implying ownership or containment. It is a more flexible and loosely coupled relationship compared to composition and aggregation.
Example: An association between Student and Course classes. This implies that students can enroll in courses, but neither owns the other. The nature of the connection is interaction or relationship without strict ownership.

2)Does association imply any specific ownership or containment semantics between the associated classes?

No, association does not imply ownership or containment semantics. It represents a more general relationship where objects of one class are related to objects of another class without specifying ownership.

3)How can you represent an association between classes in C++ code, and what are the typical ways to access associated objects?

Association can be represented in C++ by using member variables or method parameters that reference objects of other classes. Access to associated objects can be done through these references or pointers.*/