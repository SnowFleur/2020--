#include<iostream>

/*
���丮 ������ �ڽ��� �����ڿ��� �����ϴ°� �ƴ� �ٸ� Ŭ������ ������ �����ϴ� ���� ���� �� �ϳ� �̴�.
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