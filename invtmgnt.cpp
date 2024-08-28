#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Product {
    string name;
    string brand;
    string price;
    string quantity;
    string description;

    Product(string n, string b, string p, string q, string d) : name(n), brand(b), price(p), quantity(q), description(d) {};
};

struct Inventory {
    vector<Product*> items;

    Inventory() {};
};

void addProduct(Inventory* inventory, Product* product) {
    inventory -> items.push_back(product);
}

bool compareItems(Product* a, Product* b) {
    return a -> name < b -> name;
}

void printInventory(Inventory* inventory) {
    sort(inventory -> items.begin(), inventory -> items.end(), compareItems);
    for (int i = 0; i < inventory -> items.size(); i++) {
        cout << endl;
        cout << "\t" << "Item: " << inventory -> items[i] -> name << endl;
        cout << "\t" << "Brand: " << inventory -> items[i] -> brand << endl;
        cout << "\t" << "Stock: " << inventory -> items[i] -> quantity << endl;
        cout << "\t" << "Price: " << inventory -> items[i] -> price << endl;
        cout << "\t" << "Description: " << inventory -> items[i] -> description << endl;
        cout << endl;
    }
}

int main(void) {
    Inventory* items = new Inventory();
    Product* item1 = new Product("Landmine", "Yo Mama", "$199", "24", "Land on them mines and they'll explode!");
    Product* item2 = new Product("Banana Peel", "Monkeh", "$5", "92", "Place them and pray someone slips on it..");
    Product* item3 = new Product("Brown Stick", "Tree", "$1", "Infinite", "What's brown and sticky? A stick. You can pluck them from a tree and poke things with it.");
    Product* item4 = new Product("Dog", "Blackweb", "$523", "1", "I wonder what's so special about this dog.. ( ͠° ͟ʖ ͡°)");
    Product* item5 = new Product("Banana", "Monkeh", "$10", "891", "A banana covered by banana peel. Be aware of consuming it around monkeys..");
    Product* item6 = new Product("Reverse Card", "Uno", "$25,000", "7", "Why does it cost so much you may ask? Maybe because you can reverse things with it?..");

    addProduct(items, item1);
    addProduct(items, item2);
    addProduct(items, item3);
    addProduct(items, item4);
    addProduct(items, item5);
    addProduct(items, item6);

    printInventory(items);

    delete items;
    delete item1;
    delete item2;
    delete item3;
    delete item4;
    delete item5;
    delete item6;

    return 0;
}