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
	friend class Food; //Ϊ����Food��ȡ�������꣬��Ҫ��������Ϊ��Ԫ
	friend class Print;
	//friend Food::Food(const Snake&); ������Ϊ�˷�ֹȨ�����ã�ֻӦ�ð�Food(const Snake&)��һ��������Ϊ��Ԫ�����ǲ�֪��ΪɶVS�಻��
private:
	std::vector<COORDINATE> _m_coordinate;
	int _direct;
	int _flush_time = 250;
public:
	Snake(const Wall&, int direct = 1);//Ĭ�Ϲ��캯��
	Snake& move(); //ÿ���ƶ��ᵼ�³���++
	bool is_eat(Food&); //û�Ե�ʳ��Ҫ����β��
	bool is_alive(Wall&); //����Ҫ�ж�ײǽ����Ҫ�жϳԵ��Լ�
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
