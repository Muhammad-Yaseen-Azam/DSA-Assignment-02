// A#02(The Editor).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node
{
    Node *prev;
    int val;
    Node *next;
};
Node *head = NULL;
Node *tail = NULL;
Node *cursor = head;

// void print()
// {
//     if (cursor != NULL )
//     {
//         cout << "The value at cursor's node is: " << cursor->val << endl;
//         return;
//     }
//     else
//     {
//         cout << "There is no node in the list!" << endl;
//         return;
//     }
// }

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

void ADD(int new_val)
{ // inserting and tail
    Node *new_node = new Node;
    new_node->val = new_val;
    new_node->next = NULL;

    if (head == NULL)
    { // list is empty
        head = new_node;
        tail = new_node;
        // cout << "value inserted" << endl;
        printlist();
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
            // cout << "value inserted" << endl;
            printlist();
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
        // cout << "value inserted" << endl;
        printlist();
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
        return;
    }
    else
    {
        Node *curr = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(curr);
        printlist();
        return;
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
        printlist();
        return;
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
    printlist();
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
    printlist();
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
    printlist();
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
        // cout << "value inserted" << endl;
        printlist();
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
            // cout << "value inserted" << endl;
            printlist();
            return;
        }
        // if list contain more than one node(insert at mid)

        // for next pointer
        new_node->next = cursor->next;
        cursor->next = new_node;

        // for prev pointer
        new_node->next->prev = new_node;
        new_node->prev = cursor;
        // cout << "value inserted" << endl;
        printlist();
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
        printlist();
        return;
    }
    Node *curr;
    if (cursor == head && cursor->next != NULL)
    {
        curr = head;
        cursor = cursor->next;
        head = head->next; // or (head = cursor)
        cout << "The cursor value: " << curr->val << " is deleted! and moved 1 step forward at: " << cursor->val << endl;
        free(curr);
        printlist();
        return;
    }
    else if (cursor == tail)
    { // cursor point at last node
        curr = tail;
        cursor = cursor->prev;
        tail = tail->prev;
        cout << "The cursor value: " << curr->val << " is deleted! and moved 1 step forward at: " << cursor->val << endl;
        free(curr);
        printlist();
        return;
    }
    else if (cursor->next != NULL)
    {
        curr = cursor;
        cursor = cursor->next;
        curr->prev->next = cursor;
        cursor->prev = curr->prev;
        cout << "The cursor value: " << curr->val << " is deleted! and moved 1 step forward at: " << cursor->val << endl;
        free(curr);
        printlist();
        return;
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
    printlist();
    return;
}

void UpdateImmediate(int new_val){
    if(head == NULL){
        cout << "There is no node in the list!" << endl;
        return;
    }

    cursor->val = new_val;
    printlist();
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
    // if (cursor == NULL
    if(head == NULL)
    {
        cout << "There is no node in the list!" << endl;
        return;
    }
    else
    {
        cout << "The value at cursor's node is: " << cursor->val << endl;
    }
}

// void printlist()
// {
//     Node *curr = head;
//     if (curr == NULL)
//         cout << "empty" << endl;
//     while (curr != NULL)
//     {
//         cout << curr->val << "->";
//         curr = curr->next;
//     }
//     cout << "NULL" << endl;
// }


int main(){
    int num;
	string end_point;
	int check_next=0;//check after value
	int node_index;
	ifstream file("D:/YASEEN/yaseen/4th semester/DSA/Assignment#02/The Editor/Test02.txt");

	while (check_next != -1) {
		file >> end_point;
		
		if (end_point == "Add") {
			file.get();
			file >> node_index;
			check_next = file.get();
			if (check_next == 10 || check_next == -1) {
				ADD(node_index);
				continue;
			}
			else {
				file >> num;
				insertAtIndex(node_index,num);//(node_index, new_val)
				// cout << "List is: ";
				// printlist();
			}
		}
		else if (end_point == "deleteAtTail") {
			check_next=file.get();
			if (check_next == 10 || check_next==-1) {
			     deleteAtTail();
				//  cout << "List is: ";
				//  printlist();
			     continue;
			}
			else {
				file >> node_index;
				deleteAtIndex(node_index);//node_index
				// cout << "List is: ";
				// printlist();
			}
		}
        else if (end_point=="MoveForward"){
			file.get();
			file >> num;
			MoveForward(num);
		}
		else if (end_point == "MoveBackward") {
			file.get();
			file >> num;
			MoveBackward(num);
		}
		else if (end_point == "AddImmediate") {
			file.get();
			file >> num;
			AddImmediate(num);
			// cout << "List is: ";
			// printlist();
		}
		else if (end_point == "DeleteImmediate") {
			DeleteImmediate();
			// cout << "List is: ";
			// printlist();
		}
		else if (end_point == "Print") print();

		else if (end_point == "Update") {
			file.get();
			file >> node_index;
			file.get();
			file >> num;
			UpdateIndex(node_index, num); //(node_index,new_val)
			// cout << "List is: ";
			// printlist();
		}
		else if (end_point == "UpdateImmediate") {
			file.get();
			file >> num;
			UpdateImmediate(num);
			// cout << "List is: ";
			// printlist();
		}
		else if (end_point == "Shift") {
			file.get();
			file >> node_index;
			ShiftIndex(node_index);//node_index
			// cout << "List is: ";
			// printlist();
		}
		// else if (end_point == "Undo") {
		// 	Undo();
		// 	cout << "List is: ";
		// 	printlist();
		// }
		check_next = file.get();
	}
	file.close();
}