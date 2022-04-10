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
using System.IO;
using SQLite;

namespace Agenda_escolar
{
    [Activity(Label = "Eventos")]
    public class Eventos : Activity
    {
        protected override void OnCreate(Bundle bundle)
        {
            base.OnCreate(bundle);
            SetContentView(Resource.Layout.Eventos);
            // Create your application 
            Button guarda = FindViewById<Button>(Resource.Id.btnguarda_base);
            EditText nombre = FindViewById<EditText>(Resource.Id.txtevento);
            EditText detalles = FindViewById<EditText>(Resource.Id.txtdetalles);
            EditText horario = FindViewById<EditText>(Resource.Id.txthorario);

            guarda.Click += delegate
            {

                var path = System.Environment.GetFolderPath(System.Environment.SpecialFolder.Personal);
                path = Path.Combine(path, "Base.db3");
                var conn = new SQLiteConnection(path);
                conn.CreateTable < base_dato >();
                var insertar = new base_dato();
                string nombre_e, detalle_e;
                double horario_e;
                nombre_e = nombre.Text;
                detalle_e = detalles.Text;
                horario_e = double.Parse(horario.Text);
                insertar.nombre_evento = nombre_e;
                insertar.detalles_evento = detalle_e;
                insertar.horario_evento = horario_e;
                conn.Insert(insertar);
                var elementos = from s in conn.Table<base_dato>() select s;
                foreach(var fila in elementos)
                {
                    Toast.MakeText(this, fila.nombre_evento.ToString(), ToastLength.Short).Show();
                    Toast.MakeText(this, fila.detalles_evento.ToString(), ToastLength.Short).Show();
                    Toast.MakeText(this, fila.horario_evento.ToString(), ToastLength.Short).Show();
                }

            };
        }
    }
}