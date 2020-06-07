#include<assert.h>
#include "Render.h"
#include"Texture.h"

bool Render::uniqueInstance = false;

Render::Render(){
	assert(uniqueInstance == false);
	uniqueInstance = true;
}

void Render::GetHDC(HDC hdc) {
	hdc_ = hdc;
}

void Render::Draw(Texture& texture, const int x, const int y) {

	HDC hMemDc = CreateCompatibleDC(hdc_);

	SelectObject(hMemDc, texture.bitmap_);
	TransparentBlt(hdc_, x, y, texture.wDest_, texture.hDest_, 
		hMemDc, texture.xoriginSrc_, texture.yoriginSrc_,
		texture.wSrc_, texture.hSrc_, RGB(255, 255, 255));

	DeleteDC(hMemDc);
}
