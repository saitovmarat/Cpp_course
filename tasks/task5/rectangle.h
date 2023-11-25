#include <stdexcept>

class Rectangle
{
    int Length;
    int Breadth;
    public:
        Rectangle(int l, int b)
        {
            Length = l;
            Breadth = b;
        }
        int Area()
        {
            return Length * Breadth;
        }
        // отношение длинны к ширине
        double RelationsOfTheParties()
        {
            if (Breadth == 0) {
                throw std::runtime_error("zero division");
            }
            return Length / Breadth;
        }
};

int CalculateRectArea(int l, int b)
{
    std::unique_ptr<Rectangle> p = std::make_unique<Rectangle>(l, b);
    int area = p->Area();
    return area;
}

double CalculateRectRelationsOfTheParties(int l, int b)
{
    std::unique_ptr<Rectangle> p = std::make_unique<Rectangle>(l, b); 
    double relation = p->RelationsOfTheParties();
    return relation;
}
