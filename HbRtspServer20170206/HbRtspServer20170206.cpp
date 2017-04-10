// HbRtspServer20170206.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "RtspListener.h"
#include <windows.h>
#include "common/HBInterface.h"


#pragma comment(lib,"HBNetSDK")





//��ȡ��ǰ���������Ŀ¼
string GetAppPathA()
{
	char szExePath[MAX_PATH] = { 0 };
	GetModuleFileNameA(NULL, szExePath, MAX_PATH);
	char *pstr = strrchr(szExePath, '\\');
	memset(pstr + 1, 0, 1);
	string strAppPath(szExePath);
	return strAppPath;
}



int _tmain(int argc, _TCHAR* argv[])
{

	//��־�����ʼ��[add liyang 170110]
	//PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("log4cplus.cfg"));//��������
	//gvlog = Logger::getInstance(LOG4CPLUS_TEXT("HBRTSP_SERVER"));
	//SharedAppenderPtr pConsoleAppender(new ConsoleAppender());
	//gvlog.addAppender(pConsoleAppender);
	//LOG4CPLUS_DEBUG(gvlog, "����־�����ʼ����ɡ�");
	

	system("COLOR B");

	/*��ʼ��*/
	char ip[256] = { 0 };
	GetPrivateProfileStringA("net", "listenip", "127.0.0.1", ip, 256, "./HbRtspServer20170206.ini");
	int port=GetPrivateProfileIntA("net", "listenport", 554, "./HbRtspServer20170206.ini");
	int maxtask = GetPrivateProfileIntA("net", "maxtask", 8, "./HbRtspServer20170206.ini");
	int minrtpPort = GetPrivateProfileIntA("net", "minrtpPort",30000, "./HbRtspServer20170206.ini");
	//LOG(INFO) << "���ؼ����˿ڣ�" <<port<< " �������������"<<maxtask<<" ��Сrtp�˿ڣ�"<<minrtpPort;

	/*ƽ̨��¼*/
	char login_ip[256] = { 0 };
	GetPrivateProfileStringA("login", "ip", "127.0.0.1", login_ip, 256, "./HbRtspServer20170206.ini");
	int login_port = GetPrivateProfileIntA("login", "port", 8080, "./HbRtspServer20170206.ini");
	char login_user[256] = { 0 };
	GetPrivateProfileStringA("login", "user", "admin", login_user, 256, "./HbRtspServer20170206.ini");
	char login_password[256] = { 0 };
	GetPrivateProfileStringA("login", "password", "admin", login_password, 256, "./HbRtspServer20170206.ini");
	
	NET_HB_Init();

	int ret = NET_HB_Login(login_user, login_password, login_ip, login_port);
	if (ret!=0)
	{
		exit(0);
	}

	/*����rtsp����*/
	CRtspListener myRtspService;
	ret=myRtspService.startService(ip, port, maxtask,minrtpPort);
	if (-1==ret)
	{
		exit(0);
	}
	while (true)
	{
		Sleep(100);
	}
	return 0;
}

