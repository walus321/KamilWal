using MySql.Data.MySqlClient;
using System;
using System.Data;
using System.Windows.Forms;

namespace ProgramDB
{
    public partial class Form1 : Form
    {

        MySqlConnection connection = new MySqlConnection("server=localhost;user=root;database=Bazka");
        MySqlCommand cmd;
        MySqlDataReader rdr;
        string querrySQL = "";


        public Form1()
        {
            InitializeComponent();
        }

        private void dwnl_btn_Click(object sender, EventArgs e)
        {

            try
            {
                if (connection.State == ConnectionState.Closed)
                {
                    connection.Open();
                }
                querrySQL = "select * from users";
                cmd = new MySqlCommand(querrySQL, connection);
                rdr = cmd.ExecuteReader();
                lista.Items.Clear();
                if (rdr.HasRows)
                {
                    while (rdr.Read())
                    {
                        lista.Items.Add(string.Format("{0} - {1} - ({2})", rdr["id"].ToString(), rdr["name"].ToString(), rdr.GetInt32("age")));
                    }
                    rdr.Close();
                }
            }
            catch (Exception ex)
            {
                                MessageBox.Show(string.Format("error while downloading stuff:\n{0}", ex.Message), "error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                connection.Close();
            }
        }

        private void clr_btn_Click(object sender, EventArgs e)
        {
            connection.Items.Clear();
        }

        private void quit_btn_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
