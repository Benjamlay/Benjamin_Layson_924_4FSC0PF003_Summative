#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <unordered_map>

constexpr int texture_count = 35;
class TextureManager {

  std::unordered_map<int, sf::Texture> textures_;
  std::string folder_path_;

public:
  explicit TextureManager(const std::string_view& folder_path);
  void LoadTextures();
  sf::Texture& GetTexture(int idx);
  [[nodiscard]] size_t GetTextureCount() const;
};
#endif //TEXTURE_MANAGER_H
