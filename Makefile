all: src/main.cpp 
	g++ -std=c++11 -std=c++0x -pthread -g -Wall -o escape_room_radio src/main.cpp src/player.cpp src/rocker.cpp src/slider.cpp src/gps_interface.cpp src/trigger.cpp
	g++ -std=c++11 -std=c++0x -pthread -g -Wall -o test_suite src/tests/tests.cpp src/player.cpp src/rocker.cpp src/slider.cpp src/gps_interface.cpp src/trigger.cpp
clean: 
	$(RM) escape_room_radio
