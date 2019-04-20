// binary_tree.cpp
#include <iostream>
#include <cstdlib>		//for rand() use
using namespace std;

#include "binary_tree.h"
//------------------------------
void f(btree x){
    cout<< "inside f() print tree x\n";
    x.print();
}
//------------------------------

int main(){
	btree a;
	
	//create a random tree
	for(int i=0; i< 12; i++){
        // insert random key and random data
		a.insert(rand()%100, rand()%100);
	};
	
	a.print();
	
	// perform search
	int goal;
	cout<< "Enter a key as search goal: ";
	cin >> goal;
	cout<< "search for "<< goal;
	if(a.search(goal) != -1)	cout<< " succeeds\n";
	else				cout<< " fails\n";
	
	// call a function (copy constructor deployed)
	cout<< "calling f(a)\n";
	f(a);
	cout<< "print a after calling f()\n";
	a.print();
	
	a.print_vis();
	// delete an item
	cout<< "Enter a key to delete: ";
	cin >> goal;
	cout<< "deleting item with a key "<< goal;
	a.delete_item(goal);
	cout<< ", the result is:\n";
	a.print();
	a.print_vis();
	
	return 0;
}
