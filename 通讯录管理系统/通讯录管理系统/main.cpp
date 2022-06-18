#include<iostream>
#include<string>
using namespace std;
#define MAX 500
// 联系人结构体
struct Person
{
	string m_Name;   // 姓名
	int m_Age;   // 年龄
	char m_Gender;   // 性别
	string m_Phone;    // 电话
	string m_Address;   // 地址
};
// 通讯录结构体
struct Addressbooks
{
	struct Person m_Array[MAX];
	int m_Size;
};
// 菜单界面
void showMenu()
{
	cout << "1.添加联系人\t" << endl;
	cout << "2.显示联系人\t" << endl;
	cout << "3.删除联系人\t" << endl;
	cout << "4.修改联系人\t" << endl;
	cout << "5.查找联系人\t" << endl;
	cout << "0.清空联系人\t" << endl;
}
// 增加联系人
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，添加失败！" << endl;
		return;
	}
	else
	{
		// 添加姓名
		string name;
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		abs->m_Array[abs->m_Size].m_Name = name;
		// 添加性别
		char gender;
		gender = 'x';
		while (1)
		{
			cout << "请输入联系人性别:  m---男生，w---女生" << endl;
			cin >> gender;
			if (gender == 'm' || gender == 'w')
			{
				abs->m_Array[abs->m_Size].m_Gender = gender;
				break;
			}
			else
			{
				cout << "您的输入有误，请重新输入!" << endl;
			}
		}
		// 添加年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->m_Array[abs->m_Size].m_Age = age;
		// 添加电话
		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->m_Array[abs->m_Size].m_Phone = phone;
		// 添加住址
		string address;
		cout << "请输入住址" << endl;
		cin >> address;
		abs->m_Array[abs->m_Size].m_Address = address;
	}
	abs->m_Size++;
	system("pause");
	system("cls");
}
// 显示联系人
void showPerson(Addressbooks *abs)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		cout << "姓名：" << abs->m_Array[i].m_Name << "\t性别：" << "\t" <<( abs->m_Array[i].m_Gender=='m'?"男生":"女生")
			<< "\t年龄：" << abs->m_Array[i].m_Age << "\t电话：" << abs->m_Array[i].m_Phone
			<< "\t住址：" << abs->m_Array[i].m_Address << endl;
	}
	system("pause");
	system("cls");
}
// 判断联系人是否存在
 int isExit(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->m_Array[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
// 删除联系人
void delPerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
	{
		cout << "您要删除的联系人不存在！" << endl;
		return;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->m_Array[i] = abs->m_Array[i + 1];
		}		
	}
	abs->m_Size--;
	cout << "删除成功！" << endl;
	system("pause");
	system("cls");
}
// 修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs,name);
	if (ret == -1)
	{
		cout << "您查找的联系人不存在" << endl;
	}
	else
	{
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->m_Array[ret].m_Name = name;
		cout << "请输入性别:  m---男生，w---女生" << endl;
		char gender;
		cin >> gender;
		abs->m_Array[ret].m_Gender = gender;
		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->m_Array[ret].m_Age = age;
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->m_Array[ret].m_Phone = phone;
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->m_Array[ret].m_Address = address;
	}
	system("pause");
	system("cls");
}
// 查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
	{
		cout << "您查找的联系人不存在" << endl;
	}
	else
	{
		cout << "姓名：\t" << abs->m_Array[ret].m_Name << "\t性别：" << (abs->m_Array[ret].m_Gender == 'm' ? "男生" : "女生")
			<< "\t年龄: " << abs->m_Array[ret].m_Age << "\t电话：" << abs->m_Array[ret].m_Phone
			<< "\t住址：" << abs->m_Array[ret].m_Address << endl;
	}
	system("pause");
	system("cls");
}
// 清空联系人
void clearPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main()
{
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (1)
	{
		showMenu();
		cout << "请输入您的选择:" << endl;
		cin >> select;
		switch(select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			delPerson(&abs);
			break;
		case 4:
			modifyPerson(&abs);
			break;
		case 5:
			findPerson(&abs);
			break;
		case 6:
			clearPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
	system("pasue");
	system("cls");
	return 0;
}