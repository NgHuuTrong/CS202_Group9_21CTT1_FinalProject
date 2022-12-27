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
        PAVEMENT = 0,
        ROAD,
        RESTART_BTN,
        PAUSE_BTN,
        MUSIC_BTN,
        RESUME_BTN,
        HOME_BTN,
        NEXT_BTN,
        BLUR_BG,
        HOME_BG,
        INS_BG_1,
        INS_BG_2,
        RANK_BG,
        RANK_IMG,
        PAUSE_MENU,
        VICTORY_MENU,
        CHAR_FRONT_1,
        CHAR_FRONT_2,
        CHAR_FRONT_3,
        CHAR_FRONT_4,
        CHAR_BACK_1,
        CHAR_BACK_2,
        CHAR_BACK_3,
        CHAR_BACK_4,
        CHAR_LEFT_1,
        CHAR_LEFT_2,
        CHAR_LEFT_3,
        CHAR_LEFT_4,
        CHAR_RIGHT_1,
        CHAR_RIGHT_2,
        CHAR_RIGHT_3,
        CHAR_RIGHT_4,
        RED_LIGHT,
        YELLOW_LIGHT,
        GREEN_LIGHT,
        GAMERIGHT,
        YCAR_FRAME_1,
        YCAR_FRAME_2,
        YCAR_FRAME_3,
        YCAR_FRAME_4,
        YCAR_FRAME_5,
        YCAR_FRAME_6,
        YCAR_FRAME_7,
        YCAR_FRAME_8,
        YCAR_FRAME_9,
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
        PCAR_FRAME_1,
        PCAR_FRAME_2,
        PCAR_FRAME_3,
        PCAR_FRAME_4,
        PCAR_FRAME_5,
        PCAR_FRAME_6,
        PCAR_FRAME_7,
        PCAR_FRAME_8,
        PCAR_FRAME_9,
        POLICE_1,
        POLICE_2,
        POLICE_3,
        POLICE_4,
        POLICE_5,
        POLICE_6,
        POLICE_7,
        POLICE_8,
        POLICE_9,
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
} // namespace Textures

class TextureHolder
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
