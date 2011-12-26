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
#ifndef __USAGE_H__
#define __USAGE_H__

#define ERROR "ERROR"
#define WARNING "WARNING"
#define INFO "INFO"
#define DEBUG "DEBUG"

void
print_usage (char *appname);

void
print_error (int err_code, char *err_type, char *err_msg);

void
print_version (void);

#endif /* __USAGE_H__ */
