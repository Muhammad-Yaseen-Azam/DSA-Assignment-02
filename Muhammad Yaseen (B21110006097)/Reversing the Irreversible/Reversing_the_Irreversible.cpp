// A#02(Reversing the Irreversible).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int ID;
    int amount;
    Node *next;
};
Node *head = NULL;

void ADD(int new_ID, int new_amount)
{
    Node *new_node = new Node;
    new_node->ID = new_ID;
    new_node->amount = new_amount;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new_node;
        new_node->next = NULL;
    }
}
void DELETE(int toDelete_ID)
{
    if (head == NULL)
    {
        cout << "There is no node in the list!";
        return;
    }

    // is node ko me else me bhi define kr sakta tha phr uske liye mujhe curr ki jaga head use krna parta usse new pointer jaga nh leta extra
    Node *curr = head; // is par grip h
    // node me if me bhi bna sakta tha bahar isliye banya nechy use hoga else me
    if (curr->ID == toDelete_ID)
    {
        head = head->next;
        free(curr);
        return;
    }
    else
    {
        while (curr != NULL)
        {
            if (curr->ID == toDelete_ID)
            {
                Node *prev = head;
                while (prev->next != curr)
                {
                    prev = prev->next;
                }
                prev->next = curr->next;
                free(curr);
                return;
            }
            curr = curr->next;
        }
    }
}

void DELETE_Amount(int delete_amount)
{
    if (head == NULL)
    {
        cout << "There is no node in the list!";
        return;
    }

    // is node ko me else me bhi define kr sakta tha phr uske liye mujhe curr ki jaga head use krna parta usse new pointer jaga nh leta extra
    Node *curr = head; // is par grip h
    // node me if me bhi bna sakta tha bahar isliye banya nechy use hoga else me
    if (curr->amount == delete_amount)
    {
        curr->amount = NULL; // amount deleted
        return;
    }
    else
    {
        while (curr != NULL)
        {
            if (curr->amount == delete_amount)
            {
                curr->amount = NULL;
                return;
            }
            curr = curr->next;
        }
    }
}

void print()
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->ID << ",";
        cout << curr->amount << endl;
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    // ADD(2, 1000);
    // ADD(3, 20000);
    // ADD(4, 230000);
    // ADD(5, 534234);
    // ADD(6, 1234214);
    // ADD(7, 431431);
    // ADD(8, 431424343);
    // ADD(9, 4398578);
    // print();

    // DELETE_Amount(230000);
    // DELETE_Amount(431431);

    // // DELETE(4);
    // // DELETE(6);
    // print();

    int numberOfTransactions = 0;
    int numberOfFraudulentTransactions = 0;
    float ID;
    int amount;

    ifstream file("D:/YASEEN/yaseen/4th semester/DSA/Assignment#02/Reversing the Irreversible/Test02.txt");
    if(file.is_open())
    {
        file >> numberOfTransactions;
        file >> numberOfFraudulentTransactions;

        for (int i = 0; i < numberOfTransactions; i++)
        {
            file >> ID;
            file.ignore();
            file >> amount;
            ADD(ID, amount);
        }
        for (int i = 0; i < numberOfFraudulentTransactions; i++)
        {
            file >> ID;
            DELETE(ID);
        }
        print();
    }
    else{
        cout<<"File doesn't open! Please check the path"<<endl;
    }
    

    return 0;
}
