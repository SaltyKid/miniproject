/*
 *==============================================================================
 *
 *		文件名:addressBook.cpp
 *
 *		说  明:简单的通讯录功能，增删改查
 *
 *		修改时间:2020-08-24 19:15
 *
 *		作 者:Saltykid
 *
 *==============================================================================
 */

/*=============================== 头文件包含 =================================*/
#include <iostream> 
#include <string>

using namespace std;

/*================================= 宏定义 ===================================*/
#define Max 100 //通讯录最大人数

/*=============================== 结构体定义 =================================*/
struct person		// 联系人结构体
{
	string p_name;	//姓名
	int p_sex;		//1-男；2-女
	int p_age;		//年龄
	string p_phone;	//电话
	string p_addr;	//住址
};

typedef struct addressBooks	//通讯录结构体
{
	struct person personArr[Max];	//通讯录中保存联系人数组
	int p_size;			//通讯录中人员个数 
} addressBook;

/*================================ 函数定义 =================================*/
void show_menu();		//显示主菜单
void add_person(addressBook * abs);		//添加联系人
void show_books(addressBook * abs);		//显示通讯录中所有数据
int is_exist(addressBook * abs);		//判断通讯录中是否有此联系人
void del_person(addressBook * abs);		//删除联系人
void seek_person(addressBook * abs);	//查找联系人
void modify_person(addressBook * abs);	//修改联系人
void clear_books(addressBook * abs);	//清空通讯录

/*================================ 接口函数 =================================*/

/*
 *==============================================================================
 *
 *		函数名:	main
 *		说  明:	主函数程序入口
 *		输  入:	参数1:int argc 程序执行传入的参数个数，第0个默认程序全名
 *				参数2:char *argv[] 字符串指针数组，程序执行传入的参数
 *		输  出:	0代表返回成功；负数代表错误码
 *
 *==============================================================================
 */
int main(int argc,char *argv[])
{
	int orders = 0;	//用户输入命令
	addressBook abs;	//创建通讯录结构体变量

	abs.p_size = 0;	//初始化联系人数量

	while(1)
	{
		show_menu();	//菜单调用
		cin >> orders;
		switch(orders)
		{
			case 1:		//添加联系人
				add_person(&abs);
				break;
			case 2:		//显示联系人
				show_books(&abs);
				break;
			case 3:		//删除联系人
				del_person(&abs);
				break;
			case 4:		//查找联系人
				seek_person(&abs);
				break;
			case 5:		//修改联系人
				modify_person(&abs);
				break;
			case 6:		//清空联系人
				clear_books(&abs);
				break;
			case 0:		//退出通讯录
				cout << "欢迎下次使用！" << endl;
				return 0;
				break;
			default:
				break;
		}
	}

	return 0;
}

/*
 *==============================================================================
 *
 *		函数名:	show_menu
 *		说  明:	显示通讯录菜单主界面
 *		输  入:	无
 *		输  出:	无
 *
 *==============================================================================
 */
void show_menu()
{
	cout << "*************************" << endl;
	cout << "*     1、添加联系人     *" << endl;
	cout << "*     2、显示联系人     *" << endl;
	cout << "*     3、删除联系人     *" << endl;
	cout << "*     4、查找联系人     *" << endl;
	cout << "*     5、修改联系人     *" << endl;
	cout << "*     6、清空联系人     *" << endl;
	cout << "*     0、退出通讯录     *" << endl;
	cout << "*************************" << endl;
}		

/*
 *==============================================================================
 *
 *		函数名:	add_person
 *		说  明:	添加联系人
 *		输  入:	参数1:addressBook * abs 接收传入的通讯录结构体地址
 *		输  出:	无
 *
 *==============================================================================
 */
void add_person(addressBook * abs)
{
	int sex,age;
	string name,phone,address;

	if(abs->p_size == Max)
	{
		cout << "通讯录已满！" << endl;
	}
	else
	{
		//添加联系人信息
		//姓名
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArr[abs->p_size].p_name = name;
		
		//性别
		cout << "请输入性别(1-男,2-女)：" << endl;
		while(1)
		{
			cin >> sex;
			if(sex == 1 || sex == 2)
				break;
			cout << "输入有误，请重新输入：" << endl;

		}
		abs->personArr[abs->p_size].p_sex = sex;

		//年龄
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArr[abs->p_size].p_age = age;

		//电话
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs -> personArr[abs->p_size].p_phone = phone;

		//住址
		cout << "请输入住址：" << endl;
		cin >> address;
		abs -> personArr[abs->p_size].p_addr = address;

		//通讯录人数+1
		abs->p_size++;

		cout << "添加成功！" << endl;
	}
	//暂停
	cout << "\n输入任意字符继续 ";
	string key;
	cin >> key;
	system("clear");

	return;
}

/*
 *==============================================================================
 *
 *		函数名:	show_books
 *		说  明:	输出通讯录中的所有联系人，如果没有联系人输出“通讯录中无数据”
 *		输  入:	参数1:addressBook * abs 接收传入的通讯录结构体地址
 *		输  出:	无
 *
 *==============================================================================
 */
