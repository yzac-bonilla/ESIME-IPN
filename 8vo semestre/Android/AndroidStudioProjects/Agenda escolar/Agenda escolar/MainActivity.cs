using System;
using Android.App;
using Android.Content;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using Android.OS;

namespace Agenda_escolar
{
    [Activity(Label = "Agenda_escolar", MainLauncher = true, Icon = "@drawable/icon")]
    public class MainActivity : Activity
    {
        
        protected override void OnCreate(Bundle bundle)
        {
            base.OnCreate(bundle);

            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.Main);

            // Get our button from the layout resource,
            // and attach an event to it
            Button convertir = FindViewById<Button>(Resource.Id.btnconvertir);
            Button agregar = FindViewById<Button>(Resource.Id.Agregar_Evento);
           
            convertir.Click += delegate
            {
                var geoUri = Android.Net.Uri.Parse("geo:19.4885726,-99.17532189999997");
                var mapIntent = new Intent(Intent.ActionView, geoUri);
                StartActivity(mapIntent);

            };
            agregar.Click += delegate {
                StartActivity(typeof(Eventos));
            };
        }
    }
}

