# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11

# Vcpkg paths
VCPKG_ROOT = /opt/vcpkg
INCLUDE_DIRS = -I$(VCPKG_ROOT)/installed/x64-linux/include
PYTHON_INCLUDE_DIRS = -I/usr/include/python3.8/
INCLUDE_DIRS = -I$(VCPKG_ROOT)/installed/x64-linux/include -I/usr/include/python3.8
LIB_DIRS = -L$(VCPKG_ROOT)/installed/x64-linux/lib
LDLIBS = -lpython3.8 

# Directories
SRCDIR = .
OBJDIR = obj
BINDIR = bin

# Source files
SRCS = graph.cpp
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

# Executable name
EXEC = graph

# Targets
all: $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIB_DIRS) $(LDLIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $(PYTHON_INCLUDE_DIRS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean