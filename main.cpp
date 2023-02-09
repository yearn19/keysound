// keysound.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <io.h>  //��ȡ�ļ�
#include <direct.h>  //�о�ָ��·�������е��ļ���
#include <string>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <comdef.h>  //��Ҫ�Ƕ���com������ǿ��������бȽϵײ�Ķ����������������͵�ת���������Լ�λ���仯�ȡ�����ֱ�ӵ�����ߵĺ�����
#include <thread>   //�߳�
#include <time.h>
#pragma comment(lib, "winmm.lib")   //winmm.lib,��Windows��Ƶ��ý��AP�ľ�̬��
using namespace std;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // ������ڵ�ַ
//���ο���̨Ӧ�ó���Ĵ���



// ��̬��Դ
#define IDI_ICON1 102


// ȡ�����
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

int flag_fast = 0;//��Ч���

// ������Ч����
void playtheSound(string path)
{
	cout << path << endl;
	string lpath = "open " + path + " alias MySong";
	if (flag_fast) {
		mciSendString(TEXT("close all"), NULL, 0, NULL);//ʵ���˴��
	}
	// ��lpath��� \ �ĳ� /
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
	
	char file1[100] = "setaudio 01.mp3 volume to "; // to����һ��Ҫ�пո񣬲�Ȼ�ᱨ��
	mciSendString(lr2, (LPTSTR)res, 260, NULL);
	int volume = 0;
	volume = atoi(res); // ת�����
	volume += 200;
	itoa(volume, vo, 10); //ת�����
	//string path3 = "setaudio MySong volume to " + vo;
	string path3 = "setaudio MySong volume to 10";
	_bstr_t bstr3(path3.c_str());
	LPTSTR lr3 = (LPTSTR)bstr3;
	mciSendString(lr3, NULL, 0, NULL); // �趨�ɹ�
	*/
	// (TEXT("open X:/C++/keysound/x64/Debug/sounds//2.wav alias mysong"), NULL, 0, NULL);
	mciSendString(lr, NULL, 0, NULL);
	mciSendString(TEXT("play MySong"), NULL, 0, NULL);// notify
	return;
}

//static LPTSTR lr;
// ������Ч����
static int zhe = 0;
void playtheSound2(string path)//�ĳ�һ���࣬�г�Ա  ����һ����̬�����ж���û����ӹ� ��Щ���ǻ��ǲ��ԣ�����Ҫ���ǲ���������⣿����
{
	//Sleep(500);//����
	//mciSendString(TEXT("close MySong"), NULL, 0, NULL);
	cout << path << endl;
	string lpath = "open " + path + " alias MySong" + to_string(zhe);
	//string lpath = "open " + path;

	// ��lpath��� \ �ĳ� /
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

// ȡ����Ŀ¼
string getRunPath()
{
	char buf[MAX_PATH];
	GetModuleFileNameA(NULL, buf, MAX_PATH);
	string::size_type pos = string(buf).find_last_of("\\/");
	string dir = string(buf).substr(0, pos);
	return dir;
}


// ��ʼ��
void init_res(int a)
{
	string prefix = "./sounds/";
	if (_access(prefix.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(prefix.c_str());							// �򴴽�
	}
	string aa = "./sounds/random";
	if (_access(aa.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(aa.c_str());							// �򴴽�
	}
	string b = "./sounds/keyname";
	if (_access(b.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(b.c_str());							// �򴴽�
	}
	string c = "./sounds/keyname_default";
	if (_access(c.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(c.c_str());							// �򴴽�
	}
	string d = "./sounds/mouse";
	if (_access(d.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(d.c_str());							// �򴴽�
	}
	string e = "./sounds/piano";
	if (_access(e.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(e.c_str());							// �򴴽�
	}
	string f = "./sounds/yasuo";
	if (_access(f.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(f.c_str());							// �򴴽�
	}
	f = "./sounds/zhixia";
	if (_access(f.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(f.c_str());							// �򴴽�
	}
	f = "./sounds/majiang";
	if (_access(f.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(f.c_str());							// �򴴽�
	}
	f = "./sounds/fengmingqi";
	if (_access(f.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(f.c_str());							// �򴴽�
	}
	f = "./sounds/muyu";
	if (_access(f.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(f.c_str());							// �򴴽�
	}
	f = "./sounds/qifengle";
	if (_access(f.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(f.c_str());							// �򴴽�
	}
	f = "./sounds/cedar";
	if (_access(f.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(f.c_str());							// �򴴽�
	}
	f = "./sounds/cedar_default";
	if (_access(f.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(f.c_str());							// �򴴽�
	}
	f = "./sounds/yin";
	if (_access(f.c_str(), 0) == -1) { // ����ļ��в�����
		_mkdir(f.c_str());							// �򴴽�
	}
	if (a == 1) {
		// ��sounds�ļ���
		// ��system��ͬ��Ŀ¼�µ�sounds�ļ���
		string dir = getRunPath();
		string cmd = "explorer " + dir + "\\sounds";
		system(cmd.c_str());
	}
	// ���д��һЩ�Դ��Ļ�����Ч
	// �Ժ��û������Զ����޸�
}

// �ļ��б���
void getFileNames(string path, vector<string>& files)
{
	//�ļ����
	//ע�⣺�ҷ�����Щ���´���˴���long���ͣ�ʵ�������лᱨ������쳣
	intptr_t hFile = 0;
	//�ļ���Ϣ
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("/*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//�����Ŀ¼,�ݹ����
			//�������,���ļ�����·������vector��
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
		cout << "��⵽������"
			<< "0" << endl;
		key = "0";
		break;
	case 0x31:
	case 0x61:
		cout << "��⵽������"
			<< "1" << endl;
		key = "1";
		break;
	case 0x32:
	case 0x62:
		cout << "��⵽������"
			<< "2" << endl;
		key = "2";
		break;
	case 0x33:
	case 0x63:
		cout << "��⵽������"
			<< "3" << endl;
		key = "3";
		break;
	case 0x34:
	case 0x64:
		cout << "��⵽������"
			<< "4" << endl;
		key = "4";
		break;
	case 0x35:
	case 0x65:
		cout << "��⵽������"
			<< "5" << endl;
		key = "5";
		break;
	case 0x36:
	case 0x66:
		cout << "��⵽������"
			<< "6" << endl;
		key = "6";
		break;
	case 0x37:
	case 0x67:
		cout << "��⵽������"
			<< "7" << endl;
		key = "7";
		break;
	case 0x38:
	case 0x68:
		cout << "��⵽������"
			<< "8" << endl;
		key = "8";
		break;
	case 0x39:
	case 0x69:
		cout << "��⵽������"
			<< "9" << endl;
		key = "9";
		break;
	case 0x41:
		cout << "��⵽������"
			<< "A" << endl;
		key = "A";
		break;
	case 0x42:
		cout << "��⵽������"
			<< "B" << endl;
		key = "B";
		break;
	case 0x43:
		cout << "��⵽������"
			<< "C" << endl;
		key = "C";
		break;
	case 0x44:
		cout << "��⵽������"
			<< "D" << endl;
		key = "D";
		break;
	case 0x45:
		cout << "��⵽������"
			<< "E" << endl;
		key = "E";
		break;
	case 0x46:
		cout << "��⵽������"
			<< "F" << endl;
		key = "F";
		break;
	case 0x47:
		cout << "��⵽������"
			<< "G" << endl;
		key = "G";
		break;
	case 0x48:
		cout << "��⵽������"
			<< "H" << endl;
		key = "H";
		break;
	case 0x49:
		cout << "��⵽������"
			<< "I" << endl;
		key = "I";
		break;
	case 0x4A:
		cout << "��⵽������"
			<< "J" << endl;
		key = "J";
		break;
	case 0x4B:
		cout << "��⵽������"
			<< "K" << endl;
		key = "K";
		break;
	case 0x4C:
		cout << "��⵽������"
			<< "L" << endl;
		key = "L";
		break;
	case 0x4D:
		cout << "��⵽������"
			<< "M" << endl;
		key = "M";
		break;
	case 0x4E:
		cout << "��⵽������"
			<< "N" << endl;
		key = "N";
		break;
	case 0x4F:
		cout << "��⵽������"
			<< "O" << endl;
		key = "O";
		break;
	case 0x50:
		cout << "��⵽������"
			<< "P" << endl;
		key = "P";
		break;
	case 0x51:
		cout << "��⵽������"
			<< "Q" << endl;
		key = "Q";
		break;
	case 0x52:
		cout << "��⵽������"
			<< "R" << endl;
		key = "R";
		break;
	case 0x53:
		cout << "��⵽������"
			<< "S" << endl;
		key = "S";
		break;
	case 0x54:
		cout << "��⵽������"
			<< "T" << endl;
		key = "T";
		break;
	case 0x55:
		cout << "��⵽������"
			<< "U" << endl;
		key = "U";
		break;
	case 0x56:
		cout << "��⵽������"
			<< "V" << endl;
		key = "V";
		break;
	case 0x57:
		cout << "��⵽������"
			<< "W" << endl;
		key = "W";
		break;
	case 0x58:
		cout << "��⵽������"
			<< "X" << endl;
		key = "X";
		break;
	case 0x59:
		cout << "��⵽������"
			<< "Y" << endl;
		key = "Y";
		break;
	case 0x5A:
		cout << "��⵽������"
			<< "Z" << endl;
		key = "Z";
		break;
	case 0x6A:
		cout << "��⵽������"
			<< "*" << endl;
		key = "*";
		break;
	case 0x6B:
		cout << "��⵽������"
			<< "+" << endl;
		key = "+";
		break;
	case 0x6D:
		cout << "��⵽������"
			<< "-" << endl;
		key = "-";
		break;
	case 0x6E:
		cout << "��⵽������"
			<< "." << endl;
		key = ".";
		break;
	case 0x6F:
		cout << "��⵽������"
			<< "/" << endl;
		key = "/";
		break;
	case 0x0D:
		cout << "��⵽������"
			<< "Enter" << endl;
		key = "Enter";
		break;
	case 0xA0:
	case 0xA1:
		cout << "��⵽������"
			<< "Shift" << endl;
		key = "Shift";
		break;
	case 0x08:
		cout << "��⵽������"
			<< "Backspace" << endl;
		key = "Backspace";
		break;
	case 0x20:
		cout << "��⵽������"
			<< "Space" << endl;
		key = "Space";
		break;
	case 162:
		cout << "��⵽������"
			<< "Ctrl" << endl;
		key = "Ctrl";
		break;
	default:
		cout << "����������" << endl;
		key = "default";
		break;
	}

	return key;
}

HHOOK keyboardHook = 0; // ���Ӿ��
// ��������
string key = "";
string prefix = "/sounds/keyname/";
// ģʽflag 0�ǲ��Ű�ť��.wav 1���������
int flag = 3;//ָ��
clock_t startTime, endTime, cha;
int index = 0;

LRESULT CALLBACK LowLevelKeyboardProc(
	_In_ int nCode,			// �涨������δ�����Ϣ��С�� 0 ��ֱ�� CallNextHookEx
	_In_ WPARAM wParam, // ��Ϣ����
	_In_ LPARAM lParam	// ָ��ĳ���ṹ���ָ�룬������ KBDLLHOOKSTRUCT���ͼ����������¼���
)
{
	KBDLLHOOKSTRUCT* ks = (KBDLLHOOKSTRUCT*)lParam; // �����ͼ����������¼���Ϣ
	/*
	typedef struct tagKBDLLHOOKSTRUCT {
		DWORD     vkCode;		// ��������
		DWORD     scanCode;		// Ӳ��ɨ����ţ�ͬ vkCode Ҳ������Ϊ�����Ĵ��š�sad
		DWORD     flags;		// �¼����ͣ�һ�㰴������Ϊ 0 ̧��Ϊ 128��
		DWORD     time;			// ��Ϣʱ���
		ULONG_PTR dwExtraInfo;	// ��Ϣ������Ϣ��һ��Ϊ 0��
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
		if (flag == 2)//����ģʽ
		{
			cout << "����--9999--��" << ks->vkCode << endl;
			// ��ؼ���
			switch (ks->vkCode)
			{
			case 0x30:
			case 0x60:
				cout << "��⵽������"
					<< "0" << endl;
				key = "0";
				break;
			case 0x31:
			case 0x61:
				cout << "��⵽������"
					<< "1" << endl;
				key = "1";
				break;
			case 0x32:
			case 0x62:
				cout << "��⵽������"
					<< "2" << endl;
				key = "2";
				break;
			case 0x33:
			case 0x63:
				cout << "��⵽������"
					<< "3" << endl;
				key = "3";
				break;
			case 0x34:
			case 0x64:
				cout << "��⵽������"
					<< "4" << endl;
				key = "4";
				break;
			case 0x35:
			case 0x65:
				cout << "��⵽������"
					<< "5" << endl;
				key = "5";
				break;
			case 0x36:
			case 0x66:
				cout << "��⵽������"
					<< "6" << endl;
				key = "6";
				break;
			case 0x37:
			case 0x67:
				cout << "��⵽������"
					<< "7" << endl;
				key = "7";
				break;
			case 0x38:
			case 0x68:
				cout << "��⵽������"
					<< "8" << endl;
				key = "8";
				break;
			case 0x39:
			case 0x69:
				cout << "��⵽������"
					<< "9" << endl;
				key = "9";
				break;
			case 0x41:
				cout << "��⵽������"
					<< "A" << endl;
				key = "A";
				break;
			case 0x42:
				cout << "��⵽������"
					<< "B" << endl;
				key = "B";
				break;
			case 0x43:
				cout << "��⵽������"
					<< "C" << endl;
				key = "C";
				break;
			case 0x44:
				cout << "��⵽������"
					<< "D" << endl;
				key = "D";
				break;
			case 0x45:
				cout << "��⵽������"
					<< "E" << endl;
				key = "E";
				break;
			case 0x46:
				cout << "��⵽������"
					<< "F" << endl;
				key = "F";
				break;
			case 0x47:
				cout << "��⵽������"
					<< "G" << endl;
				key = "G";
				break;
			case 0x48:
				cout << "��⵽������"
					<< "H" << endl;
				key = "H";
				break;
			case 0x49:
				cout << "��⵽������"
					<< "I" << endl;
				key = "I";
				break;
			case 0x4A:
				cout << "��⵽������"
					<< "J" << endl;
				key = "J";
				break;
			case 0x4B:
				cout << "��⵽������"
					<< "K" << endl;
				key = "K";
				break;
			case 0x4C:
				cout << "��⵽������"
					<< "L" << endl;
				key = "L";
				break;
			case 0x4D:
				cout << "��⵽������"
					<< "M" << endl;
				key = "M";
				break;
			case 0x4E:
				cout << "��⵽������"
					<< "N" << endl;
				key = "N";
				break;
			case 0x4F:
				cout << "��⵽������"
					<< "O" << endl;
				key = "O";
				break;
			case 0x50:
				cout << "��⵽������"
					<< "P" << endl;
				key = "P";
				break;
			case 0x51:
				cout << "��⵽������"
					<< "Q" << endl;
				key = "Q";
				break;
			case 0x52:
				cout << "��⵽������"
					<< "R" << endl;
				key = "R";
				break;
			case 0x53:
				cout << "��⵽������"
					<< "S" << endl;
				key = "S";
				break;
			case 0x54:
				cout << "��⵽������"
					<< "T" << endl;
				key = "T";
				break;
			case 0x55:
				cout << "��⵽������"
					<< "U" << endl;
				key = "U";
				break;
			case 0x56:
				cout << "��⵽������"
					<< "V" << endl;
				key = "V";
				break;
			case 0x57:
				cout << "��⵽������"
					<< "W" << endl;
				key = "W";
				break;
			case 0x58:
				cout << "��⵽������"
					<< "X" << endl;
				key = "X";
				break;
			case 0x59:
				cout << "��⵽������"
					<< "Y" << endl;
				key = "Y";
				break;
			case 0x5A:
				cout << "��⵽������"
					<< "Z" << endl;
				key = "Z";
				break;
			case 0x6A:
				cout << "��⵽������"
					<< "*" << endl;
				key = "*";
				break;
			case 0x6B:
				cout << "��⵽������"
					<< "+" << endl;
				key = "+";
				break;
			case 0x6D:
				cout << "��⵽������"
					<< "-" << endl;
				key = "-";
				break;
			case 0x6E:
				cout << "��⵽������"
					<< "." << endl;
				key = ".";
				break;
			case 0x6F:
				cout << "��⵽������"
					<< "/" << endl;
				key = "/";
				break;
			case 0x0D:
				cout << "��⵽������"
					<< "Enter" << endl;
				key = "Enter";
				break;
			case 0xA0:
			case 0xA1:
				cout << "��⵽������"
					<< "Shift" << endl;
				key = "Shift";
				break;
			case 0x08:
				cout << "��⵽������"
					<< "Backspace" << endl;
				key = "Backspace";
				break;
			case 0x20:
				cout << "��⵽������"
					<< "Space" << endl;
				key = "Space";
				break;
			case 162:
				cout << "��⵽������"
					<< "Ctrl" << endl;
				key = "Ctrl";
				break;
			default:
				cout << "����������" << endl;
				key = "default";
				break;
			}
			// �õ�sounds�ļ����µ������ļ�
			vector<string> fileNames;
			string path_keyname("./sounds/keyname");
			getFileNames(path_keyname, fileNames);
			// ���fileNamesΪ�գ�ֱ�ӷ���
			if (fileNames.empty())
			{
				cout << "���ģʽ�ļ�Ϊ��" << endl;
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
				// ����key.wav��Ч
				// cout << "������Ч" << path;
				// ȡ����Ŀ¼
				string dir = getRunPath();
				// ƴ����Ч�ļ�·��
				path = dir + path;
				cout << "������Ч" << path + "\n";
				// ������Ч
				//thread t1(playtheSound, path);
				// �̷߳���
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
				// ���fileNames_2Ϊ�գ�ֱ�ӷ���
				if (fileNames_2.empty())
				{
					cout << "���ģʽdefault�ļ�Ϊ��" << endl;
					return CallNextHookEx(NULL, nCode, wParam, lParam);
				}
				int index = randEx(0, fileNames_2.size() - 1);
				// ȡ����Ŀ¼
				string dir = getRunPath();
				cout << dir << endl;
				string path_ = dir + fileNames_2[index].substr(1);
				
				if (flag_fast) {
					playtheSound(path_);
				}
				else {
					// �����߳�
					// �̷߳���
					thread t1(playtheSound, path_);
					t1.detach();
				}
			}
		}
		else if (flag == 1)//���ģʽ
		{
			// �õ�sounds�ļ����µ������ļ�
			vector<string> fileNames;
			string path("./sounds/random");
			getFileNames(path, fileNames);
			// ���fileNamesΪ�գ�ֱ�ӷ���
			if (fileNames.empty())
			{
				cout << "���ģʽ�ļ�Ϊ��" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// �����ȡ�����е�һ���ļ���
			int index = randEx(0, fileNames.size() - 1);
			/*
			if (cha < 1000) {
				index++;
				if (index == fileNames.size()) {//����������
					index = 0;
				}
			}
			else {
				index = 8 * randEx(0, fileNames.size() / 8 - 1);
				cout << "�����" << index << endl;
				cout << fileNames[index] << endl;//./sounds/random/301.wav
			}
			*/
			// ȡ����Ŀ¼
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			// �����߳�
			//thread t1(playtheSound, path_);
			// �̷߳���
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
			cout << "����--9999--��" << ks->vkCode << endl;
			// ��ؼ���
			switch (ks->vkCode)
			{
			case 0x30:
			case 0x60:
				cout << "��⵽������"
					<< "0" << endl;
				key = "0";
				break;
			case 0x31:
			case 0x61:
				cout << "��⵽������"
					<< "1" << endl;
				key = "1";
				break;
			case 0x32:
			case 0x62:
				cout << "��⵽������"
					<< "2" << endl;
				key = "2";
				break;
			case 0x33:
			case 0x63:
				cout << "��⵽������"
					<< "3" << endl;
				key = "3";
				break;
			case 0x34:
			case 0x64:
				cout << "��⵽������"
					<< "4" << endl;
				key = "4";
				break;
			case 0x35:
			case 0x65:
				cout << "��⵽������"
					<< "5" << endl;
				key = "5";
				break;
			case 0x36:
			case 0x66:
				cout << "��⵽������"
					<< "6" << endl;
				key = "6";
				break;
			case 0x37:
			case 0x67:
				cout << "��⵽������"
					<< "7" << endl;
				key = "7";
				break;
			case 0x38:
			case 0x68:
				cout << "��⵽������"
					<< "8" << endl;
				key = "8";
				break;
			case 0x39:
			case 0x69:
				cout << "��⵽������"
					<< "9" << endl;
				key = "9";
				break;
			case 0x41:
				cout << "��⵽������"
					<< "A" << endl;
				key = "A";
				break;
			case 0x42:
				cout << "��⵽������"
					<< "B" << endl;
				key = "B";
				break;
			case 0x43:
				cout << "��⵽������"
					<< "C" << endl;
				key = "C";
				break;
			case 0x44:
				cout << "��⵽������"
					<< "D" << endl;
				key = "D";
				break;
			case 0x45:
				cout << "��⵽������"
					<< "E" << endl;
				key = "E";
				break;
			case 0x46:
				cout << "��⵽������"
					<< "F" << endl;
				key = "F";
				break;
			case 0x47:
				cout << "��⵽������"
					<< "G" << endl;
				key = "G";
				break;
			case 0x48:
				cout << "��⵽������"
					<< "H" << endl;
				key = "H";
				break;
			case 0x49:
				cout << "��⵽������"
					<< "I" << endl;
				key = "I";
				break;
			case 0x4A:
				cout << "��⵽������"
					<< "J" << endl;
				key = "J";
				break;
			case 0x4B:
				cout << "��⵽������"
					<< "K" << endl;
				key = "K";
				break;
			case 0x4C:
				cout << "��⵽������"
					<< "L" << endl;
				key = "L";
				break;
			case 0x4D:
				cout << "��⵽������"
					<< "M" << endl;
				key = "M";
				break;
			case 0x4E:
				cout << "��⵽������"
					<< "N" << endl;
				key = "N";
				break;
			case 0x4F:
				cout << "��⵽������"
					<< "O" << endl;
				key = "O";
				break;
			case 0x50:
				cout << "��⵽������"
					<< "P" << endl;
				key = "P";
				break;
			case 0x51:
				cout << "��⵽������"
					<< "Q" << endl;
				key = "Q";
				break;
			case 0x52:
				cout << "��⵽������"
					<< "R" << endl;
				key = "R";
				break;
			case 0x53:
				cout << "��⵽������"
					<< "S" << endl;
				key = "S";
				break;
			case 0x54:
				cout << "��⵽������"
					<< "T" << endl;
				key = "T";
				break;
			case 0x55:
				cout << "��⵽������"
					<< "U" << endl;
				key = "U";
				break;
			case 0x56:
				cout << "��⵽������"
					<< "V" << endl;
				key = "V";
				break;
			case 0x57:
				cout << "��⵽������"
					<< "W" << endl;
				key = "W";
				break;
			case 0x58:
				cout << "��⵽������"
					<< "X" << endl;
				key = "X";
				break;
			case 0x59:
				cout << "��⵽������"
					<< "Y" << endl;
				key = "Y";
				break;
			case 0x5A:
				cout << "��⵽������"
					<< "Z" << endl;
				key = "Z";
				break;
			case 0x6A:
				cout << "��⵽������"
					<< "*" << endl;
				key = "*";
				break;
			case 0x6B:
				cout << "��⵽������"
					<< "+" << endl;
				key = "+";
				break;
			case 0x6D:
				cout << "��⵽������"
					<< "-" << endl;
				key = "-";
				break;
			case 0x6E:
				cout << "��⵽������"
					<< "." << endl;
				key = ".";
				break;
			case 0x6F:
				cout << "��⵽������"
					<< "/" << endl;
				key = "/";
				break;
			case 0x0D:
				cout << "��⵽������"
					<< "Enter" << endl;
				key = "Enter";
				break;
			case 0xA0:
			case 0xA1:
				cout << "��⵽������"
					<< "Shift" << endl;
				key = "Shift";
				break;
			case 0x08:
				cout << "��⵽������"
					<< "Backspace" << endl;
				key = "Backspace";
				break;
			case 0x20:
				cout << "��⵽������"
					<< "Space" << endl;
				key = "Space";
				break;
			case 162:
				cout << "��⵽������"
					<< "Ctrl" << endl;
				key = "Ctrl";
				break;
			default:
				cout << "����������" << endl;
				key = "default";
				break;
			}
			// �õ�sounds�ļ����µ������ļ�
			vector<string> fileNames;
			string path_keyname("./sounds/piano");
			getFileNames(path_keyname, fileNames);
			// ���fileNamesΪ�գ�ֱ�ӷ���
			if (fileNames.empty())
			{
				cout << "���ģʽ�ļ�Ϊ��" << endl;
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
				// ����key.wav��Ч
				// cout << "������Ч" << path;
				// ȡ����Ŀ¼
				string dir = getRunPath();
				// ƴ����Ч�ļ�·��
				path = dir + path;
				cout << "������Ч" << path + "\n";
				// ������Ч
				//thread t1(playtheSound, path);
				// �̷߳���
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
		else if (flag == 4)//�����
		{
			// �õ�sounds�ļ����µ������ļ�
			vector<string> fileNames;
			string path("./sounds/qifengle");
			getFileNames(path, fileNames);
			// ���fileNamesΪ�գ�ֱ�ӷ���
			if (fileNames.empty())
			{
				cout << "���ģʽ�ļ�Ϊ��" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// �����ȡ�����е�һ���ļ���
			//int index = randEx(0, fileNames.size() - 1);
			if (cha < 1000) {
				index++;
				if (index == fileNames.size()) {//����������
					index = 0;
				}
			}
			else {
				index = 8 * randEx(0, fileNames.size() / 8 - 1);
				cout << "�����" << index << endl;
				cout << fileNames[index] << endl;//./sounds/random/301.wav
			}
			// ȡ����Ŀ¼
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			// �����߳�
			//thread t1(playtheSound, path_);
			// �̷߳���
			//t1.detach();
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 5)//���罣��
		{
			string key = keynameFun(ks->vkCode);
			// �õ�sounds�ļ����µ������ļ�
			vector<string> fileNames;
			string path("./sounds/yasuo");
			getFileNames(path, fileNames);
			// ���fileNamesΪ�գ�ֱ�ӷ���
			if (fileNames.empty())
			{
				cout << "���ģʽ�ļ�Ϊ��" << endl;
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
				// ȡ����Ŀ¼
				string dir = getRunPath();
				// ƴ����Ч�ļ�·��
				path = dir + path;
				cout << "������Ч" << path + "\n";
				if (flag_fast) {
					playtheSound(path);
				}
				else {
					thread t1(playtheSound, path);
					t1.detach();
				}
			}

		}
		else if (flag == 6)//֪����
		{
			// �õ�sounds�ļ����µ������ļ�
			vector<string> fileNames;
			string path("./sounds/zhixia");
			getFileNames(path, fileNames);
			// ���fileNamesΪ�գ�ֱ�ӷ���
			if (fileNames.empty())
			{
				cout << "���ģʽ�ļ�Ϊ��" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// �����ȡ�����е�һ���ļ���
			int index = randEx(0, fileNames.size() - 1);
			// ȡ����Ŀ¼
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				// �����߳�
				// �̷߳���
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 7)//�齫��
		{
			// �õ�sounds�ļ����µ������ļ�
			vector<string> fileNames;
			string path("./sounds/majiang");
			getFileNames(path, fileNames);
			// ���fileNamesΪ�գ�ֱ�ӷ���
			if (fileNames.empty())
			{
				cout << "���ģʽ�ļ�Ϊ��" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// �����ȡ�����е�һ���ļ���
			int index = randEx(0, fileNames.size() - 1);
			// ȡ����Ŀ¼
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				// �����߳�
				// �̷߳���
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 8)//������
		{
			// �õ�sounds�ļ����µ������ļ�
			vector<string> fileNames;
			string path("./sounds/fengmingqi");
			getFileNames(path, fileNames);
			// ���fileNamesΪ�գ�ֱ�ӷ���
			if (fileNames.empty())
			{
				cout << "���ģʽ�ļ�Ϊ��" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// �����ȡ�����е�һ���ļ���
			int index = randEx(0, fileNames.size() - 1);
			// ȡ����Ŀ¼
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				// �����߳�
				// �̷߳���
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 9)//ľ����
		{
			// �õ�sounds�ļ����µ������ļ�
			vector<string> fileNames;
			string path("./sounds/muyu");
			getFileNames(path, fileNames);
			// ���fileNamesΪ�գ�ֱ�ӷ���
			if (fileNames.empty())
			{
				cout << "���ģʽ�ļ�Ϊ��" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// �����ȡ�����е�һ���ļ���
			int index = randEx(0, fileNames.size() - 1);
			// ȡ����Ŀ¼
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				// �����߳�
				// �̷߳���
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 10)//�����
		{
			// �õ�sounds�ļ����µ������ļ�
			vector<string> fileNames;
			string path("./sounds/yudi");
			getFileNames(path, fileNames);
			// ���fileNamesΪ�գ�ֱ�ӷ���
			if (fileNames.empty())
			{
				cout << "���ģʽ�ļ�Ϊ��" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// �����ȡ�����е�һ���ļ���
			int index = randEx(0, fileNames.size() - 1);
			// ȡ����Ŀ¼
			string dir = getRunPath();
			cout << dir << endl;
			//string path_ = dir + fileNames[index].substr(1, dir.size() - 1);
			//string path_ = dir + fileNames[index].substr(1, fileNames[index].size() - 1);
			string path_ = dir + fileNames[index].substr(1);
			if (flag_fast) {
				playtheSound(path_);
			}
			else {
				// �����߳�
				// �̷߳���
				thread t1(playtheSound, path_);
				t1.detach();
			}
		}
		else if (flag == 11)//Cader
		{
			string key = keynameFun(ks->vkCode);
			// �õ�sounds�ļ����µ������ļ�
			vector<string> fileNames;
			string path("./sounds/cedar");
			getFileNames(path, fileNames);
			// ���fileNamesΪ�գ�ֱ�ӷ���
			if (fileNames.empty())
			{
				cout << "���ģʽ�ļ�Ϊ��" << endl;
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
				// ȡ����Ŀ¼
				string dir = getRunPath();
				// ƴ����Ч�ļ�·��
				path = dir + path;
				cout << "������Ч" << path + "\n";
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
				// ���fileNames_2Ϊ�գ�ֱ�ӷ���
				if (fileNames_2.empty())
				{
					cout << "���ģʽdefault�ļ�Ϊ��" << endl;
					return CallNextHookEx(NULL, nCode, wParam, lParam);
				}
				int index = randEx(0, fileNames_2.size() - 1);
				// ȡ����Ŀ¼
				string dir = getRunPath();
				cout << dir << endl;
				string path_ = dir + fileNames_2[index].substr(1);

				if (flag_fast) {
					playtheSound(path_);
				}
				else {
					// �����߳�
					// �̷߳���
					thread t1(playtheSound, path_);
					t1.detach();
				}
			}
		}
		else if (flag == 12)//����
		{
		// �õ�sounds�ļ����µ������ļ�
		vector<string> fileNames;
		string path("./sounds/yin");
		getFileNames(path, fileNames);
		// ���fileNamesΪ�գ�ֱ�ӷ���
		if (fileNames.empty())
		{
			cout << "���ģʽ�ļ�Ϊ��" << endl;
			return CallNextHookEx(NULL, nCode, wParam, lParam);
		}
		// �����ȡ�����е�һ���ļ���
		int index = randEx(0, fileNames.size() - 1);
		// ȡ����Ŀ¼
		string dir = getRunPath();
		cout << dir << endl;
		string path_ = dir + fileNames[index].substr(1);
		if (flag_fast) {
			playtheSound(path_);
		}
		else {
			// �����߳�
			// �̷߳���
			thread t1(playtheSound, path_);
			t1.detach();
		}
		}
	}

	// ����Ϣ���ݸ��������е���һ������
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

//�����������
HHOOK mouse_Hook;

LRESULT CALLBACK LowLevelMouseProc(INT nCode,
	WPARAM wParam,
	LPARAM lParam
);
BOOL UninstallHook();  //ж��  
BOOL InstallKbHook();     //��װ


BOOL InstallKbHook()
{

	if (mouse_Hook)   UninstallHook();
	mouse_Hook = SetWindowsHookEx(
		WH_MOUSE_LL,   // �������ͣ�WH_MOUSE_LL Ϊ��깳��
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
		//������  
		//if (wParam == WM_LBUTTONDOWN || wParam == WM_RBUTTONDOWN || wParam == WM_MBUTTONDOWN || wParam == WM_LBUTTONUP || wParam == WM_RBUTTONUP || wParam == WM_MBUTTONUP) {
		if (wParam == WM_LBUTTONUP || wParam == WM_RBUTTONUP || wParam == WM_MBUTTONUP) {
			cout << "��걻�����" << endl;

			
			vector<string> fileNames;
			string path("./sounds/mouse");
			getFileNames(path, fileNames);
			// ���fileNamesΪ�գ�ֱ�ӷ���
			if (fileNames.empty())
			{
				cout << "���ģʽ�ļ�Ϊ��" << endl;
				return CallNextHookEx(NULL, nCode, wParam, lParam);
			}
			// �����ȡ�����е�һ���ļ���
			int index = randEx(0, fileNames.size() - 1);

			// ȡ����Ŀ¼
			string dir = getRunPath();
			cout << dir << endl;
			string path_mouse = dir + fileNames[index].substr(1);

			if (flag_mouse) {
				if (flag_fast) {
					playtheSound(path_mouse);
				}
				else {
					// �����߳�
					thread t1(playtheSound, path_mouse);
					// �̷߳���
					t1.detach();
				}
			}
		}
	}
		default:break;
	}

	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// ���hook
int key_hook2()
{
	// ��װ����
	//InstallKbHook();
	mouse_Hook = SetWindowsHookEx(
		WH_MOUSE_LL,   // �������ͣ�WH_MOUSE_LL Ϊ��깳��
		(HOOKPROC)(LowLevelMouseProc),
		//AfxGetApp()->m_hInstance, 
		//GetModuleHandleA(NULL),
		GetModuleHandle(NULL),
		NULL);

	// ����©����Ϣ������Ȼ����Ῠ��
	
	MSG msg;
	while (1)
	{
		// �����Ϣ����������Ϣ
		if (PeekMessageA(
			&msg,			// MSG ���������Ϣ
			NULL,			// �����Ϣ�Ĵ��ھ����NULL��������ǰ�߳����д�����Ϣ
			NULL,			// �����Ϣ��Χ�е�һ����Ϣ��ֵ��NULL�����������Ϣ������������ͬʱΪNULL��
			NULL,			// �����Ϣ��Χ�����һ����Ϣ��ֵ��NULL�����������Ϣ������������ͬʱΪNULL��
			PM_REMOVE // ������Ϣ�ķ�ʽ��PM_REMOVE���������Ϣ�Ӷ�����ɾ��
		))
		{
			// �Ѱ�����Ϣ���ݸ��ַ���Ϣ
			TranslateMessage(&msg);

			// ����Ϣ���ɸ����ڳ���
			DispatchMessageW(&msg);
		}
		else
			Sleep(100); // ����CPUȫ��������
	}
	
	// ɾ������
	//UninstallHook();
	if (mouse_Hook) {
		UnhookWindowsHookEx(mouse_Hook);
		mouse_Hook = NULL;  //set NULL  
	}
	return 0;
}

// ����hook
int key_hook()
{
	// ��װ����
	keyboardHook = SetWindowsHookEx(
		WH_KEYBOARD_LL,					// �������ͣ�WH_KEYBOARD_LL Ϊ���̹���
		LowLevelKeyboardProc,		// ָ���Ӻ�����ָ��
		GetModuleHandleA(NULL), // Dll ���
		NULL);
	InstallKbHook();

	if (keyboardHook == 0)
	{
		cout << "�ҹ�����ʧ��" << endl;
		return -1;
	}

	// ����©����Ϣ������Ȼ����Ῠ��
	MSG msg;
	while (1)
	{
		// �����Ϣ����������Ϣ
		if (PeekMessageA(
			&msg,			// MSG ���������Ϣ
			NULL,			// �����Ϣ�Ĵ��ھ����NULL��������ǰ�߳����д�����Ϣ
			NULL,			// �����Ϣ��Χ�е�һ����Ϣ��ֵ��NULL�����������Ϣ������������ͬʱΪNULL��
			NULL,			// �����Ϣ��Χ�����һ����Ϣ��ֵ��NULL�����������Ϣ������������ͬʱΪNULL��
			PM_REMOVE // ������Ϣ�ķ�ʽ��PM_REMOVE���������Ϣ�Ӷ�����ɾ��
		))
		{
			// �Ѱ�����Ϣ���ݸ��ַ���Ϣ
			TranslateMessage(&msg);

			// ����Ϣ���ɸ����ڳ���
			DispatchMessageW(&msg);
		}
		else
			Sleep(0); // ����CPUȫ��������
	}
	// ɾ������
	UnhookWindowsHookEx(keyboardHook);
	UninstallHook();
	return 0;
}



#define IDR_PAUSE 12
#define IDR_START 13
#define IDR_TEST 14
#define IDR_OPENDIR 18
// �˵�����
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
HMENU hmenu;//�˵����

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	NOTIFYICONDATA nid;
	UINT WM_TASKBARCREATED;
	POINT pt;//���ڽ����������
	int xx;//���ڽ��ղ˵�ѡ���ֵ

	// ��Ҫ�޸�TaskbarCreated������ϵͳ�������Զ������Ϣ
	WM_TASKBARCREATED = RegisterWindowMessage(TEXT("TaskbarCreated"));
	switch (message)
	{
	case WM_CREATE://���ڴ���ʱ�����Ϣ.
		nid.cbSize = sizeof(nid);
		nid.hWnd = hwnd;
		nid.uID = 0;
		nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
		nid.uCallbackMessage = WM_USER;
		nid.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		lstrcpy(nid.szTip, szAppClassName);
		Shell_NotifyIcon(NIM_ADD, &nid);
		hmenu = CreatePopupMenu();//���ɲ˵�
		AppendMenu(hmenu, MF_UNCHECKED, IDR_RANDOM, L"���ģʽ");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_KETNAME, L"����ģʽ");
		AppendMenu(hmenu, MF_CHECKED, IDR_PIANO, L"����ģʽ");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_CEDAR, L"Cedar");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_YIN, L"����ģʽ");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_QIFENGLE, L"�����");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_YASUO, L"���罣��");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_ZHIXIA, L"֪����");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_MAJIANG, L"�齫��");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_FENGMINGQI, L"������");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_MUYU, L"ľ����");
		AppendMenu(hmenu, MF_UNCHECKED, IDR_YUDI, L"���");

		AppendMenu(hmenu, MF_UNCHECKED, IDR_FAST, L"��Ч���");
		AppendMenu(hmenu, MF_CHECKED, IDR_MOUSE, L"�����Ч");
		AppendMenu(hmenu, MF_STRING, IDR_OPENDIR, L"��Ŀ¼");
		//AppendMenu(hmenu, MF_STRING, IDR_AUTORUN, L"��������");
		AppendMenu(hmenu, MF_STRING, IDR_QUIT, L"�˳�");
		break;
	case WM_USER://����ʹ�øó���ʱ�����Ϣ.
		if (lParam == WM_RBUTTONDOWN)
		{
			GetCursorPos(&pt);//ȡ�������
			::SetForegroundWindow(hwnd);//����ڲ˵��ⵥ������˵�����ʧ������
			// EnableMenuItem(hmenu, IDR_PAUSE, MF_GRAYED);//�ò˵��е�ĳһ����
			xx = TrackPopupMenu(hmenu, TPM_RETURNCMD, pt.x, pt.y, NULL, hwnd, NULL);//��ʾ�˵�����ȡѡ��ID
			if (xx == IDR_QUIT) {
				// �Ƴ�����ͼ��
				 // ж������ͼ��
				NOTIFYICONDATA nid;
				nid.cbSize = sizeof(NOTIFYICONDATA);
				nid.hWnd = hwnd;
				nid.uID = 0;
				Shell_NotifyIcon(NIM_DELETE, &nid);
				// �˳�����
				PostQuitMessage(0);
			}
			if (xx == IDR_RANDOM) {
				// ѡ�����ģʽ ȡ������ģʽ
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
				// ѡ�м���ģʽ ȡ�����ģʽ
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
				// ��Ч���
				flag_fast = !flag_fast;
				if (flag_fast) {
					CheckMenuItem(hmenu, IDR_FAST, MF_CHECKED);
				}
				else {
					CheckMenuItem(hmenu, IDR_FAST, MF_UNCHECKED);
				}

			}
			if (xx == IDR_MOUSE) {
				// ��Ч���
				flag_mouse = !flag_mouse;
				if (flag_mouse) {
					CheckMenuItem(hmenu, IDR_MOUSE, MF_CHECKED);
				}
				else {
					CheckMenuItem(hmenu, IDR_MOUSE, MF_UNCHECKED);
				}

			}
			if (xx == IDR_OPENDIR) {
				// ��Ŀ¼
				init_res(1);
			}
		}
		break;
	case WM_DESTROY://��������ʱ�����Ϣ.
		Shell_NotifyIcon(NIM_DELETE, &nid);
		PostQuitMessage(0);
		break;
	default:
		/*
		* ��ֹ��Explorer.exe �����Ժ󣬳�����ϵͳϵͳ�����е�ͼ�����ʧ
		*
		* ԭ��Explorer.exe �����������ؽ�ϵͳ����������ϵͳ������������ʱ�����ϵͳ������
		* ע�����TaskbarCreated ��Ϣ�Ķ������ڷ���һ����Ϣ������ֻ��Ҫ��׽�����Ϣ�����ؽ�ϵ
		* ͳ���̵�ͼ�꼴�ɡ�
		*/
		if (message == WM_TASKBARCREATED)
			SendMessage(hwnd, WM_CREATE, wParam, lParam);
		break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}



// �������½�ͼ��
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

	// �˴�ʹ��WS_EX_TOOLWINDOW ������������ʾ���������ϵĴ��ڳ���ť
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

	cout << "��Ϣ start" << endl;

	//��Ϣѭ��
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}



int main()
{
	// ��ʼ������ ����sounds�ļ��� ��д�������Ч �����û������Զ����޸�
	cout << '1' << endl;
	init_res(0);
	cout << '2' << endl;
	// ���߳�ȥkeyhook
	thread t2(key_hook);
	cout << 3 << endl;
	// �̷߳���
	t2.detach();

	//thread t3(key_hook2);
	cout << 4 << endl;
	// �̷߳���
	//t3.detach();
	cout << 5 << endl;
	SetIco();

	cout << 6 << endl;

}
