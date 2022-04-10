using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using SQLite;

namespace Agenda_escolar
{
    public class base_dato
    {
        
       

        public string nombre_evento { get; set; }
        public string detalles_evento { get; set; }
        public double horario_evento { get; set; }

        

    }
}