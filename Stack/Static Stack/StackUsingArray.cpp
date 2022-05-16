#include "Stack.cpp"

int main() {
    Stack *stack = new Stack(5);
    
    stack->push(10);
    stack->push(20);
    stack->push(30);

    cout<<stack->pop()<<endl;
    cout<<stack->pop()<<endl;
    cout<<stack->pop()<<endl;
    stack->pop();

    stack->push(10);
    stack->push(20);
    stack->push(30);
    stack->push(40);
    stack->push(50);
    stack->push(60);
    return 0;
}
