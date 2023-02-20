#pragma once
#include<vector>
#include"Food.h"
#pragma once
#include"Wall.h"
#define UP  1
#define DOWN  2
#define LEFT  3
#define RIGHT  4

class Snake {
	friend class Food; //为了让Food获取蛇身坐标，需要将其声明为友元
	friend class Print;
	//friend Food::Food(const Snake&); 理论上为了防止权限滥用，只应该把Food(const Snake&)这一个函数设为友元，但是不知道为啥VS编不过
private:
	std::vector<COORDINATE> _m_coordinate;
	int _direct;
	int _flush_time = 250;
public:
	Snake(const Wall&, int direct = 1);//默认构造函数
	Snake& move(); //每次移动会导致长度++
	bool is_eat(Food&); //没吃到食物要消除尾巴
	bool is_alive(Wall&); //不仅要判断撞墙，还要判断吃到自己
	int get_flush_time() {
		return _flush_time;
	}
	int get_length() {
		return _m_coordinate.size();
	}
	void set_flush_time(int new_time) {
		_flush_time = new_time;
	}
};
