CCXX =g++
CXXFLAGS = -g
LDLIBS =-lallegro.h -lallegro_image -lallegro_dialog

DEPS=allegro.h personaje.h
OBJ=allegro.o personaje.o base.o

base: $(OBJ)
	$(CXX) %(CXXFLAGS) -o $@ $^$(LDLIBS)

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean
	clean:
	$(RM) *.o *~
