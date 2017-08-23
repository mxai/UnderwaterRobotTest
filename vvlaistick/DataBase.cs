using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data;
using System.Data.SqlClient;
using System.Data.SQLite;
using System.Data.Common;


namespace vvlaistick
{
    class DataBase
    {
        public static string connStr = @"Data Source=" + Application.StartupPath + "\\markers.db;Initial Catalog=sqlite;Integrated Security=True;Max Pool Size=10";
        //插入
        public static void ExecuteSql(string sqlStr)
        {
            using (DbConnection conn = new SQLiteConnection(connStr))
            {
                conn.Open();
                DbCommand comm = conn.CreateCommand();
                comm.CommandText = sqlStr;
                comm.CommandType = CommandType.Text;
                comm.ExecuteNonQuery();
            }
        }

        public static void ExecQuery(string sqlStr)
        {
            using (DbConnection conn = new SQLiteConnection(connStr))
            {
                conn.Open();
                DbCommand comm = conn.CreateCommand();
                comm.CommandText = sqlStr;
                comm.CommandType = CommandType.Text;

                using (IDataReader reader = comm.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        MessageBox.Show(reader[0].ToString());
                    }
                }
            }
        }
        //读取返回
        public static DataSet ExecDataSet(string sqlStr)
        {
            using (SQLiteConnection conn = new SQLiteConnection(connStr))
            {
                conn.Open();
                SQLiteCommand cmd = conn.CreateCommand();
                cmd.CommandText = sqlStr;
                cmd.CommandType = CommandType.Text;

                SQLiteDataAdapter da = new SQLiteDataAdapter(cmd);
                DataSet ds = new DataSet();
                da.Fill(ds);

                return ds;
            }
        }
    }
}
