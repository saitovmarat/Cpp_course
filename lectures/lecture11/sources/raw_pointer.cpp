
void foo() /* noexcept ??? */ {}

int main() {

    {
        auto ptr = new int{10};
        
        // ...

        delete ptr; // ???
    }

    {
        auto value = 10;
        auto ptr = new int{10};

        // ...
        
        ptr = &value;
    }

    {
        auto ptr = new int[10];

        // ...

        delete[] ptr;
    }

    {
        auto ptr = new int[10];

        // if (...) {
            
        // } else if (...) {
        //     ...
        // } else if (...) {
        // 
        //     return ... !!!!!!!
        // } ...

        delete[] ptr;
    }

    {
        auto ptr = new int[10];
        
        // do smth
        
        foo(); // ???
        
        // do smth
        
        delete[] ptr;
    }

    return 0;
}