bin_PROGRAMS = keyring_tool
INCLUDES = ${GNOMEKEYRING_CFLAGS} ${GLIB_2_CFLAGS}
keyring_tool_SOURCES = main.c \
			usage.c \
			keyring.c

noinst_HEADERS = usage.h \
			keyring.h

keyring_tool_LDADD = ${GNOMEKEYRING_LIBS} ${GLIB_2_LIBS}
