// stdafx.cpp : source file that includes just the standard includes
// Sceleton.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information
//

#include "stdafx.h"

extern HINSTANCE hInst;

//LRESULT CALLBACK WFunc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	switch (message)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0); // Корректная обработка окончания сообщения
//		break;
//
//	default:
//		return DefWindowProc(hWnd, message, wParam, lParam); // Возврат неотработанного сообщения
//	}
//	return 0L;
//}

BOOL CALLBACK DFunc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static std::string buffer;
	Calculator clr;
	double result = 0.0;
	switch (message)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_1:
			if (buffer.size() && buffer[buffer.size() - 1] == ')')
				buffer += '*';
			buffer += '1';
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_2:
			if (buffer.size() && buffer[buffer.size() - 1] == ')')
				buffer += '*';
			buffer += '2';
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_3:
			if (buffer.size() && buffer[buffer.size() - 1] == ')')
				buffer += '*';
			buffer += '3';
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_4:
			if (buffer.size() && buffer[buffer.size() - 1] == ')')
				buffer += '*';
			buffer += '4';
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_5:
			if (buffer.size() && buffer[buffer.size() - 1] == ')')
				buffer += '*';
			buffer += '5';
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_6:
			if (buffer.size() && buffer[buffer.size() - 1] == ')')
				buffer += '*';
			buffer += '6';
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_7:
			if (buffer.size() && buffer[buffer.size() - 1] == ')')
				buffer += '*';
			buffer += '7';
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_8:
			if (buffer.size() && buffer[buffer.size() - 1] == ')')
				buffer += '*';
			buffer += '8';
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_9:
			if (buffer.size() && buffer[buffer.size() - 1] == ')')
				buffer += '*';
			buffer += '9';
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_0:
			if (buffer.size() && buffer[buffer.size() - 1] == ')')
				buffer += '*';
			buffer += '0';
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_DOT:
			if (buffer.size() && isdgt(buffer[buffer.size() - 1]) && !numIsDouble(buffer, buffer.size() - 1))
			{
				buffer += '.';
				SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			}
			break;
		case IDC_MULTIPLY:
			if (buffer.size() && (isdgt(buffer[buffer.size() - 1]) || buffer[buffer.size() - 1] == ')'))
			{
				buffer += '*';
				SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			}
			break;
		case IDC_PLUS:
			if (buffer.size() && (isdgt(buffer[buffer.size() - 1]) || buffer[buffer.size() - 1] == ')'))
			{
				buffer += '+';
				SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			}
			break;
		case IDC_DIVIDE:
			if (buffer.size() && (isdgt(buffer[buffer.size() - 1]) || buffer[buffer.size() - 1] == ')'))
			{
				buffer += '/';
				SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			}
			break;
		case IDC_MINUS:
			if ((buffer.size() && (isdgt(buffer[buffer.size() - 1]) || buffer[buffer.size() - 1] == ')' || 
				buffer[buffer.size() - 1] == '(')) || buffer[buffer.size() - 1] == '+' || buffer[buffer.size() - 1] == '*' ||
				buffer[buffer.size() - 1] == '/' || !buffer.size())
			{
				buffer += '-';
				SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			}
			break;
		case IDC_LBRACKET:
			if (!buffer.size() || (buffer[buffer.size() - 1] == '*' || buffer[buffer.size() - 1] == '/' || buffer[buffer.size() - 1] == '-'
				|| buffer[buffer.size() - 1] == '+' || buffer[buffer.size() - 1] == '('))
			{
				buffer += '(';
				SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			}
			break;
		case IDC_RBRACKET2:
			if (LBracketExists(buffer) && isdgt(buffer[buffer.size() - 1]))
			{
				buffer += ')';
				SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			}
			break;
		case IDC_C:
			buffer.clear();
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_DEL:
			if (buffer.size())
			{
				buffer.erase(buffer.size() - 1, 1);
				SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			}
			break;
		case IDC_EQUAL:
			if (buffer.size() && (isdgt(buffer[buffer.size() - 1]) || buffer[buffer.size() - 1] == ')'))
			{
				SendMessage(GetDlgItem(hDlg, IDC_FORMULA), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
				result = clr.Calculate(buffer);
				buffer = std::to_string(result);
				SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			}
			break;
		case IDC_SIN:
			if (buffer.size() && (isdgt(buffer[buffer.size() - 1]) || buffer[buffer.size() - 1] == ')'))
			{
				buffer += '*';
			}
			buffer += "sin(";
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_COS:
			if (buffer.size() && (isdgt(buffer[buffer.size() - 1]) || buffer[buffer.size() - 1] == ')'))
			{
				buffer += '*';
			}
			buffer += "cos(";
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_TAN:
			if (buffer.size() && (isdgt(buffer[buffer.size() - 1]) || buffer[buffer.size() - 1] == ')'))
			{
				buffer += '*';
			}
			buffer += "tan(";
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_LOG10:
			if (buffer.size() && (isdgt(buffer[buffer.size() - 1]) || buffer[buffer.size() - 1] == ')'))
			{
				buffer += '*';
			}
			buffer += "log(";
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		case IDC_LN:
			if (buffer.size() && (isdgt(buffer[buffer.size() - 1]) || buffer[buffer.size() - 1] == ')'))
			{
				buffer += '*';
			}
			buffer += "ln(";
			SendMessage(GetDlgItem(hDlg, IDC_ENTER), WM_SETTEXT, NULL, (LPARAM)buffer.c_str());
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0); // Корректная обработка окончания сообщения
		break;

	case WM_CLOSE:
		EndDialog(hDlg, 0);
		break;
	}
	return FALSE;
}

BOOL isdgt(char& ch)
{
	if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' ||
		ch == '0') return TRUE;

	return FALSE;
}

BOOL numIsDouble(std::string& s, INT n)
{
	while (n >= 0 && (s[n] != '+' && s[n] != '-' && s[n] != '*' && s[n] != '/' && s[n] != '(' && s[n] != ')'))
	{
		if (s[n] == '.')
			return TRUE;
		--n;
	}
	return FALSE;
}

BOOL LBracketExists(std::string& s)
{
	INT lbr = std::count_if(s.begin(), s.end(), [](char x) {return x == '('; });
	INT rbr = std::count_if(s.begin(), s.end(), [](char x) {return x == ')'; });
	if (lbr > rbr)
		return TRUE;
	return FALSE;
}
