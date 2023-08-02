COMPILE   = g++
FLAGS     = -lm -std=c++17
FILENAMES = main

BUILDPATH = ./build/
OUTPUT    = lazyTree

all: $(BUILDPATH)
	$(COMPILE) $(foreach file, $(FILENAMES), $(file).cpp) $(FLAGS) -o $(BUILDPATH)$(OUTPUT)
	$(BUILDPATH)$(OUTPUT)

$(BUILDPATH):
	mkdir $(BUILDPATH)
