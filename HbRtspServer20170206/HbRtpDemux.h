#pragma once
#include "util.h"

struct SessionLevel_t//�˰汾��ҪӦ���ڽ����鲥������rtsp�汾������ȫ����
{
	int   version;//�汾��
	char  connip;//�Ự����ip��ַ
};


struct MediaLevel_Video_t
{
	MediaType  mt;//ý������
	char       connip;//����ip
	short      recvport;//���ն˿�
	Proto      tranpro;//����Э��
	char       encodename[MAX_ATTIBUTE_LEN];//��������
	int        timescale;//������׼
	int        packetization_mode;//���ģʽ
};

struct MediaLevel_Audio_t
{
	MediaType  mt;//ý������
	char       connip;//����ip
	short      recvport;//���ն˿�
	Proto      tranpro;//����Э��
	char       encodename[MAX_ATTIBUTE_LEN];//��������
	int        samplerate;//����Ƶ��
	int        channels;//��Ƶͨ����
	int        mode;//����ģʽ(aac����ģʽ�Ƚ϶�)
};


static const char h264_start_code[4]={0x00,0x00,0x00,0x01};

#include<map>

class CHbRtpDemux
{
public:
	CHbRtpDemux(void);
	~CHbRtpDemux(void);

private:
	char*     m_h264ptr;//h264ָ֡��
	char*     m_audioptr;//��Ƶָ��
	bool      firstframe;//�Ƿ��һ֡h264����
private:
	unsigned        timestamp;
	unsigned        currnumsamples;
	vector<rtp_t>   v_rtp_list;
private://test
	map<int,int>    m_newList;
public:
	bool  open();
	void  close();
private:
	unsigned short  NetHostBytes(unsigned short val);
public:
	bool  parse_video_rtp_packet(char* rtp_buffer_ptr,int rtp_buffer_size,char*& h264_frame_ptr,int& h264_frame_size,bool& b_key,int& mstimestamp,int payloadtype,int timescale);
	bool  parse_audio_rtp_packet(char* rtp_buffer_ptr,int rtp_buffer_size,char*& audio_frame_ptr,int& audio_frame_size,int& numsamples,int payloadtype);
	bool  parse_video_rtp_packet2(char* rtp_buffer_ptr,int rtp_buffer_size,char*& h264_frame_ptr,int& h264_frame_size,bool& b_key,int& mstimestamp,int payloadtype,int timescale);
	bool  parse_video_rtp_packet2_mpg2ps(char* rtp_buffer_ptr, int rtp_buffer_size, char*& h264_frame_ptr, int& h264_frame_size, bool& b_key, int& mstimestamp, int payloadtype, int timescale);

};



