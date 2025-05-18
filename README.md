# Contact Management System

The **Contact Management System** is a console-based program that allows users to manage a database of contact information using a hash table. The program can **insert**, **search**, and **delete** contact entries based on a person's name. The data is stored in a hash table to provide efficient access and retrieval.

## Features

- **Insert Data**: Add new contacts to the system with name, primary contact, secondary contact, and address.
- **Search Data**: Find a contact's information by name.
- **Delete Data**: Remove a contact's information from the database using their name.
- **Hashing Mechanism**: Utilizes a hashing function to efficiently map names to hash table indices.

## Data Structure

- The system uses a **hash table** with **separate chaining** for collision resolution. Each index in the table contains a linked list of `Node` elements. Each node holds a contact's information such as name, phone numbers, and address.
- The hash function converts a name into a unique key. The key is then mapped to an index in the hash table.

## Requirements

- C++ compiler (e.g., GCC or MinGW)
- C++ standard libraries
- Input data file (`sample_data.txt`) containing initial contact data.

## Instructions

### How to Run the Program

1. **Clone this repository** to your local machine:
   ```bash
      git clone https://github.com/your-username/contact-management-system.git
2. Prepare the Data File:

   - Create a text file called sample_data.txt with initial data entries in the following format:
      - 1 John 1234567890 9876543210 123 Main St
      - 2 Jane 2345678901 8765432109 456 Oak St
      - 3 Mike 3456789012 7654321098 789 Pine St
     
3. Compile and run the program:

   - For GCC (Linux/MacOS/Windows with MinGW):

      g++ -o contact_management main.cpp
      ./contact_management
   
   - For Visual Studio (Windows):

      - Open the .cpp file, build, and run the project.

4. Using the System:

- The program will prompt you with a menu:

   1: Insert Data

   2: Search Data

   3: Delete Data

   4: Exit

- Enter the corresponding number for the action you want to perform.

- When inserting, you will need to provide a contact's details, and it will be stored in the hash table.

- When searching or deleting, you will need to enter the name of the contact.

## Example:

- Insert Data:

   1. Enter the key of the data entry: 4
   2. Enter the name of the data entry: Alice
   3. Enter the primary contact number: 555-1234
   4. Enter the secondary contact number: 555-5678
   5. Enter the address: 123 Elm St
      
- Search Data:

   Enter the name of the person whose data entry you want to search: Alice
   The data entry you wished to find is located!
   Key = 4
   Name = Alice
   Primary Contact Number = 555-1234
   Secondary Contact Number = 555-5678
   Address = 123 Elm St
   
- Delete Data:

   Enter the name of the person whose data entry you want to delete: Alice
   The data corresponding to the name you entered is successfully deleted from the database!
   
## Code Overveiw

- Key Functions:

**Insert**: Adds a new contact to the hash table by calculating the hash value of the name and using it to determine the index in the table.

**Search**: Looks for a contact by their name. If the name exists, the program displays the associated contact details.

**Delete**: Removes a contact's details from the hash table by name.

**Hashing**: The hash function (hashing_function) generates a key from the contact's name and maps it to an index in the table using mapping_function.

### Example:

Contact Data Format:

The contact information is stored as:

**Key**: A unique identifier for each contact (usually a number).

**Name**: The contact's full name.

**Primary Contact**: The primary phone number.

**Secondary Contact**: An optional secondary phone number.

**Address**: The contact's address.

## Contributing
1. Fork this repository.

2. Create a new branch:
      git checkout -b feature-name

3. Commit your changes:
      git commit -am 'Add new feature'

4. Push to the branch:
      git push origin feature-name
   
5. Open a pull request.

## License
This project is open-source and available under the MIT License.
