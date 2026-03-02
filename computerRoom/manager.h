#pragma once
#include<iostream>
#include"identity.h"
#include<fstream>
#include"globalfile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"		
using namespace std;

class manager:public Identity
{
public:
	//默认构造
	manager();
	//有参构造
	manager(string name, string pwd);
	//菜单
	virtual void operMenu();

	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房的信息
	void showComputer();
	//清空预约记录
	void clearFile();
	//初始化容器
	void initVector();
	//学生容器
	vector<student> vStu;

	//老师容器
	vector<teacher> vTeacher;

	//机房容器
	vector<computerRoom> vCom;

	//检测重复 参数一 检测学号（职工号）  参数二 检测类型
 	bool checkRepeat(int id,int type);

	//初始化机房信息
	void initComputerRoom();

};
