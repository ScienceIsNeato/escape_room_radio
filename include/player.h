class Player
{
private:
    /* data */
    const std::string CORRECT_PATH = "audio_files/correct.wav";
    const std::string INCORRECT_PATH = "audio_files/incorrect.wav";

public:
    Player(/* args */);
    ~Player();

    void play_audio(bool correct);
};
