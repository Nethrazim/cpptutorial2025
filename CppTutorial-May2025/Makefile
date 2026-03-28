# Makefile for CppTutorial-May2025
# Compiles all source files into a single executable

# Compiler settings
CPP = cl
CPPFLAGS = /EHsc /nologo /W4 /std:c++20
PROGRAM = CppTutorial.exe

# List all object files (one for each .cpp file)
# Auto-generated from project scan - 36 files total
OBJECTS = add_two_numbers_from_linked_lists.obj \
		  arraysizeof.obj \
		  avl_tree.obj \
		  basic_sale_items_ops.obj \
		  binary_search_tree.obj \
		  cctype.obj \
		  char_replacement.obj \
		  compound_declaration.obj \
		  constructors.obj \
		  conversions.obj \
		  copy_by_value_vs_copy_by_reference.obj \
		  CppTutorial-May2025.obj \
		  cstring_hdr.obj \
		  ctype.obj \
		  declarations.obj \
		  decl_arrays.obj \
		  double_pointer.obj \
		  for_ex.obj \
		  linked_list.obj \
		  merge_ranges.obj \
		  multi_dim.obj \
		  pascal_triangle.obj \
		  passing_arrays_to_functions.obj \
		  plus_one.obj \
		  pointer_traversal.obj \
		  prefix_sum.obj \
		  Sales_data.obj \
		  same_tree.obj \
		  sample_loader.obj \
		  simple_thread.obj \
		  simple_tree.obj \
		  single_producer_single_consumer.obj \
		  sq.obj \
		  test_some1.obj \
		  value_switch.obj \
		  variables.obj \
		  vector_grades.obj

# Force all targets to always rebuild (ignore timestamps)
.PHONY: all clean clobber rebuild help

# Default target: clean and rebuild everything (ignores timestamps)
all: 
	@echo.
	@echo ========================================
	@echo  Building CppTutorial (Always Rebuild)
	@echo ========================================
	@echo.
	@if exist *.obj del /Q *.obj
	@$(MAKE) /NOLOGO $(PROGRAM)

# Link all object files into single executable
$(PROGRAM): $(OBJECTS)
	@echo.
	@echo Linking $(PROGRAM)...
	$(CPP) $(CPPFLAGS) /Fe$(PROGRAM) $(OBJECTS)
	@echo.
	@echo ========================================
	@echo  Build successful! Run: $(PROGRAM)
	@echo ========================================
	@echo.

# Compile .cpp to .obj (inference rule - no dependencies allowed in nmake!)
.cpp.obj:
	@echo Compiling $<...
	$(CPP) $(CPPFLAGS) /c $<

# Clean temporary files
clean:
	@if exist *.obj del *.obj
	@if exist *.pdb del *.pdb
	@if exist *.ilk del *.ilk
	@echo Cleaned object files

# Remove all build artifacts
clobber: clean
	@if exist $(PROGRAM) del $(PROGRAM)
	@echo Removed $(PROGRAM)

# Rebuild everything from scratch
rebuild: clobber all

# Help target
help:
	@echo Available targets:
	@echo   all      - Build the executable (default)
	@echo   clean    - Remove object files
	@echo   clobber  - Remove all build artifacts
	@echo   rebuild  - Clean and rebuild everything
	@echo   help     - Show this help message
	@echo.
	@echo Usage:
	@echo   nmake          - Build the program
	@echo   nmake clean    - Clean temporary files
	@echo   nmake rebuild  - Rebuild from scratch

.SUFFIXES: .cpp .obj
