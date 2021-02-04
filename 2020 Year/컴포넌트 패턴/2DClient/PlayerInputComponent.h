#pragma once
#include"InputComponent.h"

class PlayerInputComponent : public InputComponent {
private:
    const int ADD_MOVE = 72;
public:
    virtual void Update(GameObject& obj);

};

