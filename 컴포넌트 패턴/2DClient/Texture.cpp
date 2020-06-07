#include "Texture.h"

Texture::Texture(HBITMAP bitmap, int wDest, int hDest,
    int xoriginSrc, int yoriginSrc, int wSrc, int hSrc)
    :bitmap_(bitmap), wDest_(wDest), hDest_(hDest), xoriginSrc_(xoriginSrc),
    yoriginSrc_(yoriginSrc), wSrc_(wSrc), hSrc_(hSrc){}