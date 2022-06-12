include_directories(./)
file(GLOB RSA_DEMO_SOURCES  "./*.cpp")
add_library(Tester ${RSA_DEMO_SOURCES})
