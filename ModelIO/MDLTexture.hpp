/*!
 @header MDLTexture.hpp
 @framework ModelIO
 @abstract Representation of textures for use in rendering
 @copyright Treata Norouzi on 8/16/24.
 */


#pragma once

#import "Foundation/Foundation.hpp"
#include "ModelIOExports.hpp"
#include "MDLTypes.hpp"
#include "MDLObject.hpp"
#include "MDLAssetResolver.hpp"
#import <CoreGraphics/CoreGraphics.h>
#import <CoreGraphics/CGImage.h>
#import <simd/simd.h>

namespace MDL
{
_MDL_ENUM(NS::Integer, TextureChannelEncoding) {
    TextureChannelEncodingUInt8 = 1,
    TextureChannelEncodingUint8 = 1,
    TextureChannelEncodingUInt16 = 2,
    TextureChannelEncodingUint16 = 2,
    TextureChannelEncodingUInt24 = 3,
    TextureChannelEncodingUint24 = 3,
    TextureChannelEncodingUInt32 = 4,
    TextureChannelEncodingUint32 = 4,
    TextureChannelEncodingFloat16 = 0x102,
    TextureChannelEncodingFloat16SR = 0x302,
    TextureChannelEncodingFloat32 = 0x104,
};

                       // !!!: Uncertain
class Texture : public NS::Referencing<MDL::Named>
{
public:
    static class Texture*       alloc();
    
    class Texture*              init();
    
    // textureNamed:
    static class Texture*       textureNamed(const NS::String* name);
    
    // textureNamed:bundle:
    static class Texture*       textureNamed(const NS::String* name, const NS::Bundle* bundleOrNil);
    
    // textureNamed:assetResolver:
    static class Texture*       textureNamed(const NS::String* name, class AssetResolver* resolver);
    
    // textureCubeWithImagesNamed:
    static class Texture*       textureCubeWithImagesNamed(const NS::Array* names);
    
    // textureCubeWithImagesNamed:bundle:
    static class Texture*       textureCubeWithImagesNamed(const NS::Array* names,
                                                           const NS::Bundle* bundleOrNil);
    
    // irradianceTextureCubeWithTexture:name:dimensions:
    static class Texture*       irradianceTextureCubeWithTexture(const Texture* texture,
                                                                 const NS::String* name,
                                                                 vector_int2 dimensions);
    
    // irradianceTextureCubeWithTexture:name:dimensions:roughness:
    static class Texture*       irradianceTextureCubeWithTexture(const Texture* texture,
                                                                 const NS::String* name,
                                                                 vector_int2 dimensions,
                                                                 float roughness);
    
    
    // initWithData:topLeftOrigin:name:dimensions:rowStride:channelCount:channelEncoding:isCube:
    class Texture*              init(const NS::Data* pixelData,
                                     BOOL topLeftOrigin,
                                     const NS::String* name,
                                     vector_int2 dimensions,
                                     NS::UInteger rowStride,
                                     NS::UInteger channelCount,
                                     TextureChannelEncoding channelEncoding,
                                     BOOL isCube);
    
    // writeToURL:
    BOOL                        writeToURL(const NS::URL* URL);
   
    // writeToURL:level:
    BOOL                        writeToURL(const NS::URL* URL, NS::UInteger level);

    // writeToURL:type:
    BOOL                        writeToURL(const NS::URL* nsurl, CFStringRef type);

    // writeToURL:type:level:
    BOOL                        writeToURL(const NS::URL* nsurl, CFStringRef type, NS::UInteger level);
    
    CGImageRef                  imageFromTexture();
    
    // imageFromTextureAtLevel:
    CGImageRef                  imageFromTextureAtLevel(NS::UInteger level);
    
    NS::Data*                   texelDataWithTopLeftOrigin();
    
    NS::Data*                   texelDataWithBottomLeftOrigin();
    
    // texelDataWithTopLeftOriginAtMipLevel:create:
    NS::Data*                   texelDataWithTopLeftOriginAtMipLevel(NS::Integer level, BOOL create);
    
    // texelDataWithBottomLeftOriginAtMipLevel:create:
    NS::Data*                   texelDataWithBottomLeftOriginAtMipLevel(NS::Integer level, BOOL create);
    
    vector_int2                 dimensions() const;
    
    NS::Integer                 rowStride() const;
    
    NS::UInteger                channelCount() const;
    
    NS::UInteger                mipLevelCount() const;
    
    TextureChannelEncoding      channelEncoding() const;
    
    BOOL                        isCube() const;
    // !!!: Name
    void                        setAsCube(BOOL isCube);
    
    BOOL                        hasAlphaValues() const;
    void                        setAsAlphaValues(BOOL hasAlphaValues);
    
};

class URLTexture : public NS::Referencing<MDL::Texture>
{
public:
    static class URLTexture*        alloc();
    
    // initWithURL:name:
    class URLTexture*               init(const NS::URL* URL, const NS::String* name);
    
    // copy
    NS::URL*                        URL() const;
    void                            setURL(const NS::URL* URL);
};

class CheckerboardTexture : public NS::Referencing<MDL::Texture>
{
public:
    static class CheckerboardTexture*   alloc();
    
    // initWithDivisions:name:dimensions:channelCount:channelEncoding:color1:color2:
    class CheckerboardTexture*          init(float divisions,
                                             const NS::String* name,
                                             vector_int2 dimensions,
                                             int channelCount,
                                             TextureChannelEncoding channelEncoding,
                                             CGColorRef color1,
                                             CGColorRef color2);
    
    // assign
    float                               divisions() const;
    void                                setDivisions(float divisions);
    
    CGColorRef                          color1() const;
    void                                setColor1(CGColorRef color1);
    
    CGColorRef                          color2() const;
    void                                setColor2(CGColorRef color2);
};

class SkyCubeTexture : public NS::Referencing<MDL::Texture>
{
public:
    static class SkyCubeTexture*    alloc();
    
