#pragma once
#include "raylib.h"
#include <map>
#include <string>
#include <memory>
#include <stdexcept>

namespace Textures
{
    enum ID {
        PAVEMENT = 0,
        ROAD,
        REDCAR_LEFT,
        REDCAR_RIGHT,
        BLUECAR_LEFT,
        BLUECAR_RIGHT,
        AMBULANCE_LEFT,
        AMBULANCE_RIGHT,
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
        GAMERIGHT
    };
} // namespace Textures

class TextureHolder {
private:
    static TextureHolder gTextureHolder;
    std::map<Textures::ID, std::unique_ptr<Texture2D>> mTextureMap;    
    TextureHolder();
    TextureHolder(const TextureHolder&) = delete;
    TextureHolder& operator=(const TextureHolder&) = delete;
public:
    static TextureHolder& getHolder();
    ~TextureHolder();
    void load(Textures::ID id, const std::string& filename);
    Texture2D& get(Textures::ID id);
    const Texture2D& get(Textures::ID id) const;
};
