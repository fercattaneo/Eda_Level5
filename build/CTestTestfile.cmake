# CMake generated Testfile for 
# Source directory: C:/Users/catta/Documents/EDA/Eda_Level5
# Build directory: C:/Users/catta/Documents/EDA/Eda_Level5/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(test1 "C:/Users/catta/Documents/EDA/Eda_Level5/build/Debug/main_test.exe")
  set_tests_properties(test1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/catta/Documents/EDA/Eda_Level5/CMakeLists.txt;26;add_test;C:/Users/catta/Documents/EDA/Eda_Level5/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(test1 "C:/Users/catta/Documents/EDA/Eda_Level5/build/Release/main_test.exe")
  set_tests_properties(test1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/catta/Documents/EDA/Eda_Level5/CMakeLists.txt;26;add_test;C:/Users/catta/Documents/EDA/Eda_Level5/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(test1 "C:/Users/catta/Documents/EDA/Eda_Level5/build/MinSizeRel/main_test.exe")
  set_tests_properties(test1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/catta/Documents/EDA/Eda_Level5/CMakeLists.txt;26;add_test;C:/Users/catta/Documents/EDA/Eda_Level5/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(test1 "C:/Users/catta/Documents/EDA/Eda_Level5/build/RelWithDebInfo/main_test.exe")
  set_tests_properties(test1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/catta/Documents/EDA/Eda_Level5/CMakeLists.txt;26;add_test;C:/Users/catta/Documents/EDA/Eda_Level5/CMakeLists.txt;0;")
else()
  add_test(test1 NOT_AVAILABLE)
endif()
