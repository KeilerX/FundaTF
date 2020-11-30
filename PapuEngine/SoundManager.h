#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>

enum class AudioState
{
    ERROR = 0,
    WAITING,
    PAUSED,
    STOPPED,
    PLAYING
};

class SoundManager
{
private:
    static SoundManager* instance;
    static AudioState currentState;

    static void initAudioDevice()
    {
        if (SDL_Init(SDL_INIT_AUDIO) != -1)
        {
            if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
            {
                std::cerr << "Error initializing audio device...\n";
                currentState = AudioState::ERROR;
            }
            else
            {
                currentState = AudioState::WAITING;
            }
        }
        else
        {
            std::cerr << "Error initializing SDL audio subsystem...\n";
            currentState = AudioState::ERROR;
        }
    }

     //All of these are private due to the Singleton pattern
    SoundManager()
    {
    }

    SoundManager(const SoundManager&)
    {
    }

    SoundManager& operator=(const SoundManager&)
    {
    }
    
    ~SoundManager()
    {
        Mix_CloseAudio();
    }
public:
    friend class MainGame;
    static SoundManager* getInstance()
    {
        if (instance == 0)
        {
            instance = new SoundManager;
            SoundManager::initAudioDevice();
        }
        return instance;
    }

    void playMusic(const std::string& filePath);
    void pauseMusic();
    void stopMusic();
    void playFX(const std::string& filePath) const;

    inline bool isPaused() const
    {
        return currentState == AudioState::PAUSED;
    }
    
    inline bool isStopped() const
    {
        return currentState == AudioState::STOPPED;
    }
    
    inline bool isPlaying() const
    {
        return currentState == AudioState::PLAYING;
    }
    
    inline bool inErrorState() const
    {
        return currentState == AudioState::ERROR;
    }
};
