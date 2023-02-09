// keysound.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <io.h>  //读取文件
#include <direct.h>  //列举指定路径下所有的文件名
#include <string>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <comdef.h>  //主要是定义com组件。是开发环境中比较底层的东西。比如数据类型的转换函数，以及位数变化等。可以直接调用里边的函数。
#include <thread>   //线程
#include <time.h>
#pragma comment(lib, "winmm.lib")   //winmm.lib,是Windows音频多媒体AP的静态库
using namespace std;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // 设置入口地址
//屏蔽控制台应用程序的窗口



// 静态资源
#define IDI_ICON1 102


// 取随机数
int randEx(int a, int b)
{
	if (a == b)
		return a;
	LARGE_INTEGER seed;
	QueryPerformanceFrequency(&seed);
	QueryPerformanceCounter(&seed);
	srand(seed.QuadPart);
	return rand() % b + a;
}

int flag_fast = 0;//音效打断

// 播放音效函数
void playtheSound(string path)
{
	cout << path << endl;
	string lpath = "open " + path + " alias MySong";
	if (flag_fast) {
		mciSendString(TEXT("close all"), NULL, 0, NULL);//实现了打断
	}
	// 把lpath里的 \ 改成 /
	for (int i = 0; i < lpath.length(); i++)
	{
		if (lpath[i] == '\\')
			lpath[i] = '/';
	}
	cout << "--------------666---" << lpath;
	_bstr_t bstr(lpath.c_str());
	LPTSTR lr = (LPTSTR)bstr;
	/*
	char vo[20];
	char res[260];
	string path2 = "status " + path + " volume";
	_bstr_t bstr2(path2.c_str());
	LPTSTR lr2 = (LPTSTR)bstr2;
	
	char file1[100] = "setaudio 01.mp3 volume to "; // to后面一定要有空格，不然会报错
	mciSendString(lr2, (LPTSTR)res, 260, NULL);
	int volume = 0;
	volume = atoi(res); // 转化语句
	volume += 200;
	itoa(volume, vo, 10); //转化语句
	//string path3 = "setaudio MySong volume to " + vo;
	string path3 = "setaudio MySong volume to 10";
	_bstr_t bstr3(path3.c_str());
	LPTSTR lr3 = (LPTSTR)bstr3;
	mciSendString(lr3, NULL, 0, NULL); // 设定成功
	*/
	// (TEXT("open X:/C++/keysound/x64/Debug/sounds//2.wav alias mysong"), NULL, 0, NULL);
	mciSendString(lr, NULL, 0, NULL);
	mciSendString(TEXT("play MySong"), NULL, 0, NULL);// notify
	return;
}

//static LPTSTR lr;
// 播放音效函数
static int zhe = 0;
void playtheSound2(string path)//改成一个类，有成员  或者一个静态链表判断有没有添加过 这些考虑还是不对，可能要考虑不是用这个库？？？
{
	//Sleep(500);//半秒
	//mciSendString(TEXT("close MySong"), NULL, 0, NULL);
	cout << path << endl;
	string lpath = "open " + path + " alias MySong" + to_string(zhe);
	//string lpath = "open " + path;

	// 把lpath里的 \ 改成 /
	for (int i = 0; i < lpath.length(); i++)
	{
		if (lpath[i] == '\\')
			lpath[i] = '/';
	}
	cout << "--------------666---" << lpath << endl;
	_bstr_t bstr(lpath.c_str());
	LPTSTR lr = (LPTSTR)bstr;
	//lr = (LPTSTR)bstr;
	// (TEXT("open X:/C++/keysound/x64/Debug/sounds//2.wav alias mysong"), NULL, 0, NULL);
	mciSendString(lr, NULL, 0, NULL);
	//mciSendString(TEXT("play MySong"), NULL, 0, NULL);

	string path_zhe = "play MySong0";// +to_string(zhe);
	_bstr_t bstr_zhe(path_zhe.c_str());
	LPTSTR lr_zhe = (LPTSTR)bstr_zhe;
	mciSendString(lr_zhe, NULL, 0, NULL);

	zhe++;

	return;
}

// 取运行目录
string getRunPath()
{
	char buf[MAX_PATH];
	GetModuleFileNameA(NULL, buf, MAX_PATH);
	string::size_type pos = string(buf).find_last_of("\\/");
	string dir = string(buf).substr(0, pos);
	return dir;
}


