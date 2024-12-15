# Customer Management

## Description
This C++ program implements a customer management system using a linked list to store customer records. 
The program allows users to add, delete, and display customer information. Each customer has the following attributes:

- Number (Unique Identifier)
- Name
- Age
- VIP Status (Boolean: 1 for VIP, 0 for non-VIP)

The linked list dynamically manages the customers, ensuring efficient insertion and deletion operations.

## Features

1. Add Customer: Add a new customer by entering their details (number, name, age, and VIP status).
2. Delete Customer: Delete a customer based on their unique number.
3. Display Customers: View the list of all customers along with their details.
4. Exit: Quit the program.

## Usage

### Prerequisites
- C++ Compiler (e.g., g++, clang++)

### Compilation

To compile the program, run:

```bash
g++ customer_management.cpp -o customer_management
```

### Running the Program

Execute the compiled program with:

```bash
./customer_management
```

### Sample Menu

```
1. Add customer
2. Delete customer
3. Display customers
4. Exit
Enter choice:
```

### Example Workflow

1. Add Customer:
    ```
    customer number: 101
    enter name of customer: Alice
    enter age of customer: 30
    enter 1 if vip customer else enter 0: 1
    ```

2. Display Customers:
    ```
    Number: 101 Name: Alice Age: 30 VIP status: 1
    ```

3. Delete Customer:
    ```
    Enter number of customer to delete: 101
    Customer with num 101 deleted
    ```

## Code Structure

- `node` Class: Represents a customer node containing customer details and a pointer to the next node.
- `LinkedList` Class: Implements the linked list with methods to add, delete, and display customers.
- `main` Function: Provides a menu-driven interface for the user.

## Methods

### `addCus()`
Prompts the user to enter customer details and adds a new customer node to the linked list.

### `delCus(int num)`
Deletes a customer node based on the provided customer number.

### `print()`
Displays the details of all customers in the linked list.

## Important Notes

- Edge Cases Handled:
  - Deleting from an empty list.
  - Attempting to delete a non-existent customer.
  - Deleting the head node.



