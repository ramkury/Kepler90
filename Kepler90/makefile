CXX=g++
CXXFLAGS=#-o3

ODIR=obj

LIBS= -lGL -lGLU -lglut -lm

DEPS= Camera.h Planet.h Star.h Structs.h Timer.h
#DEPS= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ= Source.o Camera.o Planet.o Star.o Timer.o
OBJ= $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(LIBS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*