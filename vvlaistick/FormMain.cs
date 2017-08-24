using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Runtime.Serialization.Formatters.Binary;
using System.Collections;
using System.Globalization;
using System.Diagnostics;
using System.Threading;
using System.IO;
using System.IO.Ports;
using System.Drawing.Drawing2D;
using System.Xml;
using System.Xml.Linq;
using System.Xml.XPath;
using System.Text.RegularExpressions;
using CCWin;
using CCWin.SkinClass;
using CCWin.SkinControl;
using Microsoft.Win32;

namespace vvlaistick
{
    public struct JOYINFOEX
    {
        public int wSize;public int wFlags;public int wXpos;public int wYpos;public int wZpos;public int wRpos;
        public int wUpos;public int wVpos;public int wButtons;public int dwButtonNumber;public int wPOV;public int dwReserved1;public int dwReserved2;
    }
    public partial class FormMain : Skin_Mac
    {
        [DllImport("winmm.dll")]
        public static extern int joyGetPosEx(uint uJoyID, ref JOYINFOEX pji);
     
        #region 系统参数
        public SerialPort commstick = new SerialPort(); private StringBuilder builderstick = new StringBuilder();
        public SerialPort comm = new SerialPort(); private StringBuilder builder = new StringBuilder();      
        Byte[] commbyte = new Byte[24] { 0x66, 0x66, 0x66, 0x66, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0xF3 };               
        bool StickOK = false;
        bool commclose = false; public bool commListening = false;
        bool commstickclose = false; public bool commstickListening = false;
        string byte4A = "00";
        string byte4B = "0";    //液压驱动
        string byte4C = "0";    //灯
        string byte4D = "0";    //镜头切换
        string byte4E = "0";    //开关框
        string byte4F = "00";
        public bool initok = false; public int SelectPlay = -1;              
        string port = null;string stick = null; string filepath = null;
        private int loginID = 0; int realplay1 = -1; bool videoing1 = false;
        int realplay2 = -1; bool videoing2 = false;
        public fDisConnect cbDisConnect; private NET_DEVICEINFO deviceInfo;

        bool ScreenShotFlag = false;
        #endregion

        #region 初始化
        public FormMain()
        {
            InitializeComponent();
            System.Diagnostics.Process currentprocess = System.Diagnostics.Process.GetCurrentProcess();
            System.Diagnostics.Process[] myProcesses = System.Diagnostics.Process.GetProcessesByName(currentprocess.ProcessName);
            if (myProcesses.Length > 1)
            {
                MessageBox.Show("当前程序已运行！", "提示");
                Process.GetCurrentProcess().Kill();
                this.Close();
                this.Dispose();
                Application.ExitThread();
                Application.Exit();
            }            
        }
     
        private void Form1_Load(object sender, EventArgs e)
        {                        
            LoadParameterXml();        //导入端口，文件保存路径，如果没有则重新生成新的配置文件并读入
            DHDVRStart();              //启动摄像头，并显示图像数据
            ControlCOMEnable();        //初始化数据接收
            lblCOM_Click(null, null);  //打开串口
            ControlCOMStickEnable();   //接收仿真摇杆控制数据
            lblStick_Click(null, null);//打开仿真摇杆
        }
      
        #endregion

        #region 大华DVR
        private void DHDVRStart()
        {
            cbDisConnect = new fDisConnect(DataCallBack);
            bool initOK = DHSDK.CLIENT_Init(cbDisConnect, this.Handle);
            deviceInfo = new NET_DEVICEINFO();
            int error = 0;
            loginID = DHSDK.CLIENT_Login("192.168.1.20", 37777, "admin", "admin", out deviceInfo, out error);
            if (loginID != 0)
            {
                realplay1 = DHSDK.CLIENT_RealPlay(loginID, 0, Play1.Handle);
                realplay2 = DHSDK.CLIENT_RealPlay(loginID, 1, Play2.Handle);
            }
        }

        public void DataCallBack(int lLoginID, string pchDVRIP, int nDVRPort, IntPtr dwUser)
        {           
            if (dwUser == IntPtr.Zero)
            {
                return;
            }           
        }
        #endregion    

