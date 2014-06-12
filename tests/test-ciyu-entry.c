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

    entry = g_object_new (CIYU_ENTRY_TYPE, NULL);
    ciyu_entry_print (entry);
    g_object_unref (entry);

    return 0;
}

#endif /* CIYU_H */
