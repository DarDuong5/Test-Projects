#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    string number;
    string firstname;
    string lastname;
    string address;

    Person(string num, string firstn, string lastn, string address) : number(num),
    firstname(firstn), lastname(lastn), address(address) {};
};

struct addressBook {
    vector<Person*> contacts;

    addressBook() {};
};

void addPerson(addressBook* book, Person* person) {
    book -> contacts.push_back(person);
}

bool comparePeople(Person* a, Person* b) {
    if (a -> firstname == b -> firstname) {
        a -> lastname < b -> lastname;
    }
    return a -> firstname < b -> firstname;
}

void printAddressBook(addressBook* book) {
    sort(book -> contacts.begin(), book -> contacts.end(), comparePeople);
    for (int i = 0; i < book -> contacts.size(); i++) {
        cout << "\n";
        cout << book -> contacts[i] -> firstname << " " << book -> contacts[i] -> lastname << endl;
        cout << "\t" << book -> contacts[i] -> number << endl;
        cout << "\t" << book -> contacts[i] -> address << endl;
        cout << "\n";
    }
}

int main(void) {
    addressBook* book = new addressBook();
    Person* client1 = new Person("123-456-7890", "Pepe", "Pig", "6969 Meme St. Memeland");
    Person* client2 = new Person("098-765-4321", "Big", "Bob", "1234 Bob St. Bob");
    Person* client3 = new Person("6969-911-8888", "Hehe", "Haw", "3921 Clash Royale");
    Person* client4 = new Person("6969-911-8888", "Big", "Boy", "3921 Boy St. Royale");
    Person* client5 = new Person("908-357-0368", "Darin", "Duong", "N/A");

    addPerson(book, client1);
    addPerson(book, client2);
    addPerson(book, client3);
    addPerson(book, client4);
    addPerson(book, client5);

    printAddressBook(book);

    delete book;
    delete client1;
    delete client2;
    delete client3;
    delete client4;
    delete client5;

    return 0;
}