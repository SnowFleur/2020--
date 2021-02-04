#pragma once

class GameObject;
class Render;

class GraphicsComponent{
private:
public:
    virtual void Update(GameObject&, Render&)=0;
};

