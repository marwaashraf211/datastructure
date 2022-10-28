#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;


class arraylist {
    int *arr;
    int maxsize;
    int length;
    int pos;
public:
    arraylist(int s) {

        if (s < 0) {
            maxsize = 10;
        } else {
            maxsize = s;
        }
        length = 0;
        arr = new int[maxsize];
    };

    int isEmpty() {
        return length == 0;
    }

    bool isFull() {
        return length == maxsize;
    }


    int getsize() {
        return length;
    }

    int insertat(int pos, int element) {
        if (isFull()) {
            cout << "is full ";
        } else if (pos < 0 || pos > length) {
            cout << "out of range ";
        } else {
            for (int i = length; i < pos; i--) {
                arr[i] = arr[i - 1];
            }
        }

    }

    void removeat(int pos) {
        if (isEmpty()) {
            cout << "empty list";
        } else if (pos < 0 || pos > length) {
            cout << "out of range ";
        } else
            for (int i = pos; i < length; i++) {
                arr[i] = arr[i + 1];
                length--;
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
