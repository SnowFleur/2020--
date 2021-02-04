#pragma once

class GameActor {
private:
	int			x_;
	int			y_;
public:
	GameActor() {};
	GameActor(int x, int y):x_(x),y_(y) {}


	void SetActorPosition(int x, int y) {
		x_ = x;
		y_ = y;
	}
	void GetActorPosition(int& x, int& y) {
		x = x_;
		y = y_;
	}
	void Move(int x, int y) {
		x_ = x;
		y_ = y;
	}

};


