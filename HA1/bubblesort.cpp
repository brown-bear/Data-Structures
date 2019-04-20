// bubblesort.cpp

#include <iostream>
using namespace std;

const int size = 10;
int a[ size ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

void print_array()
{
    for ( int i = 0; i < size; i++ )
        cout <<  a[ i ] << ' ';
    cout << "\n\n";
 }
 
int main() {
    cout << "Data items in original order\n";
    print_array();

    for ( int pass = 1; pass < size; pass++ ) {
        for (int compare = 0; compare < size - pass; compare++ ) {
            if ( a[ compare ] > a[ compare + 1 ] ) {
                // swap elements
                cout << "swaps elements "<< a[ compare ]<< " and "<< a[ compare + 1]<<endl;
                int hold = a[ compare ];
                a[ compare ] = a[ compare + 1 ];
                a[ compare + 1 ] = hold;
            } // end if
        } // end for

        cout << "After pass " << pass << ": ";
        print_array();
    } // end for

    cout << "\nData items in ascending order\n";
    print_array();
 
    return 0;
 } // end main