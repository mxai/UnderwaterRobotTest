using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;
using CCWin;
using CCWin.SkinClass;
using CCWin.SkinControl;
using System.Xml;
using System.Xml.Linq;
using System.Xml.XPath;

namespace vvlaistick
{
    public partial class FormSet : Skin_Mac
    {
        string port = null; string stick = null; string filepath = null;
        public FormSet()
        {
            InitializeComponent();
            LoadParameterXml();
        }
        private void LoadParameterXml()
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
        private void FormSet_Load(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();
            DataTable dt = new DataTable();
            dt.Columns.Add("value");
            dt.Columns.Add("display");
            cbxCOM.DataSource = dt;
            cbxCOM.DisplayMember = dt.Columns["value"].ToString();
            cbxCOM.ValueMember = dt.Columns["display"].ToString();

            DataTable dtstick = new DataTable();
            dtstick.Columns.Add("value");
            dtstick.Columns.Add("display");
            cbxStick.DataSource = dtstick;
            cbxStick.DisplayMember = dtstick.Columns["value"].ToString();
            cbxStick.ValueMember = dtstick.Columns["display"].ToString();
            for (int a = 0; a < ports.Length; a++)
            {
                DataRow dr = dt.NewRow();
                dr["value"] = ports[a].ToString();
                dr["display"] = ports[a].ToString();
                dt.Rows.Add(dr);
            }
            for (int b = 0; b < ports.Length; b++)
            {
                DataRow drgps = dtstick.NewRow();
                drgps["value"] = ports[b].ToString();
                drgps["display"] = ports[b].ToString();
                dtstick.Rows.Add(drgps);
            }
            cbxStick.SelectedValue = stick;

            cbxCOM.SelectedValue = port;            
            txtPath.Text = filepath;            
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            deleteXml(port);
            addXml(cbxCOM.SelectedValue.ToString(), stick, txtPath.Text);
            this.DialogResult = DialogResult.OK;
            this.Close();
        }
        private void deleteXml(string port)
        {
            XmlDocument xDoc = new XmlDocument();
            xDoc.Load(Application.StartupPath + "\\" + "Parameter.xml");
            XmlElement root = xDoc.DocumentElement;
            foreach (XmlElement xe in root.ChildNodes)
            {
                foreach (XmlElement xel in xe)
                {
                    if (xel.InnerText == port)
                    {
                        root.RemoveChild(xe);
                        xDoc.Save(Application.StartupPath + "\\" + "Parameter.xml");
                    }
                }
            }
        }
        private void addXml(string port, string stick, string filepath)
        {
            XmlDocument xDoc = new XmlDocument();
            xDoc.Load(Application.StartupPath + "\\" + "Parameter.xml");
            XmlNode root = xDoc.SelectSingleNode("root");
            XmlElement xmlkey = xDoc.CreateElement("Equipment");

            XmlElement xmlaikeyport = xDoc.CreateElement("port");
            xmlaikeyport.InnerText = port;
            xmlkey.AppendChild(xmlaikeyport);

            XmlElement xmlaikeybaude = xDoc.CreateElement("stick");
            xmlaikeybaude.InnerText = stick;
            xmlkey.AppendChild(xmlaikeybaude);

            XmlElement xmlaikeypath = xDoc.CreateElement("filepath");
            xmlaikeypath.InnerText = filepath;
            xmlkey.AppendChild(xmlaikeypath);

            //XmlElement xmlaikeyGPS = xDoc.CreateElement("GPS");
            //xmlaikeyGPS.InnerText = GPS;
            //xmlkey.AppendChild(xmlaikeyGPS);

            root.AppendChild(xmlkey);
            xDoc.Save(Application.StartupPath + "\\" + "Parameter.xml");
        }

        private void skinButton3_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog Folderimg = new FolderBrowserDialog();
            Folderimg.Description = "选择文件保存路径";            
            if (Folderimg.ShowDialog() == DialogResult.OK)
            {
                txtPath.Text = Folderimg.SelectedPath;
            }
        }

        private void FormSet_FormClosing(object sender, FormClosingEventArgs e)
        {
            deleteXml(port);
            addXml(cbxCOM.SelectedValue.ToString(), cbxStick.SelectedValue.ToString(), txtPath.Text);
            this.DialogResult = DialogResult.OK;
        }
    }
}
