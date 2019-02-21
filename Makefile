all: src/main.cpp 
	g++ -std=c++11 -g -Wall -o escape_room_radio src/main.cpp src/player.cpp src/rocker.cpp src/slider.cpp src/gps_interface.cpp
	g++ -std=c++11 -g -Wall -o test_suite src/tests/tests.cpp src/player.cpp src/rocker.cpp src/slider.cpp src/gps_interface.cpp
clean: 
	$(RM) escape_room_radio
