#pragma once
class Player{
private:
    int         xpos_;
    int         ypos_;
    Texture*    texture_;
public:
    Player() = default;
    Player(Texture* texture):texture_(texture),xpos_(0),ypos_(0){}
public:
    void    GetPlayerPosition(int& x, int& y);
    void    SetPlayerPosition(int x, int y);
    const   Texture& GetPlayerTexture()const;
};

