#include"Snake.h"
#include"Wall.h"
Food& Food::generate_COOR(const Wall& wall) {
	_m_coordinate.x = rand() % (wall._window_width - 30) + 1; //�������ʳ������
	_m_coordinate.y = rand() % (wall._window_height - 2) + 1;
	return *this;
}

Food::Food(Snake& ss, const Wall& wall) {//���캯��������ʳ��
	generate_COOR(wall);
	//ʳ�ﲻ�ܳ�����������
	for (int i = 0; i < ss._m_coordinate.size(); i++) {
		if (_m_coordinate.x == ss._m_coordinate[i].x && _m_coordinate.y == ss._m_coordinate[i].y) {
			generate_COOR(wall);
			i = 0;
		}
	}
}