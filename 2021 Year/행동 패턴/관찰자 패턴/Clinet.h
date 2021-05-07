#pragma once
#include<utility>
#include<vector>>
using VECTOR2D = std::pair<int, int>;

class CClinet {
private:
    VECTOR2D position_{};
public:

    void Move(VECTOR2D& move) {
        position_.first += move.first;
        position_.second += move.second;
    }

};
