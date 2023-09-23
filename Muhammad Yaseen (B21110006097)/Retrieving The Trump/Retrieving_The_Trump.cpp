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
int mid1, mid2, counter = 0;

Node *GetFirstMiddle()
{ // return node ho rhi h
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *GetSecondMiddle()
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = slow->prev;
    return slow;
}

void ADD(int new_val)
{
    Node *new_node = new Node;
    new_node->val = new_val;
    new_node->next = NULL;
    new_node->prev = tail;

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        counter++;
        mid1 = head->val;
        return;
    }

    if (tail != NULL)
    {
        tail->next = new_node;
        new_node->prev = tail;
    }
    tail = new_node;
    counter++;
    if (counter % 2 == 0)
    {
        mid1 = GetFirstMiddle()->val;
        mid2 = GetSecondMiddle()->val;
    }
    else
    {
        mid1 = GetFirstMiddle()->val;
    }
    return;
}

void DELETE()
{
    if (tail == NULL)
    {
        // cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    if (temp->next == NULL)
    {
        free(temp);
        head = NULL;
        tail = NULL;
        mid1 = 0;
        mid2 = 0;
        counter--;
        return;
    }
    Node *curr = tail;
    tail = tail->prev;

    tail->next = NULL;

    free(curr);
    counter--;
    if (counter % 2 == 0)
    {
        mid1 = GetFirstMiddle()->val;
        mid2 = GetSecondMiddle()->val;
    }
    else
    {
        mid1 = GetFirstMiddle()->val;
    }
    return;
}

void getTrump()
{
    if (counter % 2 == 0)
    {
        cout << mid1 << "  ";
        cout << mid2 << endl;
    }
    else
    {
        cout << mid1 << endl;
    }
}

void display()
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << "<-->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    cout << "okkay" << endl;
    int num;
    string end_point;
    ifstream file;
    file.open("D:/YASEEN/yaseen/4th semester/DSA/Assignment#02/Retrieving The Trump/Test01.txt");

    if (file.is_open())
    {
        int num;
        string end_point;
        end_point = file.get();

        while (end_point != "E")
        {
            if (end_point == "A")
            {
                file.seekg(4, ios::cur); // move cursor to 3 char forward from curr position
                file >> num;
                ADD(num);
                file.get();
                cout << end_point << endl;
                cout << num << endl;
            }
            if (end_point == "D")
            {
                DELETE();
                file.seekg(7, ios::cur);
            }
            end_point = file.get();
        }
        getTrump();
    }
    else
    {
        cout << "File doesn't open! Please check the path" << endl;
    }
}
