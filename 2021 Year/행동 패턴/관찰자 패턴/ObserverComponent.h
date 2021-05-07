#pragma once
#include<vector>
#include<iostream>>
//����� �ƴ� ������Ʈ�� �������� ������ ����

enum class EVENT {
    FIRST_STEP = 1, PLAY_TIME,
};

//������ �������̽�
class ObserverComponent {
public:
    virtual void FirstStep() = 0;
    virtual void AchievePlayTime() = 0;
};

//World Ŭ������ ������ ������Ʈ
class WorldObserverComponent :public ObserverComponent {
public:
    void FirstStep()override {

    }
    void AchievePlayTime() override {

    }
};


//Ŭ���̾�Ʈ Ŭ������ ������Ʈ
class ClinetObServerComponent {
private:
    std::vector< ObserverComponent*> listeners_;
public:
    void SubScribe(ObserverComponent* listener) {
        listeners_.push_back(listener);
    }

    void UnSubScribe(ObserverComponent* listener) {

        listeners_.erase(
            listeners_.begin(), std::remove(listeners_.begin(), listeners_.end(), listener));
    }

    void Notify(const EVENT& e) {

        switch (e) {
        case EVENT::FIRST_STEP: {
            for (auto listener : listeners_) {
                listener->FirstStep();
            }
            break;
        }
        case EVENT::PLAY_TIME: {
            for (auto listener : listeners_) {
                listener->AchievePlayTime();
            }
            break;
        }
        default:
            break;
        }

    }

};