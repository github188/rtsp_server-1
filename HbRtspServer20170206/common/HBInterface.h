#ifndef HBINTERFACE_H_
#define HBINTERFACE_H_
#include <string>
#include <list>
#ifdef HAIBO_API
#define HAIBO_API extern "C" _declspec(dllimport) 
#else
#define HAIBO_API extern "C" _declspec(dllexport) 
#endif

//----------��̨����---------------//
#define HB_ZOOM_IN		1 //������(���ʱ��) 
#define HB_ZOOM_OUT		2 //�����С(���ʱ�С) 
#define HB_TILT_UP		3 //��̨���� 
#define HB_TILT_DOWN	4 //��̨�¸� 
#define HB_PAN_LEFT		5 //��̨��ת 
#define HB_PAN_RIGHT	6 //��̨��ת 
#define HB_UP_LEFT		7 //��̨��������ת 
#define HB_UP_RIGHT		8 //��̨��������ת 
#define HB_DOWN_LEFT	9 //��̨�¸�����ת 
#define HB_DOWN_RIGHT	10 //��̨�¸�����ת 
#define HB_PRESET		11 //����Ԥ��λ
#define HB_ASSIST		12 //���ø���λ
#define HB_STOP         13 //ֹͣ

struct HB_3D_POSITION
{
	long bx;
	long by;
	long ex;
	long ey;
	long rx;
	long ry;
};

/*************************************************
Function:       // HB_VIDEO_CALLBACK
Description:    // �ص�����
Input:          // buffer-���ݻ�������bufferSize-��������С
*************************************************/
typedef int (__stdcall *HB_VIDEO_CALLBACK)(long lplayHandle, char* buffer, long bufferSize);

/*************************************************
Function:       // NET_HB_Init
Description:    // SDK��ʼ��
Input:          // ��
Output:         // ��
*************************************************/
HAIBO_API int NET_HB_Init();

/*************************************************
Function:       // NET_HB_Cleanup
Description:    // SDK�ͷ�
Input:          // ��
Output:         // ��
*************************************************/
HAIBO_API void NET_HB_Cleanup();

/*************************************************
Function:       // NET_HB_LoginEx
Description:    // ��¼ϵͳ----������¼
Input:          // szUser-�û���  szPwd-����	szUnitIP-��ý�嵥ԪIP	Port-��ý�嵥Ԫ�˿�
Output:         // ��
Return:         // �ɹ�����0���������ش������
*************************************************/
HAIBO_API int NET_HB_LoginEx(const char* szUser, const char* szPwd, const char* szUnitIP, long Port);

/*************************************************
Function:       // NET_HB_Login
Description:    // ��¼ϵͳ---��������¼
Input:          // szUser-�û���	szPwd-����	szServerIP-���÷�����IP	 Port-���÷������˿�
Output:         // ��
Return:         // �ɹ�����0���������ش������
*************************************************/
HAIBO_API int NET_HB_Login(const char* szUser, const char* szPwd, const char* szServerIP, long Port);

/*************************************************
Function:       // NET_HB_Logout
Description:    // �˳�ϵͳ
Input:          // ��
Output:         // ��
Return:         // ��
*************************************************/
HAIBO_API void NET_HB_Logout(void);

/*************************************************
Function:       // NET_HB_GetCamResourceList
Description:    // ��ȡ��Դ�б�---�������ӿ�
Input:          // ��
Output:         // ��
Return:         // ��
*************************************************/
HAIBO_API int NET_HB_GetCamResourceList(std::string &strCamResourceInfo);

/*************************************************
Function:       // NET_HB_SwitchCam
Description:    // �л������---�������ӿ�
Input:          // lCam-��������
Output:         // ��
Return:         // �ɹ����ؾ����ʧ�ܷ��ش������
*************************************************/
HAIBO_API int NET_HB_SwitchCam(long lCam);

/*************************************************
Function:       // NET_HB_SetVideoCallBack
Description:    // ���ûص�����
Input:          // callBack-�ص�����
Output:         // ��
Return:         // ��
*************************************************/
HAIBO_API void NET_HB_SetVideoCallBack(HB_VIDEO_CALLBACK callBack);

