#include "../header/TextureHolder.h"

TextureHolder::TextureHolder() {
    
}

TextureHolder::~TextureHolder() {
    for (auto& pair : mTextureMap) {
        UnloadTexture(*pair.second);
    }
    mTextureMap.clear();
}

TextureHolder& TextureHolder::getHolder() {
    static TextureHolder gTextureHolder;
    return gTextureHolder;
}

void TextureHolder::load(Textures::ID id, const std::string& filename) {
    std::unique_ptr<Texture2D> texture(new Texture2D());
    *texture = LoadTexture(filename.c_str());
    mTextureMap.insert({id, std::move(texture)});
}

Texture2D& TextureHolder::get(Textures::ID id) {
    auto found = mTextureMap.find(id);
    if (found == mTextureMap.end()) {
        throw std::runtime_error("TextureHolder::get - Texture not found");
    }
    return *found->second;
}

const Texture2D& TextureHolder::get(Textures::ID id) const {
    auto found = mTextureMap.find(id);
    if (found == mTextureMap.end()) {
        throw std::runtime_error("TextureHolder::get - Texture not found");
    }
    return *found->second;
}