# CMake generated Testfile for 
# Source directory: C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML
# Build directory: C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(that-test-I-made "C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/build/Debug/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/CMakeLists.txt;128;add_test;C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(that-test-I-made "C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/build/Release/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/CMakeLists.txt;128;add_test;C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(that-test-I-made "C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/build/MinSizeRel/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/CMakeLists.txt;128;add_test;C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(that-test-I-made "C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/build/RelWithDebInfo/unitTests.exe")
  set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/CMakeLists.txt;128;add_test;C:/Users/Makarije/Desktop/TSP/JIN/Tmxlite_SampleSFML/CMakeLists.txt;0;")
else()
  add_test(that-test-I-made NOT_AVAILABLE)
endif()
subdirs("_deps/pugixml-build")
subdirs("_deps/box2d-build")
subdirs("_deps/sfml-build")
subdirs("tmxlite-build/tmxlite")
subdirs("mainLauncher")
subdirs("src")
subdirs("googletest-build")
