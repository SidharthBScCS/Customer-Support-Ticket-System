# Customer Support Ticket System 

## Problem Statement
The Customer Support Ticket System is a software solution designed to manage
incoming customer tickets using queues, stacks, and linked lists. This system enables
dynamic addition of tickets, prioritizes urgent tickets, supports undo operations, and
processes tickets in a round-robin manner. The lab assignment focuses on implementing these
data structures in C++ or Python to address real-world customer support scenarios and
analyzing their functionality.

## Attributes
- **ticketId** -> Integer,unique identifier for the ticket
- **customername** -> String,name of the customer
- **issueDescription** -> String,details of the issue
- **priority** -> Integer,priority level of the ticket
- **TicketList** -> Singly linked list for storing ticket records
- **UndoStack** -> Stack to store recent ticket
- **PriorityQueue** -> Priority queue to manage urgent tickets
- **CircularQueue** -> Circular queue for round-robin ticket processing
- **BillingHistory** -> Polynomial linked list to represent billing records

## Methods
- **insertTicket()** -> Inserts a new ticket into linked list
- **deleteTicket()** -> Deletes a ticket by ID
- **retrieveTicket()** -> Retrieves ticket details by ID
- **addTicketRecord()** -> Adds a ticket using user input
- **undoTicketOperation()** -> Deletes the most recent ticket
- **processPriorityTickets()** -> Display tickets sorted by urgency
- **processRoundRobinTickets()** -> Demonstrates circular queue processing
- **addBillingTerm()** -> Adds a billing term to the polynomial list
- **compareBillingHistory()** -> Displays billing history in the polynomial list
- **displayChoice()** -> Displays the menu options

## Explanation of the code
The customer support ticket system uses four data structures to manage tickets efficiently.
**SinglyLinkedList** is used to store the ticket records dynamically.It allows fast insertion 
and supports deletion and search by ticket ID.
**Stack** implements undo functionality.Every added ticket is pushed onto the stack,and the last
ticket can be removed using pop().This follows the LIFO principle.
**Priority Queue** handles urgent tickets by sorting them based on priority.Tickets with lower
priority numbers are processed first.
**Circular Queue** manages round-robin ticket processing.It uses modular arithmetic to wrap
around the array,ensuring fair and continuous ticket handling.
**Polynomial Linked List** is used to represent billing history,storing terms with coefficients
and exponents.It supports insertion in sorted order and displays the billing polynomial.

## Time Complexity
- **insertTicket()** -> O(1)
- **deleteTicket()** -> O(n)
- **retrieveTicket()** -> O(n)
- **addTicketRecord()** -> O(1)
- **undoTicketOperation()** -> O(n)
- **processPriorityTickets()** -> O(n)
- **addBillingTerm()** -> O(n)
- **compareBillingHistory()** -> O(n)

## Space Complexity
- Space Complexity -> O(n) overall.

## Learning Outcomes
- Linked List
- Stack
- Queue
- Priority Queue
- Circular Queue for round-robin processing
- Polynomial Linked List
- Menu-driven programming
- Understanding Time and Space complexity
- Real-World application of Customer Ticket Support System

## Code Output
<img width="572" height="601" alt="Screenshot (65)" src="https://github.com/user-attachments/assets/ef9d0685-aa3b-4a59-a98b-aeebea73b8b3" />
<img width="590" height="601" alt="Screenshot (66)" src="https://github.com/user-attachments/assets/cf757380-8860-4b0a-a115-deed27534623" />
<img width="586" height="536" alt="Screenshot (68)" src="https://github.com/user-attachments/assets/748d51ec-7273-4d7b-8cd8-2643ade5cd89" />

## Student Details
**Name** : Sidharth Krishna S
**Roll No** : 2401720003
**Course** : BSc Computer Science
**Semester** : 3rd Semester
**Assignment** : Lab Assignment 2

## GitHub Link
- C++ Code -> https://github.com/SidharthBScCS/Customer-Support-Ticket-System/blob/main/TicketSystem.cpp
