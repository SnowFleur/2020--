#pragma once
#include<Windows.h>

class Texture;

class Render {
private:
    HDC hdc_;
public:
    static bool uniqueInstance;
    Render();
    void GetHDC(HDC);
    void Draw(Texture&, int x, int y);

};


