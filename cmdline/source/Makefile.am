bin_PROGRAMS = cmdline
cmdline_SOURCES = main.c++ fem/Element.c++ fem/LoadPattern.c++ fem/Model.c++ fem/NodalLoad.c++ fem/NodeRestrictions.c++ fem/SurfaceLoad.c++ fem/DomainLoad.c++ fem/FemEquation.c++ fem/Material.c++ fem/NodalDisplacement.c++ fem/Node.c++ \
	FempException.c++\
	fem/FemException.c++\
	fem/point.c++ \
	ProgramOptions.c++ 

cmdline_CPPFLAGS = $(eigen2_CFLAGS)
cmdline_LDADD = $(eigen2_LIBS)


if HAVE_RE2C
$(srcdir)/fem/Element.c++:	$(srcdir)/fem/Element.c++.re2c
	re2c -o $(srcdir)/fem/Element.c++ $(srcdir)/fem/Element.c++.re2c

$(srcdir)/ProgramOptions.c++:	$(srcdir)/ProgramOptions.c++.re2c
	re2c -o $(srcdir)/ProgramOptions.c++ $(srcdir)/ProgramOptions.c++.re2c
endif

