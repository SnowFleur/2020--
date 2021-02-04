/*
단일 책임 원칙
각 클래스는 단 하난가지의 책임을 부여받아 수정할 이유가 단 한가지여야 한다.
*/
#include<string>
#include<fstream>
#include<vector>

using string = std::string;

/*
메모장의 역할은 각 항목을 기록할 수 있고 관리할 책임이 있다.
*/
struct Journal {
    string                  title;
    std::vector<string>     entries;

    explicit Journal(const string& title) :title{ title } {}

    void Add(const string& entry) {
        static int count{ 1 };
        entries.emplace_back(std::to_string(count++) + entry);
    }
};

/*
디스크에 파일을 쓰는 기능은 메모장이 아닌 PersistenceManager가 해야한다.
Journal에 함수를 쓸경우 저장 방식이 변경되면 모두 바꿔야 하기 때문이다.
*/
struct PersistenceManager {
    static void Save(const Journal& j, const string& filename) {
        std::ofstream ofs(filename);
        for (auto& s : j.entries) {
            ofs << s << std::endl;
        }
    }
};


