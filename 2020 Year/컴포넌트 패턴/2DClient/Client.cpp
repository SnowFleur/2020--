// Client.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//


#include "stdafx.h"
#include "Client.h"
//Componenct Patterns
#include"define.h"
#include"Controller.h"
#include"GameObject.h"
#include"Texture.h"
#include"Render.h"
#include"PlayerInputComponent.h"
#include"GameObjectGraphicsComponent.h"
#define MAX_LOADSTRING 100


// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
GameObject* g_player;
Render*		g_render;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 여기에 코드를 입력합니다.

	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_CLIENT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));

	MSG msg;

	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CLIENT);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 720, 750, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


int x = 82;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	
	static HDC hdc;
    PAINTSTRUCT ps;
	static HBITMAP hbitmap;

	switch (message) {
    case WM_CREATE: {
        HBITMAP hbitmap2;

        hbitmap2 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
        hbitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		Texture* texture = new Texture(hbitmap2, 37, 62, 0, 0, 37, 62);

        g_player = new GameObject(new PlayerInputComponent, new GameObjectGraphicsComponent(texture));
        g_render = new Render();
        break;
    }
	case WM_KEYDOWN: {
		KeyInput(wParam);
		InvalidateRgn(hWnd, NULL, TRUE);
		break;
	}
    case WM_PAINT: {
		HDC hdc = BeginPaint(hWnd, &ps);
		HDC hMemDc = CreateCompatibleDC(hdc);

		//배경
        SelectObject(hMemDc, hbitmap);
        BitBlt(hdc, 0, 0, 700, 700, hMemDc, 0, 0, SRCCOPY);
		DeleteDC(hMemDc);

		g_render->GetHDC(hdc);
		g_player->Update(*g_render);


		EndPaint(hWnd, &ps);
        break;
    }
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


void KeyInput(WPARAM key) {
    switch (key) {
    case VK_RIGHT:
        Controller::SetDirection(DIR_RIGHT);
		x += 72;
        break;
    case VK_LEFT:
        Controller::SetDirection(DIR_LEFT);
        break;
    case VK_UP:
        Controller::SetDirection(DIR_UP);
        break;
    case VK_DOWN:
        Controller::SetDirection(DIR_DOWN);
        break;
    default:
        break;
    }
}

