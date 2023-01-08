#pragma once
#include "raylib.h"
#include <map>
#include <string>
#include <memory>
#include <stdexcept>

namespace Textures
{
    enum ID
    {
        // Type of lane
        PAVEMENT = 0,
        ROAD,

        //Button in game menu
        RESTART_BTN,
        PAUSE_BTN,
        MUSIC_BTN,
        RESUME_BTN,
        HOME_BTN,
        NEXT_BTN,

        // Texture in game menu
        BLUR_BG,
        HOME_BG,

        // Texture in instruction menu
        INS_BG_1,
        INS_BG_2,

        // Texture in ranking menu
        RANK_BG,
        RANK_IMG,

        // State in game menu
        PAUSE_MENU,
        VICTORY_MENU,
        LOSE_MENU,

        // Frames of character
        // FRONT
        CHAR_FRONT_1,
        CHAR_FRONT_2,
        CHAR_FRONT_3,
        CHAR_FRONT_4,

        // BACK
        CHAR_BACK_1,
        CHAR_BACK_2,
        CHAR_BACK_3,
        CHAR_BACK_4,

        // LEFT
        CHAR_LEFT_1,
        CHAR_LEFT_2,
        CHAR_LEFT_3,
        CHAR_LEFT_4,

        // RIGHT
        CHAR_RIGHT_1,
        CHAR_RIGHT_2,
        CHAR_RIGHT_3,
        CHAR_RIGHT_4,

        // Traffic light
        RED_LIGHT,
        YELLOW_LIGHT,
        GREEN_LIGHT,

        GAMERIGHT,          // Detail board in game menu

        // Frames of obstacles
        // YELLOW CAR
        YCAR_FRAME_1,
        YCAR_FRAME_2,
        YCAR_FRAME_3,
        YCAR_FRAME_4,
        YCAR_FRAME_5,
        YCAR_FRAME_6,
        YCAR_FRAME_7,
        YCAR_FRAME_8,
        YCAR_FRAME_9,

        // BUS
        BUS_FRAME_1,
        BUS_FRAME_2,
        BUS_FRAME_3,
        BUS_FRAME_4,
        BUS_FRAME_5,
        BUS_FRAME_6,
        BUS_FRAME_7,
        BUS_FRAME_8,
        BUS_FRAME_9,
        BUS_FRAME_10,
        BUS_FRAME_11,
        BUS_FRAME_12,
        BUS_FRAME_13,

        // PURPLE CAR
        PCAR_FRAME_1,
        PCAR_FRAME_2,
        PCAR_FRAME_3,
        PCAR_FRAME_4,
        PCAR_FRAME_5,
        PCAR_FRAME_6,
        PCAR_FRAME_7,
        PCAR_FRAME_8,
        PCAR_FRAME_9,

        // POLICE CAR
        POLICE_1,
        POLICE_2,
        POLICE_3,
        POLICE_4,
        POLICE_5,
        POLICE_6,
        POLICE_7,
        POLICE_8,
        POLICE_9,

        // Texture in login menu
        LOGIN_BG,
        PLAYER_BOX_1,
        PLAYER_BOX_2,
        INPUT_BTN_1,
        INPUT_BTN_2,
        OK_BTN_1,
        OK_BTN_2,
        LOAD_MENU,
        LOAD_BAR,
        LOAD_ELE
    };
}

class TextureHolder        // Singleton pattern
{
private:
    static TextureHolder gTextureHolder;
    std::map<Textures::ID, std::unique_ptr<Texture2D>> mTextureMap;
    TextureHolder();
    TextureHolder(const TextureHolder &) = delete;
    TextureHolder &operator=(const TextureHolder &) = delete;

public:
    static TextureHolder &getHolder();      
    ~TextureHolder();
    void load(Textures::ID id, const std::string &filename);
    Texture2D &get(Textures::ID id);
    const Texture2D &get(Textures::ID id) const;
};
