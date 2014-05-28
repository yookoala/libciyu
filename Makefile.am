# Point to our macro directory and pick up user flags from the environment
ACLOCAL_AMFLAGS  = -I m4 ${ACLOCAL_FLAGS}


# -- Library -------------------------
lib_LTLIBRARIES = src/libciyu.la

src_libciyu_la_SOURCES = \
	src/ciyu-entry.c \
	$(NULL)

src_libciyu_la_include_HEADERS = \
	src/ciyu-entry.h \
	$(NULL)

src_libciyu_la_includedir = $(includedir)/ciyu


# -- Tests ---------------------------
check_PROGRAMS = \
	tests/test_ciyu_entry \
	$(NULL)

tests_test_ciyu_entry_SOURCES = tests/test-ciyu-entry.c src/ciyu-entry.h
tests_test_ciyu_entry_LDADD = src/libciyu.la

TESTS = $(check_PROGRAMS)


# -- Common --------------------------
CLEANFILES = \
	$(NULL)

EXTRA_DIST = \
	autogen.sh \
	README.md \
	$(NULL)


