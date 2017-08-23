using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.ComponentModel;
using System.Drawing;

namespace vvlaistick
{    
 
    public delegate void fDisConnect(int lLoginID, string pchDVRIP, int nDVRPort, IntPtr dwUser);
    public delegate void fRealDataCallBack(int lRealHandle, uint dwDataType, IntPtr pBuffer, uint dwBufSize, IntPtr dwUser);
    public delegate void fRealDataCallBackEx(int lRealHandle,uint dwDataType, IntPtr pBuffer, uint dwBufSize,int param, IntPtr dwUser);
    public delegate void fRealPlayDisConnect(int lRealHandle,EM_REALPLAY_DISCONNECT_EVENT_TYPE dwEventype,int param, IntPtr dwUser);
    public delegate void fHaveReConnect(int lLoginID,string pchDVRIP,int nDVRPort,IntPtr dwUser);
    public delegate void fMessCallBack(int lCommand,int lLoginID,string pBuf,int dwBuflen,string pchDVRIP,int nDVRPort,IntPtr dwUser);
    public delegate void fDrawCallBack(int lLoginID, int lPlayHandle, IntPtr hDC, IntPtr dwUser);
    public struct NET_CLIENT_STATE
    {

    }

    public enum PLAY_MODE
    {
        STREAME_REALTIME = 0,
        STREAME_FILE = 1,
    }

