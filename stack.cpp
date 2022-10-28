using namespace std;
#include <iostream>
//template <t>
const int max_size=100;
class stack{
    int top;
    int item[max_size];
public:
    stack():top(-1){}

    void push(int Element)
    {
        if(top>=max_size-1)
        {
            cout<<"stack is full!";
        }
        else
        {
            top ++;
            item[top]=Element;
        }

    }
    bool isEmpty()
    {
        return top<0;
    }
    void pop()
    {
        if(top<0)
        {
            cout<< "stack is empty";
        }
        else
        {
            top--;
        }
    }
    void getTop(int&stacktop)
    {
        if (top<0)
        {
            cout<< "stack is empty!";
        } else
        {
            stacktop=item[top];
           cout<< "stack top is :" << stacktop ;
        }
    }
    void print()
    {
        cout <<"[";
        for (int i = 0; i < top+1; ++i)
        {
            cout<<item[i]<<"  ";

        }
        cout <<"]";
        cout << endl ;
    }
};





int main() {
    stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);
    s.print();
    int y=0;
    s.getTop(y);
    cout<<endl <<"============================"<< endl;
    s.pop();
    s.push(30);

    s.print();


    return 0;
}