        #region 接收串口数据
        private void ControlCOMEnable()
        {
            comm.PortName = port;
            comm.BaudRate = 115200;
            comm.DataReceived += comm_DataReceived;
        }
        private void comm_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {           
            if (commclose) return;
            commListening = true;            
            int n = comm.BytesToRead;
            byte[] buf = new byte[n];          
            comm.Read(buf, 0, n);
            builder.Clear();
             
            this.Invoke((EventHandler)(delegate
            {
                try
                {                    
                    if (buf.Length >= 13)
                    {
                        if ((buf[0] == 0xFF) && (buf[1] == 0xFE) && (buf[2] == 0xFF) && (buf[3] == 0xFE))
                        {
                            Int32 JD1UD = buf[4] + buf[5] * 256;
                            if (JD1UD > 0)
                            {
                                lbl1UD.Text = JD1UD.ToString();
                            }
                            else
                            {
                                lbl1UD.Text = "0";
                            }
                            Int32 JD1LR = buf[6] + buf[7] * 256;
                            if (JD1LR > 0)
                            {
                                lbl1LR.Text = JD1LR.ToString();
                            }
                            else
                            {
                                lbl1LR.Text = "0";
                            }
                            Int32 JD2UD = buf[8] + buf[9] * 256;
                            if (JD2UD > 0)
                            {
                                lbl2UD.Text = JD2UD.ToString();
                            }
                            else
                            {
                                lbl2UD.Text = "0";
                            }
                            Int32 JDALR = buf[10] + buf[11] * 256;
                            if (JDALR > 0)
                            {
                                lblALR.Text = JDALR.ToString();
                            }
                            else
                            {
                                lblALR.Text = "0";
                            }
                        }
                    }
                    commListening = false;
                }
                catch (Exception ex) { throw ex; }
            }
            ));
        }
        #endregion

        #region 接收手柄串口数据
        private void ControlCOMStickEnable()
        {
            commstick.PortName = stick;
            commstick.BaudRate = 115200;
            commstick.DataReceived += commstick_DataReceived;           
        }
        private void commstick_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            Thread.Sleep(50);
            if (commstickclose) return;
            commstickListening = true;
            int n = commstick.BytesToRead;
            byte[] buf = new byte[n];
            commstick.Read(buf, 0, n);
            builderstick.Clear();

            this.Invoke((EventHandler)(delegate
            {
                try
                {                   
                    if (buf.Length >= 15)
                    {
                        if ((buf[0] == 0x66) && (buf[1] == 0x66) && (buf[2] == 0x66) && (buf[3] == 0x66))
                        {
                            commbyte[6] = buf[4];
                            commbyte[7] = buf[5];
                            commbyte[8] = buf[6];
                            commbyte[9] = buf[7];
                            commbyte[10] = buf[8];
                            commbyte[11] = buf[9];
                            commbyte[12] = buf[10];
                            commbyte[13] = buf[11];
                            commbyte[14] = buf[12];
                            commbyte[15] = buf[13];
                        }
                     }
                    commListening = false;
                }
                catch (Exception ex) { throw ex; }
            }
            ));
        }
        #endregion

        #region 窗体关闭
        //窗体关闭
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {            
            if (MessageBox.Show("确定要退出吗？  ", "提示", MessageBoxButtons.OKCancel, MessageBoxIcon.Information)== DialogResult.OK)
            {
                timer1.Enabled = false;
                timer4.Enabled = false;
                commclose = true;
                if (videoing1 == true)
                {
                    btnVideo_Click(null, null);
                }
                Application.DoEvents();
                this.Dispose();
                this.Close();
                Application.Exit();
                Application.ExitThread();
                Process.GetCurrentProcess().Kill();
                System.Environment.Exit(System.Environment.ExitCode);
            }
            else
            {
                e.Cancel = true;
            }
        }
             
        #endregion
       