    // initWithName:channelEncoding:textureDimensions:turbidity:sunElevation:upperAtmosphereScattering:groundAlbedo:
    class SkyCubeTexture*           init(const NS::String* name,
                                         TextureChannelEncoding channelEncoding,
                                         vector_int2 textureDimensions,
                                         float turbidity,
                                         float sunElevation,
                                         float upperAtmosphereScattering,
                                         float groundAlbedo);
    
    // initWithName:channelEncoding:textureDimensions:turbidity:sunElevation:sunAzimuth:upperAtmosphereScattering:groundAlbedo:
    class SkyCubeTexture*           init(const NS::String* name,
                                         TextureChannelEncoding channelEncoding,
                                         vector_int2 textureDimensions,
                                         float turbidity,
                                         float sunElevation,
                                         float sunAzimuth,
                                         float upperAtmosphereScattering,
                                         float groundAlbedo);
    
    // updateTexture
    void                            updateTexture();
    
    // assing
    float                           turbidity() const;
    void                            setTurbidity(float turbidity);
    
    float                           sunElevation() const;
    void                            setSunElevation(float sunElevation);
    
    float                           sunAzimuth() const;
    void                            setSunAzimuth(float sunAzimuth);
    
    float                           upperAtmosphereScattering() const;
    void                            setUpperAtmosphereScattering(float upperAtmosphereScattering);
    
    float                           groundAlbedo() const;
    void                            setGroundAlbedo(float groundAlbedo);
    
    float                           horizonElevation() const;
    void                            setHorizonElevation(float horizonElevation);
    
    CGColorRef                      groundColor() const;
    void                            setGroundColor(CGColorRef groundColor);
    
    float                           gamma() const;
    void                            setGamma(float gamma);
    
    float                           exposure() const;
    void                            setExposure(float exposure);
    
    float                           brightness() const;
    void                            setBrightness(float brightness);
    
    float                           contrast() const;
    void                            setContrast(float contrast);
    
    float                           saturation() const;
    void                            setSaturation(float saturation);
    
    vector_float2                   highDynamicRangeCompression() const;
    void                            setHighDynamicRangeCompression(vector_float2 highDynamicRangeCompression);
};

class ColorSwatchTexture : public NS::Referencing<MDL::Texture>
{
public:
    static class ColorSwatchTexture*    alloc();
    
    // initWithColorTemperatureGradientFrom:toColorTemperature:name:textureDimensions:
    class ColorSwatchTexture*           initWithColorTemperatureGradientFrom(float colorTemperature1,
                                                                             float colorTemperature2,
                                                                             const NS::String* name,
                                                                             vector_int2 textureDimensions);
    
    // initWithColorGradientFrom:toColor:name:textureDimensions:
    class ColorSwatchTexture*           initWithColorGradientFrom(float color1,
                                                                  float color2,
                                                                  const NS::String* name,
                                                                  vector_int2 textureDimensions);
};

class NoiseTexture : public NS::Referencing<MDL::Texture>
{
public:
    static class NoiseTexture*  alloc();
    
    // initVectorNoiseWithSmoothness:name:textureDimensions:channelEncoding:
    class NoiseTexture*         initVectorNoiseWithSmoothness(float smoothness,
                                                              const NS::String* name,
                                                              vector_int2 textureDimensions,
                                                              TextureChannelEncoding channelEncoding);
    
    // initScalarNoiseWithSmoothness:name:textureDimensions:channelCount:channelEncoding:grayscale:
    class NoiseTexture*         initScalarNoiseWithSmoothness(float smoothness,
                                                              const NS::String* name,
                                                              vector_int2 textureDimensions,
                                                              int channelCount,
                                                              TextureChannelEncoding channelEncoding,
                                                              BOOL grayscale);
    
    // initCellularNoiseWithFrequency:name:textureDimensions:channelEncoding:
    class NoiseTexture*         initCellularNoiseWithFrequency(float frequency,
                                                              const NS::String* name,
                                                              vector_int2 textureDimensions,
                                                              TextureChannelEncoding channelEncoding);
};

class NormalMapTexture : public NS::Referencing<MDL::Texture>
{
public:
    static class NormalMapTexture*  alloc();
    
    // initByGeneratingNormalMapWithTexture:name:smoothness:contrast:
    class NormalMapTexture*         init(const Texture* sourceTexture,
                                         const NS::String* name,
                                         float smoothness,
                                         float contrast);
};

}

// MARK: - Private Sector 

// static method: alloc
_MDL_INLINE MDL::Texture* MDL::Texture::alloc()
{
    return NS::Object::alloc<MDL::Texture>(_MDL_PRIVATE_CLS(MDLTexture));
}

// method: init
_MDL_INLINE MDL::Texture* MDL::Texture::init()
{
    return NS::Object::init<MDL::Texture>();
}

// static method: textureNamed:
_MDL_INLINE MDL::Texture* MDL::Texture::textureNamed(const NS::String* name)
{
    return Object::sendMessage<MDL::Texture*>(_MDL_PRIVATE_CLS(MDLTexture), _MDL_PRIVATE_SEL(textureNamed_), name);
}

// static method: textureNamed:bundle:
_MDL_INLINE MDL::Texture* MDL::Texture::textureNamed(const NS::String* name, const NS::Bundle* bundleOrNil)
{
    return Object::sendMessage<MDL::Texture*>(_MDL_PRIVATE_CLS(MDLTexture), _MDL_PRIVATE_SEL(textureNamed_bundle_), name, bundleOrNil);
}

// static method: textureNamed:assetResolver:
_MDL_INLINE MDL::Texture* MDL::Texture::textureNamed(const NS::String* name, class AssetResolver* resolver)
{
    return Object::sendMessage<MDL::Texture*>(_MDL_PRIVATE_CLS(MDLTexture), _MDL_PRIVATE_SEL(textureNamed_assetResolver_), name, resolver);
}

// static method: textureCubeWithImagesNamed:
_MDL_INLINE MDL::Texture* MDL::Texture::textureCubeWithImagesNamed(const NS::Array* names)
{
    return Object::sendMessage<MDL::Texture*>(_MDL_PRIVATE_CLS(MDLTexture), _MDL_PRIVATE_SEL(textureCubeWithImagesNamed_), names);
}

