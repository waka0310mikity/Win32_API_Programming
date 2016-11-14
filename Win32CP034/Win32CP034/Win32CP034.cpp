/*------------------------------------------------------------------------
Win32CP034.cpp		 Discoveryを動かす
---------------------------------------------------------------------------*/

#include <windows.h>
#include <tchar.h>

#define	ID_MYTIMER	(32767)
#define	ID_MYCHILD	(100)
#define	CHD_WIDTH	(100)
#define	CHD_HEIGHT	(60)

// プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChdProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

BOOL InitApp(HINSTANCE, WNDPROC, LPCTSTR);
BOOL InitInstance(HINSTANCE, int, LPCTSTR);

static TCHAR szClassName[] = _T("Win32CP034");
static TCHAR szchClassName[] = _T("child");
static TCHAR szTitle[] = _T("SSN Enterprise");

int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE hPrevInst, LPSTR lpsCmdLine, int nCmdShow) {
	MSG msg;

	if (!hPrevInst) {
		if (!InitApp(hCurInst, WndProc, szClassName)) {
			return FALSE;
		}
	}
	if (!InitInstance(hCurInst, nCmdShow, szClassName)) {
		return FALSE;
	}
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

BOOL InitApp(HINSTANCE hInst, WNDPROC WndProc, LPCTSTR szClassName) {
	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;

	return (RegisterClass(&wc));
}


BOOL InitInstance(HINSTANCE hInst, int nCmdShow, LPCTSTR szClassName) {
	HWND hWnd;

	hWnd = CreateWindow(
		szClassName,
		szTitle,						//タイトルバーにこの名前が表示されます
		WS_OVERLAPPEDWINDOW,	//ウィンドウの種類
		10,			//Ｘ座標　適宜指定する
		10,			//Ｙ座標　適宜指定する
		700,			//幅	　適宜指定する
		400,			//高さ	　適宜指定する
		NULL,						//親ウィンドウのハンドル、親を作るときはNULL
		NULL,			//メニューハンドル、クラスメニューを使うときはNULL
		hInst,			//インスタンスハンドル
		NULL);

	if (!hWnd) {
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	RECT		rc;
	static int 	x;
	static int 	y;
	static int 	direction;
	static HWND		hChdWnd;
	HINSTANCE		hInst;
	enum { right, left };
	HDC hDC;
	HBRUSH  hBrushBlack;
	HBRUSH  hBrushYellow;
	HBRUSH  hBrushWhite;
	PAINTSTRUCT	ps;

	switch (message) {
	case WM_PAINT: {


		hDC = BeginPaint(hWnd, &ps);		// GDI関数による描画を開始する 

		hBrushBlack = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hDC, hBrushBlack);
		RoundRect(hDC, 10, 10, 643, 322, 80, 70);  //iPhoneの外枠
		Rectangle(hDC, 120, 6, 170, 10);  //iPhoneの電顕ボタン
		Rectangle(hDC, 85, 321, 110, 325);               //マナーモードON/OFFキー
		Rectangle(hDC, 135, 321, 185, 325);               //音量＋ボタン
		Rectangle(hDC, 200, 321, 250, 325);               //音量－ボタン

		hBrushWhite = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hDC, hBrushWhite);
		Ellipse(hDC, 25, 162, 33, 170);              //中央上部の丸
		Ellipse(hDC, 35, 221, 50, 236);              //中央上部下の丸
		RoundRect(hDC, 39, 100, 46, 207, 80, 10);
		Ellipse(hDC, 579, 139, 633, 193);  //iPhoneの中央ボタン外枠

		hBrushYellow = CreateSolidBrush(RGB(255, 255, 0));
		SelectObject(hDC, hBrushYellow);
		Rectangle(hDC, 83, 29, 569, 303);  //iPhoneの画面表示

		hBrushBlack = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hDC, hBrushBlack);
		Ellipse(hDC, 584, 144, 628, 188);  //iPhoneの中央ボタンの内枠
	}
	}

	switch (message) {
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		InitApp(hInst, ChdProc, szchClassName);

		hChdWnd = CreateWindow(
			szchClassName,			// ウィンドウクラス名
			NULL,					// タイトルバーに表示する文字列
			WS_CHILD,				// ウィンドウの種類
			83,						// ウィンドウを表示する位置(X座標）
			29,						// ウィンドウを表示する位置(Y座標）
			CHD_WIDTH,			// ウィンドウの幅
			CHD_HEIGHT,			// ウィンドウの高さ
			hWnd,					// 親ウィンドウのウィンドウハンドル
			(HMENU)ID_MYCHILD,	// メニューハンドル
			hInst,					// インスタンスハンドル
			NULL					// その他の作成データ
		);

		ShowWindow(hChdWnd, SW_SHOW);
		UpdateWindow(hChdWnd);

		SetTimer(hWnd, ID_MYTIMER, 10, NULL);
		break;

	case WM_TIMER:
		GetClientRect(hWnd, &rc);
		MoveWindow(hChdWnd, x, y, CHD_WIDTH, CHD_HEIGHT, TRUE);

		switch (direction) {
		case right:
			x += 10;
			y += 2;
			if (x >= 569 - CHD_WIDTH)
				direction = left;
			break;

		case left:
			x -= 10;
			y -= 2;
			if (y <= 29)
				direction = right;
			break;

		 
		}
		break;

	case WM_DESTROY:
		KillTimer(hWnd, ID_MYTIMER);
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}






LRESULT CALLBACK ChdProc(HWND hChdWnd, UINT message, WPARAM wParam, LPARAM lParam) {
		HDC hDC;
		static HBITMAP	hBitmap;
		static HBITMAP	hPrevBitmap;
		HINSTANCE		hInst;
		PAINTSTRUCT	ps;
		HDC			hCompatDC;

	switch (message) {

	case WM_PAINT: {
		hInst = (HINSTANCE)GetWindowLong(hChdWnd, GWL_HINSTANCE);

		hBitmap = (HBITMAP)LoadImage(
			hInst,
			_T("Discovery2.bmp"),
			IMAGE_BITMAP,
			0,
			0,
			LR_LOADFROMFILE);

		if (hBitmap == NULL) {
			MessageBox(
				hChdWnd,
				_T("ビットマップのロードに失敗しました"),
				_T("エラー"),
				MB_OK | MB_ICONWARNING
			);
			return 0;
		}

		hDC = BeginPaint(hChdWnd, &ps);
		hCompatDC = CreateCompatibleDC(hDC);
		SelectObject(hCompatDC, hBitmap);

		BitBlt(hDC, 0, 0, CHD_WIDTH, CHD_HEIGHT, hCompatDC, 0, 0, SRCCOPY);

		DeleteDC(hCompatDC);
		DeleteObject(hBitmap);
		EndPaint(hChdWnd, &ps);
		break;

	default:
		return(DefWindowProc(hChdWnd, message, wParam, lParam));
	}
				   return 0;
	}
}
