/* Copyright (c) 2013 - The Cangjians.
 *
 * This file is part of libciyu.
 *
 * libciyu is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libciyu is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libciyu.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <ciyu-entry.h>

#ifndef CIYU_H
#define CIYU_H

int main (int argc, char *argv[]) {

    CiyuEntry *entry;

    gchar *ciyu;

    entry = g_object_new (CIYU_ENTRY_TYPE,
                          "ciyu", "\xe5\xbb\xba\xe8\xa8\xad\xe6\xb0\x91\xe4\xb8\xbb\xe4\xb8\xad\xe5\x9c\x8b",
                          "frequency", 123,
                          NULL);

    g_object_get (G_OBJECT (entry), "ciyu", &ciyu, NULL);
    g_assert_cmpstr (ciyu, ==, "\xe5\xbb\xba\xe8\xa8\xad\xe6\xb0\x91\xe4\xb8\xbb\xe4\xb8\xad\xe5\x9c\x8b");

    ciyu_entry_print (entry);
    g_object_unref (entry);

    return 0;
}

#endif /* CIYU_H */
