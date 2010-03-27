bin_PROGRAMS = cmdline
cmdline_SOURCES = main.c++ fem/Analysis.c++ fem/Element.c++ fem/LoadPattern.c++ fem/Model.c++ fem/NodalLoad.c++ fem/NodeRestrictions.c++ fem/SurfaceLoad.c++ fem/DomainLoad.c++ fem/FemEquation.c++ fem/Material.c++ fem/NodalDisplacement.c++ fem/Node.c++ \
	fem/point.c++ \
	ProgramOptions.c++ \
	parsers/json.c


if HAVE_RE2C
$(srcdir)/fem/Element.c++:	$(srcdir)/fem/Element.c++.re2c
	re2c -o $(srcdir)/fem/Element.c++ $(srcdir)/fem/Element.c++.re2c
endif

