#include "list.h"
#include <iostream>


List::List()
{
    first = nullptr;
    last = nullptr;
}


bool
List::is_empty()
{
    return (first == nullptr);
}


void
List::clear()
{
    if(is_empty())
        return;
    while(first != nullptr){
        remove_back();
    }
}


void
List::push_front(int _val)
{
    Node* newNode = new Node(_val);
    if(is_empty()){
        first = newNode;
        last = newNode;
        return;
    }
    newNode->next = first;
    first = newNode;
}


void
List::push_back(int _val)
{
    Node* newNode = new Node(_val);
    if(is_empty()){
        first = newNode;
        last = newNode;
        return;
    }
    last->next = newNode;
    last = newNode;
}


Node*
List::find(int _val)
{
    if(is_empty())
        return nullptr;

    Node* current = first;
    while(current != nullptr){
        if(current->val == _val){
            return current;
        }
        current = current->next;
    }
    return current;
}


void
List::remove_front()
{
    if (is_empty())  //Случай когда в списке 0 элементов
        return;
    if(first == last){ //Случай когда в списке 1 элемент
        first = nullptr;
        last = nullptr;
        return;
    }
    Node* temp = first;
    first = first->next;
    delete temp;
}


void
List::remove_back()
{
    if (is_empty()) //Случай когда в списке 0 элементов
        return;
    if(first == last){ //Случай когда в списке 1 элемент
        first = nullptr;
        last = nullptr;
        return;
    }
    Node* current = first; 
    //Случай когда в списке > 1 элемента
    while (current->next->next != nullptr) //Идем до предпоследнего элемента, чтобы получить ссылку на последний элемент
        current = current->next;

    current->next = nullptr;
    last = current;
}


bool
List::remove(const Node* _node)
{
    if(is_empty() || _node == nullptr || find(_node->val) == nullptr) //Случаи когда 0 элементов в списке, перадаваемый элемент = nullptr или отсутствует в списке
        return false;
        
    if(_node == first){ //Случай когда передаваемый элемент стоит в начале списка
        remove_front();
        return true;
    }
    if(_node == last){ //Случай когда передаваемый элемент стоит в конце списка
        remove_back();
        return true;
    } 
    Node* temp = first;
    Node* foundNode = temp->next;
    while(temp->next != _node)
        temp = temp->next;
        
    temp->next = _node->next;

    delete foundNode;
    return true;
}
