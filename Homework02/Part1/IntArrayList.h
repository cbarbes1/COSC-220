#ifndef INTARRAYLIST_H
#define INTARRAYLIST_H

#include <iostream>
#include <cstdlib>
#include <algorithm>


class IntArrayList{
    private:
        int *list;
        int size;
    public:
        IntArrayList();
        ~IntArrayList();

        void duplicate(IntArrayList&);
        void display(bool vert = false);
        void displayAddress();
        void swap(int*, int, int);
        void sort();
        bool sorted();
        void add(int);
        void concat(const IntArrayList&);
        void remove(int, int);
        void shuffle();
        void sub(int, int);
        void insert(const IntArrayList&, int);
        void insert(int, int);
        int get(int) const;
        void set(int, int) const;
        void resize(int);
        int length() const;
};

#endif