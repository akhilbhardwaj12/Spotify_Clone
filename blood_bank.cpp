#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Donor {
    string name;
    string bloodGroup;
    int age;
    string contact;
};

class BloodBank {
    vector<Donor> donors;

public:
    void addDonor() {
        Donor d;
        cout << "Enter donor name: ";
        cin >> d.name;
        cout << "Enter blood group: ";
        cin >> d.bloodGroup;
        cout << "Enter age: ";
        cin >> d.age;
        cout << "Enter contact number: ";
        cin >> d.contact;
        donors.push_back(d);
        cout << "Donor added successfully!\n";
    }

    void displayDonors() {
        cout << "\nList of Donors:\n";
        for (const auto& d : donors) {
            cout << "Name: " << d.name << ", Blood Group: " << d.bloodGroup
                 << ", Age: " << d.age << ", Contact: " << d.contact << "\n";
        }
    }

    void searchDonorByBloodGroup() {
        string bg;
        cout << "Enter blood group to search: ";
        cin >> bg;
        bool found = false;
        for (const auto& d : donors) {
            if (d.bloodGroup == bg) {
                cout << "Name: " << d.name << ", Age: " << d.age << ", Contact: " << d.contact << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No donors found with blood group " << bg << "\n";
        }
    }
};

int main() {
    BloodBank bb;
    int choice;
    do {
        cout << "\nBlood Bank Management System\n";
        cout << "1. Add Donor\n";
        cout << "2. Display Donors\n";
        cout << "3. Search Donor by Blood Group\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bb.addDonor();
            break;
        case 2:
            bb.displayDonors();
            break;
        case 3:
            bb.searchDonorByBloodGroup();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
