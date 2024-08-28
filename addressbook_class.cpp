#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
    private:
        string first_name;
        char middle_initial;
        string last_name;

    public:

        Person(string first, char middle, string last) : first_name(first), middle_initial(middle), last_name(last) {}

        void printPerson() {
            cout << first_name << ", " << middle_initial << "., " << last_name << ": " << endl;
        }
};

class AddressBook : public Person {
    private:
        int birth_year;
        string address;
        string phone_number;

    public:
        AddressBook(string first, char middle, string last, int b, string a, string p) : Person(first, middle, last), birth_year(b), address(a), phone_number(p) {
            cout << "\n" << "Client recorded!" << "\n" << endl;
        }

        ~AddressBook() {
            cout << "Client erased!" << "\n" << endl;
        }

        void printAddressBook() {
            cout << "\t" << birth_year << "\n";
            cout << "\t" << address << "\n";
            cout << "\t" << phone_number << "\n" << endl;
        }
};

int main(void) {
    AddressBook* client1 = new AddressBook("Papi", 'J', "Choola", 2069, "1234, Bane St., Houstan Texas, 69696", "123-456-7890");
    client1->printPerson();
    client1->printAddressBook();
    delete client1;

    return 0;
}