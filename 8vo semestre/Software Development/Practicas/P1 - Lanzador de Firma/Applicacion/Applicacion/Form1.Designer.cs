namespace Applicacion
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
            this.Firma = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Firma
            // 
            this.Firma.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Firma.Location = new System.Drawing.Point(82, 49);
            this.Firma.Name = "Firma";
            this.Firma.Size = new System.Drawing.Size(75, 23);
            this.Firma.TabIndex = 0;
            this.Firma.Text = "Firma";
            this.Firma.UseVisualStyleBackColor = false;
            this.Firma.Click += new System.EventHandler(this.Firma_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkCyan;
            this.ClientSize = new System.Drawing.Size(245, 110);
            this.Controls.Add(this.Firma);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.ShowIcon = false;
            this.Text = "Lanzador de Firma";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button Firma;
    }
}

