#include <gtk/gtk.h>
#include "Position.h"

typedef struct {
    gint width;
    gint height;
}Dimension;

typedef struct {
    GtkWidget* window;//the Window
    gchar* title;//Window's title
    Dimension dim;//Window's Dimension: x and y
    gchar pos;//Window's position as a character
    gboolean isResizable;//Is the window resizable
    const gchar* icon;//The icon path as a string
    gint border ;//The window's border
}Serjem;

Dimension assignDimension(gint w, gint h)
{
    Dimension dim;
    dim.width=w;
    dim.height=h;
    return (Dimension)dim;
}

//Allocate Serjem and it's components
Serjem* allocateSerjem()
{
    Serjem* s = (Serjem*)malloc(sizeof(Serjem));
    //gchar* title = (gchar*)malloc(sizeof(gchar));
    //gchar* pos = (gchar*)malloc(sizeof(gchar));
    //gchar* icon = (gchar*)malloc(sizeof(gchar));

    //Test if allocation succeded
//    if((!s) || (!title) || (!pos)||(!icon))
    if(!s)

    {
        printf("Erreur d'allocation, dans allocateSerjem()\n");
        exit(-1);
    }
    //Return the allocated window
    return (Serjem*)s;

}

//Like a constructor
Serjem* assignToSerjem(gchar* title, Dimension dim, gchar pos,
                       gboolean isResizable, gchar* icon, gint border)
{
    //Serjem's Allocation
    Serjem* s = allocateSerjem();

    //Configure Serjem's parameters
    //strcpy(s->title, title);//Copy the title
    //strcpy(s->pos, pos);//Copy the position
    // strcpy(s->icon, icon);//Copy the icon path
    s->title=strdup(title);
    s->icon=strdup(icon);
    s->pos= pos;
    //Set x and y Dimension
    s->dim.width = dim.width;
    s->dim.height = dim.height;
    //Set isResizable
    s->isResizable=isResizable;
    //Set the border
    s->border = border;
    //Return the serjem
    return (Serjem*)s;

}

void createSerjem(Serjem* s)
{
    //Create the window
    s->window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //Set the title
    gtk_window_set_title(GTK_WINDOW(s->window), s->title);
    //Set window's size
    gtk_window_set_default_size(GTK_WINDOW(s->window), (s->dim.width), (s->dim.height));
    //Set the resizable option
    gtk_window_set_resizable(GTK_WINDOW(s->window), s->isResizable);
    //Set window's position
    //GtkWindowPosition gwp = getWinPosition(s->pos);
    setWinPosition(GTK_WINDOW(s->window), createPosition(CUSTOM, 50, 0));
    //gtk_window_set_position(GTK_WINDOW(s->window), gwp);
    //Set the window's icon
    GdkPixbuf* icon = gdk_pixbuf_new_from_file(s->icon, NULL);
    gtk_window_set_icon(GTK_WINDOW(s->window), icon);
    //Add quit signal
    g_signal_connect(s->window, "destroy", gtk_main_quit, NULL);
    //Set the Border
    gtk_container_set_border_width (GTK_CONTAINER(s->window),s->border);

}

int main(int argc, char* argv[])
{
    //Init
    gtk_init(&argc, &argv);
    //Create Dimension(width and height)
    Dimension c=assignDimension(500, 800);//
    //Assign values to window(Constructor)
    Serjem* s =  assignToSerjem("Serjem",c, 'm',TRUE, "C:\\Users\\Dell\\Documents\\gtk_learn\\lock_img.png", 15);
    //Create the window based on values passed earlier
    createSerjem(s);

    //Button test
    GtkWidget* button = gtk_button_new_with_label("click me");
    gtk_container_add(GTK_CONTAINER(s->window), button);
    gtk_widget_set_size_request(button, 50, 50);

    //Show the window
    gtk_widget_show_all(s->window);
    //gtk main
    gtk_main();
    //Free the window
    free(s);
    return 0;
}