// static method: textureCubeWithImagesNamed:bundle:
_MDL_INLINE MDL::Texture* MDL::Texture::textureCubeWithImagesNamed(const NS::Array* names,
                                                                   const NS::Bundle* bundleOrNil)
{
    return Object::sendMessage<MDL::Texture*>(_MDL_PRIVATE_CLS(MDLTexture), 
                                              _MDL_PRIVATE_SEL(textureCubeWithImagesNamed_bundle_),
                                              names, bundleOrNil);
}

// static method: irradianceTextureCubeWithTexture:name:dimensions:
_MDL_INLINE MDL::Texture* MDL::Texture::irradianceTextureCubeWithTexture(const Texture* texture,
                                                                         const NS::String* name,
                                                                         vector_int2 dimensions)
{
    return Object::sendMessage<MDL::Texture*>(_MDL_PRIVATE_CLS(MDLTexture),
                                              _MDL_PRIVATE_SEL(irradianceTextureCubeWithTexture_name_dimensions_),
                                              texture, name, dimensions);
}

// static method: irradianceTextureCubeWithTexture:name:dimensions:roughness:
_MDL_INLINE MDL::Texture* MDL::Texture::irradianceTextureCubeWithTexture(const Texture* texture,
                                                                         const NS::String* name,
                                                                         vector_int2 dimensions,
                                                                         float roughness)
{
    return Object::sendMessage<MDL::Texture*>(_MDL_PRIVATE_CLS(MDLTexture),
                                              _MDL_PRIVATE_SEL(irradianceTextureCubeWithTexture_name_dimensions_roughness_),
                                              texture, name, dimensions, roughness);
}

// method: initWithData:topLeftOrigin:name:dimensions:rowStride:channelCount:channelEncoding:isCube:
_MDL_INLINE MDL::Texture* MDL::Texture::init(const NS::Data* pixelData,
                                             BOOL topLeftOrigin,
                                             const NS::String* name,
                                             vector_int2 dimensions,
                                             NS::UInteger rowStride,
                                             NS::UInteger channelCount,
                                             TextureChannelEncoding channelEncoding,
                                             BOOL isCube)
{
    return Object::sendMessage<Texture*>(this, 
         _MDL_PRIVATE_SEL(initWithData_topLeftOrigin_name_dimensions_rowStride_channelCount_channelEncoding_isCube_),
         pixelData, topLeftOrigin, name, dimensions, rowStride, channelCount, channelEncoding, isCube);
}

// method: writeToURL:
_MDL_INLINE BOOL MDL::Texture::writeToURL(const NS::URL* URL)
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(writeToURL_), URL);
}

// method: writeToURL:level:
_MDL_INLINE BOOL MDL::Texture::writeToURL(const NS::URL* URL, NS::UInteger level)
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(writeToURL_level_), URL, level);
}

// method: writeToURL:type
_MDL_INLINE BOOL MDL::Texture::writeToURL(const NS::URL* nsurl, CFStringRef type)
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(writeToURL_type_), nsurl, type);
}

// method: writeToURL:type:level:
_MDL_INLINE BOOL MDL::Texture::writeToURL(const NS::URL* nsurl, CFStringRef type, NS::UInteger level)
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(writeToURL_type_level_), nsurl, type, level);
}

// method: imageFromTexture
_MDL_INLINE CGImageRef MDL::Texture::imageFromTexture()
{
    return Object::sendMessage<CGImageRef>(this, _MDL_PRIVATE_SEL(imageFromTexture));
}

// method: imageFromTextureAtLevel:
_MDL_INLINE CGImageRef MDL::Texture::imageFromTextureAtLevel(NS::UInteger level)
{
    return Object::sendMessage<CGImageRef>(this, _MDL_PRIVATE_SEL(imageFromTextureAtLevel_), level);
}

// method: texelDataWithTopLeftOrigin
_MDL_INLINE NS::Data* MDL::Texture::texelDataWithTopLeftOrigin()
{
    return Object::sendMessage<NS::Data*>(this, _MDL_PRIVATE_SEL(texelDataWithTopLeftOrigin));
}

// method: texelDataWithBottomLeftOrigin
_MDL_INLINE NS::Data* MDL::Texture::texelDataWithBottomLeftOrigin()
{
    return Object::sendMessage<NS::Data*>(this, _MDL_PRIVATE_SEL(texelDataWithBottomLeftOrigin));
}

// property: dimensions
_MDL_INLINE vector_int2 MDL::Texture::dimensions() const
{
    return Object::sendMessage<vector_int2>(this, _MDL_PRIVATE_SEL(dimensions));
}

// property: rowStride
_MDL_INLINE NS::Integer MDL::Texture::rowStride() const
{
    return Object::sendMessage<NS::Integer>(this, _MDL_PRIVATE_SEL(rowStride));
}

// property: channelCount
_MDL_INLINE NS::UInteger MDL::Texture::channelCount() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(channelCount));
}

// property: mipLevelCount
_MDL_INLINE NS::UInteger MDL::Texture::mipLevelCount() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(mipLevelCount));
}

// property: channelEncoding
_MDL_INLINE MDL::TextureChannelEncoding MDL::Texture::channelEncoding() const
{
    return Object::sendMessage<TextureChannelEncoding>(this, _MDL_PRIVATE_SEL(channelEncoding));
}

// property: isCube
_MDL_INLINE BOOL MDL::Texture::isCube() const
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(isCube));
}
// write method: setAsCube:
_MDL_INLINE void MDL::Texture::setAsCube(BOOL isCube)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setAsCube_), isCube);
}

// property: hasAlphaValues
_MDL_INLINE BOOL MDL::Texture::hasAlphaValues() const
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(hasAlphaValues));
}
// write method: setAsAlphaValues:
_MDL_INLINE void MDL::Texture::setAsAlphaValues(BOOL hasAlphaValues)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setAsAlphaValues_), hasAlphaValues);
}

