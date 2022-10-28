#include <iostream>
using namespace std;
//const int max_size=100;

class arrayQueueType
{
    int rear;
    int front;
    int length;
    int maxsize;
   // int arr[max_size];
   int *arr;
public:
    arrayQueueType(int size)
    {
        if(size <=0)
        {
            maxsize=100;
        } else
        {
            maxsize=size;
        }
        front=0;
        arr = new int [size];
        rear=maxsize-1;
        length=0;

    }
    int isEmpty()
    {
        return length==0;
    }
    bool isFull()
    {
        return length==maxsize;
    }
    void enqueue(int Element)
    {
        if(isFull())
        {
            cout << "Queue is full";
        }
        else
        {
            rear=(rear+1)%maxsize;
            arr[rear]=Element;
            length++;
            cout<< Element <<"   ";
        }
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"queue is empty";
        } else
        {
            front=(front+1)%maxsize;
            --length;
        }
    }
    int queuesearch(int element)
    {
        int pos=-1;
        if(!isEmpty())
        {
            for (int i = front; i!=rear; i=(i+1)%maxsize)
            {
                if (arr[i]==element) {
                    pos = i;
                    cout<< endl << pos << endl ;
                    break;
                }
            }
            if (pos==-1)
            {
                if (arr[rear]==element)
                {
                    return length==maxsize;
                }
            }
        }

    }
    void print()
    {
        cout <<"[";
        for (int i = 0; i < maxsize; ++i)
        {
            cout<<arr[i]<<"  ";

        }
        cout <<"]";
        cout << endl ;
    }

};








int main() {
    arrayQueueType aq (5) ;
    aq.enqueue(20);
    aq.enqueue(30);
    aq.enqueue(40);
    aq.enqueue(50);
    aq.enqueue(60);
    aq.queuesearch(40);
    aq.dequeue();
    aq.enqueue(70);
    aq.print();

    return 0;
}
