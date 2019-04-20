//-----------------------------------------
// Lucas Burke
// 24 Oct 2017
// Homework 1:  Merge two arrays into one and dynamically return pointer to start of third array
// Filename: Burke_HA1.cpp
//-----------------------------------------

#include<iostream>
using namespace std;

int *append(int a[], int length1, int b[], int length2);
void show(int a[], int length1);

int main() 
{
	// I initialized two arrays with single and double-digit integers to make my debugging a little easier and track mistakes.
	
    int a[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[]={10, 11, 12, 13, 14, 15, 16, 17, 18};
    int length1[] = {0, 1, 2};
    int length2[] = {0, 1, 4};  // I used a '4' to vary the length of the arrays, but only required a number >=2.
    int *result;

	// Show the original first initialized array.
    cout<<"Original Array A: ";
    show(a, 9);

	// Show the original second initialized array.
    cout<<"Original Array B: ";
    show(b, 9);

    cout<<'\n';
	
	// Run two for loops to test the nine different cases for length (0, 1, 2) for each array.
    for (int i=0; i<3; i++)
    {
        for (int k=0; k<3; k++)
        {
			// Prints out the original arrays for the given length.
            cout<<"Array A: ";
            show(a, length1[i]);
            cout<<"Array B: ";
            show(b, length2[k]);
			
			// Prints out the merged array.
            cout<<"Merged Array: ";
            result = append(a, length1[i], b, length2[k]);
            show(result, length1[i]+length2[k]);
            cout<<'\n';
        }
    }
    return 0;
}


// This function actually appends the arrays and returns the memory address of the array.

int *append(int a[], int length1, int b[], int length2) 
{
    int *c = new int[length1+length2];

    for(int i=0; i<length1; i++)
    {
        c[i] = a[i];
    }

    for(int i=0; i<length2; i++) 
    {
        c[i+length1] = b[i];
    }
	// This line was a debugging line to ensure that the address was being returned.
	// cout<<c<<endl;
    return c;
}


// This function printed the arrays to the screen.

void show(int a[], int length) 
{
    for(int i=0; i<length; i++) 
    {
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}