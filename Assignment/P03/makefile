# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -I/opt/homebrew/include -std=c++17

# Linker Flags
LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Source Files and Output
SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OUTPUT = Knucklebones

# Default Target
all: $(OUTPUT)

# Build the Executable
$(OUTPUT): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT) $(LDFLAGS)

# Clean Up Build Files
clean:
	rm -f $(OUTPUT)