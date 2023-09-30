#include "stackList.h"


List::List(){
    last = nullptr;
}

bool
List::empty(){
    return (last == nullptr);
}

Stack* 
List::pop(){
    if (empty()) //Случай когда в списке 0 элементов
        return nullptr;

    Stack* current = last;
    if(last->prev == nullptr){ //Случай когда в списке 1 элемент
        last = nullptr;
        return current;
    }
    last = last->prev;
    return current;
}    
void
List::push(int _val){
    Stack* newStack = new Stack(_val);
    newStack->prev = last;
    last = newStack;
}
int
List::size(){
    if(empty())
        return 0;

    Stack* current = last;
    int stackSize = 1; // 1, так как последний элемент не считается
    while(current->prev != nullptr){
        current = current->prev;
        stackSize++;
    }
    return stackSize;
}

