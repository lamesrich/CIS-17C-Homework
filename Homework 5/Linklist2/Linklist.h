#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
using namespace std;

class LnkdLst 
{
    public:
        LnkdLst();
        LnkdLst(LnkdLst *);
        int first();
        int last();
        LnkdLst(int value);
        void extract(int value);
        void InsertAfter(int index, int value);
        void InsertBefore(int index, int value);
        void append(int value);
        void prepend(int value);
        void pop_fornt();
        void display() const;
        int sz() const;
        //string toString();
        ~LnkdLst();
    private:
        struct Node
        {
            int data;
            Node *next;
        };
        int size;
        Node *head;
        Node *tail;
};

#endif	/* LNKDLST_H */