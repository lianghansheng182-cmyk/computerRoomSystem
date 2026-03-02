#include"orderFile.h"

//构造函数
orderFile::orderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;
	this->m_size = 0;

	while (ifs >> date >> interval >> stuId >> stuName  >> roomId >> status)
	{
		//cout << date << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomId << endl;
		//cout << status << endl;
		//cout << endl;
		string key;
		string value;
		map<string, string>m;
		int pos=date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos );
			m.insert(make_pair(key, value));
		}
		pos=interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos );
			m.insert(make_pair(key, value));
		}
		pos= stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos );
			m.insert(make_pair(key, value));
		}
		pos= stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos );
			m.insert(make_pair(key, value));
		}
		pos= roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos);
			m.insert(make_pair(key, value));
		}
		pos= status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));
		}
		this->m_orderData.insert(make_pair(m_size, m));
		m_size++;
	}
	ifs.close();

	/*cout << "打印开始" << endl;
	for (map<int, map<string,string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		cout << "条数：" << it->first << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{
			cout << "key:" << mit->first << endl;
			cout << "value:" << mit->second << endl;
		}
	}*/
}

//更新预约记录
void orderFile::updateFile()
{
	if (this->m_size == 0)
	{
		return;
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_size; i++)
	{
		ofs << "date:" << m_orderData[i]["date"] << " "
			<< "interval:" << m_orderData[i]["interval"] << " "
			<< "stuId:" << m_orderData[i]["stuId"] << " "
			<< "stuName:" << m_orderData[i]["stuName"] << " "
			<< "roomId:" << m_orderData[i]["roomId"] << " "
			<< "status:" << m_orderData[i]["status"] << " "
			<< endl;
	}
	ofs.close();
}