#pragma once
#pragma once
#include"Wall.h"
#include<iostream>
#include"Snake.h"
#include<Windows.h>

class Print {
public:
	//��ӡǽ
	void print(const Wall& wall);
	//��ӡ��Ϸ��ʾ
	void print(const std::string&, const int&, const int&, const int& ForeColor = 7, const int& BackColor = 0);
	//��ӡ��
	void print(const Snake& ss);
	//�����
	void clear(const Snake& ss);
	//��ӡʳ��
	void print(const Food& food);

private:
	void locate(const int x, const int y) {
		COORD c;
		c.X = x; c.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}

	void setColor(unsigned short ForeColor = 7, unsigned short BackGroundColor = 0) {
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);
	}
};
