#pragma once
#include"Snake.h"
#include"Wall.h"

typedef struct { //�ȱ���˭��Ҫ���������д������
	int x;
	int y;
}COORDINATE;

class Food {
	friend class Snake;
	friend class Print;
private:
	COORDINATE _m_coordinate;
public:
	Food(Snake&, const Wall&);
	
	Food& generate_COOR(const Wall&);
};




