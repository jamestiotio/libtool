// -*- C++ -*-
//    main.cpp -- tagdemo test program
//    Copyright (C) 1998-2000 Free Software Foundation, Inc.
//    Originally by Thomas Tanner <tanner@ffii.org>
//    This file is part of GNU Libtool.

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
// USA.


#include "foo.h"
#include "baz.h"
#include <stdio.h>


int
main (int, char *[])
{
  printf ("Welcome to GNU libtool tagdemo!\n");

  foobar_derived FB;
  // Instantiate the derived class.

  foobar *fb = &FB;
  // Have some fun with polymorphism.

  int value = fb->hello();

  printf ("foobar::hello returned: %i\n", value);
  if (value == HELLO_RET)
    printf("foobar::hello is ok!\n");

  if (fb->foo() == FOO_RET)
    printf("foobar::foo is ok!\n");

  // --------------

  barbaz_derived BB;
  // Instantiate the derived class.

  barbaz *bb = &BB;
  // Have some fun with polymorphism.


  // barbaz_derived::baz() should return FOO_RET since it calls
  // foobar_derived::foo(), which in turn calls ::foo().
  if (bb->baz() == FOO_RET)
    printf("barbaz::baz is ok!\n");

  return 0;
}