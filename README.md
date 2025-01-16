# WhatsApp-like Application Documentation

## Overview
This C++ program simulates a WhatsApp-like application where users can create accounts, add contacts, search contacts, delete contacts, update contacts, and chat with other users. The program utilizes various data structures such as linked lists, hash tables, and stacks to manage contacts and chat history.

## File Structure
- **main.cpp**: Contains the main function and implementation of the WhatsApp-like application.
- **Singlylist.h**: Header file containing the implementation of a singly linked list for managing contacts.
- **Hashtable.h**: Header file containing the implementation of a hash table for efficient searching of contacts.
- **stack.h**: Header file containing the implementation of a stack for managing recent chat history.

## Features
1. **Account Management**:
   - Users can create accounts or log in with existing usernames and numbers.
   - Account details are stored in a file named "All Accounts.txt".

2. **Contact Management**:
   - Users can add, delete, update, and display saved contacts.
   - Contact details are stored in a file named "<username>Contacts.txt".
   - Contacts are managed using a linked list data structure.

3. **Search Contacts**:
   - Users can search for contacts by name.
   - Contacts are efficiently searched using a hash table data structure.

4. **Chat Functionality**:
   - Users can chat with other users.
   - Chat messages are stored in separate files for each chat session.
   - Recent chat history is maintained using a stack data structure.

## Usage
1. **Creating an Account**:
   - Run the program and select the option to create an account.
   - Enter a unique username and number when prompted.

2. **Logging In**:
   - Run the program and select the option to log in.
   - Enter the username and number associated with your account.

3. **Adding Contacts**:
   - After logging in, select the option to add contacts.
   - Enter the name and number of the contact you wish to add.

4. **Searching Contacts**:
   - Select the option to search contacts and enter the name
