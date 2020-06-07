#pragma once
#include<Windows.h>
class Texture{
public:
    Texture(HBITMAP bitmap, int wDest, int hDest, 
        int xoriginSrc, int yoriginSrc, int wSrc, int hSrc);
    HBITMAP bitmap_;
    int wDest_;
    int hDest_;
    int xoriginSrc_;
    int yoriginSrc_;
    int wSrc_;
    int hSrc_;
};

