#include "SoundManager.h"
#include "SDL/SDL_mixer.h"
#include <string>
#include <algorithm>

//Initialize our static variables
SoundManager* SoundManager::instance = 0;
AudioState SoundManager::currentState = AudioState::ERROR;

void SoundManager::playMusic(const std::string& filePath)
{
    if (currentState != AudioState::ERROR)
    {
        // If no music is playing, play it
        if (Mix_PlayingMusic() == 0)
        {
            // Load music
            Mix_Music* music = Mix_LoadMUS(filePath.c_str());
            std::cout << music;
            if (music == NULL)
            {
                std::cerr << "Error loading music file: " << filePath << std::endl;
            }
            else
            {
                //Play music
                std::cout << "Playing: " << filePath << std::endl;
                Mix_PlayMusic(music, -1);
                currentState = AudioState::PLAYING;
            }
        }
        else
        {
            // If music is playing, pause it
            this->pauseMusic();
        }
    }
}

void SoundManager::pauseMusic()
{
    if (currentState != AudioState::ERROR)
    {
        // If music is playing, handle the pause request
        if (Mix_PlayingMusic() == 1)
        {
            if (Mix_PausedMusic() == 1)
            {
                // If we receive a pause request and the music is already paused, resume it
                Mix_ResumeMusic();
                currentState = AudioState::PLAYING;
            }
            else
            {
                // Otherwise, pause the music
                Mix_PauseMusic();
                currentState = AudioState::PAUSED;
            }
        }
    }
}

void SoundManager::stopMusic()
{
    if (currentState != AudioState::ERROR)
    {
        Mix_HaltMusic();
        currentState = AudioState::STOPPED;
    }
}

void SoundManager::playFX(const std::string& filePath) const
{
    if (currentState != AudioState::ERROR)
    {
        Mix_Chunk* fx = Mix_LoadWAV(filePath.c_str());
        std::cout << fx;
        if (fx == NULL)
        {
            std::cerr << "Error loading music file: " << filePath << std::endl;
        }
        else
        {
            Mix_PlayChannel(-1, fx, 0);
        }
    }
}