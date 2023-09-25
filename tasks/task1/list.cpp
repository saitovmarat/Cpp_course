#include "list.h"


List::List()
{
    List();
}


bool
List::is_empty()
{
    if(first == nullptr)
        return true;
    return false;  
}


void
List::clear()
{
    while(first != nullptr){
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}



void
List::push_front(int _val)
{
    Node* newNode = new Node(_val);
    newNode->next = first;
}


void
List::push_back(int _val)
{
    Node* newNode = new Node(_val);
    last->next = newNode;
    newNode->next = nullptr;
}


Node*
List::find(int _val)
{
    Node* temp = first;
    while(temp->val != _val || temp != nullptr){
        if(temp->val == _val)
            return temp;
        temp = temp->next;
    }
    return nullptr;
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
    if (first->next == nullptr){
        delete first;
        first = nullptr;
        return;
    }
    Node* temp = first;
    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}


bool
List::remove(const Node* _node)
{
    if(first == nullptr || _node == nullptr)
        return false;
    if(_node == first){
        remove_front();
        return true;
    }
    if(_node == last){
        remove_back();
        return true;
    } 
    if(find(_node->val) == nullptr)
        return false;
    Node* temp = first->next;
    while(temp->next != _node)
        temp = temp->next;
    temp->next = _node->next;
    delete _node;
    return true;
}
