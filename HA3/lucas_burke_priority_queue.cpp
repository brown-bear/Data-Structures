//-----------------------------------------
// Lucas Burke
// 30 Nov 2017
// Filename: lucas_burke_priority_queue.cpp
// OS: macOS High Sierra v10.13.1
//
// Homework 3: This .cpp file adds a clear, decrease_key
// and print_visual function to a priority queue class.
// The increase and decrease_key functions also test to see
// if a position argument is outside of the queue range.
//
//-----------------------------------------
#include <iostream>
#include <cstdlib>		//for rand() use
#include <cmath>		//for caclulating height of queue
using namespace std;

class Priority_queue {
    int size; // current size
    int max_size;
    int * elements;
    
    void max_heapify(int i){
        int l, r, largest;
        l = 2 * i;      // LEFT(i)
        r = 2 * i + 1;  // RIGHT(i)
        if(l <= size && elements[l] > elements[i]) 
                largest = l;
        else    largest = i;
        
        if(r <= size && elements[r] > elements[largest])
            largest = r;
        
        if(largest != i){
            // swap elements[i] with elements[largest]
            int temp = elements[i];
            elements[i] = elements[largest];
            elements[largest] = temp;
            max_heapify(largest); // recursion
        }
    }

    
public:
    // constructor
    Priority_queue(int n){
        if(n < 0) max_size = 1; // default max_size == 1
        else max_size = n;
        size = 0; // creates empty queue
        elements = new int [max_size + 1];
        // indicies of stored elements start with 1
        elements[0] = -1; 
    }
    
    void enqueue(int key){
        if(size + 1 > max_size){
            cout<< " queue overflow\n";
            return;
        }
        size++;
        elements[size] = key;
        // Walk backwards through the queue from size/2 to 1,
        // calling max_heapify() on each node => this is the same as constructing 
        // a heap from sub-heaps (bottom-up).
        // Order of processing guarantees that the children of node i 
        // are heaps when i is processed
        for(int i = size/2; i > 0; i--)
            max_heapify(i);
    }

    int maximum(){
        if(size == 0){
            cout<< " queue underflow\n";
            return -1;
        }
        return elements[1];
    }
    
    int dequeue(){
        if(size == 0){
            cout<< " queue underflow\n";
            return -1;
        }
        int root = elements[1];
        elements[1] = elements[size];
        size--;
        max_heapify(1);
        return root;
    }
    




	//******************************************************************
   //******************* !!!!!!! MY UPDATES !!!!!!!! *******************
  //********************************************************************

    void increase_key(int position, int new_key){
        if(new_key < elements[position]){
            cout<<" Error: new key "<< new_key << " is smaller than current key " 
                << elements[position]<<endl;
            return;
        }
        if(position>size){
     	   	   cout<<"ERROR: queue position does not exist (outside of queue size)."<<endl; // Additional functionality to test if position is outside of queue.
     	   	   return;
        }
        elements[position] = new_key;
        while(position > 1 && elements[position/2] < elements[position]){
            // swap element with its parent
            int temp = elements[position/2];
            elements[position/2] = elements[position];
            elements[position] = temp;
            position = position/2; // move upward
        }
    }

    void show(){
        // print the heap contents
        cout<< "the heap contents is: ";
        if(max_size<=0){cout<<"Queue is empty!"<<endl;}		// Added additional checks for a queue with max (initial) size zero
        else if(size<=0){cout<<"Queue is empty!"<<endl;}		// and a cleared queue...
        for(int i = 1; i <= size; i++)
            cout<< elements[i]<< ' ';
        cout<<endl;
    }

/************************ NEW FUNCTIONS: ************************/

    void clear(){
    	// clear the heap contents
		cout<< "clearing out the heap contents..."<<endl;  // Setting 'size = 0' does not free the current queue from memory.
		while(size>0){
			dequeue();
		}
    }

    void decrease_key(int position, int new_key){
    		cout<<"Decreasing key at position "<<position<<" to "<<new_key<<endl;

		if(new_key > elements[position]){
		   cout<<" Error: new key "<< new_key << " is greater than current key "
			   << elements[position]<<endl;
		   return;
		}
		if(position>size){
			   cout<<"ERROR: queue position does not exist (outside of queue size)."<<endl;  // Additional functionality to test if position is outside of queue.
			   return;
		}
		elements[position] = new_key;
		while(position > 1 && elements[position] < elements[position*2]){
		   max_heapify(position);
		}
	}

    void print_visual(){
		int k = 0, m = 1;

		int rows = ceil(log2(size)+1);


		for (int i = 0; i <= rows; ++i) {	// Sets the number of rows in the pyramid.

			for(int space = 0; space < 2*pow(rows,2) - pow(2,i)-i; space++){	// Sets the number of spaces leading each row.
				cout << " ";
			}

			for (int j = 1; j <= pow(2,k-1) && m<=size; ++j){ // Sets the number of elements from the queue in each row.
					cout<<elements[m]<<"    ";
					m++;
			}
			cout<<endl;
			k++;
		}
	}
};



int main(){
	cout<<"//********************** TEST CASE 1: EMPTY QUEUE **********************\\"<<endl;

    Priority_queue a(0);
    
    for(int j = 0; j <0; j++)
        a.enqueue(rand()% 100);

	a.show();
	cout<<endl;
	a.print_visual();

	a.decrease_key(2, 4);
	cout<<" After key decrease: \n";

	a.show();
	cout<<endl;
	a.print_visual();

	a.clear();
	cout<<"queue after clearing it out -- "<<endl;

	a.show();
	cout<<endl;
	a.print_visual();


	cout<<"//********************** TEST CASE 2: 1-ELEMENT QUEUE **********************\\"<<endl;

    Priority_queue b(5);

    for(int j = 1; j <2; j++)
        b.enqueue(rand()% 100);

	b.show();
	cout<<endl;
	b.print_visual();

	b.decrease_key(2, 4);
	cout<<" After key decrease: \n";

	b.show();
	cout<<endl;
	b.print_visual();

	b.clear();
	cout<<"queue after clearing it out -- "<<endl;

	b.show();
	cout<<endl;
	b.print_visual();


	cout<<"//********************** TEST CASE 3: SMALL QUEUE **********************\\"<<endl;

    Priority_queue c(10);

    for(int j = 1; j <5; j++)
        c.enqueue(rand()% 100);

	c.show();
	cout<<endl;
	c.print_visual();

	c.decrease_key(2, 4);
	cout<<" After key decrease: \n";


	c.show();
	cout<<endl;
	c.print_visual();

	c.clear();
	cout<<"queue after clearing it out -- "<<endl;

	c.show();
	cout<<endl;
	c.print_visual();


    cout<<"//********************** TEST CASE 4: LARGE QUEUE **********************\\"<<endl;

	Priority_queue d(100);

	for(int j = 1; j < 64; j++)
		d.enqueue(rand()% 100);

	d.show();
	cout<<endl;
	d.print_visual();

	d.decrease_key(2, 4);
	cout<<" After key decrease: \n";

	d.show();
	cout<<endl;
	d.print_visual();

	d.clear();
	cout<<"queue after clearing it out -- "<<endl;

	d.show();
	cout<<endl;
	d.print_visual();

    return 0;
}
