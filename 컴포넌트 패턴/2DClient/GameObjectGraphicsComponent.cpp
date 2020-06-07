#include"GameObjectGraphicsComponent.h"
#include"GameObject.h"
#include"Texture.h"
#include"Render.h"

GameObjectGraphicsComponent::GameObjectGraphicsComponent(Texture* texture) :texture_(texture) {}

GameObjectGraphicsComponent::~GameObjectGraphicsComponent() {

    if (texture_ != nullptr) {
        delete texture_;
    }
}

void GameObjectGraphicsComponent::Update(GameObject& obj, Render& render) {

    render.Draw(*texture_, obj.x_, obj.y_);

};