// MARK: Class URLTexture

// static method: alloc
_MDL_INLINE MDL::URLTexture* MDL::URLTexture::alloc()
{
    return NS::Object::alloc<MDL::URLTexture>(_MDL_PRIVATE_CLS(MDLURLTexture));
}

// method: initWithURL:name:
_MDL_INLINE MDL::URLTexture* MDL::URLTexture::init(const NS::URL* URL, const NS::String* name)
{
    return Object::sendMessage<MDL::URLTexture*>(this, _MDL_PRIVATE_SEL(initWithURL_name_), URL, name);
}

// property: URL
_MDL_INLINE NS::URL* MDL::URLTexture::URL() const
{
    return Object::sendMessage<NS::URL*>(this, _MDL_PRIVATE_SEL(URL));
}
// write method: setURL:
_MDL_INLINE void MDL::URLTexture::setURL(const NS::URL* URL)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setURL_), URL);
}

// MARK: Class CheckerboardTexture

// static method: alloc
_MDL_INLINE MDL::CheckerboardTexture* MDL::CheckerboardTexture::alloc()
{
    return NS::Object::alloc<MDL::CheckerboardTexture>(_MDL_PRIVATE_CLS(MDLCheckerboardTexture));
}

// method: initWithDivisions:name:dimensions:channelCount:channelEncoding:color1:color2:
_MDL_INLINE MDL::CheckerboardTexture* MDL::CheckerboardTexture::init(float divisions,
                                                                     const NS::String* name,
                                                                     vector_int2 dimensions,
                                                                     int channelCount,
                                                                     TextureChannelEncoding channelEncoding,
                                                                     CGColorRef color1,
                                                                     CGColorRef color2)
{
    return Object::sendMessage<CheckerboardTexture*>(this,
                                                     _MDL_PRIVATE_SEL(initWithDivisions_name_dimensions_channelCount_channelEncoding_color1_color2_),
                                                     divisions, name, dimensions, channelCount, channelEncoding, color1, color2);
}

// property: divisions
_MDL_INLINE float MDL::CheckerboardTexture::divisions() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(divisions));
}
// write method: setDivisions:
_MDL_INLINE void MDL::CheckerboardTexture::setDivisions(float divisions)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setDivisions_), divisions);
}

// property: color1
_MDL_INLINE CGColorRef MDL::CheckerboardTexture::color1() const
{
    return Object::sendMessage<CGColorRef>(this, _MDL_PRIVATE_SEL(color1));
}
// write method: setColor1:
_MDL_INLINE void MDL::CheckerboardTexture::setColor1(CGColorRef color1)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setColor1_), color1);
}

// property: color2
_MDL_INLINE CGColorRef MDL::CheckerboardTexture::color2() const
{
    return Object::sendMessage<CGColorRef>(this, _MDL_PRIVATE_SEL(color2));
}
// write method: setColor2:
_MDL_INLINE void MDL::CheckerboardTexture::setColor2(CGColorRef color2)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setColor2_), color2);
}

// MARK: Class SkyCubeTexture

// static method: alloc
_MDL_INLINE MDL::SkyCubeTexture* MDL::SkyCubeTexture::alloc()
{
    return NS::Object::alloc<MDL::SkyCubeTexture>(_MDL_PRIVATE_CLS(MDLSkyCubeTexture));
}

// method: initWithName:channelEncoding:textureDimensions:turbidity:sunElevation:upperAtmosphereScattering:groundAlbedo:
_MDL_INLINE MDL::SkyCubeTexture* MDL::SkyCubeTexture::init(const NS::String* name,
                                                           TextureChannelEncoding channelEncoding,
                                                           vector_int2 textureDimensions,
                                                           float turbidity,
                                                           float sunElevation,
                                                           float upperAtmosphereScattering,
                                                           float groundAlbedo)
{
    return Object::sendMessage<SkyCubeTexture*>(this,
        _MDL_PRIVATE_SEL(initWithName_channelEncoding_textureDimensions_turbidity_sunElevation_upperAtmosphereScattering_groundAlbedo_),
        name, channelEncoding, textureDimensions, turbidity, sunElevation, upperAtmosphereScattering, groundAlbedo);
}

// method: initWithName:channelEncoding:textureDimensions:turbidity:sunElevation:sunAzimuth:upperAtmosphereScattering:groundAlbedo:
_MDL_INLINE MDL::SkyCubeTexture* MDL::SkyCubeTexture::init(const NS::String* name,
                                                           TextureChannelEncoding channelEncoding,
                                                           vector_int2 textureDimensions,
                                                           float turbidity,
                                                           float sunElevation,
                                                           float sunAzimuth,
                                                           float upperAtmosphereScattering,
                                                           float groundAlbedo)
{
    return Object::sendMessage<SkyCubeTexture*>(this,
        _MDL_PRIVATE_SEL(initWithName_channelEncoding_textureDimensions_turbidity_sunElevation_sunAzimuth_upperAtmosphereScattering_groundAlbedo_),
        name, channelEncoding, textureDimensions, turbidity, sunElevation, sunAzimuth, upperAtmosphereScattering, groundAlbedo);
}

// method: updateTexture
_MDL_INLINE void MDL::SkyCubeTexture::updateTexture()
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(updateTexture));
}

// property: turbidity
_MDL_INLINE float MDL::SkyCubeTexture::turbidity() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(turbidity));
}
// write method: setTurbidity:
_MDL_INLINE void MDL::SkyCubeTexture::setTurbidity(float turbidity)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setTurbidity_), turbidity);
}

// property: sunElevation
_MDL_INLINE float MDL::SkyCubeTexture::sunElevation() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(sunElevation));
}
// write method: setSunElevation:
_MDL_INLINE void MDL::SkyCubeTexture::setSunElevation(float sunElevation)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setSunElevation_), sunElevation);
}

