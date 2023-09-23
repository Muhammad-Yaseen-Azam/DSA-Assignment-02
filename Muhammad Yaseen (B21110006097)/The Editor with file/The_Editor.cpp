// A#02(The Editor).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    Node *prev;
    int val;
    Node *next;
};
Node *head = NULL;
Node *tail = NULL;
Node *cursor;

void ADD(int new_val)
{ // inserting and tail
    Node *new_node = new Node;
    new_node->val = new_val;
    new_node->next = NULL;

    if (head == NULL)
    { // list is empty
        head = new_node;
        tail = new_node;
        cout << "value inserted" << endl;
        return;
    }
    // cout << "okay";
    while (head != NULL)
    { // if list contan only one node or more than one node
        if (head->next == NULL)
        { // list contain only one node
            head->next = new_node;
            new_node->prev = head;
            tail = new_node;
            cout << "value inserted" << endl;
            return;
        }
        // pochna h sir se
        //  if (tail->next == NULL) {//last element arrived
        //      tail->next = new_node;
        //      new_node->prev = tail;
        //      tail = new_node;
        //      return;
        //  }
        //  OR
        Node *curr = head;
        while (curr->next != NULL)
        { // last element of list then stop
            curr = curr->next;
        }
        curr->next = new_node;
        new_node->prev = curr;
        tail = new_node;
        cout << "value inserted" << endl;
        return;
    }
}
void DELETE()
{
    if (tail == NULL)
    {
        cout << "there is no node in the list!";
        return;
    }
    else if (head->next == NULL)
    {
        free(head);
    }
    else
    {
        Node *curr = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(curr);
    }
}

void insertAtIndex(int node_index, int new_val)
{
    int curr_pos = 0;
    Node *curr = head;
    while (curr_pos != node_index - 1)
    {
        curr = curr->next;
        curr_pos++;
    }
    if (curr != NULL)
    {
        Node *new_node = new Node;
        new_node->val = new_val;

        // for next ptr
        new_node->next = curr->next;
        curr->next = new_node;

        // for prev ptr
        new_node->next->prev = new_node;
        new_node->prev = curr;
    }
    else
    {
        cout << "Invalid Position!" << endl;
    }
}

void deleteATHead()
{
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    Node *curr = head;
    head = head->next;
    if (head == NULL)
    {
        tail = NULL;
    }
    else
    {
        head->prev = NULL;
    }
    free(curr);
    return;
}

void deleteAtTail()
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *curr = tail;
    tail = tail->prev;

    tail->next = NULL;

    free(curr);
    return;
}

void deleteAtIndex(int node_index)
{
    int curr_pos = 0;
    if (node_index == 0)
    {
        deleteATHead();
        return;
    }

    Node *curr = head;
    while (curr_pos != node_index)
    { // when curr position or node index barabar to loop stop
        curr = curr->next;
        curr_pos++;
        if (curr == tail)
        { // mean curr is at last node
            deleteAtTail();
            return;
        }
    }
    // curr at node_index
    // curr us node ko point kr rha h jo delete krni h
    curr->next->prev = curr->prev; //(curr(toDelete) node k next node ka prev ptr ko (toDelete) node k previous node par point kia h)
    curr->prev->next = curr->next; // curr(toDelete) node k prev node ka next ptr ko (toDelete) node k next node par point kia h
    free(curr);                    // delete curr
    return;
}

void MoveForward(int steps)
{
    cursor = head;
    // cursor->next  != NULL krnga to cursor NULL nh hoga last node par stop ho jayega
    // Agr step size 10 hua or list me nodes 7 hain to to ab cursor NULL ko point krna chahiye lakin agr me cursor->next == NULL condition
    // use krnga to last element ko exceed nh krega ussi ko printlist krde 10 move krne k baad bhi
    for (int i = 1; i <= steps && cursor != NULL; i++)
    {

        cursor = cursor->next; // Move 'cursor' to the next node in the list
    }

    if (cursor != NULL) // tail ka next NULL h
    {
        cout << "Moved forward " << steps << " steps. cursor value: " << cursor->val << endl;
    }

    else
    {
        cout << "Reached the end of the list." << endl;
    }
}

void MoveBackward(int steps)
{
    for (int i = 1; i <= steps && cursor != NULL; i++)
    {
        cursor = cursor->prev; // cursor ko pechy move
    }
    if (cursor != NULL) // head ka prev NULL hota h
    {
        cout << "Moved backward " << steps << " steps. cursor value: " << cursor->val << endl;
    }
    else
    {
        cout << "Reached the end of the list." << endl;
    }
}

void AddImmediate(int new_val)
{ // copy fron ADD function

    Node *new_node = new Node;
    new_node->val = new_val;
    new_node->next = NULL;

    if (cursor == NULL)
    { // list is empty
        head = new_node;
        tail = new_node;
        cursor = new_node;
        cout << "value inserted" << endl;
        return;
    }
    // cout << "okay";

    while (cursor != NULL)
    { // if list contan only one node or more than one node
        if (cursor->next == NULL)
        { // list contain only one node or cursor points to the last node
            cursor->next = new_node;
            new_node->prev = cursor;
            tail = new_node;
            cout << "value inserted" << endl;
            return;
        }
        // if list contain more than one node(insert at mid)

        // for next pointer
        new_node->next = cursor->next;
        cursor->next = new_node;

        // for prev pointer
        new_node->next->prev = new_node;
        new_node->prev = cursor;
        cout << "value inserted" << endl;
        return;
    }
}

