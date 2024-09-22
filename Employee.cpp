#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    string address;
    string post;
    double salary;
    string department;
    int experience;
    Employee* next;
};

Employee* head = nullptr;

void addEmployee(int id, string name, string address, string post, double salary, string department, int experience) {
    Employee* newEmployee = new Employee();
    newEmployee->id = id;
    newEmployee->name = name;
    newEmployee->address = address;
    newEmployee->post = post;
    newEmployee->salary = salary;
    newEmployee->department = department;
    newEmployee->experience = experience;
    newEmployee->next = head;  
    head = newEmployee;
    cout << "Employee added successfully!\n";
}

void displayEmployees() {
    if (head == nullptr) {
        cout << "No employees in the system.\n";
        return;
    }
    
    Employee* temp = head;
    cout << "\n--- Employee List ---\n";
    while (temp != nullptr) {
        cout << "ID: " << temp->id << "\n";
        cout << "Name: " << temp->name << "\n";
        cout << "Address: " << temp->address << "\n";
        cout << "Post: " << temp->post << "\n";
        cout << "Salary: " << temp->salary << "\n";
        cout << "Department: " << temp->department << "\n";
        cout << "Experience: " << temp->experience << " years\n";
        cout << "----------------------\n";
        temp = temp->next;
    }
}

Employee* searchEmployee(int id) {
    Employee* temp = head;
    while (temp != nullptr) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void promoteEmployee(int id, string newPost, double increment) {
    Employee* emp = searchEmployee(id);
    if (emp == nullptr) {
        cout << "Employee with ID " << id << " not found.\n";
        return;
    }
    emp->post = newPost;
    emp->salary += increment;
    cout << "Employee promoted successfully!\n";
}

void demoteEmployee(int id, string newPost, double decrement) {
    Employee* emp = searchEmployee(id);
    if (emp == nullptr) {
        cout << "Employee with ID " << id << " not found.\n";
        return;
    }
    emp->post = newPost;
    emp->salary -= decrement;
    cout << "Employee demoted successfully!\n";
}

void removeEmployee(int id) {
    if (head == nullptr) {
        cout << "No employees to remove.\n";
        return;
    }

    Employee* temp = head;
    Employee* prev = nullptr;

    if (temp != nullptr && temp->id == id) {
        head = temp->next;  
        delete temp;
        cout << "Employee removed successfully.\n";
        return;
    }

    while (temp != nullptr && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Employee with ID " << id << " not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Employee removed successfully.\n";
}

int main() {
    int choice, id, experience;
    string name, address, post, department;
    double salary, increment, decrement;

    while (true) {
        cout << "\n--- Employee Management System ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees\n";
        cout << "3. Promote Employee\n";
        cout << "4. Demote Employee\n";
        cout << "5. Remove Employee\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID: "; cin >> id;
            cin.ignore(); 
            cout << "Enter Employee Name: "; getline(cin, name);
            cout << "Enter Employee Address: "; getline(cin, address);
            cout << "Enter Employee Post: "; getline(cin, post);
            cout << "Enter Employee Salary: "; cin >> salary;
            cin.ignore();
            cout << "Enter Employee Department: "; getline(cin, department);
            cout << "Enter Employee Experience (years): "; cin >> experience;
            addEmployee(id, name, address, post, salary, department, experience);
            break;
        case 2:
            displayEmployees();
            break;
        case 3:
            cout << "Enter Employee ID to promote: "; cin >> id;
            cin.ignore();
            cout << "Enter new Post: "; getline(cin, post);
            cout << "Enter salary increment: "; cin >> increment;
            promoteEmployee(id, post, increment);
            break;
        case 4:
            cout << "Enter Employee ID to demote: "; cin >> id;
            cin.ignore();
            cout << "Enter new Post: "; getline(cin, post);
            cout << "Enter salary decrement: "; cin >> decrement;
            demoteEmployee(id, post, decrement);
            break;
        case 5:
            cout << "Enter Employee ID to remove: "; cin >> id;
            removeEmployee(id);
            break;
        case 6:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
