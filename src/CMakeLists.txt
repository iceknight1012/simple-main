# Main program source files and executables



##
## Add a simple executable
###

# Set the name and the source files for the executable
set(EXEC_NAME p2)
add_executable(${EXEC_NAME} problem2.cpp)
# These compile options make the compiler add extra warnings and treat warnings as errors
target_compile_options(${EXEC_NAME} PRIVATE "-Wall")
target_compile_options(${EXEC_NAME} PRIVATE "-Wextra")
target_compile_options(${EXEC_NAME} PRIVATE "-Werror")
target_compile_options(${EXEC_NAME} PRIVATE "-pedantic")

## End Executable

##
## Add an Executable with multiple sources and compile options
##

# Set the name and the source files for the executable
set(EXEC_NAME p5)
add_executable(${EXEC_NAME} problem5.cpp treasure.cpp treasure.h)

# These compile options make the compiler add extra warnings and treat warnings as errors
target_compile_options(${EXEC_NAME} PRIVATE "-Wall")
target_compile_options(${EXEC_NAME} PRIVATE "-Wextra")
target_compile_options(${EXEC_NAME} PRIVATE "-Werror")
target_compile_options(${EXEC_NAME} PRIVATE "-pedantic")

# These options turn off specific warnings, because the instructor's have requirements that
# require using variable length arrays (vla) and unused parameters. YOu should generally not
# have these in a project, unless they are absolutely necessary
target_compile_options(${EXEC_NAME} PRIVATE "-Wno-vla") # Disable variable length array warning, int foobar[SIZE]
target_compile_options(${EXEC_NAME} PRIVATE "-Wno-unused-parameter") # The instructors required a func def with unused params.


## End executable

