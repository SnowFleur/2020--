#pragma once
class GameObject;

class InputComponent{
private:
public:
    virtual ~InputComponent() {};
    virtual void Update(GameObject&) = 0;
};

