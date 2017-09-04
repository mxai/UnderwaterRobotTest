using System.Windows.Forms;
namespace vvlaistick
{
    partial class FormMain
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
            CCWin.CmSysButton cmSysButton1 = new CCWin.CmSysButton();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.lblLED1 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.lblLED = new System.Windows.Forms.Label();
            this.lblStick = new System.Windows.Forms.Label();
            this.lblCOM = new System.Windows.Forms.Label();
            this.btnCapture = new CCWin.SkinControl.SkinButton();
            this.btnVideo = new CCWin.SkinControl.SkinButton();
            this.btnForward = new CCWin.SkinControl.SkinButton();
            this.btnBack = new CCWin.SkinControl.SkinButton();
            this.btnLeft = new CCWin.SkinControl.SkinButton();
            this.btnRight = new CCWin.SkinControl.SkinButton();
            this.btnSetting = new CCWin.SkinControl.SkinButton();
            this.btnFile = new CCWin.SkinControl.SkinButton();
            this.btnHelp = new CCWin.SkinControl.SkinButton();
            this.Play1 = new CCWin.SkinControl.SkinPictureBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.imageList1 = new System.Windows.Forms.ImageList(this.components);
            this.timer2 = new System.Windows.Forms.Timer(this.components);
            this.skinPanel1 = new CCWin.SkinControl.SkinPanel();
            this.label9 = new System.Windows.Forms.Label();
            this.panel5 = new System.Windows.Forms.Panel();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label7 = new System.Windows.Forms.Label();
            this.lblALR = new System.Windows.Forms.Label();
            this.lbl2UD = new System.Windows.Forms.Label();
            this.lbl1LR = new System.Windows.Forms.Label();
            this.lbl1UD = new System.Windows.Forms.Label();
            this.btnAO = new CCWin.SkinControl.SkinButton();
            this.btnAC = new CCWin.SkinControl.SkinButton();
            this.btn2U = new CCWin.SkinControl.SkinButton();
            this.btnAL = new CCWin.SkinControl.SkinButton();
            this.btn2D = new CCWin.SkinControl.SkinButton();
            this.btnAR = new CCWin.SkinControl.SkinButton();
            this.label2 = new System.Windows.Forms.Label();
            this.btn1U = new CCWin.SkinControl.SkinButton();
            this.btn1L = new CCWin.SkinControl.SkinButton();
            this.btn1D = new CCWin.SkinControl.SkinButton();
            this.btn1R = new CCWin.SkinControl.SkinButton();
            this.panel3 = new System.Windows.Forms.Panel();
            this.lblYY = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.panel6 = new System.Windows.Forms.Panel();
            this.btnKO = new CCWin.SkinControl.SkinButton();
            this.btnKC = new CCWin.SkinControl.SkinButton();
            this.label14 = new System.Windows.Forms.Label();
            this.skinPanel2 = new CCWin.SkinControl.SkinPanel();
            this.Play2 = new CCWin.SkinControl.SkinPictureBox();
            this.panel4 = new System.Windows.Forms.Panel();
            this.btnCapture2 = new CCWin.SkinControl.SkinButton();
            this.btnVideo2 = new CCWin.SkinControl.SkinButton();
            this.timer3 = new System.Windows.Forms.Timer(this.components);
            this.timer4 = new System.Windows.Forms.Timer(this.components);
            this.autoScreenShot = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Play1)).BeginInit();
            this.panel1.SuspendLayout();
            this.skinPanel1.SuspendLayout();
            this.panel5.SuspendLayout();
            this.panel2.SuspendLayout();
            this.panel3.SuspendLayout();
            this.panel6.SuspendLayout();
            this.skinPanel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.Play2)).BeginInit();
            this.panel4.SuspendLayout();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Interval = 10;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // lblLED1
            // 
            resources.ApplyResources(this.lblLED1, "lblLED1");
            this.lblLED1.BackColor = System.Drawing.Color.Transparent;
            this.lblLED1.ForeColor = System.Drawing.Color.Black;
            this.lblLED1.Name = "lblLED1";
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.Transparent;
            resources.ApplyResources(this.pictureBox1, "pictureBox1");
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.TabStop = false;
            // 
            // lblLED
            // 
            this.lblLED.BackColor = System.Drawing.Color.DarkGreen;
            this.lblLED.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.lblLED, "lblLED");
            this.lblLED.Name = "lblLED";
            this.lblLED.Click += new System.EventHandler(this.lblLED_Click);
            // 
            // lblStick
            // 
            this.lblStick.BackColor = System.Drawing.Color.DarkGreen;
            this.lblStick.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.lblStick, "lblStick");
            this.lblStick.Name = "lblStick";
            this.lblStick.Click += new System.EventHandler(this.lblStick_Click);
            // 
            // lblCOM
            // 
            this.lblCOM.BackColor = System.Drawing.Color.DarkGreen;
            this.lblCOM.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.lblCOM, "lblCOM");
            this.lblCOM.Name = "lblCOM";
            this.lblCOM.Click += new System.EventHandler(this.lblCOM_Click);
            // 
            // btnCapture
            // 
            this.btnCapture.BackColor = System.Drawing.Color.Transparent;
            this.btnCapture.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnCapture.DownBack = ((System.Drawing.Image)(resources.GetObject("btnCapture.DownBack")));
            this.btnCapture.DrawType = CCWin.SkinControl.DrawStyle.Img;
            this.btnCapture.ForeColor = System.Drawing.Color.White;
            resources.ApplyResources(this.btnCapture, "btnCapture");
            this.btnCapture.ImageSize = new System.Drawing.Size(25, 25);
            this.btnCapture.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnCapture.MouseBack")));
            this.btnCapture.Name = "btnCapture";
            this.btnCapture.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnCapture.NormlBack")));
            this.btnCapture.UseVisualStyleBackColor = false;
            this.btnCapture.Click += new System.EventHandler(this.btnCapture_Click);
            // 
            // btnVideo
            // 
            this.btnVideo.BackColor = System.Drawing.Color.Transparent;
            this.btnVideo.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnVideo.DownBack = ((System.Drawing.Image)(resources.GetObject("btnVideo.DownBack")));
            this.btnVideo.DrawType = CCWin.SkinControl.DrawStyle.Img;
            this.btnVideo.ForeColor = System.Drawing.Color.White;
            resources.ApplyResources(this.btnVideo, "btnVideo");
            this.btnVideo.ImageSize = new System.Drawing.Size(30, 35);
            this.btnVideo.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnVideo.MouseBack")));
            this.btnVideo.Name = "btnVideo";
            this.btnVideo.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnVideo.NormlBack")));
            this.btnVideo.UseVisualStyleBackColor = false;
            this.btnVideo.Click += new System.EventHandler(this.btnVideo_Click);
            // 
            // btnForward
            // 
            this.btnForward.BackColor = System.Drawing.Color.Transparent;
            this.btnForward.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnForward.DownBack = ((System.Drawing.Image)(resources.GetObject("btnForward.DownBack")));
            this.btnForward.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnForward, "btnForward");
            this.btnForward.ForeColor = System.Drawing.Color.White;
            this.btnForward.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnForward.MouseBack")));
            this.btnForward.Name = "btnForward";
            this.btnForward.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnForward.NormlBack")));
            this.btnForward.UseVisualStyleBackColor = false;
            this.btnForward.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnForward_MouseDown);
            this.btnForward.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnForward_MouseUp);
            // 
            // btnBack
            // 
            this.btnBack.BackColor = System.Drawing.Color.Transparent;
            this.btnBack.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnBack.DownBack = ((System.Drawing.Image)(resources.GetObject("btnBack.DownBack")));
            this.btnBack.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnBack, "btnBack");
            this.btnBack.ForeColor = System.Drawing.Color.White;
            this.btnBack.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnBack.MouseBack")));
            this.btnBack.Name = "btnBack";
            this.btnBack.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnBack.NormlBack")));
            this.btnBack.UseVisualStyleBackColor = false;
            this.btnBack.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnBack_MouseDown);
            this.btnBack.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnBack_MouseUp);
            // 
            // btnLeft
            // 
            this.btnLeft.BackColor = System.Drawing.Color.Transparent;
            this.btnLeft.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnLeft.DownBack = ((System.Drawing.Image)(resources.GetObject("btnLeft.DownBack")));
            this.btnLeft.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnLeft, "btnLeft");
            this.btnLeft.ForeColor = System.Drawing.Color.White;
            this.btnLeft.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnLeft.MouseBack")));
            this.btnLeft.Name = "btnLeft";
            this.btnLeft.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnLeft.NormlBack")));
            this.btnLeft.UseVisualStyleBackColor = false;
            this.btnLeft.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnLeft_MouseDown);
            this.btnLeft.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnLeft_MouseUp);
            // 
            // btnRight
            // 
            this.btnRight.BackColor = System.Drawing.Color.Transparent;
            this.btnRight.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnRight.DownBack = ((System.Drawing.Image)(resources.GetObject("btnRight.DownBack")));
            this.btnRight.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnRight, "btnRight");
            this.btnRight.ForeColor = System.Drawing.Color.White;
            this.btnRight.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnRight.MouseBack")));
            this.btnRight.Name = "btnRight";
            this.btnRight.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnRight.NormlBack")));
            this.btnRight.UseVisualStyleBackColor = false;
            this.btnRight.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnRight_MouseDown);
            this.btnRight.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnRight_MouseUp);
            // 
            // btnSetting
            // 
            this.btnSetting.BackColor = System.Drawing.Color.Transparent;
            this.btnSetting.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnSetting.DownBack = null;
            this.btnSetting.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnSetting, "btnSetting");
            this.btnSetting.ForeColor = System.Drawing.Color.White;
            this.btnSetting.ImageSize = new System.Drawing.Size(40, 40);
            this.btnSetting.MouseBack = null;
            this.btnSetting.MouseBaseColor = System.Drawing.Color.Transparent;
            this.btnSetting.Name = "btnSetting";
            this.btnSetting.NormlBack = null;
            this.btnSetting.UseVisualStyleBackColor = false;
            this.btnSetting.Click += new System.EventHandler(this.btnSetting_Click);
            // 
            // btnFile
            // 
            this.btnFile.BackColor = System.Drawing.Color.Transparent;
            this.btnFile.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnFile.DownBack = null;
            this.btnFile.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnFile, "btnFile");
            this.btnFile.ForeColor = System.Drawing.Color.White;
            this.btnFile.ImageSize = new System.Drawing.Size(40, 40);
            this.btnFile.MouseBack = null;
            this.btnFile.MouseBaseColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.btnFile.Name = "btnFile";
            this.btnFile.NormlBack = null;
            this.btnFile.UseVisualStyleBackColor = false;
            this.btnFile.Click += new System.EventHandler(this.btnFile_Click);
            // 
            // btnHelp
            // 
            this.btnHelp.BackColor = System.Drawing.Color.Transparent;
            this.btnHelp.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnHelp.DownBack = null;
            this.btnHelp.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnHelp, "btnHelp");
            this.btnHelp.ForeColor = System.Drawing.Color.White;
            this.btnHelp.ImageSize = new System.Drawing.Size(40, 40);
            this.btnHelp.MouseBack = null;
            this.btnHelp.MouseBaseColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.btnHelp.Name = "btnHelp";
            this.btnHelp.NormlBack = null;
            this.btnHelp.UseVisualStyleBackColor = false;
            this.btnHelp.Click += new System.EventHandler(this.btnHelp_Click);
            // 
            // Play1
            // 
            this.Play1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(20)))));
            this.Play1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            resources.ApplyResources(this.Play1, "Play1");
            this.Play1.Name = "Play1";
            this.Play1.TabStop = false;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.Transparent;
            resources.ApplyResources(this.panel1, "panel1");
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.btnForward);
            this.panel1.Controls.Add(this.btnLeft);
            this.panel1.Controls.Add(this.btnBack);
            this.panel1.Controls.Add(this.btnRight);
            this.panel1.Name = "panel1";
            // 
            // label1
            // 
            resources.ApplyResources(this.label1, "label1");
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.label1.Name = "label1";
            // 
            // imageList1
            // 
            this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
            this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList1.Images.SetKeyName(0, "");
            this.imageList1.Images.SetKeyName(1, "");
            // 
            // timer2
            // 
            this.timer2.Tick += new System.EventHandler(this.timer2_Tick);
            // 
            // skinPanel1
            // 
            this.skinPanel1.BackColor = System.Drawing.Color.DimGray;
            this.skinPanel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.skinPanel1.Controls.Add(this.Play1);
            this.skinPanel1.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.skinPanel1.DownBack = null;
            resources.ApplyResources(this.skinPanel1, "skinPanel1");
            this.skinPanel1.MouseBack = null;
            this.skinPanel1.Name = "skinPanel1";
            this.skinPanel1.NormlBack = null;
            this.skinPanel1.RoundStyle = CCWin.SkinClass.RoundStyle.All;
            // 
            // label9
            // 
            resources.ApplyResources(this.label9, "label9");
            this.label9.BackColor = System.Drawing.Color.Transparent;
            this.label9.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.label9.Name = "label9";
            // 
            // panel5
            // 
            this.panel5.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel5.Controls.Add(this.label10);
            this.panel5.Controls.Add(this.lblCOM);
            this.panel5.Controls.Add(this.lblStick);
            this.panel5.Controls.Add(this.lblLED);
            resources.ApplyResources(this.panel5, "panel5");
            this.panel5.Name = "panel5";
            // 
            // label10
            // 
            resources.ApplyResources(this.label10, "label10");
            this.label10.BackColor = System.Drawing.Color.Transparent;
            this.label10.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.label10.Name = "label10";
            // 
            // label11
            // 
            resources.ApplyResources(this.label11, "label11");
            this.label11.BackColor = System.Drawing.Color.Transparent;
            this.label11.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.label11.Name = "label11";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Transparent;
            resources.ApplyResources(this.panel2, "panel2");
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel2.Controls.Add(this.label7);
            this.panel2.Controls.Add(this.lblALR);
            this.panel2.Controls.Add(this.lbl2UD);
            this.panel2.Controls.Add(this.lbl1LR);
            this.panel2.Controls.Add(this.lbl1UD);
            this.panel2.Controls.Add(this.btnAO);
            this.panel2.Controls.Add(this.btnAC);
            this.panel2.Controls.Add(this.btn2U);
            this.panel2.Controls.Add(this.btnAL);
            this.panel2.Controls.Add(this.btn2D);
            this.panel2.Controls.Add(this.btnAR);
            this.panel2.Controls.Add(this.label2);
            this.panel2.Controls.Add(this.btn1U);
            this.panel2.Controls.Add(this.btn1L);
            this.panel2.Controls.Add(this.btn1D);
            this.panel2.Controls.Add(this.btn1R);
            this.panel2.Name = "panel2";
            // 
            // label7
            // 
            resources.ApplyResources(this.label7, "label7");
            this.label7.BackColor = System.Drawing.Color.Transparent;
            this.label7.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.label7.Name = "label7";
            // 
            // lblALR
            // 
            this.lblALR.BackColor = System.Drawing.Color.Black;
            this.lblALR.ForeColor = System.Drawing.Color.Lime;
            resources.ApplyResources(this.lblALR, "lblALR");
            this.lblALR.Name = "lblALR";
            // 
            // lbl2UD
            // 
            this.lbl2UD.BackColor = System.Drawing.Color.Black;
            this.lbl2UD.ForeColor = System.Drawing.Color.Lime;
            resources.ApplyResources(this.lbl2UD, "lbl2UD");
            this.lbl2UD.Name = "lbl2UD";
            // 
            // lbl1LR
            // 
            this.lbl1LR.BackColor = System.Drawing.Color.Black;
            this.lbl1LR.ForeColor = System.Drawing.Color.Lime;
            resources.ApplyResources(this.lbl1LR, "lbl1LR");
            this.lbl1LR.Name = "lbl1LR";
            // 
            // lbl1UD
            // 
            this.lbl1UD.BackColor = System.Drawing.Color.Black;
            this.lbl1UD.ForeColor = System.Drawing.Color.Lime;
            resources.ApplyResources(this.lbl1UD, "lbl1UD");
            this.lbl1UD.Name = "lbl1UD";
            // 
            // btnAO
            // 
            this.btnAO.BackColor = System.Drawing.Color.Transparent;
            this.btnAO.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnAO.DownBack = ((System.Drawing.Image)(resources.GetObject("btnAO.DownBack")));
            this.btnAO.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnAO, "btnAO");
            this.btnAO.ForeColor = System.Drawing.Color.White;
            this.btnAO.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnAO.MouseBack")));
            this.btnAO.Name = "btnAO";
            this.btnAO.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnAO.NormlBack")));
            this.btnAO.UseVisualStyleBackColor = false;
            this.btnAO.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnAO_MouseDown);
            this.btnAO.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnAO_MouseUp);
            // 
            // btnAC
            // 
            this.btnAC.BackColor = System.Drawing.Color.Transparent;
            this.btnAC.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnAC.DownBack = ((System.Drawing.Image)(resources.GetObject("btnAC.DownBack")));
            this.btnAC.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnAC, "btnAC");
            this.btnAC.ForeColor = System.Drawing.Color.White;
            this.btnAC.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnAC.MouseBack")));
            this.btnAC.Name = "btnAC";
            this.btnAC.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnAC.NormlBack")));
            this.btnAC.UseVisualStyleBackColor = false;
            this.btnAC.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnAC_MouseDown);
            this.btnAC.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnAC_MouseUp);
            // 
            // btn2U
            // 
            this.btn2U.BackColor = System.Drawing.Color.Transparent;
            this.btn2U.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btn2U.DownBack = ((System.Drawing.Image)(resources.GetObject("btn2U.DownBack")));
            this.btn2U.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btn2U, "btn2U");
            this.btn2U.ForeColor = System.Drawing.Color.White;
            this.btn2U.MouseBack = ((System.Drawing.Image)(resources.GetObject("btn2U.MouseBack")));
            this.btn2U.Name = "btn2U";
            this.btn2U.NormlBack = ((System.Drawing.Image)(resources.GetObject("btn2U.NormlBack")));
            this.btn2U.UseVisualStyleBackColor = false;
            this.btn2U.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btn2U_MouseDown);
            this.btn2U.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btn2U_MouseUp);
            // 
            // btnAL
            // 
            this.btnAL.BackColor = System.Drawing.Color.Transparent;
            this.btnAL.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnAL.DownBack = ((System.Drawing.Image)(resources.GetObject("btnAL.DownBack")));
            this.btnAL.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnAL, "btnAL");
            this.btnAL.ForeColor = System.Drawing.Color.White;
            this.btnAL.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnAL.MouseBack")));
            this.btnAL.Name = "btnAL";
            this.btnAL.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnAL.NormlBack")));
            this.btnAL.UseVisualStyleBackColor = false;
            this.btnAL.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnAL_MouseDown);
            this.btnAL.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnAL_MouseUp);
            // 
            // btn2D
            // 
            this.btn2D.BackColor = System.Drawing.Color.Transparent;
            this.btn2D.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btn2D.DownBack = ((System.Drawing.Image)(resources.GetObject("btn2D.DownBack")));
            this.btn2D.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btn2D, "btn2D");
            this.btn2D.ForeColor = System.Drawing.Color.White;
            this.btn2D.MouseBack = ((System.Drawing.Image)(resources.GetObject("btn2D.MouseBack")));
            this.btn2D.Name = "btn2D";
            this.btn2D.NormlBack = ((System.Drawing.Image)(resources.GetObject("btn2D.NormlBack")));
            this.btn2D.UseVisualStyleBackColor = false;
            this.btn2D.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btn2D_MouseDown);
            this.btn2D.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btn2D_MouseUp);
            // 
            // btnAR
            // 
            this.btnAR.BackColor = System.Drawing.Color.Transparent;
            this.btnAR.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnAR.DownBack = ((System.Drawing.Image)(resources.GetObject("btnAR.DownBack")));
            this.btnAR.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnAR, "btnAR");
            this.btnAR.ForeColor = System.Drawing.Color.White;
            this.btnAR.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnAR.MouseBack")));
            this.btnAR.Name = "btnAR";
            this.btnAR.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnAR.NormlBack")));
            this.btnAR.UseVisualStyleBackColor = false;
            this.btnAR.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnAR_MouseDown);
            this.btnAR.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnAR_MouseUp);
            // 
            // label2
            // 
            resources.ApplyResources(this.label2, "label2");
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.label2.Name = "label2";
            // 
            // btn1U
            // 
            this.btn1U.BackColor = System.Drawing.Color.Transparent;
            this.btn1U.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btn1U.DownBack = ((System.Drawing.Image)(resources.GetObject("btn1U.DownBack")));
            this.btn1U.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btn1U, "btn1U");
            this.btn1U.ForeColor = System.Drawing.Color.White;
            this.btn1U.MouseBack = ((System.Drawing.Image)(resources.GetObject("btn1U.MouseBack")));
            this.btn1U.Name = "btn1U";
            this.btn1U.NormlBack = ((System.Drawing.Image)(resources.GetObject("btn1U.NormlBack")));
            this.btn1U.UseVisualStyleBackColor = false;
            this.btn1U.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btn1U_MouseDown);
            this.btn1U.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btn1U_MouseUp);
            // 
            // btn1L
            // 
            this.btn1L.BackColor = System.Drawing.Color.Transparent;
            this.btn1L.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btn1L.DownBack = ((System.Drawing.Image)(resources.GetObject("btn1L.DownBack")));
            this.btn1L.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btn1L, "btn1L");
            this.btn1L.ForeColor = System.Drawing.Color.White;
            this.btn1L.MouseBack = ((System.Drawing.Image)(resources.GetObject("btn1L.MouseBack")));
            this.btn1L.Name = "btn1L";
            this.btn1L.NormlBack = ((System.Drawing.Image)(resources.GetObject("btn1L.NormlBack")));
            this.btn1L.UseVisualStyleBackColor = false;
            this.btn1L.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btn1L_MouseDown);
            this.btn1L.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btn1L_MouseUp);
            // 
            // btn1D
            // 
            this.btn1D.BackColor = System.Drawing.Color.Transparent;
            this.btn1D.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btn1D.DownBack = ((System.Drawing.Image)(resources.GetObject("btn1D.DownBack")));
            this.btn1D.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btn1D, "btn1D");
            this.btn1D.ForeColor = System.Drawing.Color.White;
            this.btn1D.MouseBack = ((System.Drawing.Image)(resources.GetObject("btn1D.MouseBack")));
            this.btn1D.Name = "btn1D";
            this.btn1D.NormlBack = ((System.Drawing.Image)(resources.GetObject("btn1D.NormlBack")));
            this.btn1D.UseVisualStyleBackColor = false;
            this.btn1D.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btn1D_MouseDown);
            this.btn1D.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btn1D_MouseUp);
            // 
            // btn1R
            // 
            this.btn1R.BackColor = System.Drawing.Color.Transparent;
            this.btn1R.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btn1R.DownBack = ((System.Drawing.Image)(resources.GetObject("btn1R.DownBack")));
            this.btn1R.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btn1R, "btn1R");
            this.btn1R.ForeColor = System.Drawing.Color.White;
            this.btn1R.MouseBack = ((System.Drawing.Image)(resources.GetObject("btn1R.MouseBack")));
            this.btn1R.Name = "btn1R";
            this.btn1R.NormlBack = ((System.Drawing.Image)(resources.GetObject("btn1R.NormlBack")));
            this.btn1R.UseVisualStyleBackColor = false;
            this.btn1R.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btn1R_MouseDown);
            this.btn1R.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btn1R_MouseUp);
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.Transparent;
            resources.ApplyResources(this.panel3, "panel3");
            this.panel3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel3.Controls.Add(this.lblYY);
            this.panel3.Controls.Add(this.label8);
            this.panel3.Name = "panel3";
            // 
            // lblYY
            // 
            this.lblYY.BackColor = System.Drawing.Color.DarkGreen;
            this.lblYY.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            resources.ApplyResources(this.lblYY, "lblYY");
            this.lblYY.Name = "lblYY";
            this.lblYY.Click += new System.EventHandler(this.lblYY_Click);
            // 
            // label8
            // 
            resources.ApplyResources(this.label8, "label8");
            this.label8.BackColor = System.Drawing.Color.Transparent;
            this.label8.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.label8.Name = "label8";
            // 
            // panel6
            // 
            this.panel6.BackColor = System.Drawing.Color.Transparent;
            resources.ApplyResources(this.panel6, "panel6");
            this.panel6.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel6.Controls.Add(this.btnKO);
            this.panel6.Controls.Add(this.btnKC);
            this.panel6.Controls.Add(this.label14);
            this.panel6.Name = "panel6";
            // 
            // btnKO
            // 
            this.btnKO.BackColor = System.Drawing.Color.Transparent;
            this.btnKO.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnKO.DownBack = ((System.Drawing.Image)(resources.GetObject("btnKO.DownBack")));
            this.btnKO.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnKO, "btnKO");
            this.btnKO.ForeColor = System.Drawing.Color.White;
            this.btnKO.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnKO.MouseBack")));
            this.btnKO.Name = "btnKO";
            this.btnKO.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnKO.NormlBack")));
            this.btnKO.UseVisualStyleBackColor = false;
            this.btnKO.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnKO_MouseDown);
            this.btnKO.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnKO_MouseUp);
            // 
            // btnKC
            // 
            this.btnKC.BackColor = System.Drawing.Color.Transparent;
            this.btnKC.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnKC.DownBack = ((System.Drawing.Image)(resources.GetObject("btnKC.DownBack")));
            this.btnKC.DrawType = CCWin.SkinControl.DrawStyle.Img;
            resources.ApplyResources(this.btnKC, "btnKC");
            this.btnKC.ForeColor = System.Drawing.Color.White;
            this.btnKC.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnKC.MouseBack")));
            this.btnKC.Name = "btnKC";
            this.btnKC.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnKC.NormlBack")));
            this.btnKC.UseVisualStyleBackColor = false;
            this.btnKC.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnKC_MouseDown);
            this.btnKC.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnKC_MouseUp);
            // 
            // label14
            // 
            resources.ApplyResources(this.label14, "label14");
            this.label14.BackColor = System.Drawing.Color.Transparent;
            this.label14.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.label14.Name = "label14";
            // 
            // skinPanel2
            // 
            this.skinPanel2.BackColor = System.Drawing.Color.DimGray;
            this.skinPanel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.skinPanel2.Controls.Add(this.Play2);
            this.skinPanel2.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.skinPanel2.DownBack = null;
            resources.ApplyResources(this.skinPanel2, "skinPanel2");
            this.skinPanel2.MouseBack = null;
            this.skinPanel2.Name = "skinPanel2";
            this.skinPanel2.NormlBack = null;
            this.skinPanel2.RoundStyle = CCWin.SkinClass.RoundStyle.All;
            // 
            // Play2
            // 
            this.Play2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(20)))));
            this.Play2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            resources.ApplyResources(this.Play2, "Play2");
            this.Play2.Name = "Play2";
            this.Play2.TabStop = false;
            // 
            // panel4
            // 
            this.panel4.BackColor = System.Drawing.Color.Transparent;
            resources.ApplyResources(this.panel4, "panel4");
            this.panel4.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel4.Controls.Add(this.autoScreenShot);
            this.panel4.Controls.Add(this.btnCapture2);
            this.panel4.Controls.Add(this.btnVideo2);
            this.panel4.Controls.Add(this.btnCapture);
            this.panel4.Controls.Add(this.label9);
            this.panel4.Controls.Add(this.btnVideo);
            this.panel4.Name = "panel4";
            // 
            // btnCapture2
            // 
            this.btnCapture2.BackColor = System.Drawing.Color.Transparent;
            this.btnCapture2.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnCapture2.DownBack = ((System.Drawing.Image)(resources.GetObject("btnCapture2.DownBack")));
            this.btnCapture2.DrawType = CCWin.SkinControl.DrawStyle.Img;
            this.btnCapture2.ForeColor = System.Drawing.Color.White;
            resources.ApplyResources(this.btnCapture2, "btnCapture2");
            this.btnCapture2.ImageSize = new System.Drawing.Size(25, 25);
            this.btnCapture2.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnCapture2.MouseBack")));
            this.btnCapture2.Name = "btnCapture2";
            this.btnCapture2.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnCapture2.NormlBack")));
            this.btnCapture2.UseVisualStyleBackColor = false;
            this.btnCapture2.Click += new System.EventHandler(this.btnCapture2_Click);
            // 
            // btnVideo2
            // 
            this.btnVideo2.BackColor = System.Drawing.Color.Transparent;
            this.btnVideo2.ControlState = CCWin.SkinClass.ControlState.Normal;
            this.btnVideo2.DownBack = ((System.Drawing.Image)(resources.GetObject("btnVideo2.DownBack")));
            this.btnVideo2.DrawType = CCWin.SkinControl.DrawStyle.Img;
            this.btnVideo2.ForeColor = System.Drawing.Color.White;
            resources.ApplyResources(this.btnVideo2, "btnVideo2");
            this.btnVideo2.ImageSize = new System.Drawing.Size(30, 35);
            this.btnVideo2.MouseBack = ((System.Drawing.Image)(resources.GetObject("btnVideo2.MouseBack")));
            this.btnVideo2.Name = "btnVideo2";
            this.btnVideo2.NormlBack = ((System.Drawing.Image)(resources.GetObject("btnVideo2.NormlBack")));
            this.btnVideo2.UseVisualStyleBackColor = false;
            this.btnVideo2.Click += new System.EventHandler(this.btnVideo2_Click);
            // 
            // timer3
            // 
            this.timer3.Tick += new System.EventHandler(this.timer3_Tick);
            // 
            // timer4
            // 
            this.timer4.Interval = 1000;
            this.timer4.Tick += new System.EventHandler(this.timer4_Tick);
            // 
            // autoScreenShot
            // 
            this.autoScreenShot.BackColor = System.Drawing.Color.Black;
            resources.ApplyResources(this.autoScreenShot, "autoScreenShot");
            this.autoScreenShot.Name = "autoScreenShot";
            this.autoScreenShot.UseVisualStyleBackColor = false;
            this.autoScreenShot.Click += new System.EventHandler(this.autoScreenShot_Click);
            // 
            // FormMain
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(81)))), ((int)(((byte)(84)))), ((int)(((byte)(89)))));
            this.CanResize = false;
            this.CaptionBackColorBottom = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.CaptionBackColorTop = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.CaptionFont = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.CaptionHeight = 60;
            this.CloseBoxSize = new System.Drawing.Size(30, 25);
            this.CloseDownBack = ((System.Drawing.Image)(resources.GetObject("$this.CloseDownBack")));
            this.CloseMouseBack = ((System.Drawing.Image)(resources.GetObject("$this.CloseMouseBack")));
            this.CloseNormlBack = ((System.Drawing.Image)(resources.GetObject("$this.CloseNormlBack")));
            this.ControlBoxOffset = new System.Drawing.Point(16, 16);
            this.ControlBoxSpace = 0;
            this.Controls.Add(this.panel4);
            this.Controls.Add(this.skinPanel2);
            this.Controls.Add(this.panel6);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.panel5);
            this.Controls.Add(this.skinPanel1);
            this.Controls.Add(this.btnHelp);
            this.Controls.Add(this.btnFile);
            this.Controls.Add(this.btnSetting);
            this.Controls.Add(this.pictureBox1);
            this.EffectBack = System.Drawing.Color.Transparent;
            this.ForeColor = System.Drawing.Color.White;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.ICoOffset = new System.Drawing.Point(0, -15);
            this.InnerBorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(81)))), ((int)(((byte)(84)))), ((int)(((byte)(89)))));
            this.KeyPreview = true;
            this.MaximizeBox = false;
            this.MiniDownBack = ((System.Drawing.Image)(resources.GetObject("$this.MiniDownBack")));
            this.MiniMouseBack = ((System.Drawing.Image)(resources.GetObject("$this.MiniMouseBack")));
            this.MiniNormlBack = ((System.Drawing.Image)(resources.GetObject("$this.MiniNormlBack")));
            this.MiniSize = new System.Drawing.Size(30, 25);
            this.Name = "FormMain";
            this.Radius = 30;
            this.RoundStyle = CCWin.SkinClass.RoundStyle.None;
            this.ShadowColor = System.Drawing.Color.FromArgb(((int)(((byte)(81)))), ((int)(((byte)(84)))), ((int)(((byte)(89)))));
            this.ShadowRectangle = new System.Drawing.Rectangle(0, 0, 0, 0);
            this.ShadowWidth = 1;
            this.ShowBorder = false;
            this.ShowDrawIcon = false;
            cmSysButton1.Bounds = new System.Drawing.Rectangle(1152, 16, 30, 25);
            cmSysButton1.BoxState = CCWin.ControlBoxState.Normal;
            cmSysButton1.Location = new System.Drawing.Point(1152, 16);
            cmSysButton1.Name = null;
            cmSysButton1.OwnerForm = this;
            cmSysButton1.Size = new System.Drawing.Size(30, 25);
            cmSysButton1.SysButtonDown = ((System.Drawing.Image)(resources.GetObject("cmSysButton1.SysButtonDown")));
            cmSysButton1.SysButtonMouse = ((System.Drawing.Image)(resources.GetObject("cmSysButton1.SysButtonMouse")));
            cmSysButton1.SysButtonNorml = ((System.Drawing.Image)(resources.GetObject("cmSysButton1.SysButtonNorml")));
            cmSysButton1.ToolTip = null;
            this.SysButtonItems.AddRange(new CCWin.CmSysButton[] {
            cmSysButton1});
            this.TitleCenter = false;
            this.TitleColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.TitleOffset = new System.Drawing.Point(70, 5);
            this.TransparencyKey = System.Drawing.Color.FromArgb(((int)(((byte)(81)))), ((int)(((byte)(84)))), ((int)(((byte)(89)))));
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Play1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.skinPanel1.ResumeLayout(false);
            this.panel5.ResumeLayout(false);
            this.panel5.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.panel6.ResumeLayout(false);
            this.panel6.PerformLayout();
            this.skinPanel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.Play2)).EndInit();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

            this.KeyUp += new KeyEventHandler(this.Form1_KeyUp);
            this.KeyDown += new KeyEventHandler(this.Form1_KeyDown);
            this.KeyPress += new KeyPressEventHandler(this.Form1_KeyPress);
        }

        #endregion

        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label lblLED1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label lblLED;
        private System.Windows.Forms.Label lblStick;
        private System.Windows.Forms.Label lblCOM;
        private CCWin.SkinControl.SkinButton btnVideo;
        private CCWin.SkinControl.SkinButton btnRight;
        private CCWin.SkinControl.SkinButton btnLeft;
        private CCWin.SkinControl.SkinButton btnBack;
        private CCWin.SkinControl.SkinButton btnForward;
        private CCWin.SkinControl.SkinButton btnCapture;
        private CCWin.SkinControl.SkinButton btnSetting;
        private CCWin.SkinControl.SkinButton btnFile;
        private CCWin.SkinControl.SkinButton btnHelp;
        private CCWin.SkinControl.SkinPictureBox Play1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.ImageList imageList1;
        private System.Windows.Forms.Timer timer2;
        private CCWin.SkinControl.SkinPanel skinPanel1;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Panel panel5;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label lblALR;
        private System.Windows.Forms.Label lbl2UD;
        private System.Windows.Forms.Label lbl1LR;
        private System.Windows.Forms.Label lbl1UD;
        private CCWin.SkinControl.SkinButton btnAO;
        private CCWin.SkinControl.SkinButton btnAC;
        private CCWin.SkinControl.SkinButton btn2U;
        private CCWin.SkinControl.SkinButton btnAL;
        private CCWin.SkinControl.SkinButton btn2D;
        private CCWin.SkinControl.SkinButton btnAR;
        private System.Windows.Forms.Label label2;
        private CCWin.SkinControl.SkinButton btn1U;
        private CCWin.SkinControl.SkinButton btn1L;
        private CCWin.SkinControl.SkinButton btn1D;
        private CCWin.SkinControl.SkinButton btn1R;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Label lblYY;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Panel panel6;
        private CCWin.SkinControl.SkinButton btnKO;
        private CCWin.SkinControl.SkinButton btnKC;
        private System.Windows.Forms.Label label14;
        private CCWin.SkinControl.SkinPanel skinPanel2;
        private CCWin.SkinControl.SkinPictureBox Play2;
        private System.Windows.Forms.Panel panel4;
        private CCWin.SkinControl.SkinButton btnCapture2;
        private CCWin.SkinControl.SkinButton btnVideo2;
        private System.Windows.Forms.Timer timer3;
        private System.Windows.Forms.Timer timer4;
        private System.Windows.Forms.Button autoScreenShot;
    }
}

