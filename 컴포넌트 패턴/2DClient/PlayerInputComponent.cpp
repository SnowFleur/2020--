#include"define.h"
#include"PlayerInputComponent.h"
#include"GameObject.h"
#include"Controller.h"

void PlayerInputComponent::Update(GameObject& obj) {

    switch (Controller::GetDirection()) {
    case DIR_RIGHT:
        if (obj.x_ < 586) {
            obj.x_ += ADD_MOVE;
        }
        break;
    case DIR_LEFT:
        if (obj.x_ > 82) {
            obj.x_ -= ADD_MOVE;
        }
        break;
    case DIR_UP:
        if (obj.y_ > 45) {
            obj.y_ -= ADD_MOVE;
        }
        break;
    case DIR_DOWN:
        if (obj.y_ < 549) {
            obj.y_ += ADD_MOVE;
        }
        break;
    default:
        break;
    }
}