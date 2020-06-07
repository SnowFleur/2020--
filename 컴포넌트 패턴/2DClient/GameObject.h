#pragma once

class InputComponent;
class GraphicsComponent;
class Render;

class GameObject {
private:
    InputComponent* input_;
    GraphicsComponent* graphics_;
public:
    GameObject(InputComponent*,GraphicsComponent*);
    ~GameObject();
    int x_;
    int y_;
    virtual void Update(Render&);
};




