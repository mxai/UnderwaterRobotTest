using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace vvlaistick
{
    public delegate void m_messagecallback(IntPtr hHandle, int wParam, int lParam, IntPtr context);   
    public delegate void pvsnetchancallback(string sername,string url,ushort port,string serialno,string[] mac,int channels,int ch,bool login,IntPtr hChHandle);
    public delegate void m_nomalvideo(IntPtr pbuff,int headsize,int datasize,int timetick,int biskeyframe, IntPtr context);
    public delegate void m_nomalaudio(IntPtr pbuff,int headsize,int datasize,int timetick,int biskeyframe, IntPtr context);
    public delegate void notify(int devtype,IntPtr m_sername,IntPtr m_url,Byte m_mac,Int32 m_webport,Int32 m_localport,IntPtr m_submask,IntPtr m_getway,IntPtr m_multiip,IntPtr m_dns,Int32 m_multiport,int channel);
    public struct camera
    {
        public static string IP1;
        public static string Port1;
        public static string UserName1;
        public static string UserPwd1;
        public static string Channel1;
        public static int handle1=-1;

        public static string IP2;
        public static string Port2;
        public static string UserName2;
        public static string UserPwd2;
        public static string Channel2;
        public static int handle2=-1;

        public static string IP3;
        public static string Port3;
        public static string UserName3;
        public static string UserPwd3;
        public static string Channel3;
        public static int handle3=-1;

        public static string IP4;
        public static string Port4;
        public static string UserName4;
        public static string UserPwd4;
        public static string Channel4;
        public static int handle4=-1;
    }
    ////LauInterop m_nomalaudio

    public enum E_PTZ_COMMAND
    {
        ZOOM_TELE,
        ZOOM_WIDE,
        FOCUS_NEAR,
        FOCUS_FAR,
    };

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    public struct RECT
        {
            public int Left;
            public int Top;
            public int Right;
            public int Bottom;
        }
  
    public struct CHANNEL_CLIENTINFO
    {

        [MarshalAsAttribute(UnmanagedType.LPStr)]
        public string m_sername;                    //server name

        [MarshalAsAttribute(UnmanagedType.LPStr)]
        public string m_username;                   //user name

        [MarshalAsAttribute(UnmanagedType.LPStr)]
        public string m_password;                   //password

        public ushort m_tranType;                    //transmit type   
        public ushort m_playstart;                   //is start view
        public byte m_ch;                            //channel
        public IntPtr m_hVideohWnd;                  //video wnd handle
        public IntPtr m_hChMsgWnd;                   //message wnd handle
        public uint m_nChmsgid;                      //message id  
        public int m_buffnum;                        //buff num
        public int m_useoverlay;                     //is use overlay
        public int nColorKey;                       //color key(reserved)

        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 40)]
        public string url;                           //url
        //public delegate void IpCameraEventHandler(Int32 handle, int wParam, int lparam, IntPtr context);
        [MarshalAs(UnmanagedType.FunctionPtr)]
        public m_messagecallback callback;
        //IntPtr context;

        //void (WINAPI *m_messagecallback)(LONG hHandle,int wParam,int lParam,void *context); //message callback function
        //	void *context;                      //message callback context
    };

    public struct VSNETRVSINFO
    {
        [MarshalAsAttribute(UnmanagedType.LPStr)]
        public string m_rvsbindurl;
        public ushort m_rvsbindport;
    }
    public class LauInterop
    {
        #region 博世通变焦摄像机

        public enum E_REALDATA_TYPE
        {
            REALDATA_HEAD,   /**< 实时流的头数据 */
            REALDATA_VIDEO,  /**< 实时视频流数据（包括复合流和音视频分开的视频流数据） */
            REALDATA_AUDIO  /**< 实时音频流数据 */
        }

        public enum E_ENCODE_TYPE
        {
            ENCODE_MPEG4 = 1,   /**< MPEG4编码 */
            ENCODE_H264,        /**< H264编码 */
            ENCODE_H264_Hi3510, /**< H264 3510编码 */
            ENCODE_MJPEG,       /**< MJPEG编码，暂无用 */
        }

        public struct S_REALDATA_INFO
        {
            public uint lChannel;    /**< 通道号，从0开始 */
            public uint lStreamMode; /**< 码流类型，0-主码流，1-子码流 */
            public E_ENCODE_TYPE eEncodeType; /**< 编码类型 */
        }
        public enum E_RECORD_TYPE
        {
            RECORD_AVI,
            RECORD_IFV,
        }

        public enum E_PIC_TYPE
        {
            PIC_JPEG,
            PIC_BMP,
        }
        #endregion

        #region 博世通普通摄像机
        //开始预览
        // CNET_APIIMPORT LONG  __stdcall VSNET_ClientStart(char *m_url,CHANNEL_CLIENTINFO *m_pChaninfo,WORD wserport = 3000,int streamtype = 0);       
        [DllImport("NetClient.dll")]
        public static extern Int32 VSNET_ClientStart([MarshalAs(UnmanagedType.LPStr)]string url,
             IntPtr info, short port, short streamtype);
        //云台控制
        //CNET_APIIMPORT BOOL	 __stdcall VSNET_ClientPTZCtrl(LONG hHandle,int type,int value,int priority = 0, char *extrabuff = NULL, int extrasize = 0);
        [DllImport("NetClient.dll")]
        public static extern int VSNET_ClientPTZCtrl(Int32 handle, int type, int value, int priority, IntPtr extrabuff, int extrasize);
        //,  [MarshalAs(UnmanagedType.LPStr)]string extrabuff, int extrasize);
        //停止预览
        //CNET_APIIMPORT BOOL  __stdcall VSNET_ClientStop(LONG hHandle);
        [DllImport("NetClient.dll")]
        public static extern int VSNET_ClientStop(Int32 handle);
        //[DllImport("NetClient.dll")]
        //public static extern bool VSNET_ClientStop(Int32 hanle);
        //获取设备状态
        //CNET_APIIMPORT LONG  __stdcall VSNET_ClientGetState(LONG hHandle);
        [DllImport("NetClient.dll")]
        public static extern Int32 VSNET_ClientGetState(Int32 handle);
        //初始化SDK
        //CNET_APIIMPORT BOOL  __stdcall VSNET_ClientStartup(UINT m_nMessage,HWND m_hWnd,void 
        //(WINAPI *m_messagecallback)(LONG hHandle,int wParam,INT_PTR lParam,void *context) = NULL,void *context = NULL, char *key = NULL);
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientStartup(uint m_nMessage, IntPtr m_hWnd,m_messagecallback collback , IntPtr conntex, IntPtr key);
        //停止SDK
        //CNET_APIIMPORT BOOL  __stdcall VSNET_ClientCleanup();
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientCleanup();
        //启动声音预览
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientPlayAudio(int hHandle);
        //停止声音预览
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientStopAudio(int hHandle);
        //音量控制
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientAudioVolume(int hHandle, string m_Volume);
        //获得实际音量
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientGetVolumeLevel(int hHandle);

        //检测设备是否在线
        // BOOL VSNET_ClientCheckChanBeOnLine(LONG hHandle,)
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientCheckChanBeOnLine(Int32 handle);        
        //抓拍图片BMP格式
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientCapturePicture(Int32 handle,string m_filename);
        //录像mp4
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientStartMp4Capture(Int32 handle, string m_FileName);
        //停止录像
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientStopMp4Capture(Int32 handle);
        //播放录像打开本地文件
        [DllImport("PlayerSDK.dll")]
        public static extern int LCPLAYM4_OpenFile(string sfilename, bool m_createindex);
        //播放初始化
        [DllImport("PlayerSDK.dll")]
        public static extern bool LCPLAYM4_InitPlayer(string hwnd);
        //卸载播放SDK
        [DllImport("PlayerSDK.dll")]
        public static extern bool LCPLAYM4_FreePlayer();
        //播放视频
        [DllImport("PlayerSDK.dll")]
        public static extern bool LCPLAYM4_Play(int hHandle, IntPtr hwnd);
        //刷新视频
        [DllImport("PlayerSDK.dll")]
        public static extern bool LCPLAYM4_RefreshDisplay(Int64 handle);
        //停止播放
        [DllImport("PlayerSDK.dll")]
        public static extern bool LCPLAYM4_Stop(int hHandle);
        //刷新显示界面
        [DllImport("PlayerSDK.dll")]
        public static extern bool LCPLAYM4_RefreshDisplay(int hHandle, RECT rect);
        //暂停播放
        [DllImport("PlayerSDK.dll")]
        public static extern bool LCPLAYM4_Pause(int hHandle);
        //获取文件时长
        [DllImport("PlayerSDK.dll")]
        public static extern int LCPLAYM4_GetFileTime(int hHandle,int firsttime);
        //获取文件当前播放时间
        [DllImport("PlayerSDK.dll")]
        public static extern int LCPLAYM4_GetPlayedTime(int hHandle);
        //根据时间重新设置播放位置
        [DllImport("PlayerSDK.dll")]
        public static extern bool LCPLAYM4_SetPlayedTime(int hHandle, int retime);
        //快放
        [DllImport("PlayerSDK.dll")]
        public static extern bool LCPLAYM4_Fast(int hHandle);
        //慢放
        [DllImport("PlayerSDK.dll")]
        public static extern bool LCPLAYM4_Slow(int hHandle);
        //抓取BMP图片
        [DllImport("PlayerSDK.dll")]
        public static extern bool LCPLAYM4_CaptureBmp(int hHadle,string FileName);
        //启动录像剪切
        [DllImport("PlayerSDK.dll")]
        public static extern bool LCPLAYM4_SetFileCutStart(int hHandle, string FileName);
        //停止录像剪切
        [DllImport("PlayerSDK.dll")]
        public static extern int LCPLAYM4_SetFileCutEnd(int hHandle);
        //录像ASF
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientStartASFFileCap(int hHandle, string m_FileName, bool m_bbroad);
        //停止录像ASF
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientStopCapture(int hHandle);
        //启动原始码流
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientStartNomalCap(int hHandle, m_nomalvideo nomalvideo, IntPtr pvideocontext, m_nomalaudio nomalaudio, IntPtr paudiocontext);
        //停止原始码流
        [DllImport("NetClient.dll")]
        public static extern bool VSNET_ClientStopNomalCap(int hHandle);
        //初始化
        [DllImport("CamSearch.dll")]
        public static extern bool CAMSEAR_Startup();
        //搜索
        [DllImport("CamSearch.dll")]
        public static extern bool CAMSEAR_Searchcam(int m_wait, notify notify, string localurl);
        //H系列初始化解码库
        [DllImport("HDVSDK_Play.dll")]
        public static extern bool IPCPLAY_Init();
        //开始流播放
        [DllImport("HDVSDK_Play.dll")]
        public static extern Int32 IPCPLAY_OpenStream(string pStreamHead, long lStreamHeadSize);

        [DllImport("NetClient.dll")]
        public static extern bool VSNET_RVSStartServer(IntPtr zhuinfo);

        [DllImport("NetClient.dll")]
        public static extern bool VSNET_RVSRegSerCheckCallback(pvsnetchancallback pvnetcallback);
        #endregion

        #region 博世通变焦摄像机
        [DllImport("IPCSDK_Net.dll")]
        public static extern bool IPCNET_Init();

        [DllImport("IPCSDK_Net.dll")]
        public static extern bool IPCNET_Cleanup();

        [DllImport("IPCSDK_Net.dll")]
        public static extern int IPCNET_Login(string sDevIP, uint nDevPort, string sUserName, string sPassword);

        [DllImport("IPCSDK_Net.dll")]
        public static extern bool IPCNET_Logout(int lLoginID);

        public delegate void CBRealData(int lRealHandle, E_REALDATA_TYPE eDataType, IntPtr pBuffer, uint lBufSize, IntPtr pUserData);

        [DllImport("IPCSDK_Net.dll")]
        public static extern int IPCNET_StartRealData(int lLoginID, ref S_REALDATA_INFO pRealDataInfo, CBRealData fRealData, IntPtr pUserData);

        [DllImport("IPCSDK_Net.dll")]
        public static extern bool IPCNET_StopRealData(int lRealHandle);

        [DllImport("IPCSDK_Net.dll")]
        public static extern int IPCNET_GetLastError();

        [DllImport("IPCSDK_Net.dll")]
        public static extern bool IPCNET_PTZControl(int lLoginID, int nChannel, E_PTZ_COMMAND ePTZCommand, int iParam1, int iiParam2, bool bStop);

        //回放
        public delegate void CBDrawOSD(int lHandle,IntPtr hdc,IntPtr pUserData);
        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_Init();

        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_Cleanup();

        [DllImport("HDVSDK_Play.dll")]
        public static extern int HDVPLAY_OpenStream(IntPtr pStreamHead, uint lStreamHeadSize);

        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_InputData(int lPlayHandle, IntPtr pBuffer, uint lStreamHeadSize);

        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_CloseStream(int lPlayHandle);

        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_Play(int lPlayHandle, IntPtr hPlayWnd, bool bCloseSound = false);

        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_Stop(int lPlayHandle);

        [DllImport("HDVSDK_Play.dll")]
        public static extern int HDVPLAY_GetLastError();

        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_StartRecord(int lHandle, string FileName, E_RECORD_TYPE rRecorsType);

        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_StopRecord(int lHandle);

        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_CapturePicture(int lHandle, string FileName, E_PIC_TYPE ePicType);

        [DllImport("HDVSDK_Play.dll")]
        public static extern int HDVPLAY_OpenFile(string FileName);

        [DllImport("HDVSDK_Play.dll")]
        public static extern int HDVPLAY_GetFileTime(int lHandle);

        [DllImport("HDVSDK_Play.dll")]
        public static extern int HDVPLAY_GetPlayTime(int lHandle);

        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_SetPlayTime(int lHandle, int lSecond);

        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_SetDrawFunCallBack(int lHandle,CBDrawOSD fDrawOSD,IntPtr pUserData);

        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_Pause(int lPlayHandle);

        [DllImport("HDVSDK_Play.dll")]
        public static extern bool HDVPLAY_Resume(int lPlayHandle);

        //字符叠加
        [DllImport("IPCSDK_CGI.dll")]
        public static extern bool IPCCGI_SetValue(string sUrl, byte[] sValue, string UserName, string UserPwd, uint Watitime, uint Port = 80);
        #endregion
    }
}
