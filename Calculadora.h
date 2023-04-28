#include <gtk-3.0/gtk/gtk.h>
#include <stdlib.h>
#include <string>

class Calculadora{
    friend void on_buttonSuma_clicked(GtkWidget *w, Calculadora *c);
    friend void on_buttonResta_clicked(GtkWidget *w, Calculadora *c);
    friend void on_buttonMultiplica_clicked(GtkWidget *w, Calculadora *c);
    friend void on_buttonDivide_clicked(GtkWidget *w, Calculadora *c);

    public:
        Calculadora();
        void Show();
        
    private:
        GtkWidget *_window;

        GtkWidget *_label1;
        GtkWidget *_labelOperator;
        GtkWidget *_label2;
        GtkWidget *_labelEqual;
        GtkWidget *_labelResult;
        
        GtkWidget *_entry1;
        GtkWidget *_entry2;
        
        GtkWidget *_buttonSuma;
        GtkWidget *_buttonResta;
        GtkWidget *_buttonMultiplica;
        GtkWidget *_buttonDivide;
};

void on_buttonSuma_clicked(GtkWidget *w, Calculadora *c);
void on_buttonResta_clicked(GtkWidget *w, Calculadora *c);
void on_buttonMultiplica_clicked(GtkWidget *w, Calculadora *c);
void on_buttonDivide_clicked(GtkWidget *w, Calculadora *c);