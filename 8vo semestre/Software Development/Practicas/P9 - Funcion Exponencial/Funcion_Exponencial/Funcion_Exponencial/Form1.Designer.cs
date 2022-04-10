namespace Funcion_Exponencial
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.tBdato = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.exp = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.lBsalida = new System.Windows.Forms.ListBox();
            this.Firma = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.Color.Transparent;
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.tBdato);
            this.groupBox1.ForeColor = System.Drawing.Color.White;
            this.groupBox1.Location = new System.Drawing.Point(13, 23);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(160, 68);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Entrada";
            // 
            // tBdato
            // 
            this.tBdato.Location = new System.Drawing.Point(43, 32);
            this.tBdato.Name = "tBdato";
            this.tBdato.Size = new System.Drawing.Size(100, 20);
            this.tBdato.TabIndex = 3;
            // 
            // groupBox2
            // 
            this.groupBox2.BackColor = System.Drawing.Color.Transparent;
            this.groupBox2.Controls.Add(this.exp);
            this.groupBox2.ForeColor = System.Drawing.Color.White;
            this.groupBox2.Location = new System.Drawing.Point(194, 23);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(146, 68);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Operacion";
            // 
            // exp
            // 
            this.exp.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.exp.ForeColor = System.Drawing.Color.Black;
            this.exp.Location = new System.Drawing.Point(37, 30);
            this.exp.Name = "exp";
            this.exp.Size = new System.Drawing.Size(75, 23);
            this.exp.TabIndex = 0;
            this.exp.Text = "Exp(X)";
            this.exp.UseVisualStyleBackColor = false;
            this.exp.Click += new System.EventHandler(this.exp_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.BackColor = System.Drawing.Color.Transparent;
            this.groupBox3.Controls.Add(this.lBsalida);
            this.groupBox3.ForeColor = System.Drawing.Color.White;
            this.groupBox3.Location = new System.Drawing.Point(359, 23);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(157, 165);
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Salida";
            // 
            // lBsalida
            // 
            this.lBsalida.FormattingEnabled = true;
            this.lBsalida.Location = new System.Drawing.Point(6, 21);
            this.lBsalida.Name = "lBsalida";
            this.lBsalida.Size = new System.Drawing.Size(141, 134);
            this.lBsalida.TabIndex = 0;
            // 
            // Firma
            // 
            this.Firma.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Firma.Location = new System.Drawing.Point(135, 145);
            this.Firma.Name = "Firma";
            this.Firma.Size = new System.Drawing.Size(75, 23);
            this.Firma.TabIndex = 3;
            this.Firma.Text = "Firma";
            this.Firma.UseVisualStyleBackColor = false;
            this.Firma.Click += new System.EventHandler(this.Firma_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(11, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(26, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "X = ";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DodgerBlue;
            this.BackgroundImage = global::Funcion_Exponencial.Properties.Resources.acer01;
            this.ClientSize = new System.Drawing.Size(533, 208);
            this.Controls.Add(this.Firma);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.ShowIcon = false;
            this.Text = "Funcion Exponencial";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox tBdato;
        private System.Windows.Forms.Button exp;
        private System.Windows.Forms.ListBox lBsalida;
        private System.Windows.Forms.Button Firma;
        private System.Windows.Forms.Label label1;
    }
}

