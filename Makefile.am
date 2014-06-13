# Point to our macro directory and pick up user flags from the environment
ACLOCAL_AMFLAGS  = -I m4 ${ACLOCAL_FLAGS}
AUTOMAKE_OPTIONS = subdir-objects


# -- Common build flags --------------
AM_CFLAGS = $(GLIB_CFLAGS) $(GOBJECT_CFLAGS) -I$(top_srcdir)/src
AM_LDFLAGS = $(GLIB_LIBS) $(GOBJECT_LIBS)


# -- Library -------------------------
lib_LTLIBRARIES = src/libciyu.la

src_libciyu_la_SOURCES = \
	src/ciyu-entry.c \
	$(NULL)

src_libciyu_la_include_HEADERS = \
	src/ciyu-entry.h \
	$(NULL)

src_libciyu_la_includedir = $(includedir)/ciyu


# -- Introspection -------------------
-include $(INTROSPECTION_MAKEFILE)

if HAVE_INTROSPECTION
INTROSPECTION_SCANNER_ARGS = --add-include-path=$(srcdir)
INTROSPECTION_COMPILER_ARGS = --includedir=$(srcdir)

introspection_files = $(src_libciyu_la_SOURCES) $(src_libciyu_la_include_HEADERS)

src_Ciyu-0.1.gir: $(INTROSPECTION_SCANNER) src/libciyu.la Makefile
src_Ciyu_0_1_gir_NAMESPACE = Ciyu
src_Ciyu_0_1_gir_VERSION = $(VERSION)
src_Ciyu_0_1_gir_SCANNERFLAGS = \
	--warn-all \
	$(NULL)
src_Ciyu_0_1_gir_CFLAGS = \
	$(AM_CFLAGS) \
	$(NULL)

src_Ciyu_0_1_gir_INCLUDES = GObject-2.0
src_Ciyu_0_1_gir_PACKAGES = gobject-2.0
src_Ciyu_0_1_gir_LIBS = src/libciyu.la
src_Ciyu_0_1_gir_FILES = $(introspection_files)
src_Ciyu_0_1_gir_EXPORT_PACKAGES = ciyu

INTROSPECTION_GIRS = src/Ciyu-0.1.gir
girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibsdir = $(libdir)/girepository-1.0
typelibs_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)
endif




# -- Tests ---------------------------
check_PROGRAMS = \
	tests/test_ciyu_entry \
	$(NULL)

tests_test_ciyu_entry_SOURCES = tests/test-ciyu-entry.c
tests_test_ciyu_entry_LDADD = src/libciyu.la

TESTS = $(check_PROGRAMS)


# -- Common --------------------------
CLEANFILES = \
	$(gir_DATA) \
	$(typelib_DATA) \
	$(NULL)

EXTRA_DIST = \
	autogen.sh \
	README.md \
	$(NULL)

