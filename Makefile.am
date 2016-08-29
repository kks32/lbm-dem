# Stop autoconf looking for readme file
AUTOMAKE_OPTIONS = foreign

# M4 Macros
ACLOCAL_AMFLAGS = -I ./m4 

AM_LDFLAGS =  $(AM_LFLAGS)

AM_CPPFLAGS = -I include/ -I external/

# Main Program 
bin_PROGRAMS 	= lbmdem

lbmdem_SOURCES 	= src/main.cc

# Tests
check_PROGRAMS  = lbmdemtest

lbmdemtest_SOURCES = tests/test.cc \
                     tests/lb_node_2d_test.cc \
                     tests/lb_node_3d_test.cc