    public enum EM_REALPLAY_DISCONNECT_EVENT_TYPE
    {
        DISCONNECT_EVENT_REAVE,
        DISCONNECT_EVENT_NETFORBID,
        DISCONNECT_EVENT_SUBCONNECT
    }
    public enum REALPLAY_TYPE
    {
        DH_RType_RealPlay,
        DH_RType_Multiplay,
        DH_RType_RealPlay_0,
        DH_RType_RealPlay_1,
        DH_RType_RealPlay_2,
        DH_RType_RealPlay_3,
        DH_RType_Multiplay_1,
        DH_RType_Multiplay_4,
        DH_RType_Multiplay_8,
        DH_RType_Multiplay_9,
        DH_RType_Multiplay_16
    }
    public enum PLAY_COMMAND
    {
        Start = 0,
        Pause = 1,
        ReSume = 2,
        Stop = 3,
        OpenFile = 4,
        CloseFile = 5,
        Fast = 6,
        Slow = 7,
        OneByOne = 8,
        OneByOneBack = 9,
        CatchPic = 10,
        GetCurrentFrameNum = 11,
        SetCurrentFrameNum = 12,
        GetCurrentFrameRate = 13,
        GetFileTotalFrames = 14,
        GetFileTotalTime = 15,
        GetPlayedTime = 16,
        GetPlayedTimeEx = 17,
        SetPlayedTimeEx = 18,
        GetColor = 19,
        SetColor = 20,
        PlaySound = 21,
        StopSound = 22,
        PlaySoundShare = 23,
        StopSoundShare = 24,
        SetVolume = 25,
        GetVolume = 26,
        AdjustWaveAudio = 27,
        GetPlayPos = 28,
        SetPlayPos = 29,
        GetPictureSize = 30,
        ToBegin = 31,
        ToEnd = 32,
        OpenStream = 33,
        InputData = 34,
        CloseStream = 35,
        OpenStreamEx = 36,
        InputVideoData = 37,
        InputAudioData = 38,
        CloseStreamEx = 39,
    }
    public struct DEV_STATE
{
	NET_CLIENT_STATE cState;
	int dError;
	int dFull;
    Byte[] shelter;
    Byte[] soundalarm;
    Byte[] almDecoder;
}
    public struct DeviceNode
    {
        public string UserName;
        public string Name;
        public string IP;
        public int LoginID;
        public NET_DEVICEINFO Info;
        public int nChnNum;
        public DEV_STATE State;
        public int TotalKbps;
        public int MAX_Kbps;
        public bool bIsOnline;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct NET_DEVICEINFO
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 0x30)]
        public byte[] sSerialNumber;
        public byte byAlarmInPortNum;
        public byte byAlarmOutPortNum;
        public byte byDiskNum;
        public byte byDVRType;
        public byte byChanNum;
        public byte byLeftLogTimes;
    }

    public struct NET_CHN_COUNT_INFO
    {
        public int dwSize;
        public int nMaxTotal;
        public int nCurTotal;
        public int nMaxLocal;
        public int nCurLocal;
        public int nMaxRemote;
        public int nCurRemote;
    }

    public struct NET_DEV_CHN_COUNT_INFO
    {
        public int deSize;
        public NET_CHN_COUNT_INFO stuVideoIn;
        public NET_CHN_COUNT_INFO stuVideoOut;  
    }

    //[StructLayout(LayoutKind.Sequential)]
    public struct DH_CHANNEL_OSDSTRING
    {
     
       public bool bEnable;
       public int dwPosition;
          //[MarshalAs(UnmanagedType.ByValArray, SizeConst = 20)]
       public string szStrings;
    }
    public struct DH_DVR_VIDEOOSD_CFG
    {
        public int dwSize;
        public DH_DVR_VIDEOITEM StPSDTitleOpt;
        public byte bReservered;
    }

    public struct DH_DVR_VIDEOITEM
    {
        public DH_DVR_VIDEO_WIDGET StOSD_POS;
        public string SzOSD_Name;
    }    
    public struct DH_DVR_VIDEO_WIDGET
    {
        public int rgbaFrontground;
        public int rgbaBackground;
        public RECT rcRelativePos;
        public bool bPreviewBlend;
        public bool bEncodeBlend;
        public byte bReserved;
    }
    public struct RECT
    {
        int left;
        int top;
        int right;
        int bottom;
    }
    public struct SNAP_PARAMS
    {
        public uint Channel;
        public uint Quality;
        public uint ImageSize;
        public uint mode;
        public uint InterSnap;
        public uint CmdSerial;
        public uint Reserved;
    }

    public class DHSDK
    {      
        [DllImport("dhnetsdk.dll")]
        public static extern bool CLIENT_Init(fDisConnect cbDisConnect, IntPtr deUser);
        [DllImport("dhnetsdk.dll")]
        public static extern int CLIENT_Login(string pchDVRIP, ushort wDVRPort, string pchUserName, string pchPassword, out NET_DEVICEINFO lpDeviceInfo, out int error);
        [DllImport("dhnetsdk.dll")]
        public static extern int CLIENT_GetLastError();
        [DllImport("dhnetsdk.dll")]
        public static extern void CLIENT_SetConnectTime(int nWaitTime, int nTryTimes);
        [DllImport("dhnetsdk.dll")]
        public static extern void CLIENT_SetAutoReconnect(fHaveReConnect cbAutoConnect, IntPtr dwUser);
        [DllImport("dhnetsdk.dll")]
        public static extern void CLIENT_SetDVRMessCallBack(fMessCallBack cbmesscallback, IntPtr dwUser);
        [DllImport("dhnetsdk.dll")]
        public static extern void CLIENT_RigisterDrawFun(fDrawCallBack cbDarw, IntPtr dwUser);
        [DllImport("dhnetsdk.dll")]
        public static extern void CLIENT_SetSubconnCallBack();
        [DllImport("dhnetsdk.dll")]
        public static extern int CLIENT_StartListenEx(int lLoginID);
        [DllImport("dhnetsdk.dll")]
        public static extern int CLIENT_RealPlay(int lLoginID, int nChannelID, IntPtr hWnd);
        [DllImport("dhnetsdk.dll")]
        public static extern int CLIENT_RealPlayEx(int lLoginID, int nChannelID, IntPtr hWnd, REALPLAY_TYPE dhRealPlay);
        [DllImport("dhnetsdk.dll")]
        public static extern int CLIENT_StartRealPlay(int lLoginID, int nChannelID, IntPtr hWnd, REALPLAY_TYPE rType, fRealDataCallBackEx cbRealData, fRealPlayDisConnect cbDisconnect, int dwuser, int waittime = 1000);
        [DllImport("dhnetsdk.dll")]
        public static extern bool CLIENT_SetRealDataCallBackEx(int lRealPlay, fRealDataCallBackEx cbRealData, IntPtr dwUser, uint dwFlag);
        [DllImport("dhnetsdk.dll")]
        public static extern bool CLIENT_SetRealDataCallBack(int lRealHandle, fRealDataCallBack cbRealData, IntPtr dwUser);
        [DllImport("dhnetsdk.dll")]
        public static extern bool CLIENT_CapturePicture(int lRealhandle, string filename);
        [DllImport("dhnetsdk.dll")]
        public static extern bool CLIENT_SaveRealData(int lRealhandle, string filename);
        [DllImport("dhnetsdk.dll")]
        public static extern bool CLIENT_StopSaveRealData(int lRealhandle);
        [DllImport("dhnetsdk.dll")]        
        public static extern bool CLIENT_SetupChannelName(int lLoginID, StringBuilder pBuf, int pBuflen);
        [DllImport("dhnetsdk.dll")]
        public static extern bool CLIENT_SetupChannelOsdString(int lLoginID, int nChannelID,ref DH_CHANNEL_OSDSTRING struOsdString, Int32 nbuflen);
        [DllImport("dhnetsdk.dll")]
        public static extern bool CLIENT_SetDevConfig(int lLoginID, string OSD, int chn, DH_DVR_VIDEOOSD_CFG videoosd, int osdsize, int waittime);
        [DllImport("dhnetsdk.dll")]
        public static extern bool CLIENT_GetDevConfig(int lLoginID,string OSD,int chn);
        [DllImport("dhnetsdk.dll")]
        public static extern bool CLIENT_SnapPicture(int lLoginID, SNAP_PARAMS par);
        //[DllImport("dhnetsdk.dll")]
        //public static extern  void CLIENT_SetSnapRevCallBack()
       




        [DllImport("dhplay.dll")]
        public static extern bool PLAY_InputAudioData(int nPort, IntPtr pBuf, uint nSize);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_InputData(int nPort, IntPtr pBuf, uint nSize);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_InputVideoData(int nPort, IntPtr pBuf, uint nSize);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_OpenStream(int nPort, IntPtr pFileHeadBuf, uint nSize, uint nBufPoolSize);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_OpenStreamEx(int nPort, IntPtr pFileHeadBuf, uint nSize, uint nBufPoolSize);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_SetStreamOpenMode(int nPort, uint nMode);
        [DllImport("dhplay.dll")]
        public static extern uint PLAY_GetCurrentFrameNum(int nPort);
        [DllImport("dhplay.dll")]
        public static extern uint PLAY_GetCurrentFrameRate(int nPort);
        [DllImport("dhplay.dll")]
        public static extern UInt32 PLAY_GetFileTotalFrames(int nPort);
        [DllImport("dhplay.dll")]
        public static extern uint PLAY_GetFileTime(int nPort);
        [DllImport("dhplay.dll")]
        public static extern uint PLAY_GetPlayedTime(int nPort);
        [DllImport("dhplay.dll")]
        public static extern uint PLAY_GetPlayedTimeEx(int nPort);
        [DllImport("dhplay.dll")]
        public static extern uint PLAY_GetVolume(int nPort);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_Play(int nPort, IntPtr hWnd);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_CatchPic(int nPort, string sFileName);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_GetFreePort(int Port);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_OpenFile(int Port, string FileName);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_Pause(int Port, bool Pause);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_Stop(int nPort);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_CloseFile(int Port);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_Fast(int Port);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_Slow(int Port);
        [DllImport("dhplay.dll")]
        public static extern bool PLAY_SetPlayedTimeEx(int Port, int Time);
    }
}
