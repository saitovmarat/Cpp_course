struct Stack {
    int val;
    Stack* prev;

    Stack(int _val) : val(_val), prev(nullptr) {}

    
};

struct List{
    Stack* last;
    
    List();

    bool empty();

    Stack* pop();

    void push(int _val);

    int size();
};

