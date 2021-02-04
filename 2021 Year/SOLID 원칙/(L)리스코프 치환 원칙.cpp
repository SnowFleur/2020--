
#include<iostream>
class Rectangle {
protected:
    int width, height;
public:
    Rectangle(const int width, const int height) :width{ width }, height{ height }{}

    int GetWidth()const { return width; }
    virtual void SetWidth(const int width) {
        this->width = width;
    }

    int GetHeight()const { return height; }
    virtual void SetHeight(const int height) {
        this->height = height;
    }

    int area()const { return width * height; }
};

class Square :public Rectangle {
public:
    Square(int size) :Rectangle{ size,size } {}

    void SetWidth(const int width)override {
        this->width = this->height = width;
    }

    void SetHeight(const int height)override {
        std::cout << "Square\n";
        this->width = this->height = height;
    }

};

void Process(Rectangle& r) {
    int w = r.GetWidth();

    r.SetHeight(10);

    std::cout << "expected area = " << (w * 10)
        << ", got " << r.area() << std::endl;
}

int main() {
    Rectangle r{ 3, 4 };
    Process(r);

    Square sq{ 5 };
    Process(sq);

}