/*
 * vsockets_hostname.c - vsockets hostname (CID) fetcher
 *
 * Copyright (C) 2015 Pedro Mendes da Silva
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <stdlib.h>

#include "vmci_sockets.h"
#include "sockets_common.h"

#include <stdio.h>



extern int dump_vsocket_properties();

int main()
{

   dump_vsocket_properties();

   return 0;
}