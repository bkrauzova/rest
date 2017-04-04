AM_CPPFLAGS = -I$(top_srcdir)/include

pkglib_LTLIBRARIES = rest.la

ecppSources = \
	rest.ecpp \
        assets.ecpp \
	asset_types.ecpp \
	error.ecpp \
	first.ecpp

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
