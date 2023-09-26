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
    newNode->next = first;
    last = first;
    first = newNode;
}


void
List::push_back(int _val)
{
    Node* newNode = new Node(_val);
    if(is_empty()){
        first = newNode;
        last = first;
        return;
    }
    /*Ошибка*/last->next = newNode;
    first = last;
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
    if (is_empty())
        return;
    Node* temp = first;
    first = first->next;
    delete temp;
}


void
List::remove_back()
{
    if (is_empty())
        return;
    Node* temp = first;
    if(first->next == nullptr){
        first = nullptr;
        last = first;
        return;
    }
    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}


bool
List::remove(const Node* _node)
{
    if(is_empty() || _node == nullptr || find(_node->val) == nullptr)
        return false;
        
    if(_node == first){
        remove_front();
        return true;
    }
    if(_node == last){
        remove_back();
        return true;
    } 
    Node* temp = first;
    while(temp->next != _node)
        temp = temp->next;
    temp->next = _node->next;
    delete temp;
    return true;
}
