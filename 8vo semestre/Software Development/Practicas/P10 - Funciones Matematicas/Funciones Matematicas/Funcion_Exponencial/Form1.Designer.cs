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
            this.log = new System.Windows.Forms.Button();
            this.tan_h = new System.Windows.Forms.Button();
            this.acoseno = new System.Windows.Forms.Button();
            this.aseno = new System.Windows.Forms.Button();
            this.tan = new System.Windows.Forms.Button();
            this.cos_h = new System.Windows.Forms.Button();
            this.seno_h = new System.Windows.Forms.Button();
            this.coseno = new System.Windows.Forms.Button();
            this.seno = new System.Windows.Forms.Button();
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
            this.groupBox1.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.groupBox1.Location = new System.Drawing.Point(12, 14);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 117);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Entrada";
            // 
            // tBdato
            // 
            this.tBdato.Location = new System.Drawing.Point(50, 54);
            this.tBdato.Name = "tBdato";
            this.tBdato.Size = new System.Drawing.Size(117, 20);
            this.tBdato.TabIndex = 3;
            // 
            // groupBox2
            // 
            this.groupBox2.BackColor = System.Drawing.Color.Transparent;
            this.groupBox2.Controls.Add(this.log);
            this.groupBox2.Controls.Add(this.tan_h);
            this.groupBox2.Controls.Add(this.acoseno);
            this.groupBox2.Controls.Add(this.aseno);
            this.groupBox2.Controls.Add(this.tan);
            this.groupBox2.Controls.Add(this.cos_h);
            this.groupBox2.Controls.Add(this.seno_h);
            this.groupBox2.Controls.Add(this.coseno);
            this.groupBox2.Controls.Add(this.seno);
            this.groupBox2.Controls.Add(this.exp);
            this.groupBox2.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.groupBox2.Location = new System.Drawing.Point(232, 14);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(241, 258);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Operacion";
            // 
            // log
            // 
            this.log.BackColor = System.Drawing.Color.White;
            this.log.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.log.Location = new System.Drawing.Point(139, 204);
            this.log.Name = "log";
            this.log.Size = new System.Drawing.Size(75, 23);
            this.log.TabIndex = 9;
            this.log.Text = "log10(X)";
            this.log.UseVisualStyleBackColor = false;
            this.log.Click += new System.EventHandler(this.log_Click);
            // 
            // tan_h
            // 
            this.tan_h.BackColor = System.Drawing.Color.White;
            this.tan_h.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.tan_h.Location = new System.Drawing.Point(139, 79);
            this.tan_h.Name = "tan_h";
            this.tan_h.Size = new System.Drawing.Size(75, 23);
            this.tan_h.TabIndex = 8;
            this.tan_h.Text = "Tanh(X)";
            this.tan_h.UseVisualStyleBackColor = false;
            this.tan_h.Click += new System.EventHandler(this.tan_h_Click);
            // 
            // acoseno
            // 
            this.acoseno.BackColor = System.Drawing.Color.White;
            this.acoseno.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.acoseno.Location = new System.Drawing.Point(139, 162);
            this.acoseno.Name = "acoseno";
            this.acoseno.Size = new System.Drawing.Size(75, 23);
            this.acoseno.TabIndex = 7;
            this.acoseno.Text = "acos(X)";
            this.acoseno.UseVisualStyleBackColor = false;
            this.acoseno.Click += new System.EventHandler(this.acoseno_Click);
            // 
            // aseno
            // 
            this.aseno.BackColor = System.Drawing.Color.White;
            this.aseno.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.aseno.Location = new System.Drawing.Point(139, 122);
            this.aseno.Name = "aseno";
            this.aseno.Size = new System.Drawing.Size(75, 23);
            this.aseno.TabIndex = 6;
            this.aseno.Text = "asen(X)";
            this.aseno.UseVisualStyleBackColor = false;
            this.aseno.Click += new System.EventHandler(this.aseno_Click);
            // 
            // tan
            // 
            this.tan.AutoSize = true;
            this.tan.BackColor = System.Drawing.Color.White;
            this.tan.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.tan.Location = new System.Drawing.Point(139, 39);
            this.tan.Name = "tan";
            this.tan.Size = new System.Drawing.Size(75, 23);
            this.tan.TabIndex = 5;
            this.tan.Text = "Tan(X)";
            this.tan.UseVisualStyleBackColor = false;
            this.tan.Click += new System.EventHandler(this.tan_Click);
            // 
            // cos_h
            // 
            this.cos_h.BackColor = System.Drawing.Color.White;
            this.cos_h.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.cos_h.Location = new System.Drawing.Point(33, 204);
            this.cos_h.Name = "cos_h";
            this.cos_h.Size = new System.Drawing.Size(75, 23);
            this.cos_h.TabIndex = 4;
            this.cos_h.Text = "Cosh(X)";
            this.cos_h.UseVisualStyleBackColor = false;
            this.cos_h.Click += new System.EventHandler(this.cos_h_Click);
            // 
            // seno_h
            // 
            this.seno_h.BackColor = System.Drawing.Color.White;
            this.seno_h.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.seno_h.Location = new System.Drawing.Point(33, 162);
            this.seno_h.Name = "seno_h";
            this.seno_h.Size = new System.Drawing.Size(75, 23);
            this.seno_h.TabIndex = 3;
            this.seno_h.Text = "Senh(X)";
            this.seno_h.UseVisualStyleBackColor = false;
            this.seno_h.Click += new System.EventHandler(this.button3_Click);
            // 
            // coseno
            // 
            this.coseno.BackColor = System.Drawing.Color.White;
            this.coseno.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.coseno.Location = new System.Drawing.Point(33, 120);
            this.coseno.Name = "coseno";
            this.coseno.Size = new System.Drawing.Size(75, 23);
            this.coseno.TabIndex = 2;
            this.coseno.Text = "Cos(X)";
            this.coseno.UseVisualStyleBackColor = false;
            this.coseno.Click += new System.EventHandler(this.coseno_Click);
            // 
            // seno
            // 
            this.seno.BackColor = System.Drawing.Color.White;
            this.seno.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.seno.Location = new System.Drawing.Point(33, 80);
            this.seno.Name = "seno";
            this.seno.Size = new System.Drawing.Size(75, 23);
            this.seno.TabIndex = 1;
            this.seno.Text = "Sen(X)";
            this.seno.UseVisualStyleBackColor = false;
            this.seno.Click += new System.EventHandler(this.seno_Click);
            // 
            // exp
            // 
            this.exp.BackColor = System.Drawing.Color.White;
            this.exp.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.exp.Location = new System.Drawing.Point(33, 39);
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
            this.groupBox3.Location = new System.Drawing.Point(492, 14);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(236, 258);
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Salida";
            // 
            // lBsalida
            // 
            this.lBsalida.FormattingEnabled = true;
            this.lBsalida.Location = new System.Drawing.Point(23, 19);
            this.lBsalida.Name = "lBsalida";
            this.lBsalida.Size = new System.Drawing.Size(190, 225);
            this.lBsalida.TabIndex = 0;
            // 
            // Firma
            // 
            this.Firma.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Firma.Location = new System.Drawing.Point(74, 218);
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
            this.label1.Location = new System.Drawing.Point(18, 57);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(26, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "X = ";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::Funcion_Exponencial.Properties.Resources.acer01;
            this.ClientSize = new System.Drawing.Size(742, 288);
            this.Controls.Add(this.Firma);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.ShowIcon = false;
            this.Text = "Funciones Matematicas";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
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
        private System.Windows.Forms.Button log;
        private System.Windows.Forms.Button tan_h;
        private System.Windows.Forms.Button acoseno;
        private System.Windows.Forms.Button aseno;
        private System.Windows.Forms.Button tan;
        private System.Windows.Forms.Button cos_h;
        private System.Windows.Forms.Button seno_h;
        private System.Windows.Forms.Button coseno;
        private System.Windows.Forms.Button seno;
        private System.Windows.Forms.Button Firma;
        private System.Windows.Forms.Label label1;
    }
}

