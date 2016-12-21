/*---------------------------------------------
	Win32AP071.cpp
-----------------------------------------------*/

#include <windows.h>
#include <tchar.h>
#include "resource.h"

#define WINDOW_X			(10)
#define WINDOW_Y			(10)
#define WINDOW_WIDTH		(432)		// ウィンドウの幅
#define WINDOW_HEIGHT		(913)		// ウィンドウの高さ

// プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// 大域変数
static TCHAR szWindowClass[] = _T("iPhone");
static TCHAR szTitle[] = _T("iPhone");
HINSTANCE	hInst;
HWND FView_hWnd = 0;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR pCmdLine,
	int nCmdShow) {

		WNDCLASSEX wcex;

		// ウィンドウクラスの情報を設定
		wcex.cbSize 		= sizeof(WNDCLASSEX);				// 構造体サイズ
		wcex.style 		= CS_HREDRAW | CS_VREDRAW;		// スタイル
		wcex.lpfnWndProc	= WndProc;							// ウィンドウプロシージャ
		wcex.cbClsExtra 	= 0;									// 拡張情報１
		wcex.cbWndExtra = 0;									// 拡張情報２
		wcex.hInstance 	= hInstance;							// インスタンスハンドル
		wcex.hIcon 		= (HICON)LoadImage(					// アイコン
			NULL,
			MAKEINTRESOURCE(IDI_APPLICATION),
			IMAGE_ICON,
			0,
			0,
			LR_DEFAULTSIZE | LR_SHARED
			);
		wcex.hIconSm 	= wcex.hIcon;							// 子アイコン
		wcex.hCursor 	= LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 
		wcex.lpszMenuName = NULL;							// メニュー名
		wcex.lpszClassName = szWindowClass;
		wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

		// ウィンドウクラスを登録する
		if (!RegisterClassEx(&wcex)) {
			MessageBox(NULL,
				_T("ウィンドウの登録に失敗しました"),
				_T("ウィンドウの登録エラー"),
				NULL);
			return 1;
		}

		hInst = hInstance; // インスタンス･ハンドルを大域変数に格納

		// ウィンドウを作成する
		HWND hWnd = CreateWindow(
			szWindowClass,					// ウィンドウクラス名
			szTitle,							// タイトルバーに表示する文字列
			WS_OVERLAPPEDWINDOW,		// ウィンドウの種類
			WINDOW_X,						// ウィンドウを表示する位置(X座標)
			WINDOW_Y,						// ウィンドウを表示する位置(Y座標)
			WINDOW_WIDTH,				// ウィンドウの幅
			WINDOW_HEIGHT,				// ウィンドウの高さ
			NULL,							// 親ウィンドウのウィンドウハンドル
			NULL,							// メニューハンドル
			hInst,							// インスタンスハンドル
			NULL							// その他の作成データ
			);

		if (!hWnd) {
			MessageBox(NULL,
				_T("ウィンドウの作成に失敗しました"),
				_T("ウィンドウの作成エラー"),
				NULL);
			return 1;
		}

		// ウィンドウを表示する
		ShowWindow(hWnd, nCmdShow);
		UpdateWindow(hWnd);

		// メッセージ･ループ
		MSG msg;
		while(GetMessage(&msg, NULL, 0, 0)) {	
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return (int)msg.wParam;
}




// ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch(message) {
	case WM_CREATE:
		FView_hWnd = CreateDialog(
			GetModuleHandle(NULL),
			MAKEINTRESOURCE(IDD_FORMVIEW),
			hWnd, 
			(DLGPROC)DlgProc);
		ShowWindow(FView_hWnd, SW_SHOW);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

HBITMAP hBmp;
HBRUSH bkColorBrush=CreateSolidBrush(RGB(0,0,0));//背景色のブラシを用意する

LRESULT CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message){
	case WM_PAINT:
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		SendDlgItemMessage(hWnd, IDC_BUTTON1, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
		SendDlgItemMessage(hWnd, IDC_BUTTON2, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP3));
		SendDlgItemMessage(hWnd, IDC_BUTTON3, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP4));
		SendDlgItemMessage(hWnd, IDC_BUTTON4, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP5));
		SendDlgItemMessage(hWnd, IDC_BUTTON5, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP6));
		SendDlgItemMessage(hWnd, IDC_BUTTON6, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP7));
		SendDlgItemMessage(hWnd, IDC_BUTTON7, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP8));
		SendDlgItemMessage(hWnd, IDC_BUTTON8, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP9));
		SendDlgItemMessage(hWnd, IDC_BUTTON9, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP10));
		SendDlgItemMessage(hWnd, IDC_BUTTON10, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP11));
		SendDlgItemMessage(hWnd, IDC_BUTTON11, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP12));
		SendDlgItemMessage(hWnd, IDC_BUTTON12, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP13));
		SendDlgItemMessage(hWnd, IDC_BUTTON13, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP14));
		SendDlgItemMessage(hWnd, IDC_BUTTON14, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP15));
		SendDlgItemMessage(hWnd, IDC_BUTTON15, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP16));
		SendDlgItemMessage(hWnd, IDC_BUTTON16, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP17));
		SendDlgItemMessage(hWnd, IDC_BUTTON17, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);
		break;
	case WM_CTLCOLORDLG://ダイアログの背景色
		return (LRESULT)bkColorBrush;
		break;
	case WM_COMMAND:		// ダイアログボックス内の何かが選択されたとき
		switch(LOWORD(wParam)) {
		case IDC_BUTTON1:
			MessageBox(NULL, _T("Safariが押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON2:
			MessageBox(NULL, _T("カレンダーが押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON3:
			MessageBox(NULL, _T("時計が押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON4:
			MessageBox(NULL, _T("メッセージが押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON5:
			MessageBox(NULL, _T("電卓が押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON6:
			MessageBox(NULL, _T("株価が押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON7:
			MessageBox(NULL, _T("iPodが押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON8:
			MessageBox(NULL, _T("メールが押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON9:
			MessageBox(NULL, _T("電話が押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON10:
			MessageBox(NULL, _T("メモが押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON11:
			MessageBox(NULL, _T("マップが押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON12:
			MessageBox(NULL, _T("カメラが押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON13:
			MessageBox(NULL, _T("SMSが押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON14:
			MessageBox(NULL, _T("設定が押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON15:
			MessageBox(NULL, _T("写真が押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON16:
			MessageBox(NULL, _T("天気が押されました．"), _T("メッセージ"), MB_OK);
			break;
		case IDC_BUTTON17:
			MessageBox(NULL, _T("ホームボタンが押されました．"), _T("メッセージ"), MB_OK);
			break;
		}
	default:
		return (DefWindowProc(hWnd, message, wParam, lParam));
	}
	return 0;
}
