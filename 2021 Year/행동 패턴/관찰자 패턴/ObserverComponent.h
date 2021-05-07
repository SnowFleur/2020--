#pragma once
#include<vector>
#include<iostream>>
//상속이 아닌 컴포넌트로 옵저버를 가지고 있음

enum class EVENT {
    FIRST_STEP = 1, PLAY_TIME,
};

//옵저버 인터페이스
class ObserverComponent {
public:
    virtual void FirstStep() = 0;
    virtual void AchievePlayTime() = 0;
};

//World 클래스가 가지는 컴포넌트
class WorldObserverComponent :public ObserverComponent {
public:
    void FirstStep()override {

    }
    void AchievePlayTime() override {

    }
};


//클라이언트 클래스가 컴포넌트
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