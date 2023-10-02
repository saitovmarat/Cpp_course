class Stack {
public:
    int length;
    int* array;
    int currentIndex;

    Stack() {}
    
    Stack(int num){
        length = num;
        array = new int[length];
        currentIndex = 0;
    }

    void Push(int _val) {
        if(currentIndex == length)
            return;
        array[currentIndex] = _val;
        currentIndex++;
    }

    int Top() {
        if(currentIndex == 0){
            throw __EXCEPTIONS;
        }
        return array[currentIndex-1];
    }

    void Pop() {
        if(currentIndex == 0)
            return;
        array[currentIndex] = 0;
        currentIndex--;
    }

    ~Stack() {
        /* Not Implemented */
    }
private:
    /* Not Implemented */
};

