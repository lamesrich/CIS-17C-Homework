#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
using namespace std;

class LnkdLst 
{
    public:
        LnkdLst();
        LnkdLst(int value);
        void append(int value);
        void prepend(int value);
        void pop_fornt();
        void find(int);
        void display() const;
        void select_sort();
        //string toString();
        ~LnkdLst();
    private:
        struct Node
        {
            int data;
            Node *next;
        };
        Node *head;
        Node *tail;
};

#endif	/* LNKDLST_H */