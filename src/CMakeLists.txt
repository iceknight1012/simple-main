# Main program source files and executables



##
## Add a simple executable
###

# Set the name and the source files for the executable
set(EXEC_NAME main)
add_executable(${EXEC_NAME} main.cpp)
# These compile options make the compiler add extra warnings and treat warnings as errors
target_compile_options(${EXEC_NAME} PRIVATE "-Wall")
target_compile_options(${EXEC_NAME} PRIVATE "-Wextra")
target_compile_options(${EXEC_NAME} PRIVATE "-Werror")
target_compile_options(${EXEC_NAME} PRIVATE "-pedantic")

## End Executable
