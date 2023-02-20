#define _CRT_SECURE_NO_WARNINGS
#include"Wall.h"
Wall::Wall(int window_height, int _window_width) :
	_window_height(window_height), _window_width(_window_width) {
	//更改命令行模式
	char buf[32];
	sprintf(buf, "mode con cols=%d lines=%d", _window_width, _window_height);
	system(buf);

	//隐藏光标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	//获取控制台光标信息
	GetConsoleCursorInfo(handle, &CursorInfo);
	//隐藏控制台光标
	CursorInfo.bVisible = false;
	//将修改后的状态写回控制台
	SetConsoleCursorInfo(handle, &CursorInfo);
	//初始化随机数种子
	srand((unsigned int)time(0));
}
