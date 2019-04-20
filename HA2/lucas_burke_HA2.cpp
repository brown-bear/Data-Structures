//-----------------------------------------
// Lucas Burke
// 27 Nov 2017
// Filename: lucas_burke_HA2.cpp
// OS: macOS High Sierra v10.13.1
//
// Homework 2: This .cpp file runs binary_tree.h against
// multiple tests for empty trees, one-node trees, etc.
// This file also shows a way to improve previous code for delete_tree().
//
//-----------------------------------------


#include <iostream>
#include <cstdlib>		//for rand() use
using namespace std;

#include "lucas_burke_binary_tree.h"
//------------------------------
void f(btree x){
    cout<< "inside f() print tree x\n";
    x.print();
}
//------------------------------

int main(){


	cout<<"//********************** TEST CASE 1: EMPTY TREE **********************\\"<<endl;

	btree a;
	//create a random EMPTY tree
	for(int i=0; i< 0; i++)
	{
        // insert random key and random data
		a.insert(rand()%100, rand()%100);
	};

	a.print();
	cout<<endl;
	a.print_vis();

	// perform search test on empty tree:
	int goal1;
	int goala;
	cout<< "Enter a key as search goal: ";
	cin >> goal1;
	cout<< "search for "<< goal1;
	if(a.search(goal1) != -1)	cout<< " succeeds\n";
	else				cout<< " fails\n";

	cout<<endl;

	// call a function (copy constructor deployed)
	cout<< "calling f(a)\n";
	f(a);
	cout<< "print a after calling f()\n";
	a.print();

	cout<<endl;

	a.print_vis();
	// delete an item
	cout<< "Enter a key to delete: ";
	cin >> goala;
	cout<< "deleting item with a key "<< goala;
	a.delete_item(goala);
	cout<< ", the result is:\n";
	a.print();
	a.print_vis();

	cout<<endl;

	cout<<"Finding the smallest key: "<<a.smallest_key()<<endl;
	cout<<"Finding the largest key: "<<a.largest_key()<<endl;
	cout<<"Finding the average value of data for the tree: "<<a.average_data()<<endl;
	cout<<"Finding the max depth of tree: "<<a.max_depth()<<endl;
	cout<<"Finding the min depth of tree: "<<a.min_depth()<<endl;

	cout<<endl;
	cout<<endl;




	cout<<"//********************** TEST CASE 2: ONE NODE TREE **********************\\"<<endl;

	btree b;

	//create a random tree with ONE node
	for(int i=0; i< 1; i++)
	{
        // insert random key and random data
		b.insert(rand()%100, rand()%100);
	};

	b.print();
	cout<<endl;
	b.print_vis();

	// perform search test on tree with one node:
	int goal2;
	int goalb;
	cout<< "Enter a key as search goal: ";
	cin >> goal2;
	cout<< "search for "<< goal2;
	if(b.search(goal2) != -1)	cout<< " succeeds\n";
	else				cout<< " fails\n";

	cout<<endl;

	// call a function (copy constructor deployed)
	cout<< "calling f(b)\n";
	f(b);
	cout<< "print b after calling f()\n";
	b.print();

	cout<<endl;

	b.print_vis();

// delete an item:
// Pseudo-error:  When deleting key that does not exist, function does not raise error stating key does not exist.
// Recommended Modification in header: if(!tree) return; -->> if(!tree){ cout<<"key does not exist, nothing to delete."<<; return 0;}

	cout<< "Enter a key to delete: ";
	cin >> goalb;
	cout<< "deleting item with a key "<< goalb;
	b.delete_item(goalb);
	cout<< ", the result is:\n";
	b.print();
	cout<<endl;
	b.print_vis();

	cout<<endl;

	cout<<"Finding the smallest key: "<<b.smallest_key()<<endl;
	cout<<"Finding the largest key: "<<b.largest_key()<<endl;
	cout<<"Finding the average value of data for the tree: "<<b.average_data()<<endl;
	cout<<"Finding the max depth of tree: "<<b.max_depth()<<endl;
	cout<<"Finding the min depth of tree: "<<b.min_depth()<<endl;
	cout<<endl;
	cout<<endl;


	cout<<"//********************** TEST CASE 3: TREE WITH RANDOM NODES **********************\\"<<endl;

	btree c;

	//create a random tree with random nodes
	for(int i=0; i< 6; i++)
	{
        // insert random key and random data
		c.insert(rand()%100, rand()%100);
	};

	c.print();
	cout<<endl;
	c.print_vis();

	// perform search test on tree with random nodes:
	int goal3;
	int goalc;
	cout<< "Enter a key as search goal: ";
	cin >> goal3;
	cout<< "search for "<< goal3;
	if(c.search(goal3) != -1)	cout<< " succeeds\n";
	else				cout<< " fails\n";

	cout<<endl;


	// call a function (copy constructor deployed)
	cout<< "calling f(c)\n";
	f(c);
	cout<< "print c after calling f()\n";
	c.print();

	cout<<endl;


	c.print_vis();
	// delete an item
	cout<< "Enter a key to delete: ";
	cin >> goalc;
	cout<< "deleting item with a key "<< goalc;
	c.delete_item(goalc);
	cout<< ", the result is:\n";
	c.print();
	c.print_vis();

	cout<<endl;


	cout<<"Finding the smallest key: "<<c.smallest_key()<<endl;
	cout<<"Finding the largest key: "<<c.largest_key()<<endl;
	cout<<"Finding the average value of data for the tree: "<<c.average_data()<<endl;
	cout<<"Finding the max depth of tree: "<<c.max_depth()<<endl;
	cout<<"Finding the min depth of tree: "<<c.min_depth()<<endl;
	cout<<endl;
	cout<<endl;




	cout<<"//********************** TEST CASE 4: TREE WITH NODES ASCENDING **********************\\"<<endl;

	btree d;

	//create a tree with keys ASCENDING
	for(int i=10; i< 17; i++)
	{
        // insert ascending key and random data
		d.insert(i, rand()%50);
	};

	d.print();
	cout<<endl;
	d.print_vis();

	// perform search test on tree with keys ascending:
	int goal4;
	int goald;
	cout<< "Enter a key as search goal: ";
	cin >> goal4;
	cout<< "search for "<< goal4;
	if(d.search(goal4) != -1)	cout<< " succeeds\n";
	else				cout<< " fails\n";

	cout<<endl;

	// call a function (copy constructor deployed)
	cout<< "calling f(d)\n";
	f(d);
	cout<< "print d after calling f()\n";
	d.print();

	cout<<endl;

	d.print_vis();
	// delete an item
	cout<< "Enter a key to delete: ";
	cin >> goald;
	cout<< "deleting item with a key "<< goald;
	d.delete_item(goald);
	cout<< ", the result is:\n";
	d.print();
	d.print_vis();

	cout<<endl;

	cout<< "Finding the smallest key: "<<d.smallest_key()<<endl;
	cout<<"Finding the largest key: "<<d.largest_key()<<endl;
	cout<<"Finding the average value of data for the tree: "<<d.average_data()<<endl;
	cout<<"Finding the max depth of tree: "<<d.max_depth()<<endl;
	cout<<"Finding the min depth of tree: "<<d.min_depth()<<endl;
	cout<<endl;
	cout<<endl;



	cout<<"//********************** TEST CASE 5: TREE WITH NODES DESCENDING **********************\\"<<endl;

	btree e;

	//create a random tree with keys DESCENDING
	for(int i=400; i>393; i--)
	{
        // insert descending key and random data
		e.insert(i, rand()%100);
	};

	e.print();
	cout<<endl;
	e.print_vis();

	// perform search test on tree with keys descending:
	int goal5;
	int goale;
	cout<< "Enter a key as search goal: ";
	cin >> goal5;
	cout<< "search for "<< goal5;
	if(e.search(goal5) != -1)	cout<< " succeeds\n";
	else				cout<< " fails\n";

	cout<<endl;

	// call a function (copy constructor deployed)
	cout<< "calling f(e)\n";
	f(e);
	cout<< "print e after calling f()\n";
	e.print();

	cout<<endl;

	e.print_vis();
	// delete an item
	cout<< "Enter a key to delete: ";
	cin >> goale;
	cout<< "deleting item with a key "<< goale;
	e.delete_item(goale);
	cout<< ", the result is:\n";
	e.print();
	e.print_vis();

	cout<<endl;

	cout<<"Finding the smallest key: "<<e.smallest_key()<<endl;
	cout<<"Finding the largest key: "<<e.largest_key()<<endl;
	cout<<"Finding the average value of data for the tree: "<<e.average_data()<<endl;
	cout<<"Finding the max depth of tree: "<<e.max_depth()<<endl;
	cout<<"Finding the min depth of tree: "<<e.min_depth()<<endl;
	cout<<endl;

	return 0;
}



