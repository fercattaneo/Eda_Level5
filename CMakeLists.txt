cmake_minimum_required(VERSION 3.0)

project("EDA Level 5")

set (CMAKE_CXX_STANDARD 11)

# From "Working with CMake" documentation:
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # AddressSanitizer (ASan)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif()
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # UndefinedBehaviorSanitizer (UBSan)
    add_compile_options(-fsanitize=undefined)
    add_link_options(-fsanitize=undefined)
endif()

add_executable(main main.cpp)



enable_testing()


#add_executable(player_test player_test.cpp MQTTClient.cpp Player.cpp Robot.cpp GameModel.cpp GameView.cpp)

#add_test(NAME test1 COMMAND player_test)
