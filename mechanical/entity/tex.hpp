#pragma once
#include "mechanical/core/types_base.hpp"

namespace me {

enum class TexWrap { NONE = 0, REPEAT, CLAMP, MIRRORED, CLAMP_TO_EDGE, CLAMP_TO_BORDER };

enum class TexFilter { NONE = 0, LINEAR, NEAREST };

enum class TexDType { NONE, UNSIGNED_BYTE, UNSIGNED_SHORT, FLOAT, INT };

enum class TexFormat {
    NONE = 0,
    RGB,
    RGBA,
    LUMINANCE,
    LUMINANCE_ALPHA,
    DEPTH_COMPONENT,
    DEPTH_ATTACHMENT,
    // novos
    RGBA8,
    DEPTH24STENCIL8,
    RED_INTEGER,
    R32I
};

struct TexParam {
    TexParam() = default;
    TexParam(const TexParam& o) = default;
    TexParam(TexFormat format, TexFormat internalFormat, TexFilter minFilter, TexFilter magFilter, TexWrap wrap_r,
             TexWrap wrap_s, TexWrap wrap_t, TexDType type)
        : format(format), internalFormat(internalFormat), minFilter(minFilter), magFilter(magFilter), wrap_r(wrap_r),
          wrap_s(wrap_s), wrap_t(wrap_t), type(type), samples(1) {}

    TexFormat format{TexFormat::RGBA};
    TexFormat internalFormat{TexFormat::RGBA};
    TexFilter minFilter{TexFilter::NEAREST};
    TexFilter magFilter{TexFilter::NEAREST};
    TexWrap wrap_r{TexWrap::REPEAT};
    TexWrap wrap_s{TexWrap::REPEAT};
    TexWrap wrap_t{TexWrap::REPEAT};
    TexDType type{TexDType::UNSIGNED_BYTE};
    int samples{1};
};

// static void textParamSetUndefined(TexParam& val) {
//     val.format = TexFormat::NONE;
//     val.internalFormat = TexFormat::NONE;
//     val.minFilter = TexFilter::NONE;
//     val.magFilter = TexFilter::NONE;
//     val.wrap_r = TexWrap::NONE;
//     val.wrap_s = TexWrap::NONE;
//     val.wrap_t = TexWrap::NONE;
//     val.type = TexDType::NONE;
// }

// static bool texParamIsUndefined(const TexParam& val) {
//     return (val.format == TexFormat::NONE && val.internalFormat == TexFormat::NONE);
// }

struct Tex {
    TagInfo tag;
    uint32_t width, height;
    uint32_t idTexture;
    TexParam texParam;
};
} // namespace me
