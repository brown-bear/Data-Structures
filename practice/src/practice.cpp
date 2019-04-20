//
//  simple_list.cpp
//
//  Created by Mikhail Auguston,
//  last updated 9/7/16.
//----------------------------------

#include <iostream>
using namespace std;

struct node
{   int value;
    node * next;
};

struct list{
    int size;
    node * head;
};

void initialize(list &s){
    s.size  = 0;
    s.head  = NULL;
}

// add new element at the beginning
void push(list &l, int val){
    node * elt      = new node;
    elt -> next     = l.head;
    elt -> value    = val;
    l.head          = elt;
    l.size ++;
    return;
}

// remove the first element and return its value
int pop(list &l){
    if (l.size == 0)
    {	cout << "delete: list is empty\n";
        return 0; }
    else
    { 	int res     = l.head -> value;
        node * t    = l.head -> next;
        delete l.head;  					// Deleted Node
        l.head      = t; 					// Copy node back to have node*head pointing at int value 0;
        l.size --;
        return(res); }
}

void display(list &l){
    if (l.size == 0)
    {	cout << "display: list is empty\n"; }
    else {  for (node * p = l.head; p ; p = p -> next)
                cout << p -> value << ' ';
            cout << endl;
    }
    return;
}

int main(){

    list my_list;

    initialize(my_list);
    for(int i = 0; i < 5; i++){
        push(my_list, i * 2);				// Creates list of (0, 2, 4, 6, 8)
    }
    display(my_list);
    int work	= pop(my_list);
    cout<< "first element of list was: " << work << endl;
    display(my_list);
    return 0;
}
