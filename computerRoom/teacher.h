#pragma once
#include<iostream>
#include"identity.h"
#include"globalfile.h"
#include"orderFile.h"
#include<fstream>
#include<vector>
using namespace std;

class teacher:public Identity
{
public:
	//默认构造
	teacher();
	//有参构造
	teacher(int enpId, string name, string pwd);

	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	int m_empId;

};
