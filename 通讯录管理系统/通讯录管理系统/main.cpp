#include<iostream>
#include<string>
using namespace std;
#define MAX 500
// ��ϵ�˽ṹ��
struct Person
{
	string m_Name;   // ����
	int m_Age;   // ����
	char m_Gender;   // �Ա�
	string m_Phone;    // �绰
	string m_Address;   // ��ַ
};
// ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person m_Array[MAX];
	int m_Size;
};
// �˵�����
void showMenu()
{
	cout << "1.�����ϵ��\t" << endl;
	cout << "2.��ʾ��ϵ��\t" << endl;
	cout << "3.ɾ����ϵ��\t" << endl;
	cout << "4.�޸���ϵ��\t" << endl;
	cout << "5.������ϵ��\t" << endl;
	cout << "0.�����ϵ��\t" << endl;
}
// ������ϵ��
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼���������ʧ�ܣ�" << endl;
		return;
	}
	else
	{
		// �������
		string name;
		cout << "��������ϵ��������" << endl;
		cin >> name;
		abs->m_Array[abs->m_Size].m_Name = name;
		// ����Ա�
		char gender;
		gender = 'x';
		while (1)
		{
			cout << "��������ϵ���Ա�:  m---������w---Ů��" << endl;
			cin >> gender;
			if (gender == 'm' || gender == 'w')
			{
				abs->m_Array[abs->m_Size].m_Gender = gender;
				break;
			}
			else
			{
				cout << "����������������������!" << endl;
			}
		}
		// �������
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->m_Array[abs->m_Size].m_Age = age;
		// ��ӵ绰
		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		abs->m_Array[abs->m_Size].m_Phone = phone;
		// ���סַ
		string address;
		cout << "������סַ" << endl;
		cin >> address;
		abs->m_Array[abs->m_Size].m_Address = address;
	}
	abs->m_Size++;
	system("pause");
	system("cls");
}
// ��ʾ��ϵ��
void showPerson(Addressbooks *abs)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		cout << "������" << abs->m_Array[i].m_Name << "\t�Ա�" << "\t" <<( abs->m_Array[i].m_Gender=='m'?"����":"Ů��")
			<< "\t���䣺" << abs->m_Array[i].m_Age << "\t�绰��" << abs->m_Array[i].m_Phone
			<< "\tסַ��" << abs->m_Array[i].m_Address << endl;
	}
	system("pause");
	system("cls");
}
// �ж���ϵ���Ƿ����
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
// ɾ����ϵ��
void delPerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
	{
		cout << "��Ҫɾ������ϵ�˲����ڣ�" << endl;
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
	cout << "ɾ���ɹ���" << endl;
	system("pause");
	system("cls");
}
// �޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs,name);
	if (ret == -1)
	{
		cout << "�����ҵ���ϵ�˲�����" << endl;
	}
	else
	{
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->m_Array[ret].m_Name = name;
		cout << "�������Ա�:  m---������w---Ů��" << endl;
		char gender;
		cin >> gender;
		abs->m_Array[ret].m_Gender = gender;
		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->m_Array[ret].m_Age = age;
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->m_Array[ret].m_Phone = phone;
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->m_Array[ret].m_Address = address;
	}
	system("pause");
	system("cls");
}
// ������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
	{
		cout << "�����ҵ���ϵ�˲�����" << endl;
	}
	else
	{
		cout << "������\t" << abs->m_Array[ret].m_Name << "\t�Ա�" << (abs->m_Array[ret].m_Gender == 'm' ? "����" : "Ů��")
			<< "\t����: " << abs->m_Array[ret].m_Age << "\t�绰��" << abs->m_Array[ret].m_Phone
			<< "\tסַ��" << abs->m_Array[ret].m_Address << endl;
	}
	system("pause");
	system("cls");
}
// �����ϵ��
void clearPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
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
		cout << "����������ѡ��:" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
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