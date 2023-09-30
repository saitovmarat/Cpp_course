#include "stackList.h"
#include <iostream>

int main(){
    List l;
    //List initialisation test
    if(l.empty())
        std::cout << "Success" << "\n";
    else
        std::cout << "Fail" << "\n";

    //push() test
    l.push(1);
    if(l.size() == 1)
        std::cout << "Success" << "\n";
    else
        std::cout << "Fail" << "\n";
    
    //pop() test
    l.pop();
    if(l.size() == 0)
        std::cout << "Success" << "\n";
    else
        std::cout << "Fail" << "\n";
    return 0;
}