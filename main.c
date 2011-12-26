/*
   Copyright (C) 2011, Alexander Thomas

   This file is part of the Gnome Keyring Command Line Tool.

   This is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this tool.  If not, see <http://www.gnu.org/licenses/>.

   Author: ALexander Thomas <alexander@collab.net>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <getopt.h>
#include "usage.h"
#include "keyring.h"
#include "config.h"

static struct option long_options[] = {
  {"list", 0, 0, 't'},
  {"setdef", 1, 0, 's'},
  {"getdef", 0, 0, 'g'},
  {"create", 1, 0, 'c'},
  {"delete", 1, 0, 'd'},
  {"lock", 1, 0, 'l'},
  {"unlock", 1, 0, 'u'},
  {"modify", 1, 0, 'm'},
  {"info", 1, 0, 'i'},
  {"help", 0, 0, 'h'},
  {"version", 0, 0, 'v'},
  {0, 0, 0, 0}
};

#define SHORT_OPTIONS "ts:gc:d:l:u:m:i:hp:n:v"

GMainLoop *loop = NULL;


char *error_msg[]={
"",
"Access to keyring denied\n",
"The gnome-keyring-daemon application is not running\n",
"The keyring has already been unlocked.\n",
"A keyring with that name does not exist.\n",
"Programmer error: The application sent invalid data.\n",
"Error communicating with gnome-keyring-daemon\n",
"User interupted\n",
"A keyring with that name already exists\n",
"No matching results\n",
"Feature not supported\n"
};


int
main(int argc, char *argv[])
{
  int opt;
  int option_index = 0;
  int option_create = 0;
  int option_modify = 0;
  int option_unlock = 0;
  char *keyname = NULL;
  char *password = NULL;
  char *new_password = NULL;
  int ret;

  if (argc <= 1)
    print_usage(argv[0]);

  g_set_application_name(PACKAGE_NAME); 

  while(1)
    {

      /* FIXME: Should not allow multiple subcommands in a single cmdline.
       * now in some cases only the first subcommand is executed and rest
       * is ignored. But in scenarios it can break. */

      /* FIXME: Should not allow -p and -n to given before subcommand. */

      opt = getopt_long(argc, argv, SHORT_OPTIONS,
                        long_options, &option_index);

      if (opt == -1)
        break;

      switch (opt)
        {
          case 't':
             exit(keyring_list());
             break;
          case 's':
             exit(keyring_setdef(optarg));
             break;
          case 'g':
             exit(keyring_getdef());
             break;
          case 'c':
             /* TODO: CREATE command. */
             option_create = 1;
             if (optarg)
               keyname = strdup(optarg);
             break;
          case 'd':
             exit(keyring_delete(optarg));
             break;
          case 'l':
             exit(keyring_lock(optarg));
             break;
          case 'u':
             option_unlock = 1;
             if (optarg)
               keyname = strdup(optarg);
             break;
          case 'm':
             option_modify = 1;
             if (optarg)
               keyname = strdup(optarg);
             break;
          case 'i':
             exit(keyring_info(optarg));
             break;
          case 'p':
             if (optarg)
               password = strdup(optarg);
             break;
          case 'n':
             if (optarg)
               new_password = strdup(optarg);
             break;
          case 'v':
             print_version();
             exit(0);
          case '?':
          case 'h':
             print_usage(argv[0]);
             exit(0);
             break;
        }
    }

  if (option_create == 1)
    {
      exit(keyring_create(keyname, password));
    }
  else if (option_modify == 1)
    {
      exit(keyring_modify(keyname, password, new_password));
    }
  else if (option_unlock == 1)
    {
      exit(keyring_unlock(keyname, password));
    }
  else
    {
      fprintf (stderr, "keyring: unkown command -- %s.", argv[1]);
      print_usage(argv[0]);
    }

  return 0;
}
