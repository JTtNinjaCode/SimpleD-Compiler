LEX     = lex
YACC    = yacc
CC      = gcc

SRC_DIR = src
BUILD_DIR = build
EXAMPLE_DIR = example_code
OUTPUT_DIR = example_output

LEX_SRC  = $(SRC_DIR)/lexer.l
YACC_SRC = $(SRC_DIR)/parser.y

TARGET  = parser

# List all your C source files and header here
CFILES = $(SRC_DIR)/sym_table.c
HFILES = $(SRC_DIR)/sym_table.h

LEX_C    = $(BUILD_DIR)/lex.yy.c
YACC_C   = $(BUILD_DIR)/y.tab.c
YACC_H   = $(BUILD_DIR)/y.tab.h
Y_OUTPUT = $(BUILD_DIR)/y.output

# Convert all C files to object files in the build directory
OBJS = $(CFILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
LEX_O = $(BUILD_DIR)/lex.yy.o
YACC_O = $(BUILD_DIR)/y.tab.o

# Get all .sd file in example_code directoryEXAMPLES
EXAMPLES = $(wildcard $(EXAMPLE_DIR)/*.sd)

all: $(TARGET)

# Ensure the build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link the object files into the final executable
$(TARGET): $(OBJS) $(LEX_O) $(YACC_O)
	$(CC) -o $(BUILD_DIR)/$@ $^ -ll

# Generate lex.yy.c from lexer.l
$(LEX_C): $(LEX_SRC) $(BUILD_DIR)
	$(LEX) -o $@ $<

# Generate y.tab.c and y.tab.h from parser.y
$(YACC_C) $(YACC_H): $(YACC_SRC) $(BUILD_DIR)
	$(YACC) -Wconflicts-sr -Wconflicts-rr -v -d -o $(YACC_C) $<

# Compile all C source files into object files in the build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HFILES) $(BUILD_DIR)
	$(CC) -o $@ -c $< -I$(SRC_DIR)

# Compile lex.yy.o from lex.yy.c
$(BUILD_DIR)/lex.yy.o: $(LEX_C) $(YACC_H)
	$(CC) -o $@ -c $(LEX_C) -I$(SRC_DIR)

# Compile y.tab.o from y.tab.c
$(BUILD_DIR)/y.tab.o: $(YACC_C)
	$(CC) -o $@ -c $(YACC_C) -I$(SRC_DIR)

# Check for conflicts in the yacc output
conflict_check: $(BUILD_DIR)/y.output
	@echo "=== Conflicts in $(BUILD_DIR)/y.output: ==="
	@grep 'conflict' $(BUILD_DIR)/y.output || echo "No conflicts found."

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(OUTPUT_DIR)

# Compile all sd program in example_code directory and output to example_output directory
run: $(TARGET) $(EXAMPLES)
	@mkdir -p $(OUTPUT_DIR)
	@for file in $(EXAMPLES); do \
		$(BUILD_DIR)/$(TARGET) < $$file > $(OUTPUT_DIR)/$$(basename $$file).out; \
	done