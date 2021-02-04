#include "stdafx.h"
#include "Player.h"


void Player::GetPlayerPosition(int& x, int& y) {
    x = xpos_;
    y = ypos_;
}
void Player::SetPlayerPosition(int x, int y) {
    xpos_ = x;
    ypos_ = y;
    y = ypos_;
}

const Texture& Player::GetPlayerTexture()const {
    return *texture_;
}
