#pragma once
#include<stack>
#include"GameActor.h"


class Command {
private:
public:
	virtual void Excute() = 0;
	virtual void Undo() = 0;
	virtual ~Command() {};
};

class MoveUnitCommand : public Command {
private:
	GameActor*	    actor_;
	int				x_;
	int				y_;
	int				xBefore_;
	int				yBefore_;
public:
	MoveUnitCommand(GameActor* actor, int x, int y):
		actor_(actor),x_(x),y_(y),
		xBefore_(0),yBefore_(0) {}

	virtual void Excute() {
		//나중에 이동을 취소할 수 있또록 before변수에 저장을 한다.
		actor_->GetActorPosition(xBefore_, yBefore_);
		actor_->Move(x_, y_);
	}
	virtual void Undo() {
		actor_->SetActorPosition(xBefore_, yBefore_);
	}
	GameActor* GetActorInstance() {
		if(actor_!=nullptr)
		return actor_;
	}
};



