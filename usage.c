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
#include "usage.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>

extern char *error_msg[];

const char *usage_str = "\n"
"Keyring tools is application that lets you manage keyrings.\n\n"
"Usage:\n"
"  %s {--list | -t}\n"
"     List all the existing keyring names.\n\n"
"  %s {--setdef=keyring_name | -s keyring_name}\n"
"     Set given keyring as default keyring.\n\n"
"  %s {--getdef | -g}\n"
"     Get keyring name of default keyring.\n\n"
"  %s {--create=keyring_name | -c keyring_name} [-p password]\n"
"     Create a given keyring with a password.\n\n"
"  %s {--delete=keyring_name | -d keyring_name}\n"
"     Delete a given keyring.\n\n"
"  %s {--lock=keyring_name | -l keyring_name}\n"
"     Lock a given keyring.\n\n"
"  %s {--unlock=keyring_name | -u keyring_name} [-p password]\n"
"     Unlock given keyring with a password.\n\n"
"  %s {--modify=keyring_name | -m keyring_name} [-p password] [-n new_password]\n"
"     Modify given keyring, old password with a new password.\n\n"
"  %s {--info=keyring_name | -i keyring_name}\n"
"     Get information of a given keyring.\n\n"
"  %s {--version | -v}\n"
"     print version information.\n\n"
"  %s {--help | -h}\n"
"     Print this help.\n\n";


void
print_usage (char *appname)
{
  fprintf (stderr, usage_str, appname, appname, appname,
           appname, appname, appname, appname, appname,
           appname, appname, appname);
  exit(0);
}

void
print_error (int err_code, char *err_type, char *err_msg)
{
  fprintf (stderr, "%s: %s", err_type, error_msg[err_code]);
  return;
}

void
print_version (void)
{
  fprintf(stderr, "%s\n", PACKAGE_STRING);
  return;
}
