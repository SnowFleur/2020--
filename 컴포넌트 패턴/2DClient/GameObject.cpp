#include"GameObject.h"
#include"InputComponent.h"
#include"GraphicsComponent.h"


GameObject::GameObject(InputComponent* input, GraphicsComponent* graphics) 
    :x_(82), y_(45),input_(input), graphics_(graphics) {}


GameObject::~GameObject() {

    if (input_ != nullptr) {
        delete input_;
    }

    if (graphics_ != nullptr) {
        delete graphics_;
    }
}

void GameObject:: Update(Render& render) {

    input_->Update(*this);
    graphics_->Update(*this, render);

}
