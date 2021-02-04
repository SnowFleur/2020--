// Client.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
#include "stdafx.h"
#include "Client.h"
#include"command.h"
#include"GameActor.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
InputHandler* g_inputHandle = new InputHandler;
int x{ 82 }, y{ 45 };


// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
LRESULT	CALLBACK	KeyDiaProc(HWND, UINT, WPARAM, LPARAM);

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

LRESULT CALLBACK KeyDiaProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){

	static HWND hWkeyHandle;
	static HWND hAkeyHandle;
	static HWND hSkeyHandle;
	static HWND hDkeyHandle;

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:{
		//W ComboBox Edit
		hWkeyHandle = GetDlgItem(hDlg, IDC_COMBO_W);
		SendMessage(hWkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Fire"));
		SendMessage(hWkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Jump"));
		SendMessage(hWkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Crouch"));
		SendMessage(hWkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Run"));
		//A ComboBox Edit
		hAkeyHandle = GetDlgItem(hDlg, IDC_COMBO_A);
		SendMessage(hAkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Fire"));
		SendMessage(hAkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Jump"));
		SendMessage(hAkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Crouch"));
		SendMessage(hAkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Run"));
		//S ComboBox Edit
		hSkeyHandle = GetDlgItem(hDlg, IDC_COMBO_S);
		SendMessage(hSkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Fire"));
		SendMessage(hSkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Jump"));
		SendMessage(hSkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Crouch"));
		SendMessage(hSkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Run"));
		//D ComboBox Edit
		hDkeyHandle = GetDlgItem(hDlg, IDC_COMBO_D);
		SendMessage(hDkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Fire"));
		SendMessage(hDkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Jump"));
		SendMessage(hDkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Crouch"));
		SendMessage(hDkeyHandle, CB_ADDSTRING, NULL, (LPARAM)TEXT("Run"));
	}
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK) {
			int resultW = SendMessage(hWkeyHandle, CB_GETCURSEL, NULL, NULL);
			int resultA = SendMessage(hAkeyHandle, CB_GETCURSEL, NULL, NULL);
			int resultS = SendMessage(hSkeyHandle, CB_GETCURSEL, NULL, NULL);
			int resultD = SendMessage(hDkeyHandle, CB_GETCURSEL, NULL, NULL);

			g_inputHandle->ChangleInputHandle(KEY_W, resultW);
			g_inputHandle->ChangleInputHandle(KEY_A, resultA);
			g_inputHandle->ChangleInputHandle(KEY_S, resultS);
			g_inputHandle->ChangleInputHandle(KEY_D, resultD);

			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == IDCANCEL) {
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	
	switch (message) {
	case WM_COMMAND:{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALKEY), hWnd, KeyDiaProc);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;

	case WM_KEYDOWN: {
		KeyInput(wParam);

		InvalidateRgn(hWnd, NULL, FALSE);
		break;
	}
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		HBITMAP hbitmap, hbitmap2;
		HDC hMemDc;
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		hbitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		hbitmap2 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));


		hMemDc = CreateCompatibleDC(hdc);
		SelectObject(hMemDc, hbitmap);

		BitBlt(hdc, 0, 0, 700, 700, hMemDc, 0, 0, SRCCOPY);
		SelectObject(hMemDc, hbitmap2);
		TransparentBlt(hdc,x,y, 37, 62, hMemDc, 00, 0, 37, 62, RGB(255, 255, 255));


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
	g_inputHandle->HandleInput(key);
}

