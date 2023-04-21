#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int connection()
{
  FILE *serial_port;
  char buffer[256];

  // Open the serial port in read-only binary mode
  serial_port = fopen("/dev/ttyUSB0", "rb");

  if (serial_port == NULL)
  {
    printf("Error opening serial port!\n");
    return 1;
  }

  // Read and print the contents of the serial port
  while (fgets(buffer, sizeof(buffer), serial_port) != NULL)
  {
    mvprintw(4, 6, buffer);
  }

  // Close the serial port
  fclose(serial_port);
  return 0;
}

int main()
{
  int ch, highlight = 1;
  initscr();
  clear();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);

  while (1)
  {
    clear();
    attron(A_BOLD);
    mvprintw(2, 10, "- VulCAN PROGRAM -");
    attroff(A_BOLD);

    mvprintw(4, 2, "Please select an option:");
    mvprintw(6, 2, "1. Serial Reader");
    mvprintw(7, 2, "2. Placeholder");
    mvprintw(8, 2, "3. Quit");

    if (highlight == 1)
    {

      attron(A_REVERSE);
      attron(A_BOLD);
      mvprintw(6, 2, "1. Serial Reader ");
      attroff(A_REVERSE);
      attroff(A_BOLD);
    }
    else if (highlight == 2)
    {

      attron(A_REVERSE);
      attron(A_BOLD);
      mvprintw(7, 2, "2. Placeholder   ");
      attroff(A_REVERSE);
      attroff(A_BOLD);
    }
    else if (highlight == 3)
    {
      attron(A_REVERSE);
      attron(A_BOLD);
      mvprintw(8, 2, "3. Quit          ");
      attroff(A_REVERSE);
      attroff(A_BOLD);
    }

    refresh();
    ch = getch();
    switch (ch)
    {
    case KEY_UP:
      highlight--;
      if (highlight == 0)
        highlight = 3;
      break;
    case KEY_DOWN:
      highlight++;
      if (highlight == 4)
        highlight = 1;
      break;
    case 10:
      if (highlight == 1)
      {
          clear();
          mvprintw(6, 2, "SERIAL READER:");
        ch = getch();
        if (ch == 10)
        {
          connection();
          // TODO: Add Serial Reader functionality
        }
      }
      else if (highlight == 2)
      {
        
      }
      else if (highlight == 3)
      {
        clear();
        attron(A_BOLD);
        mvprintw(2, 10, "- VulCAN PROGRAM -");
        attroff(A_BOLD);
        mvprintw(8, 2, "Press [ENTER] to quit");
        ch = getch();
        if (ch == 10)
        {
          endwin();
          return 0;
        }
        else
        {
          return 0;
        }
      }
      break;
    }
  }
  return 0;
}


