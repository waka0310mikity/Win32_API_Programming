/*---------------------------------------------
	Win32AP071.cpp
-----------------------------------------------*/

#include <windows.h>
#include <tchar.h>
#include "resource.h"

#define WINDOW_X			(10)
#define WINDOW_Y			(10)
#define WINDOW_WIDTH		(432)		// �E�B���h�E�̕�
#define WINDOW_HEIGHT		(913)		// �E�B���h�E�̍���

// �v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// ���ϐ�
static TCHAR szWindowClass[] = _T("iPhone");
static TCHAR szTitle[] = _T("iPhone");
HINSTANCE	hInst;
HWND FView_hWnd = 0;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR pCmdLine,
	int nCmdShow) {

		WNDCLASSEX wcex;

		// �E�B���h�E�N���X�̏���ݒ�
		wcex.cbSize 		= sizeof(WNDCLASSEX);				// �\���̃T�C�Y
		wcex.style 		= CS_HREDRAW | CS_VREDRAW;		// �X�^�C��
		wcex.lpfnWndProc	= WndProc;							// �E�B���h�E�v���V�[�W��
		wcex.cbClsExtra 	= 0;									// �g�����P
		wcex.cbWndExtra = 0;									// �g�����Q
		wcex.hInstance 	= hInstance;							// �C���X�^���X�n���h��
		wcex.hIcon 		= (HICON)LoadImage(					// �A�C�R��
			NULL,
			MAKEINTRESOURCE(IDI_APPLICATION),
			IMAGE_ICON,
			0,
			0,
			LR_DEFAULTSIZE | LR_SHARED
			);
		wcex.hIconSm 	= wcex.hIcon;							// �q�A�C�R��
		wcex.hCursor 	= LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 
		wcex.lpszMenuName = NULL;							// ���j���[��
		wcex.lpszClassName = szWindowClass;
		wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

		// �E�B���h�E�N���X��o�^����
		if (!RegisterClassEx(&wcex)) {
			MessageBox(NULL,
				_T("�E�B���h�E�̓o�^�Ɏ��s���܂���"),
				_T("�E�B���h�E�̓o�^�G���["),
				NULL);
			return 1;
		}

		hInst = hInstance; // �C���X�^���X��n���h������ϐ��Ɋi�[

		// �E�B���h�E���쐬����
		HWND hWnd = CreateWindow(
			szWindowClass,					// �E�B���h�E�N���X��
			szTitle,							// �^�C�g���o�[�ɕ\�����镶����
			WS_OVERLAPPEDWINDOW,		// �E�B���h�E�̎��
			WINDOW_X,						// �E�B���h�E��\������ʒu(X���W)
			WINDOW_Y,						// �E�B���h�E��\������ʒu(Y���W)
			WINDOW_WIDTH,				// �E�B���h�E�̕�
			WINDOW_HEIGHT,				// �E�B���h�E�̍���
			NULL,							// �e�E�B���h�E�̃E�B���h�E�n���h��
			NULL,							// ���j���[�n���h��
			hInst,							// �C���X�^���X�n���h��
			NULL							// ���̑��̍쐬�f�[�^
			);

		if (!hWnd) {
			MessageBox(NULL,
				_T("�E�B���h�E�̍쐬�Ɏ��s���܂���"),
				_T("�E�B���h�E�̍쐬�G���["),
				NULL);
			return 1;
		}

		// �E�B���h�E��\������
		ShowWindow(hWnd, nCmdShow);
		UpdateWindow(hWnd);

		// ���b�Z�[�W����[�v
		MSG msg;
		while(GetMessage(&msg, NULL, 0, 0)) {	
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return (int)msg.wParam;
}




// �E�B���h�E�v���V�[�W��
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
HBRUSH bkColorBrush=CreateSolidBrush(RGB(0,0,0));//�w�i�F�̃u���V��p�ӂ���

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
	case WM_CTLCOLORDLG://�_�C�A���O�̔w�i�F
		return (LRESULT)bkColorBrush;
		break;
	case WM_COMMAND:		// �_�C�A���O�{�b�N�X���̉������I�����ꂽ�Ƃ�
		switch(LOWORD(wParam)) {
		case IDC_BUTTON1:
			MessageBox(NULL, _T("Safari��������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON2:
			MessageBox(NULL, _T("�J�����_�[��������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON3:
			MessageBox(NULL, _T("���v��������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON4:
			MessageBox(NULL, _T("���b�Z�[�W��������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON5:
			MessageBox(NULL, _T("�d�삪������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON6:
			MessageBox(NULL, _T("������������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON7:
			MessageBox(NULL, _T("iPod��������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON8:
			MessageBox(NULL, _T("���[����������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON9:
			MessageBox(NULL, _T("�d�b��������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON10:
			MessageBox(NULL, _T("������������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON11:
			MessageBox(NULL, _T("�}�b�v��������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON12:
			MessageBox(NULL, _T("�J������������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON13:
			MessageBox(NULL, _T("SMS��������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON14:
			MessageBox(NULL, _T("�ݒ肪������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON15:
			MessageBox(NULL, _T("�ʐ^��������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON16:
			MessageBox(NULL, _T("�V�C��������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		case IDC_BUTTON17:
			MessageBox(NULL, _T("�z�[���{�^����������܂����D"), _T("���b�Z�[�W"), MB_OK);
			break;
		}
	default:
		return (DefWindowProc(hWnd, message, wParam, lParam));
	}
	return 0;
}
