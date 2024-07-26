
# Event Management System

**Event Management System** is a command-line application built in C++ that demonstrates the use of Object-Oriented Programming principles. The system allows customers to book events, assign employees to these events, and enables an admin to manage employee details. This project highlights concepts such as classes, inheritance, file handling, and basic user interaction.

## Project Overview

The Event Management System is designed to handle events such as weddings, birthdays, and corporate functions. Customers can book events, and the system assigns employees to manage these events based on their availability. Admins can manage employee details and view employee information.

## Major Components

1. **Classes**
   - **`Employee`**: Manages employee details and operations.
   - **`Events`**: Handles event information and pricing.
   - **`Customer`**: Manages customer details and their associated events.

2. **Functions**
   - **`Employee`**: Includes functions for setting and getting employee details, assigning employees to events, and checking for available supervisors and workers.
   - **`Events`**: Includes functions for setting event details, calculating total price, and checking event dates.
   - **`Customer`**: Includes functions for setting customer details, assigning employees to events, and writing customer information to a file.

3. **Main Program**: Provides a menu for customers and admins to interact with the system, including event booking and employee management.

## Code Explanation

### `Employee` Class

- **Data Members**:
  - `id`: Unique identifier for each employee.
  - `name`, `designation`, `salary`, `contact`: Details about the employee.
  - `events_managed`: Counter for the number of events managed by the employee.

- **Key Methods**:
  - `setname()`, `setdes()`, `setsalary()`, `setcontact()`: Functions to set employee details.
  - `getname()`, `getdes()`, `getsalary()`, `getcontact()`: Functions to retrieve employee details.
  - `checksupervisor()`, `checkworker()`: Functions to find available supervisors and workers.

### `Events` Class

- **Data Members**:
  - `EventID`, `type`, `location`, `date`: Details of the event.
  - `total_price`, `advance`, `balance`: Financial details of the event.

- **Key Methods**:
  - `setEventID()`, `setType()`, `setLocation()`, `setDate()`: Functions to set event details.
  - `setTotalPrice()`, `setAdvance()`, `setBalance()`: Functions to calculate pricing.
  - `checkDate()`, `MatchDate()`: Functions to validate and match event dates.

### `Customer` Class

- **Data Members**:
  - `custID`, `name`, `contact`, `advpaid`: Details of the customer.
  - `assigned[]`: Array of pointers to assigned employees.

- **Key Methods**:
  - `setName()`, `setContact()`: Functions to set customer details.
  - `addemployee()`: Function to assign employees to a customer’s event.
  - `operator <()`: Overloaded operator to display customer event details.
  - `writetxt()`: Function to write customer and event details to a file.

### `main()` Function

- Provides the main user interface for the application.
- Allows customers to book events and admins to manage employee details.
- Uses a menu-driven approach to interact with users and handle various operations.

## Usage

1. **Customer**:
   - Enter your name and contact number.
   - Choose the event date and type.
   - Pay the advance amount.
   - View the details of your event and employees assigned.

2. **Admin**:
   - Enter the admin password.
   - Change employee details (name, designation, salary, contact).
   - View employee details.

## Known Issues

- **Date Validation**: The date validation logic assumes a static year (2023) and may need updates for future use.
- **Input Handling**: Limited error handling for user input; unexpected inputs may cause issues.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