// 初始化
void init_res(int a)
{
	string prefix = "./sounds/";
	if (_access(prefix.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(prefix.c_str());							// 则创建
	}
	string aa = "./sounds/random";
	if (_access(aa.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(aa.c_str());							// 则创建
	}
	string b = "./sounds/keyname";
	if (_access(b.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(b.c_str());							// 则创建
	}
	string c = "./sounds/keyname_default";
	if (_access(c.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(c.c_str());							// 则创建
	}
	string d = "./sounds/mouse";
	if (_access(d.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(d.c_str());							// 则创建
	}
	string e = "./sounds/piano";
	if (_access(e.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(e.c_str());							// 则创建
	}
	string f = "./sounds/yasuo";
	if (_access(f.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(f.c_str());							// 则创建
	}
	f = "./sounds/zhixia";
	if (_access(f.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(f.c_str());							// 则创建
	}
	f = "./sounds/majiang";
	if (_access(f.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(f.c_str());							// 则创建
	}
	f = "./sounds/fengmingqi";
	if (_access(f.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(f.c_str());							// 则创建
	}
	f = "./sounds/muyu";
	if (_access(f.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(f.c_str());							// 则创建
	}
	f = "./sounds/qifengle";
	if (_access(f.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(f.c_str());							// 则创建
	}
	f = "./sounds/cedar";
	if (_access(f.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(f.c_str());							// 则创建
	}
	f = "./sounds/cedar_default";
	if (_access(f.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(f.c_str());							// 则创建
	}
	f = "./sounds/yin";
	if (_access(f.c_str(), 0) == -1) { // 如果文件夹不存在
		_mkdir(f.c_str());							// 则创建
	}
	if (a == 1) {
		// 打开sounds文件夹
		// 用system打开同级目录下的sounds文件夹
		string dir = getRunPath();
		string cmd = "explorer " + dir + "\\sounds";
		system(cmd.c_str());
	}
	// 最后写入一些自带的基础音效
	// 以后用户可以自定义修改
}

// 文件夹遍历
void getFileNames(string path, vector<string>& files)
{
	//文件句柄
	//注意：我发现有些文章代码此处是long类型，实测运行中会报错访问异常
	intptr_t hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("/*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,递归查找
			//如果不是,把文件绝对路径存入vector中
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFileNames(p.assign(path).append("/").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("/").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

string keynameFun(DWORD code) {
	string key;
	switch (code)
	{
	case 0x30:
	case 0x60:
		cout << "检测到按键："
			<< "0" << endl;
		key = "0";
		break;
	case 0x31:
	case 0x61:
		cout << "检测到按键："
			<< "1" << endl;
		key = "1";
		break;
	case 0x32:
	case 0x62:
		cout << "检测到按键："
			<< "2" << endl;
		key = "2";
		break;
	case 0x33:
	case 0x63:
		cout << "检测到按键："
			<< "3" << endl;
		key = "3";
		break;
	case 0x34:
	case 0x64:
		cout << "检测到按键："
			<< "4" << endl;
		key = "4";
		break;
	case 0x35:
	case 0x65:
		cout << "检测到按键："
			<< "5" << endl;
		key = "5";
		break;
	case 0x36:
	case 0x66:
		cout << "检测到按键："
			<< "6" << endl;
		key = "6";
		break;
	case 0x37:
	case 0x67:
		cout << "检测到按键："
			<< "7" << endl;
		key = "7";
		break;
	case 0x38:
	case 0x68:
		cout << "检测到按键："
			<< "8" << endl;
		key = "8";
		break;
	case 0x39:
	case 0x69:
		cout << "检测到按键："
			<< "9" << endl;
		key = "9";
		break;
	case 0x41:
		cout << "检测到按键："
			<< "A" << endl;
		key = "A";
		break;
	case 0x42:
		cout << "检测到按键："
			<< "B" << endl;
		key = "B";
		break;
	case 0x43:
		cout << "检测到按键："
			<< "C" << endl;
		key = "C";
		break;
	case 0x44:
		cout << "检测到按键："
			<< "D" << endl;
		key = "D";
		break;
	case 0x45:
		cout << "检测到按键："
			<< "E" << endl;
		key = "E";
		break;
	case 0x46:
		cout << "检测到按键："
			<< "F" << endl;
		key = "F";
		break;
	case 0x47:
		cout << "检测到按键："
			<< "G" << endl;
		key = "G";
		break;
	case 0x48:
		cout << "检测到按键："
			<< "H" << endl;
		key = "H";
		break;
	case 0x49:
		cout << "检测到按键："
			<< "I" << endl;
		key = "I";
		break;
	case 0x4A:
		cout << "检测到按键："
			<< "J" << endl;
		key = "J";
		break;
	case 0x4B:
		cout << "检测到按键："
			<< "K" << endl;
		key = "K";
		break;
	case 0x4C:
		cout << "检测到按键："
			<< "L" << endl;
		key = "L";
		break;
	case 0x4D:
		cout << "检测到按键："
			<< "M" << endl;
		key = "M";
		break;
	case 0x4E:
		cout << "检测到按键："
			<< "N" << endl;
		key = "N";
		break;
	case 0x4F:
		cout << "检测到按键："
			<< "O" << endl;
		key = "O";
		break;
	case 0x50:
		cout << "检测到按键："
			<< "P" << endl;
		key = "P";
		break;
	case 0x51:
		cout << "检测到按键："
			<< "Q" << endl;
		key = "Q";
		break;
	case 0x52:
		cout << "检测到按键："
			<< "R" << endl;
		key = "R";
		break;
	case 0x53:
		cout << "检测到按键："
			<< "S" << endl;
		key = "S";
		break;
	case 0x54:
		cout << "检测到按键："
			<< "T" << endl;
		key = "T";
		break;
	case 0x55:
		cout << "检测到按键："
			<< "U" << endl;
		key = "U";
		break;
	case 0x56:
		cout << "检测到按键："
			<< "V" << endl;
		key = "V";
		break;
	case 0x57:
		cout << "检测到按键："
			<< "W" << endl;
		key = "W";
		break;
	case 0x58:
		cout << "检测到按键："
			<< "X" << endl;
		key = "X";
		break;
	case 0x59:
		cout << "检测到按键："
			<< "Y" << endl;
		key = "Y";
		break;
	case 0x5A:
		cout << "检测到按键："
			<< "Z" << endl;
		key = "Z";
		break;
	case 0x6A:
		cout << "检测到按键："
			<< "*" << endl;
		key = "*";
		break;
	case 0x6B:
		cout << "检测到按键："
			<< "+" << endl;
		key = "+";
		break;
	case 0x6D:
		cout << "检测到按键："
			<< "-" << endl;
		key = "-";
		break;
	case 0x6E:
		cout << "检测到按键："
			<< "." << endl;
		key = ".";
		break;
	case 0x6F:
		cout << "检测到按键："
			<< "/" << endl;
		key = "/";
		break;
	case 0x0D:
		cout << "检测到按键："
			<< "Enter" << endl;
		key = "Enter";
		break;
	case 0xA0:
	case 0xA1:
		cout << "检测到按键："
			<< "Shift" << endl;
		key = "Shift";
		break;
	case 0x08:
		cout << "检测到按键："
			<< "Backspace" << endl;
		key = "Backspace";
		break;
	case 0x20:
		cout << "检测到按键："
			<< "Space" << endl;
		key = "Space";
		break;
	case 162:
		cout << "检测到按键："
			<< "Ctrl" << endl;
		key = "Ctrl";
		break;
	default:
		cout << "其他按键：" << endl;
		key = "default";
		break;
	}

	return key;
}

HHOOK keyboardHook = 0; // 钩子句柄
// 按键变量
string key = "";
string prefix = "/sounds/keyname/";
// 模式flag 0是播放按钮名.wav 1是随机播放
int flag = 3;//指定
clock_t startTime, endTime, cha;
int index = 0;

LRESULT CALLBACK LowLevelKeyboardProc(
	_In_ int nCode,			// 规定钩子如何处理消息，小于 0 则直接 CallNextHookEx
	_In_ WPARAM wParam, // 消息类型
	_In_ LPARAM lParam	// 指向某个结构体的指针，这里是 KBDLLHOOKSTRUCT（低级键盘输入事件）
)
{
	KBDLLHOOKSTRUCT* ks = (KBDLLHOOKSTRUCT*)lParam; // 包含低级键盘输入事件信息
	/*
	typedef struct tagKBDLLHOOKSTRUCT {
		DWORD     vkCode;		// 按键代号
		DWORD     scanCode;		// 硬件扫描代号，同 vkCode 也可以作为按键的代号。sad
		DWORD     flags;		// 事件类型，一般按键按下为 0 抬起为 128。
		DWORD     time;			// 消息时间戳
		ULONG_PTR dwExtraInfo;	// 消息附加信息，一般为 0。
	}KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;
	*/
	// if (ks->flags == 128 || ks->flags == 129)
	cout << "flags: " << ks->flags << endl;

	//if (ks->flags == 0)
	if (ks->flags == 128 || ks->flags == 129)
	{
		endTime = clock();
		cha = endTime - startTime;
		startTime = clock();
		cout << (long)cha << endl;
		if (flag == 2)//键名模式
		{
			cout << "按键--9999--：" << ks->vkCode << endl;
			// 监控键盘
			switch (ks->vkCode)
			{
			case 0x30:
			case 0x60:
				cout << "检测到按键："
					<< "0" << endl;
				key = "0";
				break;
			case 0x31:
			case 0x61:
				cout << "检测到按键："
					<< "1" << endl;
				key = "1";
				break;
			case 0x32:
			case 0x62:
				cout << "检测到按键："
					<< "2" << endl;
				key = "2";
				break;
			case 0x33:
			case 0x63:
				cout << "检测到按键："
					<< "3" << endl;
				key = "3";
				break;
			case 0x34:
			case 0x64:
				cout << "检测到按键："
					<< "4" << endl;
				key = "4";
				break;
			case 0x35:
			case 0x65:
				cout << "检测到按键："
					<< "5" << endl;
				key = "5";
				break;
			case 0x36:
			case 0x66:
				cout << "检测到按键："
					<< "6" << endl;
				key = "6";
				break;
			case 0x37:
			case 0x67:
				cout << "检测到按键："
					<< "7" << endl;
				key = "7";
				break;
			case 0x38:
			case 0x68:
				cout << "检测到按键："
					<< "8" << endl;
				key = "8";
				break;
			case 0x39:
			case 0x69:
				cout << "检测到按键："
					<< "9" << endl;
				key = "9";
				break;
			case 0x41:
				cout << "检测到按键："
					<< "A" << endl;
				key = "A";
				break;
			case 0x42:
				cout << "检测到按键："
					<< "B" << endl;
				key = "B";
				break;
			case 0x43:
				cout << "检测到按键："
					<< "C" << endl;
				key = "C";
				break;
			case 0x44:
				cout << "检测到按键："
					<< "D" << endl;
				key = "D";
				break;
			case 0x45:
				cout << "检测到按键："
					<< "E" << endl;
				key = "E";
				break;
			case 0x46:
				cout << "检测到按键："
					<< "F" << endl;
				key = "F";
				break;
			case 0x47:
				cout << "检测到按键："
					<< "G" << endl;
				key = "G";
				break;
			case 0x48:
				cout << "检测到按键："
					<< "H" << endl;
				key = "H";
				break;
			case 0x49:
				cout << "检测到按键："
					<< "I" << endl;
				key = "I";
				break;
			case 0x4A:
				cout << "检测到按键："
					<< "J" << endl;
				key = "J";
				break;
			case 0x4B:
				cout << "检测到按键："
					<< "K" << endl;
				key = "K";
				break;
			case 0x4C:
				cout << "检测到按键："
					<< "L" << endl;
				key = "L";
				break;
			case 0x4D:
				cout << "检测到按键："
					<< "M" << endl;
				key = "M";
				break;
			case 0x4E:
				cout << "检测到按键："
					<< "N" << endl;
				key = "N";
				break;
			case 0x4F:
				cout << "检测到按键："
					<< "O" << endl;
				key = "O";
				break;
			case 0x50:
				cout << "检测到按键："
					<< "P" << endl;
				key = "P";
				break;
			case 0x51:
				cout << "检测到按键："
					<< "Q" << endl;
				key = "Q";
				break;
			case 0x52:
				cout << "检测到按键："
					<< "R" << endl;
				key = "R";
				break;
			case 0x53:
				cout << "检测到按键："
					<< "S" << endl;
				key = "S";
				break;
			case 0x54:
				cout << "检测到按键："
					<< "T" << endl;
				key = "T";
				break;
			case 0x55:
				cout << "检测到按键："
					<< "U" << endl;
				key = "U";
				break;
			case 0x56:
				cout << "检测到按键："
					<< "V" << endl;
				key = "V";
				break;
			case 0x57:
				cout << "检测到按键："
					<< "W" << endl;
				key = "W";
				break;
			case 0x58:
				cout << "检测到按键："
					<< "X" << endl;
				key = "X";
				break;
			case 0x59:
				cout << "检测到按键："
					<< "Y" << endl;
				key = "Y";
				break;
			case 0x5A:
				cout << "检测到按键："
					<< "Z" << endl;
				key = "Z";
				break;
			case 0x6A:
				cout << "检测到按键："
					<< "*" << endl;
				key = "*";
				break;
			case 0x6B:
				cout << "检测到按键："
					<< "+" << endl;
				key = "+";
				break;
			case 0x6D:
				cout << "检测到按键："
					<< "-" << endl;
				key = "-";
				break;
			case 0x6E:
				cout << "检测到按键："
					<< "." << endl;
				key = ".";
				break;
			case 0x6F:
				cout << "检测到按键："
					<< "/" << endl;
				key = "/";
				break;
			case 0x0D:
				cout << "检测到按键："
					<< "Enter" << endl;
				key = "Enter";
				break;
			case 0xA0:
			case 0xA1:
				cout << "检测到按键："
					<< "Shift" << endl;
				key = "Shift";
				break;
			case 0x08:
				cout << "检测到按键："
					<< "Backspace" << endl;
				key = "Backspace";
				break;
			case 0x20:
				cout << "检测到按键："
					<< "Space" << endl;
				key = "Space";
				break;
			case 162:
				cout << "检测到按键："
					<< "Ctrl" << endl;
				key = "Ctrl";
				break;
			default:
				cout << "其他按键：" << endl;
				key = "default";
				break;
			}
			// 拿到sounds文件夹下的所有文件
			vector<string> fileNames;
			string path_keyname("./sounds/keyname");
			getFileNames(path_keyname, fileNames);
			// 如果fileNames为空，直接返回
			if (fileNames.empty())
			{
				cout << "随机模式文件为空" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}

			boolean flag_keyname = false;
			for (vector<string>::iterator ite = fileNames.begin(); ite != fileNames.end(); ite++)
			{
				cout << *ite << " ";

				cout << (*ite).substr(17, (*ite).size() - 21) << endl;
				if ((*ite).substr(17, (*ite).size() - 21) == key) {

					flag_keyname = true;
					break;
				}
			}
			
			if (flag_keyname) {
				string path = prefix + key + ".wav";
				// 播放key.wav音效
				// cout << "播放音效" << path;
				// 取运行目录
				string dir = getRunPath();
				// 拼接音效文件路径
				path = dir + path;
				cout << "播放音效" << path + "\n";
				// 播放音效
				//thread t1(playtheSound, path);
				// 线程分离
				//t1.detach();
				//playtheSound(path);
				if (flag_fast) {
					playtheSound(path);
				}
				else {
					thread t1(playtheSound, path);
					t1.detach();
				}
			}
			else{
				vector<string> fileNames_2;
				string path_keyname("./sounds/keyname_default");
				getFileNames(path_keyname, fileNames_2);
				// 如果fileNames_2为空，直接返回
				if (fileNames_2.empty())
				{
					cout << "随机模式default文件为空" << endl;
					return CallNextHookEx(NULL, nCode, wParam, lParam);
				}
				int index = randEx(0, fileNames_2.size() - 1);
				// 取运行目录
				string dir = getRunPath();
				cout << dir << endl;
				string path_ = dir + fileNames_2[index].substr(1);
				
				if (flag_fast) {
					playtheSound(path_);
				}
				else {
					// 创建线程
					// 线程分离
					thread t1(playtheSound, path_);
					t1.detach();
				}
			}
		}
		else if (flag == 1)//随机模式
		{
			// 拿到sounds文件夹下的所有文件
			vector<string> fileNames;
			string path("./sounds/random");
			getFileNames(path, fileNames);
			// 如果fileNames为空，直接返回
			if (fileNames.empty())
			{
				cout << "随机模式文件为空" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// 随机抽取容器中的一个文件名
			int index = randEx(0, fileNames.size() - 1);
			/*
			if (cha < 1000) {
				index++;
				if (index == fileNames.size()) {//旋律连续啊
					index = 0;
				}
			}
			else {
				index = 8 * randEx(0, fileNames.size() / 8 - 1);
				cout << "随机：" << index << endl;
				cout << fileNames[index] << endl;//./sounds/random/301.wav
			}
			*/
			// 取运行目录
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			// 创建线程
			//thread t1(playtheSound, path_);
			// 线程分离
			//t1.detach();
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 3)//piano
		{
			cout << "按键--9999--：" << ks->vkCode << endl;
			// 监控键盘
			switch (ks->vkCode)
			{
			case 0x30:
			case 0x60:
				cout << "检测到按键："
					<< "0" << endl;
				key = "0";
				break;
			case 0x31:
			case 0x61:
				cout << "检测到按键："
					<< "1" << endl;
				key = "1";
				break;
			case 0x32:
			case 0x62:
				cout << "检测到按键："
					<< "2" << endl;
				key = "2";
				break;
			case 0x33:
			case 0x63:
				cout << "检测到按键："
					<< "3" << endl;
				key = "3";
				break;
			case 0x34:
			case 0x64:
				cout << "检测到按键："
					<< "4" << endl;
				key = "4";
				break;
			case 0x35:
			case 0x65:
				cout << "检测到按键："
					<< "5" << endl;
				key = "5";
				break;
			case 0x36:
			case 0x66:
				cout << "检测到按键："
					<< "6" << endl;
				key = "6";
				break;
			case 0x37:
			case 0x67:
				cout << "检测到按键："
					<< "7" << endl;
				key = "7";
				break;
			case 0x38:
			case 0x68:
				cout << "检测到按键："
					<< "8" << endl;
				key = "8";
				break;
			case 0x39:
			case 0x69:
				cout << "检测到按键："
					<< "9" << endl;
				key = "9";
				break;
			case 0x41:
				cout << "检测到按键："
					<< "A" << endl;
				key = "A";
				break;
			case 0x42:
				cout << "检测到按键："
					<< "B" << endl;
				key = "B";
				break;
			case 0x43:
				cout << "检测到按键："
					<< "C" << endl;
				key = "C";
				break;
			case 0x44:
				cout << "检测到按键："
					<< "D" << endl;
				key = "D";
				break;
			case 0x45:
				cout << "检测到按键："
					<< "E" << endl;
				key = "E";
				break;
			case 0x46:
				cout << "检测到按键："
					<< "F" << endl;
				key = "F";
				break;
			case 0x47:
				cout << "检测到按键："
					<< "G" << endl;
				key = "G";
				break;
			case 0x48:
				cout << "检测到按键："
					<< "H" << endl;
				key = "H";
				break;
			case 0x49:
				cout << "检测到按键："
					<< "I" << endl;
				key = "I";
				break;
			case 0x4A:
				cout << "检测到按键："
					<< "J" << endl;
				key = "J";
				break;
			case 0x4B:
				cout << "检测到按键："
					<< "K" << endl;
				key = "K";
				break;
			case 0x4C:
				cout << "检测到按键："
					<< "L" << endl;
				key = "L";
				break;
			case 0x4D:
				cout << "检测到按键："
					<< "M" << endl;
				key = "M";
				break;
			case 0x4E:
				cout << "检测到按键："
					<< "N" << endl;
				key = "N";
				break;
			case 0x4F:
				cout << "检测到按键："
					<< "O" << endl;
				key = "O";
				break;
			case 0x50:
				cout << "检测到按键："
					<< "P" << endl;
				key = "P";
				break;
			case 0x51:
				cout << "检测到按键："
					<< "Q" << endl;
				key = "Q";
				break;
			case 0x52:
				cout << "检测到按键："
					<< "R" << endl;
				key = "R";
				break;
			case 0x53:
				cout << "检测到按键："
					<< "S" << endl;
				key = "S";
				break;
			case 0x54:
				cout << "检测到按键："
					<< "T" << endl;
				key = "T";
				break;
			case 0x55:
				cout << "检测到按键："
					<< "U" << endl;
				key = "U";
				break;
			case 0x56:
				cout << "检测到按键："
					<< "V" << endl;
				key = "V";
				break;
			case 0x57:
				cout << "检测到按键："
					<< "W" << endl;
				key = "W";
				break;
			case 0x58:
				cout << "检测到按键："
					<< "X" << endl;
				key = "X";
				break;
			case 0x59:
				cout << "检测到按键："
					<< "Y" << endl;
				key = "Y";
				break;
			case 0x5A:
				cout << "检测到按键："
					<< "Z" << endl;
				key = "Z";
				break;
			case 0x6A:
				cout << "检测到按键："
					<< "*" << endl;
				key = "*";
				break;
			case 0x6B:
				cout << "检测到按键："
					<< "+" << endl;
				key = "+";
				break;
			case 0x6D:
				cout << "检测到按键："
					<< "-" << endl;
				key = "-";
				break;
			case 0x6E:
				cout << "检测到按键："
					<< "." << endl;
				key = ".";
				break;
			case 0x6F:
				cout << "检测到按键："
					<< "/" << endl;
				key = "/";
				break;
			case 0x0D:
				cout << "检测到按键："
					<< "Enter" << endl;
				key = "Enter";
				break;
			case 0xA0:
			case 0xA1:
				cout << "检测到按键："
					<< "Shift" << endl;
				key = "Shift";
				break;
			case 0x08:
				cout << "检测到按键："
					<< "Backspace" << endl;
				key = "Backspace";
				break;
			case 0x20:
				cout << "检测到按键："
					<< "Space" << endl;
				key = "Space";
				break;
			case 162:
				cout << "检测到按键："
					<< "Ctrl" << endl;
				key = "Ctrl";
				break;
			default:
				cout << "其他按键：" << endl;
				key = "default";
				break;
			}
			// 拿到sounds文件夹下的所有文件
			vector<string> fileNames;
			string path_keyname("./sounds/piano");
			getFileNames(path_keyname, fileNames);
			// 如果fileNames为空，直接返回
			if (fileNames.empty())
			{
				cout << "随机模式文件为空" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}

			boolean flag_keyname = false;
			for (vector<string>::iterator ite = fileNames.begin(); ite != fileNames.end(); ite++)
			{
				cout << *ite << " ";

				cout << (*ite).substr(15, (*ite).size() - 19) << endl;
				if ((*ite).substr(15, (*ite).size() - 19) == key) {

					flag_keyname = true;
					break;
				}
			}
			if (!flag_keyname) {
				flag_keyname = true;
				key = "default";
			}
			if (flag_keyname) {
				string path = "/sounds/piano/" + key + ".wav";
				// 播放key.wav音效
				// cout << "播放音效" << path;
				// 取运行目录
				string dir = getRunPath();
				// 拼接音效文件路径
				path = dir + path;
				cout << "播放音效" << path + "\n";
				// 播放音效
				//thread t1(playtheSound, path);
				// 线程分离
				//t1.detach();
				//playtheSound(path);
				if (flag_fast) {
					playtheSound(path);
				}
				else {
					thread t1(playtheSound, path);
					t1.detach();
				}
			}
		}
		else if (flag == 4)//起风了
		{
			// 拿到sounds文件夹下的所有文件
			vector<string> fileNames;
			string path("./sounds/qifengle");
			getFileNames(path, fileNames);
			// 如果fileNames为空，直接返回
			if (fileNames.empty())
			{
				cout << "随机模式文件为空" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// 随机抽取容器中的一个文件名
			//int index = randEx(0, fileNames.size() - 1);
			if (cha < 1000) {
				index++;
				if (index == fileNames.size()) {//旋律连续啊
					index = 0;
				}
			}
			else {
				index = 8 * randEx(0, fileNames.size() / 8 - 1);
				cout << "随机：" << index << endl;
				cout << fileNames[index] << endl;//./sounds/random/301.wav
			}
			// 取运行目录
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			// 创建线程
			//thread t1(playtheSound, path_);
			// 线程分离
			//t1.detach();
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 5)//疾风剑豪
		{
			string key = keynameFun(ks->vkCode);
			// 拿到sounds文件夹下的所有文件
			vector<string> fileNames;
			string path("./sounds/yasuo");
			getFileNames(path, fileNames);
			// 如果fileNames为空，直接返回
			if (fileNames.empty())
			{
				cout << "随机模式文件为空" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			boolean flag_keyname = false;
			for (vector<string>::iterator ite = fileNames.begin(); ite != fileNames.end(); ite++)
			{
				cout << *ite << " ";

				cout << (*ite).substr(15, (*ite).size() - 19) << endl;
				if ((*ite).substr(15, (*ite).size() - 19) == key) {

					flag_keyname = true;
					break;
				}
			}
			if (!flag_keyname) {
				flag_keyname = true;
				key = "default";
			}
			if (flag_keyname) {
				string path = "/sounds/yasuo/" + key + ".wav";
				// 取运行目录
				string dir = getRunPath();
				// 拼接音效文件路径
				path = dir + path;
				cout << "播放音效" << path + "\n";
				if (flag_fast) {
					playtheSound(path);
				}
				else {
					thread t1(playtheSound, path);
					t1.detach();
				}
			}

		}
		else if (flag == 6)//知夏轴
		{
			// 拿到sounds文件夹下的所有文件
			vector<string> fileNames;
			string path("./sounds/zhixia");
			getFileNames(path, fileNames);
			// 如果fileNames为空，直接返回
			if (fileNames.empty())
			{
				cout << "随机模式文件为空" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// 随机抽取容器中的一个文件名
			int index = randEx(0, fileNames.size() - 1);
			// 取运行目录
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				// 创建线程
				// 线程分离
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 7)//麻将音
		{
			// 拿到sounds文件夹下的所有文件
			vector<string> fileNames;
			string path("./sounds/majiang");
			getFileNames(path, fileNames);
			// 如果fileNames为空，直接返回
			if (fileNames.empty())
			{
				cout << "随机模式文件为空" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// 随机抽取容器中的一个文件名
			int index = randEx(0, fileNames.size() - 1);
			// 取运行目录
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				// 创建线程
				// 线程分离
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 8)//蜂鸣器
		{
			// 拿到sounds文件夹下的所有文件
			vector<string> fileNames;
			string path("./sounds/fengmingqi");
			getFileNames(path, fileNames);
			// 如果fileNames为空，直接返回
			if (fileNames.empty())
			{
				cout << "随机模式文件为空" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// 随机抽取容器中的一个文件名
			int index = randEx(0, fileNames.size() - 1);
			// 取运行目录
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				// 创建线程
				// 线程分离
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 9)//木鱼音
		{
			// 拿到sounds文件夹下的所有文件
			vector<string> fileNames;
			string path("./sounds/muyu");
			getFileNames(path, fileNames);
			// 如果fileNames为空，直接返回
			if (fileNames.empty())
			{
				cout << "随机模式文件为空" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// 随机抽取容器中的一个文件名
			int index = randEx(0, fileNames.size() - 1);
			// 取运行目录
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				// 创建线程
				// 线程分离
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 10)//雨滴音
		{
			// 拿到sounds文件夹下的所有文件
			vector<string> fileNames;
			string path("./sounds/yudi");
			getFileNames(path, fileNames);
			// 如果fileNames为空，直接返回
			if (fileNames.empty())
			{
				cout << "随机模式文件为空" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// 随机抽取容器中的一个文件名
			int index = randEx(0, fileNames.size() - 1);
			// 取运行目录
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				// 创建线程
				// 线程分离
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 11)//Cader
		{
			string key = keynameFun(ks->vkCode);
			// 拿到sounds文件夹下的所有文件
			vector<string> fileNames;
			string path("./sounds/cedar");
			getFileNames(path, fileNames);
			// 如果fileNames为空，直接返回
			if (fileNames.empty())
			{
				cout << "随机模式文件为空" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			boolean flag_keyname = false;
			for (vector<string>::iterator ite = fileNames.begin(); ite != fileNames.end(); ite++)
			{
				cout << *ite << " ";

				cout << (*ite).substr(15, (*ite).size() - 19) << endl;
				if ((*ite).substr(15, (*ite).size() - 19) == key) {

					flag_keyname = true;
					break;
				}
			}
			if (flag_keyname) {
				string path = "/sounds/cedar/" + key + ".wav";
				// 取运行目录
				string dir = getRunPath();
				// 拼接音效文件路径
				path = dir + path;
				cout << "播放音效" << path + "\n";
				if (flag_fast) {
					playtheSound(path);
				}
				else {
					thread t1(playtheSound, path);
					t1.detach();
				}
			}
			else {
				vector<string> fileNames_2;
				string path_keyname("./sounds/cedar_default");
				getFileNames(path_keyname, fileNames_2);
				// 如果fileNames_2为空，直接返回
				if (fileNames_2.empty())
				{
					cout << "随机模式default文件为空" << endl;
					return CallNextHookEx(NULL, nCode, wParam, lParam);
				}
				int index = randEx(0, fileNames_2.size() - 1);
				// 取运行目录
				string dir = getRunPath();
				cout << dir << endl;
				string path_ = dir + fileNames_2[index].substr(1);

				if (flag_fast) {
					playtheSound(path_);
				}
				else {
					// 创建线程
					// 线程分离
					thread t1(playtheSound, path_);
					t1.detach();
				}
			}
		}
		else if (flag == 12)//音游
		{
		// 拿到sounds文件夹下的所有文件
		vector<string> fileNames;
		string path("./sounds/yin");
		getFileNames(path, fileNames);
		// 如果fileNames为空，直接返回
		if (fileNames.empty())
		{
			cout << "随机模式文件为空" << endl;
			return CallNextHookEx(NULL, nCode, wParam, lParam);
		}
		// 随机抽取容器中的一个文件名
		int index = randEx(0, fileNames.size() - 1);
		// 取运行目录
		string dir = getRunPath();
		cout << dir << endl;
		string path_ = dir + fileNames[index].substr(1);
		if (flag_fast) {
			playtheSound(path_);
		}
		else {
			// 创建线程
			// 线程分离
			thread t1(playtheSound, path_);
			t1.detach();
		}
		}
	}

	// 将消息传递给钩子链中的下一个钩子
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

//开启监听鼠标
HHOOK mouse_Hook;

LRESULT CALLBACK LowLevelMouseProc(INT nCode,
	WPARAM wParam,
	LPARAM lParam
);
BOOL UninstallHook();  //卸载  
BOOL InstallKbHook();     //安装


BOOL InstallKbHook()
{

	if (mouse_Hook)   UninstallHook();
	mouse_Hook = SetWindowsHookEx(
		WH_MOUSE_LL,   // 钩子类型，WH_MOUSE_LL 为鼠标钩子
		(HOOKPROC)(LowLevelMouseProc),
		//AfxGetApp()->m_hInstance, 
		//GetModuleHandleA(NULL),
		GetModuleHandle(NULL),
		NULL);
	return(mouse_Hook != NULL);
}
 
BOOL UninstallHook()
{

	BOOL jud = FALSE;
	if (mouse_Hook) {
		jud = UnhookWindowsHookEx(mouse_Hook);
		mouse_Hook = NULL;  //set NULL  
	}

	return jud;
}

int flag_mouse = 1;
 
LRESULT CALLBACK LowLevelMouseProc(INT nCode, WPARAM wParam, LPARAM lParam)
{
	MSLLHOOKSTRUCT* pkbhs = (MSLLHOOKSTRUCT*)lParam;
	switch (nCode)
	{

	case HC_ACTION:
	{
		//鼠标左击  
		//if (wParam == WM_LBUTTONDOWN || wParam == WM_RBUTTONDOWN || wParam == WM_MBUTTONDOWN || wParam == WM_LBUTTONUP || wParam == WM_RBUTTONUP || wParam == WM_MBUTTONUP) {
		if (wParam == WM_LBUTTONUP || wParam == WM_RBUTTONUP || wParam == WM_MBUTTONUP) {
			cout << "鼠标被点击了" << endl;

			
			vector<string> fileNames;
			string path("./sounds/mouse");
			getFileNames(path, fileNames);
			// 如果fileNames为空，直接返回
			if (fileNames.empty())
			{
				cout << "随机模式文件为空" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// 随机抽取容器中的一个文件名
			int index = randEx(0, fileNames.size() - 1);

			// 取运行目录
			string dir = getRunPath();
			cout << dir << endl;
			string path_mouse = dir + fileNames[index].substr(1);

			if (flag_mouse) {
				if (flag_fast) {
					playtheSound(path_mouse);
				}
				else {
					// 创建线程
					thread t1(playtheSound, path_mouse);
					// 线程分离
					t1.detach();
				}
			}
		}
	}
		default:break;
	}

	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// 鼠标hook
int key_hook2()
{
	// 安装钩子
	//InstallKbHook();
	mouse_Hook = SetWindowsHookEx(
		WH_MOUSE_LL,   // 钩子类型，WH_MOUSE_LL 为鼠标钩子
		(HOOKPROC)(LowLevelMouseProc),
		//AfxGetApp()->m_hInstance, 
		//GetModuleHandleA(NULL),
		GetModuleHandle(NULL),
		NULL);

	// 不可漏掉消息处理，不然程序会卡死
	
	MSG msg;
	while (1)
	{
		// 如果消息队列中有消息
		if (PeekMessageA(
			&msg,			// MSG 接收这个消息
			NULL,			// 检测消息的窗口句柄，NULL：检索当前线程所有窗口消息
			NULL,			// 检查消息范围中第一个消息的值，NULL：检查所有消息（必须和下面的同时为NULL）
			NULL,			// 检查消息范围中最后一个消息的值，NULL：检查所有消息（必须和上面的同时为NULL）
			PM_REMOVE // 处理消息的方式，PM_REMOVE：处理后将消息从队列中删除
		))
		{
			// 把按键消息传递给字符消息
			TranslateMessage(&msg);

			// 将消息分派给窗口程序
			DispatchMessageW(&msg);
		}
		else
			Sleep(100); // 避免CPU全负载运行
	}
	
	// 删除钩子
	//UninstallHook();
	if (mouse_Hook) {
		UnhookWindowsHookEx(mouse_Hook);
		mouse_Hook = NULL;  //set NULL  
	}
	return 0;
}

// 键盘hook
int key_hook()
{
	// 安装钩子
	keyboardHook = SetWindowsHookEx(
		WH_KEYBOARD_LL,					// 钩子类型，WH_KEYBOARD_LL 为键盘钩子
		LowLevelKeyboardProc,		// 指向钩子函数的指针
		GetModuleHandleA(NULL), // Dll 句柄
		NULL);
	InstallKbHook();

	if (keyboardHook == 0)
	{
		cout << "挂钩键盘失败" << endl;
		return -1;
	}

	// 不可漏掉消息处理，不然程序会卡死
	MSG msg;
	while (1)
	{
		// 如果消息队列中有消息
		if (PeekMessageA(
			&msg,			// MSG 接收这个消息
			NULL,			// 检测消息的窗口句柄，NULL：检索当前线程所有窗口消息
			NULL,			// 检查消息范围中第一个消息的值，NULL：检查所有消息（必须和下面的同时为NULL）
			NULL,			// 检查消息范围中最后一个消息的值，NULL：检查所有消息（必须和上面的同时为NULL）
			PM_REMOVE // 处理消息的方式，PM_REMOVE：处理后将消息从队列中删除
		))
		{
			// 把按键消息传递给字符消息
			TranslateMessage(&msg);

			// 将消息分派给窗口程序
			DispatchMessageW(&msg);
		}
		else
			Sleep(0); // 避免CPU全负载运行
	}
	// 删除钩子
	UnhookWindowsHookEx(keyboardHook);
	UninstallHook();
	return 0;
}



#define IDR_PAUSE 12
#define IDR_START 13
#define IDR_TEST 14
#define IDR_OPENDIR 18
// 菜单常量
#define IDR_QUIT 15
#define IDR_RANDOM 16
#define IDR_KETNAME 17

#define IDR_FAST 25
#define IDR_MOUSE 26
#define IDR_KEYNAME_DEFAULT 27
#define IDR_PIANO 28
#define IDR_YASUO 29
#define IDR_ZHIXIA 30
#define IDR_MAJIANG 31
#define IDR_FENGMINGQI 32
#define IDR_MUYU 33
#define IDR_YUDI 34
#define IDR_QIFENGLE 35
#define IDR_CEDAR 36
#define IDR_YIN 37

LPCTSTR szAppClassName = TEXT("keysound");
LPCTSTR szAppWindowName = TEXT("keysound");
HMENU hmenu;//菜单句柄

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	NOTIFYICONDATA nid;
	UINT WM_TASKBARCREATED;
	POINT pt;//用于接收鼠标坐标
	int xx;//用于接收菜单选项返回值

	// 不要修改TaskbarCreated，这是系统任务栏自定义的消息
	WM_TASKBARCREATED = RegisterWindowMessage(TEXT("TaskbarCreated"));
	switch (message)
	{
	case WM_CREATE://窗口创建时候的消息.
		nid.cbSize = sizeof(nid);
		nid.hWnd = hwnd;
		nid.uID = 0;
		nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
		nid.uCallbackMessage = WM_USER;
		nid.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		lstrcpy(nid.szTip, szAppClassName);
		Shell_NotifyIcon(NIM_ADD, &nid);
		hmenu = CreatePopupMenu();//生成菜单
		AppendMenu(hmenu, MF_UNCHECKED, IDR_RANDOM, L"随机模式");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_KETNAME, L"键名模式");
		AppendMenu(hmenu, MF_CHECKED, IDR_PIANO, L"钢琴模式");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_CEDAR, L"Cedar");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_YIN, L"音游模式");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_QIFENGLE, L"起风了");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_YASUO, L"疾风剑豪");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_ZHIXIA, L"知夏轴");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_MAJIANG, L"麻将音");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_FENGMINGQI, L"蜂鸣器");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_MUYU, L"木鱼音");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_YUDI, L"雨滴");

		AppendMenu(hmenu, MF_UNCHECKED, IDR_FAST, L"音效打断");
		AppendMenu(hmenu, MF_CHECKED, IDR_MOUSE, L"鼠标音效");
		AppendMenu(hmenu, MF_STRING, IDR_OPENDIR, L"打开目录");
		//AppendMenu(hmenu, MF_STRING, IDR_AUTORUN, L"开机自启");
		AppendMenu(hmenu, MF_STRING, IDR_QUIT, L"退出");
		break;
	case WM_USER://连续使用该程序时候的消息.
		if (lParam == WM_RBUTTONDOWN)
		{
			GetCursorPos(&pt);//取鼠标坐标
			::SetForegroundWindow(hwnd);//解决在菜单外单击左键菜单不消失的问题
			// EnableMenuItem(hmenu, IDR_PAUSE, MF_GRAYED);//让菜单中的某一项变灰
			xx = TrackPopupMenu(hmenu, TPM_RETURNCMD, pt.x, pt.y, NULL, hwnd, NULL);//显示菜单并获取选项ID
			if (xx == IDR_QUIT) {
				// 移除托盘图标
				 // 卸载托盘图标
				NOTIFYICONDATA nid;
				nid.cbSize = sizeof(NOTIFYICONDATA);
				nid.hWnd = hwnd;
				nid.uID = 0;
				Shell_NotifyIcon(NIM_DELETE, &nid);
				// 退出程序
				PostQuitMessage(0);
			}
			if (xx == IDR_RANDOM) {
				// 选中随机模式 取消键名模式
				flag = 1;
				CheckMenuItem(hmenu, IDR_RANDOM, MF_CHECKED);
				CheckMenuItem(hmenu, IDR_KETNAME, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_PIANO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_CEDAR, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YIN, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_QIFENGLE, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YASUO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_ZHIXIA, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MAJIANG, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_FENGMINGQI, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MUYU, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YUDI, MF_UNCHECKED);

			}
			if (xx == IDR_KETNAME) {
				// 选中键名模式 取消随机模式
				flag = 2;
				CheckMenuItem(hmenu, IDR_RANDOM, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_KETNAME, MF_CHECKED);
				CheckMenuItem(hmenu, IDR_PIANO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_CEDAR, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YIN, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_QIFENGLE, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YASUO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_ZHIXIA, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MAJIANG, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_FENGMINGQI, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MUYU, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YUDI, MF_UNCHECKED);
			}
			if (xx == IDR_PIANO) {
				flag = 3;
				CheckMenuItem(hmenu, IDR_RANDOM, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_KETNAME, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_PIANO, MF_CHECKED);
				CheckMenuItem(hmenu, IDR_CEDAR, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YIN, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_QIFENGLE, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YASUO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_ZHIXIA, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MAJIANG, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_FENGMINGQI, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MUYU, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YUDI, MF_UNCHECKED);
			}
			if (xx == IDR_QIFENGLE) {
				flag = 4;
				CheckMenuItem(hmenu, IDR_RANDOM, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_KETNAME, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_PIANO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_CEDAR, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YIN, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_QIFENGLE, MF_CHECKED);
				CheckMenuItem(hmenu, IDR_YASUO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_ZHIXIA, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MAJIANG, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_FENGMINGQI, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MUYU, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YUDI, MF_UNCHECKED);
			}
			if (xx == IDR_YASUO) {
				flag = 5;
				CheckMenuItem(hmenu, IDR_RANDOM, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_KETNAME, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_PIANO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_CEDAR, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YIN, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_QIFENGLE, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YASUO, MF_CHECKED);
				CheckMenuItem(hmenu, IDR_ZHIXIA, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MAJIANG, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_FENGMINGQI, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MUYU, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YUDI, MF_UNCHECKED);
			}
			if (xx == IDR_ZHIXIA) {
				flag = 6;
				CheckMenuItem(hmenu, IDR_RANDOM, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_KETNAME, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_PIANO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_CEDAR, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YIN, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_QIFENGLE, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YASUO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_ZHIXIA, MF_CHECKED);
				CheckMenuItem(hmenu, IDR_MAJIANG, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_FENGMINGQI, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MUYU, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YUDI, MF_UNCHECKED);
			}
			if (xx == IDR_MAJIANG) {
				flag = 7;
				CheckMenuItem(hmenu, IDR_RANDOM, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_KETNAME, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_PIANO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_CEDAR, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YIN, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_QIFENGLE, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YASUO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_ZHIXIA, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MAJIANG, MF_CHECKED);
				CheckMenuItem(hmenu, IDR_FENGMINGQI, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MUYU, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YUDI, MF_UNCHECKED);
			}
			if (xx == IDR_FENGMINGQI) {
				flag = 8;
				CheckMenuItem(hmenu, IDR_RANDOM, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_KETNAME, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_PIANO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_CEDAR, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YIN, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_QIFENGLE, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YASUO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_ZHIXIA, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MAJIANG, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_FENGMINGQI, MF_CHECKED);
				CheckMenuItem(hmenu, IDR_MUYU, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YUDI, MF_UNCHECKED);
			}
			if (xx == IDR_MUYU) {
				flag = 9;
				CheckMenuItem(hmenu, IDR_RANDOM, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_KETNAME, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_PIANO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_CEDAR, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YIN, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_QIFENGLE, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YASUO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_ZHIXIA, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MAJIANG, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_FENGMINGQI, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MUYU, MF_CHECKED);
				CheckMenuItem(hmenu, IDR_YUDI, MF_UNCHECKED);
			}
			if (xx == IDR_YUDI) {
				flag = 10;
				CheckMenuItem(hmenu, IDR_RANDOM, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_KETNAME, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_PIANO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_CEDAR, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YIN, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_QIFENGLE, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YASUO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_ZHIXIA, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MAJIANG, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_FENGMINGQI, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MUYU, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YUDI, MF_CHECKED);
			}
			if (xx == IDR_CEDAR) {
				flag = 11;
				CheckMenuItem(hmenu, IDR_RANDOM, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_KETNAME, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_PIANO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_CEDAR, MF_CHECKED);
				CheckMenuItem(hmenu, IDR_YIN, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_QIFENGLE, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YASUO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_ZHIXIA, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MAJIANG, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_FENGMINGQI, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MUYU, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YUDI, MF_UNCHECKED);
			}
			if (xx == IDR_YIN) {
				flag = 12;
				CheckMenuItem(hmenu, IDR_RANDOM, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_KETNAME, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_PIANO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_CEDAR, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YIN, MF_CHECKED);
				CheckMenuItem(hmenu, IDR_QIFENGLE, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YASUO, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_ZHIXIA, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MAJIANG, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_FENGMINGQI, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_MUYU, MF_UNCHECKED);
				CheckMenuItem(hmenu, IDR_YUDI, MF_UNCHECKED);
			}
			if (xx == IDR_FAST) {
				// 音效打断
				flag_fast = !flag_fast;
				if (flag_fast) {
					CheckMenuItem(hmenu, IDR_FAST, MF_CHECKED);
				}
				else {
					CheckMenuItem(hmenu, IDR_FAST, MF_UNCHECKED);
				}

			}
			if (xx == IDR_MOUSE) {
				// 音效打断
				flag_mouse = !flag_mouse;
				if (flag_mouse) {
					CheckMenuItem(hmenu, IDR_MOUSE, MF_CHECKED);
				}
				else {
					CheckMenuItem(hmenu, IDR_MOUSE, MF_UNCHECKED);
				}

			}
			if (xx == IDR_OPENDIR) {
				// 打开目录
				init_res(1);
			}
		}
		break;
	case WM_DESTROY://窗口销毁时候的消息.
		Shell_NotifyIcon(NIM_DELETE, &nid);
		PostQuitMessage(0);
		break;
	default:
		/*
		* 防止当Explorer.exe 崩溃以后，程序在系统系统托盘中的图标就消失
		*
		* 原理：Explorer.exe 重新载入后会重建系统任务栏。当系统任务栏建立的时候会向系统内所有
		* 注册接收TaskbarCreated 消息的顶级窗口发送一条消息，我们只需要捕捉这个消息，并重建系
		* 统托盘的图标即可。
		*/
		if (message == WM_TASKBARCREATED)
			SendMessage(hwnd, WM_CREATE, wParam, lParam);
		break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}



// 设置右下角图标
int SetIco()
{
	cout << "SetIco start" << endl;
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;

	HWND handle = FindWindow(NULL, szAppWindowName);
	// if (handle != NULL)
	// {
	//     MessageBox(NULL, TEXT("Application is already running"), szAppClassName, MB_ICONERROR);
	//     return 0;
	// }

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	cout << "WndProc start" << endl;
	wndclass.lpfnWndProc = WndProc;
	cout << "WndProc end" << endl;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = NULL;
	wndclass.hIcon = LoadIcon(NULL, (LPCTSTR)(32512));//IDI_APPLICATION
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppClassName;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppClassName, MB_ICONERROR);
		return 0;
	}

	// 此处使用WS_EX_TOOLWINDOW 属性来隐藏显示在任务栏上的窗口程序按钮
	//hwnd = CreateWindowEx(WS_EX_TOOLWINDOW,
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
		szAppClassName, szAppWindowName,
		WS_POPUP,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL, NULL, NULL, NULL);

	ShowWindow(hwnd, 0);
	UpdateWindow(hwnd);

	cout << "消息 start" << endl;

	//消息循环
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}



int main()
{
	// 初始化函数 创建sounds文件夹 并写入基础音效 后续用户可以自定义修改
	cout << '1' << endl;
	init_res(0);
	cout << '2' << endl;
	// 开线程去keyhook
	thread t2(key_hook);
	cout << 3 << endl;
	// 线程分离
	t2.detach();

	//thread t3(key_hook2);
	cout << 4 << endl;
	// 线程分离
	//t3.detach();
	cout << 5 << endl;
	SetIco();

	cout << 6 << endl;

}
