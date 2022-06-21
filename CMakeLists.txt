cmake_minimum_required(VERSION 3.23)
project(RsaDemo)

set(NUMERIC_DIR_LIB,      /home/kamil2/Projects/Studia/C++/Numeric/build/numeric/libnumeric.a)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

file(GLOB RSA_DEMO_SOURCES "./*.cpp")
file(GLOB RSA_DEMO_UTILITIES "./Utility/*.cpp")
file(GLOB RSA_DEMO_SERVICES "./Services/*.cpp")
file(GLOB RSA_DEMO_TASKS "./Tasks/*.cpp")


add_executable(RsaDemo ${RSA_DEMO_SOURCES} ${RSA_DEMO_UTILITIES} ${RSA_DEMO_SERVICES} ${RSA_DEMO_TASKS})

target_link_libraries(RsaDemo /home/kamil/Projects/Studia/RsaDemo/lib/libnumeric.a)

target_include_directories(RsaDemo PRIVATE ./include)
target_include_directories(RsaDemo PRIVATE ./)
target_include_directories(RsaDemo PRIVATE ./*)
