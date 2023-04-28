#include <gtk-3.0/gtk/gtk.h>

int main(int argc, char *argv[]){
    //Declaramos widgets
    GtkWidget *window;

    //Inicializamos GTK y widgets
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //Creamos las conexiones
    g_signal_connect(G_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    //Mostramos nuestra ventana
    gtk_widget_show_all(window);

    //Bucle de ejecución de GTK
    gtk_main();

    return 0;
}