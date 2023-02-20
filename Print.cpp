#include"Print.h"
void Print::print(const Wall& wall) {
	//绘制地图边界
	system("cls");
	for (int i = 0; i < wall._window_width; i++)
		std::cout << "#";
	std::cout << std::endl;
	for (int i = 0; i < wall._window_height - 2; i++) {
		for (int j = 0; j < wall._window_width; j++) {
			if (i == 13 && j >= wall._window_width - 29) {
				std::cout << "#";
				continue;
			}
			if (j == 0 || j == wall._window_width - 29 || j == wall._window_width - 1)
				std::cout << "#";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < wall._window_width; i++)
		std::cout << "#";
}
//打印游戏提示
void Print::print(const std::string& str, const int& x, const int& y, const int& ForeColor, const int& BackColor) {
	locate(x, y);
	setColor(ForeColor, BackColor);
	std::cout << str;
	locate(x, y + 1);
}

//打印蛇
void Print::print(const Snake& ss) {
	//把蛇画成浅绿色
	setColor(10, 0);
	for (int i = 0; i < ss._m_coordinate.size(); i++) {
		locate(ss._m_coordinate[i].x, ss._m_coordinate[i].y);
		std::cout << "*";
	}
	//把字体切换回白色
	setColor(7, 0);
}

void Print::clear(const Snake& ss) {
	//只需清除最旧的元素即可
	int tmp = ss._m_coordinate.size() - 1;
	//print(" ", ss._m_coordinate[tmp].x, ss._m_coordinate[tmp].y);
	locate(ss._m_coordinate[tmp].x, ss._m_coordinate[tmp].y);
	std::cout << " ";
}

//打印食物
void Print::print(const Food& food) {
	setColor(12, 0);
	locate(food._m_coordinate.x, food._m_coordinate.y);
	std::cout << "@";
	setColor(7, 0);
}