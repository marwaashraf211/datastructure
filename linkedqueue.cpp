#include <iostream>
#include <cassert>

using namespace std;


class linkedqueue
{

private:
    struct node{
        int item;
        node *next;
    };
    node *frontptr;
    node *rearptr;
    int length;
public:
    linkedqueue():frontptr(NULL),rearptr(NULL),length(0)
    {};
    int isEmpty()
    {
        return length==0;
    }

    void enqueue(int Element) {
        if (isEmpty()) {
            frontptr = new node;
            frontptr->item = Element;
            frontptr->next = NULL;
            rearptr = frontptr;
            length++;
        }

        /*
        else {
            node *newptr = new node;
            newptr->item = Element;
            newptr->next = newptr;
            if (length == 0)
                rearptr = frontptr = newptr;
            else {
                rearptr->next = newptr;
                rearptr = newptr;
            }


        }
        length++;
*/

    }
    void dequeue()
    {
        node *temptr=frontptr;
        if(frontptr==rearptr)
        {
            frontptr=NULL;
            rearptr=NULL;
            length--;
        } else
        {
            --length;
            frontptr=frontptr->next;
        }
        temptr->next=NULL;
        delete temptr;
    }

    int getFront()
    {
        assert(!isEmpty());
        return frontptr->item;
    }
    int getRear()
    {
        assert(!isEmpty());
        return rearptr->item;
    }
    void getFront2(int&el)
    {
        el=frontptr->item;
    }
    void clearqueue()
    {
        node *current;
        while (frontptr!=NULL)
        {
            current=frontptr;
            frontptr=frontptr->next;
            delete current;
        }
        rearptr=NULL;
    }
    void display()
    {
        node *cur=frontptr;
        while (cur!=NULL)
        {
            cout<< cur->item;
            cur=cur->next;
        }
    }

};

int main() {
    linkedqueue lq  ;
    lq.enqueue(20);
    lq.enqueue(30);
    lq.enqueue(40);
    lq.enqueue(50);
    lq.enqueue(60);
    lq.display();
    /*lq.dequeue();
    lq.enqueue(70);
    lq.clearqueue();
    lq.display();*/

    return 0;
}
