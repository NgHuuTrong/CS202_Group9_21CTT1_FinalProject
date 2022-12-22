#pragma once
#include "raylib.h"
#include <map>
#include <string>
#include <memory>

namespace Textures
{
    enum ID {
        PAVEMENT,
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
