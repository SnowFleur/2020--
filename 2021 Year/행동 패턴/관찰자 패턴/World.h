#pragma once

#include<string>
#include <conio.h>
#include"ObserverComponent.h"

#define UP      72
#define LEFT    75
#define RIGHT   77
#define DOWN    80

class CWorld {
private:
    std::vector<std::vector<std::string>> cell;

    void Update() {

    }
    void Draw() {

        system("cls");
        for (size_t x = 0; x < cell.size(); ++x) {
            for (size_t y = 0; y < cell[x].size(); ++y) {
                std::cout << cell[x][y] << "";
            }
            std::cout << "\n";
        }

    }
public:
    void Run() {

        cell.assign(30, std::vector<std::string>(30, std::string("бс")));

        while (true) {
            if (_kbhit()) {
                switch (_getch()) {
                case LEFT:
                    break;
                case RIGHT:
                    break;
                case UP:
                    break;
                case DOWN:
                    break;
                }
                Draw();

            }
        }
    }

};