        #region 前后左右
        //前进
        private void btnForward_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[5] = 0x01;
                
            }           
        }
        private void btnForward_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[5] = 0x00;
            }
        }
        //后退
        private void btnBack_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[5] = 0x00;
            }
        }

        private void btnBack_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[5] = 0x02;
            }
        }
        //左转
        private void btnLeft_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[6] = 0x03;
            }
        }

        private void btnLeft_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[6] = 0x00;
            }
        }
        //右转
        private void btnRight_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[6] = 0x04;
            }
        }

        private void btnRight_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[6] = 0x00;
            }
        }                        
        #endregion

        #region 读写系统配置
        private void LoadParameterXml()
        {
            if (File.Exists(Application.StartupPath + "\\" + "Parameter.xml"))
            {
                XmlDocument xDoc = new XmlDocument();
                xDoc.Load(Application.StartupPath + "\\" + "Parameter.xml");
                XmlNode xn = xDoc.SelectSingleNode("root");
                XmlNodeList xlist = xn.ChildNodes;
                foreach (XmlNode xmln in xlist)
                {
                    ListViewItem eqitem = new ListViewItem();
                    XmlElement xe = (XmlElement)xmln;
                    XmlNodeList xlist1 = xe.ChildNodes;
                    port = xlist1.Item(0).InnerText;
                    stick = xlist1.Item(1).InnerText;
                    filepath = xlist1.Item(2).InnerText;                              
                }
            }
            else
            {
                StreamWriter sw = File.AppendText(Application.StartupPath + "\\" + "Parameter.xml");
                sw.Flush();
                sw.Close();

                XmlDocument xmlDoc = new XmlDocument();
                //创建类型声明节点  
                XmlNode node = xmlDoc.CreateXmlDeclaration("1.0", "gb2312", "");
                xmlDoc.AppendChild(node);
                //创建根节点  

                XmlNode root1 = xmlDoc.CreateElement("root");
                xmlDoc.AppendChild(root1);

                XmlNode root = xmlDoc.CreateElement("Equipment");
                root1.AppendChild(root);
                CreateNode(xmlDoc, root, "port", "COM1");
                CreateNode(xmlDoc, root, "stick", "COM2");
                CreateNode(xmlDoc, root, "filepath", "C:\\");               
                try
                {
                    xmlDoc.Save(Application.StartupPath + "\\" + "Parameter.xml");
                }
                catch (Exception e)
                {
                    //显示错误信息  
                    //Console.WriteLine(e.Message);
                    MessageBox.Show(e.Message, "错误");
                }                 
                LoadParameterXml();
            }
        }
        public void CreateNode(XmlDocument xmlDoc, XmlNode parentNode, string name, string value)
        {
            XmlNode node = xmlDoc.CreateNode(XmlNodeType.Element, name, null);
            node.InnerText = value;
            parentNode.AppendChild(node);
        }  
        #endregion

        #region 串口开关
        private void lblCOM_Click(object sender, EventArgs e)
        {
            if (lblCOM.BackColor == Color.DarkGreen)
            {
                try
                {
                    comm.Open();
                    timer1.Enabled = true;                    
                    lblCOM.BackColor = Color.Lime;
                    lblCOM.ForeColor = Color.Red;
                }
                catch (Exception ex)
                {
                    comm = new SerialPort();
                    MessageBox.Show(ex.Message);
                    return;
                }
                commclose = false;
            }
            else
            {
                if (commListening == true)
                {
                    commclose = true;
                }
                commclose = true;
                Thread.Sleep(100);
                timer1.Enabled = false;
                comm.Close();               
                lblCOM.BackColor = Color.DarkGreen;
                lblCOM.ForeColor = Color.White;
            }
        }
        #endregion

        #region 串口发送数据
        //时钟一直发送数据
        private void timer1_Tick(object sender, EventArgs e)
        {
            int byte4 = Convert.ToInt32(byte4A + byte4B + byte4C + byte4D + byte4E + byte4F, 2);
            commbyte[4] = BitConverter.GetBytes(byte4)[0];
            int adc = 0;
            for (int num = 0; num < 23; num++)
            {
                adc += Convert.ToInt32(commbyte[num]);
            }
            byte[] combyte2 = BitConverter.GetBytes(adc);
          
            commbyte[23] = combyte2[0];
            if (commclose == false)
            {
                comm.Write(commbyte, 0, commbyte.Length);
            }            
        }
        #endregion

        #region 启动手柄
        private void lblStick_Click(object sender, EventArgs e)
        {
            if (lblStick.BackColor == Color.DarkGreen)
            {
                try
                {
                    commstick.Open();
                    commbyte[16] = 0x00;
                    StickOK = true;        
                    lblStick.BackColor = Color.Lime;
                    lblStick.ForeColor = Color.Red;
                }
                catch (Exception ex)
                {
                    commstick = new SerialPort();
                    MessageBox.Show(ex.Message);
                    return;
                }
                commstickclose = false;
            }
            else
            {
                if (commstickListening == true)
                {
                    commstickclose = true;
                }
                commstickclose = true;
                StickOK = false;
                Thread.Sleep(100);
                commstick.Close();
                commbyte[16] = 0x01;
                lblStick.BackColor = Color.DarkGreen;
                lblStick.ForeColor = Color.White;
            }
        }
        #endregion                   
        
        #region 菜单
        private void btnSetting_Click(object sender, EventArgs e)
        {
            FormSet frmset = new FormSet();
            frmset.ShowDialog();
        }

        private void btnFile_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("explorer.exe", filepath);
        }

        private void btnHelp_Click(object sender, EventArgs e)
        {
            FormAbout frmabout = new FormAbout();
            frmabout.ShowDialog();
        }
        #endregion        

        #region 录像截图
        private void btnCapture_Click(object sender, EventArgs e)
        {
            if (realplay1 != -1)
            {
                try
                {
                    string PICName = "CHN1" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".bmp";
                    bool capOK = DHSDK.CLIENT_CapturePicture(realplay1, filepath + PICName);
                }
                catch { }
            }            
        }

        private void btnVideo_Click(object sender, EventArgs e)
        {
            if (realplay1 != -1)
            {
                if (videoing1 == false)
                {
                    string filename1 = "CHN1" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".dav";
                    DHSDK.CLIENT_SaveRealData(realplay1, filepath + filename1);
                    videoing1 = true;                   
                    timer2.Enabled = true;
                    btnVideo.Image = imageList1.Images[1];
                }
                else
                {
                    DHSDK.CLIENT_StopSaveRealData(realplay1);
                    videoing1 = false;                   
                    timer2.Enabled = false;
                    btnVideo.Image = imageList1.Images[0];
                }
            }
        }
        private void btnVideo2_Click(object sender, EventArgs e)
        {
            if (realplay2 != -1)
            {
                if (videoing2 == false)
                {
                    string filename2 = "CHN2" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".dav";
                    DHSDK.CLIENT_SaveRealData(realplay2, filepath + filename2);
                    videoing2 = true;
                    timer3.Enabled = true;
                    btnVideo2.Image = imageList1.Images[1];
                }
                else
                {
                    DHSDK.CLIENT_StopSaveRealData(realplay2);
                    videoing2 = false;
                    timer3.Enabled = false;
                    btnVideo2.Image = imageList1.Images[0];
                }
            }
        }

        private void btnCapture2_Click(object sender, EventArgs e)
        {
            if (realplay2 != -1)
            {
                try
                {
                    string PICName = "CHN2" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".bmp";
                    bool capOK = DHSDK.CLIENT_CapturePicture(realplay2, filepath + PICName);
                }
                catch { }
            }
        }
        #endregion

        #region 录像叠加录像中。。。
        private void timer2_Tick(object sender, EventArgs e)
        {
            Graphics g = Play1.CreateGraphics();
            //g.DrawString("▲", new Font("宋体", 14), Brushes.Red, new PointF(this.Width / 2 - 400, this.Height / 2));
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            Brush bush = new SolidBrush(Color.Red);//填充的颜色
            g.FillEllipse(bush, 10, 10, 15, 15);//
            g.Dispose();
        }
        private void timer3_Tick(object sender, EventArgs e)
        {
            Graphics g = Play2.CreateGraphics();
            //g.DrawString("▲", new Font("宋体", 14), Brushes.Red, new PointF(this.Width / 2 - 400, this.Height / 2));
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            Brush bush = new SolidBrush(Color.Red);//填充的颜色
            g.FillEllipse(bush, 10, 10, 15, 15);//
            g.Dispose();
        }
        #endregion

        #region 灯开关
        private void lblLED_Click(object sender, EventArgs e)
        {
            if (lblLED.BackColor == Color.DarkGreen)
            {
                byte4C = "1";
                lblLED.BackColor = Color.Lime;
                lblLED.ForeColor = Color.Red;
            }
            else
            {
                byte4C = "0";
                lblLED.BackColor = Color.DarkGreen;
                lblLED.ForeColor = Color.White;
            }
        }
        #endregion       

        #region 镜头切换
        private void btnQH_Click(object sender, EventArgs e)
        {
            if (byte4D == "0")
            {
                byte4D = "1";
            }
            else if (byte4D == "1")
            {
                byte4D = "0";
            }
            else
            {
                byte4D = "0";
            }
        }
        #endregion

        #region 一节
        private void btn1U_MouseDown(object sender, MouseEventArgs e)
        {
            if(StickOK==false)
            {
                commbyte[19] = 0x0A;
                commbyte[17] = 0x0A;
            }            
        }

        private void btn1U_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[19] = 0x0F;
                commbyte[17] = 0x0F;
            }
        }

        private void btn1D_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[19] = 0x14;
                commbyte[17] = 0x0A;
            }
        }

        private void btn1D_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[19] = 0x0F;
                commbyte[17] = 0x0F;
            }
        }

        private void btn1L_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[18] = 0x0A;
                commbyte[17] = 0x0A;
            }
        }

        private void btn1L_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[18] = 0x0F;
                commbyte[17] = 0x0F;
            }
        }

        private void btn1R_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[18] = 0x14;
                commbyte[17] = 0x0A;
            }
        }

        private void btn1R_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[18] = 0x0F;
                commbyte[17] = 0x0F;
            }
        }
        #endregion

        #region 二节
        private void btn2U_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[20] = 0x14;
                commbyte[17] = 0x0A;
            }
        }

        private void btn2U_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[20] = 0x0F;
                commbyte[17] = 0x0F;
            }
        }

        private void btn2D_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[20] = 0x0A;
                commbyte[17] = 0x0A;
            }
        }

        private void btn2D_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[20] = 0x0F;
                commbyte[17] = 0x0F;
            }
        }
        #endregion

        #region 机械手
        private void btnAL_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[21] = 0x0A;
                commbyte[17] = 0x0A;
            }
        }

        private void btnAL_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[21] = 0x0F;
                commbyte[17] = 0x0F;
            }
        }

        private void btnAR_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[21] = 0x14;
                commbyte[17] = 0x0A;
            }
        }

        private void btnAR_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[21] = 0x0F;
                commbyte[17] = 0x0F;
            }
        }

        private void btnAO_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[22] = 0x0A;
                commbyte[17] = 0x0A;
            }
        }

        private void btnAO_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[22] = 0x0F;
                commbyte[17] = 0x0F;
            }
        }

        private void btnAC_MouseDown(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[22] = 0x14;
                commbyte[17] = 0x0A;
            }
        }

        private void btnAC_MouseUp(object sender, MouseEventArgs e)
        {
            if (StickOK == false)
            {
                commbyte[22] = 0x0F;
                commbyte[17] = 0x0F;
            }
        }
        #endregion

        #region 液压开关
        bool YYOK = false;
        private void lblYY_Click(object sender, EventArgs e)
        {
            if (YYOK == false)
            {
                lblYY.BackColor = Color.Lime;
                lblYY.ForeColor = Color.Red;
                lblYY.Text = "开";
                byte4B = "1";
                YYOK = true;
            }
            else
            {
                lblYY.BackColor = Color.DarkGreen;
                lblYY.ForeColor = Color.White;
                lblYY.Text = "关";
                byte4B = "0";
                YYOK = false;
            }
        }
        #endregion

        #region 采集框开关
        private void btnKO_MouseDown(object sender, MouseEventArgs e)
        {
            byte4E = "1";
        }

        private void btnKO_MouseUp(object sender, MouseEventArgs e)
        {
            byte4E = "0";
        }

        private void btnKC_MouseDown(object sender, MouseEventArgs e)
        {
            byte4F = "10";
        }

        private void btnKC_MouseUp(object sender, MouseEventArgs e)
        {
            byte4F = "00";
        }

        #endregion

        private void timer4_Tick(object sender, EventArgs e)
        {
            if (realplay1 != -1)
            {
                try
                {
                    string PICName = "CHN1" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".bmp";
                    bool capOK = DHSDK.CLIENT_CapturePicture(realplay1, filepath + PICName);
                }
                catch { }
            }    
        }

        private void autoScreenShot_Click(object sender, EventArgs e)
        {
            if (!ScreenShotFlag)
            {
                timer4.Enabled = true;
                ScreenShotFlag = true;
                MessageBox.Show("即将开始自动截屏", "提示");
            }
            else
            {
                timer4.Enabled = false;
                ScreenShotFlag = false;
                MessageBox.Show("停止截屏", "提示");
            }
        }

        
    }        
}
