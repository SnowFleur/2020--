#pragma once

class Controller {
private:
    Controller() = default;
    static int direction_;
public:
    static void SetDirection(const int direction) {
        direction_ = direction;
    }
    static int GetDirection() {
        return direction_;
    }
};
