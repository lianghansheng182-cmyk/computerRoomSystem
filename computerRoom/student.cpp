#include"student.h"

//默认构造
student::student()
{

}
//有参构造 参数：学号，姓名，密码
student::student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom com;
	while (ifs >> com.m_comId >> com.m_MaxVal)
	{
		vCom.push_back(com);
	}
	ifs.close();
}
//学生菜单
void student::operMenu()
{
	cout << "欢迎学生代表：" << this->m_name << " 登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//申请预约
void student::applyOrder()
{
	cout << "机房开放时间为周一到周五" << endl;
	cout << "请输入申请预约的时间内" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	cout << "请输入日期" << endl;
	while (true)
	{
		cin >> date;
		if (date > 0 && date < 6)
		{
			break;
		}
		cout << "输入有误请重新输入" << endl;
	}
	cout << "请输入时间段" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval > 0 && interval < 3)
		{
			break;
		}
		cout << "输入有误请重新输入" << endl;
	}
	cout << "请输入预约的机房" << endl;
	while (true)
	{
		cin >> room;
		if (room > 0 && room < 4)
		{
			break;
		}
		cout << "输入有误请重新输入" << endl;
	}
	cout << "预约成功！审核中" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << " ";
	ofs << endl;
	ofs.close();
	system("pause");
	system("cls");
}
//查看自身预约
void student::showMyOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout << "文件为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	for (int i = 0; i < of.m_size; i++)
	{
		string status = "状态：";
		if (this->m_id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			cout << "预约日期 周：" << of.m_orderData[i]["date"] << endl;
			cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房号：" << of.m_orderData[i]["roomId"] << endl;
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	
	system("pause");
	system("cls");
}
//查看所有预约
void student::showAllOrder()
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
		string status = "状态：";
		cout << "姓名：" << of.m_orderData[i]["stuName"] << endl;
		cout << "预约日期 周：" << of.m_orderData[i]["date"] << endl;
		cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "机房号：" << of.m_orderData[i]["roomId"] << endl;
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}


	system("pause");
	system("cls");
}
//取消预约
void student::cancelOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入要取消的记录" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		//判断是否为自己的学号
		if (this->m_id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ <<"." << endl;

				string status = "状态：";
				cout << "姓名：" << of.m_orderData[i]["stuName"]
					<< "预约日期 周：" << of.m_orderData[i]["date"]
					<< "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
					<< "机房号：" << of.m_orderData[i]["roomId"];
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;

			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
	int select;
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
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateFile();
				cout << "预约已取消" << endl;
				break;
			}
			
		}
		else
		{
			cout << "输入有误请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}
