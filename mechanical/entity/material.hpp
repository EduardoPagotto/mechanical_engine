#pragma once
#include "mechanical/core/types_base.hpp"
#include "mechanical/core/uniform_value.hpp"

namespace me {

struct Material {
    TagInfo tag;
    MapUniform vMaterial; // listMaterial;

    // inline void add(const std::string& matName, const glm::vec3& val) { vMaterial[matName] = Uniform(val); }
    // inline void bindMaterialInformation(MapUniform& uniforms) { uniforms.insert(vMaterial.begin(), vMaterial.end());
    // }

    // public:
    //  Material();
    //  virtual ~Material();
    //  void init();
    //  void setDefaultEffect();
    //  void addTexture(const std::string& uniformTexName, std::shared_ptr<Texture> texture) {
    //      this->mapTex[uniformTexName] = texture;
    //  }
    //  inline void setAmbient(const glm::vec4& _color) { listMaterial[SHADE_MAT_AMBIENTE] = UValue(_color); }
    //  inline void setSpecular(const glm::vec4& _color) { listMaterial[SHADE_MAT_SPECULA] = UValue(_color); }
    //  inline void setDiffuse(const glm::vec4& _color) { listMaterial[SHADE_MAT_DIFFUSE] = UValue(_color); }
    //  inline void setEmission(const glm::vec4& _color) { listMaterial[SHADE_MAT_EMISSIVE] = UValue(_color); }
    //  inline void setShine(const float& _val) { listMaterial[SHADE_MAT_SHININESS] = UValue(_val); }

    // bool hasTexture() { return !mapTex.empty(); }
    // void bindMaterialInformation(MapUniform& uniforms, std::vector<std::shared_ptr<Texture>>& vTex);
    // bool const isValid() const { return valid; }
};

// struct MaterialComponent {
//     TagComponent tag;
//     Material* material = new Material();
//     MaterialComponent() = default;
// };

} // namespace me
