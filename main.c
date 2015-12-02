/* 
Girbox

Copyright (C) 2015 Billy Maddex

This file is part of Girbox.

Girbox is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Girbox is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Girbox.  If not, see <http://www.gnu.org/licenses/>.

Author: Billy Maddex 
*/

#include <string.h>
#include <gtk/gtk.h>

/* ps3ir lib header */
#include "ps3ir.h"

/* millisecond delay constant */
#define DELAY 100

int ps3_ir;
char *device = "/dev/ps3ir";
GtkStatusbar *status_bar;

int main(int argc, char *argv[])
{
  GtkBuilder *gtkBuilder;
  GtkWidget *window;

  gtk_init(&argc, &argv);

  gtkBuilder = gtk_builder_new();
  gtk_builder_add_from_file(gtkBuilder, "girbox.glade", NULL);

  window = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "mainWindow"));
  gtk_builder_connect_signals(gtkBuilder, NULL);
  //g_object_unref(G_OBJECT(gtkBuilder));

  ps3_ir = ps3_open(device);
  ps3_set_mode(ps3_ir, VIRTUAL_MODE);

  // temp code to handle statusbar
  const gchar *connection_status = "connectionStatus";
  const gchar *context = "usb_status";
  const gchar *status_message;
  GtkStatusbar *status_bar;
  guint context_id;
  
  status_bar = GTK_STATUSBAR(gtk_builder_get_object(gtkBuilder, connection_status));

  context_id = gtk_statusbar_get_context_id (status_bar, context);

  if (ps3_ir < 0)
    status_message = "Device Not Connected";
  else
    status_message = "Device Connected";

  gtk_statusbar_push(status_bar, context_id, status_message);
  
  gtk_widget_show(window);       
  gtk_main();
  
  return 0;
}

/* gracefull exit */
void on_mainWindow_destroy()
{
  ps3_set_mode(ps3_ir, VIRTUAL_MODE);
  ps3_close(ps3_ir);
  gtk_main_quit();
}

/* factory reset button handler */
void reset_button()
{
  ps3_factory_reset(ps3_ir);

  return;
}

/* ps3 mode set handler */
void mode_button(GtkButton *ps3mode)
{
  const char *mode_label;
  char mode;

  mode_label = gtk_button_get_label(ps3mode);

  if(strcmp(mode_label, "Teach Your Remote") == 0)
    mode = TEACH_MODE;

  if(strcmp(mode_label, "Virtual Remote") == 0)
    mode = VIRTUAL_MODE;

  ps3_set_mode(ps3_ir, mode);

  printf("Set mode to %s\n", mode_label);
  
  return;
}

/* ps3 button click handler */
void command_button(GtkButton *ps3button)
{
  const char *ps3label;
  char command;

  ps3label = gtk_button_get_label(ps3button);

  if(strcmp(ps3label, "Up") == 0)
    command = UP;

  else if(strcmp(ps3label, "Down") == 0)
    command = DOWN;

  else if(strcmp(ps3label, "Left") == 0)
    command = LEFT;

  else if(strcmp(ps3label, "Right") == 0)
    command = RIGHT;

  else if(strcmp(ps3label, "Enter") == 0)
    command = ENTER;

  else if(strcmp(ps3label, "Circle") == 0)
    command = CIRCLE;

  else if(strcmp(ps3label, "X") == 0)
    command = BIG_X;

  else if(strcmp(ps3label, "Triangle") == 0)
    command = TRIANGLE;

  else if(strcmp(ps3label, "Square") == 0)
    command = SQUARE;

  else if(strcmp(ps3label, "Select") == 0)
    command = SELECT;

  else if(strcmp(ps3label, "Start") == 0)
    command = START;

  else if(strcmp(ps3label, "PS") == 0)
    command = PS;

  else if(strcmp(ps3label, "L1") == 0)
    command = L1;

  else if(strcmp(ps3label, "L2") == 0)
    command = L2;

  else if(strcmp(ps3label, "L3") == 0)
    command = L3;

  else if(strcmp(ps3label, "R1") == 0)
    command = R1;

  else if(strcmp(ps3label, "R2") == 0)
    command = R2;

  else if(strcmp(ps3label, "R3") == 0)
    command = R3;
  
  ps3_keydown(ps3_ir, command);

  delay(DELAY);

  ps3_keyup(ps3_ir);

  printf("Sent key %s\n", ps3label);
  
  return;
}
