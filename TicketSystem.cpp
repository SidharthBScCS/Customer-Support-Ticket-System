#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

struct Ticket{
    int ticketID;
    string customerName;
    string issueDescription;
    int priority;
    Ticket *next;
};

struct BillingNode{
    int coeff;
    int exp;
    BillingNode *next;
};

class CircularQueue{
    int front;
    int rear;
    int size;
    int *queue;

    public:
        CircularQueue(int s){
            size = s;
            queue = new int[size];
            front = rear = -1;
        }

        void enqueue(int ticketID){
            if((rear+1)%size==front){
                cout << "Circular queue is full" << endl;
                return;
            }
            if(front==-1){
                front = rear = 0;
            }
            else{
                rear = (rear + 1) % size;
            }
            queue[rear] = ticketID;
        }

        void dequeue(){
            if(front==-1){
                cout << "Circular queue is empty" << endl;
                return;
            }
            cout << "Processing Ticket ID: " << queue[front] << endl;
            if(front==rear){
                front = rear = -1;
            }
            else{
                front = (front + 1) % size;
            }
        }

        void display(){
            if(front==-1){
                cout << "Circular Queue is empty" << endl;
                return;
            }
            cout << "Round-Robin Ticket IDs: ";
            int i = front;
            while(true){
                cout << queue[i] << " ";
                if(i==rear){
                    break;
                }
                i = (i + 1) % size;
            }
            cout << endl;
        }
};


class TicketSystem{
    Ticket *head;
    stack<Ticket> undoStack;
    priority_queue<pair<int, string>> priorityQueue;
    CircularQueue roundRobinQueue;
    BillingNode *billingHead;

    public:
        TicketSystem():roundRobinQueue(5){
            head = nullptr;
            billingHead = nullptr;
        }

        void insertTicket(int id,string name,string issue,int priority){
            Ticket *newTicket = new Ticket{id, name, issue, priority, head};
            head = newTicket;
            cout << "Data inserted successfully" << endl;
        }

        void deleteTicket(int id){
            Ticket *temp = head;
            Ticket *prev = nullptr;
            while(temp&&temp->ticketID!=id){
                prev = temp;
                temp = temp->next;
            }
            if(!temp){
                cout << "Ticket not found" << endl;
                return;
            }
            if(!prev){
                head = temp->next;
            }
            else{
                prev->next = temp->next;
                delete temp;
            }
            cout << "Ticket deleted successfully" << endl;
        }

        void retrieveTicket(int id){
            Ticket *temp = head;
            while(temp){
                if(temp->ticketID==id){
                    cout << "Ticket ID: " << temp->ticketID << endl;
                    cout << "Customer Name: " << temp->customerName << endl;
                    cout << "Issue: " << temp->issueDescription << endl;
                    cout << "Priority: " << temp->priority << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Ticket not found" << endl;
        }

        void addTicketRecord(int id,string name,string issue,int priority){
            insertTicket(id, name, issue, priority);
            undoStack.push({id, name, issue, priority, nullptr});
        }

        void undoTicketOperation(){
            if(!undoStack.empty()){
                Ticket last = undoStack.top();
                undoStack.pop();
                deleteTicket(last.ticketID);
                cout << "Undo successfull" << endl;
            }
            else{
                cout << "No ticket to undo" << endl;
            }
        }

        void processPriorityTickets(){
            priorityQueue.push({3, "General Inquiry"});
            priorityQueue.push({2, "Payment Failure"});
            priorityQueue.push({1, "Login Issue"});

            cout << "Processing Priority Tickets" << endl;
            while(!priorityQueue.empty()){
                cout << "Issue: " << priorityQueue.top().second << endl;
                cout << "Priority: " << priorityQueue.top().first << endl;
                priorityQueue.pop();
            }
        }

        void processRoundRobinTickets(){
            roundRobinQueue.enqueue(101);
            roundRobinQueue.enqueue(102);
            roundRobinQueue.enqueue(103);
            roundRobinQueue.display();
            roundRobinQueue.dequeue();
            roundRobinQueue.display();
        }

        void addBillingTerm(int coeff,int exp){
            BillingNode *newNode = new BillingNode{coeff, exp, nullptr};
            if(!billingHead||billingHead->exp<exp){
                newNode->next = billingHead;
                billingHead = newNode;
            }
            else{
                BillingNode *temp = billingHead;
                while(temp->next&&temp->next->exp>exp){
                    temp = temp->next;
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
            }
        }

        void compareBillingHistory(){
            BillingNode *temp = billingHead;
            cout << "Billing" << endl;
            while(temp){
                cout << temp->coeff << " X^ " << temp->exp;
                if(temp->next){
                    cout << " + ";
                }
                temp = temp->next;
            }
            cout << endl;
        }

        void displayChoice(){
            cout << "-------Customer Support Ticket System by SIDHARTH 0003-------" << endl;
            cout << "1.Add ticket" << endl;
            cout << "2.Delete ticket" << endl;
            cout << "3.View ticket" << endl;
            cout << "4.Undo last ticket" << endl;
            cout << "5.Process priority tickets" << endl;
            cout << "6.Round-Robin ticket processing" << endl;
            cout << "7.Adding Billing term" << endl;
            cout << "8.Compare billing history" << endl;
            cout << "9.Exit" << endl;
        }
};


int main(){
    TicketSystem system;
    int choice;
    do{
        system.displayChoice();
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                int id;
                string name;
                string issue;
                int priority;
                cout << "Enter ticket ID: ";
                cin >> id;
                cout << "Enter your name: ";
                cin >> name;
                cout << "Enter your issue: ";
                cin.ignore();
                getline(cin, issue);
                cout << "Enter priority: ";
                cin >> priority;
                system.addTicketRecord(id, name, issue, priority);
                break;
            }

            case 2:{
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                system.deleteTicket(id);
                break;
            }

            case 3:{
                int id;
                cout << "Enter ID to retrieve: ";
                cin >> id;
                system.retrieveTicket(id);
                break;
            }

            case 4:{
                system.undoTicketOperation();
                break;
            }

            case 5:{
                system.processPriorityTickets();
                break;
            }

            case 6:{
                system.processRoundRobinTickets();
                break;
            }

            case 7:{
                int coeff, exp;
                cout << "Enter coefficient: ";
                cin >> coeff;
                cout << "Enter exponent: ";
                cin >> exp;
                system.addBillingTerm(coeff, exp);
                break;
            }

            case 8:{
                system.compareBillingHistory();
                break;
            }

            case 9:{
                cout << "Exited..." << endl;
                break;
            }

            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 9);
}