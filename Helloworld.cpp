#include <gtk-3.0/gtk/gtk.h>

void on_button1_clicked(GtkWidget *button, GtkWidget *label);

int main(int argc, char *argv[]){
    //Declaramos widgets
    GtkWidget *window;
    GtkWidget *fixed1;
    GtkWidget *button1;
    GtkWidget *label1;
    GtkBuilder *builder;

    //Inicializamos GTK y widgets
    gtk_init(&argc, &argv);
    builder = gtk_builder_new_from_file("HolaMundo.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));

    //Creamos las conexiones
    g_signal_connect(G_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(button1), "clicked",
                     G_CALLBACK(on_button1_clicked), label1);                     

    //Mostramos nuestra ventana
    gtk_widget_show_all(window);

    //Bucle de ejecución de GTK
    gtk_main();

    return 0;
}

void on_button1_clicked(GtkWidget *button, GtkWidget *label){
    gtk_label_set_text(GTK_LABEL(label), (const gchar*) "Hello World");
}