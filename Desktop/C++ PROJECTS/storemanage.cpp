#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

struct Customer {
    string name;
    string address;
};

struct Sale {
    int productId;
    int quantity;
};

vector<Product> products;
vector<Customer> customers;
vector<Sale> sales;

void addProduct() {
    Product product;
    cout << "Enter product name: ";
    cin >> product.name;
    cout << "Enter product price: ";
    cin >> product.price;
    cout << "Enter product quantity: ";
    cin >> product.quantity;
    products.push_back(product);
    cout << "Product added successfully.\n";
}

void addCustomer() {
    Customer customer;
    cout << "Enter customer name: ";
    cin >> customer.name;
    cout << "Enter customer address: ";
    cin >> customer.address;
    customers.push_back(customer);
    cout << "Customer added successfully.\n";
}

void makeSale() {
    int customerId, productId, quantity;
    cout << "Enter customer ID: ";
    cin >> customerId;
    cout << "Enter product ID: ";
    cin >> productId;
    cout << "Enter quantity: ";
    cin >> quantity;

    // Check if customer and product exist
    if (customerId >= 0 && customerId < customers.size() && productId >= 0 && productId < products.size()) {
        // Check if product has sufficient quantity
        if (products[productId].quantity >= quantity) {
            Sale sale;
            sale.productId = productId;
            sale.quantity = quantity;
            sales.push_back(sale);

            products[productId].quantity -= quantity;
            cout << "Sale made successfully.\n";
        } else {
            cout << "Insufficient product quantity.\n";
        }
    } else {
        cout << "Invalid customer or product ID.\n";
    }
}

// ... (other functions for displaying products, customers, sales, etc.)

int main() {
    while (true) {
        cout << "1. Add product\n";
        cout << "2. Add customer\n";
        cout << "3. Make sale\n";
        cout << "4. Display products\n";
        cout << "5. Display customers\n";
        cout << "6. Display sales\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            // ... (case statements for each function)
        }
    }
}
