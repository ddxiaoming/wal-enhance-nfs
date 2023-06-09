// SPDX-License-Identifier: LGPL-3.0-or-later
/*
 * Copyright IBM Corporation, 2012
 *  Contributor: Frank Filz <ffilz@us.ibm.com>
 *
 * --------------------------
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#include "display.h"

void show_display_buffer(struct display_buffer *dspbuf, char *cmt)
{
	printf("%s size=%z len=%z buffer=%s\n", cmt, dspbuf->b_size,
	       strlen(dspbuf->b_start), dspbuf->b_start);
}

int main(int argc, char **argv)
{
	char *opaque1 = "this-is-opaque";
	char *opaque2 = "\3\4\012\65\0";
	char *opaque3 = "\3\4\012\65\0\55\66";
	char *opaque4 = "aaa\012\0";
	char buffer[10];
	struct display_buffer display = { sizeof(buffer), buffer, buffer };
	char buffer2[200];
	struct display_buffer display2 = { sizeof(buffer2), buffer2, buffer2 };
	char buffer3[14];
	struct display_buffer display3 = { sizeof(buffer3), buffer3, buffer3 };
	(void)display_printf(&display, "%s", "foo");
	(void)display_printf(&display, "%s", "foo");
	show_display_buffer(&display, "first test (foo, foo)");
	display_reset_buffer(&display);
	(void)display_printf(&display, "%s", "foo");
	(void)display_printf(&display, "%s", "foo");
	(void)display_printf(&display, "%s", "food");
	(void)display_printf(&display, "%s", "foo");
	show_display_buffer(&display, "second test (foo, foo, food, foo)");
	display_reset_buffer(&display);
	(void)display_printf(&display, "%s", "foo");
	(void)display_printf(&display, "%s", "foo");
	(void)display_printf(&display, "%s", "foo");
	show_display_buffer(&display, "third test (foo, foo, foo)");
	display_reset_buffer(&display);
	display_reset_buffer(&display);
	(void)display_printf(&display, "%s", "foo");
	(void)display_printf(&display, "%s", "foo");
	(void)display_printf(&display, "%s", "foo");
	(void)display_printf(&display, "%s", "f");
	show_display_buffer(&display, "fourth test (foo, foo, foo, f)");
	display_reset_buffer(&display);
	(void)display_printf(&display, "%d %d", 5, 50000000);
	(void)display_printf(&display2, "%d %d", 5, 50000000);
	show_display_buffer(&display, "fifth test (%d %d)");
	show_display_buffer(&display2, "fifth test (%d %d)");
	display_reset_buffer(&display);
	display_reset_buffer(&display2);
	(void)display_opaque_value(&display, opaque1, strlen(opaque1));
	show_display_buffer(&display, "opaque1");
	display_reset_buffer(&display);
	(void)display_opaque_value(&display, opaque2, strlen(opaque2));
	show_display_buffer(&display, "opaque2");
	display_reset_buffer(&display);
	(void)display_opaque_value(&display, opaque3, strlen(opaque3) + 3);
	show_display_buffer(&display, "opaque3");
	display_reset_buffer(&display2);
	(void)display_opaque_value(&display2, opaque1, strlen(opaque1));
	show_display_buffer(&display2, "opaque1");
	display_reset_buffer(&display2);
	(void)display_opaque_value(&display2, opaque2, strlen(opaque2));
	show_display_buffer(&display2, "opaque2");
	display_reset_buffer(&display2);
	(void)display_opaque_value(&display2, opaque3, strlen(opaque3) + 3);
	show_display_buffer(&display2, "opaque3");
	display_reset_buffer(&display2);
	(void)display_opaque_value(&display2, opaque4, strlen(opaque4));
	show_display_buffer(&display2, "opaque4");
	display_reset_buffer(&display2);
	display_reset_buffer(&display3);
	(void)display_opaque_value(&display3, opaque1, strlen(opaque1));
	show_display_buffer(&display3, "opaque1");
	display_reset_buffer(&display3);
	(void)display_opaque_value(&display3, opaque2, strlen(opaque2));
	show_display_buffer(&display3, "opaque2");
	display_reset_buffer(&display3);
	(void)display_opaque_value(&display3, opaque3, strlen(opaque3) + 3);
	show_display_buffer(&display3, "opaque3");
	display_reset_buffer(&display3);
	return 0;
}
