struct A {
    int memi;
    int getMem();
};

struct B {
    int memi;
    int getMem();
};

int main(void)
{
    A a;
    /*
       although A and B are classes with the exactly same members,
       they are still different type!
    */
    B b = a; // error: conversion from ‘A’ to non-scalar type ‘B’ requested
}