void DeleteImmediate()
{
    if (cursor == NULL)
    {
        cout << "There is no node in the List!" << endl;
        return;
    }
    else if (cursor == head && cursor->next == NULL)
    { // cursor at head and list contain only one node(head)
        cout << "The cursor value: " << cursor->val << " is deleted! and cursor moved to NULL" << endl;
        free(cursor);
    }
    Node *curr;
    if (cursor == head && cursor->next != NULL)
    {
        curr = head;
        cursor = cursor->next;
        head = head->next; // or (head = cursor)
        cout << "The cursor value: " << curr->val << " is deleted! and moved 1 step forward at: " << cursor->val << endl;
        free(curr);
    }
    else if (cursor == tail)
    { // cursor point at last node
        curr = tail;
        cursor = cursor->prev;
        tail = tail->prev;
        cout << "The cursor value: " << curr->val << " is deleted! and moved 1 step forward at: " << cursor->val << endl;
        free(curr);
    }
    else if (cursor->next != NULL)
    {
        curr = cursor;
        cursor = cursor->next;
        curr->prev->next = cursor;
        cursor->prev = curr->prev;
        cout << "The cursor value: " << curr->val << " is deleted! and moved 1 step forward at: " << cursor->val << endl;
        free(curr);
    }
}

void UpdateIndex(int node_index, int new_val)
{
    if (head == NULL)
    {
        cout << "There is no node in the list!" << endl;
        return;
    }

    int curr_pos = 0;
    Node *curr = head;

    while (curr_pos != node_index)
    {
        curr = curr->next;
        curr_pos++;
    }
    curr->val = new_val;
    return;
}

void UpdateImmediate(int new_val){
    if(head == NULL){
        cout << "There is no node in the list!" << endl;
        return;
    }

    cursor->val = new_val;
    return;    
}

void ShiftIndex(int node_index){
    if (head == NULL){
        cout << "There is no node in the list!" << endl;
        return;
    }
    Node *curr = head;
    int curr_pos = 0;
    while(curr_pos != node_index)
    {
        curr = curr->next;
        curr_pos++;
    }
    int swap;
    swap = cursor->val;
    cursor->val = curr->val;
    curr->val =swap;
    return;

}


void print()
{
    if (cursor == NULL)
    {
        cout << "There is no node in the list!" << endl;
        return;
    }
    else
    {
        cout << "The value at cursor's node is: " << cursor->val << endl;
    }
}

void printlist()
{
    Node *curr = head;
    if (curr == NULL)
        cout << "empty" << endl;
    while (curr != NULL)
    {
        cout << curr->val << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    print();
    // DELETE();
    AddImmediate(23);
    printlist();
    // DeleteImmediate();
    AddImmediate(97);
    printlist();
    // // deleteAtIndex(0);
    ADD(1);
    ADD(2);
    ADD(3);
    ADD(4);
    // // deleteAtIndex(0);
    ADD(5);
    ADD(6);
    print();
    ADD(7);
    AddImmediate(78);
    ADD(8);
    ADD(9);
    AddImmediate(63);
    ADD(10);
    ADD(11);
    MoveForward(14);
    AddImmediate(103);
    print();
    printlist();
    MoveBackward(14);
    print();
    printlist();
    DeleteImmediate();
    MoveForward(14);
    DeleteImmediate();
    printlist();
    print();
    cout << cursor->val << endl;
    ;
    cout << "hello" << endl;
    MoveBackward(8);
    // cout<<"hello"<<endl;
    cout << cursor->val << endl;
    ;
    DeleteImmediate();
    cout << cursor->val << endl;
    print();

    cout << endl;
    printlist();
    cout << endl;

    UpdateIndex(13,18);// (index, val)
    printlist();
    
    cout<<endl;
    UpdateImmediate(77);
    printlist();

    cout<<cursor->val<<endl;
    cout<<"-----------"<<endl;
    ShiftIndex(3);
    printlist();
    cout<<"-----------"<<endl;
    cout<<cursor->val<<endl;

    // // deleteAtIndex(3);
    // printlist();
    // // deleteAtIndex(6);
    // printlist();
    // MoveBackward(2);

    // insertAtAnyPosition(4, 14);
    // printlist();
    // // cout<<"okay";
    // DELETE();
    // printlist();
    // deleteAtAnyPosition(4);
    // printlist();
    // curr = head;
    // while (curr->next != NULL) {
    //     cout << curr->val << "-->";
    // }

    /* DELETE();
     cout << "hello" << endl;


     Node* curr = head;
     while (curr->next != NULL) {
         cout << curr->val << "-->";
     }*/
}
