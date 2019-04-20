//-----------------------------------------
// Lucas Burke
// Homework 1:  Merge two arrays into one and dynamically return pointer to start of third array
// 24 Oct 2017
// Filename: HA1prax.cpp
//-----------------------------------------

#include<iostream>
#include<cstdio>
using namespace std;

int *append(int a[], int length1, int b[], int length2);
void show(int a[], int length1);

int main() {

    int a[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[]={10, 11, 12, 13, 14, 15, 16, 17, 18};
    int length1[] = {0, 1, 4};
    int length2[] = {0, 1, 2};
    int *result;

    cout<<"Original Array A: ";
    show(a, 9);

    cout<<"Original Array B: ";
    show(b, 9);

    cout<<'\n';

    for (int i=0; i<3; i++){
        for (int k=0; k<3; k++)
        {
            cout<<"Array A: ";
            show(a, length1[i]);
            cout<<"Array B: ";
            show(b, length2[k]);
            cout<<"Merged Arrays: ";
            result = append(a, length1[i], b, length2[k]);

            show(result, length1[i]+length2[k]);
            cout<<'\n';
        }

    }
    return 0;
}

int *append(int a[], int length1, int b[], int length2) {

    int *c = new int[length1+length2];


    for(int i=0; i<length1; i++){
        c[i] = a[i];
    }

    for(int i=0; i<length2; i++) {
        c[i+length1] = b[i];
    }
    return c;
}

void show(int a[], int length) {
    for(int i=0; i<length; i++) {
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}