void show_books(addressBook * abs)
{
	int i = 0;

	if(abs->p_size == 0)
		cout << "通讯录中无数据！" << endl;
	for(i = 0;i < abs->p_size;i++)
	{
		cout << "姓名：" << abs->personArr[i].p_name << "  ";
		cout << "性别：" << ((abs->personArr[i].p_sex == 1)?"男":"女") << "  ";
		cout << "年龄：" << abs->personArr[i].p_age << "  ";
		cout << "电话：" << abs->personArr[i].p_phone << "  ";
		cout << "地址：" << abs->personArr[i].p_addr << endl;
	}

	//程序暂停
	string k;
	cout << "\n输入任意字符继续 " ;
	cin >> k;
	system("clear");
}

/*
*==============================================================================
*
 *		函数名:	is_exist
 *		说  明:	判断通讯录中是否存在某联系人，存在返回位置，不存在返回-1
 *		输  入:	参数1:addressBook * abs 接收传入的通讯录结构体地址
 *				参数2:string name 联系人姓名形参
 *		输  出:	int pos 联系人所在存储位置
 *
 *==============================================================================
 */
int is_exist(addressBook * abs,string name)
{
	int i = 0,pos = -1;		//pos初始化-1

	for(i = 0;i < abs->p_size;i++)
	{
		//找到用户输入的姓名 pos = i 数组下标，没找到默认pos = -1
		if(abs->personArr[i].p_name == name)
			pos = i;
	}

	return pos;
}

/*
*==============================================================================
*
*		函数名:	del_person
*		说  明:	删除联系人，存在此联系人输出删除成功，不存在输出查无此人
*		输  入:	参数1:addressBook * abs 接收传入的通讯录结构体地址
*		输  出:	无
*
*==============================================================================
*/
void del_person(addressBook * abs)
{
	string name;
	int ret = is_exist(abs,name);	//判断联系人是否存在，ret记录返回值

	cout << "请输入你要删除的联系人姓名：";
	cin >> name;

	//通讯录中不存在此联系人,输出 查无此人
	if(ret == -1)
	{
		cout << "查无此人！" << endl;
	}

	//通讯录中存在此联系人，删除此联系人，并输出删除成功
	else
	{
		for(int i = ret;i < abs->p_size;i++)
		{
			abs->personArr[i] = abs->personArr[i+1];
		}
		abs->p_size--; 

		cout << "删除成功。" << endl;
	}
	
	//暂停
	cout << "\n输入任意字符继续 ";
	string key;
	cin >> key;
	system("clear");
}

/*
 *==============================================================================
 *
 *		函数名:	seek_person
 *		说  明:	查找联系人，如果存在此输出联系人信息，不存在输出查无此人
 *		输  入:	参数1:addressBook * abs 接收传入的通讯录结构体地址
 *		输  出:	无
 *
 *==============================================================================
 */
void seek_person(addressBook * abs)
{
	int ret = is_exist(abs,name);
	string name;

	cout << "请输入你要查找的联系人姓名：";
	cin >> name;

	//未找到联系人
	if(ret  == -1)
	{
		cout << "查无此人！" << endl;
	}

	//找到联系人
	else
	{
		cout << "\n查找成功，以下为联系人信息：" << endl;

		cout << "姓名：" << abs->personArr[ret].p_name << "  ";
		cout << "性别：" << (abs->personArr[ret].p_sex == 1 ? "男":"女") << "  ";
		cout << "年龄：" << abs->personArr[ret].p_age << "  ";
		cout << "电话：" << abs->personArr[ret].p_phone << "  ";
		cout << "地址：" << abs->personArr[ret].p_addr << endl;
	}

	//暂停
	cout << "\n输入任意字符继续 ";
	string key;
	cin >> key;
	system("clear"); 
}


/*
 *==============================================================================
 *
 *		函数名:	modify_person
 *		说  明:	修改联系人信息，通讯录中存在此联系人进行信息修改，\
 *				不存在输出查无此人
 *		输  入:	参数1：addressBook * abs 接收传入的通讯录结构体地址；
 *		输  出:	无
 *
 *==============================================================================
 */
void modify_person(addressBook * abs)
{
	string name;
	int ret = is_exist(abs,name);

	cout << "请输入你要修改的联系人姓名：";
	cin >> name;

	//未找到联系人
	if(ret  == -1)
	{
		cout << "查无此人！" << endl;
	}

	//找到联系人
	else
	{
		int sex,age;
		string rename,phone,address;
		cout << "请输入新的联系人信息：" << endl;

		cout << "姓名：";
		cin >> rename;
		abs->personArr[ret].p_name = rename;

		cout << "性别(1-男,2-女)：";
		while(1)
		{
			cin >> sex;
			if(sex == 1 || sex == 2)
				break;
			cout << "输入有误，请重新输入：" << endl;
		}
		abs->personArr[ret].p_sex = sex;

		cout << "年龄：";
		cin >> age;
		abs->personArr[ret].p_age = age;

		cout << "电话：";
		cin >> phone;
		abs->personArr[ret].p_phone = phone;

		cout << "住址：";
		cin >> address;
		abs->personArr[ret].p_addr = address;

		cout << "修改成功。";
	}

	//暂停
	cout << "\n输入任意字符继续 ";
	string key;
	cin >> key;
	system("clear"); 
}

/*
 *==============================================================================
 *
 *		函数名:	clear_books
 *		说  明:	清空通讯录
 *		输  入:	参数1:addressBook * abs 接收传入的通讯录结构体地址
 *		输  出:	无
 *
 *==============================================================================
 */
void clear_books(addressBook * abs)
{
	abs->p_size = 0;

	cout << "清空成功。";
	//暂停
	cout << "\n输入任意字符继续 ";
	string key;
	cin >> key;
	system("clear"); 
}

