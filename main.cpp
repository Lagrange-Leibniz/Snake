#include"Snake.h"
#include"Food.h"
#include"Print.h"
#include"Wall.h"
#include<string>

void init(const Wall& wall, Print& print) {//��ʼ����Ϸ����
	
	print.print("̰������Ϸ��ӭ��", wall._window_width / 2 - 10, wall._window_height / 2 - 5);	
	system("pause");
	system("cls");
	print.print(wall);
	print.print("��Ϸ����˵����\n", wall._window_width - 22, 18);
	print.print("W: ��    S: ��\n", wall._window_width - 22, 20);
	print.print("A: ��    D: ��\n", wall._window_width - 22, 22);
	print.print("������Ϸ�ٶȣ�\n", wall._window_width - 22, 24);
	print.print("С���� + : �ӿ�\n", wall._window_width - 22, 26);
	print.print("С���� - : ����\n", wall._window_width - 22, 28);
	print.print("Designed by Liu\n", wall._window_width - 22, 30);
	print.print("v1.0\n", wall._window_width - 22, 32);
}
void print_Gmaing_Info(const Wall& wall, Print& print, const int& score, Snake& snake) {
	print.print(" ", wall._window_width - 22 + 14, 6);
	print.print(" ", wall._window_width - 22 + 14, 4);
	print.print("��ǰ��ҷ���: " + std::to_string(score) + "\n", wall._window_width - 22, 6);
	print.print("��ǰ��Ϸ�ٶ�: " + std::to_string(10 - snake.get_flush_time() / 25) + "\n", wall._window_width - 22, 4);
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
		print.clear(snake);//һ��Ҫ������clear���ܱ�֤�������ǰһ��״̬�����һ��Ԫ��
		flush = snake.get_flush_time();
		if (snake.is_eat(food) && flush >= 20) {
			food.generate_COOR(wall);
			snake.set_flush_time(flush -= 20);
		}
		if (!snake.is_alive(wall)) {
			print.print("���ź���������", wall._window_width / 2 - 20, wall._window_height / 2 - 5, 12, 0);
			print.print("��ĵ÷�Ϊ��" + std::to_string(snake.get_length()), wall._window_width / 2 - 20, wall._window_height / 2 - 3, 12, 0);
			break;
		}
		Sleep(flush);
	}
	
	system("pause");

	return 0;
}