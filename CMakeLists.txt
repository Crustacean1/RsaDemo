cmake_minimum_required(VERSION 3.23)
project(RsaDemo)

set(NUMERIC_DIR_LIB,      /home/kamil/Projects/Studia/Numeric/build/numeric/libnumeric.a)


file(GLOB RSA_DEMO_SOURCES "./*.cpp")
file(GLOB RSA_DEMO_DEPS "./*/*.cpp")


add_executable(RsaDemo ${RSA_DEMO_SOURCES} ${RSA_DEMO_DEPS})
target_link_libraries(RsaDemo /home/kamil/Projects/Studia/Numeric/build/numeric/libnumeric.a)
target_include_directories(RsaDemo PRIVATE /home/kamil/Projects/Studia/Numeric/numeric)
target_include_directories(RsaDemo PRIVATE ./)
target_include_directories(RsaDemo PRIVATE ./*)
