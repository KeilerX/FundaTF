#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include <iostream>

class SoundManager
{
private:
    static SoundManager* instance;

    enum AudioState
    {
        ERROR = 0,
        WAITING,
        PAUSED,
        STOPPED,
        PLAYING
    };
    static AudioState currentState;

    static void initAudioDevice()
    {
        if (SDL_Init(SDL_INIT_AUDIO) != -1)
        {
            if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
            {
                std::cerr << "Error initializing audio device...\n";
                currentState = ERROR;
            }
            else
            {
                currentState = WAITING;
            }
        }
        else
        {
            std::cerr << "Error initializing SDL audio subsystem...\n";
            currentState = ERROR;
        }
    }

    // All of these are private due to the Singleton pattern

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
            std::cout << "Instance";
            instance = new SoundManager;
            SoundManager::initAudioDevice();
        }
        return instance;
    }

    void playMusic(const std::string& fileName);
    void pauseMusic();
    void stopMusic();
    void playFX(const std::string& fileName) const;

    inline bool isPaused() const
    {
        return currentState == PAUSED;
    }

    inline bool isStopped() const
    {
        return currentState == STOPPED;
    }

    inline bool isPlaying() const
    {
        return currentState == PLAYING;
    }

    inline bool inErrorState() const
    {
        return currentState == ERROR;
    }
};
