SUFFIXES+=.mk


ifeq ($(OS),Windows_NT)
	GPP:=g++
else
	GPP:=g++-5
endif


ifeq ($(RELEASE),YES)
	OPTIMIZATION:=-O2
else
	OPTIMIZATION:=-O0 -g -fno-inline -fno-omit-frame-pointer -Wall -Wpedantic -Wextra -Werror
	ifneq ($(OS),Windows_NT)
		OPTIMIZATION:=$(OPTIMIZATION) -fsanitize=address
	endif
endif


OPTS_SHARED:=-I ./include -std=c++1z
ifeq ($(OS),Windows_NT)
	OPTS_SHARED:=$(OPTS_SHARED) -L "../MCPP2016/bin" -I "C:/Users/rleahy/Downloads/zlib128/zlib-1.2.8"
endif


ifeq ($(OS),Windows_NT)
	MAKE_PARENT=mkdir.bat $(subst /,\,$(dir $(1)))
	RMDIR=rmdir.bat $(subst /,\,$(1))
	MKDIR=mkdir.bat $(subst /,\,$(1))
	MODULE_EXT:=.dll
	EXECUTABLE_EXT:=.exe
else
	MAKE_PARENT=mkdir -p $(dir $(1))
	RMDIR=rm -r -f $(1)
	MKDIR=mkdir $(1)
	OPTS_SHARED:=$(OPTS_SHARED) -fPIC
	MODULE_EXT:=.so
	EXECUTABLE_EXT:=
endif


GPP:=$(GPP) $(OPTS_SHARED) $(OPTIMIZATION)


.PHONY: all
all:


.PHONY: clean
clean:
	-@$(call RMDIR,obj)
	-@$(call RMDIR,bin)
	-@$(call RMDIR,makefiles)


bin:
	-@$(call MKDIR,bin)

bin/modules: | bin
	-@$(call MKDIR,bin/modules)
	
	
NODEPS:=clean cleanall cleandeps
	
	
ifeq (0,$(words $(findstring $(MAKECMDGOALS),$(NODEPS))))

	ifeq ($(OS),Windows_NT)
		-include $(subst .cpp,.mk,$(subst src,makefiles,$(subst \,/,$(subst $(shell echo %CD%)\,,$(shell dir /b /s src\*.cpp)))))
	else
		-include $(patsubst src/%.cpp,makefiles/%.mk,$(shell find src/ -name "*.cpp"))
	endif

endif
	
	
obj/%.o:
	-@$(call MAKE_PARENT,$(patsubst obj/%.o,makefiles/%.mk,$@))
	$(GPP) -MM -MT "$@" $(patsubst obj/%.o,src/%.cpp,$@) -MF $(patsubst obj/%.o,makefiles/%.mk,$@)
	-@$(call MAKE_PARENT,$@)
	$(GPP) -c -o $@ $(patsubst obj/%.o,src/%.cpp,$@)

	
OBJS:=\
obj/endian_str.o \
obj/io/izlibstream.o \
obj/io/ozlibstream.o \
obj/io/stream_reader.o \
obj/io/stream_writer.o \
obj/tag.o \
obj/tag_array.o \
obj/tag_compound.o \
obj/tag_list.o \
obj/tag_string.o \
obj/text/json_formatter.o \
obj/value.o \
obj/value_initializer.o


all: bin/libnbt++$(MODULE_EXT)
bin/libnbt++$(MODULE_EXT): \
$(OBJS) | \
bin
	$(GPP) -shared -o $@ $^ $(LINK) -lz