// property: sunAzimuth
_MDL_INLINE float MDL::SkyCubeTexture::sunAzimuth() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(sunAzimuth));
}
// write method: setSunAzimuth:
_MDL_INLINE void MDL::SkyCubeTexture::setSunAzimuth(float sunAzimuth)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setSunAzimuth_), sunAzimuth);
}

// property: upperAtmosphereScattering
_MDL_INLINE float MDL::SkyCubeTexture::upperAtmosphereScattering() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(upperAtmosphereScattering));
}
// write method: setUpperAtmosphereScattering:
_MDL_INLINE void MDL::SkyCubeTexture::setUpperAtmosphereScattering(float upperAtmosphereScattering)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setUpperAtmosphereScattering_), upperAtmosphereScattering);
}

// property: groundAlbedo
_MDL_INLINE float MDL::SkyCubeTexture::groundAlbedo() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(groundAlbedo));
}
// write method: setGroundAlbedo:
_MDL_INLINE void MDL::SkyCubeTexture::setGroundAlbedo(float groundAlbedo)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setGroundAlbedo_), groundAlbedo);
}

// property: horizonElevation
_MDL_INLINE float MDL::SkyCubeTexture::horizonElevation() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(horizonElevation));
}
// write method: setHorizonElevation:
_MDL_INLINE void MDL::SkyCubeTexture::setHorizonElevation(float horizonElevation)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setHorizonElevation_), horizonElevation);
}

// property: groundColor
_MDL_INLINE CGColorRef MDL::SkyCubeTexture::groundColor() const
{
    return Object::sendMessage<CGColorRef>(this, _MDL_PRIVATE_SEL(groundColor));
}
// write method: setGroundColor:
_MDL_INLINE void MDL::SkyCubeTexture::setGroundColor(CGColorRef groundColor)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setGroundColor_), groundColor);
}

// property: gamma
_MDL_INLINE float MDL::SkyCubeTexture::gamma() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(gamma));
}
// write method: setGamma:
_MDL_INLINE void MDL::SkyCubeTexture::setGamma(float gamma)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setGamma_), gamma);
}

// property: exposure
_MDL_INLINE float MDL::SkyCubeTexture::exposure() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(exposure));
}
// write method: setExposure:
_MDL_INLINE void MDL::SkyCubeTexture::setExposure(float exposure)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setExposure_), exposure);
}

// property: brightness
_MDL_INLINE float MDL::SkyCubeTexture::brightness() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(brightness));
}
// write method: setBrightness:
_MDL_INLINE void MDL::SkyCubeTexture::setBrightness(float brightness)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setBrightness_), brightness);
}

// property: contrast
_MDL_INLINE float MDL::SkyCubeTexture::contrast() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(contrast));
}
// write method: setContrast:
_MDL_INLINE void MDL::SkyCubeTexture::setContrast(float contrast)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setContrast_), contrast);
}

// property: saturation
_MDL_INLINE float MDL::SkyCubeTexture::saturation() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(saturation));
}
// write method: setSaturation:
_MDL_INLINE void MDL::SkyCubeTexture::setSaturation(float saturation)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setSaturation_), saturation);
}

// property: highDynamicRangeCompression
_MDL_INLINE vector_float2 MDL::SkyCubeTexture::highDynamicRangeCompression() const
{
    return Object::sendMessage<vector_float2>(this, _MDL_PRIVATE_SEL(highDynamicRangeCompression));
}
// write method: setHighDynamicRangeCompression:
_MDL_INLINE void MDL::SkyCubeTexture::setHighDynamicRangeCompression(vector_float2 highDynamicRangeCompression)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setHighDynamicRangeCompression_), highDynamicRangeCompression);
}

// MARK: Class ColorSwatchTexture

// static method: alloc
_MDL_INLINE MDL::ColorSwatchTexture* MDL::ColorSwatchTexture::alloc()
{
    return NS::Object::alloc<MDL::ColorSwatchTexture>(_MDL_PRIVATE_CLS(MDLColorSwatchTexture));
}

// method: initWithColorTemperatureGradientFrom:toColorTemperature:name:textureDimensions:
_MDL_INLINE MDL::ColorSwatchTexture* MDL::ColorSwatchTexture::initWithColorTemperatureGradientFrom(float colorTemperature1,
                                                                                                   float colorTemperature2,
                                                                                                   const NS::String* name,
                                                                                                   vector_int2 textureDimensions)
{
    return Object::sendMessage<ColorSwatchTexture*>(this,
        _MDL_PRIVATE_SEL(initWithColorTemperatureGradientFrom_toColorTemperature_name_textureDimensions_),
        colorTemperature1, colorTemperature2, name, textureDimensions);
}

// method: initWithColorGradientFrom:toColor:name:textureDimensions:
_MDL_INLINE MDL::ColorSwatchTexture* MDL::ColorSwatchTexture::initWithColorGradientFrom(float color1,
                                                                                        float color2,
                                                                                        const NS::String* name,
                                                                                        vector_int2 textureDimensions)
{
    return Object::sendMessage<ColorSwatchTexture*>(this,
        _MDL_PRIVATE_SEL(initWithColorGradientFrom_toColor_name_textureDimensions_),
        color1, color2, name, textureDimensions);
}

// MARK: Class NoiseTexture

// static method: alloc
_MDL_INLINE MDL::NoiseTexture* MDL::NoiseTexture::alloc()
{
    return NS::Object::alloc<MDL::NoiseTexture>(_MDL_PRIVATE_CLS(MDLNoiseTexture));
}

// method: initVectorNoiseWithSmoothness:name:textureDimensions:channelEncoding:
_MDL_INLINE MDL::NoiseTexture* MDL::NoiseTexture::initVectorNoiseWithSmoothness(float smoothness,
                                                                                const NS::String* name,
                                                                                vector_int2 textureDimensions,
                                                                                TextureChannelEncoding channelEncoding)
{
    return Object::sendMessage<NoiseTexture*>(this,
        _MDL_PRIVATE_SEL(initVectorNoiseWithSmoothness_name_textureDimensions_channelEncoding_),
        smoothness, name, textureDimensions, channelEncoding);
}

// method: initScalarNoiseWithSmoothness:name:textureDimensions:channelCount:channelEncoding:grayscale:
_MDL_INLINE MDL::NoiseTexture* MDL::NoiseTexture::initScalarNoiseWithSmoothness(float smoothness,
                                                                                const NS::String* name,
                                                                                vector_int2 textureDimensions,
                                                                                int channelCount,
                                                                                TextureChannelEncoding channelEncoding,
                                                                                BOOL grayscale)
{
    return Object::sendMessage<NoiseTexture*>(this,
        _MDL_PRIVATE_SEL(initScalarNoiseWithSmoothness_name_textureDimensions_channelCount_channelEncoding_grayscale_),
        smoothness, name, textureDimensions, channelCount, channelEncoding, grayscale);
}

// method: initCellularNoiseWithFrequency:name:textureDimensions:channelEncoding:
_MDL_INLINE MDL::NoiseTexture* MDL::NoiseTexture::initCellularNoiseWithFrequency(float frequency,
                                                                                 const NS::String* name,
                                                                                 vector_int2 textureDimensions,
                                                                                 TextureChannelEncoding channelEncoding)
{
    return Object::sendMessage<NoiseTexture*>(this,
        _MDL_PRIVATE_SEL(initCellularNoiseWithFrequency_name_textureDimensions_channelEncoding_),
        frequency, name, textureDimensions, channelEncoding);
}

// MARK: Class NormalMapTexture

// static method: alloc
_MDL_INLINE MDL::NormalMapTexture* MDL::NormalMapTexture::alloc()
{
    return NS::Object::alloc<MDL::NormalMapTexture>(_MDL_PRIVATE_CLS(MDLNormalMapTexture));
}

// method: initByGeneratingNormalMapWithTexture:name:smoothness:contrast:
_MDL_INLINE MDL::NormalMapTexture* MDL::NormalMapTexture::init(const Texture* sourceTexture,
                                                               const NS::String* name,
                                                               float smoothness,
                                                               float contrast)
{
    return Object::sendMessage<NormalMapTexture*>(this,
        _MDL_PRIVATE_SEL(initByGeneratingNormalMapWithTexture_name_smoothness_contrast_),
        sourceTexture, name, smoothness, contrast);
}









// MARK: - Original Header

//#pragma once
//
//#import <Foundation/Foundation.h>
//#import <ModelIO/ModelIOExports.h>
//#import <ModelIO/MDLTypes.h>
//#import <ModelIO/MDLObject.h>
//#import <ModelIO/MDLAssetResolver.h>
//#import <CoreGraphics/CoreGraphics.h>
//#import <CoreGraphics/CGImage.h>
//#import <simd/simd.h>
//
//NS_ASSUME_NONNULL_BEGIN
//
//
//@class NSURL;
//@class NSString;

/**
 The enoding of texel channel elements
 */

//typedef NS_ENUM(NSInteger, MDLTextureChannelEncoding) {
//    MDLTextureChannelEncodingUInt8 = 1,
//    MDLTextureChannelEncodingUint8 = 1,
//    MDLTextureChannelEncodingUInt16 = 2,
//    MDLTextureChannelEncodingUint16 = 2,
//    MDLTextureChannelEncodingUInt24 = 3,
//    MDLTextureChannelEncodingUint24 = 3,
//    MDLTextureChannelEncodingUInt32 = 4,
//    MDLTextureChannelEncodingUint32 = 4,
//    MDLTextureChannelEncodingFloat16 = 0x102,
//    MDLTextureChannelEncodingFloat16SR = 0x302,
//    MDLTextureChannelEncodingFloat32 = 0x104,
//};

/**
 MDLTexture
 @summary a description of texels provided by a texture object.
 
 @discussion A texture optionally generates or loads texels
             through an access to the data property, or one of the other
             properties, otherwise the texture object is a lightweight descriptor
             only.
 
 @property data
           Texel data that will exist when referenced; it may or may not exist
           before
 @property dimensions
           texel width and height of the texture
 @property rowStride
           The number of bytes from the first texel in a row to the first texel
           in the next row. A rowStride of zero indicates that interleaved x,y
           addressing of texels is not possible. This might be the case if the
           texture was compressed in some manner, for example.
 @property channelCount
           The number of channels incoded in a single texel. For example, an RGB
           texture has 3 channels. All channels must have the same encoding.
 @property channelEncoding
           The encoding of a channel in a single texel.
 @property isCube
           The texture encodes a cube map. If YES, then the layout of the cube
           map is deduced as a vertical strip if dimension.y is six times
           dimension.x. Other layouts are possible in the future.
 */

//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLTexture : NSObject<MDLNamed>
//
//- (instancetype)init NS_DESIGNATED_INITIALIZER;
//
///**
// Creates a texture from a source in the main bundle named in a manner matching
//  name.
// */
//+ (nullable instancetype)textureNamed:(NSString *)name;
//+ (nullable instancetype)textureNamed:(NSString *)name bundle:(nullable NSBundle*)bundleOrNil;
//+ (nullable instancetype)textureNamed:(NSString *)name assetResolver:(id<MDLAssetResolver>)resolver API_AVAILABLE(macos(10.14), ios(12.0), tvos(12.0));

/**
  Creates a cube texture map image using 6 faces of the same dimensions,
  ordered +X,-X,+Y,-Y,+Z,-Z If the data is read back the image will be compacted
  into a single vertical stack where dimensions.y = 6 * dimensions.x
  isCube will return YES
 
  @param names a collection of mosaiced images in a cross formation or column or row.
  - If 6 individual images are given they are assumed to be in order and will be
    loaded as is.
  - if 3 images of double height or width are given they will be treated as
    pairs of + and - in each axis, the order is must be x, then y, then z.
  - if 2 images of triple height or width are given they will be treates as a
    positive set and a negative set in the order +x, +y, +z, then -x, -y, -z.
  - if a single image is given it will be used without conversion if in column
    orientation and demosaiced in all other instances.
 */
//+ (nullable instancetype)textureCubeWithImagesNamed:(NSArray<NSString *> *)names;
//+ (nullable instancetype)textureCubeWithImagesNamed:(NSArray<NSString *> *)names
//                                             bundle:(nullable NSBundle*)bundleOrNil;
//
//+ (instancetype)irradianceTextureCubeWithTexture:(MDLTexture*)texture
//                                            name:(nullable NSString*)name
//                                      dimensions:(vector_int2)dimensions;
//
//+ (instancetype)irradianceTextureCubeWithTexture:(MDLTexture*)texture
//                                            name:(nullable NSString*)name
//                                      dimensions:(vector_int2)dimensions
//                                       roughness:(float)roughness;

//- (instancetype)initWithData:(nullable NSData *)pixelData
//               topLeftOrigin:(BOOL)topLeftOrigin
//                        name:(nullable NSString*)name
//                  dimensions:(vector_int2)dimensions
//                   rowStride:(NSInteger)rowStride
//                channelCount:(NSUInteger)channelCount
//             channelEncoding:(MDLTextureChannelEncoding)channelEncoding
//                      isCube:(BOOL)isCube NS_DESIGNATED_INITIALIZER;
//
///** write a texture to URL, deducing type from path extension */
//- (BOOL)writeToURL:(NSURL *)URL;
//
///** write a particular level of a mipped texture to URL, deducing type from path extension */
//- (BOOL)writeToURL:(NSURL *)URL level:(NSUInteger)level API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//
///** write a texture to URL, using a specific UT type */
//- (BOOL)writeToURL:(NSURL *)nsurl type:(CFStringRef)type;

/** write a particular level of a mipped texture to URL, using a specific UT type */
//- (BOOL)writeToURL:(NSURL *)nsurl type:(CFStringRef)type level:(NSUInteger)level API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//
//- (nullable CGImageRef)imageFromTexture;
//- (nullable CGImageRef)imageFromTextureAtLevel:(NSUInteger)level API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));

//- (nullable NSData *)texelDataWithTopLeftOrigin;
//- (nullable NSData *)texelDataWithBottomLeftOrigin;
//
//- (nullable NSData *)texelDataWithTopLeftOriginAtMipLevel:(NSInteger)level create:(BOOL)create;
//- (nullable NSData *)texelDataWithBottomLeftOriginAtMipLevel:(NSInteger)level create:(BOOL)create;

//@property (nonatomic, readonly) vector_int2 dimensions;
//@property (nonatomic, readonly) NSInteger rowStride;
//@property (nonatomic, readonly) NSUInteger channelCount;
//@property (nonatomic, readonly) NSUInteger mipLevelCount;
//@property (nonatomic, readonly) MDLTextureChannelEncoding channelEncoding;
//@property (nonatomic) BOOL isCube;

/**
 hasAlphaValues
 @summary
 Can be overridden. If not overridden, hasAlpha will be NO if the texture does not
 have an alpha channel. It wil be YES if the texture has an alpha channel and
 there is at least one non-opaque texel in it.
 */
//@property (nonatomic) BOOL hasAlphaValues;
//
//@end

/**
 MDLURLTexture
 @summary a texture provider initialized with a URL or file path.
 @discussion if any of the properties of the texture, such as data, are referenced,
             then the texture may be loaded, otherwise, the MDLURLTexture is merely
             a lightweight reference to something that could be loaded
 */

//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLURLTexture : MDLTexture
//
//- (instancetype)initWithURL:(NSURL*)URL name:(nullable NSString*)name;
//
//@property (nonatomic, copy) NSURL* URL;
//
//@end

/**
MDLCheckerboardTexture
 A two color checkboard with a certain number of divisions
 
 @discussion the texture will be created if data is referenced, otherwise, this
             object is merely a description
 */

//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLCheckerboardTexture : MDLTexture
//
//- (instancetype)initWithDivisions:(float)divisions
//                             name:(nullable NSString*)name
//                       dimensions:(vector_int2)dimensions
//                     channelCount:(int)channelCount
//                  channelEncoding:(MDLTextureChannelEncoding)channelEncoding
//                           color1:(CGColorRef)color1
//                           color2:(CGColorRef)color2;
//
//@property (nonatomic, assign) float divisions;
//@property (nullable, nonatomic) CGColorRef color1;
//@property (nullable, nonatomic) CGColorRef color2;
//
//@end

/**
MDLSkyCubeTexture
 @summary A physically realistic sky as a cube texture
 
 @property sunElevation A value of zero is at the zenith, 0.5 is at the horizon,
           1.0 is at the nadir. Use in conjunction with turbidity to give a dawn,
           dusk, or noon look.
 @property turbidity A value of zero simulates the effect of a clear sky, the sun
           will impart very little color to the sky. A value of one simulates a
           great deal of dust and moisture in the sky, and will cause the sun's
           color to spread across the atmosphere.
 @property upperAtmosphereScattering A value of zero will give very dusky colors,
           a value of one will give noon-ish saturated colors.
 @property groundAlbedo controls the amount of light that bounces back up into
           the sky from the ground. A value of zero will yield a clear sky, a
           value of one will reduce the contrast of the sky, making it a bit foggy.
 
 @property horizonElevation If the lower half of the environment is being replaced
           by a color, horizonElevation is angle, in radians, below which the
           replacement should occur. Negative values are below the horizon.

 @property groundColor If this value is set, the environment will be replaced with
           the color below the horizonElevation value blended with the w factor up to
           Pi/2.0 past the horizon.
           (e.g. w = 0.0 groundColor is applied immediatly on the horizon with no blend
                 w = Pi/2 groundColor is linearly applied all the way to the south pole)
           NOTE: To maintain default behavior a simple length(groundColor) != 0 is used to determine
                 if we want to set the ground color (e.g. black and blended immediatly
                 on the horizon use (0.0, 0.0, 0.0, 0.0000001))
           4 component treats the first 3 components as color and w as blend factor
           3 component treats the first 3 components as color and 0 as blend factor
           2 component treats the first component as greyscale color and y as blend factor
           1 component treats the scalar component as greyscale color and 0 as blend factor
 
 @property gamma Modifies the amount of gamma correction applied during
           tone mapping.
 @property exposure Modifies the exposure applied during tone mapping.
 @property brighness Modifies the brightness of the image during tone mapping.
 @property contrast Modifies the contrast of the image during tone mapping.
 @property saturation Modifes the saturation of the image during tone mapping.
 @property highDynamicRangeCompression values below the x component of this value
           are not compressed during tone mapping. Values between the x component
           and y component are compressed to the maximum brightness value during
           tone mapping. Values above the limit are clamped.
 
 @discussion the texture will be created if data is referenced, otherwise, this
 object is merely a description. All parameters have legal values between zero and one.
 */

