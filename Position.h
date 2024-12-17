//
// Created by Dell on 12/17/2024.
//

#ifndef UNTITLED_POSITION_H
#define UNTITLED_POSITION_H
enum pos_type{
    CENTER,
    MOUSE,
    ON_PARENT,
    ALWAYS_CENTER,
    NONE,
    CUSTOM //the position will be based on x and y coordinates
};
typedef struct {
    enum pos_type type;
    gint x;
    gint y;
}Position;

//create  position based on a predefined position type and/or coordinates(x and y)
Position createPosition(enum pos_type type, int x, int y)
{
    Position pos;
    pos.type=type;
    pos.x=x;
    pos.y=y;
    return (Position) pos;
}
void setWinPosition(GtkWindow* window, Position pos)
{
    //Set the window position based on the given position
    switch(pos.type)
    {
        case CENTER:
            gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
            return;

        case MOUSE:
            gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_MOUSE);
            return;

        case ALWAYS_CENTER://center allwayse
            gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);
            return;

        case ON_PARENT://on parent
            gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ON_PARENT);
            return;

        case CUSTOM://Customized position (given x and y)
            gtk_window_move(GTK_WINDOW(window), pos.x, pos.y);
            return;

        default ://when 'NONE' is chosed
            gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_NONE);
            return;
    }

}

#endif //UNTITLED_POSITION_H
