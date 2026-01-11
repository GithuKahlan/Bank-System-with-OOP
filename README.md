# Bank Management System (C++)

## Overview
This is a console-based Bank Management System built in C++ as an academic and learning project.  
The system simulates core banking operations such as client management, secure transactions, user authentication, and currency exchange.


---

## Features

### Users
- *User Authentication*
  - Login with username and password
  - Passwords are encrypted before being stored in files
  - Unauthorized access to files does not reveal real passwords
- *Login Register*
  - Logs user login activity
  - Stores date and time of each login for auditing purposes

### Client Management
- Show client list
- Add new client
- Update client information
- Find client by account details

### Transactions
- Deposit funds
- Withdraw funds
- Transfer money between accounts
- View total balances
- Transfer logs to track transaction history

### Admin Functions
- List users
- Add new users
- Update user information
- Delete users
- Find users

### Currency Exchange Module
- List available currencies
- Find currency by code
- Update exchange rates
- Currency calculator for conversions

---

## Technical Details

### Object-Oriented Design
- Uses OOP principles (classes, encapsulation)
- Modular and structured program design

### Security
- Basic password encryption and decryption
- Prevents plain-text password exposure in stored files

### File Handling
- Persistent data storage using files
- Read/write operations for users, clients, and logs

### Other
- Menu-driven console application
- Date and time handling for logging

---

## Purpose
This project was created to practice C++ programming, object-oriented principles, file handling, and basic security concepts in a real-world–like application.

---

## Setup Instructions

### NOTE: MSVC (Microsoft Visual C++) compiler was used for the project

1. Clone the repository or download the ZIP file.
2. Open the project inside visual studio 
3. Compile and run the project inside visual studio

## Alternate Method

1. Download the ZIP file
2. Run the .exe file

### NOTE: The .exe file should be inside the main directoy in order for it to access the necessery files

### Use username: User20 and password: 2222 to access the application
