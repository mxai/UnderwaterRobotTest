
#ifndef DHCONFIGSDK_H
#define DHCONFIGSDK_H

#include "avglobal.h"
#if (defined(WIN32) || defined(WIN64))
#include <windows.h>
#ifdef CONFIGSDK_EXPORTS

#ifndef CLIENT_API
#define CLIENT_API  __declspec(dllexport) 
#endif

#else

#ifndef CLIENT_API
#define CLIENT_API  __declspec(dllimport)
#endif

#endif

#define CALLBACK __stdcall
#define CALL_METHOD  __stdcall  //__cdecl

#ifndef LLONG
#if (defined(WIN32) || defined(WIN64))
#ifdef WIN32
#define LLONG LONG
#else //WIN64 
#define LLONG __int64
#endif
#else	//linux
#define LLONG long 
#endif
#endif

#ifndef LDWORD
#if (defined(WIN32) || defined(WIN64))
#ifdef WIN32
#define LDWORD DWORD
#else //WIN64 
#define LDWORD __int64
#endif
#else	//linux
#define LDWORD long 
#endif
#endif

#else	//linux

#ifndef INTERNAL_COMPILE
#define CFG_RELEASE_HEADER //����ͷ�ļ�
#endif

#ifndef CFG_RELEASE_HEADER 
#include "../Platform/platform.h"
#endif

#define CLIENT_API	extern "C"
#define CALL_METHOD
#define CALLBACK

#endif


#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
 ** ��������
 ***********************************************************************/

#define MAX_CHANNEL_COUNT		8
#define MAX_VIDEO_CHANNEL_NUM	256					// ���ͨ����256
#define MAX_CHANNELNAME_LEN		64					// ���ͨ�����Ƴ���
#define MAX_VIDEOSTREAM_NUM		3					// �����������
#define MAX_VIDEO_COVER_NUM		16					// ����ڵ��������
#define WEEK_DAY_NUM			7					// һ�ܵ�����
#define MAX_REC_TSECT			6					// ¼��ʱ��θ���
#define MAX_REC_TSECT_EX		10					// ¼��ʱ�����չ����
#define MAX_WATERMARK_LEN		4096				// ����ˮӡ������󳤶�
#define MAX_MOTION_ROW			32					// ��̬������������
#define MAX_MOTION_COL			32					// ��̬������������
#define MAX_IMAGESIZE_NUM		256					// ���֧�ֵķֱ��ʸ���
#define MAX_FPS_NUM				1024				// ���֧�ֵ�֡�ʸ���
#define MAX_QUALITY_NUM			32					// ���֧�ֵĻ��ʸ���
#define MAX_ADDRESS_LEN			256					// ���ĵ�ַ����
#define MAX_USERNAME_LEN		64					// ����û�������
#define MAX_PASSWORD_LEN		64					// ������볤��
#define MAX_DIRECTORY_LEN		256					// �ļ��������ַ�������
#define MAX_NAS_TIME_SECTION	2					// ����洢ʱ��θ���
#define MAX_NAME_LEN			128					// ͨ�������ַ�������
#define MAX_DECPRO_LIST_SIZE	100					// ������Э���б��������
#define MAX_SCENE_LIST_SIZE		32					// ��Ƶ�����豸֧�ֵĳ��������б��������
#define MAX_OBJECT_LIST_SIZE	16					// ��Ƶ�����豸֧�ֵļ�����������б��������
#define MAX_RULE_LIST_SIZE		128					// ��Ƶ�����豸֧�ֵĹ����б��������
#define MAX_ANALYSE_MODULE_NUM	16					// ��Ƶ�����豸�����ģ�����
#define MAX_ANALYSE_RULE_NUM	32					// ��Ƶ�����豸���������
#define MAX_POLYGON_NUM			20					// ��Ƶ�����豸���򶥵��������
#define MAX_POLYLINE_NUM		20					// ��Ƶ�����豸���߶����������
#define MAX_VEHICLE_SIZE_LIST	4					// ��Ƶ�����豸������С��������
#define MAX_VEHICLE_TYPE_LIST	4					// ��Ƶ�����豸�������͸�������
#define MAX_PLATE_TYPE_LIST		32					// ��Ƶ�����豸�������͸�������
#define MAX_LANE_NUM            8                   // ��Ƶ�����豸ÿ��ͨ����Ӧ����������
#define MAX_STAFF_NUM           20                  // ��Ƶ�����豸ÿ��ͨ����Ӧ�ı��������
#define MAX_CALIBRATEAREA_NUM   20					// ��Ƶ�����豸�궨���������
#define MAX_EXCLUDEREGION_NUM   10                  // ���ܷ��������������Ҫ�ų�������������� 
#define MAX_CALIBRATEBOX_NUM    10                  // ���ܷ���У׼���������
#define MAX_SPECIALDETECT_NUM    10                  // ���ܷ�����������������
#define MAX_HUMANFACE_LIST_SIZE	8					// ��Ƶ�����豸֧�ֵ�������������б��������
#define	MAX_SEVER_NUM           16                  // ������������
#define MAX_SERVER_NAME_LEN     16                  // ���������ַ�����С
#define MAX_POWER_NUM           8                   // ��Դ��������
#define MAX_FUN_NUM             8                   // ���ȸ�������
#define MAX_CPU_NUM             8                   // cpu��������
#define MAX_HARDDISK_NUM        32                  // Ӳ������
#define MAX_TANK_NUM            16                  // ���洢������
#define MAX_CHAN_NUM            256                 // ���ͨ��������
#define MAX_RAID_NUM            16                  // ��������������
#define MAX_DEV_NUM             16                  // ����豸����
#define MAX_STORAGEPOOL_NUM     16                  // ���洢������
#define MAX_STRORAGEPOS_NUM     16                  // ���洢λ������
#define	MAX_VIDEODEV_NUM        256                 // ǰ���豸����
#define MAX_REMOTEDEVICENAME_LEN 32					// ���Զ���豸���ֳ���
#define	MAX_REMOTE_DEV_NUM       64                 // ���Զ���豸����
#define MAX_PLATEHINT_NUM       8                   // �����ַ���ʾ��������
#define MAX_LIGHT_NUM           8                   // ��ͨ�Ƹ�������
#define MAX_LIGHTGROUP_NUM      8                   // ��ͨ�����������
#define MAX_LIGHT_TYPE          8                   // ��ͨ����������
#define MAX_LIGHT_DIRECTION     8                   // ��ͨ��ָʾ����������
#define MAX_TRIGGERMODE_NUM     32                  // ��ͨ·�ڹ��򴥷�ģʽ���� 
#define MAX_VIOLATIONCODE       16                  // ���ܽ�ͨΥ�´��볤������
#define MAX_DETECTOR            6                   // ���ܽ�ͨ��������������
#define MAX_COILCONFIG          3                   // ���ܽ�ͨ��������Ȧ��������
#define MAX_DEVICE_ADDRESS      256                 // TrafficSnapshot���ܽ�ͨ�豸��ַ
#define MAX_DEPARTMENT          256                 // Department���ܽ�ͨ�豸������λ
#define MAX_ROADWAYNO           128                 // ��·���	��32�����ֺ���ĸ����
#define MAX_VIOLATIONCODE_DESCRIPT    64            // ���ܽ�ͨΥ�´��볤������
#define MAX_DRIVINGDIRECTION          256           // ��ʻ�����ַ�������
#define MAX_ACTIVEUSER_NUM            64            // ����û���Ϣ��
#define MAX_POLYGON_NUM10			10				// ��Ƶ�����豸���򶥵��������
#define MAX_VIDEODIAGNOSIS_DETECT_TYPE 11           // ��Ƶ������͸�������
#define MAX_ACTION_LIST_SIZE	16					// ��Ƶ�����豸֧�ֵĹ���Ķ��������б��������
#define MAX_STORAGEGROUPNAME_LEN 32                 // �洢�����ƻ���������
#define MAX_CALIBRATEAREA_TYPE_NUM 4                // �궨������������
#define MAX_PROTOCOL_NAME_LEN	32					// Э�����Ƴ���
#define	MAX_COMM_NUM			16					// ��󴮿�����
#define MAX_DNS_SERVER_NUM		2					// DNS�������
#define MAX_NETWORK_INTERFACE_NUM	32				// �����������
#define	MAX_NAS_NUM				16					// ����洢�������������
#define MAX_STORAGEPOINT_NUM        32              // ¼��洢��ӳ���������
#define MAX_TRACKSCENE_NUM          10              // ���ܸ��ٳ����������
#define MAX_STATUS_NUM          16                  // ��ͨ�豸״̬������
#define MAX_SERVICE_NUM         128                 // ������֧�ֵ���������
#define MAX_DBKEY_NUM           64                  // ���ݿ�ؼ������ֵ
#define MAX_SUMMARY_LEN         1024                // ���ӵ�JPEGͼƬ��ժҪ��Ϣ��󳤶�
#define MAX_MOTION_WINDOW       10                  // ����֧�ֵ���Ƶ����ֵ
#define MAX_OSD_SUMMARY_LEN     256                 // osd����������󳤶�    
#define MAX_OSD_TITLE_LEN       128                 // osd���ӱ�����󳤶�
#define MAX_CUSTOMCASE_NUM      16                  // �Զ���˾������������
#define MAX_GLOBAL_MSTERSLAVE_NUM   64              //����ʽ���������ȫ��������
#define MAX_OBJECT_ATTRIBUTES_SIZE	16			    // ��Ƶ�����豸֧�ֵļ���������������б��������
#define MAX_MODEL_LEN			32					// �豸�ͺų���
#define MAX_BURNING_DEV_NUM		32			        // ����¼�豸����
#define MAX_NET_TYPE_NUM        8                   // ����������͸���
#define MAX_NET_TYPE_LEN        64                  // ���������ַ������� 
#define MAX_DEVICE_NAME_LEN		64			        // ��������
#define MAX_DEV_ID_LEN_EX		128		            // �豸ID��󳤶�
#define MONTH_OF_YEAR			12					// һ�����·���
#define MAX_SERVER_NUM          10                  // ������������
#define MAX_REGISTER_NUM        10                  // ����ע������������ 
#define MAX_VIDEO_IN_ZOOM       32                  // ��ͨ�����������ø���
#define	MAX_ANALYSE_SCENE_NUM	32					// ��Ƶ����ȫ�����ó����������
#define	MAX_CONFIG_NUM			32					// ÿ����̨�����������
#define	MAX_PTZ_PRESET_NAME_LEN 64                  // ��̨Ԥ�õ����Ƴ���
#define CFG_COMMON_STRING_16    16                  // ͨ���ַ�������16
#define CFG_COMMON_STRING_32    32                  // ͨ���ַ�������32
#define CFG_COMMON_STRING_64    64                  // ͨ���ַ�������64
#define CFG_COMMON_STRING_128   128                 // ͨ���ַ�������128
#define CFG_COMMON_STRING_256   256                 // ͨ���ַ�������256
#define CFG_COMMON_STRING_512   512                 // ͨ���ַ�������512
#define AV_CFG_Channel_Name_Len				64			// ͨ�����Ƴ���
#define AV_CFG_Weekday_Num					7			// һ������
#define AV_CFG_Max_TimeSection				6			// ʱ�������
#define AV_CFG_Device_ID_Len				64			// �豸ID����
#define AV_CFG_IP_Address_Len				32			// ip����
#define AV_CFG_User_Name_Len				64			// �û�������
#define AV_CFG_Password_Len					64			// ���볤��
#define AV_CFG_Protocol_Len					32			// Э��������
#define AV_CFG_Serial_Len					32			// ���кų���
#define AV_CFG_Device_Class_Len				16			// �豸���ͳ���
#define AV_CFG_Device_Type_Len				32			// �豸�����ͺų���
#define AV_CFG_Device_Name_Len				64			// ��������
#define AV_CFG_Address_Len					128			// ��������ص�
#define AV_CFG_Group_Name_Len				64			// ��������	
#define AV_CFG_Max_Path						260			// ·������
#define AV_CFG_Max_Split_Window				128			// ���ָ������
#define	AV_CFG_Monitor_Favorite_In_Channel	64			// ÿ�����ͨ���������ѵ�����ղ�����
#define AV_CFG_Monitor_Favorite_Name_Len	64			// �����ղ����Ƴ���
#define AV_CFG_Max_Monitor_Favorite_Window	64			// �����ղص���󴰿�����
#define AV_CFG_Max_Split_Group				64			// �ָ�����������
#define AV_CFG_Max_Split_Mode				32			// �ָ�ģʽ�������
#define AV_CFG_Raid_Name_Len				64			// RAID���Ƴ���
#define AV_CFG_Max_Rail_Member				32			// ����RAID����������
#define AV_CFG_Max_Encode_Main_Format		3			// ����������������
#define AV_CFG_Max_Encode_Extra_Format		3			// ����������������
#define	AV_CFG_Max_Encode_Snap_Format		3			// ץͼ����������
#define AV_CFG_Max_VideoColor				24			// ÿ��ͨ�������Ƶ������ɫ��������
#define AV_CFG_Custom_Title_Len				256			// �Զ���������Ƴ���
#define AV_CFG_Custom_TitleType_Len         32          // �Զ���������ͳ���
#define AV_CFG_Max_Video_Widget_Cover		16			// �������򸲸��������
#define AV_CFG_Max_Video_Widget_Custom_Title 8			// ��������Զ�������������
#define AV_CFG_Max_Video_Widget_Sensor_Info	2			// ����������Ӵ�������Ϣ�������Ŀ
#define AV_CFG_Max_Description_Num			4			// ��������������Ϣ��������
#define AV_CFG_Group_Name_Len				64			// �������Ƴ���
#define AV_CFG_Group_Memo_Len				128			// ����˵������
#define AV_CFG_Max_Channel_Num				1024		// ���ͨ������
#define AV_CFG_Time_Format_Len				32			// ʱ���ʽ����
#define AV_CFG_Max_White_List				1024		// ����������
#define AV_CFG_Max_Black_List				1024		// ����������
#define AV_CFG_Filter_IP_Len				96			// ����IP��󳤶�
#define AV_CFG_Max_ChannelRule				32			// ͨ���洢������󳤶�, ��ͨ������
#define AV_CFG_Max_DBKey_Num				64			// �¼��ؼ�������
#define AV_CFG_DBKey_Len					32			// �¼��ؼ��ֳ���
#define AV_CFG_Max_Summary_Len				1024		// ժҪ����
#define AV_CFG_Max_Event_Title_Num			32			// �¼������������
#define AV_CFG_Max_Tour_Link_Num			128			// ������Ѳ�������
#define AV_CFG_PIP_BASE						1000		// ���л��ָ�ģʽ����ֵ
#define DES_KEY_LEN							8			// DES��Կ���ֽڳ���
#define DES_KEY_NUM							3			// 3DES��Կ�ĸ���
#define AES_KEY_LEN							32			// AES��Կ���ֽڳ���
#define MAX_TIME_SCHEDULE_NUM				8			// ʱ���Ԫ�ظ���
#define MAX_SCENE_SUBTYPE_LEN               64          // �����������ַ�������
#define MAX_SCENE_SUBTYPE_NUM               32          // ����������������    
#define MAX_VIDEO_IN_FOCUS                  32          // ��ͨ�����۽����ø���
#define MAX_TIMESPEEDLIMIT_NUM				16			// ���ʱ����������ø���
#define MAX_VOICEALERT_NUM					64			// ���������ʾ���ø���
#define CFG_MAX_LOWER_MATRIX_NUM			16			// �����λ��������
#define CFG_MAX_LOWER_MATRIX_INPUT			64			// �����λ��������ͨ����
#define CFG_MAX_LOWER_MATRIX_OUTPUT			32			// �����λ�������ͨ����
#define CFG_MAX_INFRARED_BOARD_TEMPLATE_NUM 16			// ���������ģ������
#define	CFG_MAX_INFRARED_KEY_NUM			128			// ��������尴������
#define	CFG_MAX_INFRARED_BOARD_NUM			16			// �������������
#define MAX_PHONE_NUMBER_LEN				32			// �绰������󳤶�
#define MAX_AUDIO_OUTPUT_NUM				16			// ��Ƶ������ͨ����
#define MAX_PSTN_SERVER_NUM					8			// ��󱨾��绰��������
#define MAX_ALARM_CHANNEL_NUM				32			// ��󱨾�ͨ����
#define MAX_ALARM_DEFENCE_TYPE_NUM			8			// ��󱨾�����������
#define MAX_ALARM_SENSE_METHOD_NUM			16			// ��󱨾���Ӧ����ʽ��
#define MAX_EXALARMBOX_PROTOCOL_NUM  		8			// ���֧����չ������Э����
#define MAX_EXALARM_CHANNEL_NUM				256			// ��󱨾�ͨ����
#define MAX_EXALARMBOX_NUM					8			// ��󱨾�������
#define MAX_MAILTITLE_LEN                   256         // ����ʼ����ⳤ��

#define AV_CFG_Local_Device_ID				"Local"		// �����豸ID
#define AV_CFG_Remote_Devce_ID				"Remote"	// Զ���豸ID   

/************************************************************************
 ** �������� ��ӦCLIENT_GetNewDevConfig��CLIENT_SetNewDevConfig�ӿ�
 ***********************************************************************/

#define CFG_CMD_ENCODE			"Encode"			// ͼ��ͨ����������(��ӦCFG_ENCODE_INFO)
#define CFG_CMD_RECORD			"Record"			// ��ʱ¼������(��ӦCFG_RECORD_INFO)
#define CFG_CMD_ALARMINPUT		"Alarm"				// �ⲿ���뱨������(��ӦCFG_ALARMIN_INFO)
#define CFG_CMD_NETALARMINPUT	"NetAlarm"			// ���籨������(��ӦCFG_NETALARMIN_INFO)
#define CFG_CMD_MOTIONDETECT	"MotionDetect"		// ��̬��ⱨ������(��ӦCFG_MOTION_INFO)
#define CFG_CMD_VIDEOLOST		"LossDetect"		// ��Ƶ��ʧ��������(��ӦCFG_VIDEOLOST_INFO)
#define CFG_CMD_VIDEOBLIND		"BlindDetect"		// ��Ƶ�ڵ���������(��ӦCFG_SHELTER_INFO)
#define CFG_CMD_STORAGENOEXIST	"StorageNotExist"	// �޴洢�豸��������(��ӦCFG_STORAGENOEXIST_INFO)
#define CFG_CMD_STORAGEFAILURE	"StorageFailure"	// �洢�豸���ʳ���������(��ӦCFG_STORAGEFAILURE_INFO)
#define CFG_CMD_STORAGELOWSAPCE	"StorageLowSpace"	// �洢�豸�ռ䲻�㱨������(��ӦCFG_STORAGELOWSAPCE_INFO)
#define CFG_CMD_NETABORT		"NetAbort"			// ����Ͽ���������(��ӦCFG_NETABORT_INFO)	
#define CFG_CMD_IPCONFLICT		"IPConflict"		// IP��ͻ��������(��ӦCFG_IPCONFLICT_INFO)
#define CFG_CMD_SNAPCAPINFO		"SnapInfo"			// ץͼ������ѯ(��ӦCFG_SNAPCAPINFO_INFO)
#define CFG_CMD_NAS				"NAS"				// ����洢����������(��ӦCFG_NAS_INFO)
#define CFG_CMD_PTZ				"Ptz"				// ��̨����(��ӦCFG_PTZ_INFO)
#define	CFG_CMD_PTZ_AUTO_MOVEMENT "PtzAutoMovement" // ��̨��ʱ��������(��ӦCFG_PTZ_AUTOMOVE_INFO)
#define CFG_CMD_WATERMARK		"WaterMark"			// ��Ƶˮӡ����(��ӦCFG_WATERMARK_INFO)
#define CFG_CMD_ANALYSEGLOBAL	"VideoAnalyseGlobal"// ��Ƶ����ȫ������(��ӦCFG_ANALYSEGLOBAL_INFO)
#define CFG_CMD_ANALYSEMODULE	"VideoAnalyseModule"// ����ļ��ģ������(��ӦCFG_ANALYSEMODULES_INFO)
#define CFG_CMD_ANALYSERULE		"VideoAnalyseRule"	// ��Ƶ������������(��ӦCFG_ANALYSERULES_INFO)
#define CFG_CMD_ANALYSESOURCE	"VideoAnalyseSource"// ��Ƶ������Դ����(��ӦCFG_ANALYSESOURCE_INFO)
#define CFG_CMD_RAINBRUSH       "RainBrush"         // ��ˢ����(��ӦCFG_RAINBRUSH_INFO)
#define CFG_CMD_INTELLECTIVETRAFFIC "TrafficSnapshot" // ���ܽ�ͨץ��(CFG_TRAFFICSNAPSHOT_INFOֻΪ������Э�飻��ʹ��CFG_CMD_TRAFFICSNAPSHOT_MULTI)
#define CFG_CMD_TRAFFICGLOBAL   "TrafficGlobal"     // ���ܽ�ͨȫ������(CFG_TRAFFICGLOBAL_INFO)
#define CFG_CMD_DEV_GENERRAL    "General"           // ��ͨ���� (CFG_DEV_DISPOSITION_INFO)
#define CFG_CMD_ATMMOTION		"FetchMoneyOverTime"// ATMȡ�ʱ����(��ӦCFG_ATMMOTION_INFO)
#define CFG_CMD_DEVICESTATUS    "DeviceStatus"      // �豸״̬��Ϣ(��ӦCFG_DEVICESTATUS_INFO)
#define CFG_CMD_HARDDISKTANK    "HardDiskTank"      // ��չ����Ϣ(��ӦCFG_HARDISKTANKGROUP_INFO)
#define CFG_CMD_RAIDGROUP       "RaidGroup"         // Raid����Ϣ(��ӦCFG_RAIDGROUP_INFO)
#define CFG_CMD_STORAGEPOOLGROUP "StoragePoolGroup" // �洢������Ϣ(��ӦCFG_STORAGEPOOLGROUP_INFO)
#define CFG_CMD_STORAGEPOSITIONGROUP  "StoragePositionGroup"  // �ļ�ϵͳ����Ϣ(��ӦCFG_STORAGEPOSITIONGROUP_INFO)
#define CFG_CMD_VIDEOINDEVGROUP "VideoInDevGroup"   // ǰ���豸����Ϣ(��ӦCFG_VIDEOINDEVGROUP_INFO)
#define CFG_CMD_DEVRECORDGROUP  "DevRecordGroup"    // ͨ��¼����״̬(��ӦCFG_DEVRECORDGROUP_INFO)
#define CFG_CMD_IPSSERVER       "IpsServer"         // ����״̬(��ӦCFG_IPSERVER_STATUS)
#define CFG_CMD_SNAPSOURCE		"SnapSource"		// ץͼԴ����(��ӦCFG_SNAPSOURCE_INFO)
#define CFG_CMD_DHRADER         "DahuaRadar"        // ���״�����
#define CFG_CMD_TRANSRADER       "TransRadar"       // �����״�����
#define CFG_CMD_LANDUNRADER      "LanDunRadar"      // �����״�����
#define CFG_CMD_LANDUNCOILS      "LanDunCoils"      // ������Ȧ����
#define CFG_CMD_MATRIX_SPOT      "SpotMatrix"       // Spot��������(��ӦCFG_VIDEO_MATRIX)
#define CFG_CMD_HDVR_DSP         "DspEncodeCap"     // HDVR��ÿ������ͨ����dsp��Ϣ ����ͨ��������IPC��DVR Ҳ����IPC��DVR������(��ӦCFG_DSPENCODECAP_INFO)
#define CFG_CMD_HDVR_ATTR_CFG    "SystemAttr"       // HDVR��ÿ������ͨ���������豸����Ϣ
#define CFG_CMD_CHANNEL_HOLIDAY  "HolidaySchedule"  // ����¼��ƻ�(��Ӧ�ṹ��CFG_HOLIDAY_SCHEDULE����)
#define CFG_CMD_HEALTH_MAIL      "HealthMail"       // �����ʼ�
#define CFG_CMD_CAMERAMOVE       "IntelliMoveDetect"      // �������λ������� 
#define CFG_CMD_SPLITTOUR        "SplitTour"        // ��Ƶ�ָ���Ѳ����(��ӦCFG_VIDEO_MATRIX)
#define CFG_CMD_VIDEOENCODEROI   "VideoEncodeROI"   // ��Ƶ����ROI(Region of Intrest)����
#define CFG_CMD_VIDEO_INMETERING "VideoInMetering"  // �������(��ӦCFG_VIDEO_INMETERING_INFO)
#define CFG_CMD_TRAFFIC_FLOWSTAT "TrafficFlowStat"  // ��ͨ����ͳ������(��ӦCFG_TRAFFIC_FLOWSTAT_INFO)
#define CFG_CMD_HDMIMATRIX        "HDMIMatrix"      // HDMI��Ƶ��������
#define CFG_CMD_VIDEOINOPTIONS	 "VideoInOptions"	// ��Ƶ����ǰ��ѡ��(��ӦCFG_VIDEO_IN_OPTIONS)
#define CFG_CMD_RTSP             "RTSP"             // RTSP������( ��ӦCFG_RTSP_INFO_IN��CFG_RTSP_INFO_OUT )
#define CFG_CMD_TRAFFICSNAPSHOT  "TrafficSnapshotNew"// ���ܽ�ͨץ��(CFG_TRAFFICSNAPSHOT_INFO �ϳ�����ʹ��CFG_CMD_TRAFFICSNAPSHOT_MULTI)
#define CFG_CMD_TRAFFICSNAPSHOT_MULTI  "TrafficSnapshotNew"// ���ܽ�ͨץ��(CFG_TRAFFICSNAPSHOT_NEW_INFO)
#define CFG_CMD_MULTICAST        "Multicast"         // �鲥���������(��ӦCFG_MULTICASTS_INFO_IN��CFG_MULTICASTS_INFO_OUT)
#define CFG_CMD_VIDEODIAGNOSIS_PROFILE   "VideoDiagnosisProfile"		// ��Ƶ��ϲ�����(CFG_VIDEODIAGNOSIS_PROFILE)
#define CFG_CMD_VIDEODIAGNOSIS_TASK	      "VideoDiagnosisTask"			// ��Ƶ��������(CFG_VIDEODIAGNOSIS_TASK)
#define CFG_CMD_VIDEODIAGNOSIS_PROJECT    "VideoDiagnosisProject"		// ��Ƶ��ϼƻ���(CFG_VIDEODIAGNOSIS_PROJECT)
#define CFG_CMD_VIDEODIAGNOSIS_REALPROJECT    "VideoDiagnosisRealProject" // ��Ƶ���ʵʱ�ƻ���(CFG_VIDEODIAGNOSIS_REALPROJECT)
#define CFG_CMD_VIDEODIAGNOSIS_GLOBAL     "VideoDiagnosisGlobal"		// ��Ƶ���ȫ�ֱ�(CFG_VIDEODIAGNOSIS_GLOBAL)
#define CFG_CMD_VIDEODIAGNOSIS_TASK_ONE   "VideoDiagnosisTask.x"	    // ��Ƶ��������(CFG_VIDEODIAGNOSIS_TASK)
#define CFG_CMD_TRAFFIC_WORKSTATE         "WorkState"                   // �豸����״̬�������(��ӦCFG_TRAFFIC_WORKSTATE_INFO)
#define CFG_CMD_STORAGEDEVGROUP           "StorageDevGroup"             // ���̴洢������(��ӦCFG_STORAGEGROUP_INFO)
#define CFG_CMD_RECORDTOGROUP             "RecordToGroup"               // ¼���ŵĴ洢������(��ӦCFG_RECORDTOGROUP_INFO)
#define CFG_CMD_INTELLITRACKSCENE         "IntelliTrackScene"           // ���ܸ��ٳ�������(CFG_INTELLITRACKSCENE_INFO) 
#define CFG_CMD_IVSFRAM_RULE              "IVSFramRule"                 // ����֡��������(��ӦCFG_ANALYSERULES_INFO)
#define CFG_CMD_RECORD_STORAGEPOINT       "RecordStoragePoint"          //¼��洢��ӳ������(��ӦCFG_RECORDTOSTORAGEPOINT_INFO)
#define CFG_CMD_MD_SERVER		          "MetaDataServer"	            //Ԫ���ݷ���������(��ӦCFG_METADATA_SERVER�ṹ��)
#define CFG_CMD_CHANNELTITLE	"ChannelTitle"		// ͨ������(��ӦAV_CFG_ChannelName)
#define	CFG_CMD_RECORDMODE		"RecordMode"		// ¼��ģʽ(��ӦAV_CFG_RecordMode)
#define CFG_CMD_VIDEOOUT		"VideoOut"			// ��Ƶ�������(��ӦAV_CFG_VideoOutAttr)
#define CFG_CMD_REMOTEDEVICE    "RemoteDevice"		// Զ���豸��Ϣ(��ӦAV_CFG_RemoteDevice����, ͨ���޹�)
#define CFG_CMD_REMOTECHANNEL	"RemoteChannel"		// Զ��ͨ��(��ӦAV_CFG_RemoteChannel)
#define CFG_CMD_MONITORTOUR		"MonitorTour"		// ������ѵ����(��ӦAV_CFG_MonitorTour)
#define CFG_CMD_MONITORCOLLECTION	"MonitorCollection"	// �����ղ�����(��ӦAV_CFG_MonitorCollection)
#define CFG_CMD_DISPLAYSOURCE	"DisplaySource"		// ����ָ���ʾԴ����(��ӦAV_CFG_ChannelDisplaySource)(�ϳ���������ʹ��)
#define CFG_CMD_RAID			"Raid"				// �洢��������(��ӦAV_CFG_Raid����, ͨ���޹�)
#define CFG_CMD_RECORDSOURCE	"RecordSource"		// ¼��Դ����(��ӦAV_CFG_RecordSource)
#define CFG_CMD_VIDEOCOLOR		"VideoColor"		// ��Ƶ������ɫ����(��ӦAV_CFG_ChannelVideoColor)
#define CFG_CMD_VIDEOWIDGET		"VideoWidget"		// ��Ƶ�����������(��ӦAV_CFG_VideoWidget)
#define CFG_CMD_STORAGEGROUP	"StorageGroup"		// �洢����Ϣ(��ӦAV_CFG_StorageGroup����, ͨ���޹�)
#define CFG_CMD_LOCALS			"Locales"			// ��������(��ӦAV_CFG_Locales)
#define CFG_CMD_LANGUAGE		"Language"			// ����ѡ��(��ӦAV_CFG_Language)
#define CFG_CMD_ACCESSFILTER	"AccessFilter"		// ���ʵ�ַ����(��ӦAV_CFG_AccessFilter)
#define CFG_CMD_AUTOMAINTAIN	"AutoMaintain"		// �Զ�ά��(��ӦAV_CFG_AutoMaintain)
#define CFG_CMD_REMOTEEVENT		"RemoteEvent"		// Զ���豸�¼�����(��ӦAV_CFG_RemoteEvent����)
#define CFG_CMD_MONITORWALL		"MonitorWall"		// ����ǽ����(��ӦAV_CFG_MonitorWall����, ͨ���޹�)
#define	CFG_CMD_SPLICESCREEN	"VideoOutputComposite"		// �ں�������(��ӦAV_CFG_SpliceScreen����, ͨ���޹�)
#define CFG_CMD_TEMPERATUREALARM	"TemperatureAlarm"		// �¶ȱ�������(��ӦAV_CFG_TemperatureAlarm, ͨ���޹�)
#define	CFG_CMD_FANSPEEDALARM		"FanSpeedAlarm"			// ����ת�ٱ�������(��ӦAV_CFG_FanSpeedAlarm, ͨ���޹�)
#define CFG_CMD_RECORDBACKUP		"RecordBackupRestore"	// ¼��ش�����(��ӦAV_CFG_RecordBackup, ͨ���޹�)
#define CFG_CMD_COMM			    "Comm"				// ��������(��ӦCFG_COMMGROUP_INFO)
#define	CFG_CMD_NETWORK			    "Network"			// ��������(��ӦCFG_NETWORK_INFO)
#define CFG_CMD_NASEX			    "NAS"				// ����洢����������, �������(��ӦCFG_NAS_INFO_EX)
#define CFG_CMD_LDAP                "LDAP"              // LDAP����
#define CFG_CMD_ACTIVE_DIR          "ActiveDirectory"   // �Ŀ¼����
#define CFG_CMD_FLASH               "FlashLight"        // ���������(��Ӧ CFG_FLASH_LIGHT)
#define CFG_CMD_AUDIO_ANALYSERULE   "AudioAnalyseRule"  // ��Ƶ������������(��Ӧ CFG_ANALYSERULES_INFO)
#define CFG_CMD_JUDICATURE          "Judicature"        // ˾����¼����(��Ӧ CFG_JUDICATURE_INFO)
#define CFG_CMD_GOODS_WEIGHT		"CQDTSet"			// ���ػ�������(��ӦCFG_GOOD_WEIGHT_INFO)
#define CFG_CMD_VIDEOIN				"VideoIn"			// ����ͨ������(��ӦCFG_VIDEO_IN_INFO)
#define CFG_CMD_ENCODEPLAN          "EncodePlan"        // ��¼���̱���ƻ�(��Ӧ CFG_ENCODE_PLAN_INFO)
#define CFG_CMD_PICINPIC            "PicInPic"          // ˾����Ѷ���л�(��Ӧ CFG_PICINPIC_INFO)��Ϊ���鷽ʽ��������ǰ�������ã����ݳ�������
#define CFG_CMD_BURNFULL            "BurnFull"          // ��¼���¼�����(��Ӧ CFG_BURNFULL_INFO)
#define CFG_CMD_MASTERSLAVE_GLOBAL  "MasterSlaveTrackerGlobal"   //����ʽȫ�����ã���Ӧ��
#define CFG_CMD_ANALYSEWHOLE	"VideoAnalyseWhole"  // ��Ƶ������������(��ӦCFG_ANALYSEWHOLE_INFO)
#define CFG_CMD_VIDEO_IN_BOUNDARY	"VideoInBoundary"	// ��Ƶ����߽�����(��ӦCFG_VIDEO_IN_BOUNDARY)
#define	CFG_CMD_MONITORWALL_COLLECTION	"MonitorWallCollection"	// ����ǽԤ��(��ӦCFG_MONITORWALL_COLLECTION����)
#define CFG_CMD_ANALOGMATRIX		"AnalogMatrix"		// ģ�����(��ӦCFG_ANALOG_MATRIX_INFO)
#define CFG_CMD_ANALOG_MATRIX_PROTOCOL	"AnalogMatrixProtocol"	// ģ�����Э������(��ӦCFG_ANALOG_MATRIX_PROTOCOL����)
#define	CFG_CMD_VIDEO_OUT_TITLE		"VideoOutputTitle"		// ��Ƶ�������(��ӦCFG_VIDEO_OUT_TITLE)
#define CFG_CMD_DISK_FLUX_ALARM		"DiskFluxAlarm"		// Ӳ������������������(��ӦCFG_DISK_FLUX_INFO)
#define CFG_CMD_NET_FLUX_ALARM		"NetFluxAlarm"		// ��������������������(��ӦCFG_NET_FLUX_INFO)
#define CFG_CMD_DVRIP               "DVRIP"             // ����Э������(��ӦCFG_DVRIP_INFO)
#define CFG_CMD_PARKINGSPACE_SCREEN "ParkingSpaceScreen"// ������Խӵ�����������(��Ӧ CFG_PARKINGSPACE_SCREEN_INFO ,�����飬Ԫ�����ֵ��DH_PRODUCTION_DEFNITION.nMaxParkingSpaceScreen)
#define CFG_CMD_PARKINGSPACE_STATUS "ParkingSpaceCellStatus"// ��λ����(ר�г�λ����ͨ��λ����)(��Ӧ CFG_PARKINGSPACE_STATUS_INFO �������飬Ԫ�����ֵ��DH_PRODUCTION_DEFNITION.nMaxRoadWays)
#define CFG_CMD_CLIENT_CUSTOM_DATA  "ClientCustomData"  // ƽ̨�Զ�����Ϣ(��Ӧ CFG_CLIENT_CUSTOM_INFO)
#define CFG_CMD_BURN_RECORD_FORMAT  "BurnRecordFormat"  // ��¼��ʽ����(��Ӧ CFG_BURN_RECORD_FORMAT)
#define CFG_CMD_MULTIBURN           "MultiBurn"         // �����ͬ����¼(��Ӧ CFG_MULTIBURN_INFO)��һ�����飬ÿһ��Ԫ�ر�ʾһ������ͬ����¼��У��
#define	CFG_CMD_ENCODE_ENCRYPT		"EncodeEncrypt"		// �������������Ϣ( CFG_ENCODE_ENCRYPT_CHN_INFO )
#define CFG_CMD_VIDEO_IN_ZOOM       "VideoInZoom"       // ��̨ͨ���䱶����(��Ӧ CFG_VIDEO_IN_ZOOM)
#define CFG_CMD_SNAP				"Snap"				// ץͼ����(��Ӧ CFG_SNAP_INFO)
#define CFG_CMD_REMOTE_STORAGE_LIMIT    "RemoteStorageLimit"    // ����洢��������������(��Ӧ CFG_REMOTE_STORAGELIMIT_GROUP)
#define CFG_CMD_SPECIAL_DIR			"SpecialDirectoryDefine"	// ������;Ŀ¼����(��Ӧ CFG_SPECIAL_DIR_INFO)
#define CFG_CMD_AUTO_STARTUP_DELAY	"AutoStartupDelay"			// �ػ�����ʱ�Զ���������(��Ӧ CFG_AUTO_STARTUP_DELAY_INFO)
#define CFG_CMD_CANFILTER			"CANFilter"			// CAN͸������(��Ӧ CFG_CANFILTER_LIST)
#define CFG_CMD_VIDEOIN_FOCUS       "VideoInFocus"      // �۽�����(��Ӧ CFG_VIDEO_IN_FOCUS)
#define CFG_CMD_ENCODE_ADAPT		"EncodeAdapt"		// ��������Ӧ����(��Ӧ CFG_ENCODE_ADAPT_INFO)
#define CFG_CMD_VIDEOANALYSE_CALIBRATE  "VideoAnalyseCalibrate"  // ��Ƶ�����궨����(��ӦCFG_VIDEO_ANALYSE_CALIBRATEAREA)
#define CFG_CMD_PTZ_PRESET           "PtzPreset"        // ��̨Ԥ�õ�����(��Ӧ�ṹPTZ_PRESET_INFO)
#define CFG_CMD_TIMESPEEDLIMIT		"TimeSpeedLimit"	// ʱ�������ֵ����(��Ӧ�ṹ�� CFG_TIMESPEEDLIMIT_LIST)
#define CFG_CMD_VOICEALERT			"VoiceAlert"		// ������ʾ����(��Ӧ�ṹ�� CFG_VOICEALERT_LIST)
#define CFG_CMD_DEVICEKEEPALIVE		"DeviceKeepAlive"	// �豸��������(��Ӧ�ṹ�� CFG_DEVICEKEEPALIVELIST)

#define CFG_CMD_AUDIO_SPIRIT		"AudioSpirit"		// ��������(��Ӧ CFG_AUDIO_SPIRIT)
#define CFG_CMD_COMPOSE_CHANNEL		"ComposeChannel"	// �ϳ�ͨ������(��Ӧ CFG_COMPOSE_CHANNEL)
#define CFG_CMD_LOWER_MATRIX		"LowerMatrix"		// ��λ��������(��Ӧ CFG_LOWER_MATRIX_LIST) 
#define CFG_CMD_INFRARED_BOARD_TEMPLATE	"InfraredBoardTemplate"	// �������ģ��(��Ӧ CFG_INFRARED_BOARD_TEMPLATE_GROUP)
#define CFG_CMD_INFRARED_BOARD		"InfraredBoard"	// �������ģ��(��Ӧ CFG_INFRARED_BOARD_GROUP)
#define CFG_CMD_VIDEOIN_EXPOSURE    "VideoInExposure"   // �ع�����(��ӦCFG_VIDEOIN_EXPOSURE_INFO)

#define CFG_CMD_ACCESS_GENERAL      "AccessControlGeneral" // �Ž���������(��Ӧ CFG_ACCESS_GENERAL_INFO)
#define CFG_CMD_ACCESS_EVENT        "AccessControl"        // �Ž��¼�����(��Ӧ CFG_ACCESS_EVENT_INFO����)     
#define CFG_CMD_WIRELESS			"Wireless"			// ����������������(��ӦCFG_WIRELESS_INFO)
#define CFG_CMD_ALARMSERVER			"AlarmServer"		// ��������������(��ӦCFG_ALARMCENTER_INFO)
#define CFG_CMD_COMMGLOBAL			"CommGlobal"		// ����ȫ������(��ӦCFG_COMMALARM_INFO)
#define CFG_CMD_ANALOGALARM			"AnalogAlarm"		// ģ��������ͨ������(��ӦCFG_ANALOGALARM_INFO)
#define CFG_CMD_ALARMOUT			"AlarmOut"			// �������ͨ������(��ӦCFG_ALARMOUT_INFO)
#define CFG_CMD_NTP					"NTP"				// ʱ��ͬ��������(��ӦCFG_NTP_INFO)
#define CFG_CMD_ALARMBELL			"AlarmBell"			// ��������(��ӦCFG_ALARMBELL_INFO)
#define CFG_CMD_MOBILE				"Mobile"			// �ƶ����ҵ������(��ӦCFG_MOBILE_INFO)
#define CFG_CMD_PHONEEVENTNOTIFY	"PhoneEventNotify"	// (��ӦCFG_PHONEEVENTNOTIFY_INFO)
#define CFG_CMD_PSTN_ALARM_SERVER	"PSTNAlarmServer"	// �绰������������(CFG_PSTN_ALARM_CENTER_INFO)
#define CFG_CMD_AUDIO_OUTPUT_VOLUME	"AudioOutputVolume"	// ��Ƶ�������(CFG_AUDIO_OUTPUT_VOLUME)
#define CFG_CMD_ALARMKEYBOARD		"AlarmKeyboard"		// ������������(CFG_ALARMKEYBOARD_INFO)
#define CFG_CMD_POWERFAULT			"PowerFault"		// ��Դ��������(CFG_POWERFAULT_INFO)
#define CFG_CMD_CHASSISINTRUSION	"ChassisIntrusion"	// �������ֱ���(���𱨾�)����(CFG_CHASSISINTRUSION_INFO)
#define CFG_CMD_EXALARMBOX			"ExAlarmBox"		// ��չ���������� (CFG_EXALARMBOX_INFO)
#define CFG_CMD_EXALARMOUTPUT		"ExAlarmOut"		// ��չ�����������(CFG_EXALARMOUTPUT_INFO)
#define CFG_CMD_EXALARMINPUT		"ExAlarm"			// ��չ������������(CFG_EXALARMINPUT_INFO)
#define CFG_CMD_ACCESSTIMESCHEDULE	"AccessTimeSchedule"// �Ž�ˢ��ʱ���(CFG_ACCESS_TIMESCHEDULE_INFO)
#define CFG_CMD_URGENCY				"Emergency"			// �����¼�����(CFG_URGENCY_INFO)
#define CFG_CMD_SENSORSAMPLING		"SensorSampling"	// ����������(CFG_SENSORSAMPLING_INFO)
#define CFG_CMD_STP					"STP"				// ��������(CFG_STP_INFO)
#define CFG_CMD_ALARM_SUBSYSTEM		"AlarmSubSystem"	// ������ϵͳ����(CFG_ALARM_SUBSYSTEM_INFO)
#define CFG_CMD_BATTERY_LOW_POWER	"BatteryLowPowerAlarm"	// ��ص���������(CFG_BATTER_LOW_POWER_INFO)
#define CFG_CMD_SNAPLIKAGE          "SnapLinkage"       // ץͼͨ��������������(CFG_SNAPLINKAGE_INFO)
#define CFG_CMD_AUDIOINPUT          "AudioInput"        // ��Ƶ��������(CFG_AUDIO_INPUT)
#define CFG_CMD_EMAIL				"Email"				// �ʼ���������(CFG_EMAIL_INFO)
#define CFG_CMD_TRAFFIC_TRANSFER_OFFLINE "TrafficTransferOffline"    // ���������ļ�����(TRAFFIC_TRANSFER_OFFLINE_INFO)
#define CFG_CMD_COMMSUBSCRIBE		"CommSubscribe"		// ���Ĵ�����������(CFG_DEVCOMM_SUBSCRIBE)
#define CFG_CMD_PARKINGSPACE_LIGHT_STATE "ParkingSpaceLightState"    // ��λ״̬��Ӧ�ĳ�λָʾ��(CFG_PARKINGSPACE_LIGHT_STATE)

 /************************************************************************
 ** ����������  ��ӦCLIENT_QueryNewSystemInfo
 ***********************************************************************/

#define CFG_CAP_CMD_VIDEOANALYSE "devVideoAnalyse.getCaps"			// ��Ƶ����������(��ӦCFG_CAP_ANALYSE_INFO)
#define CFG_NETAPP_REMOTEDEVICE	 "netApp.getRemoteDeviceStatus"		// ��ȡ����豸�ĵ�����״̬(��ӦCFG_REMOTE_DEVICE_STATUS)
#define CFG_CAP_CMD_PRODUCTDEFINITION "magicBox.getProductDefinition"	// �����豸��Ϣ
#define CFG_DEVICE_CAP_CMD_VIDEOANALYSE "intelli.getVideoAnalyseDeviceChannels"   // �豸���ܷ�������(��ӦCFG_CAP_DEVICE_ANALYSE_INFO)�������豸
#define CFG_DEVICE_CAP_NEW_CMD_VIDEOANALYSE "devVideoAnalyse.factory.getCollect"  // �豸���ܷ�������(��ӦCFG_CAP_DEVICE_ANALYSE_INFO)
#define CFG_CAP_CMD_CPU_COUNT  "magicBox.getCPUCount"               // ���CPU����
#define CFG_CAP_CMD_CPU_USAGE  "magicBox.getCPUUsage"               // ��ȡCPUռ����
#define CFG_CAP_CMD_MEMORY_INFO  "magicBox.getMemoryInfo"           // ����ڴ�����
#define CFG_CAP_CMD_DEVICE_STATE "trafficSnap.getDeviceStatus"      // ��ȡ�豸״̬��Ϣ (��ӦCFG_CAP_TRAFFIC_DEVICE_STATUS)
#define CFG_CAP_CMD_VIDEOINPUT "devVideoInput.getCaps"              // ��Ƶ����������(��ӦCFG_CAP_VIDEOINPUT_INFO)
#define CFG_USERMANAGER_ACTIVEUSER    "userManager.getActiveUserInfoAll"      // �õ����л���û���Ϣ(��ӦCFG_ACTIVEUSER_INFO)
#define CFG_CAP_VIDEOSTAT_SUMMARY     "videoStatServer.getSummary"            // ��ȡ��Ƶͳ��ժҪ��Ϣ(��ӦCFG_VIDEOSATA_SUMMARY_INFO)
#define CFG_CAP_CMD_VIDEODIAGNOSIS_SERVER "videoDiagnosisServer.getCaps"			// ��ȡ��Ƶ��Ϸ�������(CFG_VIDEODIAGNOSIS_CAPS_INFO)
#define CFG_CMD_VIDEODIAGNOSIS_GETCOLLECT          "videoDiagnosisServer.factory.getCollect"             // ��ȡ��Ƶ���ͨ����Ŀ(CFG_VIDEODIAGNOSIS_GETCOLLECT_INFO)
#define CFG_CMD_VIDEODIAGNOSIS_GETSTATE            "videoDiagnosisServer.getState"                       // ��ȡ��Ƶ��Ͻ���״̬(CFG_VIDEODIAGNOSIS_STATE_INFO)
#define CFG_CAP_CMD_SERVICE_LIST                   "system.listService"        //��ȡ��������֧�ֵķ����б�(CFG_DEV_SERVICE_LIST)
#define CFG_CAP_CMD_EVENTHANDLER    "capsManager.get&EventManagerEventHandler"       // ��ȡ��������������������(CFG_CAP_EVENTHANDLER_INFO)
#define CFG_CAP_ALARM               "alarm.getAlarmCaps"                             // ��ȡ����������(CFG_CAP_ALARM_INFO)
#define CFG_CAP_CMD_AUDIO_ANALYSE   "devAudioAnalyse.getCaps"                        // ��ȡ��Ƶ����������(CFG_CAP_AUDIO_ANALYSE_INFO)
#define CFG_CMD_MASTERSLAVE_GETCOLLECT        "masterSlaveTracker.factory.getCollect"    // ��ȡ����ʽ������ͨ����Ŀ(��Ӧ�ṹ��CFG_MASTERSLAVETRACKER_INFO)
#define CFG_CAP_CMD_MASTERSLAVE               "capsManager.get&MasterSlaveTracker"       // ��ȡ����ʽ�豸������(CFG_CAP_MASTERSLAVE_INFO)
#define CFG_CAP_CMD_FOCUS_STATE		"devVideoInput.getFocusStatus"						// ��ȡ��ͷ�۽�״̬��Ϣ (��ӦCFG_CAP_FOCUS_STATUS)
#define CFG_CAP_CMD_NETAPP          "netApp.getCaps"                                    // ��ȡ����Ӧ��������(��ӦCFG_CAP_NETAPP)
#define CFG_CAP_CMD_PTZ_ENABLE  	"ptz.factory.instance"					// ��ȡ��̨֧����Ϣ(CFG_CAP_PTZ_ENABLEINFO )
#define CFG_CAP_CMD_RECORD			"recordManager.getCaps"                 // ��ȡ¼��������(CFG_CAP_RECORD_INFO)
#define CFG_CAP_CMD_BURN_MANAGER    "BurnManager.getCaps"                   // ��ȡ��¼����������( CFG_CAP_BURN_MANAGER)
#define CFG_CAP_CMD_PTZ     		"ptz.getCurrentProtocolCaps"			// ��ȡ��̨������(CFG_PTZ_PROTOCOL_CAPS_INFO)
#define CFG_CMD_ENCODE_GETCAPS      "encode.getCaps"                        // ��ȡ����������(CFG_ENCODECAP)
#define CFG_CAP_CMD_VIDEOINPUT_EX   "devVideoInput.getCapsEx"               // ��Ƶ������������չ(��ӦCFG_CAP_VIDEOINPUT_INFO_EX)
#define CFG_CAP_CMD_ANALYSE_MODE    "intelli.getCaps.AnalyseMode"           // ��ȡ�豸���ܷ���ģʽ(��Ӧ CFG_ANALYSE_MODE)
#define CFG_CAP_CMD_EVENTMANAGER    "eventManager.getCaps"			// ��ȡ�豸������������,��Э���ѷϳ�,�¿�����ʹ�ø��ֶ�(CFG_CAP_EVENTMANAGER_INFO)
#define CFG_CAP_CMD_FILEMANAGER		"FileManager.getCaps"			// ��ȡ�ļ�����(CFG_CAP_FILEMANAGER)
#define	CFG_CAP_CMD_LOG				"log.getCaps"					// ��ȡ��־��������(CFG_CAP_LOG)
#define CFG_CAP_CMD_SPEAK			"speak.getCaps"					// ��������������(CFG_CAP_SPEAK)
#define CFG_CAP_CMD_ACCESSCONTROLMANAGER	"accessControlManager.getCaps"	// �Ž�����(CFG_CAP_ACCESSCONTROL)
#define CFG_CAP_CMD_EXALARM			"alarm.getExAlarmCaps"					// ��ȡ��չ����������, (��Ӧ�ṹ�� CFG_CAP_EXALARM_INFO)
#define CFG_CAP_CMD_EXALARMBOX		"alarm.getExAlarmBoxCaps"				// ��ȡ��չ������������, (��Ӧ�ṹ�� CFG_CAP_EXALARMBOX_INFO)
#define CFG_CAP_CMD_RECORDFINDER	"RecordFinder.getCaps"					// ��ȡ��ѯ��¼������, (��Ӧ�ṹ�� CFG_CAP_RECORDFINDER_INFO)
#define CFG_CAP_CMD_ANALOGALARM		"AnalogAlarm.getCaps"			// ģ������������ͨ������(��Ӧ�ṹ�� CFG_CAP_ANALOGALARM)

// ��־����
typedef struct tagCFG_CAP_LOG
{
	DWORD		dwMaxLogItems;		// �����־����
	DWORD		dwMaxPageItems;		// ÿ����ҳ�������־����
	BOOL		bSupportStartNo;	// ��ѯ�����Ƿ�֧����ʼ���
	BOOL		bSupportTypeFilter;	// ��ѯ�����Ƿ�֧�����͹���
	BOOL		bSupportTimeFilter;	// ��ѯ�����Ƿ�֧��ʱ�����
}CFG_CAP_LOG;


#define MAX_AUDIO_PROPERTY_NUM       32          // ��Ƶ����������  
#define MAX_AUDIO_FORMAT_NUM         16          // ��Ƶ��ʽ������ 

// ��Ƶ����ѹ����ʽ
enum EM_TALK_AUDIO_TYPE
{
	EM_TALK_AUDIO_PCM,
	EM_TALK_AUDIO_ADPCM, 
	EM_TALK_AUDIO_G711A, 
	EM_TALK_AUDIO_G711Mu, 
	EM_TALK_AUDIO_G726, 
	EM_TALK_AUDIO_G729, 
	EM_TALK_AUDIO_MPEG2, 
	EM_TALK_AUDIO_AMR, 
	EM_TALK_AUDIO_AAC, 
};

// ��Ƶ����
typedef struct CFG_AUDIO_PROPERTY
{
	int            nBitRate;               // ������С����λ:kbps������192kbps
	int            nSampleBit;             // ������λ���8��16
	int            nSampleRate;            // �����ʣ���λ:Hz������44100Hz
}CFG_AUDIO_PROPERTY;

// ֧�ֵ���Ƶ��ʽ
typedef struct CFG_CAP_AUDIO_FORMAT
{
	EM_TALK_AUDIO_TYPE  emCompression;          // ��Ƶѹ����ʽ�������ö��AV_Talk_Audio_Type
	int		            nPropertyNum;           // ��Ƶ���Ը���
	CFG_AUDIO_PROPERTY  stuProperty[MAX_AUDIO_PROPERTY_NUM]; // ��Ƶ����
}CFG_CAP_AUDIO_FORMAT;

// ����������
typedef struct CFG_CAP_SPEAK
{
	int						nAudioCapNum;           // ֧�ֵ���Ƶ��ʽ����
	CFG_CAP_AUDIO_FORMAT	stuAudioCap[MAX_AUDIO_FORMAT_NUM]; // ֧�ֵ���Ƶ��ʽ 
}CFG_CAP_SPEAK;

// �Ž���������
typedef struct tagCFG_CAP_ACCESSCONTROL
{
	int		nAccessControlGroups;	// �Ž�����
}CFG_CAP_ACCESSCONTROL;

// ��������Ӧ��ʽö������
typedef enum tagEM_SENSE_METHOD
{
	EM_SENSE_DOOR=0,         //�Ŵ�
	EM_SENSE_PASSIVEINFRA,   //��������
	EM_SENSE_GAS,            //����
	EM_SENSE_SMOKING,        //�̸�
	EM_SENSE_WATER,          //ˮ��
	EM_SENSE_ACTIVEFRA,      //��������
	EM_SENSE_GLASS,			 //��������
	EM_SENSE_EMERGENCYSWITCH,//��������
	EM_SENSE_SHOCK,			 //��
	EM_SENSE_DOUBLEMETHOD,	 //˫��(����+΢��)
	EM_SENSE_THREEMETHOD,	 //������
	EM_SENSE_TEMP,			 //�¶�
	EM_SENSE_HUMIDITY,		 //ʪ��
    EM_SENSE_WIND,           //����
	EM_SENSE_CALLBUTTON,	 //���а�ť
	EM_SENSE_GASPRESSURE,	 //����ѹ��
	EM_SENSE_GASCONCENTRATION,//ȼ��Ũ��
	EM_SENSE_GASFLOW,		 //��������
	EM_SENSE_OTHER,			 //����
	EM_SENSE_NUM             //ö����������
}EM_SENSE_METHOD;

// ������������ʽ
typedef struct tagCFG_EXALARM_SENSE_METHOD
{
	int                 nSupportSenseMethodNum;								// ֧�ֵĴ�������ʽ��
	EM_SENSE_METHOD     emSupportSenseMethod[MAX_ALARM_SENSE_METHOD_NUM];   // ֧�ֵĴ�������ʽ
}CFG_EXALARM_SENSE_METHOD;

// ģ������������ͨ������
typedef struct tagCFG_CAP_ANALOGALARM 
{
	DWORD						dwLocalNum;										// ����ģ������������ͨ����
	DWORD						dwExLocalNum;									// ��չģ������������ͨ����
	int							nAnalogAlarmChannelNum;							// ģ��������ͨ����, ��Ϊ0ʱ��ʾÿ��ͨ��֧���������͵Ĵ�����
	CFG_EXALARM_SENSE_METHOD	stuAnalogAlarmChannel[MAX_EXALARM_CHANNEL_NUM];	// ����ͨ������
}CFG_CAP_ANALOGALARM;


 /************************************************************************
 ** fAnalyzerData�ص�����dwDataType���Ͷ���
 ***********************************************************************/
#define    TYPE_CB_VIDEOSTAT       0x1000000      // �ص�������Ƶ��ϢժҪ���ͣ���Ӧ�ṹ��ΪCFG_VIDEOSATA_SUMMARY_INFO 
#define    TYPE_CB_ANARULES        0x1000001      // �ص�������Ƶ����ͨ����Ӧ�������¼��������ͣ���Ӧ�ṹ��ΪCFG_ANALYSERULES_INFO
#define    TYPE_CB_VIDEOSYNOPSIS   0x1000002	  // �ص�����Ũ����Ƶ������֡����Ӧ�ṹ��DH_MSG_OBJECT
#define	   TYPE_CB_TRAFFICFLOWINFO 0x1000003	  // �ص�������ͨ������Ϣ����Ӧ�ṹ��DEV_EVENT_TRAFFIC_FLOWSTAT_INFO	
#define    TYPE_CB_TRAFFICFLOWRULE 0x1000004      // �ص�������ͨ����������Ϣ����Ӧ�ṹ�� CFG_TRAFFIC_FLOWSTAT_INFO 	
/************************************************************************
 ** ������Ϣ(ÿ���ṹ�嶼��������Ϣ�������ֲ�ͬ�豸����汾�Ͳ�ͬ�ͺ��豸)
 ***********************************************************************/
// Э��汾��Ϣ
enum 
{
	CFG_PROTOCOL_VERSION_2 = 2,						// ����Э��
	CFG_PROTOCOL_VERSION_3 = 3						// ����Э��
};

// ��Ƶ����ͨ��
struct CFG_RemoteDeviceVideoInput 
{
	BOOL			bEnable;
	char			szName[MAX_DEVICE_NAME_LEN];
	char			szControlID[MAX_DEV_ID_LEN_EX];
	char			szMainUrl[MAX_PATH];			// ������url��ַ
	char			szExtraUrl[MAX_PATH];			// ������url��ַ
	int				nServiceType;					// ��������, 0-TCP, 1-UDP, 2-MCAST, -1-AUTO
};

// Զ���豸
struct AV_CFG_RemoteDevice 
{
	AV_int32			nStructSize;
	AV_BOOL				bEnable;						// ʹ��
	char				szID[AV_CFG_Device_ID_Len];		// �豸ID
	char				szIP[AV_CFG_IP_Address_Len];	// �豸IP
	AV_int32			nPort;							// �˿�
	char				szProtocol[AV_CFG_Protocol_Len];// Э������
	char				szUser[AV_CFG_User_Name_Len];	// �û���
	char				szPassword[AV_CFG_Password_Len];// ����
	char				szSerial[AV_CFG_Serial_Len];	// �豸���к�
	char				szDevClass[AV_CFG_Device_Class_Len];// �豸����
	char				szDevType[AV_CFG_Device_Type_Len];	// �豸�ͺ�
	char				szName[AV_CFG_Device_Name_Len];	// ��������
	char				szAddress[AV_CFG_Address_Len];	// ��������ص�
	char				szGroup[AV_CFG_Group_Name_Len];	// ��������
	AV_int32			nDefinition;					// ������, 0-����, 1-����
	AV_int32			nVideoChannel;					// ��Ƶ����ͨ����
	AV_int32			nAudioChannel;					// ��Ƶ����ͨ����
	AV_int32            nRtspPort;                      // Rtsp�˿ں�
	char                szVendor[MAX_PATH];             // �豸��������
	CFG_RemoteDeviceVideoInput *pVideoInput;            // ��Ƶ����ͨ�����û�����nMaxVideoInputs��CFG_RemoteDeviceVideoInput�ռ�
	int                 nMaxVideoInputs;
	int                 nRetVideoInputs;
	int					nHttpPort;						// http�˿ں�
};

//-----------------------------ͼ��ͨ������-------------------------------

// ����
typedef enum tagCFG_IMAGE_QUALITY
{
	IMAGE_QUALITY_Q10 = 1,							// ͼ������10%
	IMAGE_QUALITY_Q30,								// ͼ������30%
	IMAGE_QUALITY_Q50,								// ͼ������50%
	IMAGE_QUALITY_Q60,								// ͼ������60%
	IMAGE_QUALITY_Q80,								// ͼ������80%
	IMAGE_QUALITY_Q100,								// ͼ������100%
} CFG_IMAGE_QUALITY;

// ��Ƶѹ����ʽ
typedef enum tagCFG_VIDEO_COMPRESSION
{
	VIDEO_FORMAT_MPEG4,								// MPEG4
	VIDEO_FORMAT_MS_MPEG4,							// MS-MPEG4
	VIDEO_FORMAT_MPEG2,								// MPEG2
	VIDEO_FORMAT_MPEG1,								// MPEG1
	VIDEO_FORMAT_H263,								// H.263
	VIDEO_FORMAT_MJPG,								// MJPG
	VIDEO_FORMAT_FCC_MPEG4,							// FCC-MPEG4
	VIDEO_FORMAT_H264,								// H.264
} CFG_VIDEO_COMPRESSION;
// ��Ƶ����ģʽ
typedef enum tatCFG_AUDIO_FORAMT
{
	AUDIO_FORMAT_G711A,                              // G711a
    AUDIO_FORMAT_PCM,                                // PCM
    AUDIO_FORMAT_G711U,                              // G711u
    AUDIO_FORMAT_AMR,                                // AMR
    AUDIO_FORMAT_AAC,                                // AAC
} CFG_AUDIO_FORMAT;

// ��������ģʽ
typedef enum tagCFG_BITRATE_CONTROL
{
	BITRATE_CBR,									// �̶�����
	BITRATE_VBR,									// �ɱ�����
} CFG_BITRATE_CONTROL;

// H264 ���뼶��
typedef enum tagCFG_H264_PROFILE_RANK
{
	PROFILE_BASELINE = 1,                       // �ṩI/P֡����֧��progressive(����ɨ��)��CAVLC
	PROFILE_MAIN,                               // �ṩI/P/B֡��֧��progressiv��interlaced���ṩCAVLC��CABAC
	PROFILE_EXTENDED,                           // �ṩI/P/B/SP/SI֡����֧��progressive(����ɨ��)��CAVLC
	PROFILE_HIGH,                               // ��FRExt��Main_Profile������������8x8 intra prediction(8x8 ֡��Ԥ��), custom 
												// quant(�Զ�������), lossless video coding(������Ƶ����), �����yuv��ʽ
}CFG_H264_PROFILE_RANK;

// �ֱ���ö��
typedef enum tagCFG_CAPTURE_SIZE
{
	IMAGE_SIZE_D1,								// 704*576(PAL)  704*480(NTSC)
	IMAGE_SIZE_HD1,								// 352*576(PAL)  352*480(NTSC)
	IMAGE_SIZE_BCIF,							// 704*288(PAL)  704*240(NTSC)
	IMAGE_SIZE_CIF,								// 352*288(PAL)  352*240(NTSC)
	IMAGE_SIZE_QCIF,							// 176*144(PAL)  176*120(NTSC)
	IMAGE_SIZE_VGA,								// 640*480
	IMAGE_SIZE_QVGA,							// 320*240
	IMAGE_SIZE_SVCD,							// 480*480
	IMAGE_SIZE_QQVGA,							// 160*128
	IMAGE_SIZE_SVGA,							// 800*592
	IMAGE_SIZE_XVGA,							// 1024*768
	IMAGE_SIZE_WXGA,							// 1280*800
	IMAGE_SIZE_SXGA,							// 1280*1024  
	IMAGE_SIZE_WSXGA,							// 1600*1024  
	IMAGE_SIZE_UXGA,							// 1600*1200
	IMAGE_SIZE_WUXGA,							// 1920*1200
	IMAGE_SIZE_LTF,								// 240*192
	IMAGE_SIZE_720,								// 1280*720
	IMAGE_SIZE_1080,							// 1920*1080
	IMAGE_SIZE_1_3M,							// 1280*960
	IMAGE_SIZE_2M,							    // 1872*1408
	IMAGE_SIZE_5M,						   	    // 3744*1408
	IMAGE_SIZE_3M,							    // 2048*1536
	IMAGE_SIZE_5_0M,                            // 2432*2050
	IMAGE_SIZE_1_2M,							// 1216*1024
	IMAGE_SIZE_1408_1024,                       // 1408*1024
	IMAGE_SIZE_8M,                              // 3296*2472
	IMAGE_SIZE_2560_1920,                       // 2560*1920(5M)
	IMAGE_SIZE_960H,                            // 960*576(PAL) 960*480(NTSC)
	IMAGE_SIZE_960_720,                         // 960*720
	IMAGE_SIZE_NHD,							    // 640*360
	IMAGE_SIZE_QNHD,							// 320*180
	IMAGE_SIZE_QQNHD,							// 160*90
	IMAGE_SIZE_NR  
} CFG_CAPTURE_SIZE;

// ��Ƶ��ʽ
typedef struct tagCFG_VIDEO_FORMAT
{
	// ����
	bool				abCompression;
	bool				abWidth;
	bool				abHeight;
	bool				abBitRateControl;
	bool				abBitRate;
	bool				abFrameRate;
	bool				abIFrameInterval;
	bool				abImageQuality;
	bool				abFrameType;
	bool				abProfile;

	// ��Ϣ
	CFG_VIDEO_COMPRESSION emCompression;			// ��Ƶѹ����ʽ
	int					nWidth;						// ��Ƶ���
	int					nHeight;					// ��Ƶ�߶�
	CFG_BITRATE_CONTROL	emBitRateControl;			// ��������ģʽ
	int					nBitRate;					// ��Ƶ����(kbps)
	float				nFrameRate;					// ��Ƶ֡��
	int					nIFrameInterval;			// I֡���(1-100)������50��ʾÿ49��B֡��P֡������һ��I֡��
	CFG_IMAGE_QUALITY	emImageQuality;				// ͼ������
	int					nFrameType;					// ���ģʽ��0��DHAV��1��"PS"
    CFG_H264_PROFILE_RANK emProfile;                // H.264���뼶��
} CFG_VIDEO_FORMAT;

// ��Ƶ��ʽ
typedef struct tagCFG_AUDIO_FORMAT 
{
	// ����
	bool				abCompression;
	bool				abDepth;
	bool				abFrequency;
	bool				abMode;
	bool				abFrameType;
	bool				abPacketPeriod;

	// ��Ϣ
	CFG_AUDIO_FORMAT	emCompression;				// ��Ƶѹ��ģʽ
	AV_int32			nDepth;						// ��Ƶ�������
	AV_int32			nFrequency;					// ��Ƶ����Ƶ��
	AV_int32			nMode;						// ��Ƶ����ģʽ
	AV_int32			nFrameType;					// ��Ƶ���ģʽ, 0-DHAV, 1-PS
	AV_int32			nPacketPeriod;				// ��Ƶ�������, ms
} CFG_AUDIO_ENCODE_FORMAT;

// ��Ƶ�������
typedef struct tagCFG_VIDEOENC_OPT
{
	// ����
	bool				abVideoEnable;
	bool				abAudioEnable;
	bool				abSnapEnable;
	bool                abAudioAdd;                 // ��Ƶ��������
	bool				abAudioFormat;

	// ��Ϣ
	BOOL				bVideoEnable;				// ��Ƶʹ��
	CFG_VIDEO_FORMAT	stuVideoFormat;				// ��Ƶ��ʽ
	BOOL				bAudioEnable;				// ��Ƶʹ��
	BOOL				bSnapEnable;				// ��ʱץͼʹ��
	BOOL                bAudioAddEnable;            // ��Ƶ����ʹ��
	CFG_AUDIO_ENCODE_FORMAT	stuAudioFormat;			// ��Ƶ��ʽ
} CFG_VIDEOENC_OPT;

// RGBA��Ϣ
typedef struct tagCFG_RGBA
{
	int					nRed;
	int					nGreen;
	int					nBlue;
	int					nAlpha;
} CFG_RGBA;

// ������Ϣ
typedef struct tagCFG_RECT
{
	int					nLeft;
	int					nTop;
    int					nRight;
    int					nBottom;				
} CFG_RECT;

// ���򶥵���Ϣ
typedef struct tagCFG_POLYGON
{
	int					nX; //0~8191
	int					nY;		
} CFG_POLYGON;

// ������Ϣ
typedef struct tagCFG_REGION
{
	int         nPointNum;
	CFG_POLYGON stuPolygon[MAX_POLYGON_NUM];
}CFG_REGION;

// ���ߵĶ˵���Ϣ
typedef struct tagCFG_POLYLINE
{
	int					nX; //0~8191
	int					nY;		
} CFG_POLYLINE;

typedef enum tagCFG_FLOWSTAT_DIRECTION
{
	CFG_DRIVING_DIR_APPROACH ,		//���У����������豸�����Խ��Խ��
	CFG_DRIVING_DIR_LEAVE ,				//���У����������豸�����Խ��ԽԶ
}CFG_FLOWSTAT_DIRECTION;

#define  CFG_FLOWSTAT_ADDR_NAME			16						//�����еص�����
//��������ͳ�Ƴ���������Ϣ 
typedef struct tagCFG_TRAFFIC_FLOWSTAT_DIR_INFO
{
	CFG_FLOWSTAT_DIRECTION		emDrivingDir;							//��ʻ����
	char						szUpGoing[CFG_FLOWSTAT_ADDR_NAME];			//���еص� 
	char						szDownGoing[CFG_FLOWSTAT_ADDR_NAME];		//���еص� 
}CFG_TRAFFIC_FLOWSTAT_DIR_INFO;

// ������Ϣ
typedef struct tagCFG_LANE
{
	int                nLaneId;                           // �������
	int                nDirection;                        // ��������(�������ķ���),0-�� 1-���� 2-�� 3-���� 4-�� 5-���� 6-�� 7-����
	CFG_POLYLINE       stuLeftLine[MAX_POLYLINE_NUM];     // �󳵵��ߣ������ߵķ����ʾ���������س���������ߵĳ�Ϊ�󳵵���
	int                nLeftLineNum;                      // �󳵵��߶�����
	CFG_POLYLINE       stuRightLine[MAX_POLYLINE_NUM];    // �ҳ����ߣ������ߵķ����ʾ���������س��������ұߵĳ�Ϊ�ҳ�����
	int                nRightLineNum;                     // �ҳ����߶�����
	int                nLeftLineType;                     // �󳵵������ԣ�1-��ʾ��ʵ�ߣ�2- �����ߣ�3- ����
	int                nRightLineType;                    // �ҳ��������ԣ�1-��ʾ��ʵ�ߣ�2- �����ߣ�3- ����
	BOOL               bDriveDirectionEnable;             // ������ʻ����ʹ��
	int                nDriveDirectionNum;                     // ������ʻ������ 
	char               szDriveDirection[MAX_LIGHT_DIRECTION][MAX_NAME_LEN];  // ������ʻ����"Straight" ֱ�У�"TurnLeft" ��ת��"TurnRight" ��ת,"U-Turn":��ͷ
	int                nStopLineNum;                      // ������Ӧֹͣ�߶�����
	CFG_POLYLINE       stuStopLine[MAX_POLYLINE_NUM];     // ������Ӧֹͣ��
	int                nTrafficLightNumber;               // ������Ӧ�ĺ��̵�����

	bool               abDetectLine;                      // ��Ӧ������
	bool               abPreLine;
	bool               abPostLine;
	BYTE               byReserved[1];

	int                nDetectLine;
	CFG_POLYLINE       stuDetectLine[MAX_POLYLINE_NUM];   // ������Ӧ�ļ����
	int                nPreLine;
	CFG_POLYLINE       stuPreLine[MAX_POLYLINE_NUM];      // ������Ӧ��ǰ����
	int                nPostLine;
	CFG_POLYLINE       stuPostLine[MAX_POLYLINE_NUM];     // ������Ӧ�ĺ�����
	CFG_TRAFFIC_FLOWSTAT_DIR_INFO stuTrafficFlowDir;	  // ����������Ϣ
}CFG_LANE;

// ��ͨ������
typedef struct tagCFG_LIGHTATTRIBUTE
{
	BOOL             bEnable;                           // ��ǰ��ͨ���Ƿ���Ч���복��ͨ���޹صĽ�ͨ��Ҫ������Ч
	int              nTypeNum; 
	char		     szLightType[MAX_LIGHT_TYPE][MAX_NAME_LEN];      // ��ǰ��ͨ���������ݣ�����:��-Red,��-Yellow,��-Green,����ʱ-Countdown������ĳ��ͨ�ƿ�����ʾ�����������ɫ��ĳ��ͨ��ֻ��ʾ����ʱ
	int              nDirectionNum;
	char             szDirection[MAX_LIGHT_DIRECTION][MAX_NAME_LEN];      // ��ͨ��ָʾ���г�����,"Straight": ֱ�У�"TurnLeft":��ת��"TurnRight":��ת��"U-Turn": ��ͷ
	int              nYellowTime;                       // �Ƶ���ʱ��
}CFG_LIGHTATTRIBUTE;

// ��ͨ����������Ϣ 
typedef struct tagCFG_LIGHTGROUPS
{
	int                nLightGroupId;                     // ������
	CFG_RECT           stuLightLocation;                  // ��������
	int                nDirection;                        // ����ķ���,1- ����ˮƽ��,2- ���鴹ֱ��
	BOOL               bExternalDetection;                // �Ƿ�Ϊ��Ӻ��̵��ź�,����Ӻ��̵�ʱ��������ź�Ϊ�ж����ݡ�����ź�ÿ������ʱ֪ͨ
	BOOL               bSwingDetection;                   // �Ƿ�֧������Ӧ����ҡ�ڼ��,�ڷ紵���������𶯵ĳ����£�λ�û����һ���ĸ���ƫ�������㷨���м�⣬�����Ӽ��ʱ��
	int                nLightNum;                         // �����н�ͨ�Ƶ�����
	CFG_LIGHTATTRIBUTE stuLightAtrributes[MAX_LIGHT_NUM]; // �����и���ͨ�Ƶ�����

}CFG_LIGHTGROUPS;

enum EM_STAFF_TYPE
{
	EM_STAFF_TYPE_ERR,
		EM_STAFF_TYPE_HORIZONTAL,     // "Horizontal" ˮƽ�߶�
		EM_STAFF_TYPE_VERTICAL,       // "Vertical" ��ֱ�߶�
		EM_STAFF_TYPE_ANY,            // "Any" �����߶�
		EM_STAFF_TYPE_CROSS,          // "Cross" ��ֱ�潻�߶�
};

enum EM_CALIBRATEAREA_TYPE
{
	EM_CALIBRATEAREA_TYPE_ERR,
		EM_CALIBRATEAREA_TYPE_GROUD,                         // "Groud" : ���棬��ҪN����ֱ�߶�+M��ˮƽ�߶Σ���N=3��M=1������N=2��M=2���������չ����
		EM_CALIBRATEAREA_TYPE_HORIZONTAL,                    // "Horizontal"  : ˮƽ�棬��Ҫˮƽ����һ�㵽������ͶӰ��ֱ�߶Ρ�		
		EM_CALIBRATEAREA_TYPE_VERTICAL,                      // "Vertical" : ��ֱ�棬��Ҫ��ֱ�������Ľ��ߡ�
		EM_CALIBRATEAREA_TYPE_ANY,                           // "Any" ����ƽ�棬N����ֱ�߶Σ���ÿ�����ȣ�N=3���������չ����
};

// �����������������
enum EM_SEPCIALREGION_PROPERTY_TYPE
{
	EM_SEPCIALREGION_PROPERTY_TYPE_HIGHLIGHT = 1,            // ���������̼��������д�����
	EM_SEPCIALREGION_PROPERTY_TYPE_REGULARBLINK,             // ���ɵ���˸���忨������д�����
	EM_SEPCIALREGION_PROPERTY_TYPE_IREGULARBLINK,            // �����ɵ���˸����Ļ������д�����
	EM_SEPCIALREGION_PROPERTY_TYPE_NUM,
};


// �����������
enum EM_FACEDETECTION_TYPE
{
	EM_FACEDETECTION_TYPE_ERR,
	EM_FACEDETECTION_TYPE_SMALLFACE,						//С�����ͣ���������Ƶ�еı��ش��17%
	EM_FACEDETECTION_TYPE_LARGEFACE,						//�������ͣ���������Ƶ�еı��ش��33%
	EM_FACEDETECTION_TYPE_BOTH,								//�������
}; 

typedef struct tagCFG_STAFF
{
	CFG_POLYLINE       stuStartLocation;      // ��ʼ�����
	CFG_POLYLINE       stuEndLocation;        // ��ֹ�����
	float                nLenth;              // ʵ�ʳ���,��λ��
	EM_STAFF_TYPE	   emType;                // �������
}CFG_STAFF;

// Size
typedef struct tagCFG_SIZE
{
	union
	{
		float				nWidth;			// ��
		float				nArea;			// ���
	};
	float					nHeight;		// ��
	
} CFG_SIZE;

// �ڵ���Ϣ
typedef struct tagCFG_COVER_INFO
{
	// ����
	bool				abBlockType;
	bool				abEncodeBlend;
	bool				abPreviewBlend;

	// ��Ϣ
	CFG_RECT			stuRect;					// ���ǵ���������
	CFG_RGBA			stuColor;					// ���ǵ���ɫ
	int					nBlockType;					// ���Ƿ�ʽ��0���ڿ飬1��������
	int					nEncodeBlend;				// ���뼶�ڵ���1����Ч��0������Ч
	int					nPreviewBlend;				// Ԥ���ڵ���1����Ч��0������Ч
} CFG_COVER_INFO;

// �������ڵ�����
typedef struct tagCFG_VIDEO_COVER
{
	int                 nTotalBlocks;						// ֧�ֵ��ڵ�����
	int					nCurBlocks;							// �����õĿ���
	CFG_COVER_INFO		stuCoverBlock[MAX_VIDEO_COVER_NUM];	// ���ǵ�����	
} CFG_VIDEO_COVER;

// OSD��Ϣ
typedef struct tagCFG_OSD_INFO
{
	// ����
	bool				abShowEnable;

	// ��Ϣ
	CFG_RGBA			stuFrontColor;				// ǰ����ɫ
	CFG_RGBA			stuBackColor;				// ������ɫ
	CFG_RECT			stuRect;					// ��������
	BOOL				bShowEnable;				// ��ʾʹ��
} CFG_OSD_INFO;

// ������ɫ����
typedef struct tagCFG_COLOR_INFO
{
	int					nBrightness;				// ����(0-100)
	int					nContrast;					// �Աȶ�(0-100)
	int					nSaturation;				// ���Ͷ�(0-100)
	int					nHue;						// ɫ��(0-100)
	int					nGain;						// ����(0-100)
	BOOL				bGainEn;					// ����ʹ��
} CFG_COLOR_INFO;

// ͼ��ͨ��������Ϣ
typedef struct tagCFG_ENCODE_INFO
{
	int                 nChannelID;							// ͨ����(0��ʼ)
	char				szChnName[MAX_CHANNELNAME_LEN];		// ͨ������
	CFG_VIDEOENC_OPT	stuMainStream[MAX_VIDEOSTREAM_NUM];	// ��������0����ͨ¼��1-����¼��2������¼��
	CFG_VIDEOENC_OPT	stuExtraStream[MAX_VIDEOSTREAM_NUM];// ��������0��������1��1��������2��2��������3
	CFG_VIDEOENC_OPT	stuSnapFormat[MAX_VIDEOSTREAM_NUM];	// ץͼ��0����ͨץͼ��1������ץͼ��2������ץͼ
	DWORD				dwCoverAbilityMask;					// �����ڸ��������룬��λ�ֱ��Ǳ���Ԥ����¼���������
	DWORD				dwCoverEnableMask;					// �����ڸ�ʹ�����룬��λ�ֱ��Ǳ���Ԥ����¼���������
	CFG_VIDEO_COVER		stuVideoCover;						// ���򸲸�
	CFG_OSD_INFO		stuChnTitle;						// ͨ������
	CFG_OSD_INFO		stuTimeTitle;						// ʱ�����
	CFG_COLOR_INFO		stuVideoColor;						// ������ɫ
	CFG_AUDIO_FORMAT    emAudioFormat;                      // ��Ƶ��ʽ: 0:G711A,1:PCM,2:G711U,3:AMR,4:AAC
	int					nProtocolVer;						// Э��汾��, ֻ��
} CFG_ENCODE_INFO;

// ��Ƶ����ǰ��������
typedef struct tagCFG_VIDEO_ENCODECAP
{
	int		nMaxCIFFrame;			// CIF P֡���ֵ ��λKbits, Ĭ��ֵ40
	int		nMinCIFFrame;			// CIF P֡��Сֵ ��λKbits, Ĭ��ֵ7
}CFG_VIDEO_ENCODECAP;

// ����������
typedef struct tagCFG_ENCODECAP
{
	int                    nChannelNum;                                 // ʵ��ͨ����
	CFG_VIDEO_ENCODECAP    stuVideoEncodeCap[MAX_VIDEO_CHANNEL_NUM];	// ��ͨ������������Ϣ����
}CFG_ENCODECAP;

// ˮӡ����
typedef struct tagCFG_WATERMARK_INFO 
{
	int                 nChannelID;					// ͨ����(0��ʼ)
	BOOL				bEnable;					// ʹ�ܿ���
	int					nStreamType;				// ��������(1��n)��0����������
	int					nDataType;					// �������ͣ�1�����֣�2��ͼƬ
	char				pData[MAX_WATERMARK_LEN];	// �ַ���ˮӡ����
} CFG_WATERMARK_INFO;

// dsp����
typedef struct tagCFG_DSPENCODECAP_INFO{
	DWORD				dwVideoStandardMask;	// ��Ƶ��ʽ���룬��λ��ʾ�豸�ܹ�֧�ֵ���Ƶ��ʽ
	DWORD				dwImageSizeMask;		// �ֱ������룬��λ��ʾ�豸�ܹ�֧�ֵķֱ���
	DWORD				dwEncodeModeMask;		// ����ģʽ���룬��λ��ʾ�豸�ܹ�֧�ֵı���ģʽ
	DWORD				dwStreamCap;			// ��λ��ʾ�豸֧�ֵĶ�ý�幦�ܣ�
                                             	// ��һλ��ʾ֧��������
	                                         	// �ڶ�λ��ʾ֧�ָ�����1
	                                         	// ����λ��ʾ֧�ָ�����2
	                                         	// ����λ��ʾ֧��jpgץͼ
	DWORD				dwImageSizeMask_Assi[32];// ��ʾ������Ϊ���ֱ���ʱ��֧�ֵĸ������ֱ������롣
	DWORD				dwMaxEncodePower;		// DSP֧�ֵ���߱������� 
	WORD				wMaxSupportChannel;		// ÿ��DSP֧�����������Ƶͨ���� 
	WORD				wChannelMaxSetSync;		// DSPÿͨ���������������Ƿ�ͬ����0����ͬ����1��ͬ��
	BYTE				bMaxFrameOfImageSize[256];// ��ͬ�ֱ����µ����ɼ�֡�ʣ���dwVideoStandardMask��λ��Ӧ
	BYTE				bEncodeCap;				// ��־������ʱҪ����������������������ò�����Ч��
	                                         	// 0���������ı�������+�������ı������� <= �豸�ı���������
	                                         	// 1���������ı�������+�������ı������� <= �豸�ı���������
	                                         	// �������ı������� <= �������ı���������
	                                         	// �������ķֱ��� <= �������ķֱ��ʣ�
	                                         	// �������͸�������֡�� <= ǰ����Ƶ�ɼ�֡��
	                                         	// 2��N5�ļ��㷽��
	                                         	// �������ķֱ��� <= �������ķֱ���
												// ��ѯ֧�ֵķֱ��ʺ���Ӧ���֡��
	BYTE				byResolutionNum;			// bResolution�ĳ���
	BYTE				byResolutionNum_1;		// bResolution_1�ĳ���
	BYTE				byReserved;
	BYTE				byResolution[256];		//������,���շֱ��ʽ������������֧�ָ÷ֱ��ʣ���bResolution[n]����֧�ֵ����֡��.����Ϊ0.							
	BYTE				byResolution_1[256];		//��������1,ͬ������˵��.
	char				reserved[28];
	BYTE				byImageSize[256];		// ֧�ֵķֱ�������,�μ�enum CAPTURE_SIZE
	BYTE				byImageSize_Assi[256][256]; //��ʾ������Ϊ���ֱ���ʱ��֧�ֵĸ������ֱ��ʣ������±��ʾ��������֧�ֵķֱ���ֵ��
}CFG_DSPENCODECAP_INFO;


//-------------------------------¼������---------------------------------

// ʱ�����Ϣ
typedef struct tagCFG_TIME_SECTION 
{
	DWORD				dwRecordMask;						// ¼�����룬��λ�ֱ�Ϊ��̬���¼�񡢱���¼�񡢶�ʱ¼��Bit3~Bit15������Bit16��̬���ץͼ��Bit17����ץͼ��Bit18��ʱץͼ
	int					nBeginHour;
	int					nBeginMin;
	int					nBeginSec;
	int					nEndHour;
	int					nEndMin;
	int					nEndSec;
} CFG_TIME_SECTION;

// ʱ�����Ϣ
typedef struct tagCFG_TIME_SCHEDULE
{
	CFG_TIME_SECTION	stuTimeSection[MAX_TIME_SCHEDULE_NUM][MAX_REC_TSECT]; // ��һάǰ7��Ԫ�ض�Ӧÿ��7�죬��8��Ԫ�ض�Ӧ�ڼ��գ�ÿ�����6��ʱ���
} CFG_TIME_SCHEDULE;

// ��ʱ¼��������Ϣ
typedef struct tagCFG_RECORD_INFO
{
	int                 nChannelID;					// ͨ����(0��ʼ)
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT]; // ʱ���
	int					nPreRecTime;				// Ԥ¼ʱ�䣬Ϊ��ʱ��ʾ�ر�(0~300)
	BOOL				bRedundancyEn;				// ¼�����࿪��
	int					nStreamType;				// 0����������1��������1��2��������2��3��������3
	int					nProtocolVer;				// Э��汾��, ֻ��

	// ����
	bool				abHolidaySchedule;          // Ϊtrueʱ�м���������Ϣ��bHolidayEn��stuHolTimeSection����Ч;
    BOOL                bHolidayEn;                 // ����¼��ʹ��TRUE:ʹ��,FALSE:δʹ��
    CFG_TIME_SECTION    stuHolTimeSection[MAX_REC_TSECT];          // ����¼��ʱ���
} CFG_RECORD_INFO;

//-------------------------------��������---------------------------------

// ��̨��������
typedef enum tagCFG_LINK_TYPE
{
	LINK_TYPE_NONE,						    		// ������
	LINK_TYPE_PRESET,								// ����Ԥ�õ�
	LINK_TYPE_TOUR,									// ����Ѳ��
	LINK_TYPE_PATTERN,								// �����켣
} CFG_LINK_TYPE;

// ������̨��Ϣ
typedef struct tagCFG_PTZ_LINK
{
	CFG_LINK_TYPE		emType;						// ��������
	int					nValue;						// ����ȡֵ�ֱ��ӦԤ�õ�ţ�Ѳ���ŵȵ�
} CFG_PTZ_LINK;

// ������̨��Ϣ��չ
typedef struct tagCFG_PTZ_LINK_EX
{
	CFG_LINK_TYPE	emType;				// �������� 
	int			    nParam1;			// ��������1
	int			    nParam2;            // ��������2
	int			    nParam3;            // ��������3
	int			    nChannelID;         // ��������̨ͨ��
} CFG_PTZ_LINK_EX;

// �¼��������ݽṹ��
typedef struct tagCFG_EVENT_TITLE
{
	char				szText[MAX_CHANNELNAME_LEN];
	CFG_POLYGON			stuPoint;			// �������Ͻ�����, ����0-8191�������ϵ
	CFG_SIZE     		stuSize;			// ����Ŀ�Ⱥ͸߶�,����0-8191�������ϵ��ĳ���������Ϊ0��ʾ������������Ӧ���
    CFG_RGBA			stuFrontColor;		// ǰ����ɫ
    CFG_RGBA			stuBackColor;		// ������ɫ
} CFG_EVENT_TITLE;

// �ʼ���������
typedef enum tagCFG_ATTACHMENT_TYPE
{
		ATTACHMENT_TYPE_PIC,							// ͼƬ����
		ATTACHMENT_TYPE_VIDEO,							// ��Ƶ����
		ATTACHMENT_TYPE_NUM,							// ������������
} CFG_ATTACHMENT_TYPE;
// �ʼ���ϸ����
typedef struct tagCFG_MAIL_DETAIL
{
	   CFG_ATTACHMENT_TYPE emAttachType;                 // ��������
       int                 nMaxSize;                     // �ļ���С���ޣ���λkB
       int                 nMaxTimeLength;               // ���¼��ʱ�䳤�ȣ���λ�룬��video��Ч
}CFG_MAIL_DETAIL;

// �ָ�ģʽ
typedef enum tagCFG_SPLITMODE
{
	    SPLITMODE_1 = 1,						// 1����
	    SPLITMODE_2 = 2,						// 2����
	    SPLITMODE_4 = 4,						// 4����
		SPLITMODE_6 = 6,						// 6����
		SPLITMODE_8 = 8,						// 8����
		SPLITMODE_9 = 9,						// 9����
		SPLITMODE_12 = 12,				    	// 12����
		SPLITMODE_16 = 16,				    	// 16����
		SPLITMODE_20 = 20,				    	// 20����
		SPLITMODE_25 = 25,					    // 25����
		SPLITMODE_36 = 36,					    // 36����
		SPLITMODE_64 = 64,					    // 64����
		SPLITMODE_144 = 144,					// 144����
		SPLITMODE_PIP = 1000,                   // ���л��ָ�ģʽ����ֵ
		SPLITMODE_PIP1 = SPLITMODE_PIP + 1,		// ���л�ģʽ, 1��ȫ������+1��С���洰��
		SPLITMODE_PIP3 = SPLITMODE_PIP + 3,		// ���л�ģʽ, 1��ȫ������+3��С���洰��
		SPLITMODE_FREE = SPLITMODE_PIP * 2,	// ���ɿ���ģʽ���������ɴ������رմ��ڣ��������ô���λ�ú�Z�����
		SPLITMODE_COMPOSITE_1 = SPLITMODE_PIP * 3 + 1,	// �ں�����Ա1�ָ�
		SPLITMODE_COMPOSITE_4 = SPLITMODE_PIP * 3 + 4,	// �ں�����Ա4�ָ�
		SPLITMODE_EOF,                          // ������ʶ
} CFG_SPLITMODE;

// ��Ѳ��������
typedef struct tagCFG_TOURLINK
{
	BOOL				bEnable;			             // ��Ѳʹ��
	CFG_SPLITMODE	    emSplitMode;		             // ��Ѳʱ�ķָ�ģʽ
	int			        nChannels[MAX_VIDEO_CHANNEL_NUM];  // ��Ѳͨ�����б�
	int			        nChannelCount;		             // ��Ѳͨ������
} CFG_TOURLINK;

// �Ž���������
enum EM_CFG_ACCESSCONTROLTYPE
{
	EM_CFG_ACCESSCONTROLTYPE_NULL = 0,					// ��������
	EM_CFG_ACCESSCONTROLTYPE_AUTO,						// �Զ�
	EM_CFG_ACCESSCONTROLTYPE_OPEN,						// ����
	EM_CFG_ACCESSCONTROLTYPE_CLOSE,						// ����
	EM_CFG_ACCESSCONTROLTYPE_OPENALWAYS,				// ��Զ����
	EM_CFG_ACCESSCONTROLTYPE_CLOSEALWAYS,				// ��Զ�ر�
};

// �Ž��������������

#define MAX_ACCESSCONTROL_NUM	8						// ����Ž������������


// �������з���
typedef enum
{
	EM_CALLER_DEVICE = 0,								// �豸����
}EM_CALLER_TYPE;

// ����Э��
typedef enum
{
	EM_CALLER_PROTOCOL_CELLULAR = 0,					// �ֻ���ʽ
}EM_CALLER_PROTOCOL_TYPE;


// ��������������Ϣ
typedef struct tagCFG_TALKBACK_INFO
{
	BOOL				bCallEnable;					// ��������ʹ��
	EM_CALLER_TYPE		emCallerType;					// �������з���
	EM_CALLER_PROTOCOL_TYPE	emCallerProtocol;			// ��������Э��
}CFG_TALKBACK_INFO;

// �绰��������������Ϣ
typedef struct tagCFG_PSTN_ALARM_SERVER
{
	BOOL				bNeedReport;						// �Ƿ��ϱ����绰��������
	int					nServerCount;						// �绰��������������					
	BYTE 				byDestination[MAX_PSTN_SERVER_NUM];	// �ϱ��ı��������±�,�������CFG_PSTN_ALARM_CENTER_INFO
}CFG_PSTN_ALARM_SERVER;

// ����������Ϣ
typedef struct tagCFG_ALARM_MSG_HANDLE
{
	//����
	bool				abRecordMask;
	bool				abRecordEnable;
	bool				abRecordLatch;
	bool				abAlarmOutMask;
	bool				abAlarmOutEn;
	bool				abAlarmOutLatch;	
	bool				abExAlarmOutMask;
	bool				abExAlarmOutEn;
	bool				abPtzLinkEn;
	bool				abTourMask;
	bool				abTourEnable;
	bool				abSnapshot;
	bool				abSnapshotEn;
	bool				abSnapshotPeriod;
	bool				abSnapshotTimes;
	bool				abTipEnable;
	bool				abMailEnable;
	bool				abMessageEnable;
	bool				abBeepEnable;
	bool				abVoiceEnable;
	bool				abMatrixMask;
	bool				abMatrixEnable;
	bool				abEventLatch;
	bool				abLogEnable;
	bool				abDelay;
	bool				abVideoMessageEn;
	bool				abMMSEnable;
	bool				abMessageToNetEn;
	bool				abTourSplit;
	bool				abSnapshotTitleEn;

    bool                abChannelCount;
	bool                abAlarmOutCount;
	bool                abPtzLinkEx;
	bool                abSnapshotTitle;
	bool                abMailDetail;
	bool                abVideoTitleEn;
	bool                abVideoTitle;
	bool                abTour;
	bool                abDBKeys;
	bool                abJpegSummary;
	bool                abFlashEn;
	bool                abFlashLatch;
	


	//��Ϣ
	int					nChannelCount;								 // �豸����Ƶͨ����
	int					nAlarmOutCount;								 // �豸�ı����������
	DWORD				dwRecordMask[MAX_CHANNEL_COUNT];			 // ¼��ͨ������(��λ)
	BOOL				bRecordEnable;								 // ¼��ʹ��
	int					nRecordLatch;								 // ¼����ʱʱ��(��)
	DWORD				dwAlarmOutMask[MAX_CHANNEL_COUNT];			 // �������ͨ������
	BOOL				bAlarmOutEn;								 // �������ʹ��
	int					nAlarmOutLatch;								 // ���������ʱʱ��(��)
	DWORD				dwExAlarmOutMask[MAX_CHANNEL_COUNT];		 // ��չ�������ͨ������
	BOOL				bExAlarmOutEn;								 // ��չ�������ʹ��
	CFG_PTZ_LINK		stuPtzLink[MAX_VIDEO_CHANNEL_NUM];			 // ��̨������
	BOOL				bPtzLinkEn;									 // ��̨����ʹ��
	DWORD				dwTourMask[MAX_CHANNEL_COUNT];				 // ��ѯͨ������
	BOOL				bTourEnable;								 // ��ѯʹ��
	DWORD				dwSnapshot[MAX_CHANNEL_COUNT];				 // ����ͨ��������
	BOOL				bSnapshotEn;								 // ����ʹ��
	int					nSnapshotPeriod;							 // ��������(��)
	int					nSnapshotTimes;								 // ���Ĵ���
	BOOL				bTipEnable;									 // ������Ϣ����ʾ
	BOOL				bMailEnable;								 // �����ʼ��������ͼƬ����Ϊ����
	BOOL				bMessageEnable;								  // �ϴ�������������
	BOOL				bBeepEnable;							 	  // ����
	BOOL				bVoiceEnable;								  // ������ʾ
	DWORD				dwMatrixMask[MAX_CHANNEL_COUNT];			  // ������Ƶ����ͨ������
	BOOL				bMatrixEnable;								  // ������Ƶ����
	int					nEventLatch;								  // ������ʼ��ʱʱ��(��)��0��15
	BOOL				bLogEnable;									  // �Ƿ��¼��־
	int					nDelay;										  // ����ʱ����ʱ����Ч����λΪ��
	BOOL				bVideoMessageEn;							  // ������ʾ��Ļ����Ƶ�����ӵ���Ļ�����¼����ͣ�ͨ���ţ����ʱ��
	BOOL				bMMSEnable;									  // ���Ͳ���ʹ��
	BOOL				bMessageToNetEn;							  // ��Ϣ�ϴ�������ʹ��
	int					nTourSplit;									  // ��Ѳʱ�ķָ�ģʽ 0: 1����; 1: 8����
	BOOL				bSnapshotTitleEn;							  // �Ƿ����ͼƬ����
	int                 nPtzLinkExNum;                                // ��̨������
	CFG_PTZ_LINK_EX     stuPtzLinkEx[MAX_VIDEO_CHANNEL_NUM];          // ��չ��̨��Ϣ
	int                 nSnapTitleNum;                                // ͼƬ����������
	CFG_EVENT_TITLE     stuSnapshotTitle[MAX_VIDEO_CHANNEL_NUM];      // ͼƬ��������
	CFG_MAIL_DETAIL     stuMailDetail;                                // �ʼ���ϸ����
	BOOL                bVideoTitleEn;                                // �Ƿ������Ƶ���⣬��Ҫָ������
    int                 nVideoTitleNum;                               // ��Ƶ����������Ŀ
	CFG_EVENT_TITLE     stuVideoTitle[MAX_VIDEO_CHANNEL_NUM];         // ��Ƶ��������
	int                 nTourNum;                                     // ��ѯ������Ŀ
	CFG_TOURLINK        stuTour[MAX_VIDEO_CHANNEL_NUM];               // ��ѯ��������
	int                 nDBKeysNum;			                          // ָ�����ݿ�ؼ��ֵ���Ч��
	char                szDBKeys[MAX_DBKEY_NUM][MAX_CHANNELNAME_LEN]; // ָ���¼���ϸ��Ϣ����Ҫд�����ݿ�Ĺؼ���
	BYTE                byJpegSummary[MAX_SUMMARY_LEN];               // ���ӵ�JPEGͼƬ��ժҪ��Ϣ
	BOOL                bFlashEnable;                                 // �Ƿ�ʹ�ܲ����
	int                 nFlashLatch;                                  // �������ʱʱ��(��),��ʱʱ�䷶Χ��[10,300]
	
	bool				abAudioFileName;
	bool				abAlarmBellEn;
	bool				abAccessControlEn;
	bool				abAccessControl;

	char				szAudioFileName[MAX_PATH];					// ���������ļ�����·��
	BOOL				bAlarmBellEn;								// ����ʹ��
	BOOL				bAccessControlEn;							// �Ž�ʹ��

	DWORD				dwAccessControl;							// �Ž�����
	EM_CFG_ACCESSCONTROLTYPE	emAccessControlType[MAX_ACCESSCONTROL_NUM];	// �Ž�����������Ϣ
	
	bool				abTalkBack;	
	CFG_TALKBACK_INFO	stuTalkback;								// ��������������Ϣ

	bool				abPSTNAlarmServer;
	CFG_PSTN_ALARM_SERVER	stuPSTNAlarmServer;						// �绰��������������Ϣ
    CFG_TIME_SCHEDULE       stuTimeSection;                         // �¼���Ӧʱ���
	bool				abAlarmBellLatch;
	int					nAlarmBellLatch;							// ���������ʱʱ��(10-300��)

} CFG_ALARM_MSG_HANDLE;



// ����ʹ�ܿ��Ʒ�ʽö������
typedef enum tagEM_CTRL_ENABLE
{
	EM_CTRL_NORMAL=0,   //������ʹ��
	EM_CTRL_ALWAYS_EN,  //����ʹ��
	EM_CTRL_ONCE_DIS,   //��·
	EM_CTRL_ALWAYS_DIS, //�Ƴ�
	EM_CTRL_NUM         //ö����������
}EM_CTRL_ENABLE;


// ��������
typedef enum tagEM_CFG_DEFENCEAREATYPE
{
	EM_CFG_DefenceAreaType_Unknown = 0,	// δ֪����
	EM_CFG_DefenceAreaType_InTime,		// ��ʱ���� 
	EM_CFG_DefenceAreaType_Delay,		// ��ʱ����
	EM_CFG_DefenceAreaType_FullDay,		// 24Сʱ����
}EM_CFG_DEFENCEAREATYPE;

// �ⲿ��������
typedef struct tagCFG_ALARMIN_INFO
{
	int					nChannelID;									// ����ͨ����(0��ʼ)
	BOOL				bEnable;									// ʹ�ܿ���
	char				szChnName[MAX_CHANNELNAME_LEN];				// ����ͨ������
	int					nAlarmType;									// ���������ͣ�0�����գ�1������
	CFG_ALARM_MSG_HANDLE stuEventHandler;							// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���
	BOOL				abDevID;									// 
	char				szDevID[MAX_NAME_LEN];						// �豸ID
	int                 nPole;                                      // ����������ģʽ, 0:����Ч��1����Ч��
	                                                                // �������Ϊ�������ӵ�or��Դ����nAlarmType���ʹ��
	EM_SENSE_METHOD     emSense;                                    // ��������Ӧ��ʽ
	EM_CTRL_ENABLE      emCtrl;                                     // ����ʹ�ܿ��Ʒ�ʽ
	int                 nDisDelay;                                  // ��ʱ����ʱ��,��������Ϊ"Delay"(��ʱ����)ʱ����Ч, ��λ: ��, ���ʱ��ͨ����ѯ�������
	                                                                //emCtrlֵΪEM_CTRL_NORMAL��EM_CTRL_ALWAYS_EN ʱ��Ч��

	EM_CFG_DEFENCEAREATYPE emDefenceAreaType;						// ��������, ����֧�ֵ�����ͨ����ѯ�������
	int					nEnableDelay;								// ��ʱ����ʱ��, ��������Ϊ"Delay"(��ʱ����)ʱ����Ч, ��λ: ��, ���ʱ��ͨ����ѯ�������    
    int                 nSlot;                                      // ����ַ, -1��ʾ��Ч, 0��ʾ����ͨ��, 1��ʾ�����ڵ�һ�������ϵ���չͨ��, 2��3...�Դ�����
    int                 nLevel1;                                    // ��һ��������ַ, ��ʾ�����ڵ�nSlot�����ϵĵ�nLevel1��̽�������Ǳ�, -1��ʾ��Ч, ��0��ʼ
    bool                abLevel2;                                   // ��ʾnLevel2�ֶ��Ƿ����
    int                 nLevel2;                                    // �ڶ���������ַ, ��ʾ�����ڵ�nLevel1�����Ǳ��ϵ�̽�������, -1��ʾ��Ч, ��0��ʼ
} CFG_ALARMIN_INFO;

// �������뱨������
typedef struct tagCFG_NETALARMIN_INFO 
{
	int					nChannelID;									// ����ͨ����(0��ʼ)
	BOOL				bEnable;									// ʹ�ܿ���
	char				szChnName[MAX_CHANNELNAME_LEN];				// ����ͨ������
	int					nAlarmType;									// ���������ͣ�0�����գ�1������
	CFG_ALARM_MSG_HANDLE stuEventHandler;							// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���
} CFG_NETALARMIN_INFO;


// ����֧�ֵ���Ƶ��������
typedef struct tagCFG_MOTION_WINDOW
{
	int                  nThreshold;           // �����ֵ��ȡֵ[0, 100]
	int                  nSensitive;           // �����ȣ�ȡֵ[0, 100]
	CFG_RECT             stuWindow;            // ���촰������, ����λ��ȡֵ[0, 8192)
}CFG_MOTION_WINDOW;

// ��̬��ⱨ������
typedef struct tagCFG_MOTION_INFO 
{
	int					 nChannelID;									// ����ͨ����(0��ʼ), nVersion=1ʱ�����ֶ���Ч
	BOOL				 bEnable;									    // ʹ�ܿ���
	int					 nSenseLevel;								    // ������1��6
	int					 nMotionRow;									// ��̬������������
	int					 nMotionCol;									// ��̬������������
	BYTE				 byRegion[MAX_MOTION_ROW][MAX_MOTION_COL];	    // ����������32*32������
	CFG_ALARM_MSG_HANDLE stuEventHandler;							    // ��������
	CFG_TIME_SECTION	 stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];   // �¼���Ӧʱ���
	int			         nVersion;                                      // 0, 1, ��������ȷ��, ֻ��, ����1ʱ�����ֶ���Ч
	BOOL                 bSenseLevelEn;                                 // ֻ��������nSenseLevel�Ƿ���Ч
	BOOL                 bVRatioEn;                                     // ֻ�������ռ�ñ�ʹ�ܣ� ����nVolumeRatio�Ƿ���Ч
	int                  nVolumeRatio;                                  // ���ռ�ñ�,1-100
	BOOL                 bSRatioEn;                                     // ֻ����������ʹ�ܣ�����nSubRatioֵ�Ƿ���Ч
	int                  nSubRatio;                                     // ����Ĳв���ֵ, 1-100
	BOOL                 abWindow;                                      // ֻ����0: nMotionRow, nMotionCol��byRegion�ֶ���Ч, 1: ������Ƶ�����ֶ� 
	int                  nWindowCount;                                  // ��Ƶ���ڸ���
	CFG_MOTION_WINDOW    stuWindows[MAX_MOTION_WINDOW];                 // ��Ƶ��������
} CFG_MOTION_INFO;

// ��Ƶ��ʧ��������
typedef struct tagCFG_VIDEOLOST_INFO 
{
	int					nChannelID;									// ����ͨ����(0��ʼ)
	BOOL				bEnable;									// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;							// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���
} CFG_VIDEOLOST_INFO;

// ��Ƶ�ڵ���������
typedef struct tagCFG_SHELTER_INFO 
{
	int					nChannelID;									// ����ͨ����(0��ʼ)
	BOOL				bEnable;									// ʹ�ܿ���
	int					nSenseLevel;								// ������
	CFG_ALARM_MSG_HANDLE stuEventHandler;							// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���
} CFG_SHELTER_INFO;

// �޴洢�豸��������
typedef struct tagCFG_STORAGENOEXIST_INFO 
{
	BOOL				bEnable;						// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;				// ��������
} CFG_STORAGENOEXIST_INFO;

// �洢�豸���ʳ���������
typedef struct tagCFG_STORAGEFAILURE_INFO 
{
	BOOL				bEnable;						// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;				// ��������
} CFG_STORAGEFAILURE_INFO;

// �洢�豸�ռ䲻�㱨������
typedef struct tagCFG_STORAGELOWSAPCE_INFO 
{
	BOOL				bEnable;						// ʹ�ܿ���
	int					nLowerLimit;					// Ӳ��ʣ���������ޣ��ٷ���(0~99)
	CFG_ALARM_MSG_HANDLE stuEventHandler;				// ��������
} CFG_STORAGELOWSAPCE_INFO;

// ����Ͽ���������
typedef struct tagCFG_NETABORT_INFO 
{
	BOOL				bEnable;						// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;				// ��������
} CFG_NETABORT_INFO;

// IP��ͻ��������
typedef struct tagCFG_IPCONFLICT_INFO 
{
	BOOL				bEnable;						// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;				// ��������
} CFG_IPCONFLICT_INFO;

// CLIENT_QueryNewSystemInfo �ӿڵ����� CFG_CAP_ALARM (��ȡ����������)��Ӧ�ṹ��

// ������������ʽ
typedef struct tagCFG_ALARM_SENSE_METHOD
{
	int                 nSupportSenseMethodNum;								// ֧�ֵĴ�������ʽ��
	EM_SENSE_METHOD     emSupportSenseMethod[MAX_ALARM_SENSE_METHOD_NUM];   // ֧�ֵĴ�������ʽ
}CFG_ALARM_SENSE_METHOD;

typedef struct tagCFG_CAP_ALARM_INFO
{
	BOOL                 bAlarmPir;									// �豸�Ƿ�֧��PIR(������ʽ��Ӧ��)����,�ⲿ������һ��
	BOOL                 bFlashLight;								// �豸�Ƿ�֧�ֲ����
	int					 nDefenceAreaTypeNum;						// ��������������,Ϊ0��ʾ�޴��ֶ�ʱ�������벻��Ϊ����ʹ�á�
	EM_CFG_DEFENCEAREATYPE	emDefenceAreaType[MAX_ALARM_DEFENCE_TYPE_NUM];			// ֧�ַ������� 
	int				 	 nMaxDelay;									// ��ʱ�����������ʱʱ��,��λΪ�룬ֻ��֧����ʱ����ʱ���ֶβ���Ч��
	int					 nAlarmChannelNum;							// ����ͨ����,Ϊ�˱��ּ�����,��Ϊ0ʱ��ʾÿ��ͨ��֧���������͵Ĵ�����
	CFG_ALARM_SENSE_METHOD stuAlarmChannel[MAX_ALARM_CHANNEL_NUM];	// ����ͨ������
	int					 nAlarmBellCount;							// ���Ÿ���
	int					 nMaxBackupAlarmServer;						// ����ñ���������,�޴��ֶ�ʱĬ��Ϊ0,0��ʾ��֧�ֱ��ñ�������
	int					 nMaxPSTNAlarmServer;						// ���绰����������, �޴��ֶ�ʱĬ��Ϊ0,0��ʾ��֧�ֵ绰�������ġ�
}CFG_CAP_ALARM_INFO;

// ���������
typedef struct tagCFG_FLASH_LIGHT
{
	BOOL                bEnable;                        // ʹ�ܿ���
	int                 nBrightness;                    // ���� 0~100
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// ����ƹ���ʱ���
}CFG_FLASH_LIGHT;

typedef struct tagCFG_CUSTOMCASE
{
	char                szCaseTitle[MAX_OSD_TITLE_LEN];    // ��������
	char                szCaseContent[MAX_OSD_SUMMARY_LEN];  // ��������
	BOOL                bCaseNoOsdEn;                        // ������ŵ���ʹ��
}CFG_CUSTOMCASE;

// ˾����¼����
typedef struct tagCFG_JUDICATURE_INFO
{
	char                szDiskPassword[MAX_PASSWORD_LEN];// �������룬����ʱ��������ȷ������ܲ���

	char                szCaseNo[MAX_OSD_SUMMARY_LEN];     // �������
	BOOL                bCaseNoOsdEn;                      // ������ŵ���ʹ��
	char                szCaseTitle[MAX_OSD_SUMMARY_LEN];  // ��������
	BOOL                bCaseTitleOsdEn;                   // �������Ƶ���ʹ��
	char                szOfficer[MAX_OSD_SUMMARY_LEN];    // �참��Ա
	BOOL                bOfficerOsdEn;                     // �참��Ա����ʹ��
	char                szLocation[MAX_OSD_SUMMARY_LEN];   // �참�ص�
	BOOL                bLocationOsdEn;                    // �참�ص����ʹ��
	char                szRelatedMan[MAX_OSD_SUMMARY_LEN]; // �永��Ա
	BOOL                bRelatedManOsdEn;                  // �永��Ա����ʹ��
	char                szDiskNo[MAX_OSD_SUMMARY_LEN];     // ���̱��
	BOOL                bDiskNoOsdEn;                      // ���̱�ŵ���ʹ��

	BOOL                bCustomCase;                       // TRUE:�Զ���˾��������Ϣ,FALSE: �ϱ�szCaseNo���ֶ���Ч
	int                 nCustomCase;                       // ʵ��CFG_CUSTOMCASE����
	CFG_CUSTOMCASE      stuCustomCases[MAX_CUSTOMCASE_NUM];// �Զ���˾��������Ϣ

	BOOL                bDataCheckOsdEn;                   // ���̿�¼����У������ ����ʹ��
	BOOL                bAttachFileEn;                     // �����ϴ�ʹ��
}CFG_JUDICATURE_INFO;

// ��¼���¼�����
typedef struct tagCFG_BURNFULL_ONE
{
	char                szBurnDisk[MAX_NAME_LEN];          // ��¼�豸
	BOOL                bEnable;                           // ʹ�ܿ���
	unsigned int        nLowerLimit;                       // ����ʣ����������	��λ��M
	BOOL                bBurnStop;                         // ��¼ֹͣʹ��
	CFG_ALARM_MSG_HANDLE stuEventHandler;							// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���
}CFG_BURNFULL_ONE;

typedef struct tagCFG_BURNFULL_INFO
{
	unsigned int        nBurnDev;                          // ʵ�ʿ�¼�豸����
	CFG_BURNFULL_ONE    stuBurns[MAX_BURNING_DEV_NUM];     // ÿ��Ԫ�ض�Ӧһ����¼�豸
}CFG_BURNFULL_INFO;

//-------------------------------ץͼ��������---------------------------------
// ץͼ��������
typedef struct tagCFG_SNAPCAPINFO_INFO  
{
	int					nChannelID;						// ץͼͨ����(0��ʼ)
	DWORD				dwIMageSizeNum;					// ֧�ֵķֱ�����Ϣ
	CFG_CAPTURE_SIZE	emIMageSizeList[MAX_IMAGESIZE_NUM];
	DWORD				dwFramesPerSecNum;				// ֧�ֵ�֡����Ϣ
	int					nFramesPerSecList[MAX_FPS_NUM];
	DWORD				dwQualityMun;					// ֧�ֵĻ�����Ϣ
	CFG_IMAGE_QUALITY	emQualityList[MAX_QUALITY_NUM];

	DWORD               dwMode;							// ģʽ,��λ����һλ����ʱ���ڶ�λ���ֶ���
	DWORD               dwFormat;						// ͼƬ��ʽģʽ,��λ����һλ��bmp���ڶ�λ��jpg��
} CFG_SNAPCAPINFO_INFO;


//-------------------------------����洢����������---------------------------------
// ����洢����������
typedef struct tagCFG_CHANNEL_TIME_SECTION 
{
	CFG_TIME_SECTION stuTimeSection[WEEK_DAY_NUM][MAX_NAS_TIME_SECTION];//�洢ʱ���
} CFG_CHANNEL_TIME_SECTION;

typedef struct tagCFG_NAS_INFO
{
	BOOL						bEnable;									// ʹ�ܿ���
	int							nVersion;									// ����洢�������汾0=�ϵ�FTP��1=NAS�洢
	int							nProtocol;									// Э������0=FTP 1=SMB
	char						szAddress[MAX_ADDRESS_LEN];					// IP��ַ��������
	int							nPort;										// �˿ں�
	char						szUserName[MAX_USERNAME_LEN];				// �ʻ���
	char						szPassword[MAX_PASSWORD_LEN];				// ����
	char						szDirectory[MAX_DIRECTORY_LEN];				// �����Ŀ¼��
	int							nFileLen;									// �ļ�����
	int							nInterval;									// �����ļ�ʱ����
	CFG_CHANNEL_TIME_SECTION	stuChnTime[MAX_VIDEO_CHANNEL_NUM];			// �洢ʱ���
	int                         nChnTimeCount;                              // ��Ч�Ĵ洢ʱ�����
} CFG_NAS_INFO;

//------------------------------��̨����--------------------------------------------
// Э����
typedef struct tagCFG_PRONAME
{
	char				name[MAX_NAME_LEN];			// Э����
} CFG_PRONAME;

// ���ڻ�������
typedef struct tagCFG_COMM_PROP
{
	BYTE				byDataBit;					// ����λ��0��5��1��6��2��7��3��8
	BYTE				byStopBit;					// ֹͣλ��0��1λ��1��1.5λ��2��2λ
	BYTE				byParity;					// У��λ��0����У�飬1����У�飻2��żУ��
	BYTE				byBaudRate;					// �����ʣ�0��300��1��600��2��1200��3��2400��4��4800��													
	                                                // 5��9600��6��19200��7��38400��8��57600��9��115200
} CFG_COMM_PROP;

// ��λԤ�õ�����
typedef struct tagCFG_PRESET_HOMING
{
	int          nPtzPresetId;   //��̨Ԥ�õ���	0~65535
 //-1��ʾ��Ч
	int          nFreeSec;       //���е�ʱ�䣬��λΪ��
}CFG_PRESET_HOMING;

// ��̨����
typedef struct tagCFG_PTZ_INFO
{
	// ����
	bool				abMartixID;
	bool				abCamID;
	bool				abPTZType;

	// ��Ϣ
	int					nChannelID;								// ͨ����(0��ʼ)
	BOOL                bEnable;                                // ʹ�ܿ���
	char                szProName[MAX_NAME_LEN];                // Э������
	int					nDecoderAddress;						// ��������ַ��0 - 255
	CFG_COMM_PROP		struComm;
	int					nMartixID;								// �����
	int					nPTZType;								// ��̨����0-���ݣ�������̨ 1-Զ��������̨
	int					nCamID;									// ����ͷID
	int                 nPort;                                  // ʹ�õĴ��ڶ˿ں�
	CFG_PRESET_HOMING   stuPresetHoming;                        // һ��ʱ�䲻������̨���Զ���λ��ĳ��Ԥ�õ�
	int                 nControlMode;                           // ����ģʽ, 0:"RS485"���ڿ���(Ĭ��);1:"Coaxial" ͬ��ڿ���
} CFG_PTZ_INFO;  

//��ʱ��������
typedef enum tagCFG_PTZ_FUNC_TYPE
{
	FUNC_TYPE_TOUR = 0 ,		//Ѳ��
	FUNC_TYPE_PATTERN  ,		//�Զ�Ѳ��
	FUNC_TYPE_PRE	   ,		//Ԥ�õ�
	FUNC_TYPE_SCAN	   ,		//�Զ���ɨ
	FUNC_TYPE_MAX	   ,		
}CFG_PTZ_FUNC_TYPE;


//�Զ���λ
typedef struct tagCFG_AUTO_HOMING
{
	BOOL	bEnable;		// �Զ���λ����
	int		nTime;			// ����ʱ��,��ʾ���е�ʱ�䣬��λΪ��
}CFG_AUTO_HOMING;

//��ʱ��������
typedef struct tagCFG_PTZ_PER_AUTOMOVE_INFO
{
	BOOL				bEnable;		//	��ʱ�������ر�־ TRUE ����FALSE ��
	CFG_TIME_SCHEDULE	stTimeSchedule;	//  ʱ�������
	CFG_PTZ_FUNC_TYPE	emFuncType;		//  ��ʱ����
	int					nTourId;		// 	Ѳ�����,		��Χ����CFG_PTZ_PROTOCOL_CAPS_INFO��wTourMin��wTourMax
	int					nPatternId;		// 	�Զ�Ѳ�����,	��Χ����CFG_PTZ_PROTOCOL_CAPS_INFO��wPatternMin��wPatternMax
	int					nPresetId;		//  Ԥ�õ���,		��Χ����CFG_PTZ_PROTOCOL_CAPS_INFO��wPresetMin��wPresetMax
	int					nScanId;		//	�Զ���ɨ���,	��Χ����CFG_PTZ_PROTOCOL_CAPS_INFO��wAutoScanMin��wAutoScanMax
	CFG_AUTO_HOMING		stAutoHoming;	//  �Զ���λ,һ��ʱ�䲻������̨���Զ���λ����ʱ����ڵĶ���
}CFG_PTZ_PER_AUTOMOVE_INFO;

typedef struct tagCFG_PTZ_ALL_AUTOMOVE_INFO
{
	CFG_PTZ_PER_AUTOMOVE_INFO stPTZPerInfo[MAX_CONFIG_NUM];		//������Ϣ
	int						  nCfgNum;							//��ȡ�������ø���
}CFG_PTZ_ALL_AUTOMOVE_INFO;

//��̨��ʱ�������ã�ע�⣬�˽ṹ����豸
typedef struct tagCFG_PTZ_AUTOMOVE_INFO
{
	CFG_PTZ_ALL_AUTOMOVE_INFO *pstPTZAutoConfig;				//��̨��������Ϣ
	int						   nMaxPTZNum;						//�ṹ���������̨����(���ڶ�ͨ����ѯ�����벻С���豸ͨ�������ڵ�ͨ����ѯ��һ���͹���)
	int						   nReturnPTZNum;					//�豸���ص���̨����(һ��Ϊ�豸ͨ����)
}CFG_PTZ_AUTOMOVE_INFO;

//----------------------------------��Ƶ�����豸����------------------------------------------
// ����֧�ֵĹ���
typedef struct
{
	DWORD             dwSupportedRule;                                         // ��������
	int               nSupportedObjectTypeNum;                                 // ֧�ֵļ���������͸���
	char              szObjectTypeName[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];	   // ֧�ֵļ�����������б�
	int               nSupportedActionsNum;                                    // ֧�ֵļ�����嶯������
	char              szSupportedActions[MAX_ACTION_LIST_SIZE][MAX_NAME_LEN];  // ֧�ֵļ�����嶯���б�
	int               nSupportedDetectTypeNum;                                 // ֧�ֵļ�����͸���
	char              szSupportedDetectTypes[MAX_ACTION_LIST_SIZE][MAX_NAME_LEN];// ֧�ֵļ�������б�
	int               nSupportFaceTypeNum;                                       // ֧�ֵ�����������͸���
	char              szSupportFaceTypes[MAX_HUMANFACE_LIST_SIZE][MAX_NAME_LEN]; // ֧�ֵ�������������б�
	BOOL              bTriggerPosition;                                        // �Ƿ�֧�ִ�������λ��
}SCENE_SUPPORT_RULE;

// �궨����������Ϣ
typedef struct tagCFG_CAP_CELIBRATE_AREA
{
	EM_CALIBRATEAREA_TYPE  emType;												 // �궨��������
	BYTE                   byMaxHorizontalStaffNum;                              // ֧�ֵ�ˮƽ���������
	BYTE                   byMinHorizontalStaffNum;                              // ֧�ֵ�ˮƽ�����С����
	BYTE                   byMaxVerticalStaffNum;                                // ֧�ֵĴ�ֱ���������
	BYTE                   byMinVerticalStaffNum;                                // ֧�ֵĴ�ֱ�����С����
}CFG_CAP_CELIBRATE_AREA;

// ��������
typedef struct tagCFG_CAP_SCENE
{
	char               szSceneName[MAX_PATH];                                   // ��������
	int                nSupportedObjectTypeNum;                                 // ��ǰ��������֧�ֵļ���������͸���
	char               szObjectTypeName[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];	// ��ǰ��������֧�ֵļ�����������б�
	int                nSupportRules;                                           // ֧�ֵĹ������
	SCENE_SUPPORT_RULE stSpportRules[MAX_RULE_LIST_SIZE];                       // ֧�ֵĹ����б�

	//֧�ֵ�ģ�����
	bool               bDisturbance;                                            // �Ƿ�֧���Ŷ�ǿ������
	bool               bAntiDisturbance;                                        // �Ƿ�֧��ȥ�Ŷ�����
	bool               bBacklight;                                              // �Ƿ�֧����⴦��
	bool               bShadow;                                                 // �Ƿ�֧����Ӱ����
	bool               bAccuracy;                                               // �Ƿ�֧�ּ�⾫��
	bool               bMovingStep;												// �Ƿ�֧�ּ�ⲽ��
	bool               bScalingFactor;                                          // �Ƿ�֧�ּ������
	bool               bThresholdY;                                             // �Ƿ�֧��Y�����ж���ֵ
	bool               bThresholdUV;                                            // �Ƿ�֧��UV�����ж���ֵ
	bool               bThresholdEdge;                                          // �Ƿ�֧�ֱ�Ե����ж���ֵ
	bool               bDetectBalance;                                          // �Ƿ�֧�ּ��ƽ��
	bool               bAlgorithmIndex;                                         // �Ƿ�֧���㷨���
	bool               bHighlight;                                              // �Ƿ�֧�ָ߹⴦����Backgroud���� 
	bool               bSnapshot;                                               // �Ƿ�֧������ץͼ
	bool               bDetectRegion;                                           // �Ƿ�֧�ּ����������
	bool               bExcludeRegion;                                          // �Ƿ�֧���ų���������
	bool               bContourAssistantTrack;                                  // �Ƿ�֧��������������

	//֧�ֵĳ�������
	bool               bCameraAspect;                                            // �Ƿ�����ͷλ�ò���
	bool               bJitter;                                                  // �Ƿ�֧�ֶ�������
	bool               bDejitter;                                                // �Ƿ�֧��ȥ�����������

	// ֧�ֵı궨������
	int               nMaxCalibrateAreaNum;                                      // ���궨�������
	int               nCalibrateAreaNum;                                         // �궨����������Ϣ����
	CFG_CAP_CELIBRATE_AREA stCalibrateAreaCap[MAX_CALIBRATEAREA_TYPE_NUM];       // �궨����������Ϣ

	// �ߴ������������ʽ
	bool              bPixel;                                                    // �Ƿ�֧�����ؼ�����ʽ
	bool              bMetric;                                                   // �Ƿ�֧��ʵ�ʳ��ȼ�����ʽ
	bool              bCalibratedPixel;                                          // �Ƿ�֧��Զ�˽��˱궨������ؼ�����ʽ

	char              szSubType[MAX_SCENE_SUBTYPE_NUM][MAX_SCENE_SUBTYPE_LEN];  // ��ǰ������֧�ֵ��ӳ�������
	int               nSubTypeNum;                                              // �ӳ������͸���
}CFG_CAP_SCENE;

// �����б�
typedef struct tagCFG_VACAP_SUPPORTEDSCENES
{
	int                nScenes;													   // ֧�ֵĳ�������
	CFG_CAP_SCENE      stScenes[MAX_SCENE_LIST_SIZE];                              // ֧�ֵĳ����б�
}CFG_VACAP_SUPPORTEDSCENES;

#define CFG_DEVICE_ANALYSE_INFO CFG_CAP_DEVICE_ANALYSE_INFO
//��Ƶ�����豸������Ϣ
typedef struct tagCFG_CAP_DEVICE_ANALYSE_INFO
{
	int                nMaxChannels;											 // ֧�����ܷ��������ͨ����
}CFG_CAP_DEVICE_ANALYSE_INFO;

// ĳ������֧�ֵ���������
typedef struct
{
	DWORD               dwRuleType;                                             // ��ǰ��������
	int					nSupportedObjectTypeNum;								// ��ǰ��������֧�ֵļ���������͸���
	char				szObjectTypeName[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];	// ��ǰ��������֧�ֵļ�����������б�
}RULE_SUPPORTED_OBJECT_TYPE;

// ��Ƶ����������
typedef struct tagCFG_CAP_ANALYSE_INFO
{
	int					nSupportedSceneNum;										// ֧�ֵĳ�������
	char				szSceneName[MAX_SCENE_LIST_SIZE][MAX_NAME_LEN];			// ֧�ֵĳ����б�
	int					nMaxMoudles;											// ÿͨ��֧��������ģ����
	int					nSupportedObjectTypeNum;								// ֧�ֵļ���������͸���
	char				szObjectTypeName[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];	// ֧�ֵļ�����������б�
	int					nMaxRules;												// ÿͨ��֧������������
	int					nSupportedRulesNum;										// ֧�ֵ��¼����͹������
	DWORD				dwRulesType[MAX_RULE_LIST_SIZE];	             		// ֧�ֵ��¼����͹����б��¼����ͣ����dhnetsdk.h��"���ܷ����¼�����"
	int					nMaxStaffs;												// ֧�ֵ�����߸���
	int					nMaxPointOfLine;										// ������󶥵���
	int					nMaxPointOfRegion;										// ������󶥵���
	int                 nMaxInternalOptions;                                    // ����ڲ�ѡ�����
	bool                bComplexSizeFilter;                                     // �Ƿ�֧�ָ��ӳߴ������	���ӳߴ������ʹ�ö�����������˺Ϳ�߱ȹ��˲�����      
	bool                bSpecifiedObjectFilter;                                 // �Ƿ�֧���ض������������
	int                 nMaxExcludeRegionNum;                                   // ֧��ģ���е�����ų��������
	int                 nMaxCalibrateBoxNum;                                    // ֧�ֵ�ģ���е����У׼�����
	int                 nMinCalibrateBoxNum;                                    // ģ����������Ҫ���õ�У׼�����
	int                 nMaxSepcialDetectRegions;                               // ģ����֧�ֵ�����������������
	int                 nSupportedTimeSectionNum;                               // ֧�ֵ�ÿ���ʱ��θ��� 
	int                 nSpecialDetectPropertyNum;                              // ֧�ֵ������������Ը���
	int			        nSupportedSpecialDetectPropertys[EM_SEPCIALREGION_PROPERTY_TYPE_NUM]; // ֧�ֵ�������������
	DWORD				nSupportedVideoChannelType;								// ֧�ֵ���Ƶͨ������ѡ��   ��0λΪ1��ʾ֧����������,��1λΪ1��ʾ֧��ģ������,��2Ϊ1��ʾ֧�ֻ��(���ֺ�ģ��)				
	bool				bSupportMultiSceneSwitch;								// �Ƿ�֧�ֶೡ���л�
	CFG_VACAP_SUPPORTEDSCENES  stSupportScenes;                                 // ֧�ֵĳ���������
} CFG_CAP_ANALYSE_INFO;

// У׼����Ϣ
typedef struct tagCFG_CALIBRATEBOX_INFO
{
	CFG_POLYGON         stuCenterPoint;                       // У׼�����ĵ�����(��������һ����[0,8191]����)
	float               fRatio;                               // ��Ի�׼У׼��ı���(����1��ʾ��׼���С��0.5��ʾ��׼���С��һ��)
}CFG_CALIBRATEBOX_INFO;

// �궨����,��ͨ����ʹ��
typedef struct tagCFG_CALIBRATEAREA_INFO
{
	int               nLinePoint;                             // ˮƽ�������߶�����
	CFG_POLYGON       stuLine[MAX_POLYLINE_NUM];              // ˮƽ��������
	float             fLenth;                                 // ʵ�ʳ���
	CFG_REGION        stuArea;                                // ����
	int                 nStaffNum;                            // ��ֱ�����
	CFG_STAFF           stuStaffs[MAX_STAFF_NUM];             // ��ֱ���         
	EM_CALIBRATEAREA_TYPE emType;							  // ��������
}CFG_CALIBRATEAREA_INFO;

// ����ʶ�𳡾�
typedef struct tagCFG_FACERECOGNITION_SCENCE_INFO
{
	double				dbCameraHeight;							// ����ͷ��ظ߶� ��λ����
	double				dbCameraDistance;						// ����ͷ��������������ĵ�ˮƽ���� ��λ����
	int                 nMainDirection;                         // ������Ҫ���򶥵���
	CFG_POLYGON         stuMainDirection[MAX_POLYLINE_NUM];     // ������Ҫ���򣬵�һ��������ʼ�㣬�ڶ���������ֹ��
	char                byFaceAngleDown;                        // ��Ҫ���������������ƫ��, ��λ�ȣ�-45~45��������ʾ���������ϱߣ�������ʾ���������±ߣ�0��ʾ������ֱ����������������ͷ��
	char                byFaceAngleUp;                          // ��Ҫ���������������ƫ��,��λ�ȣ�-45~45��������ʾ���������ϱߣ�������ʾ���������±ߣ�0��ʾ������ֱ����������������ͷ��
 	char                byFaceAngleLeft;                        // ��Ҫ���������������ƫ��,��λ�ȣ�-45~45��������ʾ����������ߣ�������ʾ���������ұߣ�0��ʾ����ˮƽ����������������ͷ
	char                byFaceAngleRight;                       // ��Ҫ���������������ƫ��,��λ�ȣ�-45~45��������ʾ����������ߣ�������ʾ���������ұߣ�0��ʾ����ˮƽ����������������ͷ
	EM_FACEDETECTION_TYPE	emDetectType;						// �����������
}CFG_FACERECOGNITION_SCENCE_INFO;

// ������ⳡ��
typedef struct tagCFG_FACEDETECTION_SCENCE_INFO
{
	double				dbCameraHeight;							// ����ͷ��ظ߶� ��λ����
	double				dbCameraDistance;						// ����ͷ��������������ĵ�ˮƽ���� ��λ����
	int                 nMainDirection;                         // ������Ҫ���򶥵���
	CFG_POLYGON         stuMainDirection[MAX_POLYLINE_NUM];     // ������Ҫ���򣬵�һ��������ʼ�㣬�ڶ���������ֹ��
	char                byFaceAngleDown;                        // ��Ҫ���������������ƫ��, ��λ�ȣ�-45~45��������ʾ���������ϱߣ�������ʾ���������±ߣ�0��ʾ������ֱ����������������ͷ��
	char                byFaceAngleUp;                          // ��Ҫ���������������ƫ��,��λ�ȣ�-45~45��������ʾ���������ϱߣ�������ʾ���������±ߣ�0��ʾ������ֱ����������������ͷ��
	char                byFaceAngleLeft;                        // ��Ҫ���������������ƫ��,��λ�ȣ�-45~45��������ʾ����������ߣ�������ʾ���������ұߣ�0��ʾ����ˮƽ����������������ͷ
	char                byFaceAngleRight;                       // ��Ҫ���������������ƫ��,��λ�ȣ�-45~45��������ʾ����������ߣ�������ʾ���������ұߣ�0��ʾ����ˮƽ����������������ͷ
	EM_FACEDETECTION_TYPE	emDetectType;						// �����������
}CFG_FACEDETECTION_SCENCE_INFO;

// ��ͨ����
typedef struct tagCFG_TRAFFIC_SCENE_INFO 
{
	BOOL                abCompatibleMode;	
	int                 nCompatibleMode;                        // 0:"OldTrafficRule" : ��ͨ�Ϲ������ģʽ;1:"NewTrafficRule" :  ��ͨ�¹������ģʽ;-1:�ַ�������
	float				fCameraHeight;							// ����ͷ��ظ߶�	��λ����
	float				fCameraDistance;						// ����ͷ��������������ĵ�ˮƽ����	��λ����
	char                szSubType[MAX_NAME_LEN];                // ��ͨ������������,"Gate" ��������,"Junction" ·������ 
																// "Tunnel"������� , "ParkingSpace"��λ�������
																// "Bridge"��������
																// "Freeway"���ٹ�·����                 
	CFG_POLYGON         stuNearDetectPoint;                     // ��������
	CFG_POLYGON         stuFarDectectPoint;                     // Զ������
	int                 nNearDistance;                          // NearDetectPoint,ת����ʵ�ʳ�����ʱ,������ͷ��ֱ�ߵ�ˮƽ����
	int                 nFarDistance;                           // FarDectectPoint,ת����ʵ�ʳ�����ʱ,������ͷ��ֱ�ߵ�ˮƽ����
	int                 nPlateHintNum;                          // �����ַ���ʾ����
	char                szPlateHints[MAX_PLATEHINT_NUM][MAX_NAME_LEN]; // �����ַ���ʾ���飬������ͼƬ�����ϲ��ʶ��ȷ��ʱ�����ݴ������е��ַ�����ƥ�䣬�����±�ԽС��ƥ�����ȼ�Խ��
	int                 nLaneNum;                               // ������
	CFG_LANE            stuLanes[MAX_LANE_NUM];                 // ������Ϣ
} CFG_TRAFFIC_SCENE_INFO;

// �ձ鳡��
typedef struct tagCFG_NORMAL_SCENE_INFO
{
	float				fCameraHeight;							// ����ͷ��ظ߶�	��λ����
	float				fCameraAngle;							// ����ͷ�봹����ļн�	��λ�ȣ�0~90��
	float				fCameraDistance;						// ����ͷ��������������ĵ�ˮƽ����	��λ����
	CFG_POLYGON			stuLandLineStart;						// ��ƽ���߶���ʼ��(������������һ����[0,8192)���䡣)
	CFG_POLYGON			stuLandLineEnd;							// ��ƽ���߶���ֹ��(������������һ����[0,8192)���䡣)
} CFG_NORMAL_SCENE_INFO;

// ��ͨѲ�ӳ���
typedef struct tagCFG_TRAFFIC_TOUR_SCENE_INFO 
{
	int                 nPlateHintNum;                          // �����ַ���ʾ����
	char                szPlateHints[MAX_PLATEHINT_NUM][MAX_NAME_LEN]; // �����ַ���ʾ���飬������ͼƬ�����ϲ��ʶ��ȷ��ʱ�����ݴ������е��ַ�����ƥ�䣬�����±�ԽС��ƥ�����ȼ�Խ��
} CFG_TRAFFIC_TOUR_SCENE_INFO;

// ��Ƶ����ȫ�����ó���
typedef struct tagCFG_ANALYSEGLOBAL_SCENE
{
	char				szSceneType[MAX_NAME_LEN];				// Ӧ�ó���,���"֧�ֵĳ����б�"

	// ����Ϊ����������Ϣ, ����szSceneType�����ĸ�������Ч
	union
	{
		CFG_FACEDETECTION_SCENCE_INFO	stuFaceDetectionScene;	// ������ⳡ��/����ʶ����
		CFG_TRAFFIC_SCENE_INFO			stuTrafficScene;		// ��ͨ����
		CFG_NORMAL_SCENE_INFO			stuNormalScene;			// ��ͨ����/Զ������/�о�����/��������/���ڳ���/����ͳ�Ƴ���
		CFG_TRAFFIC_TOUR_SCENE_INFO		stuTrafficTourScene;	// ��ͨѲ�ӳ���
	};
} CFG_ANALYSEGLOBAL_SCENE;

typedef struct tagCFG_TIME
{
	DWORD				dwHour;					// ʱ
	DWORD				dwMinute;				// ��
	DWORD				dwSecond;				// ��
}CFG_TIME;

typedef struct tagCFG_TIME_PERIOD
{
	CFG_TIME	stuStartTime;				
	CFG_TIME	stuEndTime;			
}CFG_TIME_PERIOD;

// �ೡ���궨�������û�����Ԫ
typedef struct tagCFG_CALIBRATEAREA_SCENE_UNIT
{
	unsigned int           nCalibrateAreaNum;                                // �˳����ڱ궨������
	CFG_CALIBRATEAREA_INFO stuCalibrateArea[MAX_CALIBRATEBOX_NUM];           // �궨����(�����ֶβ����ڣ�������������Ϊ�궨����)
}
CFG_CALIBRATEAREA_SCENE_UNIT;

// �ೡ���궨��������
typedef struct tagCFG_CALIBRATEAREA_SCENE_INFO
{
	DWORD                        dwMaxSceneCalibrateAreaNum;                 // �ೡ���궨����������(��Ҫ����˴�С�ڴ�)
	DWORD                        dwRetSceneCalibrateAreaNum;                 // ʵ�ʰ����ೡ���궨�������
	CFG_CALIBRATEAREA_SCENE_UNIT *pstuCalibrateArea;                         // �ೡ���궨����Ԫ
}
CFG_CALIBRATEAREA_SCENE_INFO;

// ��̨�������굥Ԫ
typedef struct tagCFG_PTZ_SPACE_UNIT
{
	int                    nPositionX;           //��̨ˮƽ�˶�λ�ã���Ч��Χ��[0,3600]
	int                    nPositionY;           //��̨��ֱ�˶�λ�ã���Ч��Χ��[-1800,1800]
	int                    nZoom;                //��̨��Ȧ�䶯λ�ã���Ч��Χ��[0,128]
}CFG_PTZ_SPACE_UNIT;

// �궨��������
typedef struct tagCFG_CALIBRATEAREA_UNIT
{
	int                          nSceneID;                                 // �������
	int                          nPtzPresetID;                             // Ԥ�õ���
	BOOL                         abCalibrateArea;                          // �궨�����Ƿ����
	CFG_CALIBRATEAREA_SCENE_UNIT stuCalibrateArea;                         // �궨����
	CFG_PTZ_SPACE_UNIT           stuPtzPosition;                           // �궨����̨λ��
}
CFG_VIDEO_ANALYSE_CALIBRATEAREA_UNIT;

// �궨��������
typedef struct tagCFG_VIDEO_ANALYSE_CALIBRATEAREA
{

	DWORD                                dwMaxSceneCalibrateNum;           // �ೡ���궨����������(��Ҫ����˴�С�ڴ�)
	DWORD                                dwRetSceneCalibrateNum;           // ʵ�ʰ����ೡ���궨�������
	CFG_VIDEO_ANALYSE_CALIBRATEAREA_UNIT *pstuCalibrateAreaUnit;           // �궨����
}
CFG_VIDEO_ANALYSE_CALIBRATEAREA;

// ��ҹ�㷨�л�ģʽ
typedef enum tagCFG_TIMEPERIOD_SWITCH_MODE
{
	CFG_TIMEPERIOD_SWITCH_MODE_UNKNOWN,                                     // δ֪
	CFG_TIMEPERIOD_SWITCH_MODE_BYCOLOR,                                    // ͨ��ɫ���л�                     
	CFG_TIMEPERIOD_SWITCH_MODE_BYBRIGHTNESS,                               // ͨ�������л�
}CFG_TIMEPERIOD_SWITCH_MODE;

// �ೡ���궨����ͺ�ҹ���û�����Ԫ
typedef struct tagCFG_TIME_PERIOD_SCENE_UNIT
{
	CFG_TIME_PERIOD        stuDayTimePeriod;								 // �궨�����ʱ���.(8,20),��ʾ��8�㵽����20��Ϊ����
	CFG_TIME_PERIOD        stuNightTimePeriod;								 // �궨��ҹ��ʱ���.(20,7)����ʾ����8�㵽�賿7��Ϊ��ҹ
	CFG_TIMEPERIOD_SWITCH_MODE emSwitchMode;                                  // ��ҹ�㷨�л�ģʽ�����CFG_TIMEPERIOD_SWITCH_MODE
}
CFG_TIME_PERIOD_SCENE_UNIT;

// �ೡ���궨����ͺ�ҹ����
typedef struct tagCFG_TIME_PERIOD_SCENE_INFO
{
	DWORD                        dwMaxTimePeriodSceneNum;                    // �ೡ���궨����ͺ�ҹ����������(��Ҫ����˴�С�ڴ�)
	DWORD                        dwRetTimePeriodSceneNum;                    // ʵ�ʰ����ೡ���궨����ͺ�ҹ���ø���
	CFG_TIME_PERIOD_SCENE_UNIT   *pstuTimePeriodScene;                       // �ೡ�������ͺ�ҹ������Ԫ
}
CFG_TIME_PERIOD_SCENE_INFO;

// ��Ƶ����ȫ������
typedef struct tagCFG_ANALYSEGLOBAL_INFO
{
	// ��Ϣ
	char				szSceneType[MAX_NAME_LEN];				// Ӧ�ó���,���"֧�ֵĳ����б�"

	//��ͨ������Ϣ
	double				CameraHeight;							// ����ͷ��ظ߶�	��λ����
	double				CameraDistance;							// ����ͷ��������������ĵ�ˮƽ����	��λ����
	CFG_POLYGON         stuNearDetectPoint;                     // ��������
	CFG_POLYGON         stuFarDectectPoint;                     // Զ������
	int                 nNearDistance;                          // NearDetectPoint,ת����ʵ�ʳ�����ʱ,������ͷ��ֱ�ߵ�ˮƽ����
	int                 nFarDistance;                           // FarDectectPoint,ת����ʵ�ʳ�����ʱ,������ͷ��ֱ�ߵ�ˮƽ����
	char                szSubType[MAX_NAME_LEN];                // ��ͨ������������,"Gate",��������,"Junction" ·������                            
	int                 nLaneNum;                               // ������
	CFG_LANE            stuLanes[MAX_LANE_NUM];                 // ������Ϣ
	int                 nPlateHintNum;                          // �����ַ���ʾ����
	char                szPlateHints[MAX_PLATEHINT_NUM][MAX_NAME_LEN]; // �����ַ���ʾ���飬������ͼƬ�����ϲ��ʶ��ȷ��ʱ�����ݴ������е��ַ�����ƥ�䣬�����±�ԽС��ƥ�����ȼ�Խ��
	int                 nLightGroupNum;                         // ������
	CFG_LIGHTGROUPS     stLightGroups[MAX_LIGHTGROUP_NUM];      // ����������Ϣ

	// һ�㳡����Ϣ 
	int                 nStaffNum;                              // �����
	CFG_STAFF           stuStaffs[MAX_STAFF_NUM];               // ���

	unsigned int        nCalibrateAreaNum;                         // �궨������
	CFG_CALIBRATEAREA_INFO stuCalibrateArea[MAX_CALIBRATEBOX_NUM]; // �궨����(�����ֶβ����ڣ�������������Ϊ�궨����)

	BOOL                bFaceRecognition;                          // ����ʶ�𳡾��Ƿ���Ч
	CFG_FACERECOGNITION_SCENCE_INFO stuFaceRecognitionScene;       // ����ʶ�𳡾�
		
	bool                abJitter;
	bool                abDejitter;	
	BYTE                bReserved[2];                           // �����ֶ�

	int					nJitter;								// ����������� : ����������ʣ�ȡֵ0-100����Ӧ��ֹ����������̶ȣ�����Խ������ֵԽ��
	BOOL                bDejitter;                              // �Ƿ���ȥ����ģ�� Ŀǰ��ʵ��

	BOOL                abCompatibleMode;	
	int                 nCompatibleMode;                        // 0:"OldTrafficRule" : ��ͨ�Ϲ������ģʽ;1:"NewTrafficRule" :  ��ͨ�¹������ģʽ;-1:�ַ�������

	int                 nCustomDataLen;                         // ʵ�����ݳ��ȣ����ܴ���1024
	BYTE                byCustomData[1024];                     // �������Զ�����������
	double				CameraAngle;							// ����ͷ�봹����ļн�
	CFG_POLYGON			stuLandLineStart;						// ��ƽ���߶���ʼ��(������������һ����[0,8192)���䡣)
	CFG_POLYGON			stuLandLineEnd;							// ��ƽ���߶���ֹ��(������������һ����[0,8192)���䡣)

	BOOL				bFaceDetection;							// ������ⳡ���Ƿ���Ч
	CFG_FACEDETECTION_SCENCE_INFO	stuFaceDetectionScene;		// ������ⳡ��
	CFG_TIME_PERIOD		stuDayTimePeriod;						// �궨�����ʱ���.(8,20),��ʾ��8�㵽����20��Ϊ����
	CFG_TIME_PERIOD		stuNightTimePeriod;						// �궨��ҹ��ʱ���.(20,7)����ʾ����8�㵽�賿7��Ϊ��ҹ
	CFG_TIME_PERIOD_SCENE_INFO      stuTimePeriodSceneInfo;     // �ೡ���궨����ͺ�ҹʱ���
	CFG_CALIBRATEAREA_SCENE_INFO    stuCalibrateAreaSceneInfo;  // �ೡ���궨����������Ϣ
	CFG_TIMEPERIOD_SWITCH_MODE emSwitchMode;                    // ��ҹ�㷨�л�ģʽ,���CFG_TIMEPERIOD_SWITCH_MODE
	BYTE                bReserved2[2812];                       // �����ֶ� ������չ

	int					nSceneNum;									// ������, >0ʱ��ʾ֧�ֶೡ��, stuMultiScene��Ч
	CFG_ANALYSEGLOBAL_SCENE	stuMultiScene[MAX_ANALYSE_SCENE_NUM];	// �ೡ������
} CFG_ANALYSEGLOBAL_INFO;

// �ߴ������
typedef struct tagCFG_SIZEFILTER_INFO
{
	int                   nCalibrateBoxNum;                       // У׼�����
	CFG_CALIBRATEBOX_INFO stuCalibrateBoxs[MAX_CALIBRATEBOX_NUM]; // У׼��(Զ�˽��˱궨ģʽ����Ч)
	bool                bMeasureModeEnable;                       // ������ʽ�����Ƿ���Ч
	BYTE                bMeasureMode;                             // ������ʽ,0-���أ�����ҪԶ�ˡ����˱궨, 1-ʵ�ʳ��ȣ���λ����, 2-Զ�˽��˱궨�������
	bool                bFilterTypeEnable;                        // �������Ͳ����Ƿ���Ч
	// ByArea,ByRatio�������ݣ�ʹ�ö�����ByArea��ByRatioѡ����� 2012/03/06
	BYTE				bFilterType;			 				  // ��������:0:"ByLength",1:"ByArea", 2"ByWidthHeight"
	BYTE                bReserved[2];                             // �����ֶ�
	bool                bFilterMinSizeEnable;                     // ������С�ߴ�����Ƿ���Ч
	bool                bFilterMaxSizeEnable;                     // �������ߴ�����Ƿ���Ч
	CFG_SIZE			stuFilterMinSize;						  // ������С�ߴ� "ByLength"ģʽ�±�ʾ��ߵĳߴ磬"ByArea"ģʽ�¿��ʾ���������Ч(Զ�˽��˱궨ģʽ�±�ʾ��׼��Ŀ�߳ߴ�)��
	CFG_SIZE			stuFilterMaxSize;				          // �������ߴ� "ByLength"ģʽ�±�ʾ��ߵĳߴ磬"ByArea"ģʽ�¿��ʾ���������Ч(Զ�˽��˱궨ģʽ�±�ʾ��׼��Ŀ�߳ߴ�)��
	
	bool                abByArea;
	bool                abMinArea;
	bool                abMaxArea;
	bool                abMinAreaSize;
	bool                abMaxAreaSize;
	bool                bByArea;                                  // �Ƿ�������� ͨ������ComplexSizeFilter�ж��Ƿ����
	bool                bReserved1[2];
	float               nMinArea;                                 // ��С���
	float               nMaxArea;                                 // ������
	CFG_SIZE            stuMinAreaSize;                           // ��С������ο�ߴ� "������ʽ"Ϊ"����"ʱ����ʾ��С������ο�Ŀ�߳ߴ磻"������ʽ"Ϊ"Զ�˽��˱궨ģʽ"ʱ����ʾ��׼�����С��߳ߴ磻
	CFG_SIZE            stuMaxAreaSize;                           // ���������ο�ߴ�, ͬ��
	
	bool                abByRatio;
	bool                abMinRatio;
	bool                abMaxRatio;
	bool                abMinRatioSize;
	bool                abMaxRatioSize;
	bool                bByRatio;                                 // �Ƿ񰴿�߱ȹ��� ͨ������ComplexSizeFilter�ж��Ƿ����
	bool                bReserved2[2];
	double              dMinRatio;                                // ��С��߱�
	double              dMaxRatio;                                // ����߱�
	CFG_SIZE            stuMinRatioSize;                          // ��С��߱Ⱦ��ο�ߴ磬��С��߱ȶ�Ӧ���ο�Ŀ�߳ߴ硣
	CFG_SIZE            stuMaxRatioSize;                          // ����߱Ⱦ��ο�ߴ磬ͬ��
	
	int                 nAreaCalibrateBoxNum;                     // ���У׼�����
	CFG_CALIBRATEBOX_INFO stuAreaCalibrateBoxs[MAX_CALIBRATEBOX_NUM];// ���У׼��
	int                 nRatioCalibrateBoxs;                      // ���У׼�����
	CFG_CALIBRATEBOX_INFO stuRatioCalibrateBoxs[MAX_CALIBRATEBOX_NUM];// ���У׼��
	
	bool                abBySize;                                 // �������ʹ�ܲ����Ƿ���Ч
	bool                bBySize;                                  // �������ʹ��
}CFG_SIZEFILTER_INFO;

// ���������ض��Ĺ�����
typedef struct tagCFG_OBJECT_SIZEFILTER_INFO
{
	char				szObjectType[MAX_NAME_LEN];              // ��������
	CFG_SIZEFILTER_INFO stSizeFilter;                            // ��Ӧ�ĳߴ������
}CFG_OBJECT_SIZEFILTER_INFO;

// ������������ָ�Ӽ���������ֳ����������������Ե�����
typedef struct tagCFG_SPECIALDETECTREGION_INFO
{
	int                nDetectNum;                              // ������򶥵���
	CFG_POLYGON        stDetectRegion[MAX_POLYGON_NUM];         // �������
	int                nPropertyNum;                            // �����������Ը���
	int                nPropertys[EM_SEPCIALREGION_PROPERTY_TYPE_NUM];      // ������������
}CFG_SPECIALDETECT_INFO;

// ��ͬ���������������ļ��ģ������
typedef struct tagCFG_MODULE_INFO
{
	// ��Ϣ
	char				szObjectType[MAX_NAME_LEN];				// Ĭ����������,���"֧�ֵļ�����������б�"
	bool				bSnapShot;								// �Ƿ��ʶ������ץͼ
	BYTE                bSensitivity;                           // ������,ȡֵ1-10��ֵԽС������Խ��
	bool                bMeasureModeEnable;                     // ������ʽ�����Ƿ���Ч
	BYTE                bMeasureMode;                           // ������ʽ,0-���أ�����ҪԶ�ˡ����˱궨, 1-ʵ�ʳ��ȣ���λ����, 2-Զ�˽��˱궨�������
	int					nDetectRegionPoint;						// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];		// �������
	int					nTrackRegionPoint;						// �������򶥵���
	CFG_POLYGON			stuTrackRegion[MAX_POLYGON_NUM];		// ��������
	bool                bFilterTypeEnable;                      // �������Ͳ����Ƿ���Ч
	// ByArea,ByRatio�������ݣ�ʹ�ö�����ByArea��ByRatioѡ����� 2012/03/06
	BYTE				nFilterType;							// ��������:0:"ByLength",1:"ByArea", 2:"ByWidthHeight", 3:"ByRatio": ���տ�߱ȣ���ȳ��Ը߶ȵĽ��С��ĳ��ֵ���ߴ���ĳ��ֵ�����⽫�����˵���
	bool                bBackgroudEnable;                       // ����ı������Ͳ����Ƿ���Ч
	BYTE                bBackgroud;                             // ����ı�������, 0-��ͨ����, 1-�߹�����
	bool                abBySize;                               // �������ʹ�ܲ����Ƿ���Ч
	bool                bBySize;                                // �������ʹ��
	bool                bFilterMinSizeEnable;                   // ������С�ߴ�����Ƿ���Ч
	bool                bFilterMaxSizeEnable;                   // �������ߴ�����Ƿ���Ч
	CFG_SIZE			stuFilterMinSize;						// ������С�ߴ� "ByLength"ģʽ�±�ʾ��ߵĳߴ磬"ByArea"ģʽ�¿��ʾ���������Ч��
	CFG_SIZE			stuFilterMaxSize;						// �������ߴ� "ByLength"ģʽ�±�ʾ��ߵĳߴ磬"ByArea"ģʽ�¿��ʾ���������Ч��
	int                 nExcludeRegionNum;                      // �ų�������
	CFG_REGION          stuExcludeRegion[MAX_EXCLUDEREGION_NUM];// �ų�����
	int                 nCalibrateBoxNum;                       // У׼�����
	CFG_CALIBRATEBOX_INFO stuCalibrateBoxs[MAX_CALIBRATEBOX_NUM];// У׼��(Զ�˽��˱궨ģʽ����Ч)
	bool                bAccuracy;                               // ��⾫���Ƿ���Ч
	BYTE                byAccuracy;                              // ��⾫��
	bool                bMovingStep;                             // �㷨�ƶ������Ƿ���Ч                        
	BYTE                byMovingStep;                            // �㷨�ƶ�����
	bool                bScalingFactor;							 // �㷨���������Ƿ���Ч
	BYTE                byScalingFactor;						 // �㷨��������

	BYTE                bReserved2[1];                           // �����ֶ�
	bool                abDetectBalance;						 // ©������ƽ������Ƿ���Ч
	int					nDetectBalance;							 // ©������ƽ��	0-����ģʽ(Ĭ��)1-©�����2-������
	
	bool                abByRatio;
	bool                abMinRatio;
	bool                abMaxRatio;
	bool                abMinAreaSize;
	bool                abMaxAreaSize;
	bool                bByRatio;                                // �Ƿ񰴿�߱ȹ��� ͨ������ComplexSizeFilter�ж��Ƿ���� ���Ժ�nFilterType����
	bool                bReserved1[2];
	double              dMinRatio;                               // ��С��߱�
	double              dMaxRatio;                               // ����߱�
	CFG_SIZE            stuMinAreaSize;                           // ��С������ο�ߴ� "������ʽ"Ϊ"����"ʱ����ʾ��С������ο�Ŀ�߳ߴ磻"������ʽ"Ϊ"Զ�˽��˱궨ģʽ"ʱ����ʾ��׼�����С��߳ߴ磻
	CFG_SIZE            stuMaxAreaSize;                           // ���������ο�ߴ�, ͬ��
	
	bool                abByArea;
	bool                abMinArea;
	bool                abMaxArea;
	bool                abMinRatioSize;
	bool                abMaxRatioSize;
	bool                bByArea;                                 // �Ƿ�������� ͨ������ComplexSizeFilter�ж��Ƿ����  ���Ժ�nFilterType����
	bool                bReserved3[2];
	float               nMinArea;                                // ��С���
	float               nMaxArea;                                // ������
	CFG_SIZE            stuMinRatioSize;                          // ��С��߱Ⱦ��ο�ߴ磬��С��߱ȶ�Ӧ���ο�Ŀ�߳ߴ硣
	CFG_SIZE            stuMaxRatioSize;                          // ����߱Ⱦ��ο�ߴ磬ͬ��
	
	int                 nAreaCalibrateBoxNum;                    // ���У׼�����
	CFG_CALIBRATEBOX_INFO stuAreaCalibrateBoxs[MAX_CALIBRATEBOX_NUM];// ���У׼��
	int                 nRatioCalibrateBoxs;                      // ����У׼�����
	CFG_CALIBRATEBOX_INFO stuRatioCalibrateBoxs[MAX_CALIBRATEBOX_NUM];// ����У׼�����

	bool                bAntiDisturbance;                        // �Ƿ���ȥ�Ŷ�ģ��
	bool                bBacklight;                              // �Ƿ������
	bool                bShadow;                                 // �Ƿ�����Ӱ
	bool                bContourAssistantTrack;                  // �Ƿ��������������٣�����������ʶ��ʱ����ͨ����������������ʶ������
	int                 nPtzPresetId;                            // ��̨Ԥ�õ㣬0~255��0��ʾ�̶�����������Ԥ�õ㡣����0��ʾ�ڴ�Ԥ�õ�ʱģ����Ч

	int                 nObjectFilterNum;                        // �����ض��Ĺ���������
	CFG_OBJECT_SIZEFILTER_INFO stObjectFilter[MAX_OBJECT_LIST_SIZE]; // �����ض��Ĺ�������Ϣ

	BOOL                abObjectImageSize;                        
	CFG_SIZE            stObjectImageSize;                       // ��֤����ͼ��ߴ���ͬ,��λ������,��֧��С����ȡֵ��>=0,  0 ��ʾ�Զ�������С

	int                 nSpecailDetectNum;                                // �������������
	CFG_SPECIALDETECT_INFO stSpecialDetectRegions[MAX_SPECIALDETECT_NUM];  // ����������Ϣ

	unsigned int        nAttribute;                              // ��Ҫʶ����������Ը���
	char                szAttributes[MAX_OBJECT_ATTRIBUTES_SIZE][MAX_NAME_LEN];   // ��Ҫʶ������������б���Category�� �������ࣻ��Size�� �����С����Color�� ������ɫ����Speed�� �����ٶȣ���Sign�� �����־���Գ������ԣ�ָ���ꣻ��Action�� ���嶯��
	
	BOOL                abPlateAnalyseMode;                      // nPlateAnalyseMode�Ƿ���Ч
	int                 nPlateAnalyseMode;                       // ����ʶ��ģʽ��0-ֻʶ��ͷ���� 1-ֻʶ��β���� 2-��ͷ�������ȣ������д󲿷ֳ����ǳ�ͷ���գ�3-��β�������ȣ������д󲿷ֳ����ǳ�β���գ�
} CFG_MODULE_INFO;

typedef struct tagCFG_ANALYSEMODULES_INFO
{
	int					nMoudlesNum;							// ���ģ����
	CFG_MODULE_INFO     stuModuleInfo[MAX_ANALYSE_MODULE_NUM];			// ÿ����Ƶ����ͨ����Ӧ�ĸ�����������ļ��ģ������

} CFG_ANALYSEMODULES_INFO;

// ��Ƶ�����¼�����������ؽṹ�嶨��
enum CFG_EM_DETECTMODE_T{
	CFG_EM_DETECTMODE_NONE,            // �޴��ֶ�
	CFG_EM_DETECTMODE_BY_VIDEO,        // ��Ƶ���ģʽ
	CFG_EM_DETECTMODE_BY_BYAUDIO,      // ��Ƶ���ģʽ
	CFG_EM_DETECTMODE_BY_BOTH,         // ����Ƶ���ϼ��ģʽ
	CFG_EM_DETECTMODE_ERR=255          // �ֶ����ݴ���
};

// ��Ƶ�����¼���������
// �¼�����EVENT_IVS_CROSSLINEDETECTION(�������¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_CROSSLINE_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ� 
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nDirection;												// ��ⷽ��:0:��������;1:��������;2:���߶�����
	int					nDetectLinePoint;										// �����߶�����
	CFG_POLYLINE		stuDetectLine[MAX_POLYLINE_NUM];						// ������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
 	BOOL                bDisableTimeSection;                                    // stuTimeSection�ֶ��Ƿ���ã�Ĭ��FALSE�������ã�TRUE�����ã��û�����

	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������
	int                 nTriggerPosition;                                       // ��������λ����
	BYTE                bTriggerPosition[8];                                    // ��������λ��,0-Ŀ����ӿ�����, 1-Ŀ����ӿ��������, 2-Ŀ����ӿ򶥶�����, 3-Ŀ����ӿ��Ҷ�����, 4-Ŀ����ӿ�׶�����

} CFG_CROSSLINE_INFO;

//�¼�����EVENT_IVS_CROSSFENCEDETECTION(��ԽΧ������)��Ӧ�Ĺ�������
typedef struct tagCFG_CROSSFENCEDETECTION_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ� 
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nDirection;												// ��ԽΧ������:0:��������;1:��������;2:���߶�����
	int					nUpstairsLinePointNumber;								// Χ�����߶�����
	CFG_POLYLINE		stuUpstairsLine[MAX_POLYLINE_NUM];						// Χ������
	int					nDownstairsLinePointNumber;								// Χ�����߶�����
	CFG_POLYLINE		stuDownstairsLine[MAX_POLYLINE_NUM];					// Χ������
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������
	int                 nTriggerPosition;                                       // ��������λ����
	BYTE                bTriggerPosition[8];                                    // ��������λ��,0-Ŀ����ӿ�����, 1-Ŀ����ӿ��������, 2-Ŀ����ӿ򶥶�����, 3-Ŀ����ӿ��Ҷ�����, 4-Ŀ����ӿ�׶�����
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
} CFG_CROSSFENCEDETECTION_INFO;

// �¼�����EVENT_IVS_CROSSREGIONDETECTION(�������¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_CROSSREGION_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nDirection;												// ��ⷽ��:0:Enter;1:Leave;2:Both
	int					nDetectRegionPoint;										// ������������
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// ������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������

	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
 	BOOL                bDisableTimeSection;                                    // stuTimeSection�ֶ��Ƿ���ã�Ĭ��FALSE�������ã�TRUE�����ã��û�����

	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������
	int                 nActionType;                                            // ��⶯����
	BYTE                bActionType[4];                                         // ��⶯���б�,0-���� 1-��ʧ 2-�������� 3-��Խ����
	int                 nMinTargets;                                            // ��СĿ�����(��bActionType�а���"2-��������"ʱ��Ч)
	int                 nMaxTargets;                                            // ���Ŀ�����(��bActionType�а���"2-��������"ʱ��Ч)
	int                 nMinDuration;                                           // ��̳���ʱ�䣬 ��λ��(��bActionType�а���"2-��������"ʱ��Ч)
	int                 nReportInterval;                                        // ����ʱ������ ��λ��(��bActionType�а���"2-��������"ʱ��Ч)
		
} CFG_CROSSREGION_INFO;

// �¼�����EVENT_IVS_PASTEDETECTION(ATM�����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_PASTE_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
		
} CFG_PASTE_INFO;

// �¼�����EVENT_IVS_LEFTDETECTION(��Ʒ�����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_LEFT_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int                 nTriggerPosition;                                       // ��������λ����
	BYTE                bTriggerPosition[8];                                    // ��������λ��,0-Ŀ����ӿ�����, 1-Ŀ����ӿ��������, 2-Ŀ����ӿ򶥶�����, 3-Ŀ����ӿ��Ҷ�����, 4-Ŀ����ӿ�׶�����
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������

} CFG_LEFT_INFO;

// �¼�����EVENT_IVS_TAKENAWAYDETECTION(��Ʒ���ƹ�������)��Ӧ�Ĺ�������
typedef struct tagCFG_TAKENAWAYDETECTION_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int                 nTriggerPosition;                                       // ��������λ����
	BYTE                bTriggerPosition[8];                                    // ��������λ��,0-Ŀ����ӿ�����, 1-Ŀ����ӿ��������, 2-Ŀ����ӿ򶥶�����, 3-Ŀ����ӿ��Ҷ�����, 4-Ŀ����ӿ�׶�����
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������

} CFG_TAKENAWAYDETECTION_INFO;

// �¼�����EVENT_IVS_PARKINGDETECTION (�Ƿ�ͣ��)��Ӧ�Ĺ�������
typedef struct tagCFG_PARKINGDETECTION_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int                 nTriggerPosition;                                       // ��������λ����
	BYTE                bTriggerPosition[8];                                    // ��������λ��,0-Ŀ����ӿ�����, 1-Ŀ����ӿ��������, 2-Ŀ����ӿ򶥶�����, 3-Ŀ����ӿ��Ҷ�����, 4-Ŀ����ӿ�׶�����
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������

} CFG_PARKINGDETECTION_INFO;

// �¼�����EVENT_IVS_PRESERVATION(��Ʒ��ȫ�¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_PRESERVATION_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535

} CFG_PRESERVATION_INFO;

// �¼�����EVENT_IVS_STAYDETECTION(ͣ���¼�/����)��Ӧ�Ĺ�������
typedef struct tagCFG_STAY_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int                 nTriggerPosition;                                       // ��������λ����
	BYTE                bTriggerPosition[8];                                    // ��������λ��,0-Ŀ����ӿ�����, 1-Ŀ����ӿ��������, 2-Ŀ����ӿ򶥶�����, 3-Ŀ����ӿ��Ҷ�����, 4-Ŀ����ӿ�׶�����
	int                 nTriggerTargetsNumber;                                  // �����������ǻ�����������
	int                 nReportInterval;                                        // ����ʱ����,��λ��
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������
	
} CFG_STAY_INFO;

// �¼�����EVENT_IVS_WANDERDETECTION(�ǻ��¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_WANDER_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int                 nTriggerPosition;                                       // ��������λ����
	BYTE                bTriggerPosition[8];                                    // ��������λ��,0-Ŀ����ӿ�����, 1-Ŀ����ӿ��������, 2-Ŀ����ӿ򶥶�����, 3-Ŀ����ӿ��Ҷ�����, 4-Ŀ����ӿ�׶�����
	int                 nTriggerTargetsNumber;                                  // �����������ǻ�����������
	int                 nReportInterval;                                        // ����ʱ����,��λ��
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������

} CFG_WANDER_INFO;

// �¼�����EVENT_IVS_MOVEDETECTION(�ƶ��¼�/�˶����)��Ӧ�Ĺ�������
typedef struct tagCFG_MOVE_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bSensitivity;                                           // �����ȣ�ȡֵ1-10��ֵԽС������Խ��
	BYTE                bReserved[2];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int                 nTriggerSpeed;                                          // �����ٶȣ�km/h
	int                 nTriggerPosition;                                       // ��������λ����
	BYTE                bTriggerPosition[8];                                    // ��������λ��,0-Ŀ����ӿ�����, 1-Ŀ����ӿ��������, 2-Ŀ����ӿ򶥶�����, 3-Ŀ����ӿ��Ҷ�����, 4-Ŀ����ӿ�׶�����
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������	
	int                 nTypeNumber;                                            // ���������
	BYTE                bDetectType[4];                                         // ��⶯���б�,0-�����˶� 1-ͻȻ���� 2-ͻȻ����

} CFG_MOVE_INFO;

// �¼�����EVENT_IVS_TAILDETECTION(β���¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TAIL_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535

} CFG_TAIL_INFO;

// �¼�����EVENT_IVS_RIOTERDETECTION(�����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_RIOTER_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bAreaPercent;                                           // �ۼ���ռ��������ٷֱ�
	BYTE                bSensitivity;                                           // �����ȣ�ȡֵ1-10��ֵԽС������Խ�ͣ���Ӧ��Ⱥ���ܼ��̶�Խ��(ȡ��bAreaPercent)
	BYTE                bReserved;												// �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535

	int                 nReportInterval;                                        // ����ʱ����,��λ�� [1,600] Ĭ��0��ʾ���ظ�����
	CFG_POLYGON         stuMinDetectRect[2];                                    // ��С�ۼ�������ο򣬷ֱ��Ӧ���ο�����Ϻ����µ㣬���ο��ʵ�������ʾ������������С��Ⱥ�ۼ����
} CFG_RIOTER_INFO;

// �¼�����EVENT_IVS_DENSITYDETECTION(��Ⱥ�ܶȼ���¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_DENSITYDETECTION_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved1;                                             // �����ֶ�
	BYTE                bSensitivity;                                           // ������(ȡֵ1-10��ֵԽС������Խ�ͣ���Ӧ��Ⱥ���ܼ��̶�Խ��)
	BYTE                bReserved2;                                             // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	
} CFG_DENSITYDETECTION_INFO;


// �¼�����EVENT_IVS_FIGHTDETECTION(��Ź�¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_FIGHT_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nSensitivity;											// ������, 1-10
    CFG_EM_DETECTMODE_T emDetectMode;                                           // ���ģʽ

} CFG_FIGHT_INFO;

// �¼�����EVENT_IVS_FIREDETECTION(���¼�/������)��Ӧ�Ĺ�������
typedef struct tagCFG_FIRE_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535

} CFG_FIRE_INFO;

// �¼�����EVENT_IVS_ELECTROSPARKDETECTION(����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_ELECTROSPARK_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	
} CFG_ELECTROSPARK_INFO;

// �¼�����EVENT_IVS_SMOKEDETECTION(�������¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_SMOKE_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535

} CFG_SMOKE_INFO;

// �¼�����EVENT_IVS_FLOWSTAT(����ͳ���¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_FLOWSTAT_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nUpperLimit;											// ��������	��λ����/�룬1~65535
	int					nPeriod;												// �ϱ�����	��λ���룬1~65535
	int					nDetectLinePoint;										// ����߶�����
	CFG_POLYLINE		stuDetectLine[MAX_POLYLINE_NUM];						// �����
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
		
} CFG_FLOWSTAT_INFO;

enum NET_NUMBERSTAT_TYPE
{
	NET_EM_NUMSTAT_TYPE_REGION,                  // "Region" ��������
		NET_EM_NUMSTAT_TYPE_ENTRANCE,            // "Entrance" ���������
		NET_EM_NUMSTAT_TYPE_OTHER,               // other
};
// �¼�����EVENT_IVS_NUMBERSTAT(����ͳ���¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_NUMBERSTAT_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nUpperLimit;											// �������� ��λ������1~65535
	int					nPeriod;												// �ϱ�����	��λ���룬1~65535
	int					nDetectRegionPoint;										// �����������
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �����
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	NET_NUMBERSTAT_TYPE emType;                                                 // ����ͳ������	֧�֣�"Region" �������� "Entrance" ���������
	CFG_POLYGON         stDirection[2];                                         // �����˶�����, ���մ˷�����ʻ�����򣬷�����������	ֻ�Գ����������Ч����һ��������㣬�ڶ��������յ㣬��������һ����[0,8191]���䡣
    int                 nRecordInterval;                                        // ��¼���ڣ���λ�����ӣ�1~10
} CFG_NUMBERSTAT_INFO;

//�¼�����EVENT_IVS_RETROGRADEDETECTION(��Ա�����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_RETROGRADEDETECTION_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bSensitivity;                                           // ������, ȡֵ1-10��ֵԽС������Խ��
	BYTE                bReserved[2];                                           // �����ֶ� 
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	int                 nDirectionPoint;                                        // ������ʻ���򶥵���
	CFG_POLYGON			stuDirection[MAX_POLYLINE_NUM];					      	// ������ʻ����, ���մ˷�����ʻ�����򣬷�����������(��һ��������㣬�ڶ��������յ㣬��������һ����[0,8191]����)
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������
	int                 nTriggerPosition;                                       // ��������λ����
	BYTE                bTriggerPosition[8];                                    // ��������λ��,0-Ŀ����ӿ�����, 1-Ŀ����ӿ��������, 2-Ŀ����ӿ򶥶�����, 3-Ŀ����ӿ��Ҷ�����, 4-Ŀ����ӿ�׶�����
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
} CFG_RETROGRADEDETECTION_INFO;

//�¼�����EVENT_IVS_ABNORMALRUNDETECTION(�쳣�����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_ABNORMALRUNDETECTION_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bSensitivity;                                           // ������, ȡֵ1-10��ֵԽС������Խ��
	BYTE                bReserved[2];                                           // �����ֶ� 
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������
	int                 nTriggerPosition;                                       // ��������λ����
	BYTE                bTriggerPosition[8];                                    // ��������λ��,0-Ŀ����ӿ�����, 1-Ŀ����ӿ��������, 2-Ŀ����ӿ򶥶�����, 3-Ŀ����ӿ��Ҷ�����, 4-Ŀ����ӿ�׶�����
	int                 nDetectType;                                            // ���������
	BYTE                bDetectType[4];                                         // �������,0-���ٱ���, 1-ͻȻ����, 2-ͻȻ����
	int                 nTriggerSpeed;                                          // �����ٶȣ����ڸ��ٶȱ���	��λ��km/h
	int                 nMinDuration;                                           // ��̳���ʱ��	��λ���룬0~65535
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
} CFG_ABNORMALRUNDETECTION_INFO;

//�¼�����EVENT_IVS_VIDEOABNORMALDETECTION(��Ƶ�쳣)��Ӧ�Ĺ�������
typedef struct tagCFG_VIDEOABNORMALDETECTION_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bSensitivity;                                           // ������, ȡֵ1-10��ֵԽС������Խ��(ֻ�Լ��������Ƶ�ڵ��������������������仯��Ч)
	BYTE                bReserved[2];                                           // �����ֶ� 
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int                 nDetectType;                                            // ���������
	BYTE                bDetectType[8];                                         // �������,0-��Ƶ��ʧ, 1-��Ƶ�ڵ�, 2-���涳��, 3-����, 4-����, 5-�����仯
	int					nMinDuration;											// ��̳���ʱ��	��λ���룬0~65535
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int					nDetectRegionPoint;										// �����������
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �����
	
} CFG_VIDEOABNORMALDETECTION_INFO;

// �¼�����EVENT_IVS_FACERECOGNITION(����ʶ��)��Ӧ�Ĺ�������
typedef struct tagCFG_FACERECOGNITION_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[2];                                           // �����ֶ� 
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	BYTE                 bySimilarity;                                          // ���ƶȣ�������ڸ���ʶ�Ȳű���(1~100)
	BYTE                 byAccuracy;                                            // ʶ�𾫶�(ȡֵ1~10������ֵ���󣬼�⾫����ߣ�����ٶ��½�����СֵΪ1 ��ʾ����ٶ����ȣ����ֵΪ10��ʾ��⾫������)
	BYTE                 byMode;                                                // �Ա�ģʽ, 0-����, 1-ָ�������������, 2-����ģʽ(�㷨��������������������Զ�ѡȡ���)
	BYTE                 byImportantRank;                                       // ��ѯ��Ҫ�ȼ����ڵ��ڴ˵ȼ�����Ա(1~10,��ֵԽ��Խ��Ҫ)
	int                  nAreaNum;                                              // ������  
	BYTE                 byAreas[8];                                            // �����������, 0-üë��1-�۾���2-���ӣ�3-��ͣ�4-����(�˲����ڶԱ�ģʽΪ1ʱ��Ч)
	int                  nMaxCandidate;                                         // ��������ƥ��ͼƬ����
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
} CFG_FACERECOGNITION_INFO;


// �¼�����EVENT_IVS_TRAFFICCONTROL(��ͨ�����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFICCONTROL_INFO 
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];									// ��������,��ͬ����������
	bool				bRuleEnable;												// ����ʹ��
	BYTE                bReserved[3];                                               // �����ֶ�
	int					nObjectTypeNum;												// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];			// ��Ӧ���������б�
	int					nDetectLinePoint;							            	// ����߶�����
	CFG_POLYLINE		stuDetectLine[MAX_POLYLINE_NUM];			            	// �����
	CFG_TIME_SECTION	stuTimeSchedule[WEEK_DAY_NUM][MAX_REC_TSECT];           	// ����ʱ���
	int					nVehicleSizeNum;							            	// ������С���͸���
	char				szVehicleSizeList[MAX_VEHICLE_SIZE_LIST][MAX_NAME_LEN];		// ������С�����б�"Light-duty":С�ͳ�;	"Medium":���ͳ�; "Oversize":���ͳ�
	int					nPlateTypeNum;												// �������͸���
	char				szPlateTypesList[MAX_PLATE_TYPE_LIST][MAX_NAME_LEN];		// ���������б�"Unknown" δ֪; "Normal" ���ƺ���; "Yellow" ����; "DoubleYellow" ˫���β��
																					// "Police" ����; "Armed" �侯��; "Military" ���Ӻ���; "DoubleMilitary" ����˫��
																					// "SAR" �۰���������; "Trainning" ����������; "Personal" ���Ժ���; "Agri" ũ����
																					// "Embassy" ʹ�ݺ���; "Moto" Ħ�г�����; "Tractor" ����������; "Other" ��������
	int					nPlateNumber;												// ���Ƶ�˫�� 0:����; 1:˫��; 2:��˫��;	
	CFG_ALARM_MSG_HANDLE stuEventHandler;											// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];				// �¼���Ӧʱ���
	int                 nPtzPresetId;												// ��̨Ԥ�õ���	0~65535
} CFG_TRAFFICCONTROL_INFO;

// �¼�����EVENT_IVS_TRAFFICACCIDENT(��ͨ�¹��¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAACCIDENT_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nDetectRegionPoint;										// �����������
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �����
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	
} CFG_TRAACCIDENT_INFO;

// �¼�����EVENT_IVS_TRAFFICJUNCTION(��ͨ·���Ϲ����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAJUNCTION_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];				// ��������,��ͬ����������
	bool				bRuleEnable;							// ����ʹ��
	int					nObjectTypeNum;							// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nLane;									// �������
	int                 nDirection;                             // ��������(�������ķ���),0-�� 1-���� 2-�� 3-���� 4-�� 5-���� 6-�� 7-����
	int					nPreLinePoint;							// ǰ�ü���߶�����
	CFG_POLYLINE		stuPreLine[MAX_POLYLINE_NUM];			// ǰ�ü����
	int					nMiddleLinePoint;						// �м����߶�����
	CFG_POLYLINE		stuMiddleLine[MAX_POLYLINE_NUM];		// �м�����
	int					nPostLinePoint;							// ���ü���߶�����
	CFG_POLYLINE		stuPostLine[MAX_POLYLINE_NUM];			// ���ü����
	int                 nFlowLimit;                             // �������ޣ���λ��/��
	int                 nSpeedDownLimit;                        // �ٶ����ޣ���Ϊ0�����ʾ�������ޣ�km/h
	int                 nSpeedUpLimit;                          // �ٶ����ޣ���Ϊ0�����ʾ�������ޣ�km/h
	int                 nTriggerModeNum;                        // ����ģʽ����
	char                szTriggerMode[MAX_TRIGGERMODE_NUM][MAX_NAME_LEN];  // ����ģʽ��"Passing" : ����·��(���м�����Ϊ׼��ֻ�ܵ���ʹ��),"RunRedLight" : �����
																// "Overline":ѹ�׳�����,"OverYellowLine": ѹ����, "Retrograde":����
																// "TurnLeft":Υ����ת, "TurnRight":Υ����ת, "CrossLane":Υ�±��
																// "U-Turn" Υ�µ�ͷ, "Parking":Υ��ͣ��, "WaitingArea" Υ�½��������
																// "OverSpeed": ����,"UnderSpeed":Ƿ��,"Overflow" : ��������
																// "Human":����,"NoMotor":�ǻ�����

	CFG_ALARM_MSG_HANDLE stuEventHandler;							// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	BOOL                bMaskRetrograde;         	             // �Ƿ��������У��������е�����������
			
} CFG_TRAJUNCTION_INFO;

// �¼�����EVENT_IVS_TRAFFICGATE(��ͨ�����Ϲ����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFICGATE_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nLane;													// �������
	int					nDetectLinePoint1;										// �����(������Ȧ)1������
	CFG_POLYLINE		stuDetectLine1[MAX_POLYLINE_NUM];						// �����1
	int					nDetectLinePoint2;										// �����(������Ȧ)2������
	CFG_POLYLINE		stuDetectLine2[MAX_POLYLINE_NUM];						// �����2
	int					nLeftLinePoint;											// �󳵵��߶�����
	CFG_POLYLINE		stuLeftLine[MAX_POLYLINE_NUM];							// �󳵵���
	int					nRightLinePoint;										// �ҳ����߶�����
	CFG_POLYLINE		stuRightLine[MAX_POLYLINE_NUM];							// �ҳ�����
	int					nSpeedWeight;											// �ٶ�Ȩ��ϵ��(���ճ���=��������*Ȩ��ϵ��)
	double				MetricDistance;											// ���������ʵ�ʾ���,��λ����
	int					nSpeedUpperLimit;										// �ٶ����� 0��ʾ�������� ��λ��km/h
	int					nSpeedLowerLimit;										// �ٶ����� 0��ʾ�������� ��λ��km/h
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nDirection;                                             // ��������(�������ķ���)��0-�� 1-���� 2-�� 3-���� 4-�� 5-���� 6-�� 7-����
	int                 nTriggerModeNum;                                        // ����ģʽ����
	char                szTriggerMode[MAX_TRIGGERMODE_NUM][MAX_NAME_LEN];       // ����ģʽ��"OverLine":ѹ��,"Retrograde":����,"OverSpeed":����,"UnderSpeed":Ƿ��
	                                                                            // "Passing":����·�ڣ�������ץ��, "WrongRunningRoute":�г�ռ��(����ʹ��),"YellowVehicleInRoute": ����ռ��
	                                                                            // "OverYellowLine":ѹ����
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	BOOL                bMaskRetrograde;         	             // �Ƿ��������У��������е�����������
} CFG_TRAFFICGATE_INFO;

// �¼�����EVENT_IVS_TRAFFIC_TOLLGATE(��ͨ�����¹����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFICTOLLGATE_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535

	int					nLane;													// �������
	int					nDetectLinePoint;										// ���ڱ����߶�����
	CFG_POLYLINE		stuDetectLine[MAX_POLYLINE_NUM];						// ���ڱ�����

	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
} CFG_TRAFFICTOLLGATE_INFO;

// �¼�����EVENT_IVS_FACEDETECT(��������¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_FACEDETECT_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int					nDetectRegionPoint;										// �����������
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �����
	int                 nHumanFaceTypeCount;                                    // �����¼����������͸���
	char                szHumanFaceType[MAX_HUMANFACE_LIST_SIZE][MAX_NAME_LEN]; // �����¼�����������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int                 nMinDuration;                                           // ��̴���ʱ��,��λ���� 
}CFG_FACEDETECT_INFO;

//�¼�����EVENT_IVS_TRAFFIC_NOPASSING(��ͨΥ��-��ֹͨ���¼�)��Ӧ�����ݿ�������Ϣ
typedef struct tagCFG_NOPASSING_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
}CFG_NOPASSING_INFO;

// �¼�����EVENT_IVS_TRAFFICJAM (��ͨӵ���¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFICJAM_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
    BYTE                bJamLineMargin;                                         // ռ����ֵ��ӵ�³���ռ����������ֵ��0-100
	BYTE                bReserved[2];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	int                 nDelayTime;                                             // ��⵽������������ʼ�ϱ���ʱ��, ��λ���룬��Χ1~65535
	int                 nIntervalTime;                                          // �������ʱ��, ��λ���룬��Χ1~65535
	int                 nReportTimes;                                           // �ϱ�����, 1~255
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int		            nDetectRegionPoint;                                     // �����������
	CFG_POLYGON         stuDetectRegion[MAX_POLYGON_NUM];                       // �������
}CFG_TRAFFICJAM_INFO;

// �¼�����EVENT_IVS_TRAFFIC_IDLE (��ͨ�����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_IDLE_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
    BYTE                bJamLineMargin;                                         // ռ����ֵ��ӵ�³���ռ����������ֵ��0-100
	BYTE                bReserved[2];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	int                 nDelayTime;                                             // ��⵽������������ʼ�ϱ���ʱ��, ��λ���룬��Χ1~65535
	int                 nIntervalTime;                                          // �������ʱ��, ��λ���룬��Χ1~65535
	int                 nReportTimes;                                           // �ϱ�����, 1~255
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	int		            nDetectRegionPoint;                                     // �����������
	CFG_POLYGON         stuDetectRegion[MAX_POLYGON_NUM];                       // �������
}CFG_TRAFFIC_IDLE_INFO;


// �¼�����EVENT_IVS_TRAFFIC_PARKING (��ͨΥ��ͣ���¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_PARKING_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	int                 nDelayTime;                                             // ��⵽������������ʼ�ϱ���ʱ��, ��λ���룬��Χ1~65535
	int                 nParkingAllowedTime;                                    // ����ͣ��ʱ��, ��λ���룬��Χ1~65535
	int                 nReportTimes;                                           // �ϱ�����, 1~255
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
		
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	
	
}CFG_TRAFFIC_PARKING_INFO;

// �¼����� EVENT_IVS_TRAFFIC_RUNREDLIGHT (��ͨΥ��-������¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_RUNREDLIGHT_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	int                 nDirection;                                             // ��������(�������ķ���)��0-�� 1-���� 2-�� 3-���� 4-�� 5-���� 6-�� 7-����
	int					nPreLinePoint;							                // ǰ�ü���߶�����
	CFG_POLYLINE		stuPreLine[MAX_POLYLINE_NUM];			                // ǰ�ü����
	int					nMiddleLinePoint;						                // �м����߶�����
	CFG_POLYLINE		stuMiddleLine[MAX_POLYLINE_NUM];		                // �м�����
	int					nPostLinePoint;							                // ���ü���߶�����
	CFG_POLYLINE		stuPostLine[MAX_POLYLINE_NUM];			                // ���ü����
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
}CFG_TRAFFIC_RUNREDLIGHT_INFO;

// �¼����� EVENT_IVS_TRAFFIC_WRONGROUTE (��ͨΥ��-����������ʻ�¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_WRONGROUTE_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
}CFG_TRAFFIC_WRONGROUTE_INFO;

// �¼����� EVENT_IVS_TRAFFIC_CROSSLANE (��ͨΥ��-Υ�±��)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_CROSSLANE_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
}CFG_TRAFFIC_CROSSLANE_INFO;

// �¼����� EVENT_IVS_TRAFFIC_OVERLINE (��ͨΥ��-ѹ������)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_OVERLINE_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
}CFG_TRAFFIC_OVERLINE_INFO;

// �¼����� EVENT_IVS_TRAFFIC_OVERYELLOWLINE (��ͨΥ��-ѹ����)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_OVERYELLOWLINE_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���

	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������

}CFG_TRAFFIC_OVERYELLOWLINE_INFO;

// �¼����� EVENT_IVS_TRAFFIC_RETROGRADE (��ͨΥ��-�����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_RETROGRADE_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	BOOL                bLegal;                                                 // TRUE: ���кϷ�;FALSE:���в��Ϸ�
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���

	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	int                 nDirectionLinPoint;                                     // ������ʻ���򶥵���
	CFG_POLYLINE		stuDirectionLine[MAX_POLYLINE_NUM];						// ������ʻ���򣬵�һ��������㣬���һ�������յ�
	int					nMinDuration;											// ��̴���ʱ��	��λ����
}CFG_TRAFFIC_RETROGRADE_INFO;

// �¼����� EVENT_IVS_TRAFFIC_TURNLEFT (��ͨΥ��-Υ����ת�¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_TURNLEFT_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
}CFG_TRAFFIC_TURNLEFT_INFO;

// �¼����� EVENT_IVS_TRAFFIC_TURNRIGHT (��ͨΥ��-Υ����ת)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_TURNRIGHT_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
}CFG_TRAFFIC_TURNRIGHT_INFO;

// �¼����� EVENT_IVS_TRAFFIC_UTURN (��ͨΥ��-Υ�µ�ͷ)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_UTURN_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���


	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
	int					nTriggerAngle;											// ��ͷ�����Ƕ�,ȡֵ��Χ(90,180)��Ŀ���ͷǰ����˶��н�
	BOOL                abSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������
	
}CFG_TRAFFIC_UTURN_INFO;

// �¼����� EVENT_IVS_TRAFFIC_OVERSPEED (��ͨΥ��-����)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_OVERSPEED_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	int                 nSpeedUpperLimit;                                       // �ٶ�����
	int                 nSpeedLowerLimit;                                       // �ٶ�����
	int					nMinDuration;											// ��̴���ʱ��	��λ����
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
}CFG_TRAFFIC_OVERSPEED_INFO;

// �¼����� EVENT_IVS_TRAFFIC_UNDERSPEED (��ͨΥ��-Ƿ��)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_UNDERSPEED_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	int                 nSpeedUpperLimit;                                       // �ٶ�����
	int                 nSpeedLowerLimit;                                       // �ٶ�����
	int					nMinDuration;											// ��̴���ʱ��	��λ����
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
}CFG_TRAFFIC_UNDERSPEED_INFO;

// �¼����� EVENT_IVS_TRAFFIC_YELLOWPLATEINLANE (��ͨΥ��-���Ƴ�ռ���¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_YELLOWPLATEINLANE_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
}CFG_TRAFFIC_YELLOWPLATEINLANE_INFO;

// �¼����� EVENT_IVS_TRAFFIC_VEHICLEINROUTE (��ͨΥ��-�г�ռ���¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_VEHICLEINROUTE_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nLane;													// �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
}CFG_TRAFFIC_VEHICLEINROUTE_INFO;

// �¼����� EVENT_IVS_PRISONERRISEDETECTION (�������������¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_PRISONRISEDETECTION_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	int					nDetectRegionPoint;										// ������������
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM10];						// ������
	CFG_POLYGON			stDirection[2];											// ��˯������	��һ��������㣬�ڶ��������յ㣬��������һ����[0,8191]����
	CFG_POLYGON			stBedMiddleLine[2];										// ��������	��������һ����[0,8191]����
	int					nBedSide;												// ���̵ķ�λ	1�����λ,2�ұ���λ
	int					nMinDuration;											// ��̴���ʱ��	��λ����
	int					nReportInterval;										// �ظ��������	��λ����
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
}CFG_PRISONRISEDETECTION_INFO;

// �¼����� EVENT_IVS_TRAFFIC_PEDESTRAINPRIORITY (���������������¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_PEDESTRAINPRIORITY_INFO
{
	char                szRuleName[MAX_NAME_LEN];                               // ��������,��ͬ����������
	bool                bRuleEnable;                                            // ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int                 nObjectTypeNum;                                         // ��Ӧ�������͸���
	char                szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];      // ��Ӧ���������б�
	int                 nPtzPresetId;                                           // ��̨Ԥ�õ���	0~65535
	int                 nLane;                                                  // �������
	CFG_ALARM_MSG_HANDLE stuEventHandler;                                       // ��������
	CFG_TIME_SECTION    stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];            // �¼���Ӧʱ���
}CFG_TRAFFIC_PEDESTRAINPRIORITY_INFO;

// �¼����� EVENT_IVS_QUEUEDETECTION (�ŶӼ���¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_IVS_QUEUEDETECTION_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
	CFG_POLYLINE		stuDetectLine[2];						                // ������
	int                 nOccupyLineMargin;                                      // ռ����ֵ�����鳤��ռ�߱�����ֵ
	int                 nTriggerTime;                                           // ��λ�룬�ŶӼ�ⱨ��ʱ�䣬�Ŷӳ�����ֵ��״̬ά����"�ŶӼ�ⱨ��ʱ��"�Ժ󱨾�
}CFG_IVS_QUEUEDETECTION_INFO;

// �¼����� EVENT_IVS_CLIMBDETECTION (�ʸ߼���¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_IVS_CLIMBDETECTION_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���

	int                 nDetectLine;                                            // ����߶������
	CFG_POLYLINE        stuDetectLine[MAX_POLYLINE_NUM];                        // ��Ӧ�ļ������,[0,8192)
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������
}CFG_IVS_CLIMBDETECTION_INFO;

// �¼����� EVENT_IVS_LEAVEDETECTION (��ڼ���¼�)��Ӧ�Ĺ�������
enum CFG_EM_LEAVEDETECTION_MODE{
	CFG_EM_LEAVEDETECTION_MODE_NONE,
	CFG_EM_LEAVEDETECTION_MODE_PATROL,    // Ѳ��ģʽ
	CFG_EM_LEAVEDETECTION_MODE_SENTRY,    // ����ģʽ
	CFG_EM_LEAVEDETECTION_MODE_ERR=255
};
typedef struct tagCFG_IVS_LEAVEDETECTION_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���

	CFG_EM_LEAVEDETECTION_MODE emMode;                                          // ���ģʽ
	unsigned int        nMinDuration;                                           // ��̳���ʱ��,��λ����
	unsigned int        nReportInterval;                                        // ����ʱ����,��λ����
	BOOL                bSizeFileter;                                           // �����ض��ĳߴ�������Ƿ���Ч
	CFG_SIZEFILTER_INFO stuSizeFileter;                                         // �����ض��ĳߴ������

	int					nDetectRegionPoint;										// �����������
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �����
}CFG_IVS_LEAVEDETECTION_INFO;

//�¼�����	EVENT_IVS_TRAFFIC_PARKINGONYELLOWBOX(��������ץ���¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_PARKINGONYELLOWBOX_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���

	int					nLane;													// ������
	int					nInterval1;												// �ڶ��ź͵�һ�ŵ���ʱʱ�䣬��λ��
	int					nInterval2;												// �����ź͵ڶ��ŵ���ʱʱ�䣬��λ��
	int					nFollowTime;											// ����ʱ�䣬���һ������ǰһ��������������ʱ���С�ڴ�ֵ������Ϊ�Ǹ������룬����������������ͣ������Υ��

}CFG_TRAFFIC_PARKINGONYELLOWBOX_INFO;

//�¼�����	EVENT_IVS_TRAFFIC_PARKINGSPACEPARKING(��λ�г��¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_PARKINGSPACEPARKING_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
	int					nLane;													// ��λ��
	int                 nDelayTime;                                             // ��⵽������������ʼ�ϱ���ʱ��, ��λ���룬��Χ1~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
}CFG_TRAFFIC_PARKINGSPACEPARKING_INFO;

//�¼�����	EVENT_IVS_TRAFFIC_PARKINGSPACENOPARKING(��λ�޳��¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_PARKINGSPACENOPARKING_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
	int					nLane;													// ��λ��
	int                 nDelayTime;                                             // ��⵽������������ʼ�ϱ���ʱ��, ��λ���룬��Χ1~65535
	int					nDetectRegionPoint;										// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];						// �������
}CFG_TRAFFIC_PARKINGSPACENOPARKING_INFO;

//�¼�����EVENT_IVS_TRAFFIC_PARKINGSPACEOVERLINE(��λѹ���¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_PARKINGSPACEOVERLINE_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	bool                bAllowParkingSpaceParkingSnap;                          // �Ƿ�����λ�г��ϴ�ץ�ģ�true-��ʾ����(Ĭ�ϲ�����)
	BYTE                byReserved[2];                                           // �����ֶ�
	int					nObjectTypeNum;											// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	int                 nPtzPresetId;											// ��̨Ԥ�õ���	0~65535
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
	
	int					nLane;													// ��λ��
}CFG_TRAFFIC_PARKINGSPACEOVERLINE_INFO;

//�¼����� EVENT_IVS_TRAFFIC_PEDESTRAIN (��ͨ�����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_PEDESTRAIN_INFO
{
    char                szRuleName[MAX_NAME_LEN];                               // ��������,��ͬ����������
    bool                bRuleEnable;                                            // ����ʹ��
    BYTE                bReserved[3];                                           // �����ֶ�
    int                 nObjectTypeNum;                                         // ��Ӧ�������͸���
    char                szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];      // ��Ӧ���������б�
    int                 nPtzPresetId;                                           // ��̨Ԥ�õ��� 0~65535
    CFG_ALARM_MSG_HANDLE stuEventHandler;                                       // ��������
    CFG_TIME_SECTION    stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];         // �¼���Ӧʱ���
    
    int                 nLane;                                                  // �������
    int                 nDetectRegionPoint;                                     // �����������
    CFG_POLYGON         stuDetectRegion[MAX_POLYGON_NUM];                       // �����
    int                 nMinDuration;                                           // ��̴���ʱ�䣬��λ����
}CFG_TRAFFIC_PEDESTRAIN_INFO;

//�¼����� EVENT_IVS_TRAFFIC_THROW (��ͨ�����¼�)��Ӧ�Ĺ�������
typedef struct tagCFG_TRAFFIC_THROW_INFO
{
    char                szRuleName[MAX_NAME_LEN];                               // ��������,��ͬ����������
    bool                bRuleEnable;                                            // ����ʹ��
    BYTE                bReserved[3];                                           // �����ֶ�
    int                 nObjectTypeNum;                                         // ��Ӧ�������͸���
    char                szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];      // ��Ӧ���������б�
    int                 nPtzPresetId;                                           // ��̨Ԥ�õ��� 0~65535
    CFG_ALARM_MSG_HANDLE stuEventHandler;                                       // ��������
    CFG_TIME_SECTION    stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];         // �¼���Ӧʱ���
    
    int                 nLane;                                                  // �������
    int                 nDetectRegionPoint;                                     // �����������
    CFG_POLYGON         stuDetectRegion[MAX_POLYGON_NUM];                       // �����
    int                 nMinDuration;                                           // ��̴���ʱ�䣬��λ����
}CFG_TRAFFIC_THROW_INFO;

typedef struct tagCFG_RULE_INFO
{
	DWORD				dwRuleType;							// �¼����ͣ����dhnetsdk.h��"���ܷ����¼�����"
	int					nRuleSize;							// ���¼����͹������ýṹ���С
	
} CFG_RULE_INFO;

// ÿ����Ƶ����ͨ����Ӧ�������¼����򣺻�����pRuleBuf������¼�������Ϣ��ÿ���¼�������Ϣ����ΪCFG_RULE_INFO+"�¼����Ͷ�Ӧ�Ĺ������ýṹ��"��
typedef struct tagCFG_ANALYSERULES_INFO
{
	int					nRuleCount;							// �¼��������
	char*				pRuleBuf;							// ÿ����Ƶ����ͨ����Ӧ����Ƶ�����¼��������û���
	int					nRuleLen;							// �����С

} CFG_ANALYSERULES_INFO;

// ��Ƶ������Դ����
typedef enum tagCFG_VIDEO_SOURCE_TYPE
{
	CFG_VIDEO_SOURCE_REALSTREAM,                            // ʵʱ��
	CFG_VIDEO_SOURCE_FILESTREAM,                            // �ļ���
}CFG_VIDEO_SOURCE_TYPE;

// ����Դ�ļ�����
typedef enum tagCFG_SOURCE_FILE_TYPE
{
	CFG_SOURCE_FILE_UNKNOWN,                                // δ֪����
	CFG_SOURCE_FILE_RECORD,                                 // ¼���ļ�
	CFG_SOURCE_FILE_PICTURE,                                    // ͼƬ�ļ�
}CFG_SOURCE_FILE_TYPE;

// ��Ƶ����Դ�ļ���Ϣ
typedef struct tagCFG_SOURCE_FILE_INFO
{
	char                szFilePath[MAX_PATH];               // �ļ�·��
	CFG_SOURCE_FILE_TYPE emFileType;                        // �ļ����ͣ����CFG_SOURCE_FILE_TYPE
}CFG_SOURCE_FILE_INFO;

// ÿ����Ƶ����ͨ����Ӧ����Ƶ������Դ������Ϣ
typedef struct tagCFG_ANALYSESOURCE_INFO
{
	bool				bEnable;								// ��Ƶ����ʹ��
	BYTE				bReserved[3];							// ��������
	int					nChannelID;								// ���ܷ�����ǰ����Ƶͨ����
	int					nStreamType;							// ���ܷ�����ǰ����Ƶ�������ͣ�0:ץͼ����; 1:������; 2:������1; 3:������2; 4:������3; 5:������
	char				szRemoteDevice[MAX_NAME_LEN];			// �豸��
	BOOL				abDeviceInfo;				        	// �豸��Ϣ�Ƿ���Ч
	AV_CFG_RemoteDevice stuDeviceInfo;					        // �豸��Ϣ
	CFG_VIDEO_SOURCE_TYPE emSourceType;                         // ��Ƶ����Դ���ͣ����CFG_VIDEO_SOURCE_TYPE
	CFG_SOURCE_FILE_INFO stuSourceFile;                          // ����Ƶ����Դ����ΪCFG_VIDEO_SOURCE_FILESTREAMʱ����Ч
} CFG_ANALYSESOURCE_INFO;

//��Ƶ�����������ã�Ӱ���豸�������������Ϊ
typedef struct tagCFG_ANALYSEWHOLE_INFO
{	
	unsigned  int nVideoChannelType;		// ��Ƶͨ������ѡ�� 0:���֣�1;ģ�⣬2:���ֺ�ģ��
	
}CFG_ANALYSEWHOLE_INFO;




typedef struct tagCFG_RAINBRUSH_INFO
{
	bool                bEnable;                                 // ��ˢʹ��
	BYTE                bSpeedRate;                              // ��ˢ�ٶ�,1:����;2:����;3:����
	BYTE                bReserved[2];                            // ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���

}CFG_RAINBRUSH_INFO;

// BreakingSnapTimes
typedef struct tagBREAKINGSNAPTIMES_INFO
{
	int               nNormal;                          // ����
	int               nRunRedLight;                     // �����
	int			      nOverLine;						// ѹ��
	int				  nOverYellowLine;			  	    // ѹ����
	int				  nRetrograde;			    	    // ����
	int				  nUnderSpeed;					    // Ƿ��
    int				  nOverSpeed;						// ����
	int			      nWrongRunningRoute;				// �г�ռ��
	int			      nYellowInRoute;					// ����ռ��
	int		    	  nSpecialRetrograde;				// ��������
	int			      nTurnLeft;						// Υ����ת
	int			      nTurnRight;						// Υ����ת
	int			      nCrossLane;						// Υ�±��
	int			      nU_Turn;						    // Υ�µ�ͷ
	int			      nParking;						    // Υ��ͣ��
	int               nWaitingArea;						// Υ�½��������
	int			      nWrongRoute;					    // ����������ʻ		
	int               nParkingSpaceParking;             // ��λ�г�
	int               nParkingSpaceNoParking;           // ��λ�޳�

	int               nRunYellowLight;					// ���Ƶ�
	int               nStay;							// Υ��ͣ��
	int               nPedestrainPriority;	            // ��������������Υ��
	int               nVehicleInBusRoute;               // Υ��ռ��
	int               nBacking;                         // Υ�µ���
	int				  nOverStopLine;					// ѹֹͣ��
	int               nParkingOnYellowBox;           	// ��������ͣ��	
	int               nRestrictedPlate;					// ���޳���	
	int               nNoPassing;						// ����	
}BREAKINGSNAPTIMES_INFO;


// ʱ��
typedef struct tagCFG_NET_TIME
{
    int                 nStructSize;
    DWORD				dwYear;					// ��
    DWORD				dwMonth;				// ��
    DWORD				dwDay;					// ��
    DWORD				dwHour;					// ʱ
    DWORD				dwMinute;				// ��
    DWORD				dwSecond;				// ��
} CFG_NET_TIME;

//OSD�ڱ�
typedef struct tagBLACK_REGION_INFO
{
	int nHeight;			//�ڱ߸߶� ȡֵ��Χ��0 ~ ( 8192-ԭͼƬ�߶�)
	int nOSDPosition;		//�ڱ�λ�� 0=δ֪ , 1=���� , 2=�ײ�
}BLACK_REGION_INFO;

#define MAX_OSD_CUSTOM_SORT_NUM       8
#define MAX_OSD_CUSTOM_SORT_ELEM_NUM  8
#define MAX_OSD_ITEM_ATTR_NUM         8 
#define MAX_PRE_POX_STR_LEN           32
#define MAX_OSD_CUSTOM_NAME_LEN       32
#define MAX_OSD_CUSTOM_VALUE_LEN      256

//ȫ��OSD�������
typedef struct tagOSD_WHOLE_ATTR
{
    BOOL        bPositionAsBlackRegion;     //λ���Ƿ�ͬ�ڱ���ͬ,trueʱ�������Position��Ч
    CFG_RECT    stPostion;                  //λ��,���ܳ���ͼƬ��Χ
    BOOL        bNewLine;                   //�������η�Χ�Ƿ���,bPositionAsBlackRegionΪtrueʱ��Ч
    BOOL        bLoneVehicle;                //������Ϣ������ʾ,true һ����ʾһ������Ϣ,false �����������Ϣ��ʾ��һ��
}OSD_WHOLE_ATTR;

typedef union tagOSD_ATTR_SCHEME
{
    OSD_WHOLE_ATTR stWholeAttr;
}OSD_ATTR_SCHEME;

//OSD�������Ԫ��
typedef struct tagOSD_CUSTOM_ELEMENT
{
    int  nNameType;                          //��������,	0:szName�ֶκ������szOSDOrder�ֶζ������
                                             //             1:"Name"�ֶα�ʾ�Զ�����������
    char szName[MAX_OSD_CUSTOM_VALUE_LEN];                           // ��������
    char szPrefix[MAX_PRE_POX_STR_LEN];      // ����ǰ׺�ַ���	
    char szPostfix[MAX_PRE_POX_STR_LEN];     //���Ӻ�׺�ַ���
    int  nSeperaterCount;                    //������ӷָ�������
    
}OSD_CUSTOM_ELEMENT;

//OSD���������Զ�������
typedef struct tagOSD_CUSTOM_SORT
{
    OSD_CUSTOM_ELEMENT   stElements[MAX_OSD_CUSTOM_SORT_ELEM_NUM];     //�������Ԫ��
    int                  nElementNum;
}OSD_CUSTOM_SORT;

#define  MAX_CONF_CHAR 256
//OSD����
typedef struct tagOSD_INFO
{
	BLACK_REGION_INFO	stBackRegionInfo;		//OSD�ڱ�����
	int					nOSDAttrScheme;		    //OSD�������÷��� 0=δ֪ , 1=ȫ��OSD������� , 2=ÿ��OSD��һ������
	OSD_ATTR_SCHEME		stOSDAttrScheme;		//OSD�������÷�������
    OSD_CUSTOM_SORT     stOSDCustomSorts[MAX_OSD_CUSTOM_SORT_NUM];    //OSD���������Զ�������
    int                 nOSDCustomSortNum;
    int                 nRedLightTimeDisplay;   //OSD���ʱ������ 0=δ֪,1=Υ�����һ��,2=������
    char                cSeperater;             //OSD��ͬ��֮��ķָ���
    BYTE		        bReserved[3];           //�ֽڶ���
    char                szOSDOrder[MAX_CONF_CHAR];    
    int                 nOSDContentScheme;      //0=δ֪, 1=Mask , 2=CustomizeSort
}OSD_INFO;

// Detector -- BEGIN
// CoilConfig
typedef struct tagCOILCONFIG_INFO
{
    int               nDelayFlashID;                 // ��ʱ��������	ÿ����Ȧ��Ӧ����ʱ���ص���ţ���Χ0~5��0��ʾ����ʱ�κ������
    int               nFlashSerialNum;               // ��������	��Χ0~5��0��ʾ��������ƣ�۴����Ŀ�ã�
    int               nRedDirection;                 // ��Ʒ���	ÿ����Ȧ��Ӧ�ĺ�Ʒ���0-������,1-��ת���,2-ֱ�к��,3-��ת���,4-����,5-��ֱ,6-����, ֻ�ڵ羯����Ч
    int               nTriggerMode ;                 // ��Ȧ����ģʽ	����ģʽ��0-����Ȧ����1-����Ȧ������۴����Ŀ�ã�
    int				  nFlashSerialNum2;				 //��ץ�ڶ��Ŷ�Ӧ�������� ��Χ0~5��0��ʾ���������
    int				  nFlashSerialNum3;				 //��ץ�����Ŷ�Ӧ�������� ��Χ0~5��0��ʾ���������
}COILCONFIG_INFO;

typedef struct tagDETECTOR_INFO
{
	int                nDetectBreaking;                  // Υ����������	�ӵ�λ����λ�����ǣ�0-����1-�����2-ѹ��3-����4-Ƿ��5-����6-�г�ռ��7-����ռ��
	COILCONFIG_INFO    arstCoilCfg[MAX_COILCONFIG];      // ��Ȧ��������
	int				   nRoadwayNumber;				     // ������	1-16 ; 0��ʾ������
	int                nRoadwayDirection;                // �������򣨳������ķ���	0-���� 1-�����򶫱� 2-�� 3-�������� 4-������ 5-���������� 6-������ 7-���������� 8-����
	int                nRedLightCardNum;                 // ����ͼƬ���	��ʾ���羯�е�ĳһ��ͼƬ��Ϊ����ͼƬ�������ţ���0��ʾ�����ã�1~3,��ʾ���ö�Ӧ��ŵ�ͼƬ
	int                nCoilsNumber;                     // ��Ȧ����	1-3
	int                nOperationType;                   // ҵ��ģʽ	0-���ڵ羯1-�羯2-����
	int                arnCoilsDistance[3];              // ������Ȧ�ļ��	��Χ0-1000����λΪ����
	int                nCoilsWidth;                      // ÿ����Ȧ�Ŀ��	0~200cm
	int                arnSmallCarSpeedLimit[2];         // С�ͳ����ٶ����޺�����	0~255km/h�������ô�С������ʱ��Ϊ��ͨ��������
	int				   arnBigCarSpeedLimit[2];           // ���ͳ����ٶ����޺�����	0~255km/h�����ô�С������ʱ��Ч
	int				   nOverSpeedMargin;			     // �޸��ٿ���ֵ	��λ��km/h
	int                nBigCarOverSpeedMargin;           // ���޸��ٿ���ֵ	��λ��km/h�����ô�С������ʱ��Ч
	int				   nUnderSpeedMargin;			     // �޵��ٿ���ֵ	��λ��km/h
	int                nBigCarUnderSpeedMargin;          // ���޵��ٿ���ֵ	��λ��km/h�����ô�С������ʱ��Ч
	bool               bSpeedLimitForSize;               // �Ƿ����ô�С������
	bool			   bMaskRetrograde;				     // �����Ƿ���ΪΥ����Ϊ
	BYTE               byReserved[2];                    // ��������
	char               szDrivingDirection[3][MAX_DRIVINGDIRECTION]; //
													     // "DrivingDirection" : ["Approach", "�Ϻ�", "����"],��ʻ����
													     // "Approach"-���У����������豸�����Խ��Խ����"Leave"-���У�
														 // ���������豸�����Խ��ԽԶ���ڶ��͵����������ֱ�������к�
														 // ���е������ص㣬UTF-8����
	int                nOverPercentage;                  // ���ٰٷֱȣ��������ٰٷֱȺ�ץ��
	int                nCarScheme;                       // ����ķ���Index,���巽������βο��������local.png;����CFG_TRAFFICSNAPSHOT_INFO.abSchemeRange�ֶ��������÷�Χ
	int                nSigScheme;                       // ͬ�ϣ��ǿ���ʹ��
	BOOL               bEnable;                          // �����Ƿ���Ч��ֻ����Чʱ��ץ��

	int				   nYellowSpeedLimit[2];			 //���Ƴ��������޺����� ��Χ0~255km/h
	int				   nRoadType;						 //����·�� 0 ��ͨ��· 1 ���ٹ�·
	int				   nSnapMode;						 //ץ��ģʽ 0-ȫ��ץ�� 1-����ץ�� 2-����ץ�ģ�۴����Ŀ�ã�
    int                nDelayMode;						 //��ʱץ�ķ��� 0-ʹDelaySnapshotDistance��1-ʹ��DelayTime
	int                nDelayTime;						 //��ʱץ��ʱ�� ����Ƶ�����ץ��λ�þ������һ����Ȧ��ʱ�䣬��λ����
	int				   nTriggerMode;					 //����ģʽ 0-����Ȧ���� 1-����Ȧ���� 2-���붼ץ�� 3-�ر�
	int			       nErrorRange;						 //�ٶ����ֵ������Ȧ2�����Ȧ3֮����ٶ����ֵ����ʵ�������ڻ���ڸ�ֵ�����ٶ���Ч������ȡƽ���ٶ� 0-20
	double			   dSpeedCorrection;				 //�ٶ�У��ϵ�������ٶ�ֵΪ�����ֵ���Ը�ϵ�� 
    int                nDirection[2];                    //��Գ���������Ҫ�ϱ�������ʻ����,nDirection[0] 0--�� 1--���� ; nDirection[1] 0--�� 1--����	
}DETECTOR_INFO;
// Detector -- END

typedef struct tagRADAR_INFO
{
    int     nAngle;                 //�Ƕ�,���������״�̽ͷ��װ�ĽǶ���ɵ��ٶ����,��Χ[0,90]
    int     nAntiJammingValue;      //�������ż�ֵ
    int     nComeInValue;           //��������ż�ֵ,ȡֵ��Χ[0,65535]
    int     nComeOutValue;          //�����뿪�ż�ֵ
    int     nDelayTime;             //�״���ʱ,��λms����Χ[0,255]
    DWORD   nDetectBreaking;        //Υ����������,�ӵ�λ����λ������:
                                    //0-����,1-�����, 2-ѹ��, 3-����,4-Ƿ��
                                    //5-����,6-�г�ռ��,7-����ռ��,8-���Ƶ�,9-Υ��ռ��������
    int     nDetectMode;            //���ģʽ  0-��ͷ��� 1-��β��� 2-˫����
    int     nInstallMode;           //�״ﰲװ��ʽ  0-���氲װ 1-�Ϸ���װ
    int     nLevel;                 //������,0�����������,��Χ[0,5]
    int     nMultiTargetFilter;     //��Ŀ�����ģʽ,0-���� 1-����
    int     nWentEndValue;          //ȥ���źŽ����ż�ֵ
    int     nWentInValue;           //ȥ������ż�ֵ
    int     nWentOutValue;          //ȥ���뿪�ż�ֵ
}RADAR_INFO;

// CFG_CMD_INTELLECTIVETRAFFIC
typedef struct tagCFG_TRAFFICSNAPSHOT_INFO
{
	char                     szDeviceAddress[MAX_DEVICE_ADDRESS];  // �豸��ַ	UTF-8���룬256�ֽ�
	DWORD                    nVideoTitleMask;                      // OSD������������	�ӵ�λ����λ�ֱ��ʾ��0-ʱ�� 1-�ص� 2-����3-���� 4-���� 5-����6-������ 7-С������8-���� 9-Υ������10-������ 11-������ɫ 12-�������� 13-������ɫ14-��Ƶ���ʱ�� 15-Υ������ 16-�״﷽�� 17-�豸��� 18-�궨����ʱ�� 19-���� 20-��ʻ����
	int                      nRedLightMargin;                      // ���������ʱ��	��ƿ�ʼ��һ��ʱ���ڣ�����ͨ�в��㴳��ƣ���λ����
	float				     fLongVehicleLengthLevel;              // ������������С��ֵ	��λ���ף�����
	float					 arfLargeVehicleLengthLevel[2];        // �󳵳�����ֵ	��λ���ף�����Сֵ
	float					 arfMediumVehicleLengthLevel[2];       // ���ͳ�������ֵ	��λ���ף�����Сֵ
	float					 arfSmallVehicleLengthLevel[2];        // С��������ֵ	��λ���ף�����Сֵ
	float					 fMotoVehicleLengthLevel;              // Ħ�г����������ֵ	��λ���ף�������
	BREAKINGSNAPTIMES_INFO   stBreakingSnapTimes;                  // Υ��ץ������
	DETECTOR_INFO            arstDetector[MAX_DETECTOR];           // ���������ã��±��ǳ�����
	int 					 nCarType;			               	   // ץ�ĳ�������	0-��С����ץ��1-ץ��С��2-ץ�Ĵ�3-��С������ץ��
	int						 nMaxSpeed;			               	   // ����õ��ٶȳ�������ٶ�ʱ����������ٶȼ�	0~255km/h
	int						 nFrameMode;		               	   // ֡���ģʽ	1-�ٶ�����Ӧ�������ٶ�����ȡ0����������ٶ�����ȡ2������м�ȡ1�����2-��������������
	int                      arnAdaptiveSpeed[2];                  // �ٶ�����Ӧ���޺�����
	CFG_ALARM_MSG_HANDLE     stuEventHandler;	                   // ��ͨץ����������
	BOOL                     abSchemeRange;                        // TRUE:����������,�Գ���0��ֵΪ׼;FALSE:������Գ������������޸Ĵ��ֶ�����, ֻ�ڲ�ʹ��

    DWORD                    nVideoTitleMask1;					   // �ӵ�λ����λ�ֱ��ʾ��0-���� 1-��ƽ���ʱ�� 2-�豸���쳧�� 3-С�������� 4-�󳵵����� 5-С�������� 6-�󳵸����� 7-�豸����ģʽ 8-ͨ���Զ��� 9-�����Զ��� 10-ץ�Ĵ���Դ 11-ͣ��������12-��������(��������γ��ȵ�) 13-�г������� 14-�г������� 15-��·���� 16-GPS��Ϣ
    DWORD				     nMergeVideoTitleMask;                 // �ϳ�ͼƬOSD������������	����nVideoTitleMask�ֶ�
    DWORD				     nMergeVideoTitleMask1;				   // �ϳ�ͼƬOSD������������	����nVideoTitleMask1�ֶ�
    int                      nTriggerSource;					   // ����Դ���� 0-RS232 1-RS485 2-IO 3-Video 4-Net
    int						 nSnapMode;							   // ץ��ģʽ 0-ȫ��ץ�� 1-����ץ�� 2-����ץ�� 3-PKģʽ
    int                      nWorkMode;							   // ����ģʽ 0-�Զ�ģʽ��1-��Ȧץ��ģʽ��2-��Ȧץ��ʶ��3-��Ƶץ�ģ�4-��Ƶʶ��, 5-���ץ�ģ���ʶ��
    int                      nCarThreShold;						   // ������ֵ  ���ִ�С��������ֵ����λ: cm
    int                      nSnapType;							   // ץ�Ļ�ץ¼ѡ�� 0-����ץ��ģʽ 1-��Ƶץ��ģʽ 2-������ץģʽ
    int                      nCustomFrameInterval[3];			   // �Զ���ץ��֡��� ��һ��Ԫ��ָ����С���ٶ�����Ӧ����ʱ��ץ��֡�������������
    int                      nKeepAlive;				           // ���״��������Ĭ�ϱ������� ��λ��
    OSD_INFO				 stOSD;								   // ԭʼͼƬOSD��������
    OSD_INFO                 stMergeOSD;                           // �ϳ�ͼƬOSD��������
    CFG_NET_TIME             stValidUntilTime;					   // �궨����ʱ�䣬ָ��ʱ���֮ǰץ����Ƭ��Ч
    RADAR_INFO               stRadar;

}CFG_TRAFFICSNAPSHOT_INFO;

typedef struct tagCFG_TRAFFICSNAPSHOT_NEW_INFO
{
	int							nCount;								// ��Ч��Ա����
	CFG_TRAFFICSNAPSHOT_INFO	stInfo[8];							// ��ͨץ�ı�����

}CFG_TRAFFICSNAPSHOT_NEW_INFO;

// ��ͨ���� (CFG_CMD_DEV_GENERRAL) General 
typedef struct tagCFG_DEV_DISPOSITION_INFO
{
	int                      nLocalNo;              // ������ţ���Ҫ����ң�������ֲ�ͬ�豸	0~998
	char                     szMachineName[256];    // �������ƻ���
	char                     szMachineAddress[256]; // ��������ص㼴��·����
	char                     szMachineGroup[256];   // �����������豸������λ	Ĭ��Ϊ�գ��û����Խ���ͬ���豸��Ϊһ�飬���ڹ������ظ���
	char					 szMachineID[64];		// �������, ����ƽ̨��Ψһ
	
	BYTE		             bReserved[960];        // �����ֽ�
}CFG_DEV_DISPOSITION_INFO;

typedef struct tagOVERSPEED_INFO
{
	int                      nSpeedingPercentage[2];                        // ���ٰٷֱ�����Ҫ�����䲻���ص�����ЧֵΪ0,����,-1��-1��ʾ�����ֵ
	                                                                        // �����Ƿ�٣�Ҫ�����䲻���ص�����ЧֵΪ0,����,-1��-1��ʾ�����ֵ��Ƿ�ٰٷֱȵļ��㷽ʽ���޵���-ʵ�ʳ���/�޵���
	char                     szCode[MAX_VIOLATIONCODE];                     // Υ�´���
	char                     szDescription[MAX_VIOLATIONCODE_DESCRIPT];     // Υ������

}CFG_OVERSPEED_INFO;

typedef CFG_OVERSPEED_INFO CFG_OVERSPEED_HIGHWAY_INFO;
typedef CFG_OVERSPEED_INFO CFG_UNDERSPEED_INFO;

//ViolationCode Υ�´������ñ�
typedef struct tagVIOLATIONCODE_INFO
{
    char                szRetrograde[MAX_VIOLATIONCODE];			// ����
	char                szRetrogradeDesc[MAX_VIOLATIONCODE_DESCRIPT];              // Υ��������Ϣ

	char				szRetrogradeHighway[MAX_VIOLATIONCODE];		// ����-���ٹ�·
	char				szRetrogradeHighwayDesc[MAX_VIOLATIONCODE_DESCRIPT];		// Υ��������Ϣ

	char                szRunRedLight[MAX_VIOLATIONCODE];			// �����
	char                szRunRedLightDesc[MAX_VIOLATIONCODE_DESCRIPT];			   // Υ��������Ϣ

	char                szCrossLane[MAX_VIOLATIONCODE];				// Υ�±��
	char                szCrossLaneDesc[MAX_VIOLATIONCODE_DESCRIPT];			   // Υ��������Ϣ

	char                szTurnLeft[MAX_VIOLATIONCODE];				// Υ����ת
	char                szTurnLeftDesc[MAX_VIOLATIONCODE_DESCRIPT];				   // Υ��������Ϣ

	char                szTurnRight[MAX_VIOLATIONCODE];				// Υ����ת
	char                szTurnRightDesc[MAX_VIOLATIONCODE_DESCRIPT];				// Υ��������Ϣ

	char                szU_Turn[MAX_VIOLATIONCODE];				// Υ�µ�ͷ
	char                szU_TurnDesc[MAX_VIOLATIONCODE_DESCRIPT];				   // Υ��������Ϣ

	char                szJam[MAX_VIOLATIONCODE];					// ��ͨӵ��
	char                szJamDesc[MAX_VIOLATIONCODE_DESCRIPT];					   // Υ��������Ϣ

	char                szParking[MAX_VIOLATIONCODE];				// Υ��ͣ��
	char                szParkingDesc[MAX_VIOLATIONCODE_DESCRIPT];			      	// Υ��������Ϣ

	// ���� �� ���ٱ��� ֻ���ұ�����һ������
	char                szOverSpeed[MAX_VIOLATIONCODE];				// ����
	char                szOverSpeedDesc[MAX_VIOLATIONCODE_DESCRIPT];				// Υ��������Ϣ
	CFG_OVERSPEED_INFO  stOverSpeedConfig[5];                       // ���ٱ�������

	// ����(���ٹ�·) �� ���ٱ���(���ٹ�·) ֻ���ұ�����һ������
	char                szOverSpeedHighway[MAX_VIOLATIONCODE];		// ����-���ٹ�·
	char                szOverSpeedHighwayDesc[MAX_VIOLATIONCODE_DESCRIPT];	      	// ����-Υ��������Ϣ
	CFG_OVERSPEED_HIGHWAY_INFO stOverSpeedHighwayConfig[5];         // ���ٱ�������

	// Ƿ�� �� Ƿ�ٱ��� ֻ���ұ�����һ������
	char                szUnderSpeed[MAX_VIOLATIONCODE];	        // Ƿ��
	char                szUnderSpeedDesc[MAX_VIOLATIONCODE_DESCRIPT];	            // Υ��������Ϣ
	CFG_UNDERSPEED_INFO stUnderSpeedConfig[5];                            // Ƿ��������Ϣ	��һ�����飬��ͬ��Ƿ�ٱ�Υ�´��벻ͬ��Ϊ�ձ�ʾΥ�´��벻���ֳ��ٱ�

	char                szOverLine[MAX_VIOLATIONCODE];				// ѹ��
	char                szOverLineDesc[MAX_VIOLATIONCODE_DESCRIPT];			    	// Υ��������Ϣ

	char                szOverYellowLine[MAX_VIOLATIONCODE];	    // ѹ����
	char                szOverYellowLineDesc[MAX_VIOLATIONCODE_DESCRIPT];	    	// Υ��������Ϣ

	char                szYellowInRoute[MAX_VIOLATIONCODE];			// ����ռ��
	char                szYellowInRouteDesc[MAX_VIOLATIONCODE_DESCRIPT];			// Υ��������Ϣ

	char                szWrongRoute[MAX_VIOLATIONCODE];			// ����������ʻ
	char                szWrongRouteDesc[MAX_VIOLATIONCODE_DESCRIPT];				// Υ��������Ϣ

	char                szDrivingOnShoulder[MAX_VIOLATIONCODE];		// ·����ʻ
	char                szDrivingOnShoulderDesc[MAX_VIOLATIONCODE_DESCRIPT];		// Υ��������Ϣ

	char                szPassing[MAX_VIOLATIONCODE];               // ������ʻ
	char                szPassingDesc[MAX_VIOLATIONCODE_DESCRIPT];               	// Υ��������Ϣ

	char                szNoPassing[MAX_VIOLATIONCODE];             // ��ֹ��ʻ
	char                szNoPassingDesc[MAX_VIOLATIONCODE_DESCRIPT]; 				// Υ��������Ϣ

	char                szFakePlate[MAX_VIOLATIONCODE];              // ����
	char                szFakePlateDesc[MAX_VIOLATIONCODE_DESCRIPT]; 				// Υ��������Ϣ
	
	char                szParkingSpaceParking[MAX_VIOLATIONCODE];              // ��λ�г�
	char                szParkingSpaceParkingDesc[MAX_VIOLATIONCODE_DESCRIPT]; 				// Υ��������Ϣ

	char                szParkingSpaceNoParking[MAX_VIOLATIONCODE];              // ��λ�޳�
	char                szParkingSpaceNoParkingDesc[MAX_VIOLATIONCODE_DESCRIPT]; 				// Υ��������Ϣ

	BYTE		        bReserved[864];
}VIOLATIONCODE_INFO;
// CFG_CMD_TRAFFICGLOBAL ��ͨȫ���������ñ�
typedef struct tagCFG_TRAFFICGLOBAL_INFO
{
	VIOLATIONCODE_INFO   stViolationCode;       // Υ�´������ñ�
	BOOL                 bEnableRedList;        // ʹ�ܺ�������⣬ʹ�ܺ������ڳ���Υ�²��ϱ�
	BYTE		         bReserved[1020];
}CFG_TRAFFICGLOBAL_INFO;

// CFG_CMD_VIDEOENCODEROI ��Ƶ����ROI(Region of Intrest)����
#define DH_MAX_QUALITY_REGION_NUM 8
typedef struct tagCFG_VIDEOENCODEROI_INFO
{
	int      nRegionNum;                               // �Ż��������
	CFG_RECT stRegions[DH_MAX_QUALITY_REGION_NUM];     // �Ż����� ֧�ֶ���Ż�����ʹ�����������ϵ��ȡֵ��Ϊ0~8191
	BYTE     byQuality;        // ͼ������ ȡֵ1~6��ֵԽ��ͼ������Խ��
	bool     bMain;            // �Ż���������Ƶ����
	bool     bExtra1;          // �Ż�������1��Ƶ����	
	bool     bExtra2;          // �Ż�������2��Ƶ����
	bool     bExtra3;          // �Ż�������3��Ƶ����
	bool     bSnapshot;        // �Ż�ץͼ����
	BYTE     byReserved2[2];   // ����
}CFG_VIDEOENCODEROI_INFO;

// ATMȡ�ʱ����
typedef struct tagCFG_ATMMOTION_INFO
{
	int nTimeLimit;            // ȡ�ʱʱ��,��λ:��
}CFG_ATMMOTION_INFO;

typedef struct tagCFG_SNAPSOURCE_INFO_SINGLE_CHANNEL
{
	bool		bEnable;			// ʹ��
	BYTE		bReserved1[3];		// �����ֶΣ�����
	BYTE		bDevice[64];		// �豸��
	DWORD		dwChannel;			// ��Ƶͨ����
	DWORD		dwLinkVideoChannel; // ץͼͨ����Ӧ����Ƶͨ����
	BYTE		bReserved[512];		// �����ֶ�
}SNAPSOURCE_INFO_SINGLE_CHANNEL;

typedef struct tagCFG_SNAPSOURCE_INFO
{
	DWORD dwCount;												//Ҫ���õ�ͨ���ĸ���
	SNAPSOURCE_INFO_SINGLE_CHANNEL singleChnSanpInfo[MAX_VIDEO_CHANNEL_NUM];	//SNAPSOURCE_INFO_SINGLE_CHANNEL����ĵ�ַ
}CFG_SNAPSOURCE_INFO;

typedef struct tagDEVICE_STATUS
{
	char	szDeviceName[MAX_REMOTEDEVICENAME_LEN];	//Զ���豸������
	BYTE	bDeviceStatus;							//Զ���豸��״̬ 0������ 1������
	BYTE	bReserved[63];							//�����ֽ�
}DEVICE_STATUS;

typedef struct tagCFG_REMOTE_DEVICE_STATUS
{
	DEVICE_STATUS devStatus[MAX_REMOTE_DEV_NUM]; //�豸״̬
	DWORD		  dwDevCount;					 //�豸����
	BYTE		  bReserved[1024];				 //�����ֽ�
}CFG_REMOTE_DEVICE_STATUS;

//-----------------------------��Ƶ�����������------------------------------
// �¼����� EVENT_IVS_AUDIO_ABNORMALDETECTION (�����쳣����¼�)��Ӧ��������
typedef struct tagCFG_IVS_AUDIO_ABNORMALDETECTION_INFO
{
	char				szRuleName[MAX_NAME_LEN];								// ��������,��ͬ����������
	bool				bRuleEnable;											// ����ʹ��
	BYTE                bReserved[3];                                           // �����ֶ�
	int                 nDecibel;                                               // ����ǿ�ȣ���λ db
	int                 nFrequency;                                             // ����Ƶ��, ��λ Hz
	int                 nMinDuration;                                           // ��̳���ʱ��, ��λ s
	CFG_ALARM_MSG_HANDLE stuEventHandler;										// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];			// �¼���Ӧʱ���
}CFG_IVS_AUDIO_ABNORMALDETECTION_INFO;

typedef struct tagCFG_CAP_AUDIO_ANALYSE_INFO
{
	int                 nSupportedRuleNum;                                      // ֧�ֵĹ���������
	DWORD               dwSupportedRules[MAX_RULE_LIST_SIZE];                   // ����֧�ֵĹ�������
}CFG_CAP_AUDIO_ANALYSE_INFO;

//-------------------------IPS && SVR------------------------------

// �豸״̬��Ϣ
typedef struct tagCFG_DEVICESTATUS_INFO
{
	int                 nPowerNum;                               // ��Դ����
	BYTE                byPowerStatus[MAX_POWER_NUM];            // ��Դ״̬��1:���� 2:�쳣 3:δ֪
	int                 nCPUNum;                                 // CPU����
	int                 nCPUTemperature[MAX_CPU_NUM];            // CPU�¶�
	int                 nFanNum;                                 // ���ȸ���
	int                 nRotatoSpeed[MAX_FUN_NUM];               // ����ת��
}CFG_DEVICESTATUS_INFO;

// ��չ����Ϣ
typedef struct tagCFG_HARDDISK_INFO 
{
	int                     nChannel;                        // ͨ����
	int                     nCapacity;                       // Ӳ������ 
	BYTE                    byStatus;                        // Ӳ��״̬��0:unknown 1:running 2:fail 3.spare�ȱ�
															 // 4.syncͬ�� 5.faultyʧЧ 6.rebuilding�ؽ� 7.remove�Ƴ� 8.sleep����
	BYTE                    byUsedStatus;                    // ʹ��״̬��1.���� 2.���� 3.δ֪
    BYTE                    byHotBack;                       // �Ƿ����ȱ��̣�0:�ȱ��� 1:���ȱ���
	BYTE                    byReserved;                      // �ֽڶ���
	char                    szRaidName[MAX_NAME_LEN];        // ����Raid(������)������	"RaidName" : "Raid0",
															 // ����Raid(������)�����ơ��粻�����κ�Raid�����ֶ�Ϊnull��
															 // �����ȱ��̣�����ȫ���ȱ��̵ģ���null��
	char                    szType[32];                      // Ӳ���ͺ�
	int                     nTank;                           // ��չ��, 0:����;1:��չ��1; 2:��չ��2	����
	int						nRemainSpace;					 // ʣ����������λM
}CFG_HARDDISK_INFO;

typedef struct tagCFG_HARDDISKTANK_INFO
{
	char                    szTankName[MAX_NAME_LEN];           // �洢������
	int                     nHardDiskNum;                       // Ӳ�̸���
	CFG_HARDDISK_INFO       stuHarddiskInfo[MAX_HARDDISK_NUM];  // Ӳ����Ϣ
}CFG_HARDDISKTANK_INFO;

typedef struct tagCFG_HARDISKTANKGROUP_INFO
{
	int                      nTankNum;                       // Ӳ�̴洢�����
	CFG_HARDDISKTANK_INFO    stuHarddisktank[MAX_TANK_NUM];  // Ӳ�̴洢������
}CFG_HARDISKTANKGROUP_INFO;

// Raid����Ϣ
typedef struct tagCFG_RAID_INFO
{
	char                    szRaidName[MAX_NAME_LEN];         // Raid����
	BYTE                    byType;                           // ���� 1:Jbob, 2:Raid0, 3:Raid1, 4:Raid5
	BYTE                    byStatus;                         // ״̬  0:unknown, 1:active, 2:degraded, 3:inactive, 4: Resyncing
															  // 5.Clean 6.Unknow 7.Recovering 8.Reshaping 9.Checking 10.NotStarted
	BYTE                    byStatusCount;                    // ״̬����, ״̬��>=1ʱ, ��byStatusGroup��ʾ״̬
	BYTE                    byReserved;						  // �ֽڶ���
	int                     nMember[MAX_CHAN_NUM];            // ��ɴ���ͨ��
	int                     nDiskNUM;                         // ���̸���
	int                     nCapacity;                        // ����
	int                     nTank;                            // ��չ��
	int						nRemainSpace;					  // ʣ����������λM
	BYTE					byStatusGroup[MAX_STATUS_NUM];	  // ״̬����, ����ֵͬbyStatus
}CFG_RAID_INFO;

typedef struct tagCFG_RAIDGROUP_INFO
{
	int                     nRaidNum;                         // Raid����
	CFG_RAID_INFO           stuRaidInfo[MAX_RAID_NUM];        // Raid����Ϣ
}CFG_RAIDGROUP_INFO;

// �洢������Ϣ
typedef struct tagCFG_STORAGEPOOL_INFO
{
	char                   szName[MAX_NAME_LEN];               // �洢������
	int                    nMemberNum;                         // �豸����
	char                   szMember[MAX_DEV_NUM][MAX_NAME_LEN];// ����豸
	int                    nUsed;                              // ��������
    int                    nCapacity;                          // ������
    int                    nStatus;                            // ״̬	0:unknown 1:active 2:degraded 3:inactive
    int                    nTank;                              // ��չ��	0:����, 1:��չ��1, 2:��չ��2 ����
}CFG_STORAGEPOOL_INFO;

typedef struct tagCFG_STORAGEPOOLGROUP_INFO
{
	int                     nStroagePoolNum;                           // �洢�ظ���
	CFG_STORAGEPOOL_INFO    stuStoragePoolInfo[MAX_STORAGEPOOL_NUM];   // �洢����Ϣ
}CFG_STORAGEPOOLGROUP_INFO;

// �ļ�ϵͳ����Ϣ
typedef struct tagCFG_STORAGEPOSITION_INFO
{
	char                   szName[MAX_NAME_LEN];               // �洢λ������	
    char                   szStoragePoolName[MAX_NAME_LEN];    // �洢������	
    int                    nUsedCapacity;                      // ��������,��λG	
    int                    nTotalCapacity;                     // ����,��λG	
	BYTE                   byStatus;                           // ״̬ 0.δ֪ 1.���� 2.�����쳣 3.�����쳣
    BYTE                   byReserved[3];                      // �ֽڶ���
}CFG_STORAGEPOSITION_INFO;

typedef struct tafCFG_STORAGEPOSITIONGROUP_INFO
{
	int                      nStoragePositionNum;                         // �洢��Ϣ����
	CFG_STORAGEPOSITION_INFO stuStoragePositionInfo[MAX_STRORAGEPOS_NUM]; // �ļ�ϵͳ����Ϣ      
}CFG_STORAGEPOSITIONGROUP_INFO;

// ǰ���豸����Ϣ
typedef struct tagCFG_VIDEOINDEV_INFO
{
	char                   szDevName[MAX_NAME_LEN];             // ǰ���豸����	
    char                   szDevID[MAX_NAME_LEN];               // �豸ID	
    char                   szDevType[MAX_NAME_LEN];             // �豸����
    int                    nTotalChan;                          // ��ͨ����
	int                    nTotalAlarmChan;                     // ����ͨ������
    char                   szIP[MAX_ADDRESS_LEN];               // �豸IP
	BYTE                   byStatus;                            // ״̬ 0:δ֪ 1:���� 2:����
	BYTE                   byReserved[3];                       // �ֽڶ���
}CFG_VIDEOINDEV_INFO;

typedef struct tafCFG_VIDEOINDEVGROUP_INFO
{
	int                    nVideoDevNum;                              // ǰ���豸����
	CFG_VIDEOINDEV_INFO    stuVideoInDevInfo[MAX_VIDEODEV_NUM];       // ǰ���豸����Ϣ      
}CFG_VIDEOINDEVGROUP_INFO;

// ͨ��¼����״̬
typedef struct tagCFG_DEVRECORD_INFO
{
	char                   szDevName[MAX_NAME_LEN];               // �豸����
	char                   szIP[MAX_ADDRESS_LEN];                 // �豸IP	
	char                   szChannel[MAX_NAME_LEN];               // ͨ����
    char                   szChannelName[MAX_NAME_LEN];           // ͨ������	
    char                   szStoragePosition[MAX_NAME_LEN];       // �洢λ����Ϣ
	BYTE                   byStatus;                              // ״̬ 0:δ֪ 1:¼�� 2:ֹͣ
	BYTE                   byReserved[3];                         // �ֽڶ���
}CFG_DEVRECORD_INFO;

typedef struct tagCFG_DEVRECORDGROUP_INFO
{
	int                    nChannelNum;                          // ͨ������
	CFG_DEVRECORD_INFO     stuDevRecordInfo[MAX_CHAN_NUM];       // ͨ��¼��״̬��Ϣ
}CFG_DEVRECORDGROUP_INFO;

#define byDahuaII byPrivateII
#define byDahuaIId byPrivateIId

// ����״̬
typedef struct tagCFG_IPSERVER_STATUS
{
	int                    nSupportedServerNum;                  // �ṩ�ķ������
	char                   szSupportServer[MAX_SEVER_NUM][MAX_NAME_LEN];  // �ṩ�ķ������� Svr Svrd(SVR�ػ�����) DataBase DataBased(DataBase�ػ�����) NtpServer NtpServerd(NtpServer�ػ�����) DahuaII DahuaIId(DahuaII�ػ�����) Samba Nfs Ftp iScsi 
	int                    nSvrSuppSubServerNum;                          // Svr�ṩ���ӷ�����Ϣ����
	char                   szSvrSuppSubServer[MAX_SEVER_NUM][MAX_NAME_LEN];           // Svr�ṩ���ӷ�����Ϣ CMS DMS	MTS	SS RMS DBR
	BYTE                   byCMS;                                // 0:δ֪ 1:���� 2:δ����
	BYTE                   byDMS;                                // 0:δ֪ 1:���� 2:δ����
	BYTE                   byMTS;                                // 0:δ֪ 1:���� 2:δ����
	BYTE                   bySS;                                 // 0:δ֪ 1:���� 2:δ����
	BYTE                   byRMS;                                // 0:δ֪ 1:���� 2:δ����
	BYTE                   byDBR;                                // 0:δ֪ 1:���� 2:δ����
	BYTE                   bySvrd;                               // 0:δ֪ 1:���� 2:δ����
	BYTE                   byDataBase;                           // 0:δ֪ 1:���� 2:δ����
	BYTE                   byDataBased;                          // 0:δ֪ 1:���� 2:δ����
	BYTE                   byNtpServer;                          // 0:δ֪ 1:���� 2:δ����
	BYTE                   byNtpServerd;                         // 0:δ֪ 1:���� 2:δ����
	BYTE                   byPrivateII;                          // 0:δ֪ 1:���� 2:δ����
	BYTE                   byPrivateIId;                         // 0:δ֪ 1:���� 2:δ����
	BYTE                   bySAMBA;                              // 0:δ֪ 1:���� 2:δ����
	BYTE                   byNFS;                                // 0:δ֪ 1:���� 2:δ����
	BYTE                   byFTP;                                // 0:δ֪ 1:���� 2:δ����
	BYTE                   byISCSI;                              // 0:δ֪ 1:���� 2:δ����
	BYTE                   byReserved[3];                        // �ֽڶ���
}CFG_IPSERVER_STATUS;

//---------------------------��Ƶ����-----------------------------------
#define MAX_SUPPORT_SPLIT_MODE_NUM    16             // ֧�ֵĻ���ָ�����������
#define MAX_MATRIX_PLAN               4              // �����󷽰���
#define MAX_TOUR_MODE                 16             // �����Ѳ������

typedef enum MATRIX_VIEW_SPLITMODE
{
	MATRIX_VIEW_SPLIT1 = 0,
	MATRIX_VIEW_SPLIT2,	
	MATRIX_VIEW_SPLIT4,
	MATRIX_VIEW_SPLIT8,
	MATRIX_VIEW_SPLIT9,	
	MATRIX_VIEW_SPLIT16,
	MATRIX_VIEW_SPLITPIP,
	MATRIX_VIEW_SPLIT6,
	MATRIX_VIEW_SPLIT12,
	MATRIX_VIEW_SPLIT25,
	MATRIX_VIEW_SPLIT36,
	MATRIX_VIEW_SPLIT_NR,
};

// ��Ѳģʽ
typedef struct tagCFG_TOUR_MODE
{
	int               nViewMode;                                    // ����ָ�ģʽ,�ο�ö������MATRIX_VIEW_SPLITMODE
	unsigned int      dwViewSplitMask;                     // ��ʾViewModeָ��ģʽ��,ʹ�ܵļ����ָ�����,ʹ�������﷽ʽ
													       // ����:0x00000007:��ʾģʽ3(SPLIT8)�ķָ�1,2,3ʹ�ܿ���,����δʹ��,0x0000000F��ʾ�ָ�1,2,3,4ʹ��
}CFG_TOUR_MODE;

// SPOT��Ƶ���󷽰�
typedef struct tagCFG_VIDEO_MATRIX_PLAN
{
	BOOL            bEnable;                                          // �������÷���ʹ��
	int             nTourPeriod;                                      // ������Ѳ���,��λ��,>=1
	int             nTourModeNum;                                     // ��Ѳ���и���
	CFG_TOUR_MODE   stuTourMode[MAX_TOUR_MODE];                       // ��Ѳ����
}CFG_VIDEO_MATRIX_PLAN;

// SPOT��������
typedef struct tagCFG_VIDEO_MATRIX
{
	int                         nSupportSplitModeNumber;         // ֧�ֵĻ���ָ��������
	BYTE                        bySupportSplitMode[MAX_SUPPORT_SPLIT_MODE_NUM];          // ֧�ֵĻ���ָ������
	int                         nMatrixPlanNumber;               // ���󷽰���
	CFG_VIDEO_MATRIX_PLAN       stuMatrixPlan[MAX_MATRIX_PLAN];                // ���󷽰�
}CFG_VIDEO_MATRIX;

///////////////////////////////////��Ƶ�������///////////////////////////////////////
// ��Ƶ�������
typedef struct tagCFG_VIDEO_DITHER_DETECTION
{
	BOOL							bEnable;									// ʹ������
	int								nMinDuration;								// ��̳���ʱ�� ��λ���� 0~65535
	BYTE							byThrehold1;								// Ԥ����ֵ ȡֵ1-100
	BYTE							byThrehold2;								// ������ֵ ȡֵ1-100
}CFG_VIDEO_DITHER_DETECTION;
// ���Ƽ��
typedef struct tagCFG_VIDEO_STRIATION_DETECTION 
{
	BOOL							bEnable;									// ʹ������
	int								nMinDuration;								// ��̳���ʱ�� ��λ���� 0~65535
	BYTE							byThrehold1;								// Ԥ����ֵ ȡֵ1-100
	BYTE							byThrehold2;								// ������ֵ ȡֵ1-100
	BYTE							byReserved1[2];								// �ֽڶ���
	BOOL							bUVDetection;								// UV�����Ƿ���					
}CFG_VIDEO_STRIATION_DETECTION;
// ��Ƶ��ʧ���
typedef struct tagCFG_VIDEO_LOSS_DETECTION
{
	BOOL							bEnable;									// ʹ������
	int								nMinDuration;								// ��̳���ʱ�� ��λ���� 0~65535
}CFG_VIDEO_LOSS_DETECTION;
// ��Ƶ�ڵ����
typedef struct tagCFG_VIDEO_COVER_DETECTION
{
	BOOL							bEnable;									// ʹ������
	int								nMinDuration;								// ��̳���ʱ�� ��λ���� 0~65535
	BYTE							byThrehold1;								// Ԥ����ֵ ȡֵ1-100
	BYTE							byThrehold2;								// ������ֵ ȡֵ1-100
}CFG_VIDEO_COVER_DETECTION;
// ���涳����
typedef struct tagCFG_VIDEO_FROZEN_DETECTION
{
	BOOL							bEnable;									// ʹ������
	int								nMinDuration;								// ��̳���ʱ�� ��λ���� 0~65535
}CFG_VIDEO_FROZEN_DETECTION;
// �����쳣���
typedef struct tagCFG_VIDEO_BRIGHTNESS_DETECTION
{	
	BOOL							bEnable;									// ʹ������
	int								nMinDuration;								// ��̳���ʱ�� ��λ���� 0~65535
	BYTE							bylowerThrehold1;							// Ԥ����ֵ ȡֵ1-100
	BYTE							bylowerThrehold2;							// ������ֵ ȡֵ1-100
	BYTE							byUpperThrehold1;							// Ԥ����ֵ ȡֵ1-100
	BYTE							byUpperThrehold2;							// ������ֵ ȡֵ1-100
}CFG_VIDEO_BRIGHTNESS_DETECTION;
// �Աȶ��쳣���
typedef struct tagCFG_VIDEO_CONTRAST_DETECTION
{	
	BOOL							bEnable;									// ʹ������
	int								nMinDuration;								// ��̳���ʱ�� ��λ���� 0~65535
	BYTE							bylowerThrehold1;							// Ԥ����ֵ ȡֵ1-100
	BYTE							bylowerThrehold2;							// ������ֵ ȡֵ1-100
	BYTE							byUpperThrehold1;							// Ԥ����ֵ ȡֵ1-100
	BYTE							byUpperThrehold2;							// ������ֵ ȡֵ1-100
}CFG_VIDEO_CONTRAST_DETECTION;
// ƫɫ���
typedef struct tagCFG_VIDEO_UNBALANCE_DETECTION
{	
	BOOL							bEnable;									// ʹ������
	int								nMinDuration;								// ��̳���ʱ�� ��λ���� 0~65535
	BYTE							byThrehold1;								// Ԥ����ֵ ȡֵ1-100
	BYTE							byThrehold2;								// ������ֵ ȡֵ1-100
}CFG_VIDEO_UNBALANCE_DETECTION;
// �������
typedef struct tagCFG_VIDEO_NOISE_DETECTION
{	
	BOOL							bEnable;									// ʹ������
	int								nMinDuration;								// ��̳���ʱ�� ��λ���� 0~65535
	BYTE							byThrehold1;								// Ԥ����ֵ ȡֵ1-100
	BYTE							byThrehold2;								// ������ֵ ȡֵ1-100
}CFG_VIDEO_NOISE_DETECTION;
// ģ�����
typedef struct tagCFG_VIDEO_BLUR_DETECTION
{
	BOOL							bEnable;									// ʹ������
	int								nMinDuration;								// ��̳���ʱ�� ��λ���� 0~65535
	BYTE							byThrehold1;								// Ԥ����ֵ ȡֵ1-100
	BYTE							byThrehold2;								// ������ֵ ȡֵ1-100
}CFG_VIDEO_BLUR_DETECTION;
// �����仯���
typedef struct tagCFG_VIDEO_SCENECHANGE_DETECTION
{	
	BOOL							bEnable;									// ʹ������
	int								nMinDuration;								// ��̳���ʱ�� ��λ���� 0~65535
	BYTE							byThrehold1;								// Ԥ����ֵ ȡֵ1-100
	BYTE							byThrehold2;								// ������ֵ ȡֵ1-100
}CFG_VIDEO_SCENECHANGE_DETECTION;
typedef struct tagCFG_VIDEO_DIAGNOSIS_PROFILE
{
	char							szName[MAX_PATH];							// ����Ansi����

	CFG_VIDEO_DITHER_DETECTION*		pstDither;									// ��Ƶ�������
	CFG_VIDEO_STRIATION_DETECTION*	pstStriation;								// ��Ƶ���Ƽ��
	CFG_VIDEO_LOSS_DETECTION*		pstLoss;									// ��Ƶ��ʧ���
	CFG_VIDEO_COVER_DETECTION*		pstCover;									// ��Ƶ�ڵ����
	CFG_VIDEO_FROZEN_DETECTION*		pstFrozen;									// ��Ƶ������
	CFG_VIDEO_BRIGHTNESS_DETECTION*	pstBrightness;								// ��Ƶ�����쳣���
	CFG_VIDEO_CONTRAST_DETECTION*	pstContrast;								// �Աȶ��쳣���
	CFG_VIDEO_UNBALANCE_DETECTION*	pstUnbalance;								// ƫɫ�쳣���
	CFG_VIDEO_NOISE_DETECTION*		pstNoise;									// �������
	CFG_VIDEO_BLUR_DETECTION*		pstBlur;									// ģ�����
	CFG_VIDEO_SCENECHANGE_DETECTION* pstSceneChange;							// �����仯���
}CFG_VIDEO_DIAGNOSIS_PROFILE;
// ��Ƶ��ϲ�����(CFG_CMD_VIDEODIAGNOSIS_PROFILE)��֧�ֶ��ֲ������ñ�����������   �����������ڴ沢��ʼ��
typedef struct tagCFG_VIDEODIAGNOSIS_PROFILE
{
	int								nTotalProfileNum;							// �����߷���������� ������������ȡ
	int								nReturnProfileNum;							// ���ص�ʵ�ʲ�������
	CFG_VIDEO_DIAGNOSIS_PROFILE*	pstProfiles;								// �����߷���nProfileCount��VIDEO_DIAGNOSIS_PROFILE
}CFG_VIDEODIAGNOSIS_PROFILE;

///// ��Ƶ�������
enum CFG_EM_STREAM_TYPE
{
	CFG_EM_STREAM_ERR,                  // ����
	CFG_EM_STREAM_MAIN,					// "Main"-������
	CFG_EM_STREAM_EXTRA_1,				// "Extra1"-������1
	CFG_EM_STREAM_EXTRA_2,				// "Extra2"-������2
	CFG_EM_STREAM_EXTRA_3,				// "Extra3"-������3
	CFG_EM_STREAM_SNAPSHOT,				// "Snapshot"-ץͼ����
	CFG_EM_STREAM_OBJECT,				// "Object"-������
};

// �豸��ϸ��Ϣ
typedef struct tagCFG_TASK_REMOTEDEVICE
{
	char                            szAddress[MAX_PATH];                        // �豸��ַ������
	unsigned int                    dwPort;                                     // �˿ں�
	char                            szUserName[MAX_PATH];                       // �û���
	char                            szPassword[MAX_PATH];                       // ��������
	char                            szProtocolType[MAX_PATH];                   // �����豸��Э������
	CFG_RemoteDeviceVideoInput      *pVideoInput;                               // ��Ƶ����ͨ�����û�����nMaxVideoInputs��CFG_RemoteDeviceVideoInput�ռ�
	int				                nMaxVideoInputs;					        // ��Ƶ����ͨ�������
	int				                nRetVideoInputs;					        // ���ص���Ƶ����ͨ����
}CFG_TASK_REMOTEDEVICE;

typedef struct tagCFG_TAST_SOURCES
{
	// ����
	bool							abDeviceID;                                 // abDeviceID(ʹ��szDeviceID) �� abRemoteDevice(ʹ��stRemoteDevice) ������һ��Ϊtrue������Sources��null
	bool							abRemoteDevice;

	char							szDeviceID[MAX_PATH];						// �豸ID
	CFG_TASK_REMOTEDEVICE           stRemoteDevice;                             // �豸��ϸ��Ϣ
	int								nVideoChannel;								// ��Ƶͨ����
	CFG_EM_STREAM_TYPE				emVideoStream;								// ��Ƶ��������
	int								nDuration;									// �������ʱ��
}CFG_TAST_SOURCES;
typedef struct tagCFG_DIAGNOSIS_TASK
{
	char							szTaskName[MAX_PATH];						// ��������Ansi����
	char							szProfileName[MAX_PATH]; 					// ������ʹ�õ���ϲ�������Ansi����
	int								nTotalSourceNum;						    // �����߷�����������Դ�ĸ���  ������������ȡ
	int								nReturnSourceNum;							// ����ʵ����������Դ�ĸ���
	CFG_TAST_SOURCES*				pstSources;									// ��������Դ �����߷����ڴ�nTotalSourceNum��
}CFG_DIAGNOSIS_TASK;
// ��Ƶ��������(CFG_CMD_VIDEODIAGNOSIS_TASK),��ͬ������ͨ����������  �����������ڴ沢��ʼ��
typedef struct tagCFG_VIDEODIAGNOSIS_TASK
{
	int								nTotalTaskNum; 								// �����߷����������  ������������ȡ
	int								nReturnTaskNum; 							// ����ʵ���������
	CFG_DIAGNOSIS_TASK*				pstTasks;									// �������� �����߷����ڴ�nTotalTaskNum��
}CFG_VIDEODIAGNOSIS_TASK;

// ��Ƶ��ϼƻ�
typedef struct tagPROJECT_TASK
{
	BOOL							bEnable;									// �����Ƿ�ʹ��
	char							szTaskName[MAX_PATH];						// ��������Ansi����
	CFG_TIME_SECTION				stTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];	// ����ʱ���
	BOOL                            bIsCycle;                                   // �����Ƿ�ѭ��,TRUE��ʾѭ��,FALSE��ʾ��ѭ��
}CFG_PROJECT_TASK;

typedef struct tagDIAGNOSIS_PROJECT
{
	char							szProjectName[MAX_PATH];					// �ƻ�����Ansi����
	int								nTotalTaskNum;								// �����߷��������б����  ������������ȡ
	int								nReturnTaskNum;					    		// ����ʵ�������б����
	CFG_PROJECT_TASK*				pstProjectTasks;								// �����б� �����߷����ڴ�nTotalTaskNum��
}CFG_DIAGNOSIS_PROJECT;
// Ƶ��ϼƻ���(CFG_CMD_VIDEODIAGNOSIS_PROJECT),��ͬ�ļƻ�ͨ���������� �����������ڴ沢��ʼ��
typedef struct tagCFG_VIDEODIAGNOSIS_PROJECT
{
	int								nTotalProjectNum;							// �����߷���ƻ�����  ������������ȡ
	int								nReturnProjectNum;							// ����ʵ�ʼƻ�����
	CFG_DIAGNOSIS_PROJECT*			pstProjects;									// �ƻ����� �����߷����ڴ�nTotalProjectNum��
}CFG_VIDEODIAGNOSIS_PROJECT;

// ʵʱ�ƻ������Ϣ
typedef struct tagCFG_DIAGNOSIS_REALPROJECT
{
	char							szProjectName[MAX_PATH];					// �ƻ�����Ansi����
	CFG_DIAGNOSIS_TASK			    stProjectTask;							    // ������Ϣ
}CFG_DIAGNOSIS_REALPROJECT;

// ��Ƶ���ʵʱ�ƻ���
typedef struct tagCFG_VIDEODIAGNOSIS_REALPROJECT 
{
	int								nProjectNum;							    // ʵʱ�ƻ�����
	CFG_DIAGNOSIS_REALPROJECT*		pstProjects;							    // �ƻ����� �����߷����ڴ�nProjectNum��
}CFG_VIDEODIAGNOSIS_REALPROJECT;

// ��Ƶ���ȫ�ֱ�(CFG_CMD_VIDEODIAGNOSIS_GLOBAL),ÿ��ͨ��֧��һ��������� 
typedef struct tagCFG_VIDEODIAGNOSIS_GLOBAL_CHNNL
{
	BOOL                            abProjectName;                              // �ƻ������Ƿ���Ч 
	char							szProjectName[MAX_PATH];					// �ƻ����ƣ�Ansi����
	BOOL                            abRealProjectName;                          // ʵʱ�ƻ������Ƿ���Ч
	char                            szRealProjectName[MAX_PATH];                // ʵʱ�ƻ����ƣ�Ansi����   
}CFG_VIDEODIAGNOSIS_GLOBAL_CHNNL;

typedef struct tagCFG_VIDEODIAGNOSIS_GLOBAL
{
	int								nTotalGlobalNum;							// �����߷���ȫ�����ø���  ������������ȡ
	int								nReturnGlobalNum;							// ����ʵ��ȫ�����ø���
	CFG_VIDEODIAGNOSIS_GLOBAL_CHNNL	*pstGlobals;								// ��Ƶ���ȫ������ �����߷����ڴ�nGlobalCount��CFG_VIDEODIAGNOSIS_GLOBAL_CHNNL
}CFG_VIDEODIAGNOSIS_GLOBAL;

// ��Ƶ��Ϸ���������(CFG_CAP_CMD_VIDEODIAGNOSIS_SERVER)
typedef struct tagCFG_VIDEODIAGNOSIS_CAPS_INFO
{
	int								nTypeCount;									// ֧�ֵ���Ƶ������� ����
	char						    szSupportedType[MAX_VIDEODIAGNOSIS_DETECT_TYPE][MAX_PATH];// ֧�ֵ���Ƶ�������
	int								nMaxProfiles;								// �����������
	int								nMaxTasks;									// ����������
	int								nMaxSourcesOfTask;							// ��󵥸��������ƵԴ����
	int								nMaxProjects;								// ��󷽰�����
}CFG_VIDEODIAGNOSIS_CAPS_INFO;

// ��ȡ��Ƶ���ͨ����Ŀ( CFG_CMD_VIDEODIAGNOSIS_GETCOLLECT )��Ӧ�ṹ��
typedef struct tagCFG_VIDEODIAGNOSIS_COLLECT_INFO
{
	int                             nDiagnosisChannels;                                   // ��Ƶ���ͨ����Ŀ
}CFG_VIDEODIAGNOSIS_COLLECT_INFO;

// ��ȡ��Ƶ��Ͻ���״̬( CFG_CMD_VIDEODIAGNOSIS_GETSTATE )��Ӧ�ṹ��
typedef struct tagCFG_VIDEODIAGNOSIS_STATE_INFO
{
	BOOL                            bEnable;                                     // �Ƿ�ʹ��
	BOOL                            bRunning;                                    // �Ƿ���������	ʹ�ܿ��������ҵ�ǰ�й����������ڽ��У�û�д�������
	char                            szCurrentProject[MAX_PATH];                  // ��ǰ�ƻ�����
	char                            szCurrentTask[MAX_PATH];                     // ��ǰ��������
	char                            szCurrentProfile[MAX_PATH];                  // ��ǰ�������ò���������
	int                             nCurrentSourceCount;                         // ��ǰ������ѵ��ƵԴ����
	int                             nCurrentSourceIndex;                         // ��ǰ����ǰ��ƵԴ���	��0��ʼ
	CFG_TIME_SECTION                stCurrentTimeSection;                        // ��ǰ�ƻ�ʱ���
	int                             nTaskCountOfProject;                         // ��ǰ�ƻ���������
	int                             nIndexOfCurrentTask;                         // ��ǰ������� ��0��ʼ
}CFG_VIDEODIAGNOSIS_STATE_INFO;

// ������֧�ֵķ����б�
typedef struct tagCFG_DEV_SERVICE_LIST
{
	int                             nServiceNum;                                 // ֧�ֵķ�����
	char                            szService[MAX_SERVICE_NUM][MAX_NAME_LEN];    // ������֧�־���ķ�����
}CFG_DEV_SERVICE_LIST;

//��ȡ����ʽ��������Ŀ
typedef struct tagCFG_MASTERSLAVETRACKER_INFO
{
        int                nStructSize;
	    int                nChannels;	//����ʽ������ͨ����Ŀ
}CFG_MASTERSLAVETRACKER_INFO;

#define  MAX_CAMERA_TYPE	64
#define	 MAX_TYPE_STRING	64

typedef struct tagCFG_CAMERA_PER_TYPE_INFO
{
	char				szCameraType[MAX_TYPE_STRING];	//����ͺ�
	char				szLensType[MAX_TYPE_STRING];	//�����ͷ�ͺ�	��ͷ�ͺź�����ͺ���أ�����Ϊ��ֵ
}CFG_CAMERA_PER_TYPE_INFO;

typedef struct tagCFG_CAMERA_TYPE_INFO
{
	int							nCameraTypeNum;						//�����͵���������еĲ�ͬ�ͺ���
	CFG_CAMERA_PER_TYPE_INFO	stCameraTypeInfos[MAX_CAMERA_TYPE]; //������ͺ���Ϣ
}CFG_CAMERA_TYPE_INFO;

// �䱶����
typedef enum tagCFG_ZOOM_TYPE
{
	ZOOM_TYPE_EXPECTMULTIPLE =0,     // �̶����������䱶
	ZOOM_TYPE_IVSADAPTIVE,           // ���������豸�������Ӧ�䱶
	ZOOM_TYPE_MULTIPLEADAPTIVE,      // ����Ӧ�䱶
	ZOOM_TYPE_NUM
}CFG_ZOOM_TYPE;

// ����ģʽ
typedef enum tagCFG_TRACKING_MODE
{
    TRACKING_MODE_ALARM=0,        // ��������
	TRACKING_MODE_MANUALOBJECT,   // �ֶ�ѡ���������
	TRACKING_MODE_AUTOOBJECT,     // �Զ�ѡ���������
	TRACKING_MODE_SELECTPOINT,    // �������
	TRACKING_MODE_MIX,            // ��ϸ���(�������ָ���ģʽͬʱ֧��)
	TRACKING_MODE_SLAVESELF,      // ����������ƣ���Ҫ�����û���������ƣ�
	TRACKING_MODE_NUM
}CFG_TRACKING_MODE;


// ����ʽ������ȫ�����û����ṹ��
typedef struct tagCFG_MASTERSLAVE_GLOBAL_INFO
{
	int						nStructSize;
	float					fMaxZoom;						// ���䱶����
	float					fMinZoom;						// ��С�䱶����
	float					fExpectMultiple;				// ������������׼����������С�䱶����<��������<���䱶����
	float					fPollTrackTime;					// ��ѯ����ʱ������λ���룻>0.0
	float					fPointTrackTime;				// �������ʱ��,��λ���룻>0.0�ڱ������١��Զ�ѡ��������١���ϸ���ģʽ����Ч
    float					fObjectTrackTime;				// �ֶ�ѡ���������ʱ��, ��λ���룻>0.0�ڱ������١��Զ�ѡ��������١���ϸ���ģʽ����Ч
	float					fExpectAngleX;					// ����������Ӧ����Ƕ�x(ˮƽ)
    float					fExpectAngleY;					// ����������Ӧ����Ƕ�y(��ֱ)
	CFG_SIZE				stTargetFaceSize;				// ����ߴ�(��λ������), ����豸������������й�
	float					fMinFocus;						// ��С����(��λ������)
	float					fMaxFocus;						// ��󽹾�(��λ������)
	CFG_ZOOM_TYPE			emZoomType;						// �䱶����
	CFG_TRACKING_MODE		emTrackingMode;					// ����ģʽ
	CFG_CAMERA_TYPE_INFO	stCameraInfo;					// ǹʽ�����
	CFG_CAMERA_TYPE_INFO	stDomeInfo;						// ��ʽ�����
	int						nTrackZoomLevel;				// ���ٱ����ȼ�	-5<= TrackZoomLevel <=5 0��ʾ��Ĭ���㷨��ʽ
	BOOL					bReturnPtzPreset;				// TRUE�����ٺ󷵻�Ԥ�õ� , FALSE�����ٺ󲻷���Ԥ�õ�
}CFG_MASTERSLAVE_GLOBAL_INFO;
	
// ��ȡ����ʽ�豸������
typedef struct tagCFG_CAP_MASTERSLAVE_INFO
{
	int                     nStructSize;
	BYTE                    byTrackingMode[TRACKING_MODE_NUM]; // �����±��ʾCFG_TRACKING_MODEö�����Ӧģʽ��1��ʾ֧��
	CFG_CAMERA_TYPE_INFO	stCameraInfo;  // ǹʽ�����
	CFG_CAMERA_TYPE_INFO	stDomeInfo;	   // ��ʽ�����
}CFG_CAP_MASTERSLAVE_INFO;


// ��ȡ��������������������
typedef struct tagCFG_CAP_EVENTHANDLER_INFO
{
	BOOL				bTimeSectionEnable;                                      // 
	BOOL				bRecordEnable;                                           // �Ƿ�֧��¼��
	BOOL				bAlarmOutEnable;                                         // �Ƿ�֧�ֱ������
	BOOL				bPtzLinkEnable;                                          // �Ƿ�֧�ֱ������
	BOOL				bSnapshotEnable;                                         // �Ƿ�֧�ֿ���
	BOOL				bMailEnable;                                             // �Ƿ�֧�ַ����ʼ�
	BOOL				bBeepEnable;                                             // �Ƿ�֧�ַ���
	BOOL				bDejitterEnable;                                         // �Ƿ�֧��ȥ����
	BOOL                bTipEnable;                                              // �Ƿ�֧�ֱ�����Ϣ����ʾ
	BOOL                bMonitorTourEnable;                                      // �Ƿ�֧����ѯ��������
}CFG_CAP_EVENTHANDLER_INFO;

//----------------------------------��Ƶ��������------------------------------------------
#define DH_MAX_INMETERING_REGION_NUM 8

typedef struct tagVIDEO_INMETERING_INFO_CHANNEL
{
	// ����
	bool            bRegion;
	bool            bMode;
	BYTE			bReserved1[2];					         // �����ֶ�1
	
	int				nRegionNum;                                 // ����������
	CFG_RECT    	stuRegions[DH_MAX_INMETERING_REGION_NUM];   // �������, �ֲ����ʹ�ã�֧�ֶ���������ʹ�����������ϵ��ȡֵ��Ϊ0~8191
	BYTE  			byMode;				                     // ���ģʽ,0:ƽ�����,1:�ֲ����
	BYTE  			bReserved2[3];				             // �����ֶ�2
	BYTE			bReserved3[32];					         // �����ֶ�3
}VIDEO_INMETERING_INFO_CHANNEL;

// �������(CFG_CMD_VIDEO_INMETERING)��һ�����飬ÿ����Ƶ����ͨ��һ������
typedef struct tagCFG_VIDEO_INMETERING_INFO
{
	int				nChannelNum; // ͨ����
	VIDEO_INMETERING_INFO_CHANNEL	stuMeteringMode[MAX_VIDEO_CHANNEL_NUM]; // ÿ��ͨ���Ĳ����Ϣ���±��Ӧͨ����
}CFG_VIDEO_INMETERING_INFO;

// ��Ƶ����������(CFG_CAP_CMD_VIDEOINPUT)����
typedef struct tagCFG_CAP_VIDEOINPUT_INFO
{
	int				nMeteringRegionCount;                   // ������������
	BOOL            bFishEye;                               // �Ƿ�֧������
	BOOL			bElectricFocus;							// �Ƿ�֧�ֵ綯����
	DWORD			dwExposureMode;							// ֧�ֵ��Զ��ع�ģʽ����  �ӵ�λ����λ���α�ʾ��0-�Զ��ع⣬1-�����������棩���ȣ�2-����Ӱ�����ţ����ȣ� 3-50HZ����˸��4-60HZ����˸
	int             nWideDynamicRange;						// �Ƿ�֧�ֿ�̬ 0-��֧�֣�1-֧�����ֿ�̬
	int			    nGlareInhibition;						// �Ƿ�֧��ǿ������ 0-��֧�֣�1-֧��
}CFG_CAP_VIDEOINPUT_INFO;

// ����ͳ�Ʊ�����Ϣ����
typedef struct tagCFG_TRAFFIC_FLOWSTAT_ALARM_INFO
{
	bool                            bEnable;                              // �Ƿ�ʹ��
	int                             nPeriod;                              // ͳ�����ڣ���λ������
	int                             nLimit;                               // ͳ�������ڳ����������ޣ���λ����
	int                             nRestore;                             // ͳ�������ڱ����ָ�����������λ���� 
    int                             nDelay;                               // ��⵽������������ʼ�ϱ���ʱ��, ��λ:��,��Χ1~65535
	int                             nInterval;                            // �������ʱ��, ��λ:��, ��Χ1~65535
	int                             nReportTimes;                         // �ϱ�����,1~255
	CFG_TIME_SECTION                stCurrentTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX]; // ��ǰ�ƻ�ʱ���
	CFG_ALARM_MSG_HANDLE            stuEventHandler;					  // ��������
}CFG_TRAFFIC_FLOWSTAT_ALARM_INFO;

typedef struct tagCFG_TRAFFIC_FLOWSTAT_INFO_CHNL
{
	// ����
	bool	                		 abEnable;

	bool			                 bEnable;								// �Ƿ�ʹ��
	CFG_TRAFFIC_FLOWSTAT_ALARM_INFO  stuAlarmUpperInfo;                     // �������߲���
	CFG_TRAFFIC_FLOWSTAT_ALARM_INFO  stuAlarmLowInfo;                       // �������߲���
    int                              nDetectRegionPoint;                    // �����������
    CFG_POLYGON                      stuDetectRegion[MAX_POLYGON_NUM];      // �������
	char                             szName[MAX_NAME_LEN];                  // ��ǰ�����������ƣ���ͬ����������
	int								 nPresetID;								// ��̨����Ԥ�õ���(�������Ч)
}CFG_TRAFFIC_FLOWSTAT_INFO_LANE;

// ��ͨ����ͳ������(CFG_CMD_TRAFFIC_FLOWSTAT)
typedef struct tagCFG_TRAFFIC_FLOWSTAT_INFO
{
	// ����
	bool							abPeriod;
	BYTE							bReserved1[3];						        // �����ֶ�1

	int								nPeriod;									// ͳ�����ڣ���λ����
	int								nLaneNum;									// ������
	CFG_TRAFFIC_FLOWSTAT_INFO_LANE	stuTrafficFlowstat[MAX_LANE_NUM];			// ÿ���������������ã��±��Ӧ������
	DWORD                           dwLaneExtraMaxNum;                           // �������������ֵ(���������ڴ�),�ೡ��Ӧ�ö���ĳ�����Ϣ��Ҫ
	DWORD                           dwLaneExtraRetNum;                           // �ೡ��Ӧ�ö���ĳ�����ʵ�ʸ���
	CFG_TRAFFIC_FLOWSTAT_INFO_LANE  *pstuTrafficFlowstat;                       // �ೡ���ĳ�����, stuTrafficFlowstat����Ų����ĳ���������������棬��Ŵӳ���MAX_LANE_NUM+1��ʼ
}CFG_TRAFFIC_FLOWSTAT_INFO;

//-----------------------------------��Ƶ����ǰ��ѡ��-------------------------------------------

// ��Ƶ����ҹ����������ѡ������Ϲ��߽ϰ�ʱ�Զ��л���ҹ������ò���
typedef struct tagCFG_VIDEO_IN_NIGHT_OPTIONS
{
	BYTE				bySwitchMode;			// 0-���л�������ʹ�ð������ã�1-���������л���2-����ʱ���л���3-���л�������ʹ��ҹ�����ã�4-ʹ����ͨ���ã� 
	BYTE				byProfile;				// ��ǰʹ�õ������ļ�.
												// 0-����
												// 1-����
												// 2-Normal
												// 0��1,2��Ϊ��ʱ���ã�ʹͼ����Ч�����ڲ鿴ͼ�����Ч���������ȷ�����뿪ҳ�治�������豸��
												///3-����ʱ���ã����ȷ���󱣴����豸����SwitchMode���ʹ�ã�����SwitchMode����������Ч�����á�
												// SwitchMode=0��Profile=3�����ð������õ��豸��
												// SwitchMode=1��Profile=3��������ҹ�����õ��豸
												// SwitchMode=2��Profile=3�������ճ�����ʱ����л�������ʱ���ʹ�ð������ã�ҹ��ʱ���ʹ��ҹ�����ã��������豸��
												// SwitchMode=4��Profile=3��ʹ����ͨ���ã��������豸
	BYTE				byBrightnessThreshold ;	// ������ֵ 0~100	
	BYTE				bySunriseHour;			// �����ճ�������ʱ�䣬����֮���ճ�֮ǰ��������ҹ����������á�
	BYTE				bySunriseMinute;		// 00:00:00 ~ 23:59:59
	BYTE				bySunriseSecond;
	BYTE				bySunsetHour;
	BYTE				bySunsetMinute;
	BYTE				bySunsetSecond;  
	BYTE				byGainRed;				// ��ɫ������ڣ���ƽ��Ϊ"Custom"ģʽ����Ч 0~100
	BYTE				byGainBlue;				// ��ɫ������ڣ���ƽ��Ϊ"Custom"ģʽ����Ч 0~100
	BYTE				byGainGreen;			// ��ɫ������ڣ���ƽ��Ϊ"Custom"ģʽ����Ч 0~100
	BYTE				byExposure;				// �ع�ģʽ��ȡֵ��Χȡ�����豸��������0-�Զ��ع⣬1-�ع�ȼ�1��2-�ع�ȼ�2��n-1����ع�ȼ��� n��ʱ�������޵��Զ��ع� n+1�Զ���ʱ���ֶ��ع� (n==byExposureEn��
	float				fExposureValue1;		// �Զ��ع�ʱ�����޻����ֶ��ع��Զ���ʱ��,����Ϊ��λ��ȡֵ0.1ms~80ms
	float				fExposureValue2;		// �Զ��ع�ʱ������,����Ϊ��λ��ȡֵ0.1ms~80ms	
	BYTE				byWhiteBalance ;		// ��ƽ��, 0-"Disable", 1-"Auto", 2-"Custom", 3-"Sunny", 4-"Cloudy", 5-"Home", 6-"Office", 7-"Night", 8-"HighColorTemperature", 9-"LowColorTemperature", 10-"AutoColorTemperature", 11-"CustomColorTemperature"
	BYTE				byGain;					// 0~100, GainAutoΪtrueʱ��ʾ�Զ���������ޣ������ʾ�̶�������ֵ
	bool				bGainAuto;				// �Զ�����
	bool				bIrisAuto;				// �Զ���Ȧ
	float               fExternalSyncPhase;     // ��ͬ������λ���� 0~360
	BYTE				byGainMin;				// ��������
	BYTE				byGainMax;				// ��������
	BYTE				byBacklight;			// ���ⲹ����ȡֵ��Χȡ�����豸��������0-�ر�1-����2-ָ�����򱳹ⲹ��
	BYTE				byAntiFlicker;			// ����˸ģʽ 0-Outdoor 1-50Hz����˸ 2-60Hz����˸
	BYTE				byDayNightColor;		// ��/ҹģʽ��0-���ǲ�ɫ��1-���������Զ��л���2-���Ǻڰ�
	BYTE				byExposureMode;         // �ع�ģʽ���� �ع�ȼ�Ϊ�Զ��ع�ʱ��Ч��ȡֵ��0-Ĭ���Զ���1-�������ȣ�2-��������
	BYTE				byRotate90;				// 0-����ת��1-˳ʱ��90�㣬2-��ʱ��90��
	bool				bMirror;				// ����
	BYTE                byWideDynamicRange;     // ��ֵ̬ 0-�رգ�1~100-Ϊ��ʵ��Χֵ
	BYTE                byGlareInhibition;		// ǿ������ 0-�رգ� 1~100Ϊ��Χֵ
	CFG_RECT			stuBacklightRegion;     // ���ⲹ������
	BYTE                byFocusMode;            // 0-�رգ�1-�����۽���2-�Զ��۽�
	bool				bFlip;					// ��ת
	BYTE				reserved[74];			// ����
} CFG_VIDEO_IN_NIGHT_OPTIONS;

typedef struct tagCFG_VIDEO_IN_NORMAL_OPTIONS
{
	BYTE				byGainRed;				// ��ɫ������ڣ���ƽ��Ϊ"Custom"ģʽ����Ч 0~100
	BYTE				byGainBlue;				// ��ɫ������ڣ���ƽ��Ϊ"Custom"ģʽ����Ч 0~100
	BYTE				byGainGreen;			// ��ɫ������ڣ���ƽ��Ϊ"Custom"ģʽ����Ч 0~100
	BYTE				byExposure;				// �ع�ģʽ��ȡֵ��Χȡ�����豸��������0-�Զ��ع⣬1-�ع�ȼ�1��2-�ع�ȼ�2��n-1����ع�ȼ��� n��ʱ�������޵��Զ��ع� n+1�Զ���ʱ���ֶ��ع� (n==byExposureEn��
	float				fExposureValue1;		// �Զ��ع�ʱ�����޻����ֶ��ع��Զ���ʱ��,����Ϊ��λ��ȡֵ0.1ms~80ms
	float				fExposureValue2;		// �Զ��ع�ʱ������,����Ϊ��λ��ȡֵ0.1ms~80ms	
	BYTE				byWhiteBalance ;		// ��ƽ��, 0-"Disable", 1-"Auto", 2-"Custom", 3-"Sunny", 4-"Cloudy", 5-"Home", 6-"Office", 7-"Night", 8-"HighColorTemperature", 9-"LowColorTemperature", 10-"AutoColorTemperature", 11-"CustomColorTemperature"
	BYTE				byGain;					// 0~100, GainAutoΪtrueʱ��ʾ�Զ���������ޣ������ʾ�̶�������ֵ
	bool				bGainAuto;				// �Զ�����
	bool				bIrisAuto;				// �Զ���Ȧ
	float               fExternalSyncPhase;     // ��ͬ������λ���� 0~360
	BYTE				byGainMin;				// ��������
	BYTE				byGainMax;				// ��������
	BYTE				byBacklight;			// ���ⲹ����ȡֵ��Χȡ�����豸��������0-�ر�1-����2-ָ�����򱳹ⲹ��
	BYTE				byAntiFlicker;			// ����˸ģʽ 0-Outdoor 1-50Hz����˸ 2-60Hz����˸
	BYTE				byDayNightColor;		// ��/ҹģʽ��0-���ǲ�ɫ��1-���������Զ��л���2-���Ǻڰ�
	BYTE				byExposureMode;         // �ع�ģʽ���� �ع�ȼ�Ϊ�Զ��ع�ʱ��Ч��ȡֵ��0-Ĭ���Զ���1-�������ȣ�2-��������
	BYTE				byRotate90;				// 0-����ת��1-˳ʱ��90�㣬2-��ʱ��90��
	bool				bMirror;				// ����
	BYTE                byWideDynamicRange;     // ��ֵ̬ 0-�رգ�1~100-Ϊ��ʵ��Χֵ
	BYTE                byGlareInhibition;		// ǿ������ 0-�رգ� 1~100Ϊ��Χֵ
	CFG_RECT			stuBacklightRegion;     // ���ⲹ������
	BYTE                byFocusMode;            // 0-�رգ�1-�����۽���2-�Զ��۽�
	bool				bFlip;					// ��ת
	BYTE				reserved[74];			// ����
}CFG_VIDEO_IN_NORMAL_OPTIONS;



// ���������
typedef struct tagCFG_FLASH_CONTROL
{
	BYTE				byMode;					// ����ģʽ��0-��ֹ���⣬1-ʼ�����⣬2-�Զ�����
	BYTE				byValue;				// ����ֵ, 0-0us, 1-64us, 2-128us, 3-192...15-960us
	BYTE				byPole;					// ����ģʽ, 0-�͵�ƽ 1-�ߵ�ƽ 2-������ 3-�½���
	BYTE                byPreValue;				// ����Ԥ��ֵ  ����0~100
	BYTE				byDutyCycle;			// ռ�ձ�, 0~100
	BYTE				byFreqMultiple;			// ��Ƶ, 0~10
	BYTE				reserved[122];			// ����
}CFG_FLASH_CONTROL;

// ץ�Ĳ�����������
typedef struct tagCFG_VIDEO_IN_SNAPSHOT_OPTIONS
{
	BYTE				byGainRed;				// ��ɫ������ڣ���ƽ��Ϊ"Custom"ģʽ����Ч 0~100
	BYTE				byGainBlue;				// ��ɫ������ڣ���ƽ��Ϊ"Custom"ģʽ����Ч 0~100
	BYTE				byGainGreen;			// ��ɫ������ڣ���ƽ��Ϊ"Custom"ģʽ����Ч 0~100
	BYTE				byExposure;				// �ع�ģʽ��ȡֵ��Χȡ�����豸��������0-�Զ��ع⣬1-�ع�ȼ�1��2-�ع�ȼ�2��n-1����ع�ȼ��� n��ʱ�������޵��Զ��ع� n+1�Զ���ʱ���ֶ��ع� (n==byExposureEn��
	float				fExposureValue1;		// �Զ��ع�ʱ�����޻����ֶ��ع��Զ���ʱ��,����Ϊ��λ��ȡֵ0.1ms~80ms
	float				fExposureValue2;		// �Զ��ع�ʱ������,����Ϊ��λ��ȡֵ0.1ms~80ms	
	BYTE				byWhiteBalance;			// ��ƽ��, 0-"Disable", 1-"Auto", 2-"Custom", 3-"Sunny", 4-"Cloudy", 5-"Home", 6-"Office", 7-"Night", 8-"HighColorTemperature", 9-"LowColorTemperature", 10-"AutoColorTemperature", 11-"CustomColorTemperature"
	BYTE				byColorTemperature;		// ɫ�µȼ�, ��ƽ��Ϊ"CustomColorTemperature"ģʽ����Ч
	bool				bGainAuto;				// �Զ�����
	BYTE				byGain;					// �������, GainAutoΪtrueʱ��ʾ�Զ���������ޣ������ʾ�̶�������ֵ
	BYTE				reversed[112];			// ����
} CFG_VIDEO_IN_SNAPSHOT_OPTIONS;

// ���۾�ͷ����
typedef struct tagCFG_FISH_EYE
{
    CFG_POLYGON         stuCenterPoint;         // ����Բ������,��Χ[0,8192]
	unsigned int        nRadius;                // ���۰뾶��С,��Χ[0,8192]
	float               fDirection;             // ��ͷ��ת����,��ת�Ƕ�[0,360.0]
	BYTE                byPlaceHolder;          // ��ͷ��װ��ʽ	1��װ��2��װ��3��װ,Ĭ��1
	BYTE				reversed[31];			// ����
}CFG_FISH_EYE;
// ��Ƶ����ǰ��ѡ��
typedef struct tagCFG_VIDEO_IN_OPTIONS
{
	BYTE				byBacklight;			// ���ⲹ����ȡֵ��Χȡ�����豸��������0-�ر�1-����2-ָ�����򱳹ⲹ��
	BYTE				byDayNightColor;		// ��/ҹģʽ��0-���ǲ�ɫ��1-���������Զ��л���2-���Ǻڰ�
	BYTE				byWhiteBalance;			// ��ƽ��, 0-"Disable", 1-"Auto", 2-"Custom", 3-"Sunny", 4-"Cloudy", 5-"Home", 6-"Office", 7-"Night", 8-"HighColorTemperature", 9-"LowColorTemperature", 10-"AutoColorTemperature", 11-"CustomColorTemperature"
	BYTE				byColorTemperature;		// ɫ�µȼ�, ��ƽ��Ϊ"CustomColorTemperature"ģʽ����Ч
	bool				bMirror;				// ����
	bool				bFlip;					// ��ת
	bool				bIrisAuto;				// �Զ���Ȧ
	bool				bInfraRed;				// ���ݻ������Զ��������ⲹ����	
	BYTE				byGainRed;				// ��ɫ������ڣ���ƽ��Ϊ"Custom"ģʽ����Ч 0~100
	BYTE				byGainBlue;				// ��ɫ������ڣ���ƽ��Ϊ"Custom"ģʽ����Ч 0~100
	BYTE				byGainGreen;			// ��ɫ������ڣ���ƽ��Ϊ"Custom"ģʽ����Ч 0~100
	BYTE				byExposure;				// �ع�ģʽ��ȡֵ��Χȡ�����豸��������0-�Զ��ع⣬1-�ع�ȼ�1��2-�ع�ȼ�2��n-1����ع�ȼ��� n��ʱ�������޵��Զ��ع� n+1�Զ���ʱ���ֶ��ع� (n==byExposureEn��
	float				fExposureValue1;		// �Զ��ع�ʱ�����޻����ֶ��ع��Զ���ʱ��,����Ϊ��λ��ȡֵ0.1ms~80ms
	float				fExposureValue2;		// �Զ��ع�ʱ������,����Ϊ��λ��ȡֵ0.1ms~80ms	
	bool				bGainAuto;				// �Զ�����
	BYTE				byGain;					// �������, GainAutoΪtrueʱ��ʾ�Զ���������ޣ������ʾ�̶�������ֵ
	BYTE				bySignalFormat;			// �źŸ�ʽ, 0-Inside(�ڲ�����) 1-BT656 2-720p 3-1080p  4-1080i  5-1080sF
	BYTE				byRotate90;				// 0-����ת��1-˳ʱ��90�㣬2-��ʱ��90��	
	float               fExternalSyncPhase;		// ��ͬ������λ���� 0~360	
	BYTE                byExternalSync;			// �ⲿͬ���ź�����,0-�ڲ�ͬ�� 1-�ⲿͬ��
	BYTE				reserved0;				// ����
	BYTE				byDoubleExposure;		// ˫����, 0-�����ã�1-˫����ȫ֡�ʣ���ͼ�����Ƶֻ�п��Ų�����ͬ��2-˫���Ű�֡�ʣ���ͼ�����Ƶ���ż���ƽ���������ͬ
	BYTE                byWideDynamicRange;     // ��ֵ̬
	CFG_VIDEO_IN_NIGHT_OPTIONS stuNightOptions;	// ҹ�����
	CFG_FLASH_CONTROL	stuFlash;				// ���������
	CFG_VIDEO_IN_SNAPSHOT_OPTIONS stuSnapshot;	// ץ�Ĳ���, ˫����ʱ��Ч
	CFG_FISH_EYE        stuFishEye;             // ���۾�ͷ
	BYTE                byFocusMode;            // 0-�رգ�1-�����۽���2-�Զ��۽�
	BYTE                reserved[28];           // ����
	BYTE				byGainMin;				// ��������
	BYTE				byGainMax;				// ��������
	BYTE				byAntiFlicker;			// ����˸ģʽ 0-Outdoor 1-50Hz����˸ 2-60Hz����˸
	BYTE				byExposureMode;         // �ع�ģʽ���� �ع�ȼ�Ϊ�Զ��ع�ʱ��Ч��ȡֵ��0-Ĭ���Զ���1-�������ȣ�2-��������,4-�ֶ�
	BYTE                byGlareInhibition;		// ǿ������ 0-�رգ� 1~100Ϊ��Χֵ
	CFG_RECT			stuBacklightRegion;     // ���ⲹ������            
	CFG_VIDEO_IN_NORMAL_OPTIONS stuNormalOptions;//��ͨ����
} CFG_VIDEO_IN_OPTIONS;

// RTSP�������������������ýṹ��
typedef struct tagCFG_MULTICAST_INFO
{
	int  nStructSize;
	bool abStreamType;
	BYTE byReserved[3];
	BOOL bEnable;      // �Ƿ�ʹ��
	char szMulticastAddr[MAX_ADDRESS_LEN]; //�鲥��ַ
	int  nPort;        //�鲥�˿�
	char szLocalAddr[MAX_ADDRESS_LEN];   //������ַ�������鲥ָ����ϸ����
	int  nChannelID;   // ͨ����
	int  nStreamType;  // �������� 0-������, 1-������1,2-������2,3-������3
}CFG_MULTICAST_INFO;

typedef struct tagCFG_MULTICASTS_INFO
{
	int nStructSize;
	CFG_MULTICAST_INFO stuMultiInfo[MAX_CHAN_NUM]; //����鲥����
	int nCount;                                    //��Ч�������
}CFG_MULTICASTS_INFO;

typedef struct tagCFG_RTSP_INFO_IN
{
	int         nStructSize;
	BOOL        bEnable;       // ���������Ƿ�ʹ��
	int         nPort;         // RTSP����˿�
	int         nRtpStartPort; // RTP��ʼ�˿�
	int         nRtpEndPort;   // RTP�����˿�
	BOOL        bHttpEnable;   // RtspOverHttpʹ��
	int         nHttpPort;     // RtspOverHttp�˿�
}CFG_RTSP_INFO_IN;

typedef struct tagCFG_RTSP_INFO_OUT
{
	int         nStructSize;
	BOOL        bEnable;       // ���������Ƿ�ʹ��
	int         nPort;         // RTSP����˿�
	int         nRtpStartPort; // RTP��ʼ�˿�
	int         nRtpEndPort;   // RTP�����˿�
	BOOL        bHttpEnable;   // RtspOverHttpʹ��
	int         nHttpPort;     // RtspOverHttp�˿�
}CFG_RTSP_INFO_OUT;

typedef struct tagCFG_MULTICASTS_INFO_IN
{
	int                  nStructSize;
	CFG_MULTICAST_INFO   *pTSMulticast;   //TS���鲥����
	int                  nTSCount;        //��ЧTS�������
	CFG_MULTICAST_INFO   *pRTPMulticast;  //RTP���鲥����
	int                  nRTPCount;       //��ЧRTP�������
	CFG_MULTICAST_INFO   *pDHIIMulticast; //DHII���鲥����
	int                  nDHIICount;      //��ЧDHII�������
}CFG_MULTICASTS_INFO_IN;

typedef struct tagCFG_MULTICASTS_INFO_OUT
{
	int                  nStructSize;
	CFG_MULTICASTS_INFO  stuTSMulticast;   //TS���鲥����
	CFG_MULTICASTS_INFO  stuRTPMulticast;  //RTP���鲥����
	CFG_MULTICASTS_INFO  stuDHIIMulticast; //DHII���鲥����
}CFG_MULTICASTS_INFO_OUT;

typedef struct tagCFG_ACTIVEUSER_INFO
{
	int nStructSize;
	int nUserID;                         //��û�ID��һ���ǻỰID
	char szUser[MAX_USERNAME_LEN];       // �û���
	char szGroupName[MAX_USERNAME_LEN];  // �û���������
	int  nGroupLevel;                    // �û�������ȼ�
	char szClientType[MAX_USERNAME_LEN]; // �ͻ�������
	char szClientAddr[MAX_ADDRESS_LEN];  // �ͻ���IP��ַ
	CFG_NET_TIME  stuLoginTime;              // �û�����ʱ��
}CFG_ACTIVEUSER_INFO;

typedef struct tagCFG_ACTIVEALLUSER_INFO
{
	int nStructSize;
	int nCount;                                                //��Ч�������
	CFG_ACTIVEUSER_INFO stuActiveUserInfo[MAX_ACTIVEUSER_NUM]; //  ����û��б�
}CFG_ACTIVEALLUSER_INFO;

typedef struct tagCFG_NET_TIME_EX
{
	DWORD				dwYear;					// ��
	DWORD				dwMonth;				// ��
	DWORD				dwDay;					// ��
	DWORD				dwHour;					// ʱ
	DWORD				dwMinute;				// ��
	DWORD				dwSecond;				// ��
	DWORD               dwMillisecond;          // ����
	DWORD               dwReserved[2];          // �����ֶ�
} CFG_NET_TIME_EX;

//��ȡ��Ƶͳ��ժҪ��Ϣ�ṹ��
typedef struct tagCFG_CFG_VIDEOSATA_SUMMARY_INFO
{
	int         nStructSize;
	int         nChannelID;               //ͳ��ͨ����
	char        szRuleName[MAX_NAME_LEN]; //��������
	CFG_NET_TIME_EX stuStatTime;          // ͳ��ʱ�䣬ת����UTC
	int         nEnteredTotal;            //�����ܼ�
	int         nEnteredToday;            //��������ܼ�
	int         nEnteredMonth;            //���½����ܼ�
	int         nEnteredYear;             //��������ܼ�
	int         nEnteredDaily;            //ÿ���������ܼ�
	int         nExitedTotal;             //��ȥ�ܼ�
	int         nExitedToday;             //�����ȥ�ܼ�
	int         nExitedMonth;             //���³�ȥ�ܼ�
	int         nExitedYear;              //�����ȥ�ܼ�
	int         nExitedDaily;             //ÿ������ȥ�ܼ�
	int         nAvgTotal;                //ƽ�����б���ͳ��(��ȥ��ֵ)
	int         nAvgToday;                //ƽ�����챣��ͳ��
	int         nAvgMonth;                //ƽ�����±���ͳ��
	int         nAvgYear;                 //ƽ�����걣��ͳ��         
	int         nMaxTotal;                //������б���ͳ��(��ȥ��ֵ)
	int         nMaxToday;                //�����챣��ͳ��
	int         nMaxMonth;                //����±���ͳ��
	int         nMaxYear;                 //�����걣��ͳ��
}CFG_VIDEOSATA_SUMMARY_INFO;

// ���������ٽṹ��
typedef struct tagCFG_SINGLESCENE
{
	int                 nStructSize;
	int					nSingleAlarmDelay;					//������ʱ:1~600��
	int					nSinglePresetID;					//Ԥ�õ��ţ�1~255(-1�����޶���)
}CFG_SINGLESCENE;
// Ѳ��·���ṹ��
typedef struct tagCFG_TOURPATH
{
	int                 nStructSize;
	int					nMultiPresetID;						//����Ԥ�õ���
	int					nMultiDuration;						//ͣ��ʱ��30~900��
}CFG_TOURPATH;
// �ೡ�����ٽṹ��
typedef struct tagCFG_MULTISCENE
{
	int                 nStructSize;
	int					nMultiAlarmDelay;					    //������ʱ��1~600��
	int					nTourPathCount;						    //Ѳ��·������
	CFG_TOURPATH	    stuMultiTourPath[MAX_TRACKSCENE_NUM];   //Ѳ��·��
}CFG_MULTISCENE;
// ȫ�������ٽṹ��
typedef struct tagCFG_FULLSCENE
{
	int                 nStructSize;
	int					nFullAlarmDelay;					//������ʱ��1~600��
	int					nFullPresetID;						//Ԥ�õ���,ȫ������Ԥ�õ�̶�Ϊ0���û���������
	int					nFullDuration;						//ȫ�����ٳ���ʱ��,0��: һֱ����;1~300:���ٳ���ʱ��
}CFG_FULLSCENE;
// ��λ�����ṹ��
typedef struct tag_CFG_POSITION_LIMIT
{
	int                 nStructSize;
	BOOL				bEnable;							//������λ����
	int					nType;								//��λֵ������ʽ��0: ����̨����λ���ò���ʱ�������ݣ���λֵ����������
	                                                        //1����λֵ�ýǶ�(��λ0.1��)��ʾ���ø�ֵ���øó�������λ
	int					nTop;								//����λֵ, 0~900:����λ0.1�ȣ�
	int					nBottom;							//����λֵ��0~900:����λ0.1�ȣ�
	int					nLeft;								//����λֵ��0~3600:����λ0.1�ȣ�
	int					nRight;								//����λֵ��0~3600:����λ0.1�ȣ�
}CFG_POSITION_LIMIT;
// ������Ϣ�ṹ��
typedef struct tagCFG_SCENE
{
	int                    nStructSize;
	int					   nScenePresetID;						//����Ԥ�õ㣬1~255��ͨ��Ԥ�õ��Ź�������Ӧ������
	char			       szSceneName[MAX_NAME_LEN];		    //������
	int					   nSceneDuration;						//���ٳ���ʱ��:0��: һֱ����;1~300:���ٳ���ʱ��
	double		           dSceneMaxZoom;					    //��һ����0~1;Ϊnull��ʾʹ��ȫ��MaxZoomֵ
	CFG_POSITION_LIMIT	   stuPositionLimit;                    //��λ����
}CFG_SCENE;
// ���ܸ��ٳ������ýṹ��
typedef struct tagCFG_INTELLITRACKSCENE_INFO
{
	int               nStructSize;
	BOOL		      bEnableTrack;				         //�������ܸ���
	int				  nTrackType;						 //0,�������٣�1���ֶ�����
	double			  dMaxZoom;							 //�����ٱ��ʣ���һ����0~1��Ϊnull��ʾ������
	char			  szCategory[MAX_NAME_LEN];		     //��ǰ�������ͣ�"SingleScene"�����������٣�"MultiScene"���ೡ�����٣�"FullScene"��ȫ������
	CFG_SINGLESCENE   stuSingleTrack;					 //����������
	CFG_MULTISCENE	  stuMultiTrack;	                 //�ೡ������
	CFG_FULLSCENE	  stuFullTrack;						 //ȫ������
	int				  nSceneCount;						 //֧�ֵĳ�������
	CFG_SCENE		  stuScene[MAX_TRACKSCENE_NUM];	     //�����б�
}CFG_INTELLITRACKSCENE_INFO;

/************************����״̬����**********************************/

// ץ��ģʽ
typedef enum tagCFG_TRAFFIC_SNAP_MODE
{
	TRAFFIC_SNAP_MODE_AUTO = 0,				       // �Զ�ץ��
	TRAFFIC_SNAP_MODE_COIL,				           // ��Ȧץ��
	TRAFFIC_SNAP_MODE_COIL_PICANALYSIS,		       // ��Ȧץ��, ͼƬ����
	TRAFFIC_SNAP_MODE_STREAM,				       // ��Ƶץ��
	TRAFFIC_SNAP_MODE_STREAM_IDENTIFY,		       // ��Ƶץ��, ����ʶ��
	TRAFFIC_SNAP_MODE_MIX_IDENTIFY,		           // ���ץ��, ����ʶ��
} CFG_TRAFFIC_SNAP_MODE;

// �豸����״̬��Ϣ
typedef struct tagCFG_TRAFFIC_WORKSTATE_INFO
{
	int                     nChannelID;  // ͨ����
	CFG_TRAFFIC_SNAP_MODE   emSnapMode;  // ץ��ģʽ
	int                     nMatchMode;  // ץ��ƥ��ģʽ: 0-��ʵʱƥ�䷽ʽ���ȱ�����ץ�ģ�ץ��֡���Ǳ���֡;  1-ʵʱƥ��ģʽ������֡��ץ��֡��ͬһ֡ 
}CFG_TRAFFIC_WORKSTATE_INFO;

// ��ȡ�豸����״̬�Ƿ�����(CFG_CAP_CMD_DEVICE_STATE ��Ӧ�Ľṹ��)
typedef struct tagCFG_TRAFFIC_DEVICE_STATUS
{
	char                 szType[MAX_PATH];          // �豸����	֧�֣�"Radar","Detector","SigDetector"
	char                 szSerialNo[MAX_PATH];      // �豸���
	char                 szVendor[MAX_PATH];        // ��������
	int                  nWokingState;              // ����״̬	0-����,1-��������
}CFG_TRAFFIC_DEVICE_STATUS;

typedef struct tagCFG_CAP_TRAFFIC_DEVICE_STATUS
{
	int                        nStatus;             // stuStatus ʵ�ʸ���
	CFG_TRAFFIC_DEVICE_STATUS  stuStatus[MAX_STATUS_NUM];
}CFG_CAP_TRAFFIC_DEVICE_STATUS;

/************************¼����������**********************************/

// �洢����Ϣ
typedef struct tagCFG_STORAGEGROUP_INFO
{
	char                  szGroupName[MAX_STORAGEGROUPNAME_LEN];   // �洢������
	BYTE*                 byDisks;                                 // ���������Ż�����
	int                   nBufSize;                                // ������byDisks�ĳ���
	int                   nDiskNum;                                // �洢���еĴ�����
	int                   nGroupIndex;                             // �洢�����(1~���Ӳ����)
}CFG_STORAGEGROUP_INFO;

// ¼��-�洢�� ��Ӧ��Ϣ
typedef struct tagCFG_RECORDTOGROUP_INFO
{
	int                   nChannelID;                               // ͨ����
	BOOL                  bEnable;                                  // ʹ��                       
	char                  szGroupName[MAX_STORAGEGROUPNAME_LEN];    // �洢������, ֻ��
	int                   nGroupIndex;                              // �洢�����(1~�������, 0���ʾ�޶�Ӧ����)��ͨ���˲�����CFG_STORAGE_GROUP_INFO����
}CFG_RECORDTOGROUP_INFO;

enum EM_STORAGEPOINT_TYPE
{
       	EM_STORAGE_TIMINGRECORD,        //��ʱ¼��洢������
		EM_STORAGE_MANUALRECORD,        //�ֶ�¼��洢������
		EM_STORAGE_VIDEODETECTRECORD,   //��Ƶ���¼��洢������
		EM_STORAGE_ALARMRECORD,         //����¼��洢������
		EM_STORAGE_CARDRECORD,          //����¼��洢������
		EM_STORAGE_EVENTRECORD,         // �����¼�¼��洢������                
		EM_STORAGE_TIMINGSNAPSHOT,      // ��ʱץͼ�洢������
		EM_STORAGE_MANUALSNAPSHOT,      // �ֶ�ץͼ�洢������
		EM_STORAGE_VIDEODETECTSNAPSHOT, // ��Ƶ���ץͼ�洢������
		EM_STORAGE_ALARMSNAPSHOT,       // ����ץͼ�洢������
		EM_STORAGE_CARDSNAPSHOT,        // ����ץͼ�洢������
		EM_STORAGE_EVENTSNAPSHOT,       // �����¼�ץͼ�洢������
};
// �洢��������Ϣ
typedef struct tagCFG_STORAGEPOINT_INFO
{
	DWORD dwSize;
	EM_STORAGEPOINT_TYPE emStoragePointType;// �洢������
	char nLocalDir;                         //���ع���Ŀ¼������, �ձ�ʾ��¼������
	char szCompressDir[MAX_DIRECTORY_LEN];  //ʵʱѹ���洢Ŀ¼�飬�ձ�ʾ��ʹ��ʵʱѹ���洢��
	char szRedundantDir[MAX_DIRECTORY_LEN]; //���๤��Ŀ¼������,�ձ�ʾû������¼��
	char szRemoteDir[MAX_DIRECTORY_LEN];   //Զ�̹���Ŀ¼������,�ձ�ʾ��¼��Զ�̡�
	BOOL bAutoSync;                         //Զ�̴洢������ϻָ����Ƿ��Զ������ش洢������ͬ����Զ�̴洢��
	UINT nAutoSyncRange;                    //������ָ���ʱ�̿�ʼ����Ҫ��ǰͬ��������ʱ�䷶Χ��СʱΪ��λ��0��ʾͬ���������ݡ�
	BOOL bLocalEmergency;                   //Զ��Ŀ¼�޷�����ʱ���Ƿ񱣴浽����Ŀ¼��
	UINT nCompressBefore;                   //���ý�������֮ǰ��¼���ļ�����ѹ����
}CFG_STORAGEPOINT_INFO;

// ¼��洢��ӳ��������Ϣ
typedef struct tagCFG_RECORDTOSTORAGEPOINT_INFO
{
	int	nStoragePointNum;                                        //�洢����Ŀ
	CFG_STORAGEPOINT_INFO stStoragePoints[MAX_STORAGEPOINT_NUM]; // �洢��������Ϣ
}CFG_RECORDTOSTORAGEPOINT_INFO;

//iscsiֱ�棬Ԫ���ݷ��������ýӿ�
typedef struct __tagCFG_METADATA_SERVER
{
	DWORD       nStructSize;
	BOOL        bEnable;                              //ʹ�ܿ���
	char        szAddress[MAX_ADDRESS_LEN];           //IP��ַ��������
	DWORD       dwPort;                               //�˿ں�
	char        szUserName[MAX_USERNAME_LEN];         //�ʻ���  
	char        szPassword[MAX_PASSWORD_LEN];         //����
	char        szDeviceID[MAX_REMOTEDEVICENAME_LEN]; //Ϊʹ��Ԫ���ݷ��������豸ͳһ�����ID���豸�Դ�ID��ʶ�Լ�
}CFG_METADATA_SERVER;

// ���ػ�������
typedef struct __tagCFG_GOOD_WEIGHT_INFO
{
	DWORD		dwMaxGoodsWeight;					// ������(kg)
	DWORD		dwMinGoodsWeight;					// ��С����(kg)
	DWORD		dwSelfWeight;						// ����(kg)
	DWORD		dwStandardWeight;					// ����(kg)
	DWORD		dwAlarmWeight;						// ������ֵ(kg)
	int			nCheckTime;							// ��ֹ�ɼ�ʱ��(s)
} CFG_GOOD_WEIGHT_INFO;

//��ͷ�۽�״̬��Ϣ
typedef struct tagCFG_CAP_FOCUS_STATUS
{
	int					nAutofocusPeak;							// ��ǰAF��ֵ	�����۽�ģʽ����Ч
	double		        dFocus;									// �۽�λ��	��һ����0~1
	double		        dZoom;									// �Ŵ���	��һ����0~1
	int					nStatus;								// �۽�״̬, 0 ����״̬ 1 �����Զ��۽�
}CFG_CAP_FOCUS_STATUS;

//��̨֧��������Ϣ
typedef struct tagCFG_CAP_PTZ_ENABLEINFO 
{
	BOOL bEnable;												//��ͨ���Ƿ�֧����̨
	
}CFG_CAP_PTZ_ENABLEINFO;


// ����Ӧ��������
typedef struct tagCFG_CAP_NETAPP
{
	int                nNetCardCount;                           // ��������
	int                nNetTypeNumber;                          // �������͸���
	char               szNetType[MAX_NET_TYPE_NUM][MAX_NET_TYPE_LEN]; // ������������, "PPPoE"��"WIFI"��"3G"��"LAN"
}CFG_CAP_NETAPP;



///////////////////////////////////����Э������///////////////////////////////////////
// ¼��ģʽ
struct AV_CFG_RecordMode
{
	AV_int32			nStructSize;
	AV_int32			nMode;							// ¼��ģʽ, 0-�Զ�¼��1-�ֶ�¼��2-�ر�¼��
};

// ͨ������
struct AV_CFG_ChannelName
{
	AV_int32			nStructSize;
	AV_int32			nSerial;						// ����ͷΨһ���
	char				szName[AV_CFG_Channel_Name_Len];// ͨ����
};

// ��Ƶ�������
struct AV_CFG_VideoOutAttr
{
	AV_int32			nStructSize;
	AV_int32			nMarginLeft;					// ��߾�, ����, 0~100
	AV_int32			nMarginTop;						// �ϱ߾�, ����, 0~100
	AV_int32			nMarginRight;					// �ұ߾�, ����, 0~100
	AV_int32			nMarginBottom;					// �±߾�, ����, 0~100
	AV_int32			nBrightness;					// ����, 0~100
	AV_int32			nContrast;						// �Աȶ�, 0~100
	AV_int32			nSaturation;					// ���Ͷ�, 0~100
	AV_int32			nHue;							// ɫ��, 0~100
	AV_int32			nWidth;							// ˮƽ�ֱ���
	AV_int32			nHeight;						// ��ֱ�ֱ���
	AV_int32			nBPP;							// ��ɫ���
	AV_int32			nFormat;						// 0-Auto, 1-TV, 2-VGA, 3-DVI
	AV_int32			nRefreshRate;					// ˢ��Ƶ��
	AV_BOOL				bIQIMode;						// ���ͼ����ǿ
	AV_int32			nScanFormat;					// ɨ��ģʽ, 0-����, 1-����
};

// ʱ���
struct AV_CFG_TimeSection
{
	AV_int32			nStructSize;
	AV_int32			nMask;							// ����
	AV_int32			nBeginHour;						// ��ʼʱ��
	AV_int32			nBeginMinute;
	AV_int32			nBeginSecond;
	AV_int32			nEndHour;						// ����ʱ��
	AV_int32			nEndMinute;
	AV_int32			nEndSecond;
};

// Զ��ͨ��
struct AV_CFG_RemoteChannel 
{
	AV_int32			nStructSize;
	AV_BOOL				bEnable;						// ʹ��
	char				szDeviceID[AV_CFG_Device_ID_Len];	// �豸ID
	AV_int32			nChannel;						// ͨ����
};

// ��ʾԴ
struct AV_CFG_DisplaySource 
{
	AV_int32			nStructSize;
	AV_int32			nWindowID;						// ����ID
	AV_BOOL				bEnable;						// ʹ��
	char				szDeviceID[AV_CFG_Device_ID_Len];// �豸ID
	AV_int32			nVideoChannel;					// ��Ƶͨ����
	AV_int32			nVideoStream;					// ��Ƶ����
	AV_int32			nAudioChannle;					// ��Ƶͨ����
	AV_int32			nAudioStream;					// ��Ƶ����
	AV_BOOL				bVideoEnable;			        // ��ʾ�ô����Ƿ�����ƵԴ
};

// ͨ���ָ���ʾԴ
struct AV_CFG_ChannelDisplaySource 
{
	AV_int32			nStructSize;
	AV_int32			nWindowNum;						// �ָ������
	AV_CFG_DisplaySource stuSource[AV_CFG_Max_Split_Window];// �ָ����ʾԴ
};

// ������ѵ�·ָ�ģʽ�ķ���ʹ��״̬
struct AV_CFG_MonitorTourMask
{
	AV_int32			nStructSize;
	CFG_SPLITMODE		emSplitMode;					// �ָ�ģʽ
	AV_int32			nGroupNum;						// ��������
	AV_int32			nGroup[AV_CFG_Max_Split_Group];	// �÷ָ�ģʽ�¼�����ѵ�ķ���
};

// ������ѵ
struct AV_CFG_MonitorTour 
{
	AV_int32			nStructSize;
	AV_BOOL				bEnable;						// ʹ��
	AV_int32			nInterval;						// ʱ����, 5~120s
	AV_int32			nSplitMaskNum;					// �ָ����ʹ������
	AV_CFG_MonitorTourMask	stuSplitMask[AV_CFG_Max_Split_Mode];// ���ָ�ģʽ��Ӧ�ķ���ʹ��״̬
	AV_int32			nCollectionNum;					// �ղ�����
	char				szCollection[AV_CFG_Monitor_Favorite_In_Channel][AV_CFG_Monitor_Favorite_Name_Len];// �����ղ�����
};

// ���ӻ����ղ�
struct AV_CFG_MonitorFavorite 
{
	AV_int32			nStructSize;
	AV_BOOL				bDir;										// �Ƿ�ΪĿ¼	
	char				szName[AV_CFG_Monitor_Favorite_Name_Len];	// ����
	char				szPath[AV_CFG_Max_Path];					// Ŀ¼·��, ��ʽ����: .name1.name2.name3
	CFG_SPLITMODE		emMode;										// �ָ�ģʽ
	AV_int32			nWindowNum;									// ��������
	AV_CFG_DisplaySource stuWindow[AV_CFG_Max_Monitor_Favorite_Window];	// ������ʾԴ����
};

// ���ӻ����ղؼ���
struct AV_CFG_MonitorCollection 
{
	AV_int32			nStructSize;
	AV_CFG_MonitorFavorite*	pstuFavorite;				// �����ղ�����
	AV_int32			nMaxCount;						// �����ղ������С
	AV_int32			nRetCount;						// ���صĻ����ղ�����
};

// Raid��Ϣ
struct AV_CFG_Raid 
{
	AV_int32			nStructSize;
	char				szName[AV_CFG_Raid_Name_Len];	// ����
	AV_int32			nLevel;							// �ȼ�
	AV_int32			nMemberNum;						// ���̳�Ա����
	char				szMembers[AV_CFG_Max_Rail_Member][AV_CFG_Max_Path];	// ���̳�Ա
};

// ¼��Դ
struct AV_CFG_RecordSource
{
	AV_int32			nStructSize;
	AV_BOOL				bEnable;						// ʹ��
	char				szDeviceID[AV_CFG_Device_ID_Len];// �豸ID
	AV_int32			nVideoChannel;					// ��Ƶͨ����
	AV_int32			nVideoStream;					// ��Ƶ����
	AV_int32			nAudioChannle;					// ��Ƶͨ����
	AV_int32			nAudioStream;					// ��Ƶ����
};

// �����ʽ, ������Ƶ����Ƶ
struct AV_CFG_EncodeFormat
{
	AV_int32			nStructSize;
	AV_BOOL				bAudioEnable;					// ��Ƶʹ��
	AV_int32			nAudioBitRate;					// ��Ƶ������
	CFG_AUDIO_FORMAT	emAudioCompression;				// ��Ƶѹ��ģʽ
	AV_int32			nAudioDepth;					// ��Ƶ�������
	AV_int32			nAudioFrequency;				// ��Ƶ����Ƶ��
	AV_int32			nAudioMode;						// ��Ƶ����ģʽ
	AV_int32			nAudioPack;						// ��Ƶ���ģʽ, 0-DHAV, 1-PS

	AV_BOOL				bVideoEnable;					// ��Ƶʹ��
	AV_int32			nVideoBitRate;					// ��Ƶ������
	CFG_BITRATE_CONTROL	emVideoBitRateControl;			// ��������ģʽ
	CFG_VIDEO_COMPRESSION emVideoCompression;			// ��Ƶѹ��ģʽ
	AV_int32			nVideoFPS;						// ��Ƶ֡��
	AV_int32			nVideoGOP;						// ��ƵI֡���
	AV_int32			nVideoWidth;					// ��Ƶ���
	AV_int32			nVideoHeight;					// ��Ƶ�߶�
	CFG_IMAGE_QUALITY	emVideoQuality;					// ��Ƶͼ������
	AV_int32			nVideoPack;						// ��Ƶ���ģʽ, 0-DHAV, 1-PS	
};

// ��������
struct AV_CFG_Encode 
{
	AV_int32			nStructSize;
	AV_CFG_EncodeFormat stuMainFormat[AV_CFG_Max_Encode_Main_Format];	// ������, ������ͨ����, �������, ��������
	AV_CFG_EncodeFormat	stuExtraFormat[AV_CFG_Max_Encode_Extra_Format];	// ������, ����������1, ������2, ������3
	AV_CFG_EncodeFormat	stuSnapFormat[AV_CFG_Max_Encode_Snap_Format];	// ץͼ, ������ͨץͼ, ����ץͼ, ����ץͼ
};

// ��Ƶ������ɫ����, ÿ����Ƶ����ͨ����Ӧ�����ɫ����
struct AV_CFG_VideoColor 
{
	AV_int32			nStructSize;
	AV_CFG_TimeSection	stuTimeSection;					// ʱ���
	AV_int32			nBrightness;					// ����, 0~100
	AV_int32			nContrast;						// �Աȶ�, 0~100
	AV_int32			nSaturation;					// ���Ͷ�, 0~100
	AV_int32			nHue;							// ɫ��, 0~100
	AV_int32			nGamma;							// ����, 0~100
};


// ͨ����Ƶ������ɫ����
struct AV_CFG_ChannelVideoColor 
{
	AV_int32			nStructSize;
	AV_int32			nColorNum;						// ͨ����ɫ������
	AV_CFG_VideoColor	stuColor[AV_CFG_Max_VideoColor];// ͨ����ɫ����, ÿ��ͨ����Ӧ�����ɫ����
};

// ��ɫ
struct AV_CFG_Color
{
	AV_int32			nStructSize;
	AV_int32			nRed;							// ��
	AV_int32			nGreen;							// ��
	AV_int32			nBlue;							// ��
	AV_int32			nAlpha;							// ͸��
};

// ����
struct AV_CFG_Rect 
{
	AV_int32			nStructSize;
	AV_int32			nLeft;
	AV_int32			nTop;
	AV_int32			nRight;
	AV_int32			nBottom;	
};

// �������-���򸲸�����
struct AV_CFG_VideoWidgetCover 
{
	AV_int32			nStructSize;	
	AV_BOOL				bEncodeBlend;					// ���ӵ�������
	AV_BOOL				bEncodeBlendExtra1;				// ���ӵ�������1
	AV_BOOL				bEncodeBlendExtra2;				// ���ӵ�������2
	AV_BOOL				bEncodeBlendExtra3;				// ���ӵ�������3
	AV_BOOL				bEncodeBlendSnapshot;			// ���ӵ�ץͼ
	AV_CFG_Color		stuFrontColor;					// ǰ��ɫ
	AV_CFG_Color		stuBackColor;					// ����ɫ
	AV_CFG_Rect			stuRect;						// ����, ����ȡֵ0~8191
	AV_BOOL				bPreviewBlend;					// ���ӵ�Ԥ����Ƶ
};

// �������-ͨ������
struct AV_CFG_VideoWidgetChannelTitle
{
	AV_int32			nStructSize;
	AV_BOOL				bEncodeBlend;					// ���ӵ�������
	AV_BOOL				bEncodeBlendExtra1;				// ���ӵ�������1
	AV_BOOL				bEncodeBlendExtra2;				// ���ӵ�������2
	AV_BOOL				bEncodeBlendExtra3;				// ���ӵ�������3
	AV_BOOL				bEncodeBlendSnapshot;			// ���ӵ�ץͼ
	AV_CFG_Color		stuFrontColor;					// ǰ��ɫ
	AV_CFG_Color		stuBackColor;					// ����ɫ
	AV_CFG_Rect			stuRect;						// ����, ����ȡֵ0~8191, ��ʹ��left��topֵ, ��(left,top)Ӧ��(right,bottom)���ó�ͬ���ĵ�
	AV_BOOL				bPreviewBlend;					// ���ӵ�Ԥ����Ƶ
};

// �������-ʱ�����
struct AV_CFG_VideoWidgetTimeTitle
{
	AV_int32			nStructSize;
	AV_BOOL				bEncodeBlend;					// ���ӵ�������
	AV_BOOL				bEncodeBlendExtra1;				// ���ӵ�������1
	AV_BOOL				bEncodeBlendExtra2;				// ���ӵ�������2
	AV_BOOL				bEncodeBlendExtra3;				// ���ӵ�������3
	AV_BOOL				bEncodeBlendSnapshot;			// ���ӵ�ץͼ
	AV_CFG_Color		stuFrontColor;					// ǰ��ɫ
	AV_CFG_Color		stuBackColor;					// ����ɫ
	AV_CFG_Rect			stuRect;						// ����, ����ȡֵ0~8191, ��ʹ��left��topֵ, ��(left,top)Ӧ��(right,bottom)���ó�ͬ���ĵ�
	AV_BOOL				bShowWeek;						// �Ƿ���ʾ����
	AV_BOOL				bPreviewBlend;					// ���ӵ�Ԥ����Ƶ
};
	
// �������-�Զ������
struct AV_CFG_VideoWidgetCustomTitle 
{
	AV_int32			nStructSize;
	AV_BOOL				bEncodeBlend;					// ���ӵ�������
	AV_BOOL				bEncodeBlendExtra1;				// ���ӵ�������1
	AV_BOOL				bEncodeBlendExtra2;				// ���ӵ�������2
	AV_BOOL				bEncodeBlendExtra3;				// ���ӵ�������3
	AV_BOOL				bEncodeBlendSnapshot;			// ���ӵ�ץͼ
	AV_CFG_Color		stuFrontColor;					// ǰ��ɫ
	AV_CFG_Color		stuBackColor;					// ����ɫ
	AV_CFG_Rect			stuRect;						// ����, ����ȡֵ0~8191, ��ʹ��left��topֵ, ��(left,top)Ӧ��(right,bottom)���ó�ͬ���ĵ�
	char				szText[AV_CFG_Custom_Title_Len];// ��������
	AV_BOOL				bPreviewBlend;					// ���ӵ�Ԥ����Ƶ
    char                szType[AV_CFG_Custom_TitleType_Len];// �������� "Rtinfo" ʵʱ��¼��Ϣ "Custom" �Զ�����ӡ���ʪ�ȵ��� "Title" :Ƭͷ��Ϣ "Check"  У����
};

//  �������-���Ӵ�������Ϣ-������������
struct AV_CFG_VideoWidgetSensorInfo_Description 
{
	AV_int32			nStructSize;
	AV_int32			nSensorID;						// ��Ҫ�����Ĵ�������ID(��ģ��������ͨ����)
};

// �������-���Ӵ�������Ϣ
struct AV_CFG_VideoWidgetSensorInfo
{
	AV_int32			nStructSize;
	AV_BOOL				bPreviewBlend;					// ���ӵ�Ԥ����Ƶ
	AV_BOOL				bEncodeBlend;					// ���ӵ���������Ƶ����
	AV_CFG_Rect			stuRect;						// ����, ����ȡֵ0~8191
	AV_int32			nDescriptionNum;				// ��������������Ŀ
	AV_CFG_VideoWidgetSensorInfo_Description stuDescription[AV_CFG_Max_Description_Num];// ��������������Ϣ
};

// ��Ƶ�����������
struct AV_CFG_VideoWidget 
{
	AV_int32						nStructSize;
	AV_CFG_VideoWidgetChannelTitle	stuChannelTitle;	// ͨ������
	AV_CFG_VideoWidgetTimeTitle		stuTimeTitle;		// ʱ�����
	AV_int32						nConverNum;			// ���򸲸�����
	AV_CFG_VideoWidgetCover			stuCovers[AV_CFG_Max_Video_Widget_Cover];				// ��������
	AV_int32						nCustomTitleNum;	// �Զ����������
	AV_CFG_VideoWidgetCustomTitle	stuCustomTitle[AV_CFG_Max_Video_Widget_Custom_Title];	// �Զ������
	AV_int32						nSensorInfo;		// ��������Ϣ����������Ŀ
	AV_CFG_VideoWidgetSensorInfo	stuSensorInfo[AV_CFG_Max_Video_Widget_Sensor_Info];		// ��������Ϣ����������Ϣ
};

// �洢��ͨ���������
struct AV_CFG_StorageGroupChannel 
{
	AV_int32			nStructSize;
	AV_int32			nMaxPictures;					// ÿ��ͨ���ļ���ͼƬ�洢����, �����͸���
	char				szPath[AV_CFG_Max_ChannelRule];	// ͨ����������������ַ�����ʾ, %c��Ӧ������
};

// �洢������
struct AV_CFG_StorageGroup 
{
	AV_int32			nStructSize;	
	char				szName[AV_CFG_Group_Name_Len];	// ��������
	char				szMemo[AV_CFG_Group_Memo_Len];	// ����˵��
	AV_int32			nFileHoldTime;					// �ļ�����ʱ��
	AV_BOOL				bOverWrite;						// �洢�ռ����Ƿ񸲸�
	char				szRecordPathRule[AV_CFG_Max_Path];	// ¼���ļ�·����������
	char				szPicturePathRule[AV_CFG_Max_Path];	// ͼƬ�ļ�·����������
															// %y��, %M��, %d��, %hʱ, %m��, %s��, %cͨ��·��
															// ���������ʱ�����������, ��һ�α�ʾ��ʼʱ��, �ڶ��α�ʾ����ʱ��
	AV_CFG_StorageGroupChannel	stuChannels[AV_CFG_Max_Channel_Num];// ͨ��������� 
	AV_int32				nChannelCount;				// ͨ��������
};

// DSTʱ��
struct AV_CFG_DSTTime 
{
	AV_int32			nStructSize;
	AV_int32			nYear;							// ��, 2000~2038
	AV_int32			nMonth;							// ��, 1~12
	AV_int32			nWeek;							// �ڼ���, 1-��һ��,2-�ڶ���,...,-1-���һ��,0-�����ڼ���
	AV_int32			nDay;							// ���ڼ�������
														// ���ܼ���ʱ, 0-����, 1-��һ,..., 6-����
														// ��������ʱ, ��ʾ����, 1~31
	AV_int32			nHour;							// Сʱ
	AV_int32			nMinute;						// ����
};

// ��������
struct AV_CFG_Locales 
{
	AV_int32			nStructSize;
	char				szTimeFormat[AV_CFG_Time_Format_Len];	// ʱ���ʽ
	AV_BOOL				bDSTEnable;						// ����ʱʱ��
	AV_CFG_DSTTime		stuDstStart;					// ����ʱ��ʼʱ��
	AV_CFG_DSTTime		stuDstEnd;						// ����ʱ����ʱ��
};

// ��������
enum AV_CFG_LanguageType
{
	AV_CFG_Language_English,							// Ӣ��
	AV_CFG_Language_SimpChinese,						// ��������
	AV_CFg_Language_TradChinese,						// ��������
	AV_CFG_Language_Italian,							// �������
	AV_CFG_Language_Spanish,							// ��������
	AV_CFG_Language_Janpanese,							// ����
	AV_CFG_Language_Russian,							// ����
	AV_CFG_Language_French,								// ����
	AV_CFG_Language_German,								// ����
};

// ��������
struct AV_CFG_Language 
{
	AV_int32			nStructSize;
	AV_CFG_LanguageType emLanguage;						// ��ǰ����
};

// ���ʵ�ַ����
struct AV_CFG_AccessFilter
{
	AV_int32			nStructSize;
	AV_BOOL				bEnable;						// ʹ��
	AV_int32			nType;							// ����, 0-������, 1-������
	AV_int32			nWhiteListNum;					// ������IP����
	char				szWhiteList[AV_CFG_Max_White_List][AV_CFG_Filter_IP_Len];	// ������
	AV_int32			nBlackListNum;					// ������IP��IP������
	char				szBlackList[AV_CFG_Max_Black_List][AV_CFG_Filter_IP_Len];	// ������
};

// �Զ�ά��
struct AV_CFG_AutoMaintain 
{
	AV_int32			nStructSize;
	AV_int32			nAutoRebootDay;					// �Զ���������, -1����, 0~6����~����, 7ÿ��
	AV_int32			nAutoRebootHour;				// �Զ�����Сʱ, 0~23
	AV_int32			nAutoRebootMinute;				// �Զ���������, 0~59
	AV_int32			nAutoShutdownDay;				// �Զ��ػ�����
	AV_int32			nAutoShutdownHour;				// �Զ��ػ�Сʱ
	AV_int32			nAutoShutdownMinute;			// �Զ��ػ�����
	AV_int32			nAutoStartupDay;				// �Զ���������
	AV_int32			nAutoStartupHour;				// �Զ�����Сʱ
	AV_int32			nAutoStartupMinute;				// �Զ���������
	AV_BOOL				bAutoRebootEnable;				// true��ʾ�����Զ�������false��ʾ�ر��Զ�����
};

#define AV_CFG_Monitor_Name_Len		64			// ����ǽ���Ƴ���
#define AV_CFG_Max_TV_In_Block		64			// ������TV���������
#define AV_CFG_Max_Block_In_Wall	128			// ����ǽ��������������

// ����ǽ���ͨ����Ϣ
struct AV_CFG_MonitorWallTVOut
{
	AV_int32		nStructSize;
	char			szDeviceID[AV_CFG_Device_ID_Len];	// �豸ID, Ϊ�ջ�"Local"��ʾ�����豸
	AV_int32		nChannelID;							// ͨ��ID
	char			szName[AV_CFG_Channel_Name_Len];	// ��Ļ����
};

// ����ǽ����
struct AV_CFG_MonitorWallBlock 
{
	AV_int32				nStructSize;
	AV_int32				nLine;				// ����TVռ����������
	AV_int32				nColumn;			// ����TVռ����������
	AV_CFG_Rect				stuRect;			// �������������
	AV_int32				nTVCount;			// TV����
	AV_CFG_MonitorWallTVOut	stuTVs[AV_CFG_Max_TV_In_Block];					// TV����
	CFG_TIME_SECTION		stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];	// ���ػ�ʱ��
	char					szName[AV_CFG_Channel_Name_Len];				// ��������
	char					szCompositeID[AV_CFG_Device_ID_Len];			// �ں���ID
};

// ����ǽ
struct AV_CFG_MonitorWall
{
	AV_int32			nStructSize;
	char				szName[AV_CFG_Monitor_Name_Len];	// ����
	AV_int32			nLine;								// ��������
	AV_int32			nColumn;							// ��������
	AV_int32			nBlockCount;						// ��������
	AV_CFG_MonitorWallBlock stuBlocks[AV_CFG_Max_Block_In_Wall];// ��������
};

// ƴ����
struct AV_CFG_SpliceScreen
{
	AV_int32			nStructSize;
	char				szName[AV_CFG_Channel_Name_Len];	// ƴ��������	
	char				szWallName[AV_CFG_Monitor_Name_Len];// ��������ǽ����
	AV_int32			nBlockID;							// �����������
	AV_CFG_Rect			stuRect;							// ��������(0~8191)
};

// ��̨��������
typedef enum tagAV_CFG_PtzLinkType
{
	AV_CFG_PtzLink_None,				// ������
	AV_CFG_PtzLink_Preset,				// ����Ԥ�õ�
	AV_CFG_PtzLink_Tour,				// ����Ѳ��
	AV_CFG_PtzLink_Pattern,				// �����켣
} AV_CFG_PtzLinkType;

// ������̨��Ϣ
typedef struct tagAV_CFG_PtzLink
{
	AV_int32            nStructSize;
	AV_CFG_PtzLinkType	emType;				// �������� 
	AV_int32			nParam1;			// ��������1
	AV_int32			nParam2;            // ��������2
	AV_int32			nParam3;            // ��������3
	AV_int32			nChannelID;         // ��������̨ͨ��
} AV_CFG_PtzLink;

// �����
typedef struct tagAV_CFG_Point
{
	AV_int32			nStructSize;
	AV_int32			nX;
	AV_int32			nY;
} AV_CFG_Point;

// ���
typedef struct tagAV_CFG_Size
{
	AV_int32			nStructSize;
	AV_uint32			nWidth;
	AV_uint32			nHeight;
} AV_CFG_Size;	

// �¼���������
typedef struct tagAV_CFG_EventTitle
{
	AV_int32			nStructSize;
	char				szText[AV_CFG_Channel_Name_Len];	// �����ı�
	AV_CFG_Point		stuPoint;			// �������Ͻ�����, ����0-8191�������ϵ
	AV_CFG_Size			stuSize;			// ����Ŀ�Ⱥ͸߶�,����0-8191�������ϵ��ĳ���������Ϊ0��ʾ������������Ӧ���
    AV_CFG_Color		stuFrontColor;		// ǰ����ɫ
    AV_CFG_Color		stuBackColor;		// ������ɫ
} AV_CFG_EventTitle;


// ��Ѳ��������
typedef struct tagAV_CFG_TourLink
{
	AV_int32			nStructSize;
	AV_BOOL				bEnable;			// ��Ѳʹ��
	CFG_SPLITMODE		emSplitMode;		// ��Ѳʱ�ķָ�ģʽ
	AV_int32			nChannels[AV_CFG_Max_Channel_Num];  // ��Ѳͨ�����б�
	AV_int32			nChannelCount;		// ��Ѳͨ������
} AV_CFG_TourLink;

// ��������
typedef struct tagAV_CFG_EventHandler
{
	AV_int32			nStructSize;
	AV_CFG_TimeSection  stuTimeSect[AV_CFG_Weekday_Num][AV_CFG_Max_TimeSection]; // �¼���Ӧʱ���
	AV_BOOL             bRecordEnable;		// ¼��ʹ��
	AV_uint32           nRecordMask[AV_CFG_Max_Channel_Num];	// ¼��ͨ�����б�
	AV_BOOL             abRecordLatch;		// ������, ��ʶnRecordLatch�Ƿ���Ч
	AV_int32            nRecordLatch;		// ¼����ʱʱ�䣨10~300�룩
	AV_BOOL				bAlarmOutEn;		// �������ʹ��
	AV_uint32			nAlarmOutMask[AV_CFG_Max_Channel_Num];	// �������ͨ�����б�
	AV_BOOL             abAlarmOutLatch;	// ������, ��ʶnAlarmOutLatch�Ƿ���Ч
	AV_int32			nAlarmOutLatch;		// ���������ʱʱ�䣨10~300�룩
	AV_BOOL				bExAlarmOutEn;		// ��չ�������ʹ��
	AV_uint32			nExAlarmOutMask[AV_CFG_Max_Channel_Num]; // ��չ�������ͨ���б�
	AV_BOOL				bPtzLinkEn;			// ��̨����ʹ��
	AV_int32            nPtzLinkNum;		// ��Ч��������Ŀ
	AV_CFG_PtzLink		stuPtzLink[AV_CFG_Max_Channel_Num];		// ��̨������
	AV_BOOL				bSnapshotEn;		// ����ʹ��
	AV_uint32			nSnapshotMask[AV_CFG_Max_Channel_Num];  // ����ͨ�����б�	
	AV_BOOL             abSnapshotPeriod;	// ������, ��ʶnSnapshotPeriod�Ƿ���Ч
	AV_int32			nSnapshotPeriod;	// ֡�����ÿ������֡ץһ��ͼƬ��һ��ʱ����ץ�ĵ���������ץͼ֡���йء�0��ʾ����֡������ץ�ġ�
	AV_BOOL             abSnapshotTimes;	// ������, nSnapshotTimes��Ч��
	AV_int32			nSnapshotTimes;		// ���Ĵ���, ��SnapshotEnableΪtrue������£�SnapshotTimesΪ0���ʾ����ץ�ģ�ֱ���¼�������
	AV_BOOL             bSnapshotTitleEn;	// �Ƿ����ͼƬ����
	AV_int32            nSnapTitleNum;      // ��ЧͼƬ������Ŀ
	AV_CFG_EventTitle   stuSnapTitles[AV_CFG_Max_Event_Title_Num]; // ͼƬ��������
	AV_BOOL				bTipEnable;			// ������Ϣ����ʾ
	AV_BOOL				bMailEnable;		// �����ʼ��������ͼƬ����Ϊ����
	AV_BOOL				bMessageEnable;		// �ϴ�������������
	AV_BOOL				bBeepEnable;		// ����
	AV_BOOL				bVoiceEnable;		// ������ʾ
	AV_BOOL             abDejitter;			// ������, nDejitter��Ч��
	AV_int32            nDejitter;			// �ź�ȥ����ʱ�䣬��λΪ��,0~100
	AV_BOOL             bLogEnable;			// �Ƿ��¼��־
	AV_BOOL             abDelay;			// nDelay��Ч��
	AV_int32            nDelay;				// ����ʱ����ʱ����Ч, ��λΪ��
	AV_BOOL             bVideoTitleEn;		// �Ƿ������Ƶ���⣬��Ҫָ������
	AV_int32            nVideoTitleNum;		// ��Ч��Ƶ������Ŀ
	AV_CFG_EventTitle	stuVideoTitles[AV_CFG_Max_Event_Title_Num]; // ��Ƶ��������
	AV_BOOL				bMMSEnable;			// ���Ͳ���ʹ��
	AV_int32            nTourNum;			// ��Ѳ������Ŀ������Ƶ���һ��
	AV_CFG_TourLink	    stuTour[AV_CFG_Max_Tour_Link_Num];		// ��Ѳ��������, ÿ����Ƶ�����Ӧһ������
	AV_int32            nDBKeysNum;			// �ؼ�������
	char	            szDBKeys[AV_CFG_Max_DBKey_Num][AV_CFG_DBKey_Len]; // �ؼ���
	AV_BOOL             abJpegSummary;		// ������, ��ʶbyJpegSummary�Ƿ���Ч
	AV_BYTE             byJpegSummary[AV_CFG_Max_Summary_Len]; // ���ӵ�JPEGͼƬ��ժҪ��Ϣ
} AV_CFG_EventHandler;

#define AV_CFG_Event_Code_Len	64		// �¼��볤��

// Զ���豸�¼�����
struct AV_CFG_RemoteEvent 
{
	AV_int32            nStructSize;
	AV_BOOL             bEnable;						 // ʹ��
	char                szDeviceID[AV_CFG_Device_ID_Len];// �豸ID
	char                szCode[AV_CFG_Event_Code_Len];	 // �¼���
	AV_int32            nIndex;							 // ���
	AV_BOOL             abSensorType;                    // nSensorType�Ƿ���Ч
	AV_uint32           nSensorType;                     // ���������� ����:1 or ����:0
	AV_CFG_EventHandler stuEventHandler;				 // ��������
};

// �¶ȱ�������
typedef struct tagAV_CFG_TemperatureAlarm
{
	AV_int32			nStructSize;
	AV_BOOL				bEnable;							// ����ʹ��
	char				szName[AV_CFG_Device_Name_Len];		// ����������
	AV_float			fNormalTempMin;						// �����¶���Сֵ
	AV_float			fNormalTempMax;						// �����¶����ֵ
	AV_CFG_EventHandler stuEventHandler;					// ��������
} AV_CFG_TemperatureAlarm;

// ����ת�ٱ�������
typedef struct tagAV_CFG_FanSpeedAlarm
{
	AV_int32			nStructSize;
	AV_BOOL				bEnable;							// ����ʹ��
	char				szName[AV_CFG_Device_Name_Len];		// ����������
	AV_uint32			nNormalSpeedMin;					// ����ת����Сֵ
	AV_uint32			nNormalSpeedMax;					// ����ת�����ֵ
	AV_CFG_EventHandler stuEventHandler;					// ��������
} AV_CFG_FanSpeedAlarm;

// Ӳ��������������
typedef struct tagCFG_DISK_FLUX_INFO 
{
	BOOL				bEnable;							// ����ʹ��
	unsigned int		nNormalFluxMin;						// ����������Сֵ, ��λKB
	unsigned int		nNormalFluxMax;						// �����������ֵ, ��λKB
	CFG_ALARM_MSG_HANDLE stuEventHandler;					// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];	// �¼���Ӧʱ���
} CFG_DISK_FLUX_INFO;

// ����������������
typedef struct tagCFG_NET_FLUX_INFO
{
	BOOL				bEnable;							// ����ʹ��
	unsigned int		nNormalFluxMin;						// ����������Сֵ, ��λKB
	unsigned int		nNormalFluxMax;						// �����������ֵ, ��λKB
	CFG_ALARM_MSG_HANDLE stuEventHandler;					// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT_EX];	// �¼���Ӧʱ���
} CFG_NET_FLUX_INFO;

// ������
typedef struct tagCFG_SERVER_INFO
{
	int                 nPort;                             // �������˿ں�
	char                szAddress[MAX_ADDRESS_LEN];        // IP��ַ��������
}CFG_SERVER_INFO;

// ����ע������
typedef struct tagCFG_REGISTER_SERVER_INFO
{
	BOOL                bEnable;                            // ����ע��ʹ��
	char                szDeviceID[MAX_ADDRESS_LEN];        // �豸ID
	int                 nServersNum;                        // ����������
	CFG_SERVER_INFO     stuServers[MAX_SERVER_NUM];         // ����������
}CFG_REGISTER_SERVER_INFO;

// ������ʱ��������
typedef enum tagSTREAM_POLICY
{
    STREAM_POLICY_UNKNOWN,
    STREAM_POLICY_NONE = 1,								// �޲���,������ʹ��"None"
    STREAM_POLICY_QUALITY,                              // ��������"Quality"  
    STREAM_POLICY_FLUENCY,                              // ����������"Fluency"
    STREAM_POLICY_AUTOADAPT,                            // �Զ�"AutoAdapt"
}EM_STREAM_POLICY;

// ����Э������
typedef struct tagCFG_DVRIP_INFO
{
	int                 nTcpPort;                           // TCP����˿�,1025~65535
	int                 nSSLPort;                           // SSL����˿�,1025~65535
	int                 nUDPPort;                           // UDP����˿�,1025~65535
	int                 nMaxConnections;                    // ��������� 
	BOOL                bMCASTEnable;                       // �鲥ʹ��
	int                 nMCASTPort;                         // �鲥�˿ں�
	char                szMCASTAddress[MAX_ADDRESS_LEN];    // �鲥��ַ
	int                 nRegistersNum;                      // ����ע�����ø���
	CFG_REGISTER_SERVER_INFO stuRegisters[MAX_REGISTER_NUM];// ����ע������ 
    EM_STREAM_POLICY    emStreamPolicy;                     // ������ʱ��������
}CFG_DVRIP_INFO;

// ����¼��ƻ�
typedef struct tagCFG_HOLIDAY_SCHEDULE
{
	BOOL				bEnable;
	int					nChannel;
	DWORD				dwMonthSchedule[MONTH_OF_YEAR];		// ÿ���µļ��ڰ���, ÿ��Ԫ�ر�ʾһ����, 
															// ����ӵ͵������α�ʾÿ��1-28/29/30/31���Ƿ�Ϊ����
															// 0:���Ǽ���, 1:�Ǽ���
	CFG_TIME_SECTION	stuTimeSection[MAX_REC_TSECT];		// ¼��ʱ���
} CFG_HOLIDAY_SCHEDULE;

// ¼��ش�����
typedef struct tagAV_CFG_RecordBackup
{
	AV_int32			nStructSize;
	AV_uint32			nBitrateLimit;						// �����������, ��λKbps
	AV_CFG_RemoteDevice	*pstuDevices;						// �����豸����, �û������ڴ�
	int					nMaxDeviceCount;					// �������������С, �û���д
	int					nRetDeviceCount;					// ���ص��豸����
} AV_CFG_RecordBackup;

typedef struct tagALARM_EVENT_INFO
{
	DWORD	        	dwEventType;					    // �¼����ͣ����dhnetsdk.h��"���ܷ����¼�����"
	int		         	nEventSize;							// ���¼����͹������ýṹ���С
} ALARM_EVENT__INFO;

// ÿ����Ƶ����ͨ����Ӧ�������¼���������pEventBuf������¼���Ϣ��ÿ���¼�������Ϣ����ΪALARM_EVENT_INFO+"�¼����Ͷ�Ӧ�Ĺ������ýṹ��"��
typedef struct tagALARM_ANALYSEEVENTS_INFO
{
	int	         		nEventCount;						// �¼�����
	char*				pEventBuf;							// ÿ����Ƶ����ͨ����Ӧ����Ƶ�����¼�����
	int		        	nEventBufLen;						// �����С
	
} ALARM_ANALYSEEVENTS_INFO;

// ������Ϣ
typedef struct tagCFG_COMM_INFO
{
	char				szProtocolName[MAX_PROTOCOL_NAME_LEN];	// ����Э��
	CFG_COMM_PROP		stuAttribute;							// ��������
	int					nAddress;								// �豸��ַ
} CFG_COMM_INFO;

// ��������
typedef struct tagCFG_COMMGROUP_INFO
{
	int					nCommNum;						// ��������
	CFG_COMM_INFO		stuComms[MAX_COMM_NUM];			// ��������
} CFG_COMMGROUP_INFO;

// ����ӿ�
typedef struct tagCFG_NETWORK_INTERFACE 
{
	char				szName[MAX_NAME_LEN];			// ����ӿ�����
	char				szIP[MAX_ADDRESS_LEN];			// ip��ַ
	char				szSubnetMask[MAX_ADDRESS_LEN];	// ��������
	char				szDefGateway[MAX_ADDRESS_LEN];	// Ĭ������
	BOOL				bDhcpEnable;					// �Ƿ���DHCP
	BOOL				bDnsAutoGet;					// DNS��ȡ��ʽ��dhcpʹ��ʱ��������Ϊtrue��֧��ͨ��dhcp��ȡ
	char				szDnsServers[MAX_DNS_SERVER_NUM][MAX_ADDRESS_LEN];	// DNS��������ַ
	int					nMTU;							// ��������䵥Ԫ
} CFG_NETWORK_INTERFACE;

// ����ӿ�����
typedef struct tagCFG_NETWORK_INFO 
{
	char				szHostName[MAX_NAME_LEN];		// ��������
	char				szDomain[MAX_NAME_LEN];			// ������
	char				szDefInterface[MAX_NAME_LEN];	// Ĭ��ʹ�õ�����
	int					nInterfaceNum;					// ��������
	CFG_NETWORK_INTERFACE	stuInterfaces[MAX_NETWORK_INTERFACE_NUM];	// �����б�
} CFG_NETWORK_INFO;

// ����洢����
typedef struct tagCFG_NAS_INFO_NEW
{
	BOOL				bEnable;						// ʹ��
	char				szName[MAX_NAME_LEN];			// ����
	int					nPortocol;						// Э������, 0-FTP, 1-SMB, 2-ISCSI, 3-NFS
	char				szAddress[MAX_ADDRESS_LEN];		// IP��ַ����ַ
	int					nPort;							// �˿�
	char				szUser[MAX_USERNAME_LEN];		// �û���
	char				szPassword[MAX_PASSWORD_LEN];	// ����
	char				szDirectory[MAX_NAME_LEN];		// �����Ŀ¼��
	int					nCharEncoding;					// �ַ������ʽ, 0-UTF8, 1-GB2312
	int					nTimeOut;						// ��ʱʱ��, ��λ����
	unsigned int		nStreamID;						// ������ID
	CFG_NET_TIME_EX		stuUpdateTime;					// ����ʱ��, ���ֶ�ֵ�仯����Ҫ���³�ʼ��iSCSI����
} CFG_NAS_INFO_NEW;

// ����洢����������, �������������
typedef struct tagCFG_NAS_GROUP_INFO
{
	int					nNasNum;						// �洢����������
	CFG_NAS_INFO_NEW	stuNasInfo[MAX_NAS_NUM];		// �洢����������	
} CFG_NAS_GROUP_INFO;

// ����洢����������
typedef struct tagCFG_NAS_INFO_EX 
{
	int					nVersion;						// 0, 1, ��������ȷ��, ֻ��
	CFG_NAS_INFO		stuNasOld;						// nVersion == 0ʱ��Ч, ��֧�ֵ�������
	CFG_NAS_GROUP_INFO	stuNasGroup;					// nVersion == 1ʱ��Ч, ֧�ֶ��������
} CFG_NAS_INFO_EX;

// ����ͨ����������
typedef struct tagCFG_VIDEO_IN_INFO 
{
	char				szDevType[MAX_NAME_LEN];		// ͨ�����ͣ�ָͨ�����ӵ��豸���ͣ�
	char				szDevID[MAX_NAME_LEN];			// ����ͷΨһ���
	char				szChnName[MAX_NAME_LEN];		// ͨ������
	char				szManufacturer[MAX_NAME_LEN];	// ����
	char				szModel[MAX_NAME_LEN];			// �豸�ͺ�
	char				szAddress[MAX_ADDRESS_LEN];		// ��װ��ַ
	char				szCivilCode[MAX_NAME_LEN];		// ��������
	char				szOwner[MAX_NAME_LEN];			// �豸����
	BOOL				bParental;						// �Ƿ������豸
	BOOL				bEnable;						// ͨ��ʹ��
	int					nRegisterWay;					// ע�᷽ʽ
														// 0-����sip3261��׼����֤ע��ģʽ
														// 1-���ڿ����˫����֤ע��ģʽ
														// 2-��������֤���˫����֤ע��ģʽ
	BOOL				bSecrecy;						// ��������, FALSE������, TRUE����
	char				szUpperDevID[MAX_NAME_LEN];		// �ϼ������豸�豸ID
	int					nUpperDevOutChn;				// �ϼ������豸���ͨ����
} CFG_VIDEO_IN_INFO;

// ��¼���̱���ƻ�(��Ӧ���� CFG_CMD_ENCODEPLAN)��ÿ��ͨ��(�������л�ͨ��)һ�����ýṹ��
typedef struct tagCFG_ENCODE_PLAN_INFO
{
	BOOL                bEnable;                        // ͨ���Ƿ���Ҫ����,FALSE:û�д�ͨ��,TRUE:��ͨ������
	unsigned int        nExpectTime;                    // ҵ��Ԥ��ʱ��	 ����,��λ������
	CFG_CAPTURE_SIZE    emResolution;                   // ��Ƶ�ֱ���
	unsigned int        nBitRate;                       // ��Ƶ�̶�����ֵ(kbps)
}CFG_ENCODE_PLAN_INFO;

//////////////////////////////////////////////////////////////////////////
// ˾����Ѷ���л�����
// С���洰����Ϣ
typedef struct tagCFG_SMALLPIC_INFO
{
	char                szDeviceID[AV_CFG_Device_ID_Len];// �豸ID
	int                 nChannelID;						 // ͨ����(0��ʼ)
	BOOL                bAudio;                          // �����Ƿ���С������Ƶ
    CFG_RECT            stuPosition;                     // ʹ�����������ϵ��ȡֵ��Ϊ0-8192,��������Ļ�ϵ�λ��
}CFG_SMALLPIC_INFO;

// �ָ�ͨ��
typedef struct tagCFG_SPLIT_CHANNEL_INFO
{
	BOOL                bEnable;                         // ʹ��
	char                szDeviceID[AV_CFG_Device_ID_Len];// �豸ID
	int                 nChannelID;						 // ͨ����(0��ʼ)
	unsigned int        nMaxSmallChannels;               // С����ͨ��������ÿ��ͨ��һ��CFG_SMALLPIC_INFO,�������Ӧ�����豸ͨ������һ
	unsigned int        nReturnSmallChannels;            // �������صĻ��װ���͵�С����ͨ������
	CFG_SMALLPIC_INFO  *pPicInfo;                        // С������Ϣ
}CFG_SPLIT_CHANNEL_INFO;

// �ָ��
typedef struct tagCFG_SPLIT_INFO
{
	CFG_SPLITMODE       emSplitMode;        // �ָ�ģʽ��ͨ��CLIENT_GetSplitCaps�ӿڻ�ȡ����emSplitMode
	unsigned int        nMaxChannels;       // �����ڴ�CFG_SPLIT_CHANNEL_INFO����,������16��ͨ����nMaxChannels����16��SPLITMODE_4ģʽ����˳�����η�Ϊ4��
	unsigned int        nReturnChannels;    // ��������ͨ������,Ҫ��װ���͵�ͨ������
	CFG_SPLIT_CHANNEL_INFO* pSplitChannels; // �ָ�ͨ����Ϣ
}CFG_SPLIT_INFO;

// ���л�����
typedef struct tagCFG_PICINPIC_INFO
{
	unsigned int        nMaxSplit;          // �ڴ������CFG_SPLIT_INFO����,���ֵͨ��CLIENT_GetSplitCaps�ӿڻ�ȡ����nModeCount
	unsigned int        nReturnSplit;       // �����õ�ʵ��ʹ�õĻ��װ���͵�CFG_SPLIT_INFO����
	CFG_SPLIT_INFO     *pSplits;            // �ָ��
}CFG_PICINPIC_INFO;

// ģ������ⲿ����Դ
typedef struct tagCFG_ANALOG_MATRIX_INPUT_CHN_SRC 
{
	char				szName[MAX_NAME_LEN];			// ����ͨ������
	char				szControlID[MAX_NAME_LEN];		// ���Ʊ��
	BOOL				bActive;						// �Ƿ񼤻�����
	int					nFormat;						// ����, 0-VGA
} CFG_ANALOG_MATRIX_INPUT_CHN_SRC;

// ����
typedef struct tagCFG_COM_PORT 
{
	int					nPortIndex;						// ����������
	int					nAddress;						// �豸��ַ
	CFG_COMM_PROP		stComProp;						// ��������
} CFG_COM_PORT;

// ģ�����
typedef struct tagCFG_ANALOG_MATRIX_INFO
{
	char				szDevID[MAX_NAME_LEN];			// �豸ID
	char				szName[MAX_NAME_LEN];			// �豸����
	char				szModel[MAX_MODEL_LEN];			// �ͺ�
	char				szUserName[MAX_USERNAME_LEN];	// �û���
	char				szPassword[MAX_PASSWORD_LEN];	// ����
	int					nChnInCount;					// ����ͨ������
	int					nChnOutCount;					// ���ͨ������
	CFG_ANALOG_MATRIX_INPUT_CHN_SRC* pstuChnInSrc;		// �ⲿ����Դ����, �û������ڴ�
	int					nChnInSrcCount;					// �ⲿ����Դ�����С
	int					nRetChnInSrcCount;				// ʵ�ʷ��ص��ⲿ����Դ����, һ��ͬnChnInCount
	CFG_COM_PORT		stComPort;						// ��������
	char				szProtocol[MAX_NAME_LEN];		// Э������
} CFG_ANALOG_MATRIX_INFO;

// ģ�����Э������
typedef struct tagCFG_ANALOG_MATRIX_PROTOCOL 
{
	char				szName[MAX_NAME_LEN];			// Э������
	char				szProtocolRule[MAX_NAME_LEN];	// Э������, ����%A-��ַ�룬%I-����˿ںţ�%O-����˿ں�
} CFG_ANALOG_MATRIX_PROTOCOL;

// ��Ƶ�������
typedef struct tagCFG_VIDEO_OUT_TITLE 
{
	char				szName[MAX_NAME_LEN];			// ͨ������
} CFG_VIDEO_OUT_TITLE;

// ��ʾԴ
typedef struct tagCFG_DISPLAY_SOURCE
{
	BOOL				bEnable;						// �Ƿ�ʹ��
	char				szDeviceID[MAX_NAME_LEN];		// �豸ID
	char				szControlID[MAX_NAME_LEN];		// ����ID
	int					nVideoChannel;					// ��Ƶͨ����
	int					nVideoStream;					// ��Ƶ����, -1-�Զ�, 0-������, 1-������1, 2-������2, 3-������3 
	int					nAudioChannel;					// ��Ƶͨ����
	int					nAudioStream;					// ��Ƶ����, -1-�Զ�, 0-������, 1-������1, 2-������2, 3-������3 
	BOOL				abDeviceInfo;					// �豸��Ϣ�Ƿ���Ч
	AV_CFG_RemoteDevice stuDeviceInfo;					// �豸��Ϣ
} CFG_DISPLAY_SOURCE;

// ����λ��
typedef struct tagCFG_SPLIT_WINDOW_POSITION 
{
	CFG_RECT			stuRect;						// ��������
	BOOL				bDirectable;					// �Ƿ�����ֱͨ����, ֱͨ��ָƴ������ʽ�£��˴�����������Ϊ����������
	int					nZorder;						// Z����
} CFG_SPLIT_WINDOW_POSITION;

// ƴ����������Ϣ
typedef struct tagCFG_SPLIT_WINDOW 
{
	BOOL				bEnable;						// �����Ƿ�����ƵԴ, ΪFALSEʱ��ʾû����Ƶ��Ҳ���ô���Source����
	int					nWindowID;						// ����ID
	char				szControlID[MAX_NAME_LEN];		// ����ID
	CFG_SPLIT_WINDOW_POSITION stuPosition;				// ����λ��
	CFG_DISPLAY_SOURCE	stuSource;						// ��ƵԴ
} CFG_SPLIT_WINDOW;

// ƴ��������
typedef struct tagCFG_BLOCK_COLLECTION 
{
	char				szBlockID[MAX_NAME_LEN];		// ƴ����ID
	char				szControlID[MAX_NAME_LEN];		// ����ID
	CFG_SPLITMODE		emSplitMode;					// �ָ�ģʽ
	CFG_SPLIT_WINDOW*	pstuWnds;						// ������Ϣ����, �û������ڴ�
	int					nMaxWndCount;					// ������Ϣ�����С, �û���д
	int					nRetWndCount;					// ���صĴ�������
} CFG_BLOCK_COLLECTION;

// ����ǽ�е�ĳ��Ԥ������
typedef struct tagCFG_MONITORWALL_COLLECTION_SINGLE
{
	char				szName[MAX_NAME_LEN];			// ����
	char				szControlID[MAX_NAME_LEN];		// ����ID
	AV_CFG_MonitorWall	stuMonitorWall;					// ����ǽ����
	CFG_BLOCK_COLLECTION* pstuBlockCollections;			// ƴ����������Ϣ����, �û������ڴ�
	int					nMaxBlockCollectionCount;		// ƴ�������������С, �û���д
	int					nRetBlockCollectionCount;		// ���ص�ƴ������������
} CFG_MONITORWALL_COLLECTION_SINGLE;

// ����ǽԤ���б�, ��ʾĳ������ǽ��Ӧ�Ķ��Ԥ��
typedef struct tagCFG_MONITORWALL_COLLECTION_LIST
{
	CFG_MONITORWALL_COLLECTION_SINGLE* pstuCollections;	// Ԥ������, �û������ڴ�
	int					nMaxCollectionCount;			// Ԥ�������С, �û���д
	int					nRetCollectionCount;			// ���ص�Ԥ������
} CFG_MONITORWALL_COLLECTION;

// ��Ƶ����߽�����
typedef struct tagCFG_VIDEO_IN_BOUNDARY 
{
	CFG_RECT			stuBoundary;					// �߽�
} CFG_VIDEO_IN_BOUNDARY;

// ������Խӵ�����������,�����飬Ԫ�����ֵ��DH_PRODUCTION_DEFNITION.nMaxParkingSpaceScreen)
typedef struct tagCFG_PARKINGSPACE_SCREEN_INFO
{
	char                szAddress[MAX_PATH];            // ��������ַ������
	int                 nPort;                          // �������˿�
	char                szAuthorization[MAX_PATH];      // Ȩ����
    char                szDeviceNo[MAX_PATH];           // �豸���
	BOOL                bEnable;                        // �������Ƿ�����
} CFG_PARKINGSPACE_SCREEN_INFO;

// ��λ����(ר�г�λ����ͨ��λ����)�������飬Ԫ�����ֵ��DH_PRODUCTION_DEFNITION.nMaxRoadWays)
typedef struct tagCFG_PARKINGSPACE_STATUS_INFO
{
	int                  nLaneID;                        // ��λ��
	int                  nLaneType;                      // 0����ͨ��λ 1��ר�г�λ
} CFG_PARKINGSPACE_STATUS_INFO;

// ƽ̨�Զ�����Ϣ
typedef struct tagCFG_CLIENT_CUSTOM_INFO
{
	char                 szDescription[MAX_PATH];        // ������Ϣ,��ͬƽ̨�Զ���������Ϣ,Ŀǰ֧��"LiFang"
	char*                pData;                          // �Զ������ݻ��壬�����м䲻�ܴ��ڶ����Ƶ�0Ҳ�����ַ�'\0'
	int                  nDataLen;                       // �û�����ĳ��ȣ���ͬƽ̨�Լ�ȷ��
} CFG_CLIENT_CUSTOM_INFO;

// ��¼��ʽ����,�����Կ��ǣ��޴�����ʱĬ��DHAV��ʽ
typedef struct tagCFG_BURN_RECORD_FORMAT
{
	char                 szRecordPack[MAX_PATH];         // �������ģʽ:Ŀǰ֧��"DHAV","PS"
}CFG_BURN_RECORD_FORMAT;

// �����ͬ����¼(��Ӧ CFG_MULTIBURN_INFO) ��һ�����飬ÿһ��Ԫ�ر�ʾһ������ͬ����¼��У��
typedef struct tagCFG_MULTIBURN_INFO
{
	BOOL                 bEnable;                        // ������ʹ�ܿ���
    BOOL                 bDataCheck;                     // �����һ����У��ʹ��
    char                 szDataCheckSpeed[MAX_PATH];     // У���ٶ� "High":���٣�ͷβ����У�飩,"Normal":�������������У�飩,"Low":���� ��ȫ������У�飩
}CFG_MULTIBURN_INFO;

// ��������洢��������������
typedef struct tagCFG_REMOTE_STORAGE_LIMIT
{
    char				        szName[MAX_NAME_LEN];                       // ����
    int							nFileLen;									// �ļ����� ��λ,MB
	int							nInterval;									// �����ļ�ʱ���� ��λ,��
	CFG_CHANNEL_TIME_SECTION	*pstuChnTime;        	                    // �洢ʱ������飬�û������ڴ�
	int                         nMaxChnCount;                               // ���ͨ�������û���д
    int                         nRetChnCount;                               // ���ص�ͨ����,��������ʱ����Чͨ����
}CFG_REMOTE_STORAGE_LIMIT;

// ����洢��������������
typedef struct tagCFG_REMOTE_STORAGELIMIT_GROUP
{
	CFG_REMOTE_STORAGE_LIMIT    stuRemoteStorageLimit[MAX_NAS_NUM];         // ����洢��������������
    int                         nLimitCount;                                // ��Ч�������������
}CFG_REMOTE_STORAGELIMIT_GROUP;

// ��ȡ��¼����������
typedef struct tagCFG_CAP_BURN_MANAGER	
{
    BOOL                 bSupportMultiBurn;              // �Ƿ�֧�ֶ����ͬ����¼
    int                  nMultiBurnGroups;               // ֧�ּ���ͬ����¼
}CFG_CAP_BURN_MANAGER;

// ¼��������Ϣ
typedef struct tagCFG_CAP_RECORD_INFO	
{
	BOOL  bSupportHoliday;				                 //¼��ƻ��Ƿ�֧�ּ��չ���
	BOOL  bSupportExtraRecordMode;						 //�Ƿ�֧�����ø�����¼��ģʽ	
	DWORD dwMaxPreRecordTime;							 //���Ԥ¼ʱ��
	DWORD dwMaxRemoteBitrate;							 //������������,��λkbps
	DWORD dwMaxRemoteRawBitrate;						 //�����뵐����������·�����ֱ��ʡ�֡�ʣ�ɫ�16bpp���㣩
    DWORD dwMaxStreams;                                  //���¼����������
} CFG_CAP_RECORD_INFO;

//-------------------------------�������---------------------------------
typedef  enum tagCFG_ENCRYPT_ALGO_TYPE
{
	ALGO_TYPE_AES	 , 
	ALGO_TYPE_UNKNOW ,
}CFG_ENCRYPT_ALGO_TYPE;

// ���������㷨����ģʽ
typedef enum  tagCFG_ENCRYPT_ALGO_WORKMODE
{
	ENCRYPT_ALGO_WORKMODE_ECB,     // ECBģʽ
	ENCRYPT_ALGO_WORKMODE_CBC,     // CBCģʽ
	ENCRYPT_ALGO_WORKMODE_CFB,     // CFBģʽ
	ENCRYPT_ALGO_WORKMODE_OFB,     // OFBģʽ
	ENCRYPT_ALGO_WORKMODE_UNKNOW ,
}CFG_ENCRYPT_ALGO_WORKMODE;

typedef union tagCFG_ENCRYPT_KEY_INFO
{
	BYTE byAesKey[AES_KEY_LEN];							// aes��Կ
}CFG_ENCRYPT_KEY_INFO;

//��������������Ϣ
typedef struct tagCFG_STREAM_ENCRYPT_INFO
{
	BOOL						bEncryptEnable;		// �Ƿ����
	CFG_ENCRYPT_ALGO_TYPE		emEncrptAlgoType;	// �����㷨����: �μ�ö������CFG_ENCRYPT_ALGO_TYPE
	CFG_ENCRYPT_ALGO_WORKMODE	emAlgoWorkMode;		// ����ģʽ,�ο�ö������ CFG_ENCRYPT_ALGO_WORKMODE
	WORD						wEncryptLenth;		// ��Կ���ȣ���ǰΪAES�㷨����ʱ����ʾ��Կλ��(Ŀǰ֧��128��192��256λ����, ��: wEncryptLenthΪ128������Կ��ϢENCRYPT_KEY_INFO���byAesKey[0]~[15])
	CFG_ENCRYPT_KEY_INFO		stuEncryptKeys;		// ͨ������Կ��Ϣ 
	CFG_NET_TIME				stuPreTime;			// ���ܼƻ��Ŀ�ʼʱ��
}CFG_STREAM_ENCRYPT_INFO;

//������������ͨ����Ϣ
typedef struct tagCFG_ENCODE_ENCRYPT_CHN_INFO
{
	int						 nChannelID;					// ͨ����(0��ʼ)
	CFG_STREAM_ENCRYPT_INFO *pstEncodeEncryptInfo;			// ÿ��ͨ���������б�,�û�������
												            // nMaxEncryptInputs��CFG_STREAM_ENCRYPT
	BYTE					 nMaxEncryptInputs; 
	BYTE					 nRetEncryptOutputs;			// ������CFG_STREAM_ENCRYPT�ĸ���
}CFG_ENCODE_ENCRYPT_CHN_INFO;


//��������Ӧ��������
typedef  enum tagCFG_ENCRYPT_POLICY_TYPE
{
	ENCRYPT_POLICY_UNKNOWN ,		//δ֪
	ENCRYPT_POLICY_NONE ,		//�޲��ԣ�����������Ӧ����
	ENCRYPT_POLICY_QUALITY ,    //�������ȣ����ȱ�֤�ֱ��ʣ�����֡��
	ENCRYPT_POLICY_FLUENCY ,	//�������ȣ����ȱ�֤�����ԣ����ͷֱ���
}CFG_ENCRYPT_POLICY_TYPE;

//�����������Ȳ���
typedef enum tagCFG_ENCRYPT_FLUENCY_MODE
{
	ENCRYPT_FLUENCY_UNKNOWN ,		//δ֪
	ENCRYPT_FLUENCY_FAST ,			//��ָ�(���ٱ��ʱ�������ָ�)
	ENCRYPT_FLUENCY_SLOW ,			//���ָ�(ͬһʱ��ֻ����һ��ͨ���ָ�)
	ENCRYPT_FLUENCY_SYNC ,			//ͬ���ָ�(�����ͨ���½���������ͨ�����ָ�)
	ENCRYPT_FLUENCY_SLOWSYNC ,		//��ͬ���ָ�(������ָ���ͬ���ָ�)
}CFG_ENCRYPT_FLUENCY_MODE;

//��������Ӧ����
typedef struct tagCFG_ENCODE_ADAPT_INFO
{
	CFG_ENCRYPT_POLICY_TYPE		emPolicyType;		//����Ӧ��������
	CFG_ENCRYPT_FLUENCY_MODE	emFluencyMode;		//�������Ȳ���
}CFG_ENCODE_ADAPT_INFO;

// �䱶���û�����Ϣ��Ԫ
typedef struct tagCFG_VIDEO_IN_ZOOM_UNIT
{
	int         nSpeed;									 //�䱶����(0~7)
	BOOL		bDigitalZoom;							 //�Ƿ����ֱ䱶
	int			nZoomLimit;								 //��ǰ���������䱶����(0~13)��
} CFG_VIDEO_IN_ZOOM_UNIT;

// ��ͨ���䱶���û�����Ϣ
typedef struct tagCFG_VIDEO_IN_ZOOM	
{
	int						nChannelIndex;				 //ͨ����
	int						nVideoInZoomRealNum;		 //����ʹ�ø���
	CFG_VIDEO_IN_ZOOM_UNIT  stVideoInZoomUnit[MAX_VIDEO_IN_ZOOM];		 //ͨ���������õ�Ԫ��Ϣ
	
} CFG_VIDEO_IN_ZOOM;

// ץͼ����
typedef struct tagCFG_SNAP_INFO 
{
	CFG_TIME_SCHEDULE		stuTimeSchedule;			// ʱ���, ÿ��ʱ������밴λ��������: 
														// Bit0-��ʱץͼ
														// Bit1-��̬���ץͼ
														// Bit2-����ץͼ
														// Bit3-����ץͼ
														// Bit4~Bit31-����
} CFG_SNAP_INFO;

//��̨ת���Ƕȷ�Χ����λ����
typedef struct tagCFG_PTZ_MOTION_RANGE
{
	int                 nHorizontalAngleMin;       // ˮƽ�Ƕȷ�Χ��Сֵ,��λ:��
	int                 nHorizontalAngleMax;       // ˮƽ�Ƕȷ�Χ���ֵ,��λ:��
	int                 nVerticalAngleMin;          // ��ֱ�Ƕȷ�Χ��Сֵ,��λ:��
	int                 nVerticalAngleMax;          // ��ֱ�Ƕȷ�Χ���ֵ,��λ:��
}CFG_PTZ_MOTION_RANGE;

//֧�ֵĽ���ģʽ��Ӧö��
typedef enum tagSUPPORT_FOCUS_MODE
{
    ENUM_SUPPORT_FOCUS_CAR        = 1,                // ���峵ģʽ         
	ENUM_SUPPORT_FOCUS_PLATE      = 2,                // ���峵��ģʽ 
	ENUM_SUPPORT_FOCUS_PEOPLE     = 3,                // ������ģʽ     
	ENUM_SUPPORT_FOCUS_FACE       = 4,                // ��������ģʽ     
}EM_SUPPORT_FOCUS_MODE;

//��̨ת���Ƕȷ�Χ����λ����
typedef struct tagCFG_PTZ_LIGHTING_CONTROL
{
	char                szMode[CFG_COMMON_STRING_32];  // �ֶ��ƹ����ģʽ
	                                                   // on-off"��ֱ�ӿ���ģʽ,
	                                                   // "adjustLight"���ֶ���������ģʽ

	DWORD               dwNearLightNumber;             // �����������
	DWORD               dwFarLightNumber;              // Զ���������
}CFG_PTZ_LIGHTING_CONTROL;

//��ȡ��̨��������Ϣ
typedef struct tagCFG_PTZ_PROTOCOL_CAPS_INFO
{
	int                 nStructSize;
    BOOL                bPan;                       // �Ƿ�֧����̨ˮƽ�ڶ�
	BOOL                bTile;                      // �Ƿ�֧����̨��ֱ�ڶ�
	BOOL                bZoom;                      // �Ƿ�֧����̨�䱶
	BOOL                bIris;                      // �Ƿ�֧����̨��Ȧ����
	BOOL                bPreset;                    // �Ƿ�֧��Ԥ�õ�
	BOOL                bRemovePreset;              // �Ƿ�֧�����Ԥ�õ�
	BOOL                bTour;                      // �Ƿ�֧���Զ�Ѳ����·
	BOOL                bRemoveTour;                // �Ƿ�֧�����Ѳ��
	BOOL                bPattern;                   // �Ƿ�֧�ֹ켣��·
	BOOL                bAutoPan;                   // �Ƿ�֧���Զ�ˮƽ�ڶ�
	BOOL                bAutoScan;                  // �Ƿ�֧���Զ�ɨ��
	BOOL                bAux;                       // �Ƿ�֧�ָ�������
	BOOL                bAlarm;                     // �Ƿ�֧�ֱ�������
	BOOL                bLight;                     // �Ƿ�֧�ֵƹ�, ���ݼ�����"stuPtzLightingControl"
	BOOL                bWiper;                     // �Ƿ�֧����ˢ
	BOOL                bFlip;                      // �Ƿ�֧�־�ͷ��ת
	BOOL                bMenu;                      // �Ƿ�֧����̨���ò˵�
	BOOL                bMoveRelatively;            // �Ƿ�֧����̨��������궨λ
	BOOL                bMoveAbsolutely;            // �Ƿ�֧����̨���������궨λ
	BOOL                bReset;                     // �Ƿ�֧����̨��λ
	BOOL                bGetStatus;                 // �Ƿ�֧�ֻ�ȡ��̨�˶�״̬����λ����
	BOOL                bSupportLimit;              // �Ƿ�֧����λ
	BOOL                bPtzDevice;                 // �Ƿ�֧����̨�豸
	BOOL                bIsSupportViewRange;        // �Ƿ�֧����̨������

	WORD				wCamAddrMin;		    	// ͨ����ַ����Сֵ
	WORD				wCamAddrMax;			    // ͨ����ַ�����ֵ
	WORD				wMonAddrMin;    			// ���ӵ�ַ����Сֵ
	WORD				wMonAddrMax;	    		// ���ӵ�ַ�����ֵ
	WORD				wPresetMin;			    	// Ԥ�õ����Сֵ
	WORD				wPresetMax;				    // Ԥ�õ�����ֵ
	WORD				wTourMin;    				// �Զ�Ѳ����·����Сֵ
	WORD				wTourMax;	    			// �Զ�Ѳ����·�����ֵ
	WORD				wPatternMin;	    		// �켣��·����Сֵ
	WORD				wPatternMax;		    	// �켣��·�����ֵ
	WORD				wTileSpeedMin;			    // ��ֱ�ٶȵ���Сֵ
	WORD				wTileSpeedMax;    			// ��ֱ�ٶȵ����ֵ
	WORD				wPanSpeedMin;	    		// ˮƽ�ٶȵ���Сֵ
	WORD				wPanSpeedMax;		    	// ˮƽ�ٶȵ����ֵ
	WORD				wAutoScanMin;			    // �Զ�ɨ�����Сֵ
	WORD				wAutoScanMax;    			// �Զ�ɨ������ֵ
	WORD				wAuxMin;		    		// �������ܵ���Сֵ
	WORD				wAuxMax;			    	// �������ܵ����ֵ

	DWORD				dwInterval;				    // ���������ʱ����
	DWORD				dwType;				        // Э������ͣ�0-������̨��1-Զ����̨
	DWORD				dwAlarmLen;				    // Э��ı�������
	DWORD				dwNearLightNumber;		    // �����������,0~4,Ϊ0ʱ��ʾ��֧��
	DWORD				dwFarLightNumber;		    // Զ���������,0~4,Ϊ0ʱ��ʾ��֧��

	DWORD               dwSupportViewRangeType;     // ֧�ֵĿ��������ݻ�ȡ��ʽ����,�ӵ�λ����λ������,Ŀǰ֧��
	                                                // ��1λ:Ϊ1��ʾ֧��"ElectronicCompass" �������̷�ʽ

	DWORD               dwSupportFocusMode;         // ֧�ֵ�֧�ֵĽ���ģʽ����,�ӵ�λ����λ������,��#EM_SUPPORT_FOCUS_MODE
	                  
	char				szName[MAX_PROTOCOL_NAME_LEN];                       // ������Э����
	char                szAuxs[CFG_COMMON_STRING_32][CFG_COMMON_STRING_32];  //��̨�������������б�

	CFG_PTZ_MOTION_RANGE stuPtzMotionRange;         // ��̨ת���Ƕȷ�Χ����λ����
	CFG_PTZ_LIGHTING_CONTROL stuPtzLightingControl; // �ƹ��������
	BOOL				bSupportPresetTimeSection;	// �Ƿ�֧��Ԥ�õ�ʱ������õĹ���
}CFG_PTZ_PROTOCOL_CAPS_INFO;
// ������;Ŀ¼����
typedef struct tagCFG_SPECIAL_DIR_INFO 
{
	char				szBackgroudImageDir[MAX_PATH];	// ��Ļ��ͼĿ¼
	char				szWindowIconDir[MAX_PATH];		// ����ͼ��Ŀ¼
	char				szEventVoiceDir[MAX_PATH];		// ����������ʾ��Ƶ�ļ����Ŀ¼
} CFG_SPECIAL_DIR_INFO;


// �ػ�����ʱ�Զ���������
typedef struct tagCFG_AUTO_STARTUP_DELAY_INFO
{
	BOOL	bEnable;		//�����Ƿ��           
	int		nDelay;			//�ػ�����ʱ����ʱ��,��λ������(ȡֵ��Χ[30, 255])       
}CFG_AUTO_STARTUP_DELAY_INFO;

// ��Ƶ����������(CFG_CAP_CMD_VIDEOINPUT_EX)��չ����
typedef struct tagCFG_CAP_VIDEOINPUT_INFO_EX
{
	BOOL            bSupportDefog;                          // �Ƿ�֧��͸����
	BOOL			bSupportABFFunction;					// �Ƿ�֧���Զ����󽹹���
	BOOL			bSupportImageStabilization;				// �Ƿ�֧�ֵ��ӷ�������

	BOOL			bSupportKillShutLine;					// �Ƿ�֧�����������߹���
	int             nMinKillShutLine;						// �������Сֵ
	int			    nMaxKillShutLine;						// ��������ֵ
}CFG_CAP_VIDEOINPUT_INFO_EX;

// CAN��������
#define MAX_CAN_COUNT	16			// ���CAN����

// CAN ���˲���
typedef enum tagCFG_CAN_POLICY_METHOD
{
	CFG_CAN_POLICY_METHOD_UNKONW,		// δ֪����
	CFG_CAN_POLICY_METHOD_NONE,			// �޹���
	CFG_CAN_POLICY_METHOD_WHITE,		// ������
	CFG_CAN_POLICY_METHOD_BLACK,		// ������
}CFG_CAN_POLICY_METHOD;

typedef struct tagCFG_CANFILTER_INFO
{
	int						nResponseTimeout;			// �ȴ�Ӧ��ʱ(��λ:����)�� �������ݺ󣬵ȴ�3000����󣬽�����·͸��
	int						nRequestTimeout;			// ��������Ӧ��ʱ(��λ:����)�� ����ָ��ʱ��δ�յ����ݣ���Ϊ�������
	int						nFilterPIDCount;			// ���ݺŸ���
	int						nRetFiterPIDCount;			// �������ݺŸ���
	int*					pnFilterPID;				// �������ݺ�
	CFG_CAN_POLICY_METHOD	emPolicy;					// ���˲���
														// ����ǰ��������ϱ�����PID������
														// ����Ǻ��������ϱ�����PID������
														// �޹������������ݶ��ϱ�																
}CFG_CANFILTER_INFO;

typedef struct tagCFG_CANFILTER_LIST
{
	int						nCANCount;			// CAN����
	int						nRetCANCount;		// �豸����CAN����
	CFG_CANFILTER_INFO		stuCANFilter[MAX_CAN_COUNT];			
}CFG_CANFILTER_LIST;

// �۽����޶�Ӧö��
typedef enum tagEM_FOCUS_LIMIT_SELECT_MODE
{
    EM_FOCUS_LIMIT_MODE_MANUAL,                // "Manual" �Զ�
    EM_FOCUS_LIMIT_MODE_AUTO,                  // "Auto"�ֶ�
    EM_FOCUS_LIMIT_MODE_INVALID
}EM_FOCUS_LIMIT_SELECT_MODE;

// �۽����û�����Ϣ��Ԫ
typedef struct tagCFG_VIDEO_IN_FOCUS_UNIT
{
	int                        nMode;                   // �۽�ģʽ, 0-�ر�, 1-�����۽�, 2-�Զ��۽�, 3-���Զ��۽�, 4-�ֶ��۽�
	int                        nSensitivity;            // �۽�������, 0-��, 1-Ĭ��, 2-��
	int                        nIRCorrection;           // �����۽�����, 0-������, 1-����, 2-�Զ�����
	EM_FOCUS_LIMIT_SELECT_MODE emFocusMode;             // �۽�����
	int	                       nFocusLimit;				// �۽�����ֵ, ��λ����
} CFG_VIDEO_IN_FOCUS_UNIT;

// ��ͨ���۽����û�����Ϣ
typedef struct tagCFG_VIDEO_IN_FOCUS	
{
	int						 nChannelIndex;				             // ͨ����
	int						 nVideoInFocusRealNum;		             // ����ʹ�ø���
	CFG_VIDEO_IN_FOCUS_UNIT  stVideoInFocusUnit[MAX_VIDEO_IN_FOCUS]; //ͨ���۽����õ�Ԫ��Ϣ
	
} CFG_VIDEO_IN_FOCUS;

typedef enum tagEM_ANALYSE_MODE
{
	EM_ANALYSE_MODE_REAL_STREAM,                            // ʵʱ��ģʽ     
	EM_ANALYSE_MODE_RECORDFILE_STREAM,                      // ¼���ļ���ģʽ
	EM_ANALYSE_MODE_PICFILE_STREAM,                         // ͼƬ�ļ���ģʽ
}EM_ANALYSE_MODE;

// ���ܷ���ģʽ
typedef struct tagCFG_ANALYSE_MODE
{
	EM_ANALYSE_MODE emMode;                                 // ����ģʽ�����EM_ANALYSE_MODE 
}CFG_ANALYSE_MODE;

// ��̨����Ԥ�õ�ṹ
typedef struct tagPTZ_PRESET
{
	BOOL                 bEnable;                             // ��Ԥ�õ��Ƿ���Ч
	char                 szName[MAX_PTZ_PRESET_NAME_LEN];     // Ԥ�õ�����
	CFG_PTZ_SPACE_UNIT   stPosition;                          // Ԥ�õ������ͷŴ���
}PTZ_PRESET;

// ��̨Ԥ�õ����ö�Ӧ�ṹ
typedef struct tagPTZ_PRESET_INFO
{
	DWORD              dwMaxPtzPresetNum;                     // ���Ԥ�õ����
	DWORD              dwRetPtzPresetNum;                     // ʵ��ʹ��Ԥ�õ����
	PTZ_PRESET         *pstPtzPreset;                         // Ԥ�õ���Ϣ(���������������ڴ�)
}PTZ_PRESET_INFO;

// ����������Ƶͨ������
typedef struct tagCFG_AUDIO_SPIRIT_CHANNE
{
	int				nChannel;				// ��������������Ƶͨ����
	int				nPriority;				// �����������ȼ�, 1~10
	int				nPreset;				// ��Ӧ����Ƶ�������Ԥ�õ�, ����̨һ��0~255
} CFG_AUDIO_SPIRIT_CHANNEL;

// ��������������
typedef struct tagCFG_AUDIO_SPIRIT_LINKAGE 
{
	int				nOutputNum;				// �������������
	int				nOutputChanel[CFG_MAX_LOWER_MATRIX_OUTPUT];	// ͬ�����������(���)���������
} CFG_AUDIO_SPIRIT_LINKAGE;

// ��������
typedef struct tagCFG_AUDIO_SPIRIT 
{
	BOOL				bEnable;			// ʹ��
	int					nAudioLimit;		// ����������ֵ, 0~100
	int					nDelayTime;			// ������ʱʱ��, ��λ: ��
	CFG_AUDIO_SPIRIT_CHANNEL* pstuChannels;	// ����������Ƶͨ������
	int					nChannelCount;		// ��Ƶͨ����
	CFG_AUDIO_SPIRIT_LINKAGE stuLinkage;	// ����������
} CFG_AUDIO_SPIRIT;

// �ϳ�ͨ������
typedef struct tagCFG_COMPOSE_CHANNEL 
{
	CFG_SPLITMODE	emSplitMode;			// �ָ�ģʽ
	int				nChannelCombination[MAX_VIDEO_CHANNEL_NUM]; // ��ģʽ�µĸ��Ӵ�����ʾ����
	int				nChannelCount;			// �ָ������
} CFG_COMPOSE_CHANNEL;

// ��λ�����������
typedef struct tagCFG_LOWER_MATRIX_OUTPUT
{
	char					szName[CFG_COMMON_STRING_128]; // ���ͨ������
	CFG_SPLITMODE			emSplitMode;		// �ָ�ģʽ
	int						nInputs[CFG_MAX_LOWER_MATRIX_INPUT]; // ����ͨ����
	int						nInputCount;		// ����ͨ����
} CFG_LOWER_MATRIX_OUTPUT;

// ��λ������Ϣ
typedef struct tagCFG_LOWER_MATRIX_INFO 
{
	int						nOutputCount;			// ���ͨ����
	CFG_LOWER_MATRIX_OUTPUT	stuOutputs[CFG_MAX_LOWER_MATRIX_OUTPUT]; // ���ͨ������
} CFG_LOWER_MATRIX_INFO;

// ��λ��������
typedef struct tagCFG_LOWER_MATRIX_LIST
{
	int						nMatrixCount;		// ��λ��������
	CFG_LOWER_MATRIX_INFO	stuMatrix[CFG_MAX_LOWER_MATRIX_NUM]; // ��λ��������
} CFG_LOWER_MATRIX_LIST;

// ��ʼ���������
typedef struct tagCFG_DAYTIME_INFO
{
	int					nBeginMonth;		// ��ʼʱ�� �·�
	int					nBeginDay;			// ��ʼʱ�� ����
	int					nEndMonth;			// ����ʱ�� �·�
	int					nEndDay;			// ����ʱ��	����
}CFG_DAYTIME_INFO;

// ʱ�������ֵ����
typedef struct tagCFG_TIMESPEEDLIMIT_INFO
{
	BOOL				bEnable;			// �ٶ����ƿ���
	CFG_DAYTIME_INFO	stuDayTime;			// ʱ��ο�ʼ���������
	int					nDaySpeedLimit;		// ��������ֵ����λkm/h
	int					nNightSpeedLimit;	// ��������ֵ����λkm/h
	CFG_TIME_SECTION	stuTimeSection;		// ����ʱ��η�Χ��������Ч
}CFG_TIMESPEEDLIMIT_INFO;

typedef struct tagCFG_TIMESPEEDLIMIT_LIST
{
	int						nTimeSpeedLimitCount;		// ����ʱ��θ���
	CFG_TIMESPEEDLIMIT_INFO stuTimeSpeedLimit[MAX_TIMESPEEDLIMIT_NUM];
}CFG_TIMESPEEDLIMIT_LIST;

// ������ʾʱ��
typedef struct tagCFG_ALERTTIME_INFO
{
	int				nHour;				// Сʱ
	int				nMinute;			// ����
}CFG_ALERTTIME_INFO;

// ������ʾ����
typedef struct tagCFG_VOICEALERT_INFO
{
	CFG_ALERTTIME_INFO	stuAlertTime;							// ��������ʱ��㣬��ʱ����
	int					nIntervalTime;							// ���Ѽ��ʱ����λ��
	char				szWarnText[CFG_COMMON_STRING_256];		// �����������ݣ��û��Զ���
}CFG_VOICEALERT_INFO;

typedef struct tagCFG_VOICEALERT_LIST
{
	int					nVoiceAlertCount;					// ������ʾ����
	CFG_VOICEALERT_INFO stuVoiceAlert[MAX_VOICEALERT_NUM];
}CFG_VOICEALERT_LIST;

// ������尴��
typedef struct tagCFG_INFRARED_KEY 
{
	char			szName[CFG_COMMON_STRING_32];	// ��尴������
	char			szText[CFG_COMMON_STRING_64];	// ��尴����ʾ���֣���ťlabel
} CFG_INFRARED_KEY;

// �������ģ��
typedef struct tagCFG_INFRARED_BOARD_TEMPLATE 
{
	unsigned int	nID;							// ���ģ����
	char			szName[CFG_COMMON_STRING_64];	// ���Ʒ���ͺŶ���
	unsigned int	nCategory;						// �������, ����, 0-DVD, 1-TV
	int				nKeyNum;						// ��尴������
	CFG_INFRARED_KEY stuKeys[CFG_MAX_INFRARED_KEY_NUM];	// ��尴��
} CFG_INFRARED_BOARD_TEMPLATE;

// �������ģ����
typedef struct tagCFG_INFRARED_BOARD_TEMPLATE_GROUP 
{
	int			nTemplateNum;		// ģ������
	CFG_INFRARED_BOARD_TEMPLATE stuTemplates[CFG_MAX_INFRARED_BOARD_TEMPLATE_NUM];	// �������ģ��
} CFG_INFRARED_BOARD_TEMPLATE_GROUP;

// �������
typedef struct tagCFG_INFRARED_BOARD 
{
	unsigned int	nID;							// �����, Ψһ��ʾ
	char			szName[CFG_COMMON_STRING_64];	// ��������������, �û��Զ���
	unsigned int	nCategory;						// �������, 0-DVD, 1-TV
	int				nCommPort;						// ����ͨѶ�˿�
	unsigned int	nTemplateID;					// ������ģ��ID
} CFG_INFRARED_BOARD;

// ���������
typedef struct tagCFG_INFRARED_BOARD_GROUP
{
	int				nBoardNum;						// �����������
	CFG_INFRARED_BOARD stuBoards[CFG_MAX_INFRARED_BOARD_NUM];	// ���������Ϣ		
} CFG_INFRARED_BOARD_GROUP;

// �豸��������
typedef struct tagCFG_DEVICEKEEPALIVE_INFO
{
	BOOL	bEnable;		// ��������ʹ��
	int		nInterval;		// ����ʱ������������>=10��ֵ����λ����
	int		nFailTimes;		// ����ʧ�ܴ���������ʧ�ܴ��������ֵ��Ϊ�豸����
	int		nWaitBootTime;	// �ȴ�����ӵ���������Ᵽ����������λ����
}CFG_DEVICEKEEPALIVE_INFO;

// �豸�ع����û�����Ϣ
typedef struct tagCFG_VIDEOIN_EXPOSURE_BASE
{
    BOOL        bSlowShutter;           // ������ʹ��

    BYTE        byExposureMode;         // �ع�ģʽ����
    BYTE        byAntiFlicker;			// ����˸ģʽ 0-Outdoor 1-50Hz����˸ 2-60Hz����˸
    BYTE        byCompensation;         // �عⲹ��, [0~14]
    BYTE        byAutoGainMax;          // �Զ���������, [0, 2]
    BYTE        byGain;                 // ���浵λ, [0, 15]
    BYTE        bySlowAutoExposure;     // ���ع�, [0, 15]
    BYTE        byExposureSpeed;        // �ع��ٶȵȼ���0-�Զ��ع⣬1-�ع�ȼ�1��2-�ع�ȼ�2��n-1����ع�ȼ��� n��ʱ�������޵��Զ��ع� n+1�Զ���ʱ���ֶ��ع� (nΪ֧�ֵ��ع�ȼ�)
    BYTE        bySlowSpeed;            // ���ع�ȼ�
    BYTE        byIris;                 // ��Ȧ����, [0~17]
    BYTE        byBacklight;            // ���ⲹ��: ȡֵ��Χȡ�����豸������: 0-�ر� 1-���� 2-ָ�����򱳹ⲹ��
    BYTE        byWideDynamicRange;     // ��ֵ̬ 0-�رգ�1~100-Ϊ��ʵ��Χֵ
    BYTE        byWideDynamicRangeMode; // ��̬ģʽ, 0:�ر�; 1:�ֶ�����; 2:�Զ�����
    BYTE        byGlareInhibition;      // ǿ������, 0:�ر�; 1:��; 2:��; 3:ǿ
    BYTE        byDoubleExposure;       // ˫����֧��, 0:��֧��; 1:֧��˫����ȫ֡��; 2:֧��˫���Ű�֡��; 3:֧��˫����ȫ֡�ʺͰ�֡��
    BYTE        byReserved[2];          // �ֽڶ���
    int         nRecoveryTime;          // �Զ��ع�ָ�, 0-��ʾ���ָ�, ������ʾ�ָ���ʱ��, ��λΪ��

    float       fValue1;                // �Զ��ع�ʱ�����޻����ֶ��ع��Զ���ʱ��, [0.1~80ms]
    float       fValue2;                // �Զ��ع�ʱ������, �費С������, [0.1~80ms]

    CFG_RECT    stuBacklightRegion;     // ���ⲹ������
}CFG_VIDEOIN_EXPOSURE_BASE;

// �豸�ع�����
typedef struct tagCFG_VIDEOIN_EXPOSURE_INFO
{
    DWORD                       dwMaxExposureNum;       // ���õ�������
    DWORD                       dwRetExposureNum;       // ʵ��ʹ�õ�������(��ѯʱ����ʵ�ʽ�������, ��װʱ���մ�ֵ������װ)
    CFG_VIDEOIN_EXPOSURE_BASE   *pstuVideoInExposure;   // �ع�������Ϣ
}CFG_VIDEOIN_EXPOSURE_INFO;

//////////////////////////////////////////////////////////////////////////
// �Ž���������

// �Զ��忪�ŷ�ʽ
typedef enum tagCFG_DOOR_OPEN_METHOD
{
	CFG_DOOR_OPEN_METHOD_UNKNOWN = 0,
	CFG_DOOR_OPEN_METHOD_PWD_ONLY,		// ֻ�������뿪��
	CFG_DOOR_OPEN_METHOD_CARD,			// ֻ����ˢ������
	CFG_DOOR_OPEN_METHOD_PWD_OR_CARD,	// �����ˢ������
	CFG_DOOR_OPEN_METHOD_CARD_FIRST,	// ��ˢ�������뿪��
	CFG_DOOR_OPEN_METHOD_PWD_FIRST,		// �������ˢ������
	CFG_DOOR_OPEN_METHOD_SECTION,		// ��ʱ�ο���
}CFG_DOOR_OPEN_METHOD;


// �Ž���������
typedef struct tagCFG_ACCESS_GENERAL_INFO
{
	char                szOpenDoorAudioPath[MAX_ADDRESS_LEN];   // ������Ƶ�ļ�·��
	char                szCloseDoorAudioPath[MAX_ADDRESS_LEN];  // ������Ƶ�ļ�·��
	char                szInUsedAuidoPath[MAX_ADDRESS_LEN];     // ������Ƶ�ļ�·��
	char                szPauseUsedAudioPath[MAX_ADDRESS_LEN];  // ��ͣʹ����Ƶ�ļ�·�� 
	char                szNotClosedAudioPath[MAX_ADDRESS_LEN];  // ��δ����Ƶ�ļ�·��
	char                szWaitingAudioPath[MAX_ADDRESS_LEN];    // �ȴ���ʾ��Ƶ�ļ�·��
	int                 nUnlockReloadTime;                      // ����������Ӧ���ʱ��,��λ�룬ȡֵ10��15(Ĭ��ֵ)��20
	int                 nUnlockHoldTime;                        // �����������ʱ��,��λ�룬ȡֵ1��2(Ĭ��)��3��4��5��6��9��15�� 

	// ����
	bool                abProjectPassword;
	BYTE				byReserved[3];

	char				szProjectPassword[MAX_PASSWORD_LEN];	// ��������
}CFG_ACCESS_GENERAL_INFO;

// �Ž�״̬
typedef enum CFG_ACCESS_STATE
{
	ACCESS_STATE_NORMAL,                                        // ��ͨ
	ACCESS_STATE_CLOSEALWAYS,                                   // ����
	ACCESS_STATE_OPENALWAYS,                                    // ���� 
}CFG_ACCESS_STATE; 

// �Ž�ģʽ
typedef enum CFG_ACCESS_MODE
{
	ACCESS_MODE_HANDPROTECTED,                                  // ����ģʽ
	ACCESS_MODE_SAFEROOM,                                       // ��������ģʽ    
	ACCESS_MODE_OTHER,                                          // ����
}CFG_ACCESS_MODE;


// ��ʱ�ο���
typedef struct tagCFG_DOOROPEN_TIMESECTION_INFO
{
	CFG_TIME_PERIOD			stuTime;				// ʱ���
	CFG_DOOR_OPEN_METHOD	emDoorOpenMethod;		// ����ģʽ
}CFG_DOOROPEN_TIMESECTION_INFO;

#define MAX_DOOR_TIME_SECTION		4				// �Ž�ÿ���ʱʱ���������

// �Ž��¼�����
typedef struct tagCFG_ACCESS_EVENT_INFO
{
	char                szChannelName[MAX_NAME_LEN];	// �Ž�ͨ������
	CFG_ACCESS_STATE    emState;						// �Ž�״̬
	CFG_ACCESS_MODE     emMode;							// �Ž�ģʽ
	int					nEnableMode;					// �Ž�ʹ�ܵ�ƽֵ, 0:�͵�ƽ��Ч(�ϵ�����); 1:�ߵ�ƽ��Ч(ͨ������);
	BOOL                bSnapshotEnable;				// �¼�����ץͼʹ��
	
    // ����
	bool                abDoorOpenMethod;
    bool                abUnlockHoldInterval;
	bool                abCloseTimeout;
	bool                abOpenAlwaysTimeIndex;
	bool                abHolidayTimeIndex;
	bool                abBreakInAlarmEnable;
	bool				abRepeatEnterAlarmEnable;
	bool                abDoorNotClosedAlarmEnable;
	bool				abDuressAlarmEnable;
	bool                abDoorTimeSection;
	bool				abSensorEnable;
	BYTE				byReserved;

	CFG_DOOR_OPEN_METHOD	emDoorOpenMethod;			// ���ŷ�ʽ
	int					nUnlockHoldInterval;			// ��������ʱ��(�Զ�����ʱ��),��λ����,[250, 20000]
	int					nCloseTimeout;					// ���ų�ʱʱ��, ������ֵδ�ػᴥ����������λ��,[0,9999];0��ʾ����ⳬʱ
	int					nOpenAlwaysTimeIndex;			// ����ʱ���, ֵΪCFG_ACCESS_TIMESCHEDULE_INFO���õ������±�
	int					nHolidayTimeRecoNo;				// ������ʱ���, ֵΪ���ռ�¼���ļ�¼��ţ���ӦNET_RECORDSET_HOLIDAY��nRecNo
	BOOL				bBreakInAlarmEnable;			// ���뱨��ʹ��
	BOOL				bRepeatEnterAlarm;				// ��Ǳ����ʹ��
	BOOL				bDoorNotClosedAlarmEnable;		// ��δ�ر���ʹ��
	BOOL				bDuressAlarmEnable;				// в�ȱ���ʹ��
	CFG_DOOROPEN_TIMESECTION_INFO	stuDoorTimeSection[WEEK_DAY_NUM][MAX_DOOR_TIME_SECTION];// ��ʱ�ο�����Ϣ
	BOOL				bSensorEnable;					// �Ŵ�ʹ��
}CFG_ACCESS_EVENT_INFO;



// �Ž�ˢ��ʱ���
typedef struct tagCFG_ACCESS_TIMESCHEDULE_INFO 
{
	CFG_TIME_SECTION		stuTime[WEEK_DAY_NUM][MAX_DOOR_TIME_SECTION];	// ˢ��ʱ���
	BOOL					bEnable;										// ʱ���ʹ�ܿ���
}CFG_ACCESS_TIMESCHEDULE_INFO;

//////////////////////////////////////////////////////////////////////////
// ����������������

// ÿ���������Ʋ���
enum EM_CFG_DAY3GFLUXTACTIC
{
	EM_CFG_DAY3GFLUXTACTIC_BYFLUX = 0,	// ������
	EM_CFG_DAY3GFLUXTACTIC_BYTIME,		// ��ʱ��
};

// �������������
enum EM_CFG_APN
{
	EM_CFG_APN_CTNET = 0,				// CTNET
};

// ������������
enum EM_CFG_DAY3GFLUXACTION
{
	EM_CFG_DAY3GFLUXACTION_NOTHING = 0,	// �޶���
	EM_CFG_DAY3GFLUXACTION_3GNETDOWN,	// 3G����
};

typedef struct tagCFG_WIRELESS_INFO
{
	BOOL			bEnable;						// 2G����ʹ��
	int				nKeepAlive;						// ����ʱ��, ��λΪ�룬0��ʾһֱ���ӣ����Զ��Ͽ�
	EM_CFG_APN		emAPN;							// �����2G��������
	char			szUseName[MAX_USERNAME_LEN];	// �û���
	char			szPassword[MAX_PASSWORD_LEN];	// ����
	EM_CFG_DAY3GFLUXTACTIC	emDay3GFluxTactic;		// ÿ���������Ʋ���
	DWORD			dwDay3GFluxUp;					// ÿ������ʹ������, MB���߷���
	DWORD			dwDay3GFluxUse;					// ���յ���������, MB���߷���
	EM_CFG_DAY3GFLUXACTION	emDay3GFluxAction;		// ������������
}CFG_WIRELESS_INFO;

#define MAX_CONNECTION_TYPE_LEN		32	// ���ӷ�ʽ�����ֳ���

// �Ǳ�ʱ������
enum emCFG_REPORTWEEKDAY
{
	emReportWeekDay_DoNotReport = -1,	// ���Ǳ�
	emReportWeekDay_Sunday,				// ÿ���ն�ʱ�Ǳ�
	emReportWeekDay_Monday,				// ÿ��һ��ʱ�Ǳ�
	emReportWeekDay_Tuesday,			// ÿ�ܶ���ʱ�Ǳ�
	emReportWeekDay_Wednesday,			// ÿ������ʱ�Ǳ�
	emReportWeekDay_Thursday,			// ÿ���Ķ�ʱ�Ǳ�
	emReportWeekDay_Friday,				// ÿ���嶨ʱ�Ǳ�
	emReportWeekDay_Saturday,			// ÿ������ʱ�Ǳ�
	emReportWeekDay_Everyday,			// ÿ�춨ʱ�Ǳ�
};

// ����������������
typedef struct tagCFG_ALARMSERVER_INFO
{
	BOOL			bEnable;								// ʹ��
	char			szProtocol[MAX_PROTOCOL_NAME_LEN];		// Э������, Ŀǰ֧��"DAHUA"
	char			szConnection[MAX_CONNECTION_TYPE_LEN];	// ���ӷ�ʽ
	char			szAddress[MAX_ADDRESS_LEN];				// IP��ַ��������
	int				nPort;									// �˿ں�
	char			szUserName[MAX_USERNAME_LEN];			// �û���
	char			szPsw[MAX_PASSWORD_LEN];				// ����
	emCFG_REPORTWEEKDAY	emReportWeekDay;					// �Ǳ���
	int				nHour;									// �Ǳ�ʱ����ʱ
	int				nMinute;								// �Ǳ�ʱ���ķ�
	int				nSecond;								// �Ǳ�ʱ������
}CFG_ALARMSERVER_INFO;

#define MAX_ALARMSERVER_NUM		8

// ��������ʹ�õı������ļ��������ĵ�����
typedef struct tagCFG_ALARMCENTER_INFO
{
	CFG_ALARMSERVER_INFO	stuMainServer;						// ��������ʹ�õı������ķ�����
	int						nBackupAlarmServerNum;				// ���ñ������ķ���������Ŀ
	CFG_ALARMSERVER_INFO	stuBackupAlarmServer[MAX_ALARMSERVER_NUM];	// ���ñ������ķ�����������
}CFG_ALARMCENTER_INFO;

//////////////////////////////////////////////////////////////////////////
// ��������������
#define	MAX_SCENE_COUNT	8		//	����龰ģʽ����
// �龰ģʽ
enum emCFG_SCENE_MODE
{	
	emCFG_SCENE_MODE_UNKNOWN,			// δ֪ģʽ
	emCFG_SCENE_MODE_OUTDOOR,			// ���ģʽ
	emCFG_SCENE_MODE_INDOOR,			// �ڼ�ģʽ
};
typedef struct tagCFG_SCENE_INFO
{
	emCFG_SCENE_MODE emName;							// ģʽ��
	int				 nAlarmInChannelsCount;				// ����ͨ������
	int				 nRetAlarmInChannelsCount;			// ʵ�ʷ��صı���ͨ������
	int*			 pnAlarmInChannels;					// ���õı�������ͨ�����б����û������ڴ�
}CFG_SCENE_INFO;
typedef struct tagCFG_COMMGLOBAL_INFO	// =>CFG_CMD_COMMGLOBAL
{
	BOOL				bEnable;								// TRUE: ����; FALSE: ����; ��������̨�豸��������ͨ��
	BOOL				bSceneEnable;							// �Ƿ������龰ģʽ
	emCFG_SCENE_MODE	emCurrentScene;							// ��ǰѡ����龰ģʽ
	int					nSceneCount;							// �龰ģʽ��Ч����
	CFG_SCENE_INFO		stuScense[MAX_SCENE_COUNT];			// �龰ģʽ���壬ÿ��ģʽ��Ӧһ������
}CFG_COMMGLOBAL_INFO;

// ģ������������ͨ������
typedef struct tagCFG_ANALOGALARM_INFO	// =>CFG_CMD_ANALOGALARM
{
	BOOL				bEnable;									// ʹ�ܿ���(��̨�豸���ڲ����Ҹ�ͨ����ʹ��ʱΪ��·)
	char				szChnName[MAX_CHANNELNAME_LEN];				// ����ͨ������
	float				fUpperLimit;								// ��������
	float				fLowerLimit;								// ��������
	int					nSensitivity;								// ������, ��λ���ٷֱ�
	float				fCompensation;								// ����ֵ, ���ݴ��������Ͷ���
	float				fLimit1;									// ������1
	float				fLimit2;									// ������2
	float				fLimit3;									// ������3
	float				fLimit4;									// ������4
	BYTE				byMode;										// ����ģʽ, �����ʾ, ��������ֵ1111��1110��1100��1000��0000
																	// 1��ʾ����������ֵ��0��ʾ���ڱ�����ֵ
																	// ģʽ�����ҷֱ��Ӧ4��������ֵ, ���ε���
																	// ����1110��ʾ������1��2��3��������ֵ, �����ڵ�4��������ֵ
	BYTE				byReserve[3];								// �����ֽ�
	CFG_ALARM_MSG_HANDLE	stuEventHandler;						// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���
	EM_SENSE_METHOD		emSense;									// ��������ʽ
	char				szSensorType[CFG_COMMON_STRING_64];			// ����������
    int                 nSlot;                                      // ����ַ, 0��ʾ����ͨ��, 1��ʾ�����ڵ�һ�������ϵ���չͨ��, 2��3...�Դ�����, -1��ʾ��Ч
	int                 nLevel1;                                    // ��һ��������ַ, ��ʾ�����ڵ�nSlot�����ϵĵ�nLevel1��̽�������Ǳ�, ��0��ʼ, -1��ʾ��Ч
    bool                abLevel2;                                   // ��ʾnLevel2�ֶ��Ƿ����
    int                 nLevel2;                                    // �ڶ���������ַ, ��ʾ�����ڵ�nLevel1�����Ǳ��ϵ�̽�������, ��0��ʼ
}CFG_ANALOGALARM_INFO;

// �������ͨ����״̬������
typedef struct tagCFG_ALARMOUT_INFO		// =>CFG_CMD_ALARMOUT
{
	int					nChannelID;									// ����ͨ����(0��ʼ)
	char				szChnName[MAX_CHANNELNAME_LEN];				// ����ͨ������
	char				szOutputType[MAX_NAME_LEN];					// �������, �û��Զ���
	int					nOutputMode;								// ���ģʽ, 0-�Զ�����, 1-ǿ�Ʊ���, 2-�رձ���
}CFG_ALARMOUT_INFO;


// ʱ������(NTP)
typedef enum __EM_CFG_TIME_ZONE_TYPE
{
	EM_CFG_TIME_ZONE_0,								// {0, 0*3600,"GMT+00:00"}
	EM_CFG_TIME_ZONE_1,								// {1, 1*3600,"GMT+01:00"}
	EM_CFG_TIME_ZONE_2,								// {2, 2*3600,"GMT+02:00"}
	EM_CFG_TIME_ZONE_3,								// {3, 3*3600,"GMT+03:00"}
	EM_CFG_TIME_ZONE_4,								// {4, 3*3600+1800,"GMT+03:30"}
	EM_CFG_TIME_ZONE_5,								// {5, 4*3600,"GMT+04:00"}
	EM_CFG_TIME_ZONE_6,								// {6, 4*3600+1800,"GMT+04:30"}
	EM_CFG_TIME_ZONE_7,								// {7, 5*3600,"GMT+05:00"}
	EM_CFG_TIME_ZONE_8,								// {8, 5*3600+1800,"GMT+05:30"}
	EM_CFG_TIME_ZONE_9,								// {9, 5*3600+1800+900,"GMT+05:45"}
	EM_CFG_TIME_ZONE_10,							// {10, 6*3600,"GMT+06:00"}
	EM_CFG_TIME_ZONE_11,							// {11, 6*3600+1800,"GMT+06:30"}
	EM_CFG_TIME_ZONE_12,							// {12, 7*3600,"GMT+07:00"}
	EM_CFG_TIME_ZONE_13,							// {13, 8*3600,"GMT+08:00"}
	EM_CFG_TIME_ZONE_14,							// {14, 9*3600,"GMT+09:00"}
	EM_CFG_TIME_ZONE_15,							// {15, 9*3600+1800,"GMT+09:30"}
	EM_CFG_TIME_ZONE_16,							// {16, 10*3600,"GMT+10:00"}
	EM_CFG_TIME_ZONE_17,							// {17, 11*3600,"GMT+11:00"}
	EM_CFG_TIME_ZONE_18,							// {18, 12*3600,"GMT+12:00"}
	EM_CFG_TIME_ZONE_19,							// {19, 13*3600,"GMT+13:00"}
	EM_CFG_TIME_ZONE_20,							// {20, -1*3600,"GMT-01:00"}
	EM_CFG_TIME_ZONE_21,							// {21, -2*3600,"GMT-02:00"}
	EM_CFG_TIME_ZONE_22,							// {22, -3*3600,"GMT-03:00"}
	EM_CFG_TIME_ZONE_23,							// {23, -3*3600-1800,"GMT-03:30"}
	EM_CFG_TIME_ZONE_24,							// {24, -4*3600,"GMT-04:00"}
	EM_CFG_TIME_ZONE_25,							// {25, -5*3600,"GMT-05:00"}
	EM_CFG_TIME_ZONE_26,							// {26, -6*3600,"GMT-06:00"}
	EM_CFG_TIME_ZONE_27,							// {27, -7*3600,"GMT-07:00"}
	EM_CFG_TIME_ZONE_28,							// {28, -8*3600,"GMT-08:00"}
	EM_CFG_TIME_ZONE_29,							// {29, -9*3600,"GMT-09:00"}
	EM_CFG_TIME_ZONE_30,							// {30, -10*3600,"GMT-10:00"}
	EM_CFG_TIME_ZONE_31,							// {31, -11*3600,"GMT-11:00"}
	EM_CFG_TIME_ZONE_32,							// {32, -12*3600,"GMT-12:00"}
}EM_CFG_TIME_ZONE_TYPE;

// ʱ��ͬ������������
typedef struct tagCFG_NTP_INFO
{
	BOOL				bEnable;									// ʹ�ܿ���
	char				szAddress[MAX_ADDRESS_LEN];					// IP��ַ��������
	int					nPort;										// �˿ں�
	int					nUpdatePeriod;								// �������ڣ���λΪ����
	EM_CFG_TIME_ZONE_TYPE emTimeZoneType;							// ʱ��
	char				szTimeZoneDesc[MAX_NAME_LEN];				// ʱ������
}CFG_NTP_INFO;

// ��������
typedef struct tagCFG_ALARMBELL_INFO
{
	int					nDutyRation;								// ռ�ձ�
}CFG_ALARMBELL_INFO;

#define MAX_MSG_NUMBER_LEN	32				// ���ź������󳤶�
#define MAX_RECEIVER_NUM	100				// ���ն����û��������Ŀ

// ��������
typedef enum EM_MSG_TYPE
{
	EM_MSG_UNKNOWN = 0,												// δ֪����
	EM_MSG_SMS,														// SMS����
	EM_MSG_MMS,														// MMS����
};

// ϵͳ�¼���������/���ŷ��͵�����
typedef struct tagCFG_EVENT_MSG_SENDING_INFO
{
	BOOL				bEnable;									// ʹ�ܿ���
	EM_MSG_TYPE			emMsgType;									// ���͵���Ϣ������
	char				szTitle[MAX_NAME_LEN];						// ����, Ҳ���Ƕ���/���ŵĵ�һ������
	DWORD				dwReceiverCount;							// �����˺���ĸ���
	char				szReceiverNumbersList[MAX_RECEIVER_NUM][MAX_MSG_NUMBER_LEN];// �����˺���
}CFG_EVENT_MSG_SENDING_INFO;

// �ƶ����ҵ������
typedef struct tagCFG_MOBILE_INFO
{
	CFG_EVENT_MSG_SENDING_INFO	stuEventMsgSending;					// ϵͳʱ�䴥���ķ��Ͷ���/���ŵ�����
}CFG_MOBILE_INFO;

#define MAX_CONTACT_NUM		100				// ��ϵ�������Ŀ

// �绰������������
typedef struct tagCFG_PHONEEVENTNOTIFY_INFO
{
	BOOL				bEnable;									// ʹ�ܿ���
	DWORD				dwContactCount;								// ���к���ĸ���
	char				szContactNumbersList[MAX_CONTACT_NUM][MAX_MSG_NUMBER_LEN];// ���к����б�
}CFG_PHONEEVENTNOTIFY_INFO;

// �绰������������
enum CFG_EM_SIGNALTRANSMIT_MODE
{
	CFG_EM_SIGNALTRANSMIT_ERROR = 0,								// δ֪ģʽ
	CFG_EM_SIGNALTRANSMIT_DTMF_5S,									// "DTMF 5/S" - DTMFģʽ����
	CFG_EM_SIGNALTRANSMIT_DTMF_10S,									// "DTMF 10/S" - DTMFģʽ�첦
};
enum CFG_EM_PSTN_PROTOCOL_TYPE
{
	CFG_EM_PSTN_PROTOCOL_ERROR = 0,									// δ֪����
	CFG_EM_PSTN_PROTOCOL_CID,										// "CID" - Contact ID Protocol
};
typedef struct tagCFG_PSTN_ALARM_SERVER_INFO
{
	char							szName[MAX_NAME_LEN];						// �绰������������
	char							szNumber[MAX_PHONE_NUMBER_LEN];				// �绰�������Ľ��ջ�����
																				// "057188888888PPP888",��ʽΪ[����][ͣ��ʱ��][�ֻ�����]������P��ʾͣ��2�롣
	CFG_EM_PSTN_PROTOCOL_TYPE		emProtocol;									// Э�����ͣ�
	CFG_EM_SIGNALTRANSMIT_MODE		emMode;										// �źŴ���ģʽ																															
	int								nTryCount;									// ���ų��Դ���
	int								nDelay;										// ������ʱ����λ����
	char							szAccount[MAX_PHONE_NUMBER_LEN];			// �û�����
}CFG_PSTN_ALARM_SERVER_INFO;

typedef struct tagCFG_PSTN_ALARM_CENTER_INFO
{
	BOOL						bEnable;								// ʹ�ܿ���
	int							nServerCount;							// �绰��������������
	CFG_PSTN_ALARM_SERVER_INFO	stuPSTNAlarmServer[MAX_PSTN_SERVER_NUM];		// �绰����������
}CFG_PSTN_ALARM_CENTER_INFO;

// �����������
typedef struct tagCFG_AUDIO_OUTPUT_VOLUME
{
	int				nAudioOutputCount;									// ʵ����Ƶ���ͨ������
	char			szAudioOutputVolume[MAX_AUDIO_OUTPUT_NUM];			// ÿ��Ԫ�ض�Ӧһ����Ƶ���ͨ��������ֵ,��Χ[0, 100]
}CFG_AUDIO_OUTPUT_VOLUME;


// ������������
typedef struct tagCFG_ALARMKEYBOARD_INFO
{
	BOOL			bEnable;								// ʹ�ܿ���
	char			szProtocolName[MAX_PROTOCOL_NAME_LEN];	// Э������
	int				nPort;									// ʹ�õĴ��ڶ˿ں�
	int				nAddress;								// �豸��ַ����������Ϲ��˶�������豸��ͨ�������ַ����
	CFG_COMM_PROP	stuCommAttr;							// ��������
}CFG_ALARMKEYBOARD_INFO;

// ��ȡ�ļ���������
typedef struct tagCFG_CAP_FILEMANAGER
{
	int			nMaxUploadFileSize;		// �����ϴ��ļ��Ĵ�С, ��λ: �ֽ�
}CFG_CAP_FILEMANAGER;

// ��ȡ�豸������������
typedef struct tagCFG_CAP_EVENTMANAGER_INFO
{
	BOOL				bTimeSectionEnable;                               // �Ƿ�֧��ʱ���¼���Ӧ
	BOOL				bRecordEnable;                                    // �Ƿ�֧��¼��
	BOOL				bAlarmOutEnable;                                  // �Ƿ�֧�ֱ������
	BOOL				bPtzLinkEnable;                                   // �Ƿ�֧����̨����
	BOOL				bSnapshotEnable;                                  // �Ƿ�֧�ֿ���
	BOOL				bMailEnable;                                      // �Ƿ�֧�ַ����ʼ�
	BOOL				bBeepEnable;                                      // �Ƿ�֧�ַ���
	BOOL				bDejitterEnable;                                  // �Ƿ�֧��ȥ����
	BOOL				bTipEnable;										  // �Ƿ�֧�ֱ�����Ϣ����ʾ
	BOOL				bMonitorTourEnable;								  // �Ƿ�֧����ѯ��������
	BOOL				bMMSEnable;										  // �Ƿ�֧�ֶ���Ϣ
	BOOL				bSupportAlarmBell;								  // �Ƿ�֧�־������
	BOOL				bSupportAccessControl;							  // �Ƿ�֧���Ž�����
	BOOL				bSupportAlarmServer;							  // �Ƿ�֧���ϴ�������������
	BOOL				bSupportPtzLinkDelay;							  // �Ƿ�֧����̨�����ӳ�
	BOOL				bSupportPSTNAlarmServer;						  // �Ƿ�֧���ϴ����绰��������
}CFG_CAP_EVENTMANAGER_INFO;

// ��Դ��������
typedef struct tagCFG_POWERFAULT_ONE
{
	BOOL			bEnable;									// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;						// ��������
}CFG_POWERFAULT_ONE;

typedef struct tagCFG_POWERFAULT_INFO
{
	int				nPowerCount;								// ��Դ����
	CFG_POWERFAULT_ONE stuPowerFault[MAX_POWER_NUM];			// ��������
}CFG_POWERFAULT_INFO;

// �������ֱ���(���𱨾�)����
typedef struct tagCFG_CHASSISINTRUSION_INFO
{
	BOOL			bEnable;									// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;						// ��������
}CFG_CHASSISINTRUSION_INFO;

// �����¼�����
typedef struct tagCFG_URGENCY_INFO 
{
	BOOL			bEnable;									// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;						// ��������
}CFG_URGENCY_INFO;

/************************************************************************
** ��չ����ģ��
***********************************************************************/
// ��չģ�鱨����������
typedef struct tagCFG_EXALARMINPUT_INFO
{
	CFG_ALARMIN_INFO		stuAlarmIn;						// ���������������� CFG_ALARMIN_INFO
	
}CFG_EXALARMINPUT_INFO;

// ��չģ�鱨���������
typedef struct tagCFG_EXALARMOUTPUT_INFO
{
	char		szChnName[MAX_CHANNELNAME_LEN];				// ����ͨ������
	int			nOutputMode;								// ���ģʽ, 0-�Զ�����, 1-ǿ�Ʊ���, 2-�رձ���
}CFG_EXALARMOUTPUT_INFO;

// ��չģ�鱨��������
typedef struct tagCFG_EXALARMBOX_INFO
{
	BOOL			bEnable;								// ʹ�ܿ���
	char			szProtocolName[MAX_PROTOCOL_NAME_LEN];	// Э������
	int				nPort;									// ʹ�õĴ��ڶ˿ں�
	int				nAddress;								// �豸��ַ
	CFG_COMM_PROP	stuCommAttr;							// ��������
}CFG_EXALARMBOX_INFO;

// ��չ������Э������
enum CFG_EM_EXALARM_PROTOCOL_TYPE
{
	CFG_EM_EXALARM_PROTOCOL_ERROR,								// δ֪����
	CFG_EM_EXALARM_PROTOCOL_DH_ALARMBOX,						// DH_AlarmBox �󻪱�����Э��
};


// ��չģ�鱨��������
typedef struct tagCFG_CAP_EXALARM_INFO
{	
	int					 nAlarmInCount;											// ��չ����ģ���������
	int					 nAlarmOutCount;										// ��չ����ģ���ٳ�����
	int				 	 nMaxDelay;												// ��ʱ�����������ʱʱ��,��λΪ�룬ֻ��֧����ʱ����ʱ���ֶβ���Ч��
	int					 nDefenceAreaTypeNum;									// ��������������,Ϊ0��ʾ�޴��ֶ�ʱ�������벻��Ϊ����ʹ�á�
	EM_CFG_DEFENCEAREATYPE	emDefenceAreaType[MAX_ALARM_DEFENCE_TYPE_NUM];		// ֧�ַ������� 
	int					 nExAlarmChannelNum;									// ��չģ�鱨��ͨ����,Ϊ�˱��ּ�����,��Ϊ0ʱ��ʾÿ��ͨ��֧���������͵Ĵ�����
	CFG_EXALARM_SENSE_METHOD stuExAlarmChannel[MAX_EXALARM_CHANNEL_NUM];		// ����ͨ������
	int					 nProtocolNum;											// ֧�ֵ�Э������
	CFG_EM_EXALARM_PROTOCOL_TYPE emProtocolType[MAX_EXALARMBOX_PROTOCOL_NUM];	// ��չ����ģ�鱨����֧�ֵ�Э������	
}CAP_EXALARM_INFO;

// ��չģ�鱨����������
typedef struct tagCFG_CAP_EXALARMBOX_INFO 
{
	int nAlarmInCount; // ��չ����ģ���������
	int nAlarmOutCount; // ��չ����ģ��������� 
}CFG_CAP_EXALARMBOX_INFO; 

// ��ѯ��¼������������
typedef struct tagCFG_CAP_RECORDFINDER_INFO 
{
	int nMaxPageSize; // ����ҳ���� 
}CFG_CAP_RECORDFINDER_INFO;


// ���������� ==>CFG_CMD_SENSORSAMPLING
typedef struct  tagCFG_SENSORSAMPLING_INFO 
{
	int			nDetectionPeriod;			// �������, ��λ���룬���������ʵʱ�ϴ��¶�״̬
	int			nStorageItem;				// �洢��Ϣ��, ��λ���������豸������д�ļ���ʽ���ɵ�����0~5000��
}CFG_SENSORSAMPLING_INFO;

// ���� ==>CFG_CMD_STP
typedef struct tagCFG_STP_INFO 
{
	BOOL			bEnable;				// ʹ��
}CFG_STP_INFO;

#define DH_MAX_ZONE_NUM					(256)	// ��������Ŀ
#define DH_MAX_PUBLIC_SUBSYSTEM_NUM		(8)		// ��󹫹���ϵͳ��Ŀ

// ������ϵͳ���� ==>CFG_CMD_ALARM_SUBSYSTEM
typedef struct tagCFG_ALARM_SUBSYSTEM_INFO 
{
	char		szName[CFG_COMMON_STRING_128];	// ����
	int			nZoneNum;						// ���ط�����Ŀ
	int			anZone[DH_MAX_ZONE_NUM];		// ���ط�����
	int			nExZoneNum;						// ��չ������Ŀ
	int			anExZone[DH_MAX_ZONE_NUM];		// ��չ������
	int			nDisableDelay;					// ��ʱ����ʱ�䣨������ʱ��, ��λΪ��
	int			nEnableDelay;					// ��ʱ����ʱ�䣨�˳���ʱ��, ��λΪ��
	BOOL		bIsPublic;						// �Ƿ�Ϊ������ϵͳ
	int			nPublicSubSystem;				// ������������ϵͳ��Ŀ
	int			anPublicSubSystem[DH_MAX_PUBLIC_SUBSYSTEM_NUM];// ���������Ĺ�����ϵͳ
}CFG_ALARM_SUBSYSTEM_INFO;

// ��ص�ѹ������ ==>CFG_CMD_BATTERY_LOW_POWER
typedef struct tagCFG_BATTERY_LOW_POWER_INFO 
{
	BOOL		bEnable;						// ʹ��
	CFG_ALARM_MSG_HANDLE stuEventHandler;		// ��������
}CFG_BATTERY_LOW_POWER_INFO;


// ץͼͨ�������������� ==>CFG_CMD_SNAPLINKAGE
typedef struct tagCFG_SNAPLINKAGE_INFO 
{
    int         nChannelNum;                    // ��Ƶͨ��������ģ����ͨ����Ŀ
    int         anAnalogAlarm[DH_MAX_ZONE_NUM]; // ��Ƶͨ��������ģ��ͨ����
}CFG_SNAPLINKAGE_INFO;

// ��Ƶ��������
typedef struct tagCFG_AUDIO_INPUT 
{
    char        szAudioSource[CFG_COMMON_STRING_256];   // ������ƵԴ. �����Ƶͨ�����������ɶ�·�ϳɣ���|�ָ�.
                                                        // ����"Mic|LineIn|Remote" ��ʾ����Ƶͨ����Mic��LineIn��Զ��ͨ������Ƶ���빹��.
                                                        // "Coaxial" ͬ�����Ƶ
                                                        // "BNC" ����BNC����Ƶ
                                                        // "HDCVI_BNC" Զ��HDCVI�豸��Ƶ
                                                        // "LineIn" ��������
                                                        // "Mic" ��˷�����
                                                        // "MicOut" ������
                                                        // "Remote" Զ��ͨ��(���Ի��л�ͨ�������壬��ʾ���л�������ΪԶ��ͨ��ʱ������ǰԶ��ͨ������Ƶ��Ϊ��Ƶ����)
}CFG_AUDIO_INPUT;

// �ʼ��ϱ��豸״��
typedef struct tagCFG_HEALTHREPORT_INFO 
{
    BOOL			bEnable;				// ʹ��
    int             nInterval;              // �ʼ����ͼ��,��λΪ��,��Χ��0~3600
}CFG_HEALTHREPORT_INFO;

// �ʼ��������� ==>CFG_CMD_EMAIL
typedef struct tagCFG_EMAIL_INFO 
{
    BOOL			bEnable;				                            // ʹ��
    BOOL            bSslEnable;                                         // �Ƿ���ҪSSL����
    BOOL            bTlsEnable;                                         // �Ƿ���ҪTLS����
    char            szAddress[MAX_ADDRESS_LEN];                         // SMTP������IP��ַ��������
    int             nPort;                                              // �˿ں�
    char            szUserName[MAX_USERNAME_LEN];                       // �ʻ���
    char            szPassword[MAX_PASSWORD_LEN];                       // ����
    BOOL            bAnonymous;                                         // �����ʼ���true������false������
    char            szSendAddress[MAX_ADDRESS_LEN];                     // �����˵�ַ
    int             nRetReciversNum;                                    // ��Ч�ռ�����
    char            szReceivers[MAX_RECEIVER_NUM][MAX_ADDRESS_LEN];     // �ռ����б�
    char            szTitle[MAX_MAILTITLE_LEN];                         // �ʼ�����ؼ���
    BOOL            bOnlyAttachment;                                    // �¼������ʼ���ֻ���ʹ��������ʼ�
    BOOL            bAttachEnable;                                      // �ʼ�����ʹ��
    int             nSendInterv;                                        // ͬһ�¼�����С�ʼ����ͼ������λΪ��
    
    bool            abHealthReport;                                     // ����,Ϊtrueʱ,stuHealthReport��Ч
    BYTE            byReserved[3];
    CFG_HEALTHREPORT_INFO   stuHealthReport;                            // �ʼ��ϱ��豸״��
}CFG_EMAIL_INFO;

#define MAX_TRANSFER_SERVER_NUM          10                             // ��������������
// ���������ļ�����
typedef struct tagTRAFFIC_TRANSFER_OFFLINE_INFO
{
    BOOL            bEnable;                                                // ʹ��
    int             nType;                                                  // 0: ʹ��IP��ַ; 1:ʹ��MAC��ַ
    int             nIpAddrNum;                                             // ���ص�IP��ַ����
    char            szIpAddr[MAX_TRANSFER_SERVER_NUM][MAX_ADDRESS_LEN];     // IP��ַ��������
    int             nMacAddrNum;                                            // ���ص�mac��ַ����
    char            szClientID[MAX_TRANSFER_SERVER_NUM][MAX_ADDRESS_LEN];   // mac��ַ

}TRAFFIC_TRANSFER_OFFLINE_INFO;

#define MAX_DEVCOMM_NUM          16                                     // ��󴮿ڸ���
// ���Ĵ�����������-������������
typedef struct tagCFG_DEVCOMM_SUBSCRIBE_INFO
{
    int             nReadCycle;                                         // ���ڶ�ȡ���,��λ: ��    
}CFG_DEVCOMM_SUBSCRIBE_INFO;

// ���Ĵ�����������
typedef struct tagCFG_DEVCOMM_SUBSCRIBE
{
    int                             nSubscribeInfoNum;                  // �����������ø���
    CFG_DEVCOMM_SUBSCRIBE_INFO      stuSubscribeInfo[MAX_DEVCOMM_NUM];  // ���Ĵ����������ã���һ�����飬ÿ��Ԫ�ض�Ӧһ������    
}CFG_DEVCOMM_SUBSCRIBE;

// ��λ״̬��Ӧ�ĳ�λָʾ��
typedef enum tagEM_CFG_PARKINGSPACE_LIGHT_COLOR
{
    EM_CFG_PARKINGSPACE_LIGHT_RED,                                      // ��ɫ
    EM_CFG_PARKINGSPACE_LIGHT_YELLOW,                                   // ��ɫ
    EM_CFG_PARKINGSPACE_LIGHT_BLUE,                                     // ��ɫ 
    EM_CFG_PARKINGSPACE_LIGHT_GREEN,                                    // ��ɫ
    EM_CFG_PARKINGSPACE_LIGHT_PURPLE,                                   // ��ɫ
    EM_CFG_PARKINGSPACE_LIGHT_WHITE,                                    // ��ɫ
    EM_CFG_PARKINGSPACE_LIGHT_PINK,                                     // ��ɫ
}EM_CFG_PARKINGSPACE_LIGHT_COLOR;

// ָʾ��״̬
typedef enum tagEM_CFG_PARKINGSPACE_LIGHT_STATE
{
    EM_CFG_PARKINGSPACE_LIGHT_OFF,                                      // ��
    EM_CFG_PARKINGSPACE_LIGHT_ON,                                       // ��
    EM_CFG_PARKINGSPACE_LIGHT_GLINT,                                    // ��˸
}EM_CFG_PARKINGSPACE_LIGHT_STATE;

#define CFG_MAX_PARKINGSPACE_LIGHT_NUM       8

typedef struct tagCFG_PARKINGSPACE_LIGHT_STATE
{
    BYTE                            bySpaceFreeLinght[CFG_MAX_PARKINGSPACE_LIGHT_NUM]; // ��λ����״̬��ɫ,��ɫö��ֵ��Ϊ�����±꣬����Ԫ��ֵ��ʾָʾ��״̬����bySpaceFreeLinght[0]=1,��ʾ��ɫָʾ����
    int                             nSpaceFreeLinghtNum;
    BYTE                            bySpaceFullLinght[CFG_MAX_PARKINGSPACE_LIGHT_NUM]; // ��λ��״̬��ɫ����ɫö��ֵ��Ϊ�����±꣬����Ԫ��ֵ��ʾָʾ��״̬����bySpaceFullLinght[1]=1,��ʾ��ɫָʾ����
    int                             nSpaceFullLinghtNum;
}CFG_PARKINGSPACE_LIGHT_STATE;

/************************************************************************
** �ӿڶ���
***********************************************************************/
// �����¼����͸���dhnetsdk.h���������ı�������
typedef int  (CALLBACK *fALARMEvent)(DWORD dwAlarmType, void* pAlarmInfo, DWORD dwStructSize, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser);

// �ص���ʽ�������ݽ�����dwDataType��ʾ���ݽ����õ�����
typedef int  (CALLBACK *fAnalyzerData)(DWORD dwDataType, void* pDataInfo, DWORD dwStructSize, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser);

// ������ѯ����������Ϣ
CLIENT_API BOOL  CALL_METHOD CLIENT_ParseData(char* szCommand, char* szInBuffer, LPVOID lpOutBuffer, DWORD dwOutBufferSize, void* pReserved);

// ���Ҫ���õ�������Ϣ
CLIENT_API BOOL  CALL_METHOD CLIENT_PacketData(char* szCommand, LPVOID lpInBuffer, DWORD dwInBufferSize, char* szOutBuffer, DWORD dwOutBufferSize);

// ¼�񱨾��¼�����
CLIENT_API BOOL  CALL_METHOD CLIENT_ParseAnalyzerEventData(LPVOID lpInBuffer, DWORD dwInBufferSize, fALARMEvent cbEvent, LDWORD dwUser);

// �ص���ʽ���ݽ���
CLIENT_API BOOL CALL_METHOD CLIENT_ParseDataByCallback(LPVOID lpInBuffer, DWORD dwInBufferSize, fAnalyzerData cbAnalyzer, LDWORD dwUser);
#ifdef __cplusplus
}
#endif

#endif // DHCONFIGSDK_H

