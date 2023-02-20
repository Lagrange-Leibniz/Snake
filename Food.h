#pragma once
#include"Snake.h"
#include"Wall.h"

typedef struct { //先编译谁就要把这个类型写到哪里
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




