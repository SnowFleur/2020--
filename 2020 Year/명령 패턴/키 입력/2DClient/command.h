#pragma once
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 
#endif

//defined key
#define KEY_W 0x57
#define KEY_A 0x41
#define KEY_D 0x44
#define KEY_S 0x53
//defeind command
#define CROUCH	0
#define FIRE	1
#define JUMP	2
#define RUN		3
#include<iostream>
class Command {
private:
public:
	virtual void Excute() = 0;
	virtual ~Command() {};
};

class FireCommand :public Command {
	virtual void Excute() {
		Fire();
	}
	void Fire() {
		std::cout << "Fire\n";
	}
};

class JumpCommand :public Command {
	virtual void Excute() {
		Jump();
	}
	void Jump() {
		std::cout << "Jump\n";
	}
};

class CrouchCommand :public Command {
	virtual void Excute() {
		Crouch();
	}
	void Crouch() {
		std::cout << "Crouch\n";
	}
};

class RunCommand :public Command {
	virtual void Excute() {
		Run();
	}
	void Run() {
		std::cout << "Run\n";
	}
};

class InputHandler {
private:
	Command* button_w;
	Command* button_a;
	Command* button_s;
	Command* button_d;
public:
	InputHandler() {
		button_w = new FireCommand();
		button_a = new JumpCommand();
		button_s = new CrouchCommand();
		button_d = new RunCommand();
	}

	void HandleInput(WPARAM key) {
		switch (key) {
		case KEY_D: {
			std::cout << "KEY_D:  ";
			button_d->Excute();
			break;
		}
		case KEY_A: {
			std::cout << "KEY_A:  ";
			button_a->Excute();
			break;
		}
		case KEY_W: {
			std::cout << "KEY_W:  ";
			button_w->Excute();
			break;
		}
		case KEY_S: {
			std::cout << "KEY_S:  ";
			button_s->Excute();
			break;
		}
		default:
			break;
		}
	}

	void ChangleInputHandle(int key, int command) {

		switch (key) {
		case KEY_W: {
			delete button_w;
			button_w = ChangedCommand(command);
			break;
		}
		case KEY_A: {
			delete button_a;
			button_a = ChangedCommand(command);
			break;
		}
		case KEY_S: {
			delete button_s;
			button_s = ChangedCommand(command);
			break;
		}
		case KEY_D: {
			delete button_d;
			button_d = ChangedCommand(command);
			break;
		}
		default:
			while (1) {
			std::cout << "Error: not defined key \n";
			}
			break;
		}
		std::cout << "===== Changed Key===== \n\n";

	}

	Command* ChangedCommand(int command) {
		switch (command) {
		case CROUCH: {
			return new CrouchCommand();
			break;
		}
		case FIRE: {
			return new FireCommand();
			break;
		}
		case JUMP: {
			return new JumpCommand();
			break;
		}
		case RUN: {
			return new RunCommand();
			break;
		}
		default:
			while (1) {
			std::cout << "Error: not defined command \n";
			}
			break;
		}
	}
};

