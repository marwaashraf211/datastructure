#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;


class linkedlist {

    struct node{
        int item;
        node *next;
    };
    node *first;
    node *last;
    int length;

public:
    linkedlist() {

        first= last=NULL;
        length=0;
    };

    bool isEmpty() {
        return length == 0;
    }

    int getsize() {
        return length;
    }

    int insertfirst( int element) {
        node *newnode =new node;
        newnode->item=element;
        if (isEmpty()) {
            first= last=newnode;
            newnode->next=NULL;
        }
        else
        {
            newnode->next=first;
            first=newnode;
        }
        length++;
        }
    int insertatlast( int element) {
        node *newnode =new node;
        newnode->item=element;
        if (isEmpty()) {
            first= last=newnode;
            newnode->next=NULL;
        }
        else
        {
            last->next=newnode;
            newnode->next=NULL;
            last= newnode;
        }
        length++;
    }

    int insertatpos( int pos,int item) {
        node *newnode = new node;
        newnode->item = item;
        if (pos == 0)
            insertfirst(item);
        else if (pos == length)
            insertatlast(item);
        else {
            node *cur = first;
            for (int i = 1; i < pos; i++) {
                cur = cur->next;
                newnode->next = cur;
                cur->next = newnode;
                length++;
            }
        }
        length++;
    }
    void removeatfirst() {
        if (length==0) {
            cout << "empty list";
        } else if (length==1) {
            delete first;
            first= last=NULL;
        } else
        {
            node *curr=first;
            first=first->next;
            delete curr;
        }
    }
    void removelast() {
        node *curr=first->next;
        node *prev=first;
        while (curr!=last)
        {
            prev=curr;
            curr=curr->next;
        }
        delete curr ;
        prev->next=NULL;
    }
    void remove(int element)
    {
        if (isEmpty())
            cout << " empty list";
        node *curr,*prev;
        if(first->item==element)
        {
            curr=first;
            first=first->next;
            delete curr;
            length--;
            if (length==0)
                last=NULL;
        } else
        {
            curr=first->next;
            prev=first;
            while (curr!=NULL)
            {
                if (curr->item==element)
                    break;
                prev=curr;
                curr=curr->next;
            }
        }

    }

    void print() {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }

    }

    int search(int element) {
        for (int i = 0; i < length; i++) {
            if (arr[i] == element) {
                return i;
            }
            return -1;
        }
    }

    void noduplicated(int element)
    {
        if (search(element)==-1)
            cout << "out of range";
        else
            arr[pos]=element;


    }
    int getelement(int pos)
    {
        if(pos<0 || pos>=length)
            cout << "out of range";

        return arr[pos];

    }

};

int main() {
    int size;
    int pos;
    cout<< "enter the size" << endl , cin >> size;
    arraylist al (size);
    int ele;
    for (int i = 0; i <size-1 ; i++)
    {
        int la=al.insertat(i,ele);
        cout << "enter your elemts  " << endl << i <<"    "<<endl, cin >> la  ;
    }
    al.search(30);
    al.print();




    return 0;
}