/*************************************************
Function:       // NET_HB_SwitchCamUrl
Description:    // �л������---�������ӿ�
Input:          // lCam--��������
Output:         // VideoAddress--��Ƶ�鲥��ַ
Return:         // �ɹ����ؾ����ʧ�ܷ��ش������
*************************************************/
HAIBO_API int NET_HB_SwitchCamUrl(long lCam,char *&VideoAddress);

/*************************************************
Function:       // NET_HB_PTZControl
Description:    // ��̨����---�������ӿ�
Input:          // lPlayHandle-ʵʱ���������lTZCommand-�������lData-��������
Output:         // ��
Return:         // �ɹ�����0���������ش������
*************************************************/
HAIBO_API int NET_HB_PTZControl(long lPlayHandle, long lTZCommand, long lData);

/*************************************************
Function:       // NET_HB_AbandonCam
Description:    // �ͷ������---�������ӿ�
Input:          // lPlayHandle-ʵʱ�������
Output:         // ��
Return:         // �ɹ�����0���������ش������
*************************************************/
HAIBO_API int NET_HB_AbandonCam(long lPlayHandle);

/*************************************************
Function:       // NET_HB_AbandonCamUrl
Description:    // �ͷ������---�������ӿ�
Input:          // lPlayHandle-ʵʱ�������
Output:         // ��
Return:         // �ɹ�����0���������ش������
*************************************************/
HAIBO_API int NET_HB_AbandonCamUrl(long lPlayHandle);

/*************************************************
Function:       // NET_HB_SetPTZSpeed
Description:    // ������̨�ٶ�
Input:          // lspeed-�ٶ�ֵ
Output:         // ��
Return:         // ��
*************************************************/
HAIBO_API int NET_HB_SetPTZSpeed(long lspeed);

/*************************************************
Function:       // NET_HB_PTZPreset
Description:    // Ԥ��λ����
Input:          // lCam-��������,lNo-Ԥ��λ���
Output:         // ��
Return:         // �ɹ�����0���������ش������
*************************************************/
HAIBO_API int NET_HB_PTZPreset(long lCam, long lNo);

/*************************************************
Function:       // NET_HB_FastPosition
Description:    // ���ٶ�λ
Input:          // lPlayHandle-ʵʱ�������, Positon-��������
Output:         // 
Return:         // �ɹ�����0���������ش������
*************************************************/
HAIBO_API int NET_HB_FastPosition(long lPlayHandle, HB_3D_POSITION &Positon);

/*************************************************
Function:       // NET_HB_QueryVideoRecordEx
Description:    // ��ʷ¼���ѯ---�����ӿ�
Input:          // lCam-�������� ulStarttime-��ѯ�Ŀ�ʼʱ�� ulEndtime-��ѯ����ֹʱ�� szUnitIP-��ԪIP szUnitPort-��Ԫ�˿� 
Output:         // recordlist-��ʷ�ļ��б�xml
Return:         // �ɹ�����0���������ش������
*************************************************/
HAIBO_API int NET_HB_QueryVideoRecordEx(long CamID, unsigned long ulStarttime, unsigned long ulEndtime, const char* szUnitIP, int szUnitPort,char *&recordlist);

/*************************************************
Function:       // NET_HB_QueryVideoRecord
Description:    // ��ʷ¼���ѯ---�������ӿ�
Input:          // lCam-�������� ulStarttime-��ѯ�Ŀ�ʼʱ�� ulEndtime-��ѯ����ֹʱ��
Output:         // recordlist-��ʷ�ļ��б�xml
Return:         // �ɹ�����0���������ش������
*************************************************/
HAIBO_API int NET_HB_QueryVideoRecord(long CamID, unsigned long ulStarttime, unsigned long ulEndtime, char *&recordlist);

/*************************************************
Function:       // NET_HB_GetErrMsg
Description:    // �õ�������Ϣ
Input:          // lError-�������
Output:         // ��
Return:         // ������Ϣ
*************************************************/
HAIBO_API const char* NET_HB_GetErrMsg(int lError);

#endif

