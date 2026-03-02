#include<iostream>
#include<string>
#include<fstream>
#include"identity.h"
#include"globalfile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;

//进入教师子菜单
void teacherMenu(Identity*& Teacher)
{
	int select = -1;
	
	while (true)
	{
		Teacher->operMenu();
		teacher* tea = (teacher*)Teacher;
		cout << "请输入选择" << endl;
		cin >> select;
		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else
		{
			delete Teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//进入学生子菜单界面
void studentMenu(Identity*& Student)
{
	while (true)
	{
		Student->operMenu();
		student* Stu = (student*) Student;
		int select = -1;
		cin >> select;
		if (select == 1)
		{
			//1.申请预约
			Stu->applyOrder();
		}
		else if (select == 2)
		{
			//2.查看我的预约
			Stu->showMyOrder();
		}
		else if (select == 3)
		{
			//3.查看所有预约
			Stu->showAllOrder();
		}
		else if (select == 4)
		{
			//4.取消预约 
			Stu->cancelOrder();
		}
		else if (select == 0)
		{
			//注销登录
			delete Student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
		}
	}
}
//进入管理员子菜单界面
void managerMenu(Identity*& Manager)
{
	
	while (true)
	{
		//调用管理员子菜单
		Manager->operMenu();
		manager* man = (manager*)Manager;
		int select = 0;
		cin >> select;

		if (select == 1)//添加账号
		{
			//cout << "添加账号" << endl;
			
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			//cout << "查看账号" << endl;
	
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			//cout << "查看机房" << endl;

			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			//cout << "清空预约" << endl;

			man->clearFile();
		}
		else
		{
			delete Manager;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LogIn(string filename, int type)
{
	//父类指针用于指向子类对象
	Identity* person = nullptr;

	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//接收信息
	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入学号" << endl;
		cin >> id;
	}
	else if(type==2)
	{
		cout << "请输入职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId;//从文件读取的ID号
		string fName;//从文件读取的姓名
		string fPwd;//从文件读取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				person = new student(id, name, pwd);
				system("pause");
				system("cls");
				//进入学生的子菜单
				studentMenu(person);

				return;
			}
		}

	}
	else if (type == 2)
	{
		//老师身份验证

		int fId;//从文件读取的ID号
		string fName;//从文件读取的姓名
		string fPwd;//从文件读取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "老师验证登录成功" << endl;
				person = new teacher(id, name, pwd);
				system("pause");
				system("cls");
				//进入老师的子菜单
				teacherMenu(person);


				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;//从文件读取的姓名
		string fPwd;//从文件读取的密码
		while ( ifs >> fName && ifs >> fPwd)
		{
			if ( fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功" << endl;
				person = new manager( name, pwd);
				system("pause");
				system("cls");
				//进入管理员的子菜单
				managerMenu(person);


				return;
			}
		}
	}
	cout << "验证登陆失败" << endl;
	system("pause");
	system("cls");
}
int main()
{

	while (true)
	{
		cout << "======================  欢迎来到传智播客机房预约系统  ======================"
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1://学生
			LogIn(STUDENT_FILE, 1);
			break;
		case 2://老师
			LogIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LogIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
		
			cout << "输入有误请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		
		}
	}
	system("pause");
	return 0;
}