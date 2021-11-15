// Sceleton.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Sceleton.h" // ����� ������������ resource.h

char name[] = "Qwerty"; // ���������� ��� ����������� ����

// ��������� �� ������ ������� �������� ����������
HINSTANCE hInst; // ���������, ������ �������, � ������� �� �� �������� � ������

int APIENTRY WinMain(HINSTANCE hInstance, // ������� ����������
					 HINSTANCE, // �������� ����� ���� (�� ���������� ��������)
					 LPSTR     lpCmdLine, // ��������� ������
					 int       nCmdShow) // ��� ����
{
	hInst = hInstance; // �������� ����� ��������
	//// 1. �������� �������� ���� ����
	//WNDCLASS win; // ������ ��� ���������� �� ����
	//win.style = CS_HREDRAW | CS_VREDRAW; // ����� �����������
	//win.lpfnWndProc = WFunc; // ��� (��������) ������� �������, ������ ��������������� ����� ������� 
	//win.cbClsExtra = win.cbWndExtra = 0; // ������ = 0
	//win.hInstance = hInstance; // ��� ����������, � �������� ��������� ����
	//win.hIcon = LoadIcon(NULL, IDI_ASTERISK); // ������, ������������� ������ ID_APPLIKATION
	//win.hCursor = LoadCursor(NULL, IDC_ARROW); // ������
	//win.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ���� ����
	//win.lpszMenuName = NULL; // ���� �����������
	//win.lpszClassName = name; // ��� ��� ����������� = qwerty

	//// 2. ����������� ���� � ������������ �������
	//if (!RegisterClass(&win))
	//{
	//	MessageBox(NULL, "���� �� ����������������", "������", MB_OK);
	//	return -1; // ���� ���� �� ����������������
	//}

	//// 3. �������� ����
	//HWND hWnd; // ���������� �������� ����
	//hWnd = CreateWindow(name, "������ ����", WS_OVERLAPPEDWINDOW/*|WS_VISIBLE*/, 50, 50,
	//					500, 500, HWND_DESKTOP, NULL, hInstance, NULL); // �������� �������� ����

	//// HWND_DESKTOP - ������������ ������� �������� �����

	//// 4*. ����������� ����
	//ShowWindow(hWnd, nCmdShow); // nCmdShow - ��� ������ ����
	//UpdateWindow(hWnd); // �������� ����� ���� - �����������
	
	DialogBox(hInst, (TCHAR*)IDD_DIALOG1, HWND_DESKTOP, DFunc);

	// �������� ������ ���������
	MSG msg; // �������� ���������� ���������
	while (GetMessage(&msg, 0, 0, 0)) // ����� ���������� ���������
	{
		TranslateMessage(&msg); // ��������� ������������ ����������
		DispatchMessage(&msg); // �������� ������������� ��������� � ��
	}
	return msg.wParam; // ���������� �������� �������� ���������
}
