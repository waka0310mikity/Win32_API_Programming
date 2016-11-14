/*------------------------------------------------------------------------
Win32CP034.cpp		 Discovery�𓮂���
---------------------------------------------------------------------------*/

#include <windows.h>
#include <tchar.h>

#define	ID_MYTIMER	(32767)
#define	ID_MYCHILD	(100)
#define	CHD_WIDTH	(100)
#define	CHD_HEIGHT	(60)

// �v���g�^�C�v�錾
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
		szTitle,						//�^�C�g���o�[�ɂ��̖��O���\������܂�
		WS_OVERLAPPEDWINDOW,	//�E�B���h�E�̎��
		10,			//�w���W�@�K�X�w�肷��
		10,			//�x���W�@�K�X�w�肷��
		700,			//��	�@�K�X�w�肷��
		400,			//����	�@�K�X�w�肷��
		NULL,						//�e�E�B���h�E�̃n���h���A�e�����Ƃ���NULL
		NULL,			//���j���[�n���h���A�N���X���j���[���g���Ƃ���NULL
		hInst,			//�C���X�^���X�n���h��
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


		hDC = BeginPaint(hWnd, &ps);		// GDI�֐��ɂ��`����J�n���� 

		hBrushBlack = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hDC, hBrushBlack);
		RoundRect(hDC, 10, 10, 643, 322, 80, 70);  //iPhone�̊O�g
		Rectangle(hDC, 120, 6, 170, 10);  //iPhone�̓d���{�^��
		Rectangle(hDC, 85, 321, 110, 325);               //�}�i�[���[�hON/OFF�L�[
		Rectangle(hDC, 135, 321, 185, 325);               //���ʁ{�{�^��
		Rectangle(hDC, 200, 321, 250, 325);               //���ʁ|�{�^��

		hBrushWhite = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hDC, hBrushWhite);
		Ellipse(hDC, 25, 162, 33, 170);              //�����㕔�̊�
		Ellipse(hDC, 35, 221, 50, 236);              //�����㕔���̊�
		RoundRect(hDC, 39, 100, 46, 207, 80, 10);
		Ellipse(hDC, 579, 139, 633, 193);  //iPhone�̒����{�^���O�g

		hBrushYellow = CreateSolidBrush(RGB(255, 255, 0));
		SelectObject(hDC, hBrushYellow);
		Rectangle(hDC, 83, 29, 569, 303);  //iPhone�̉�ʕ\��

		hBrushBlack = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hDC, hBrushBlack);
		Ellipse(hDC, 584, 144, 628, 188);  //iPhone�̒����{�^���̓��g
	}
	}

	switch (message) {
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		InitApp(hInst, ChdProc, szchClassName);

		hChdWnd = CreateWindow(
			szchClassName,			// �E�B���h�E�N���X��
			NULL,					// �^�C�g���o�[�ɕ\�����镶����
			WS_CHILD,				// �E�B���h�E�̎��
			83,						// �E�B���h�E��\������ʒu(X���W�j
			29,						// �E�B���h�E��\������ʒu(Y���W�j
			CHD_WIDTH,			// �E�B���h�E�̕�
			CHD_HEIGHT,			// �E�B���h�E�̍���
			hWnd,					// �e�E�B���h�E�̃E�B���h�E�n���h��
			(HMENU)ID_MYCHILD,	// ���j���[�n���h��
			hInst,					// �C���X�^���X�n���h��
			NULL					// ���̑��̍쐬�f�[�^
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
				_T("�r�b�g�}�b�v�̃��[�h�Ɏ��s���܂���"),
				_T("�G���["),
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
