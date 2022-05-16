#include<iostream>
using namespace std;
class Stack {
    int *data;
    int nextIndex;
    int stackSize;
    public:
        Stack(int totalSize) {
            data = new int[totalSize];
            nextIndex = 0;
            stackSize = totalSize;
        }

        //Return the number of elements present in the stack
        int size() {
            return nextIndex;
        }

        bool isEmpty() {
            return nextIndex == 0;
        }

        //Insert element in the stack

        void push(int element) {
            if(nextIndex == stackSize) {
                cout<<"Stack Full...."<<endl;
                return;
            }
            data[nextIndex] = element;
            nextIndex++;
        }

        //Delete the element from stack
        int pop() {
            if(isEmpty()) {
                cout<<"Stack Empty...."<<endl;
                return -1;
            }
            nextIndex--;
            return data[nextIndex];
        }

        //Return top element of the stack
        int top() {
            if(isEmpty()) {
                return -1;
            }
            return data[nextIndex-1];
        }
};