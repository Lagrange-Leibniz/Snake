#define _CRT_SECURE_NO_WARNINGS
#include"Wall.h"
Wall::Wall(int window_height, int _window_width) :
	_window_height(window_height), _window_width(_window_width) {
	//����������ģʽ
	char buf[32];
	sprintf(buf, "mode con cols=%d lines=%d", _window_width, _window_height);
	system(buf);

	//���ع��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	//��ȡ����̨�����Ϣ
	GetConsoleCursorInfo(handle, &CursorInfo);
	//���ؿ���̨���
	CursorInfo.bVisible = false;
	//���޸ĺ��״̬д�ؿ���̨
	SetConsoleCursorInfo(handle, &CursorInfo);
	//��ʼ�����������
	srand((unsigned int)time(0));
}
