#include "Calculadora.h"

Calculadora::Calculadora(){

    GtkBuilder * builder = gtk_builder_new_from_file("Calculadora.glade");

   _window = GTK_WIDGET((gtk_builder_get_object(builder, "window")));

    // No necesitamos importar los contenedores (Gran ventaja)
    // GtkWidget *Box1 = GTK_WIDGET((gtk_builder_get_object(builder, "Box1")));
    // GtkWidget *Box2 = GTK_WIDGET((gtk_builder_get_object(builder, "Box2")));
    // GtkWidget *Grid1 = GTK_WIDGET((gtk_builder_get_object(builder, "Grid1")));

    _label1 = GTK_WIDGET((gtk_builder_get_object(builder, "label1")));
    _labelOperator = GTK_WIDGET((gtk_builder_get_object(builder, "labelOperator")));
    _label2 = GTK_WIDGET((gtk_builder_get_object(builder, "label2")));
    _labelEqual = GTK_WIDGET((gtk_builder_get_object(builder, "labelEqual")));
    _labelResult = GTK_WIDGET((gtk_builder_get_object(builder, "labelResult")));

    _entry1 = GTK_WIDGET((gtk_builder_get_object(builder, "entry1")));
    _entry2 = GTK_WIDGET((gtk_builder_get_object(builder, "entry2")));

    _buttonSuma = GTK_WIDGET((gtk_builder_get_object(builder, "buttonSuma")));
    _buttonResta = GTK_WIDGET((gtk_builder_get_object(builder, "buttonResta")));
    _buttonMultiplica = GTK_WIDGET((gtk_builder_get_object(builder, "buttonMultiplica")));
    _buttonDivide = GTK_WIDGET((gtk_builder_get_object(builder, "buttonDivide")));

    //Conexiones:
    g_signal_connect(G_OBJECT(_buttonSuma), "clicked", G_CALLBACK(on_buttonSuma_clicked), this);
    g_signal_connect(G_OBJECT(_buttonResta), "clicked", G_CALLBACK(on_buttonResta_clicked), this);
    g_signal_connect(G_OBJECT(_buttonMultiplica), "clicked", G_CALLBACK(on_buttonMultiplica_clicked), this);
    g_signal_connect(G_OBJECT(_buttonDivide), "clicked", G_CALLBACK(on_buttonDivide_clicked), this);
    g_signal_connect(G_OBJECT(_window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
}
    
void Calculadora::Show(){
    gtk_widget_show_all(_window);
}

void on_buttonSuma_clicked(GtkWidget *, Calculadora *c){
    gchar a[] = "+";
    double result = atof(gtk_entry_get_text(GTK_ENTRY(c->_entry1))) + atof(gtk_entry_get_text(GTK_ENTRY(c->_entry2)));
    gtk_label_set_label(GTK_LABEL(c->_label1), gtk_entry_get_text(GTK_ENTRY(c->_entry1)));
    gtk_label_set_label(GTK_LABEL(c->_label2), gtk_entry_get_text(GTK_ENTRY(c->_entry2)));
    gtk_label_set_label(GTK_LABEL(c->_labelResult), std::to_string(result).c_str());
    gtk_label_set_label(GTK_LABEL(c->_labelOperator), a);
}

void on_buttonResta_clicked(GtkWidget *, Calculadora *c){
    gchar a[] = "-";
    double result = atof(gtk_entry_get_text(GTK_ENTRY(c->_entry1))) - atof(gtk_entry_get_text(GTK_ENTRY(c->_entry2)));
    gtk_label_set_label(GTK_LABEL(c->_label1), gtk_entry_get_text(GTK_ENTRY(c->_entry1)));
    gtk_label_set_label(GTK_LABEL(c->_label2), gtk_entry_get_text(GTK_ENTRY(c->_entry2)));
    gtk_label_set_label(GTK_LABEL(c->_labelResult), std::to_string(result).c_str());
    gtk_label_set_label(GTK_LABEL(c->_labelOperator), a);
}

void on_buttonMultiplica_clicked(GtkWidget *, Calculadora *c){
    gchar a[] = "*";
    double result = atof(gtk_entry_get_text(GTK_ENTRY(c->_entry1))) * atof(gtk_entry_get_text(GTK_ENTRY(c->_entry2)));
    gtk_label_set_label(GTK_LABEL(c->_label1), gtk_entry_get_text(GTK_ENTRY(c->_entry1)));
    gtk_label_set_label(GTK_LABEL(c->_label2), gtk_entry_get_text(GTK_ENTRY(c->_entry2)));
    gtk_label_set_label(GTK_LABEL(c->_labelResult), std::to_string(result).c_str());
    gtk_label_set_label(GTK_LABEL(c->_labelOperator), a);
}

void on_buttonDivide_clicked(GtkWidget *, Calculadora *c){
    gchar a[] = "/";
    double result = atof(gtk_entry_get_text(GTK_ENTRY(c->_entry1))) / atof(gtk_entry_get_text(GTK_ENTRY(c->_entry2)));
    gtk_label_set_label(GTK_LABEL(c->_label1), gtk_entry_get_text(GTK_ENTRY(c->_entry1)));
    gtk_label_set_label(GTK_LABEL(c->_label2), gtk_entry_get_text(GTK_ENTRY(c->_entry2)));
    gtk_label_set_label(GTK_LABEL(c->_labelResult), std::to_string(result).c_str());
    gtk_label_set_label(GTK_LABEL(c->_labelOperator), a);
}

int main(int argc, char *argv[]){
    //Inicializamos motor gtk
    gtk_init(&argc, &argv);

    //Creamos nuestra calculadora y la mostramos
    Calculadora c;
    c.Show();

    //Bucle de ejecución
    gtk_main();
    return 0;
}
