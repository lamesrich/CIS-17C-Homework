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
        void display() const;
        //string toString();
        ~LnkdLst();
    private:
        struct Node
        {
            int data;
            Node *next;
        };
        Node *head;
        Node *worker;
};

#endif	/* LNKDLST_H */