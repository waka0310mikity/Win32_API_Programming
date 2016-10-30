/*---------------------------------------------
Iphone2.cpp
-----------------------------------------------*/


#define _USE_MATH_DEFINES 
#include <windows.h> 
#include <tchar.h> 
#include <math.h> 


// �v���g�^�C�v�錾 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


// ���ϐ� 
static TCHAR szWindowClass[] = _T("iPhone2");
static TCHAR szTitle[] = _T("iPhone2");
HINSTANCE	hInst;


int window_pos_x = 100;
int window_pos_y = 20;
int window_width = 350;
int window_height = 690;


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR pCmdLine,
	int nCmdShow) {


	WNDCLASSEX wcex;


	// �E�B���h�E�N���X�̏���ݒ� 
	wcex.cbSize = sizeof(WNDCLASSEX);				// �\���̃T�C�Y 
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	// �X�^�C�� 
	wcex.lpfnWndProc = WndProc;							// �E�B���h�E�v���V�[�W�� 
	wcex.cbClsExtra = 0;									// �g�����P 
	wcex.cbWndExtra = 0;									// �g�����Q 
	wcex.hInstance = hInstance;							// �C���X�^���X�n���h�� 
	wcex.hIcon = (HICON)LoadImage(					// �A�C�R�� 
		NULL,
		IDI_APPLICATION,
		IMAGE_ICON,
		0,
		0,
		LR_DEFAULTSIZE | LR_SHARED
	);
	wcex.hIconSm = wcex.hIcon;							// �q�A�C�R�� 
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;							// ���j���[�� 
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);


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
		window_pos_x,								// �E�B���h�E��\������ʒu(X���W) 
		window_pos_y,								// �E�B���h�E��\������ʒu(Y���W) 
		window_width,								// �E�B���h�E�̕� 
		window_height,								// �E�B���h�E�̍��� 
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
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}


// �E�B���h�E�v���V�[�W�� 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC hDC;
	HBRUSH  hBrushBlack;
	HBRUSH  hBrushYellow;
	HBRUSH  hBrushWhite;
	PAINTSTRUCT ps;
	LPCTSTR STR1 = _T("i");
	LPCTSTR STR2 = _T("n");
	LPCTSTR STR3 = _T("f");
	LPCTSTR STR4 = _T("t");
	LPCTSTR STR5 = _T("y");
	static LOGFONT logfont;  //�t�H���g���̍\���� 
	HFONT hFont;
	int angle = 1;
	int m = 0;


	switch (message) {
	case WM_CREATE:
		ZeroMemory(&logfont, sizeof(logfont));	// �t�H���g���\���̂��O�ŏ����� 
		logfont.lfCharSet = DEFAULT_CHARSET;	// �V�X�e���̃f�t�H���g�����Z�b�g���g�� 
		wsprintf(logfont.lfFaceName, _T("Lucida Handwriting")); //�t�H���g���w��
		break;

	case WM_PAINT: {


		hDC = BeginPaint(hWnd, &ps);		// GDI�֐��ɂ��`����J�n���� 

		hBrushBlack = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hDC, hBrushBlack);
		RoundRect(hDC, 10, 10, 322, 643, 70, 80);  //iPhone�̊O�g
		Rectangle(hDC, 321, 120, 325, 170);  //iPhone�̓d���{�^��

		hBrushWhite = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hDC, hBrushWhite);
		Ellipse(hDC, 139, 579, 193, 633);  //iPhone�̒����{�^���O�g

		hBrushYellow = CreateSolidBrush(RGB(255, 255, 0));
		SelectObject(hDC, hBrushYellow);
		Rectangle(hDC, 29, 83, 303, 569);  //iPhone�̉�ʕ\��

		hBrushBlack = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hDC, hBrushBlack);
		Ellipse(hDC, 144, 584, 188, 628);  //iPhone�̒����{�^���̓��g


		/****  ������`�� ****/ 
		double x0 = 170;//���S��x���W
		double y0 = 310;//���S��y���W
		double x1, y1;//�ϐ�
		double a1 = 1.1;//���W�̕ω���
		double g = 0.6;//�����T�C�Y�̕ω���

		int i = 1;
		MoveToEx(hDC, x0, y0, NULL);     //�J�n�_�Ɉړ� 
		for (double theta = 40.2; theta < 90; theta += 0.2) {

			while (angle >= 0) {
				hFont = CreateFontIndirect(&logfont);

				SelectObject(hDC, hFont);

				logfont.lfHeight = theta*g -5;   //�����̑傫�����w�� 
				g *= 1.01;


				x1 = pow(a1, theta)*cos(theta) + x0;       //x���W��ݒ� 
				y1 = pow(a1, theta)*sin(theta) + y0;       //y���W��ݒ� 


				/**** 2�_����p�x�����߂� ****/
				double dx = x0 - x1;
				double dy = y0 - y1;
				double radian = atan2(dx, dy);
				radian = radian*(180 / M_PI) * 10;


				logfont.lfEscapement = radian;     //�����ɌX����t���� 

				if (m == 0) { //���ڂ���for���[�v��break
					m = 1;
					break;
				}

				if ((x1 >= 10 && x1 <= 310) && (y1 >= 50 && y1 <= 600)) {  //�g���̂ݗ�����`�� 
					SetBkMode(hDC, TRANSPARENT);      //�e�L�X�g�̔w�i�𓧖��ɂ��� 
					while (i < 9) {
						switch (i) {
						case 1:
						case 4:
						case 6:
							TextOut(hDC, x1, y1, STR1, _tcslen(STR1));//�ui�v�̕\��
							break;
						case 2:
						case 5:
							TextOut(hDC, x1, y1, STR2, _tcslen(STR2));//�un�v�̕\��
							break;
						case 3:
							TextOut(hDC, x1, y1, STR3, _tcslen(STR3));//�uf�v�̕\��
							break;
						case 7:
							TextOut(hDC, x1, y1, STR4, _tcslen(STR4));//�ut�v�̕\��
							break;
						case 8:
							TextOut(hDC, x1, y1, STR5, _tcslen(STR5));//�uy�v�̕\��
							i = 0;
							break;


						}
						i++;
						break;


					}


					DeleteObject(hFont); 					// �쐬�����_���t�H���g���폜���� 
				}
				break;
			}

		}

		SelectObject(hDC, hBrushBlack);
		Ellipse(hDC, 144, 584, 188, 628);            //�{�^���̓��� 




		EndPaint(hWnd, &ps);				// GDI�֐��ɂ��`����I������ 
	}break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	default:
		return DefWindowProc(hWnd, message, wParam, lParam);  		break;
	}
	return 0;
}