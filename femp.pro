TEMPLATE = app
QT -= gui

CONFIG += qt debug no_keywords
QMAKE_CXXFLAGS_DEBUG +=-O0 

QMAKE_EXT_CPP += c++

LIBS += -ll -ly -lboost_math_c99-mt

HEADERS += Document.h++ ProgramOptions.h++ \
	fem/Model.h++ fem/Node.h++ fem/Element.h++ fem/Material.h++ fem/LoadPattern.h++ fem/NodalLoad.h++ fem/NodalDisplacement.h++ fem/point.h++ fem/NodeRestrictions.h++ \
	fem/DomainLoad.h++ fem/SurfaceLoad.h++\
	fem_msh.h++ lex.msh_yy.h \
	parsers/parser.h++ parsers/msh.h++ parsers/json.h \
	fem/FemEquation.h++

SOURCES += main.c++ Document.c++ ProgramOptions.c++ \
	fem/Model.c++ fem/Node.c++ fem/Element.c++ fem/Material.c++ fem/LoadPattern.c++ fem/NodalLoad.c++ fem/NodalDisplacement.c++ fem/point.c++ fem/NodeRestrictions.c++ \
	fem/DomainLoad.c++ fem/SurfaceLoad.c++\
	fem_msh.c++ lex.msh_yy.c++ \
	parsers/parser.c++ parsers/msh.c++ parsers/json.c 

UI_DIR += ./ui
OBJECTS_DIR += ./build

MshParserRe2c.target = fem/msh.c++
MshParserRe2c.commands = re2c -o fem/msh.c++ fem/msh.c++.re2c
MshParserRe2c.depends = fem/msh.c++.re2c
MshParserRe2c.output = fem/msh.c++

ProgramOptionRe2c.target = ProgramOptions.c++
ProgramOptionRe2c.commands = re2c -o ProgramOptions.c++ ProgramOptions.c++.re2c
ProgramOptionRe2c.depends = ProgramOptions.c++.re2c
ProgramOptionRe2c.output = ProgramOptions.c++

ElementRe2c.target = fem/Element.c++
ElementRe2c.commands = re2c -o fem/Element.c++ fem/Element.c++.re2c
ElementRe2c.depends = fem/Element.c++.re2c
ElementRe2c.output = fem/Element.c++

FlexOutput.target = lex.msh_yy.h 
FlexOutput.commands = flex --header-file=lex.msh_yy.h -o lex.msh_yy.c++ msh.l
FlexOutput.depends = msh.l
FlexOutput.output = lex.msh_yy.c++ lex.msh_yy.h

BisonOutput.target = msh.tab.h
BisonOutput.commands = bison -d --debug msh.y
BisonOutput.depends = msh.y lex.msh_yy.h
BisonOutput.output = msh.tab.c msh.tab.h

BisonCompile.target = msh.tab.o
BisonCompile.commands = g++ -c msh.tab.c $(INCPATH)
BisonCompile.depends = msh.tab.h
BisonCompile.output = msh.tab.o

OBJECTS += msh.tab.o
QMAKE_CLEAN += lex.msh_yy.h lex.msh_yy.c++ msh.tab.c msh.tab.h msh.tab.o

QMAKE_EXTRA_TARGETS += MshParserRe2c ProgramOptionRe2c  ElementRe2c FlexOutput BisonOutput BisonCompile 
