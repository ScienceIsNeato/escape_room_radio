#include <string>
#include <iostream>
#include "../include/player.h"

using namespace std;

Player::Player(/* args */)
{
}

Player::~Player()
{
}

void Player::play_audio(bool correct)
{
    std::string audio_file;
    audio_file = correct ? CORRECT_PATH : INCORRECT_PATH; 
    audio_file = "ffplay -nodisp -autoexit " + audio_file;
    const char *command = audio_file.c_str(); 
    std::cout << "About to call`" << *command << "`" << std::endl;
    system(command);
}
