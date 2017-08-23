/************************************************************************/
/* dhplay   �汾:  3.34			                                    */
/************************************************************************/

#ifndef _DHPLAY_H
#define _DHPLAY_H

#if (defined(WIN32) || defined(WIN64))
	#ifdef dhplay_EXPORTS
		#define PLAYSDK_API __declspec(dllexport)
	#else
		#define PLAYSDK_API __declspec(dllimport)
	#endif
	#define CALLMETHOD __stdcall
	#define CALLBACK   __stdcall
#else
	#define CALLMETHOD
	#define CALLBACK
	#define PLAYSDK_API //extern "C"
#endif

#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#else
#define BOOL		int
#define BYTE		unsigned char
#define PBYTE		BYTE*
#define LPBYTE		BYTE*
#ifndef LONG
#define LONG		long
#endif
#ifndef DWORD
#define DWORD		unsigned long
#endif
#define WORD		unsigned short
#define COLORREF	DWORD
#define HDC			void*
#define HWND		void*
#define LPSTR		char*
#define UINT		unsigned int
#define TRUE		1
#define FALSE		0

typedef struct _SYSTEMTIME
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

#endif

typedef struct _tagRECT
{
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
}DISPLAYRECT;

#ifdef	__cplusplus
extern "C" {
#endif

/************************************************************************/
/* �궨��			                                                    */
/************************************************************************/

#define  FUNC_MAX_PORT					501		//���ͨ����

#define MIN_WAVE_COEF					-100	//PLAY_AdjustWaveAudioʹ��
#define MAX_WAVE_COEF					100		//PLAY_AdjustWaveAudioʹ��

#define TIMER_1							1		//��ý�嶨ʱ��
#define TIMER_2							2		//�̶߳�ʱ��

#define BUF_VIDEO_SRC					1		//��ƵԴ����
#define BUF_AUDIO_SRC					2		//��ƵԴ����
#define BUF_VIDEO_RENDER				3		//�������Ƶ���ݻ���
#define BUF_AUDIO_RENDER				4		//�������Ƶ���ݻ���

#define MAX_DISPLAY_WND					4

#define DISPLAY_NORMAL					1		//�����ֱ�����ʾ
#define DISPLAY_QUARTER					2		//1/4�ֱ�����ʾ

#define MAX_DIS_FRAMES					50		//���Ż�������󻺳�֡��
#define MIN_DIS_FRAMES					6		//���Ż�������С����֡��

#define BY_FRAMENUM						1		//��֡�ŷ�ʽ(PLAY_GetKeyFramePosʹ��)
#define BY_FRAMETIME					2		//��ʱ�䷽ʽ(PLAY_GetKeyFramePosʹ��)

#define SOURCE_BUF_MAX					1024*100000	//��������������󳤶�
#define SOURCE_BUF_MIN					1024*50		//��������������С����

#define STREAME_REALTIME				0		//ʵʱ��ģʽ
#define STREAME_FILE					1		//�ļ���ģʽ

#define T_AUDIO16						101		//16λ��Ƶ��������
#define T_AUDIO8						100		//8λ��Ƶ��������

#define T_UYVY							1		//UYVY���͵�YUV����,���ڲ�֧��.
#define T_IYUV							3		//IYUV(I420)����YUV����
#define T_RGB32							7		//RGB32����

#define SUPPORT_DDRAW					1		//֧��DIRECTDRAW,�����֧��,�򲥷������ܹ���
#define SUPPORT_BLT						2		//�Կ�֧��BLT����,�����֧��,�򲥷������ܹ���
#define SUPPORT_BLTFOURCC				4		//�Կ�BLT֧����ɫת��,�����֧��,��������ʹ�������ʽ��RGBת��
#define SUPPORT_BLTSHRINKX				8		//�Կ�BLT֧��X����С,�����֧��,ϵͳʹ�������ʽת��
#define SUPPORT_BLTSHRINKY				16		//�Կ�BLT֧��Y����С,�����֧��,ϵͳʹ�������ʽת��
#define SUPPORT_BLTSTRETCHX				32		//�Կ�BLT֧��X��Ŵ�,�����֧��,ϵͳʹ�������ʽת��
#define SUPPORT_BLTSTRETCHY				64		//�Կ�BLT֧��Y��Ŵ�,�����֧��,ϵͳʹ�������ʽת��
#define SUPPORT_SSE						128		//CPU֧��SSEָ��,Intel Pentium3����֧��SSEָ��
#define SUPPORT_MMX						256		//CPU֧��MMXָ�

#define PLAY_CMD_GetTime				1		//������ʱ����Ϣ
#define PLAY_CMD_GetFileRate			2		//֡����Ϣ
#define PLAY_CMD_GetMediaInfo			3		//ý����Ϣ
#define PLAY_CMD_GetRenderNum			4		//��ǰҪ��Ⱦ��֡��
#define PLAY_CMD_GetRenderTime			5		//��ǰҪ��Ⱦ��ʱ��
#define PLAY_CMD_GetSrcTime				6

#define AVI_MEDIACHANGE_FRAMERATE		1		//֡�ʸı�
#define AVI_MEDIACHANGE_RESOLUTION		2		//�ֱ��ʸı�

#define WATERMARK_DATA_TEXT				0		//����
#define WATERMARK_DATA_JPEG_BMP			1		//JPEG����BMPͼƬ
#define WATERMARK_DATA_FRAMEDATA		3		//֡����

#define	DH_PLAY_NOERROR					0		//û�д���
#define DH_PLAY_PARA_OVER				1		//��������Ƿ�
#define DH_PLAY_ORDER_ERROR				2		//����˳�򲻶�
#define DH_PLAY_TIMER_ERROR				3		//��ý��ʱ������ʧ��
#define DH_PLAY_DEC_VIDEO_ERROR			4		//��Ƶ����ʧ��
#define DH_PLAY_DEC_AUDIO_ERROR			5		//��Ƶ����ʧ��
#define DH_PLAY_ALLOC_MEMORY_ERROR		6		//�����ڴ�ʧ��
#define DH_PLAY_OPEN_FILE_ERROR			7		//�ļ�����ʧ��
#define DH_PLAY_CREATE_OBJ_ERROR		8		//�����߳��¼���ʧ��
#define DH_PLAY_CREATE_DDRAW_ERROR		9		//����directDrawʧ��
#define DH_PLAY_CREATE_OFFSCREEN_ERROR	10		//������˻���ʧ��
#define DH_PLAY_BUF_OVER				11		//��������,������ʧ��
#define DH_PLAY_CREATE_SOUND_ERROR		12		//������Ƶ�豸ʧ��
#define DH_PLAY_SET_VOLUME_ERROR		13		//��������ʧ��
#define DH_PLAY_SUPPORT_FILE_ONLY		14		//ֻ���ڲ����ļ�ʱ����ʹ��
#define DH_PLAY_SUPPORT_STREAM_ONLY		15		//ֻ���ڲ�����ʱ����ʹ��
#define DH_PLAY_SYS_NOT_SUPPORT			16		//ϵͳ��֧��,������ֻ�ܹ�����Pentium 3����
#define DH_PLAY_FILEHEADER_UNKNOWN		17		//û���ļ�ͷ
#define DH_PLAY_VERSION_INCORRECT		18		//�������ͱ������汾����Ӧ
#define DH_PLAY_INIT_DECODER_ERROR		19		//��ʼ��������ʧ��
#define DH_PLAY_CHECK_FILE_ERROR		20		//�ļ�̫�̻������޷�ʶ��
#define DH_PLAY_INIT_TIMER_ERROR		21		//��ʼ����ý��ʱ��ʧ��
#define DH_PLAY_BLT_ERROR				22		//λ����ʧ��
#define DH_PLAY_UPDATE_ERROR			23		//��ʾoverlayʧ��
#define DH_PLAY_MEMORY_TOOSMALL			24		//����̫С

/************************************************************************/
/* �ṹ��	                                                            */
/************************************************************************/

typedef enum __tPicFormats
{
	PicFormat_BMP = 0,				        //BMP32����
    PicFormat_JPEG,							//JPEG����
	PicFormat_JPEG_70,						//70%������JPEG����
	PicFormat_JPEG_50,						//50%������JPEG����
	PicFormat_JPEG_30,						//30%������JPEG����
	PicFormat_JPEG_10,						//10%������JPEG����
	PicFormat_BMP24,                        //BMP24����
	PicFormat_TIFF							//TIFF����
} tPicFormats;

typedef struct
{
	LONG			nFilePos;				//ָ��֡���ļ��е�ƫ��λ��
	LONG			nFrameLen;				//֡����
	LONG			nFrameNum;				//֡���
	LONG			nFrameTime;				//֡ʱ��
	LONG			nErrorFrameNum;			//����,����ʹ��
	SYSTEMTIME*		pErrorTime;				//����,����ʹ��
	LONG			nErrorLostFrameNum;		//����,����ʹ��
	LONG			nErrorFrameSize;		//����,����ʹ��
}FRAME_POS,*PFRAME_POS;

typedef struct
{
	LONG			nWidth;					//�����,��λ����.�������Ƶ������Ϊ0.
	LONG			nHeight;				//�����,�������Ƶ������Ϊ0
	LONG			nStamp;					//ʱ����Ϣ,��λ����
	LONG			nType;					//��Ƶ֡����,T_AUDIO16,T_RGB32,T_IYUV
	LONG			nFrameRate;				//����ʱ������ͼ��֡��
}FRAME_INFO;

typedef struct
{
	#define FRAME_TYPE_VIDEO 0				//��Ƶ֡
	#define FRAME_TYPE_AUDIO 1				//��Ƶ֡
	int				nFrameType;				//��Ƶ֡����,�����涨��
	int				nFrameSeq;				//֡���
	int				nStamp;					//ʱ����Ϣ,��λ����
	int				nWidth;					//�����,��λ����.�������Ƶ������Ϊ0.
	int 			nHeight;				//�����,�������Ƶ������Ϊ0
	int				nFrameRate;				//����ʱ������ͼ��֡��
	int				nChannels;				//��Ƶͨ����
	int				nBitPerSample;			//��Ƶ����λ��
	int				nSamplesPerSec;			//��Ƶ����Ƶ��
	int				nRemainData;			//����ʣ��������
	SYSTEMTIME		nDataTime;				//ʱ��
	int				nReserved[59];			//�����ֶ�
}FRAME_INFO_EX;

typedef struct 
{
	int				nFrameType;					//֡����,�����FRAME_INFO_EX��nFrameType�ֶ�
	
	void*			pAudioData;				//��Ƶ����,�������Ƶ֡
	int				nAudioDataLen;			//��Ƶ���ݳ���

	void*			pVideoData[3];			//�ֱ��ʾ��Ƶ��YUV��������
	int				nStride[3];				//�ֱ��ʾYUV���������Ŀ��
	int				nWidth[3];				//�ֱ��ʾYUV���������Ŀ��
	int				nHeight[3];				//�ֱ��ʾYUV���������ĸ߶�
	int				nReserved[64];			//�����ֶ�
}FRAME_DECODE_INFO;

typedef struct 
{
	int			lWidth;					//�����,��λ����.
	int			lHeight;				//�����
	int			lFrameRate;				//֡��
	int			lChannel;				//��Ƶͨ����
	int			lBitPerSample;			//��Ƶ����λ��
	int			lSamplesPerSec;			//��Ƶ����Ƶ��
}MEDIA_INFO;

typedef struct 
{
	char*			pDataBuf;				//֡����
	LONG			nSize;					//֡���ݳ���
	LONG			nFrameNum;				//֡���
	BOOL			bIsAudio;				//�Ƿ���Ƶ֡
	LONG			nReserved;				//����
}FRAME_TYPE;


/************************************************************************/
/* �ӿ�		                                                            */
/************************************************************************/

//------------------------------------------------------------------------
// ����: PLAY_OpenFile
// ����: �򿪲����ļ��������ڲ����ļ�֮ǰ����. �ļ����ܳ���4G��С��4K
// ����: nPort,ͨ����
//		 sFileName,�ļ���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenFile(LONG nPort,LPSTR sFileName);

//------------------------------------------------------------------------
// ����: PLAY_CloseFile
// ����: �ر��ļ�, ��PLAY_Stop�����
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseFile(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_OpenStream
// ����: ��������
// ����: nPort,ͨ����
//		 pFileHeadBuf,Ŀǰ��ʹ��,��NULL.
//		 nSize,Ŀǰ������,��0.
//		 nBufPoolSize,���ò������д���������Ļ�������С.
//			��Χ��[SOURCE_BUF_MIN,SOURCE_BUF_MAX].һ����Ϊ900*1024�������
//			���͹�����Ծ���,�ɵ�С��ֵ,������ݴ��䲻����,�������ֵ.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenStream(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);

//------------------------------------------------------------------------
// ����: PLAY_CloseStream
// ����: �ر���
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseStream(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_Play
// ����: ��ʼ����.����Ѿ�����,�ı䵱ǰ����״̬Ϊ�����ٶȲ���.
// ����: nPort,ͨ����
//		 hWnd,���Ŵ��ھ��
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Play(LONG nPort, HWND hWnd);

//------------------------------------------------------------------------
// ����: PLAY_Stop
// ����: ֹͣ����
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Stop(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_InputData
// ����: ����������,PLAY_Play֮��ʹ��
// ����: nPort,ͨ����
//		 pBuf,��������ַ
//		 nSize,��������С
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.��ʧ��,һ���ǻ���������,�û�����ͣ
//			���룬һ��ʱ��֮������������ȷ�����ſⲻ��ʧ���ݡ�
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_InputData(LONG nPort,PBYTE pBuf,DWORD nSize);

//------------------------------------------------------------------------
// ����: PLAY_Pause
// ����: ��ͣ���߻ָ�����
// ����: nPort,ͨ����
//		 nPause,TRUE��ͣ,FLASE�ָ�
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Pause(LONG nPort,DWORD nPause);

//------------------------------------------------------------------------
// ����: PLAY_Fast
// ����: �����ٶȷ�Ϊ�ż�,�����ٶȷֱ�Ϊÿ�벥��1,3,6,12,25,50,75,100,125֡
//		 ͼ��.ÿ�ε��ò����ٶ�����һ��,������4��,Ҫ�ָ��������ŵ���
//		 PLAY_Play,�ӵ�ǰλ�ÿ�ʼ��������.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Fast(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_Slow
// ����: ÿ�ε��ò����ٶȽ�һ��,������4��,Ҫ�ָ��������ŵ���PLAY_Play.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Slow(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_OneByOne
// ����: ���岥��,Ҫ�ָ��������ŵ���PLAY_ Play.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OneByOne(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetPlayPos
// ����: �����ļ�����ָ������λ��(�ٷֱ�)
// ����: nPort,ͨ����
//		 fRelativePos,�ļ����ȵİٷֱ�
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayPos(LONG nPort,float fRelativePos);

//------------------------------------------------------------------------
// ����: PLAY_SetPlayDirection
// ����: ���ò��ŷ���
// ����: nPort,ͨ����
//		 emDirection,���ŷ���0����ǰ��1�����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayDirection(LONG nPort, DWORD emDirection);

//------------------------------------------------------------------------
// ����: PLAY_GetPlayPos
// ����: ��ȡ�ļ�����ָ������λ��(�ٷֱ�)
// ����: nPort,ͨ����
// ����: float,�ļ����ȵ����λ��,��Χ0-100%
//------------------------------------------------------------------------
PLAYSDK_API float CALLMETHOD PLAY_GetPlayPos(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetFileEndMsg
// ����: �����ļ�����ʱҪ���͵���Ϣ
// ����: nPort,�˿ں�
//       hWnd,��Ϣ���ʹ���
//       nMsg,�û��Զ�����������Ϣ�������ŵ��ļ�����ʱ�û���hWnd���ڹ�����
//			�յ������Ϣ������Ϣ�е�wParam����lParam�����Ի��nPort��ֵ.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileEndMsg(LONG nPort,HWND hWnd,UINT nMsg);

//------------------------------------------------------------------------
// ����: PLAY_SetVolume
// ����: ��������,���õ�������ָ�������������,��Ӱ������������Ӧ��.
// ����: nPort,ͨ����
//		 nVolume,������ֵ,��Χ[0,0xFFFF]
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVolume(LONG nPort,WORD nVolume);

//------------------------------------------------------------------------
// ����: PLAY_StopSound
// ����: �رն�ռ��ʽ����
// ����: 
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopSound();

//------------------------------------------------------------------------
// ����: PLAY_PlaySound
// ����: ��ռ��ʽ������,ͬһʱ��ֻ����һ·����,��������Ѿ��������򿪣���
//		 �Զ��ر�ԭ���Ѿ��򿪵�����.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_PlaySound(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetFileTime
// ����: ��ȡ�ļ���ʱ��
// ����: nPort,ͨ����
// ����: �ļ��ܵ�ʱ�䳤��ֵ,��λ��.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetFileTime(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetPlayedTime
// ����: ��ȡ��ǰ�ļ�����ʱ��
// ����: nPort,ͨ����
// ����: �ļ���ǰ���ŵ�ʱ��,��λ��
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedTime(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetPlayedFrames
// ����: ��ȡ�Ѳ��ŵ�����
// ����: nPort,ͨ����
// ����: �Ѿ��������Ƶ֡��
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedFrames(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetDecodeCallBack
// ����: ���ý���ص�,�滻�������е���ʾ����,���û��Լ�������ʾ,�ú�����
//			PLAY_Play֮ǰ����,��PLAY_Stopʱ�Զ�ʧЧ,�´ε���PLAY_Play֮ǰ
//			��Ҫ��������.���벿�ֲ������ٶ�,ֻҪ�û��ӻص������з���,������
//			�ͻ������һ��������.������ֻ���벻��ʾ�����Ρ�
// ����: nPort,ͨ����
//		 cbDec,����ص�����ָ��,����ΪNULL.�ص�����������������:
//			nPort,ͨ����
//			pFrameDecodeInfo,����������Ƶ����
//			pFrameInfo,ͼ���������Ϣ,��μ�FRAME_INFO�ṹ��
//			pUser,�û��Զ������
//		 pUser,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fCBDecode)(LONG nPort, FRAME_DECODE_INFO* pFrameDecodeInfo, FRAME_INFO_EX* pFrameInfo, void* pUser);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecodeCallBack(LONG nPort, fCBDecode cbDec, void* pUser);

//------------------------------------------------------------------------
// ����: PLAY_SetDisplayCallBack
// ����: ������Ƶץͼ�ص�����.���Ҫֹͣ�ص�,���԰ѻص�����ָ����ΪNULL,��
//			�����������κ�ʱ�����
// ����: nPort,ͨ����
//		 DisplayCBFun,ץͼ�ص�����,����ΪNULL,�������������
//			nPort,ͨ����
//			pBuf,����ͼ������
//			nSize,����ͼ�����ݴ�С
//			nWidth,�����,��λ����
//			nHeight,�����
//			nStamp,ʱ����Ϣ����λ����
//			nType,��������,T_RGB32,T_UYVY,����궨��˵��
//			nReceaved,��Ӧ�û��Զ������
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDisplayCBFun)(LONG nPort,char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nStamp,LONG nType, void* pReserved);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayCallBack(LONG nPort, fDisplayCBFun DisplayCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_ConvertToBmpFile
// ����: ͼ���ʽתΪBMP��ʽ.
// ����: pBuf,ͼ������ָ��
//		 nSize,ͼ�����ݴ�С
//		 nWidth,ͼ����
//		 nHeight,ͼ��߶�
//		 nType,��������.T_RGB32,T_UYVY��.
//		 sFileName,Ҫ������ļ���.�����BMP��Ϊ�ļ���չ��.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ConvertToBmpFile(char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nType, char *sFileName);

//------------------------------------------------------------------------
// ����: PLAY_ConvertToJpegFile
// ����: ͼ���ʽתΪJPEG��ʽ.
// ����: pYUVBuf,ͼ������ָ��
//		 nWidth,ͼ����
//		 nHeight,ͼ��߶�
//		 YUVtype,YUV��������,��T_YV12,T_UYVY
//		 quality,ͼƬѹ������,��Χ(0, 100].
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ConvertToJpegFile(char *pYUVBuf, LONG nWidth, LONG nHeight, int YUVtype, int quality, char *sFileName);

//------------------------------------------------------------------------
// ����: PLAY_GetFileTotalFrames
// ����: ��ȡ�ļ���֡��
// ����: nPort,ͨ����
// ����: DWORD,�ļ��е���֡��
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetFileTotalFrames(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetCurrentFrameRate
// ����: ��ȡ��ǰ֡��
// ����: nPort,ͨ����
// ����: DWORD,��ǰ�����б���ʱ��֡��ֵ
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetCurrentFrameRate(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetPlayedTimeEx
// ����: ��ȡ�ļ���ǰ����ʱ��
// ����: nPort,ͨ����
// ����: DWORD,�ļ���ǰ���ŵ�ʱ��,��λ����.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedTimeEx(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetPlayedTimeEx
// ����: �����ļ���ǰ����ʱ��.
// ����: nPort,ͨ����
//		 nTime,�����ļ�����λ�õ�ָ��ʱ��,��λ����.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayedTimeEx(LONG nPort,DWORD nTime);

//------------------------------------------------------------------------
// ����: PLAY_GetCurrentFrameNum
// ����: ��ȡ��ǰ���ŵ�֡���,PLAY_GetPlayedFrames���ܹ������֡��.����ļ�
//			����λ�ò����ı䣬��ô�����������ķ���ֵӦ�÷ǳ��ӽ�������������
//			ʧ����.
// ����: nPort,ͨ����
// ����: ��ǰ���ŵ�֡���.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetCurrentFrameNum(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetStreamOpenMode
// ����: ����������ģʽ,�����ڲ���֮ǰ����.
// ����: nPort,ͨ����
//		 nMode,STREAME_REALTIMEʵʱģʽ(Ĭ��);STREAME_FILE�ļ�ģʽ.ʵʱģ
//			ʽ,�ʺϲ�������ʵʱ����;�ļ�ģʽ,�ʺ��û����ļ�����������ʽ����.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetStreamOpenMode(LONG nPort,DWORD nMode);

//------------------------------------------------------------------------
// ����: PLAY_GetSdkVersion
// ����: ��ȡ���ſ�SDK�汾��,�ΰ汾�źͲ�����
// ����: 
// ����: DWORD,��16λ��ʾ��ǰ�����汾��;9~16λ��ʾ�ΰ汾��;1~8λ��ʾ�β�����;
//			��:����ֵ0x00030107��ʾ:���汾����3,�ΰ汾����1,��������7.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetSdkVersion();

//------------------------------------------------------------------------
// ����: PLAY_GetLastError
// ����: ��ȡ������
// ����: nPort,ͨ����
// ����: DWORD,��õ�ǰ����Ĵ�����.��μ�������궨��.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetLastError(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_RefreshPlay
// ����: ˢ����ʾ.���û���ͣʱ���ˢ���˴���,�򴰿��е�ͼ����Ϊˢ�¶���ʧ,
//			��ʱ��������ӿڿ������°�ͼ����ʾ����.ֻ������ͣ�͵�֡����ʱ��
//			ִ��,���������ֱ�ӷ���.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_RefreshPlay(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetPictureSize
// ����: ��ȡԭʼͼ���С,���ݴ˴�С��������ʾ���ڵ�����,���Բ����Կ�������
//			����,������Щ��֧��Ӳ�����ŵ��Կ���˵�ǳ�����.
// ����: nPort,ͨ����
//		 pWidth,�������,����ͼƬ���
//		 pHeight,�������,����ͼƬ�߶�
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPictureSize(LONG nPort,LONG *pWidth,LONG *pHeight);

//------------------------------------------------------------------------
// ����: PLAY_SetPicQuality
// ����: ����ͼ������,�����óɸ�����ʱ����Ч����,��CPU�����ʸ�.��֧�ֶ�·����ʱ��
//			������Ϊ������,�Խ���CPU������.��ĳ·�Ŵ󲥷�ʱ����·���óɸ�������
//			�Դﵽ�õĻ���Ч��.
// ����: nPort,ͨ����
//		 bHighQuality,ΪTRUE(1)ʱͼ�������,ΪFALSE(0)ʱ������(Ĭ��ֵ).
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPicQuality(LONG nPort,BOOL bHighQuality);

//------------------------------------------------------------------------
// ����: PLAY_PlaySoundShare
// ����: �Թ���ʽ��������,���ű�·��������ȥ�ر�����·������.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_PlaySoundShare(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_StopSoundShare
// ����: �ر�����(����ʽ).��ͬһ��������,����ͨ������ʹ����ͬ�ķ�ʽ���Ż�ر�����.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopSoundShare(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetStreamOpenMode
// ����: ��ȡ������ģʽ
// ����: nPort,ͨ����
// ����: LONG,STREAME_REALTIME��STREAME_FILE.
//------------------------------------------------------------------------
PLAYSDK_API LONG CALLMETHOD PLAY_GetStreamOpenMode(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetVolume
// ����: ��ȡ����,�����������ָ�������������.
// ����: nPort,ͨ����
// ����: WORD,����ֵ
//------------------------------------------------------------------------
PLAYSDK_API WORD CALLMETHOD PLAY_GetVolume(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetPictureQuality
// ����: ��ȡͼ������
// ����: nPort,ͨ����
//		 bHighQuality,�������,TRUE��ʾ������,FALSE��ʾ������.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPictureQuality(LONG nPort,BOOL *bHighQuality);

//------------------------------------------------------------------------
// ����: PLAY_GetSourceBufferRemain
// ����: ��ȡ������ģʽ��Դ������ʣ�����ݴ�С
// ����: nPort,ͨ����
// ����: DWORD,��ǰԴ����Ĵ�С��λBYTE(�ֽ�).
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetSourceBufferRemain(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_ResetSourceBuffer
// ����: ���������ģʽ��Դ��������ʣ������
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ResetSourceBuffer(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_OneByOneBack
// ����: ��֡����,�˽ӿ�ֻ֧���ļ�����,�������ļ���������֮����ܵ���.ÿ��
//			��һ�ε���һ֡
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OneByOneBack(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetCurrentFrameNum
// ����: �����ļ���ǰ֡����֡��,�˺����������ļ���������֮����ܵ���.
// ����: nPort,ͨ����
//		 nFrameNum,֡���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetCurrentFrameNum(LONG nPort,DWORD nFrameNum);

//------------------------------------------------------------------------
// ����: PLAY_GetKeyFramePos
// ����: ����ָ��λ��֮ǰ�Ĺؼ�֡λ��,ͼ��������ӹؼ�֡��ʼ������û�����
//			���ļ����Ǵӹؼ�֡��ʼ��,��ô����һ���ؼ�֮֡ǰ�����ݻᱻ����.��
//			���û�Ҫ��ȡ�ļ��е�һ������,��Ӧ�ÿ��Ǵӹؼ�֡��ʼ��ȡ.����λ��
//			���ϵ����,��ඪʧ3֡����.���ļ�����������ȫ��ǰ����,��
//			PLAY_GetNextKeyFramePos����ʹ��,��������ʵ�ּ���¼���ļ�,��������
//			��ؼ�֡����й�.
// ����: nPort,ͨ����
//		 nValue,��ǰλ��,������ʱ���֡��,������nTypeָ��.
//		 nType,ָ��nValue������.���nType��BY_FRAMENUM,��nValue��ʾ֡��;
//			���nType��BY_FRAMTIME,��nValue��ʾʱ��,��λms.
//		 pFramePos,���ҵ��Ĺؼ�֡���ļ�λ����Ϣ�ṹָ��,���PFRAME_POS.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);

//------------------------------------------------------------------------
// ����: PLAY_GetNextKeyFramePos
// ����: ����ָ��λ��֮��Ĺؼ�֡λ��
// ����: nPort,ͨ����
//		 nValue,��ǰλ��,������ʱ���֡��,������nTypeָ��.
//		 nType,ָ��nValue������.���nType��BY_FRAMENUM,��nValue��ʾ֡��;
//			���nType��BY_FRAMTIME,��nValue��ʾʱ��,��λms.
//		 pFramePos,���ҵ��Ĺؼ�֡���ļ�λ����Ϣ�ṹָ��,���PFRAME_POS.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetNextKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);

//------------------------------------------------------------------------
// ����: PLAY_SetDecCBStream
// ����: ���ý���ص�������,��PLAY_Play֮ǰ����.
// ����: nPort,ͨ����
//		 nStream,1 ��Ƶ��;2 ��Ƶ��;3 ������.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCBStream(LONG nPort,DWORD nStream);

//------------------------------------------------------------------------
// ����: PLAY_SetDisplayRegion
// ����: ���û�������ʾ����,�������ֲ��Ŵ���ʾ.
// ����: nPort,ͨ����
//		 nRegionNum,��ʾ�������,0~(MAX_DISPLAY_WND-1),���Ϊ0,�����õ�������ʾ����������.
//		 pSrcRect,�ֲ���ʾ����
//		 hDestWnd,��ʾ���ھ��
//		 bEnable,��(����)��ر���ʾ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayRegion(LONG nPort,DWORD nRegionNum, DISPLAYRECT *pSrcRect, HWND hDestWnd, BOOL bEnable);


//------------------------------------------------------------------------
// ����: PLAY_GetRefValue
// ����: ��ȡ�ļ�����,�Ա��´δ�ͬһ���ļ�ʱֱ��ʹ�������Ϣ.�������������ɺ���ܻ����Ϣ.
// ����: nPort,ͨ����
//		 pBuffer,������Ϣ
//		 pSize,����pBuffer�Ĵ�С,���������Ϣ��С.�����ڵ�һ��ָ��pSize=0,pBuffer=NULL,��
//			pSize�ķ���ֵ�����Ҫ�Ļ�������С.Ȼ������㹻�Ļ���,�ٵ���һ��.	 
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetRefValue(LONG nPort,BYTE *pBuffer, DWORD *pSize);

//------------------------------------------------------------------------
// ����: PLAY_SetRefValue
// ����: �����ļ�����,������Ϣ���䳤�ȱ���׼ȷ.����Ѿ������ļ�������Ϣ,����
//			���ٵ������������Ļص�����PLAY_SetFileRefCallBackEx,ֱ������������Ϣ.
// ����: nPort,ͨ����
//		 pBuffer,������Ϣ
//		 nSize,������Ϣ�ĳ���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetRefValue(LONG nPort,BYTE *pBuffer, DWORD nSize);

//------------------------------------------------------------------------
// ����: PLAY_RigisterDrawFun
// ����: ע��һ���ص�����,��õ�ǰ�����device context,����������DC�ϻ�ͼ(������),
//			�ͺ����ڴ��ڵĿͻ���DC�ϻ�ͼ,�����DC���Ǵ��ڿͻ�����DC,����DirectDraw��
//			��Off-Screen�����DC.ע��,�����ʹ��overlay����,����ӿ���Ч,����ֱ����
//			�����ϻ�ͼ,ֻҪ����͸��ɫ�Ͳ��ᱻ����.
// ����: nPort,ͨ����
//		 DrawFun,��ͼ�ص�����,�������������:
//			nPort,ͨ����
//			hDc,OffScreen�����豸������.
//			pUserData,�û�����,��������������û�����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDrawCBFun)(LONG nPort,HDC hDc, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_RigisterDrawFun(LONG nPort, fDrawCBFun DrawCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_ResetBuffer
// ����: ���ָ����������ʣ������
// ����: nPort,ͨ����
//		 nBufType,����:
//			BUF_VIDEO_SRC 1 ��ƵԴ����
//			BUF_AUDIO_SRC 2 ��ƵԴ����
//			BUF_VIDEO_RENDER 3 �������Ƶ���ݻ���
//			BUF_AUDIO_RENDER 4 �������Ƶ���ݻ���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ResetBuffer(LONG nPort,DWORD nBufType);

//------------------------------------------------------------------------
// ����: PLAY_GetBufferValue
// ����: ��ȡָ���������Ĵ�С
// ����: nPort,ͨ����
//		 nBufType,����:
//			BUF_VIDEO_SRC 1 ��ƵԴ����
//			BUF_AUDIO_SRC 2 ��ƵԴ����
//			BUF_VIDEO_RENDER 3 �������Ƶ���ݻ���
//			BUF_AUDIO_RENDER 4 �������Ƶ���ݻ���
// ����: DWORD,���ݲ�ͬ�������ػ�����ֵ,Դ����������byte,����󻺳�������֡��.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetBufferValue(LONG nPort,DWORD nBufType);

//------------------------------------------------------------------------
// ����: PLAY_AdjustWaveAudio
// ����: ����WAVE����,���Ըı������Ĵ�С.����PLAY_SetVolume�Ĳ�ͬ����,���ǵ���
//			��������,ֻ�Ը�·������,��PLAY_SetVolume�ǵ�����������,������ϵͳ������.
// ����: nPort,ͨ����
//		 nCoefficient,�����Ĳ���,��Χ��MIN_WAVE_COEF��MAX_WAVE_COEF,0�ǲ�����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_AdjustWaveAudio(LONG nPort,LONG nCoefficient);

//------------------------------------------------------------------------
// ����: PLAY_SetAudioCallBack
// ����: ��Ƶ������WAVE���ݻص�.
// ����: nPort,ͨ����
//		 funAudio,��Ƶ����ص�����,�������������
//			nPort,ͨ����
//			pAudioBuf,wave��ʽ��Ƶ����
//			nSize,��Ƶ���ݳ���
//			nStamp,ʱ��(ms)
//			nType,��Ƶ����T_AUDIO16, ������8000����������ÿ��������16λ��ʾ
//			pUserData,�û��Զ�������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK * fAudioCBFun)(LONG nPort, char * pAudioBuf, LONG nSize, LONG nStamp, LONG nType, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioCallBack(LONG nPort, fAudioCBFun AudioCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_SetEncTypeChangeCallBack
// ����: ����ͼ��ֱ��ʸı�֪ͨ�ص�,���ļ�ǰʹ��.
// ����: nPort,ͨ����
//		 funEncChange,�ص�����
//			nPort,ͨ����
//			pUserData,�û��Զ�������
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void(CALLBACK *fEncChangeCBFun)(LONG nPort, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetEncTypeChangeCallBack(LONG nPort, fEncChangeCBFun EncChangeCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_SetColor
// ����: ������Ƶ����
// ����: nPort,ͨ����
//		 nRegionNum,��ʾ����,�ο�PLAY_SetDisplayRegion;���ֻ��һ����ʾ����(ͨ�����)��Ϊ0.
//		 nBrightness,����,Ĭ��64;��Χ0-128.
//		 nContrast,�Աȶ�,Ĭ��64;��Χ0-128.
//		 nSaturation,���Ͷ�,Ĭ��64;��Χ0-128.
//		 nHue,ɫ��,Ĭ��64;��Χ0-128.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetColor(LONG nPort, DWORD nRegionNum, int nBrightness, int nContrast, int nSaturation, int nHue);

//------------------------------------------------------------------------
// ����: PLAY_GetColor
// ����: ��ȡ��Ƶ����
// ����: nPort,ͨ����
//		 nRegionNum,��ʾ����,�ο�PLAY_SetDisplayRegion;���ֻ��һ����ʾ����(ͨ�����)��Ϊ0.
//		 pBrightness,����,Ĭ��64;��Χ0-128.
//		 pContrast,�Աȶ�,Ĭ��64;��Χ0-128.
//		 pSaturation,���Ͷ�,Ĭ��64;��Χ0-128.
//		 pHue,ɫ��,Ĭ��64;��Χ0-128.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetColor(LONG nPort, DWORD nRegionNum, int *pBrightness, int *pContrast, int *pSaturation, int *pHue);

//------------------------------------------------------------------------
// ����: PLAY_SetEncChangeMsg
// ����: ���÷ֱ��ʸı�֪ͨ��Ϣ
// ����: nPort,ͨ����
//		 hWnd,��Ϣ���͵Ĵ���
//		 nMsg,�û��������Ϣ,������ʱ�����ʽ�����ı�ʱ�û���hWnd���ڹ������յ������Ϣ.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetEncChangeMsg(LONG nPort,HWND hWnd,UINT nMsg);

//------------------------------------------------------------------------
// ����: PLAY_CatchPic
// ����: ץͼ,��BMPͼƬ����Ϊָ�����ļ�.PLAY_SetDisplayCallBack���õ���Ƶ��
//			�ݻص�����,ֻ��������Ƶ���ݽ������ʱ�ŵ���,�����û�������Ƶ��
//			��(��ץͼ),��������н��������,�Ͳ��ϵ�������ص�����.��PLAY_
//			CatchPicһ��ֻץһ��ͼ,��������ͣ�͵�֡����ʱʵ��ץͼ.����:���
//			�û���ʵ��ץͼ(һ��ץһ��ͼ),����PLAY_CatchPic,�������õ�һ��
//			ʱ���ڵ���Ƶ����,����PLAY_SetDisplayCallBack.
// ����: nPort,ͨ����
//		 sFileName,�ļ�����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchPic(LONG nPort,char* sFileName) ;

//------------------------------------------------------------------------
// ����: PLAY_CatchPicEx
// ����: PLAY_CatchPic����չ�ӿ�,�÷������PLAY_CatchPic.��ָ��ͼƬ��ʽ
// ����: nPort,ͨ����
//		 sFileName,�ļ�����
//		 ePicfomat,ͼƬ��ʽ,��tPicFormats.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchPicEx(LONG nPort,char* sFileName,tPicFormats ePicfomat);

//------------------------------------------------------------------------
// ����: PLAY_SetFileEndCallBack
// ����: �����ļ������ص�
// ����: nPort,ͨ����
//		 pFileEnd,�ص�����ָ��,�������������:
//			nPort,ͨ����
//			pUserData,�û��Զ������
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK *fpFileEndCBFun)(DWORD nPort, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileEndCallBack(LONG nPort, fpFileEndCBFun pFileEndCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_StartDataRecord
// ����: ��ʼ������¼��,ֻ����ģʽ����,��PLAY_Play֮�����.
// ����: nPort,ͨ����
//		 sFileName,¼���ļ���,����ļ������в����ڵ��ļ���,�ʹ������ļ���.
//		 idataType,0��ʾԭʼ��Ƶ��;1��ʾת����AVI��ʽ;2��ʾת����ASF��ʽ;3�ֶα����ļ�
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartDataRecord(LONG nPort, char *sFileName, int idataType);

//------------------------------------------------------------------------
// ����: PLAY_WriteData
// ����: ����ԭʼ����
// ����: nPort,ͨ����
//		 pBuf,������
//		 nSize,��С
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_WriteData(LONG nPort, PBYTE pBuf,DWORD nSize);

//------------------------------------------------------------------------
// ����: PLAY_StopDataRecord
// ����: ֹͣ������¼��
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopDataRecord(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetPlaySpeed
// ����: �ı�ͼ�񲥷ŵ��ٶ�,
// ����: nPort,ͨ����
//		 fCoff,�����ٶ�,��Χ[1/64~64.0],С��1��ʾ���ţ�����1��ʾ����.
//			   �������ٶȽϿ�ʱ���ܻ��֡����.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlaySpeed(LONG nPort, float fCoff);

//------------------------------------------------------------------------
// ����: PLAY_QueryInfo
// ����: Ŀǰʵ���˶Ե�ǰʱ���֡����Ϣ�Ĳ�ѯ.
// ����: nPort,ͨ����
//		 cmdType,ָ��״̬��ѯָ��,����
//			PLAY_CMD_GetTime   ��ȡ������ʱ����Ϣ,��λms.
//			PLAY_CMD_GetFileRate  ��ȡ֡����Ϣ
//			PLAY_CMD_GetMediaInfo  ��ȡý����Ϣ,��Ϣ�ṹΪ MEDIA_INFO
//		 buf,�����Ϣ�Ļ���
//		 buflen,���峤��
//		 returnlen,��ȡ����Ϣ����Ч���ݳ���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_QueryInfo(LONG nPort , int cmdType, char* buf, int buflen, int* returnlen);

//------------------------------------------------------------------------
// ����: PLAY_OpenAudioRecord
// ����: ����Ƶ�ɼ�����.
// ����: pProc,��Ƶ�ɼ����ݻص�ָ��,�������������:
//			pDataBuffer,�ص�����ָ��
//			DataLength,�ص����ݳ���
//			pUserData,�û�����
//		 nBitsPerSample,��ʾÿ����������Ҫ��λ��
//		 nSamplesPerSec,������
//		 nLength,���ݻ���ĳ���
//		 nReserved,����
//		 pUserData,�û��Զ�������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK *pCallFunction)(LPBYTE pDataBuffer, DWORD DataLength, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenAudioRecord(pCallFunction pProc, LONG nBitsPerSample, LONG nSamplesPerSec, LONG nLength, LONG nReserved, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_CloseAudioRecord
// ����: �ر���Ƶ�ɼ�����
// ����: 
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseAudioRecord();

//------------------------------------------------------------------------
// ����: PLAY_SetWaterMarkCallBack
// ����: ����ˮӡ���ݻص���ע�⣺ˮӡУ��ص����ú󽫲�����н�����ʾ
// ����: nPort,ͨ����
//		 pFunc,ˮӡ��Ϣ��ȡ�ص�����,�������������:
//			buf,ˮӡ����bufferָ��
//			key,���ֲ�ͬˮӡ��Ϣ
//			len,�������󳤶�
//			reallen,�����ʵ�ʳ���
//			type,��ֵ��Χ[0,3],��������
//				0  I֡֡����ˮӡ��Ϣ
//				1  ֡ˮӡ
//				2  ˮӡУ�� 
//				3  ���ܷ���֡
//		 pUserData,�û��Զ������ 
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef int (CALLBACK* GetWaterMarkInfoCallbackFunc)(char* buf, LONG key, LONG len, LONG reallen, LONG type, void* pUserData);	
PLAYSDK_API BOOL CALLMETHOD PLAY_SetWaterMarkCallBack(LONG nPort, GetWaterMarkInfoCallbackFunc pFunc, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_CreateFile
// ����: ���ļ����Զ�����ͨ����
// ����: sFileName,�ļ���
// ����: DWORD,ʧ�ܷ���0,���򷵻�ͨ����.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_CreateFile(LPSTR sFileName);

//------------------------------------------------------------------------
// ����: PLAY_DestroyFile
// ����: �رղ����ļ����ͷ��Զ������ͨ����.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_DestroyFile(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_CreateStream
// ����: �����ӿڲ��Զ�����ͨ����
// ����: nBufPoolSize,�ò������д���������Ļ�������С,��Χ��[SOURCE_BUF_MIN,SOURCE_BUF_MAX].
// ����: DWORD,ʧ�ܷ���0,���򷵻�ͨ����.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_CreateStream(DWORD nBufPoolSize);

//------------------------------------------------------------------------
// ����: PLAY_DestroyStream
// ����: �ر�������,���ͷ��Զ������ͨ����.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_DestroyStream(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_GetFreePort
// ����: ��ȡ����ͨ����,����Ϊ501.��PLAY_ReleasePortƥ��ʹ��.
// ����: plPort,�������,���ػ�ȡ��ͨ����.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetFreePort(LONG *plPort);

//------------------------------------------------------------------------
// ����: PLAY_ReleasePort
// ����: �ͷ�ͨ����,��PLAY_RealsePortƥ��ʹ��.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ReleasePort(LONG lPort);

//------------------------------------------------------------------------
// ����: PLAY_VerticalSyncEnable
// ����: ��ֱͬ����ʾ����.�˽ӿ�����PLAY_Play֮�����,���²���ʱ����������.
//			�ڲ��Ŷ�̬ͼ����ֶϲ�ʱ,����ʹ�ô˽ӿڴ򿪴�ֱͬ������.
// ����: nPort,ͨ����
//		 bEnable,TRUE�򿪴�ֱͬ��;FALSE�رմ�ֱͬ��.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API	BOOL CALLMETHOD PLAY_VerticalSyncEnable(LONG nPort, BOOL bEnable);

//------------------------------------------------------------------------
// ����: PLAY_GetPicBMP
// ����: ץȡBMPͼ��
// ����: nPort,ͨ����
//		 pBmpBuf,���BMPͼ�����ݵĻ����ַ,���û�����,����С��bmp ͼ���С,
//			�Ƽ���С:sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+w*h*4,
//			����w��h�ֱ�Ϊͼ����.
//		 dwBufSize,��������С
//		 pBmpSize,��ȡ����ʵ��bmp ͼ���С
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicBMP(LONG nPort, PBYTE pBmpBuf, DWORD dwBufSize, DWORD* pBmpSize);

//------------------------------------------------------------------------
// ����: PLAY_GetPicBMPEx
// ����: ץȡBMPͼ��
// ����: nPort,ͨ����
//		 pBmpBuf,���BMPͼ�����ݵĻ����ַ,���û�����,����С��bmp ͼ���С,
//			�Ƽ���С:sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+w*h*4,
//			����w��h�ֱ�Ϊͼ����.
//		 dwBufSize,��������С
//		 pBmpSize,��ȡ����ʵ��bmp ͼ���С
//		 nWidth,ָ����bmp�Ŀ�
//		 nHeight,ָ����bmp�ĸ�
//		 nRgbType,ָ��RGB��ʽ 0��RGB32;1��RGB24;
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicBMPEx(LONG nPort, PBYTE pBmpBuf, DWORD dwBufSize, DWORD* pBmpSize, LONG nWidth, LONG nHeight, int nRgbType);

//------------------------------------------------------------------------
// ����: PLAY_GetPicJPEG
// ����: ץȡJPEGͼ��.
// ����: nPort,ͨ����
//		 pJpegBuf,���JPEGͼ�����ݵĻ����ַ,���û�����,����С��JPEGͼ���С,
//			�Ƽ���С:w*h*3/2,����w��h�ֱ�Ϊͼ����.
//		 dwBufSize,��������С.
//		 pJpegSize,��ȡ����ʵ��JPEGͼ���С.
//		 quality,JPEGͼ���ѹ������,ȡֵ��ΧΪ(0,100].
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicJPEG(LONG nPort, PBYTE pJpegBuf, DWORD dwBufSize, DWORD* pJpegSize, int quality);

//------------------------------------------------------------------------
// ����: PLAY_GetPicTIFF
// ����: ץȡTIFFͼ��
// ����: nPort,ͨ����
//		 pTiffBuf,���TIFFͼ�����ݵĻ����ַ,���û�����,����С��tiffͼ���С,
//			�Ƽ���С:w*h*3+1024,
//			����w��h�ֱ�Ϊͼ����.
//		 dwBufSize,��������С
//		 pTiffSize,��ȡ����ʵ��TIFFͼ���С
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicTIFF(LONG nPort, PBYTE pTiffBuf, DWORD dwBufSize, DWORD* pTiffSize);

//------------------------------------------------------------------------
// ����: PLAY_SetVisibleDecodeCallBack
// ����: ����ص�.��PLAY_SetDecodeCallBack������ͬ,��ͬ���ǽ���ص���ͬʱ����
//			��ʾ��Ƶ,���鲻Ҫ�ڻص�������������ʱ����߼�����,����������ʾ����ʱ.
// ����: nPort,ͨ����
//		 cbDec,����ص�����ָ��,����ΪNULL.�ص�����������������:
//			nPort,ͨ����
//			pFrameDecodeInfo,����������Ƶ����
//			pFrameInfo,ͼ���������Ϣ,��μ�FRAME_INFO�ṹ��
//			pUser,�û��Զ������
//		 pUser,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVisibleDecodeCallBack(LONG nPort, fCBDecode cbDec, void* pUser);

//------------------------------------------------------------------------
// ����: PLAY_RigisterDrawFunEx
// ����: ע��һ���ص�����,��õ�ǰ�����������(HDC),���DC���Ǵ��ڿͻ�����DC,
//			����DirectDraw���Off-Screen�����DC.ע��.�����ʹ��overlay����,
//			����ӿ���Ч,overlay��ʽ����ֱ���ڴ����ϻ�ͼ,ֻҪ����͸��ɫ�Ͳ��ᱻ����.
// ����: nPort,ͨ����
//		 nReginNum,��ʾ�������,��Χ[0,(MAX_DISPLAY_WND-1)].���nRegionNumΪ0,
//			�����õ�������ʾ����������.
//		 DrawFunEx,��ͼ�ص�����,�������������:
//			nPort,ͨ����
//			hDc,Off-Screen������豸������(DC)
//			pUserData,�û��Զ������
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDrawCBFunEx)(LONG nPort,LONG nReginNum,HDC hDc, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_RigisterDrawFunEx(LONG nPort, LONG nReginNum, fDrawCBFunEx DrawFunEx, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_CatchResizePic
// ����: ץͼ,��ѡ���ʽ��ָ�����.
// ����: nPort,ͨ����
//		 sFileName,�ļ�����
//		 lTargetWidth,ָ����ͼ����
//		 lTargetHeight,ָ����ͼ��߶�
//		 ePicfomat,ͼƬ��ʽ,���tPicFomats
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchResizePic(LONG nPort, char* sFileName, LONG lTargetWidth, LONG lTargetHeight, tPicFormats ePicfomat);

//------------------------------------------------------------------------
// ����: PLAY_GetRealFrameBitRate
// ����: ��ȡ��Ƶʵʱ����
// ����: nPort,ͨ����
//		 pBitRate,�������,������Ƶ����.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetRealFrameBitRate(LONG nPort, double* pBitRate);


//------------------------------------------------------------------------
// ����: PLAY_SetFileRefCallBackEx
// ����: ���ý��������ص�,�Է��������������.
// ����: nPort,ͨ����
//		 pFileRefDoneEx,�ص�����ָ��,�������������:
//			nPort,ͨ����
//			bIndexCreated,����������־,TRUE���������ɹ�;FALSEʧ��.
//			pUserData,�û��Զ������
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK *fpFileRefDoneCBFunEx)(DWORD nPort, BOOL bIndexCreated, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileRefCallBackEx(LONG nPort, fpFileRefDoneCBFunEx pFileRefDoneCBFunEx, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_StartAVIConvert
// ����: ��ʼAVIת��������AVIת��״̬�ص�.
// ����: nPort,ͨ����
//		 pAVIFunc,�ص�����,�������������:
//			nPort,ͨ����
//			lMediaChangeType,AVI_MEDIACHANGE_FRAMERATE��ʾ֡�ʸı�;AVI_MEDIACHANGE_RESOLUTION��ʾ�ֱ��ʸı�
//			lUser,�û��Զ������
//			pbIfContinue,TRUE����ת��;FALSE ֹͣת��
//			sNewFileName,�������ת��,�µ�¼���ļ���
//		 lUser,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* AVIConvertCallback)(LONG nPort, LONG lMediaChangeType, void* pUserData, BOOL *pbIfContinue, char *sNewFileName);
PLAYSDK_API BOOL CALLMETHOD PLAY_StartAVIConvert(LONG nPort, char *sFileName, AVIConvertCallback pAVIFunc, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_StopAVIConvert
// ����: ֹͣAVIת��.
// ����: nPort,ͨ����
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopAVIConvert(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetWaterMarkCallBackEx
// ����: ����ˮӡ���ݻص���ע�⣺ˮӡУ��ص����ú󽫲�����н�����ʾ
// ����: nPort,ͨ����
//		 pFunc,����ָ��,�������������:
//			nPort,ͨ����
//			buf,ˮӡ���ݻ���
//			lTimeStamp,ˮӡ��ʱ���
//			lInfoType,ˮӡ��Ϣ����,����������,WATERMARK_DATA_TEXT,
//				WATERMARK_DATA_JPEG_BMP,WATERMARK_DATA_FRAMEDATA
//		 len,�������󳤶�
//		 reallen,�����ʵ�ʳ���
//		 lCheckResult,1û�д���;2ˮӡ����;3֡���ݴ���;4֡�Ŵ���
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef int (CALLBACK* GetWaterMarkInfoCallbackFuncEx)(LONG nPort, char* buf, LONG lTimeStamp, LONG lInfoType, LONG len, LONG reallen, LONG lCheckResult, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetWaterMarkCallBackEx(LONG nPort, GetWaterMarkInfoCallbackFuncEx pFunc, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_SetAudioRecScaling
// ����: ������Ƶ�ɼ��������ű���
// ����: fRatio,���ű���.����0С��1Ϊ��Ƶ��С;1Ϊԭʼ��Ƶ;����1Ϊ��Ƶ�Ŵ�.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioRecScaling(float fRatio);

//------------------------------------------------------------------------
// ����: PLAY_GetAudioRecScaling
// ����: ��ȡ��Ƶ�ɼ��������ű���
// ����: pfRatio,���ű���.����0С��1Ϊ��Ƶ��С;1Ϊԭʼ��Ƶ;����1Ϊ��Ƶ�Ŵ�.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioRecScaling(float* pfRatio);

//------------------------------------------------------------------------
// ����: PLAY_SetAudioRenderScaling
// ����: ������Ƶ�������ű���
// ����: nPort,ͨ����
//		 fRatio,���ű���.����0С��1Ϊ��Ƶ��С;1Ϊԭʼ��Ƶ;����1Ϊ��Ƶ�Ŵ�.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioRenderScaling(LONG nPort, float fRatio);

//------------------------------------------------------------------------
// ����: PLAY_GetAudioRenderScaling
// ����: ��ȡ��Ƶ�������ű���
// ����: nPort,ͨ����
//		 pfRatio,���ű���.����0С��1Ϊ��Ƶ��С;1Ϊԭʼ��Ƶ;����1Ϊ��Ƶ�Ŵ�.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioRenderScaling(LONG nPort, float* pfRatio);

//------------------------------------------------------------------------
// ����: PLAY_SetRotateAngle
// ����: ͼ��ת
// ����: nrotateType,��ת����,��Χ[0,3]. 0����ת;1��ת90��;2��ת180��;3��ת270��.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetRotateAngle(LONG nPort , int nrotateType);

//------------------------------------------------------------------------
// ����: PLAY_SetDelayTime
// ����: �����ӳ�ʱ��
// ����: nDelay,�ӳ�ʱ�䣬�������ʱ�俪ʼ���ţ�����С�ڴ�ֵ��ʼ��΢����
//       nThreshold,��ֵʱ�䣬���﷧ֵ��ʼ��΢���
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDelayTime(LONG nPort, int nDelay, int nThreshold);

//------------------------------------------------------------------------
// ����: PLAY_SetPlayMethod
// ����: ���ò��Ų��Բ�����ֻ��ʵʱ����Ч
// ����: nStartTime,��ʼ���ŵ�ʱ��
//       nSlowTime,��ʼ���ŵ�ʱ��
//		 nFastTime,��ʼ��ŵ�ʱ��
//		 nFailedTime,������ʱ��Ͷ������ʧ��
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayMethod(LONG nPort, int nStartTime, int nSlowTime, int nFastTime, int nFailedTime);

//------------------------------------------------------------------------
// ����: PLAY_BackOne
// ����: ��PLAY_OneByOneBack�ظ�����ʹ��PLAY_OneByOneBack
// ����: 
// ����: 
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_BackOne(LONG nPort);

//------------------------------------------------------------------------
// ����: PLAY_SetDecCallBack(����ʹ��PLAY_SetDecodeCallBack)
// ����: ���ý���ص�,�滻�������е���ʾ����,���û��Լ�������ʾ,�ú�����
//			PLAY_Play֮ǰ����,��PLAY_Stopʱ�Զ�ʧЧ,�´ε���PLAY_Play֮ǰ
//			��Ҫ��������.���벿�ֲ������ٶ�,ֻҪ�û��ӻص������з���,������
//			�ͻ������һ��������.������ֻ���벻��ʾ�����Ρ�
// ����: nPort,ͨ����
//		 DecCBFun,����ص�����ָ��,����ΪNULL.�ص�����������������:
//			nPort,ͨ����
//			pBuf,����������Ƶ����
//			nSize,����������Ƶ����pBuf�ĳ���
//			pFrameInfo,ͼ���������Ϣ,��μ�FRAME_INFO�ṹ��
//			nReserved1,��������
//			nReserved2,��������	
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDecCBFun)(LONG nPort,char * pBuf,LONG nSize,FRAME_INFO * pFrameInfo, void* pUserData, LONG nReserved2);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCallBack(LONG nPort, fDecCBFun DecCBFun);

//------------------------------------------------------------------------
// ����: PLAY_SetDecCallBackEx(����ʹ��PLAY_SetDecodeCallBack)
// ����: ���ý���ص�,�滻�������е���ʾ����,���û��Լ�������ʾ,�ú�����
//			PLAY_Play֮ǰ����,��PLAY_Stopʱ�Զ�ʧЧ,�´ε���PLAY_Play֮ǰ
//			��Ҫ��������.���벿�ֲ������ٶ�,ֻҪ�û��ӻص������з���,������
//			�ͻ������һ��������.������ֻ���벻��ʾ�����Ρ�
// ����: nPort,ͨ����
//		 DecCBFun,����ص�����ָ��,����ΪNULL.�ص�����������������:
//			nPort,ͨ����
//			pBuf,����������Ƶ����
//			nSize,����������Ƶ����pBuf�ĳ���
//			pFrameInfo,ͼ���������Ϣ,��μ�FRAME_INFO�ṹ��
//			nReserved1,�û��Զ������
//			nReserved2,��������	
//		 pUserData,�û��Զ������
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCallBackEx(LONG nPort, fDecCBFun DecCBFun, void* pUserData);

//------------------------------------------------------------------------
// ����: PLAY_SetVisibleDecCallBack(����ʹ��PLAY_SetVisibleDecodeCallBack)
// ����: ����ص�.��PLAY_SetDecCallBackEx������ͬ,��ͬ���ǽ���ص���ͬʱ����
//			��ʾ��Ƶ,���鲻Ҫ�ڻص�������������ʱ����߼�����,����������ʾ����ʱ.
// ����: nPort,ͨ����
//		 DecCBFun,�ص�����ָ��,����ΪNULL,�������������:
//			nPort,ͨ����
//			pBuf,����������Ƶ����
//			nSize,���ݳ���
//			pFrameInfo,֡��Ϣ,���FRAME_INFO�ṹ��.
//			pUserData,�û��Զ������
//			pReserved1,��������.
//		 pUserData,�û��Զ������.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fVisibleDecCBFun)(LONG nPort,char * pBuf,LONG nSize,FRAME_INFO * pFrameInfo, void* pUserData, LONG nReserved1);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVisibleDecCallBack(LONG nPort, fVisibleDecCBFun DecCBFun, void* pUserData);

#ifdef __cplusplus
}
#endif

#endif
