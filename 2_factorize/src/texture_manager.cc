﻿#include "texture_manager.h"

#include <iostream>
TextureManager::TextureManager(const std::string_view& folder_path): folder_path_(folder_path) {
}

void TextureManager::LoadTextures() {
  if (!std::filesystem::exists(folder_path_)) {
    throw std::runtime_error("Folder does not exist");
  }

  for (int i = 0; i <= texture_count; i++) {
    sf::Texture texture;
    if (!texture.loadFromFile(folder_path_ + std::format("splat{:02d}.png", i))) {
      throw std::runtime_error("Could not load texture");
    }

    textures_.emplace(i, std::move(texture));
  }

  std::cout << textures_.size() << std::endl;
  //std::cout << folder_path_ << std::endl;
}
sf::Texture &TextureManager::GetTexture(int idx) { return textures_[idx]; }
size_t TextureManager::GetTextureCount() const {
  return folder_path_.size();
}