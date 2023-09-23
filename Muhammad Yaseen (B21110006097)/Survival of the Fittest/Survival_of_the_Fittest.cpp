#include <iostream>
#include<fstream>
using namespace std;
struct Node {
    int val;
    Node* next;
    Node* prev;
};
Node* head = NULL;
Node* tail = NULL;
int counter = 0;
float median = 0;
void ADD(int new_val)
{
    Node* new_node = new Node;
    new_node->val = new_val;
    new_node->next = NULL;
    new_node->prev = tail;

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        counter++;
        median = head->val;
        return;
    }
    else {
        Node* curr = head;
        while (curr->next != NULL && curr->val < new_node->val) {//curr ki val greater hogi input se or insert krdi to list onsort rahegi
            curr = curr->next;
        }
        //inserting in head
        //list has only one node
        if (curr == head && curr->val > new_node->val) {//for 1st node inserting
            new_node->next = curr;
            curr->prev = new_node;
            curr = tail;//new addition (issue resolved)
            new_node->prev = NULL;
            head = new_node;
        }
        //inserting in tail
        else if (curr->next == NULL && curr->val < new_node->val) {//(inserting in after last )curr val is less than new node val
            curr->next = new_node;
            new_node->prev = curr;
            new_node->next = NULL;
            tail = new_node;
        }
        //inserting in middle
        //curr->val > new-node->val;
        else {
            new_node->next = curr;
            new_node->prev = curr->prev;
            curr->prev->next = new_node;
            curr->prev = new_node;
        }
        counter++;

        if (counter % 2 == 0) {
            Node* curr = head;
            for (int i = 1; i != (counter) / 2; i++) {//i = 0 to -1 add
                curr = curr->next;
            }
            median = curr->val; //for Eg: 3
            curr = curr->next;  //for Eg: 4
            median = (median + curr->val) / 2; //3+4=7--->is liye / by 2
            //cout << "if" << median << endl;
            return;

        }
        else {
            Node* curr = head;
            for (int i = 1; i != (counter + 1) / 2; i++) { //i = 0 se shurur krnge to counter me +1 nh krnge
                curr = curr->next;
            }
            median = curr->val;
            //cout << "if" << median << endl;
            return;
        }
    }
}

void print() {
    Node* curr = head;
    if (curr == NULL) {
        cout << "there is no node in the list!" << endl;
        return;
    }
    cout << "Printing a a list!" << endl;
    while (curr != NULL) {
        cout << curr->val << "<-->";
        curr = curr->next;
    }
    cout << endl;
}

void Reverse() {
    Node* curr = tail;
    //Node* curr = head;
    if (curr == NULL) {
        cout << "there is no node in the list!" << endl;
        return;
    }
    cout << "reversed of a list!" << endl;
    //extra traversing 
    /*
    while (curr->next != NULL) {
        curr = curr->next;
    }
    */
    //main (curr = tail) (extra traversing k baghair nh chal rha )---?sir se pochna h
    //ANS: inserting at head when we have only one node, i was not updating the tail..(issue resolved)
    while (curr != NULL) {
        cout << curr->val << "<-->";
        curr = curr->prev;
    }
}


int main()
{
    // int num, checker = 0;
    // fstream file;
    // file.open("C:/Users/dell/Desktop/DSA(A2)/Survival of the Fittest/Test01.txt");
    // while (checker != -1) {
    //     file >> num;
    //     ADD(num);
    //     cout << "median is:" << median << endl;
    //     checker = file.get();
    // }

    int num;
    ifstream file;
    file.open("D:/YASEEN/yaseen/4th semester/DSA/Assignment#02/Survival of the Fittest/Test01.txt");

    if(file.fail()){ // OR !file.is_open() (both condition same)
        cout<<"File doesn't open! Please check the path"<<endl;
    }
    else{
    while(file.eof() == 0){
        file>>num;
        ADD(num);
        cout << "median is:" << median << endl;
    }
    }




    //cout << tail->val;

//    print();
//    cout << endl;
//    Reverse();

    
}

