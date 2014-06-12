/* Copyright (c) 2014 - The Cangjians.
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

#ifndef __CIYU_ENTRY_H__
#define __CIYU_ENTRY_H__

#include <glib.h>
#include <glib-object.h>

#define CIYU_ENTRY_TYPE \
    (ciyu_entry_get_type())
#define CIYU_ENTRY(o) \
    (G_TYPE_CHECK_INSTANCE_CAST ((o), CIYU_ENTRY_TYPE, CiyuEntry))
#define CIYU_ENTRY_CLASS(c) \
    (G_TYPE_CHECK_CLASS_CAST ((c), CIYU_ENTRY_TYPE, CiyuEntryClass))
#define CIYU_IS_ENTRY(o) \
    (G_TYPE_CHECK_INSTANCE_TYPE ((o), CIYU_ENTRY_TYPE))
#define CIYU_IS_ENTRY_CLASS(c) \
    (G_TYPE_CHECK_CLASS_TYPE ((c), CIYU_ENTRY_TYPE))
#define CIYU_ENTRY_GET_CLASS(o) \
    (G_TYPE_INSTANCE_GET_CLASS ((o), CIYU_ENTRY_TYPE, CiyuEntryClass))


typedef struct _CiyuEntry CiyuEntry;
typedef struct _CiyuEntryPrivate CiyuEntryPrivate;
typedef struct _CiyuEntryClass CiyuEntryClass;

struct _CiyuEntry {
    GObject parent;
};

struct _CiyuEntryClass {
    GObjectClass parent;
};

GType ciyu_entry_get_type () G_GNUC_CONST;

CiyuEntry* ciyu_entry_new (void);

void ciyu_entry_print (CiyuEntry *entry);


#endif /* __CIYU_ENTRY_H__ */