//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLSkyCubeTexture : MDLTexture
//
//- (instancetype)initWithName:(nullable NSString*)name
//             channelEncoding:(MDLTextureChannelEncoding)channelEncoding
//           textureDimensions:(vector_int2)textureDimensions   // the size of one cube face
//                   turbidity:(float)turbidity                 // the clearness of the sky
//                sunElevation:(float)sunElevation              // from 0 to 1 zenith to nadir
//   upperAtmosphereScattering:(float)upperAtmosphereScattering // how intense the sun looks, 0 to 1
//                groundAlbedo:(float)groundAlbedo;             // how much sky color is reflected from the Earth
//
//- (instancetype)initWithName:(nullable NSString*)name
//             channelEncoding:(MDLTextureChannelEncoding)channelEncoding
//           textureDimensions:(vector_int2)textureDimensions   // the size of one cube face
//                   turbidity:(float)turbidity                 // the clearness of the sky
//                sunElevation:(float)sunElevation              // from 0 to 1 zenith to nadir
//                  sunAzimuth:(float)sunAzimuth                // from 0 to 2Pi
//   upperAtmosphereScattering:(float)upperAtmosphereScattering // how intense the sun looks, 0 to 1
//                groundAlbedo:(float)groundAlbedo              // how much sky color is reflected from the Earth
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));

/**
 Call updateTexture if parameters have been changed and a new sky is required.
 */
//- (void)updateTexture;
//
//@property (nonatomic, assign) float turbidity;
//@property (nonatomic, assign) float sunElevation;
//@property (nonatomic, assign) float sunAzimuth API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//@property (nonatomic, assign) float upperAtmosphereScattering;
//@property (nonatomic, assign) float groundAlbedo;
//
//@property (nonatomic, assign) float horizonElevation;
//@property (nullable, nonatomic) CGColorRef groundColor;
//
//@property (nonatomic, assign) float gamma;
//@property (nonatomic, assign) float exposure;
//@property (nonatomic, assign) float brightness;
//@property (nonatomic, assign) float contrast;
//@property (nonatomic, assign) float saturation;
//@property (nonatomic, assign) vector_float2 highDynamicRangeCompression;
//
//@end

//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLColorSwatchTexture : MDLTexture
//
///**
// Create a color gradient from one color temperature to another. The units are
// blackbody temperatures. The gradient will be vertical.
// */
//
//- (instancetype) initWithColorTemperatureGradientFrom:(float)colorTemperature1
//                                   toColorTemperature:(float)colorTemperature2
//                                                 name:(nullable NSString*)name
//                                    textureDimensions:(vector_int2)textureDimensions;
//
///**
// Create a color gradient from one color to another. The color will interpolate
// according to hue. The gradient will be vertical.
// */
//
//- (instancetype) initWithColorGradientFrom:(CGColorRef)color1
//                                   toColor:(CGColorRef)color2
//                                      name:(nullable NSString*)name
//                         textureDimensions:(vector_int2)textureDimensions;
//
//@end


/**
 MDLNoiseTexture
 @summary a noise texture containing vector or scalar noise
 @discussion the texture will be created if data is referenced, otherwise, this
 object is merely a description
 */

//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLNoiseTexture : MDLTexture
//
//
///**
// Create a four channel texture containing directional noise. The RGBA values in this
// texture can be used as a normal map or as direction possibly with length. XYZ are a
// three dimensional direction, and A is a magnitude.
// 
// @param smoothness how similar neighboring pixels are. A value of zero is like static,
// one is smooth.
// */
//- (instancetype)initVectorNoiseWithSmoothness:(float)smoothness
//                                         name:(nullable NSString*)name
//                            textureDimensions:(vector_int2)textureDimensions
//                              channelEncoding:(MDLTextureChannelEncoding)channelEncoding;
//
///**
// Create a texture containing colored noise. The noise texture is tileable with itself.
// 
// @param smoothness how similar neighboring pixels are. A value of zero is like
//        static, one is smooth.
// @param grayscale if YES, RGB and A will all be the same. If no, RGB and A will
//        all be different. A is not pre-multiplied, because the intent is that if
//        you read a texel in a shader, all four values will be exactly the same
//        value if grayscale, or four different, uncorrelated values if not grayscale.
// */
//- (instancetype)initScalarNoiseWithSmoothness:(float)smoothness
//                                         name:(nullable NSString*)name
//                            textureDimensions:(vector_int2)textureDimensions
//                                 channelCount:(int)channelCount
//                              channelEncoding:(MDLTextureChannelEncoding)channelEncoding
//                                    grayscale:(BOOL)grayscale;
//
///**
// Create a texture containing cellular noise.
// 
// @param frequency How large the cells will be
// */
//- (instancetype)initCellularNoiseWithFrequency:(float)frequency
//                                          name:(nullable NSString*)name
//                             textureDimensions:(vector_int2)textureDimensions
//                               channelEncoding:(MDLTextureChannelEncoding)channelEncoding API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//
//@end
//
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLNormalMapTexture : MDLTexture
//
//- (instancetype)initByGeneratingNormalMapWithTexture:(MDLTexture*)sourceTexture
//                                                name:(nullable NSString*)name
//                                          smoothness:(float)smoothness
//                                            contrast:(float)contrast;
//
//@end
//
//NS_ASSUME_NONNULL_END

