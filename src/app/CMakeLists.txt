# Define executable
add_executable(app
    src/app.cpp)

# Link to our library
target_link_libraries(app
    my_library)