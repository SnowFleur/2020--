/*
���� å�� ��Ģ
�� Ŭ������ �� �ϳ������� å���� �ο��޾� ������ ������ �� �Ѱ������� �Ѵ�.
*/
#include<string>
#include<fstream>
#include<vector>

using string = std::string;

/*
�޸����� ������ �� �׸��� ����� �� �ְ� ������ å���� �ִ�.
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
��ũ�� ������ ���� ����� �޸����� �ƴ� PersistenceManager�� �ؾ��Ѵ�.
Journal�� �Լ��� ����� ���� ����� ����Ǹ� ��� �ٲ�� �ϱ� �����̴�.
*/
struct PersistenceManager {
    static void Save(const Journal& j, const string& filename) {
        std::ofstream ofs(filename);
        for (auto& s : j.entries) {
            ofs << s << std::endl;
        }
    }
};


