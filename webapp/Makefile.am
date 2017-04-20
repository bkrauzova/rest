AM_CPPFLAGS = -I$(top_srcdir)/include
AM_CXXFLAGS = -std=c++11

pkglib_LTLIBRARIES = rest.la

ecppSources = \
	rest.ecpp \
        assets.ecpp \
	asset_types.ecpp \
        powerchain.ecpp \
	first.ecpp \
	json.cc

rest_la_SOURCES = \
	$(ecppSources)

rest_la_LIBADD = $(top_builddir)/lib/librest.la
rest_la_LDFLAGS = -module -ltntnet

noinst_DATA = tntnet.xml
CLEANFILES = $(ecppSources:.ecpp=.cpp) tntnet.xml

SUFFIXES=.ecpp .jpg .cpp

.ecpp.cpp:
	$(ECPPC) -I $(top_srcdir)/web -o $@ $<
.jpg.cpp:
	$(ECPPC) -b -m image/jpeg -o $@ $<

tntnet.xml:
	( $(SHELL) $(TNTNET_CONFIG) --config=calc|awk '/<\/tntnet>/{print "  <compPath>\n    <entry>.libs</entry>\n  </compPath>"} {print}' ) >$@
