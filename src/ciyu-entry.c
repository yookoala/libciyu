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

#include <stdio.h>
#include <ciyu-entry.h>


/**
 * SECTION: ciyu-entry
 * @short_description: A Ci Yu entry.
 *
 * The #CiyuEntry is a class to represent a Chinese vocab (Ci Yu)
 */
G_DEFINE_TYPE (CiyuEntry, ciyu_entry, G_TYPE_OBJECT)

#define CIYU_ENTRY_GET_PRIVATE(o) \
    (G_TYPE_INSTANCE_GET_PRIVATE ((o), CIYU_ENTRY_TYPE, CiyuEntryPrivate))

struct _CiyuEntryPrivate
{
    gchar *ciyu;
    guint frequency;
};

enum
{
    PROP_0,
    PROP_CIYU_ENTRY_CIYU,
    PROP_CIYU_ENTRY_FREQUENCY,
    N_PROPERTIES
};

static GParamSpec *obj_properties[N_PROPERTIES] = { NULL, };


static void
ciyu_entry_init (CiyuEntry *object)
{
    CiyuEntryPrivate *priv = CIYU_ENTRY_GET_PRIVATE (object);
    priv->ciyu = NULL;
    priv->frequency = 0;
}


static void
ciyu_entry_finalize (GObject *object)
{
    CiyuEntryPrivate *priv = CIYU_ENTRY_GET_PRIVATE (object);
    g_free (priv->ciyu);
    G_OBJECT_CLASS (ciyu_entry_parent_class)->finalize (object);
}


static void
ciyu_entry_set_property (GObject *object,
                         guint property_id,
                         const GValue *value,
                         GParamSpec *pspec)
{
    CiyuEntryPrivate *priv = CIYU_ENTRY_GET_PRIVATE (object);

    switch (property_id) {
        case PROP_CIYU_ENTRY_CIYU:
            g_free (priv->ciyu);
            priv->ciyu = g_value_dup_string (value);
            break;
        case PROP_CIYU_ENTRY_FREQUENCY:
            priv->frequency = g_value_get_uint (value);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
            break;
    }
}


static void
ciyu_entry_get_property (GObject *object,
                         guint property_id,
                         GValue *value,
                         GParamSpec *pspec)
{
    CiyuEntryPrivate *priv = CIYU_ENTRY_GET_PRIVATE (object);

    switch (property_id) {
        case PROP_CIYU_ENTRY_CIYU:
            g_value_set_string (value, priv->ciyu);
            break;
        case PROP_CIYU_ENTRY_FREQUENCY:
            g_value_set_uint (value, priv->frequency);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
            break;
    }
}


static void
ciyu_entry_class_init (CiyuEntryClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS (klass);
    object_class->set_property = ciyu_entry_set_property;
    object_class->get_property = ciyu_entry_get_property;
    object_class->finalize = ciyu_entry_finalize;

    /**
     * CiyuEntry:ciyu:
     *
     * The entity content.
     */
    obj_properties[PROP_CIYU_ENTRY_CIYU] =
        g_param_spec_string ("ciyu",
                             "Ciyu",
                             "The Chinese vocab / Ci Yu",
                             "",
                             G_PARAM_READWRITE |
                             G_PARAM_CONSTRUCT);

    /**
     * CiyuEntry:frequency:
     *
     * The frequency of the ciyu.
     */

    obj_properties[PROP_CIYU_ENTRY_FREQUENCY] =
        g_param_spec_uint ("frequency",
                           "Frequency",
                           "The frequency of the Chinese vocab / Ci Yu",
                           0, 65535, 0,
                           G_PARAM_CONSTRUCT_ONLY |
                           G_PARAM_READWRITE);

    g_object_class_install_properties (object_class,
                                       N_PROPERTIES,
                                       obj_properties);
    g_type_class_add_private (object_class, sizeof (CiyuEntryPrivate));
}


/**
 * ciyu_entry_new:
 *
 * Allocates a new #CiyuEntry.
 *
 * Return value: a new #CiyuEntry.
 */
CiyuEntry* ciyu_entry_new ()
{
    CiyuEntry *entry;
    entry = g_object_new (CIYU_ENTRY_TYPE, NULL);
    return entry;
}


/**
 * ciyu_entry_hello:
 * @entry: a #CiyuEntry
 *
 * Prints the Ciyu out.
 *
 * Return value: nothing.
 */
void
ciyu_entry_hello (CiyuEntry *entry)
{
    CiyuEntryPrivate *priv;
    g_return_if_fail (entry != NULL);
    priv = CIYU_ENTRY_GET_PRIVATE (entry);
    printf ("Hello, %s!\n", priv->ciyu);
}
