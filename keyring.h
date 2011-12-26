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
#ifndef __KEYRING_H__
#define __KEYRING_H__

int
keyring_list(void);

int
keyring_getdef(void);

int
keyring_setdef(const char *keyname);

int
keyring_lock(const char *keyname);

int
keyring_info(const char *keyname);

int
keyring_delete(const char *keyname);

int
keyring_create(const char *keyname,
               const char *password);

int
keyring_unlock(const char *keyname,
               const char *password);

int
keyring_modify(const char *keyname,
               const char *password,
               const char *new_password);

#endif /* __KEYRING_H__ */
