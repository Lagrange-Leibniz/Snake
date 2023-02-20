#include"Snake.h"
#include <conio.h>
Snake::Snake(const Wall& wall, int direct) :_direct(direct) {
	COORDINATE head;//初始化蛇头
	head.x = wall._window_width / 2 - 15;
	head.y = wall._window_height / 2;
	for (int i = 0; i < 3; i++) {//初始化蛇身为3节
		_m_coordinate.push_back(head);
		head.y++;
	}
}

Snake& Snake::move() {
	char ch;
	if (_kbhit()) {
		ch = _getch();
		switch (ch) {
		case 'w':
		case'W':
			if (_direct == DOWN)
				break;
			_direct = UP;
			break;
		case 's':
		case 'S':
			if (_direct == UP)
				break;
			_direct = DOWN;
			break;
		case 'a':
		case 'A':
			if (_direct == RIGHT)
				break;
			_direct = LEFT;
			break;
		case 'd':
		case 'D':
			if (_direct == LEFT)
				break;
			_direct = RIGHT;
			break;
		case '+':
			if (_flush_time >= 25)
				_flush_time -= 25;
			break;
		case '-':
			if (_flush_time < 250) 
				_flush_time += 25;
			break;
		}
	}

	COORDINATE head = _m_coordinate[0];
	switch (_direct) {
	case UP:
		head.y--;
		break;
	case DOWN:
		head.y++;
		break;
	case LEFT:
		head.x--;
		break;
	case RIGHT:
		head.x++;
		break;
	}
	_m_coordinate.insert(_m_coordinate.begin(), head);
	return *this;
}

bool Snake::is_eat(Food& food) {
	if (_m_coordinate[0].x == food._m_coordinate.x && _m_coordinate[0].y == food._m_coordinate.y) 
		return true;
	_m_coordinate.erase(_m_coordinate.end() - 1); //注：end返回的不是最后一个元素，而是最后一个的下一个元素
	return false;
}

bool Snake::is_alive(Wall& wall) {
	//不能撞墙
	if (_m_coordinate[0].x <= 0 ||
		_m_coordinate[0].x >= wall._window_width - 29 ||
		_m_coordinate[0].y <= 0 ||
		_m_coordinate[0].y >= wall._window_height - 1) {
		return false;
	}
	//蛇头不能碰到蛇身
	for (int i = 1; i < _m_coordinate.size(); i++) {
		if (_m_coordinate[0].x == _m_coordinate[i].x && _m_coordinate[0].y == _m_coordinate[i].y) 
			return false;
	}
	return true;
}