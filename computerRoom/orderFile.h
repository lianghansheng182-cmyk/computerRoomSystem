#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include"globalfile.h"
using namespace std;

class orderFile
{
public:
	//构造函数
	orderFile();

	//更新预约记录
	void updateFile();

	//记录预约条数
	int m_size;

	//记录所有预约信息的容器  key记录条数 value具体记录键值对信息
	map<int, map<string, string>>m_orderData;
};