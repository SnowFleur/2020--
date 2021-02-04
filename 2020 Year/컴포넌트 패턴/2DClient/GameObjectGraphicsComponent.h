#pragma once
#include"GraphicsComponent.h"

class Texture;
class Render;
class GameObject;

class GameObjectGraphicsComponent : public GraphicsComponent {
private:
    Texture* texture_;
public:
    GameObjectGraphicsComponent(Texture*);
    ~GameObjectGraphicsComponent();
    virtual void Update(GameObject&, Render&);
};