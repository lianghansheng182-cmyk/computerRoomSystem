#include "manager.h"

manager::manager()
{
}

manager::manager(string name, string pwd)
{
	this->m_name = name;
	this->m_Pwd = pwd;

	//初始化容器 获取到文件中所有 学生 老师的信息
	this->initVector();
	//初始化机房信息
	this->initComputerRoom();
}

//选择菜单
void manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.添加账号             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看账号             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看机房             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.清空预约             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void manager::addPerson()
{
	cout << "请输入添加账号类型" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;
	string fileName;
	string tip;//提示id号
	ofstream ofs;
	
	int select = 0;
	string errorTip;
	
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			fileName = STUDENT_FILE;
			tip = "请输入学号";
			errorTip = "输入学号重复";
			break;
		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip = "请输入职工号";
			errorTip = "输入职工号重复";
			break;
		}
		else
		{
			cout << "输入有误请重新输入" << endl;
			system("pause");
		}
	}
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			//有重复
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd <<" "<< endl;
	cout << "添加成功" << endl;
	this->initVector();

	system("pause");
	system("cls");
	ofs.close();
}
////用函数来打印
//void printStudent(student& s)
//{
//	cout << "学号：" << s.m_id << "姓名：" << s.m_name << "密码" << s.m_Pwd << endl;
//}
//
//void printTeacher(teacher&t)
//{
//	cout << "职工号：" << t.m_empId << "姓名：" << t.m_name << "密码" << t.m_Pwd << endl;
//}



//用仿函数来打印
class printPerson
{
public:
	void operator()(student& s)
	{
		cout << "学号：" << s.m_id << "姓名：" << s.m_name << "密码" << s.m_Pwd << endl;
	}

	void operator()(teacher& t)
	{
		cout << "职工号：" << t.m_empId << "姓名：" << t.m_name << "密码" << t.m_Pwd << endl;
	}
};

void manager::showPerson()
{
	cout << "请选择查看内容" << endl;
	cout << "1.查看学生" << endl;
	cout << "2.查看老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//学生
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printPerson());
	}
	else
	{
		//老师
		cout << "所有老师信息如下：" << endl;
		for_each(vTeacher.begin(), vTeacher.end(), printPerson());
	}
	system("pause");
	system("cls");
}

class printComputer
{
public:
	void operator()(computerRoom& com)
	{
		cout << "机房编号：" << com.m_comId << "电脑数量：" <<com.m_MaxVal<< endl;
	}
};

void manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for_each(vCom.begin(), vCom.end(), printComputer());
	//第二种方法
	//for (vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end();it++)
	//{
	//	cout << "机房编号：" << it->m_comId << "电脑数量：" << it->m_MaxVal << endl;
	//}
	system("pause");
	system("cls");
}

void manager::clearFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "文件清空成功" << endl;
	system("pause");
	system("cls");
}
//初始化容器
void manager::initVector()
{
	vStu.clear();
	vTeacher.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	//读取学生信息
	student s;
	while (ifs>>s.m_id >>s. m_name  >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "学生人数" << vStu.size() << endl;
	ifs.close();


	//读取老师信息

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	
	teacher t;
	while (ifs >> t.m_empId >> t.m_name >> t.m_Pwd)
	{
		vTeacher.push_back(t);
	}
	cout << "老师人数" << vTeacher.size() << endl;

	ifs.close();

}
//检测重复 参数一 检测学号（职工号）  参数二 检测类型
bool manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//学生
		for (vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		//老师
		for (vector<teacher>::iterator it = vTeacher.begin(); it != vTeacher.end(); it++)
		{
			if (id == it->m_empId)
			{
				return true;
			}
		}

	}
	return false;
}

//初始化机房信息
void manager::initComputerRoom()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom com;
	while (ifs >> com.m_comId >> com.m_MaxVal)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房数量" << vCom.size() << endl;
}