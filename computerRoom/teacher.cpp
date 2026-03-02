#include"teacher.h"

//默认构造
teacher::teacher()
{

}
//有参构造
teacher::teacher(int empId, string name, string pwd)
{
	this->m_empId = empId;
	this->m_name = name;
	this->m_Pwd = pwd;
}

//教师菜单界面
void teacher::operMenu()
{
	cout << "欢迎教师： " << this->m_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//查看所有预约
void teacher::showAllOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "." << endl;
		cout << "预约日期：周" << of.m_orderData[i]["date"]
			<< "姓名：" << of.m_orderData[i]["stuName"]
			<< "学号：" << of.m_orderData[i]["stuId"]
			<< "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
			<< "机房号：" << of.m_orderData[i]["roomId"];
		string status = "状态：";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else
		{
			status += "预约失败";
		}
		cout << status << endl;


	}
	system("pause");
	system("cls");
}

//审核预约
void teacher::validOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index=1;
	vector<int>v;
	cout << "待审核的预约记录如下" << endl;
	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << endl;
			cout << "姓名：" << of.m_orderData[i]["stuName"]
				<< "预约日期 周：" << of.m_orderData[i]["date"]
				<< "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
				<< "机房号：" << of.m_orderData[i]["roomId"];
			string status = "状态：审核中";
			cout << status << endl;
		}
	}
	cout << "请输入审核的预约记录，0表示返回" << endl;
	int select = 0;
	int ret;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
			}
			of.updateFile();
			cout << "审核完毕" << endl;
			break;
		}
		cout << "输入有误请重新输入" << endl;
	}
	system("pause");
	system("cls");
}