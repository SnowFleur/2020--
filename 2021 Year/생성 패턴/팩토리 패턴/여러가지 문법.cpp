#include <map>
#include<iostream>
#include<string>
#include <functional>
#include<memory>

/*
디자인 패턴책에서 사용하는 생소하면서도 C++스러운 문법들을 다시 공부하고 습득하는 소스파일
*/

using namespace std;

namespace case1 {

    /*Function과 map을 이용한 기법*/
    class CObject {

    };
    class DrinkWithVolumeFactory {
        map<string, function<unique_ptr<CObject>()>> factories;
    public:

        DrinkWithVolumeFactory()
        {
            factories["tea"] = [] {
                auto tea = make_unique<CObject>();
                return tea;
            };
        }

        unique_ptr<CObject> make_drink(const string& name) {
            return factories[name]();
        }
    };


    void Process() {
        DrinkWithVolumeFactory factory;
        map<string, function<void()>> fun;

        fun["A"] = []() {std::cout << "A\n"; };
        fun["B"] = []() {std::cout << "B\n"; };
        fun["C"] = []() {std::cout << "C\n"; };

        fun["A"]();
        fun["B"]();
        fun["C"]();
    }
};

namespace case2 {
    /*변환 연산자 오버로딩*/
    class CPlayer {
    };

    class CObject {
    private:
        CPlayer p;
    public:

        operator CPlayer() {
            std::cout << "변환 연산자 오버로딩\n";
            return p;
        }

    };

    void Process() {
        CObject b;
        CPlayer p = b;
    }
}



int main() {
    case1::Process();
    case2::Process();
}