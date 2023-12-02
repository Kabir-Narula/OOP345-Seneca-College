/*Aggregation represents a "whole-part" relationship like composition, but with a key difference: part objects can exist independently of the whole. The whole object has a reference or pointer to the part objects, but it doesn't necessarily own them. Part objects can be shared among multiple whole objects, and their lifetimes aren't strictly tied to the whole object.*/

#include <iostream>
#include <string>
#include <vector>

class Department {
public:
    Department(const std::string& name) : name(name) {
        // Department constructor
    }
private:
    std::string name;
};

class University {
private:
    std::vector<Department*> departments; // Aggregation: University has Departments
public:
    void AddDepartment(Department* dept) {
        departments.push_back(dept);
    }
};

int main() {
    Department* dept1 = new Department("Computer Science");
    Department* dept2 = new Department("Physics");

    University myUniversity;
    myUniversity.AddDepartment(dept1);
    myUniversity.AddDepartment(dept2);

    // Departments can exist independently
    delete dept1;
    delete dept2;

    return 0;
}

/*In this example, a University aggregates Department objects using pointers. Departments can exist independently and are not destroyed when the university is destroyed. Multiple universities can share the same department objects.*/