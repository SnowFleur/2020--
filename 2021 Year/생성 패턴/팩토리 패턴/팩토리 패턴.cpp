#include<iostream>

/*
팩토리 패턴은 자신이 생성자에서 생성하는게 아닌 다른 클래스에 생성을 위임하는 생성 패턴 중 하나 이다.
*/

class CGameObjectFactory;

class CGameObject {
private:
    int x_, y_;
    int hp_;
    CGameObject(int x, int y, int hp) :x_{ x }, y_{ y }, hp_{ hp } {}
public:
    CGameObject() = delete;

    friend CGameObjectFactory;
};

class CGameObjectFactory {
private:
public:
    static CGameObject NewPlayerObject(int x, int y, int hp) {
        return CGameObject{ x,y,hp };
    }
    static CGameObject NewMonsterObject(int x, int y, int hp) {
        return CGameObject{ x,y,hp };
    }
};


int main() {
    CGameObject monster = CGameObjectFactory::NewMonsterObject(5, 5, 5);
    CGameObject player = CGameObjectFactory::NewPlayerObject(5, 5, 5);

}