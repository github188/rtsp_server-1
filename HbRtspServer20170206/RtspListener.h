#pragma once
typedef unsigned int uint32_t;
#include <WinSock2.h>
#include "RtspAnalyzer.h"
#pragma comment(lib,"ws2_32")
#include <vector>
using namespace std;
#define  max_mtu_size    1500
#define  max_ip_len      32
#include "common/HBInterface.h"
#define  MAX_SOCKET_RECV_BUFFER_SIZE   (8*1024*1024)//512*1024
#define max_mpeg2ps_len		(8*1024*1024)
//ps
#include "HbRtpDemux.h"
#include "HbMpeg2psDemux.h"
#include "HbRtpMux.h"
#include "rtpMuxer_udp.h"

struct rtsp_t
{
	void*    arg;
	SOCKET   connSock;
	int      isUsed;
	SOCKET   rtpSock;
	SOCKET   rtcpSock;
	char*    recvbuffer;
	char*    resbuffer;
	int      rtpPort;		//server
	int      rtcpPort;		//server
	/*Ĭ��һ��ý���Ӧһ���Ự*/
	int      cli_rtpPort;	//client
	int      cli_rtcpPort;	//client
	char     cli_ip[max_ip_len];//client
	int      cli_isUsed2;//�����Ƿ��������
	int      cli_isExit;	//�Ƿ�Ͽ�
	int      cli_isBye;		
	int      cli_ssrc;		//ssrc
	int      cli_logicid;	//������
	/*���ݽ���*/
	char     video_multicast_recvip[32];//video����ip
	int      video_multicast_recvport;  //video���ն˿�
	/*thread*/
	int      threadid;
	/*ͬ�����*/
	CRITICAL_SECTION  cric_session;
	CRITICAL_SECTION  cric_rtp;
	CRITICAL_SECTION  cric_rtp2;
	CRITICAL_SECTION  cric_rtp3;
	HANDLE            hndRtpExit;
	int               isActive;
};


class CRtspListener
{
public:
	CRtspListener();
	~CRtspListener();
private:
	char            m_listenip[256];
	int             m_listenport;
	int             m_taskcount;
	SOCKET          m_listensock;
	SOCKADDR_IN     m_listenaddr;
	int             m_isExit;
	int             m_isExit2;
	vector<rtsp_t*> m_threads;
	CRITICAL_SECTION m_cric;
protected:
	static unsigned int _stdcall ListenThread(void* arg);
	static unsigned int _stdcall SessionThread(void* arg);
	static unsigned int _stdcall RtpThread(void* arg);
	static unsigned int _stdcall RtcpThread(void* arg);
public:
	int  startService(const char* ip,int port,int maxcount,int minrtpPort);
	void closeService();
};

