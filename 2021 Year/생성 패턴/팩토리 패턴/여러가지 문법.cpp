#include <map>
#include<iostream>
#include<string>
#include <functional>
#include<memory>

/*
������ ����å���� ����ϴ� �����ϸ鼭�� C++������ �������� �ٽ� �����ϰ� �����ϴ� �ҽ�����
*/

using namespace std;

namespace case1 {

    /*Function�� map�� �̿��� ���*/
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
    /*��ȯ ������ �����ε�*/
    class CPlayer {
    };

    class CObject {
    private:
        CPlayer p;
    public:

        operator CPlayer() {
            std::cout << "��ȯ ������ �����ε�\n";
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