#include"Snake.h"
#include"Food.h"
#include"Print.h"
#include"Wall.h"
#include<string>

void init(const Wall& wall, Print& print) {//初始化游戏界面
	
	print.print("贪吃蛇游戏欢迎您", wall._window_width / 2 - 10, wall._window_height / 2 - 5);	
	system("pause");
	system("cls");
	print.print(wall);
	print.print("游戏操作说明：\n", wall._window_width - 22, 18);
	print.print("W: 上    S: 下\n", wall._window_width - 22, 20);
	print.print("A: 左    D: 右\n", wall._window_width - 22, 22);
	print.print("调节游戏速度：\n", wall._window_width - 22, 24);
	print.print("小键盘 + : 加快\n", wall._window_width - 22, 26);
	print.print("小键盘 - : 减慢\n", wall._window_width - 22, 28);
	print.print("Designed by Liu\n", wall._window_width - 22, 30);
	print.print("v1.0\n", wall._window_width - 22, 32);
}
void print_Gmaing_Info(const Wall& wall, Print& print, const int& score, Snake& snake) {
	print.print(" ", wall._window_width - 22 + 14, 6);
	print.print(" ", wall._window_width - 22 + 14, 4);
	print.print("当前玩家分数: " + std::to_string(score) + "\n", wall._window_width - 22, 6);
	print.print("当前游戏速度: " + std::to_string(10 - snake.get_flush_time() / 25) + "\n", wall._window_width - 22, 4);
}
int main() {
	Wall wall;
	Print print;
	Snake snake(wall);
	Food food(snake, wall);
	init(wall, print);
	int flush = snake.get_flush_time();
	while (true) {
		print_Gmaing_Info(wall, print, snake.get_length() - 1, snake);
		print.print(snake);
		print.print(food);
		snake.move();
		print.clear(snake);//一定要在这里clear才能保证清除的是前一个状态的最后一个元素
		flush = snake.get_flush_time();
		if (snake.is_eat(food) && flush >= 20) {
			food.generate_COOR(wall);
			snake.set_flush_time(flush -= 20);
		}
		if (!snake.is_alive(wall)) {
			print.print("很遗憾，你输了", wall._window_width / 2 - 20, wall._window_height / 2 - 5, 12, 0);
			print.print("你的得分为：" + std::to_string(snake.get_length()), wall._window_width / 2 - 20, wall._window_height / 2 - 3, 12, 0);
			break;
		}
		Sleep(flush);
	}
	
	system("pause");

	return 0;
}