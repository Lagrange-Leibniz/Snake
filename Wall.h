#pragma once
#include<Windows.h>
#include<iostream>
class Wall {
public:
	const int _window_height;
	const int _window_width;
	Wall(int window_height = 40, int _window_width = 80);
};