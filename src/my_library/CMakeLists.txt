## inspired by https://rix0r.nl/blog/2015/08/13/cmake-guide/

# Define library. 
project(liblib VERSION 0.1 LANGUAGES CXX)

# Add the library
add_library(my_library
    src/my_library_component_impl.cpp)

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
target_include_directories(my_library PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

# Example Compiler Requirements
target_compile_features(my_library
    PUBLIC cxx_auto_type
    PRIVATE cxx_variadic_templates)

# Depend on a library that we defined in the top-level file
# target_link_libraries(my_library)

# 'make install' to the correct locations (provided by GNUInstallDirs).
install(TARGETS my_library EXPORT my_library_config
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'.
install(EXPORT my_library_config DESTINATION share/my_library/cmake)

# This makes the project importable from the build directory
export(TARGETS my_library FILE my_library_config.cmake)

# Every library has unit tests, of course
set(LIBRARY_TEST_NAME testlib)
add_executable(${LIBRARY_TEST_NAME}
    test/testlib.cpp)

# Link libraries
if(NOT WIN32 OR MINGW)
    target_link_libraries(${LIBRARY_TEST_NAME}
        ${GTEST_LIBS_DIR}/libgtest.a
        ${GTEST_LIBS_DIR}/libgtest_main.a
        )
else()
    target_link_libraries(${LIBRARY_TEST_NAME}
        debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        )
    target_link_libraries(${LIBRARY_TEST_NAME}
        debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
        )
endif()

# link our library to our tests
target_link_libraries(testlib
    my_library)

# finally add the tests
add_test(testlib testlib)