/*!
 @header MDLMaterial.hpp
 @framework ModelIO
 @abstract Structures for describing rendering material properties
 @copyright Treata Norouzi on 8/17/24.
 */


#pragma once

#import <Foundation/Foundation.hpp>
#import <CoreGraphics/CoreGraphics.h>
#import <simd/simd.h>
#include "ModelIOExports.hpp"
#include "MDLTypes.hpp"
#include "MDLTransform.hpp"
#include "MDLAssetResolver.hpp"

namespace MDL
{
_MDL_ENUM(NS::UInteger, MaterialSemantic) {
    MaterialSemanticBaseColor = 0,
    MaterialSemanticSubsurface,
    MaterialSemanticMetallic,
    MaterialSemanticSpecular,
    MaterialSemanticSpecularExponent,
    MaterialSemanticSpecularTint,
    MaterialSemanticRoughness,
    MaterialSemanticAnisotropic,
    MaterialSemanticAnisotropicRotation,
    MaterialSemanticSheen,
    MaterialSemanticSheenTint,
    MaterialSemanticClearcoat,
    MaterialSemanticClearcoatGloss,
    
    MaterialSemanticEmission,
    MaterialSemanticBump,
    MaterialSemanticOpacity,
    MaterialSemanticInterfaceIndexOfRefraction,
    MaterialSemanticMaterialIndexOfRefraction,
    MaterialSemanticObjectSpaceNormal,
    MaterialSemanticTangentSpaceNormal,
    MaterialSemanticDisplacement,
    MaterialSemanticDisplacementScale,
    MaterialSemanticAmbientOcclusion,
    MaterialSemanticAmbientOcclusionScale,
    
    MaterialSemanticNone = 0x8000,
    MaterialSemanticUserDefined = 0x8001
};

_MDL_ENUM(NS::UInteger, MaterialPropertyType) {
    MaterialPropertyTypeNone = 0, // default resulting from [MaterialProperty init]
    MaterialPropertyTypeString,
    MaterialPropertyTypeURL,
    MaterialPropertyTypeTexture,
    MaterialPropertyTypeColor,
    MaterialPropertyTypeFloat,
    MaterialPropertyTypeFloat2,
    MaterialPropertyTypeFloat3,
    MaterialPropertyTypeFloat4,
    MaterialPropertyTypeMatrix44,
    MaterialPropertyTypeBuffer
};

_MDL_ENUM(NS::UInteger, MaterialTextureWrapMode) {
    MaterialTextureWrapModeClamp,
    MaterialTextureWrapModeRepeat,
    MaterialTextureWrapModeMirror,
};

_MDL_ENUM(NS::UInteger, MaterialTextureFilterMode) {
    MaterialTextureFilterModeNearest,
    MaterialTextureFilterModeLinear,
};

_MDL_ENUM(NS::UInteger, MaterialMipMapFilterMode) {
    MaterialMipMapFilterModeNearest,
    MaterialMipMapFilterModeLinear,
};

// MARK: -

class TextureFilter : public NS::Referencing<TextureFilter>
{
public:
    static class TextureFilter*     alloc();
    
    // !!!: Uncertain
    class TextureFilter*            init();
    
    // assign
    MaterialTextureWrapMode         sWrapMode() const;
    void                            setSWrapMode(MaterialTextureWrapMode sWrapMode);
    
    MaterialTextureWrapMode         tWrapMode() const;
    void                            setTWrapMode(MaterialTextureWrapMode tWrapMode);
    
    MaterialTextureWrapMode         rWrapMode() const;
    void                            setRWrapMode(MaterialTextureWrapMode rWrapMode);
    
    MaterialTextureFilterMode       minFilter() const;
    void                            setMinFilter(MaterialTextureFilterMode minFilter);
    
    MaterialTextureFilterMode       magFilter() const;
    void                            setMagFilter(MaterialTextureFilterMode magFilter);
    
    MaterialMipMapFilterMode        mipFilter() const;
    void                            setMipFilter(MaterialMipMapFilterMode mipFilter);
};

class TextureSampler : public NS::Referencing<TextureSampler>
{
public:
    static class TextureSampler*    alloc();
    
    // !!!: Uncertain
    class TextureSampler*           init();
    
    Texture*                        texture() const;
    void                            setTexture(const Texture* texture);
    
    TextureFilter*                  hardwareFilter() const;
    void                            setHardwareFilter(const TextureFilter* hardwareFilter);
    
    Transform*                      transform() const;
    void                            setTransform(const Transform* transform);
};

class MaterialProperty : public NS::Copying<Named>
{
public:
    static class MaterialProperty*  alloc();
    
    // initWithName:semantic:
    class MaterialProperty*         init(const NS::String* name, MaterialSemantic semantic);
    
    // initWithName:semantic:float2:
    class MaterialProperty*         init(const NS::String* name, MaterialSemantic semantic, vector_float2 value);
    
    // initWithName:semantic:float3:
    class MaterialProperty*         init(const NS::String* name, MaterialSemantic semantic, vector_float3 value);
    
    // initWithName:semantic:float4:
    class MaterialProperty*         init(const NS::String* name, MaterialSemantic semantic, vector_float4 value);
    
    // initWithName:semantic:matrix4x4:
    class MaterialProperty*         init(const NS::String* name, MaterialSemantic semantic, matrix_float4x4 value);
    
    // initWithName:semantic:URL:
    class MaterialProperty*         init(const NS::String* name, MaterialSemantic semantic, const NS::URL* URL);
    
    // initWithName:semantic:string:
    class MaterialProperty*         init(const NS::String* name, MaterialSemantic semantic, const NS::String* string);
    
    // initWithName:semantic:textureSampler:
    class MaterialProperty*         init(const NS::String* name, MaterialSemantic semantic, const TextureSampler* textureSampler);
    
    // initWithName:semantic:color:
    class MaterialProperty*         init(const NS::String* name, MaterialSemantic semantic, CGColorRef color);
    
    // setProperties:
    void                            setProperties(const MaterialProperty * property);
    
    // assign
    MaterialSemantic                semantic() const;
    void                            setSemantic(MaterialSemantic semantic);
    
    MaterialPropertyType            type() const;
    void                            setType(MaterialPropertyType type);
    
    // copy
    NS::String*                     name() const;
    void                            setName(const NS::String* name);
    
    NS::String*                     stringValue() const;
    void                            setStringValue(const NS::String* stringValue);
    
    NS::URL*                        URLValue() const;
    void                            setURLValue(const NS::URL* URLValue);
    
    // retain
    TextureSampler*                 textureSamplerValue() const;
    void                            setTextureSamplerValue(const TextureSampler* textureSamplerValue);
    
    //
    CGColorRef                      color() const;
    void                            setColor(CGColorRef color);
    
    // assign
    float                           floatValue() const;
    void                            setFloatValue(float floatValue);
    
    vector_float2                   float2Value() const;
    void                            setFloat2Value(vector_float2);
    
    vector_float3                   float3Value() const;
    void                            setFloat3Value(vector_float3);
    
    vector_float4                   float4Value() const;
    void                            setFloat4Value(vector_float4);
    
    matrix_float4x4                 matrix4x4() const;
    void                            setMatrix4x4(matrix_float4x4 matrix4x4);
    
    float                           luminance() const;
    void                            setLuminance(float luminance);
};

class MaterialPropertyConnection : public NS::Copying<Named>
{
public:
    static class MaterialPropertyConnection*    alloc();
    
    // initWithOutput:input:
    class MaterialPropertyConnection*           init(const MaterialProperty* output,
                                                     const MaterialProperty* input);
    
    MaterialProperty*                           output() const;
    
    MaterialProperty*                           input() const;
};

class MaterialPropertyNode : public NS::Copying<Named>
{
public:
    static class MaterialPropertyNode*  alloc();
    
    // initWithInputs:outputs:evaluationFunction:
    class MaterialPropertyNode*         init(const class MaterialProperty* inputs,
                                             // !!!: Uncertain
                                             const class MaterialProperty* outputs,
                                             void (^function)(const MaterialPropertyNode*));
    
    // !!!: Uncertain
    // copy
    void                                (^evaluationFunction)(const MaterialPropertyNode*);
    // Needs set method?
    
    NS::Array*                          inputs() const;
    
    NS::Array*                          outputs() const;
};

class MaterialPropertyGraph : public NS::Copying<MaterialPropertyNode>
{
public:
    static class MaterialPropertyGraph* alloc();
    
    // initWithNodes:connections:
    class MaterialPropertyGraph*        init(const NS::Array* nodes,
                                             const NS::Array* connections);
    
    void                                evaluate();
    
    NS::Array*                          nodes() const;
    
    NS::Array*                          connections() const;
};

class ScatteringFunction : public NS::Copying<Named>
{
public:
    static class ScatteringFunction*    alloc();
    
    class ScatteringFunction*           init();
    
    // copy
    NS::String*                         name() const;
    void                                setName(const NS::String* name);
    
    // - Readonly
    MaterialProperty*                   baseColor() const;
    
    MaterialProperty*                   emission() const;
    
    MaterialProperty*                   specular() const;
    
    MaterialProperty*                   materialIndexOfRefraction() const;
    
    MaterialProperty*                   interfaceIndexOfRefraction() const;
    
    MaterialProperty*                   normal() const;
    
    MaterialProperty*                   ambientOcclusion() const;
    
    MaterialProperty*                   ambientOcclusionScale() const;
};

class PhysicallyPlausibleScatteringFunction : public NS::Copying<ScatteringFunction>
{
public:
    static class PhysicallyPlausibleScatteringFunction* alloc();
    
    class PhysicallyPlausibleScatteringFunction*        init();
    
    // - Readonly
    NS::Integer                                         version() const;
    
    MaterialProperty*                                   subsurface() const;
    
    MaterialProperty*                                   metallic() const;
    
    MaterialProperty*                                   specularAmount() const;
    
    MaterialProperty*                                   specularTint() const;
    
    MaterialProperty*                                   roughness() const;
    
    MaterialProperty*                                   anisotropic() const;
    
    MaterialProperty*                                   anisotropicRotation() const;
    
    MaterialProperty*                                   sheen() const;
    
    MaterialProperty*                                   sheenTint() const;
    
    MaterialProperty*                                   clearcoat() const;
    
    MaterialProperty*                                   clearcoatGloss() const;
};

_MDL_ENUM(NS::UInteger, MaterialFace) {
    MaterialFaceFront = 0,
    MaterialFaceBack,
    MaterialFaceDoubleSided
};

class Material : public NS::Copying<MDL::Named, NS::FastEnumeration>
{
public:
    static class Material*      alloc();
    
    // initWithName:scatteringFunction:
    class Material*             init(const NS::String* name, const ScatteringFunction* scatteringFunction);
    
    // setProperty:
    void                        setProperty(const MaterialProperty* property);
    
    // removeProperty:
    void                        removeProperty(const MaterialProperty* property);
    
    // propertyNamed:
    MaterialProperty*           propertyNamed(const NS::String* name);
    
    // propertyWithSemantic:
    MaterialProperty*           propertyWithSemantic(MaterialSemantic semantic);
    
    // propertiesWithSemantic:
    NS::Array*                  propertiesWithSemantic(MaterialSemantic semantic);
    
    void                        removeAllProperties();
    
    // resolveTexturesWithResolver:
    void                        resolveTexturesWithResolver(const class AssetResolver* resolver);
    
    // loadTexturesUsingResolver:
    void                        loadTexturesUsingResolver(const class AssetResolver* resolver);
    
    ScatteringFunction*         scatteringFunction() const;
    
    // copy
    NS::String*                 name() const;
    void                        setName(const NS::String* name);
    
    Material*                   baseMaterial() const;
    void                        setBaseMaterial(const Material* baseMaterial);
    
    // objectAtIndexedSubscript:
    MaterialProperty*           objectAtIndexedSubscript(NS::UInteger idx);
    
    // objectForKeyedSubscript:
    MaterialProperty*           objectForKeyedSubscript(const NS::String* name);
    
    NS::UInteger                count() const;
    
    MaterialFace                materialFace() const;
    void                        setMaterialFace(MaterialFace materialFace);
};
    
}

// MARK: - Private Sector

// static method: alloc
_MDL_INLINE MDL::TextureFilter* MDL::TextureFilter::alloc()
{
    return NS::Object::alloc<MDL::TextureFilter>(_MDL_PRIVATE_CLS(MDLTextureFilter));
}

// method: init
_MDL_INLINE MDL::TextureFilter* MDL::TextureFilter::init()
{
    return NS::Object::init<MDL::TextureFilter>();
}

// property: sWrapMode
_MDL_INLINE MDL::MaterialTextureWrapMode MDL::TextureFilter::sWrapMode() const
{
    return Object::sendMessage<MaterialTextureWrapMode>(this, _MDL_PRIVATE_SEL(sWrapMode));
}
// write method: setSWrapMode:
_MDL_INLINE void MDL::TextureFilter::setSWrapMode(MaterialTextureWrapMode sWrapMode)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setSWrapMode_), sWrapMode);
}

// property: tWrapMode
_MDL_INLINE MDL::MaterialTextureWrapMode MDL::TextureFilter::tWrapMode() const
{
    return Object::sendMessage<MaterialTextureWrapMode>(this, _MDL_PRIVATE_SEL(tWrapMode));
}
// write method: setTWrapMode:
_MDL_INLINE void MDL::TextureFilter::setTWrapMode(MaterialTextureWrapMode tWrapMode)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setTWrapMode_), tWrapMode);
}

// property: rWrapMode
_MDL_INLINE MDL::MaterialTextureWrapMode MDL::TextureFilter::rWrapMode() const
{
    return Object::sendMessage<MaterialTextureWrapMode>(this, _MDL_PRIVATE_SEL(rWrapMode));
}
// write method: setRWrapMode:
_MDL_INLINE void MDL::TextureFilter::setRWrapMode(MaterialTextureWrapMode rWrapMode)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setRWrapMode_), rWrapMode);
}

// property: minFilter
_MDL_INLINE MDL::MaterialTextureFilterMode MDL::TextureFilter::minFilter() const
{
    return Object::sendMessage<MaterialTextureFilterMode>(this, _MDL_PRIVATE_SEL(minFilter));
}
// write method: setMinFilter:
_MDL_INLINE void MDL::TextureFilter::setMinFilter(MaterialTextureFilterMode minFilter)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setMinFilter_), minFilter);
}

// property: magFilter
_MDL_INLINE MDL::MaterialTextureFilterMode MDL::TextureFilter::magFilter() const
{
    return Object::sendMessage<MaterialTextureFilterMode>(this, _MDL_PRIVATE_SEL(magFilter));
}
// write method: setMagFilter:
_MDL_INLINE void MDL::TextureFilter::setMagFilter(MaterialTextureFilterMode magFilter)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setMagFilter_), magFilter);
}

// property: mipFilter
_MDL_INLINE MDL::MaterialMipMapFilterMode MDL::TextureFilter::mipFilter() const
{
    return Object::sendMessage<MaterialMipMapFilterMode>(this, _MDL_PRIVATE_SEL(mipFilter));
}
// write method: setMipFilter:
_MDL_INLINE void MDL::TextureFilter::setMipFilter(MaterialMipMapFilterMode mipFilter)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setMipFilter_), mipFilter);
}

// MARK: Class TextureSampler

// static method: alloc
_MDL_INLINE MDL::TextureSampler* MDL::TextureSampler::alloc()
{
    return NS::Object::alloc<MDL::TextureSampler>(_MDL_PRIVATE_CLS(MDLTextureSampler));
}

// method: init
_MDL_INLINE MDL::TextureSampler* MDL::TextureSampler::init()
{
    return NS::Object::init<MDL::TextureSampler>();
}

// property: texture
_MDL_INLINE MDL::Texture* MDL::TextureSampler::texture() const
{
    return Object::sendMessage<Texture*>(this, _MDL_PRIVATE_SEL(texture));
}
// write method: setTexture:
_MDL_INLINE void MDL::TextureSampler::setTexture(const Texture* texture)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setTexture_), texture);
}

// property: hardwareFilter
_MDL_INLINE MDL::TextureFilter* MDL::TextureSampler::hardwareFilter() const
{
    return Object::sendMessage<TextureFilter*>(this, _MDL_PRIVATE_SEL(hardwareFilter));
}
// write method: setHardwareFilter:
_MDL_INLINE void MDL::TextureSampler::setHardwareFilter(const TextureFilter* hardwareFilter)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setHardwareFilter_), hardwareFilter);
}

// property: transform
_MDL_INLINE MDL::Transform* MDL::TextureSampler::transform() const
{
    return Object::sendMessage<Transform*>(this, _MDL_PRIVATE_SEL(transform));
}
// write method: setTransform:
_MDL_INLINE void MDL::TextureSampler::setTransform(const Transform* transform)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setTransform_), transform);
}

// MARK: Class MaterialProperty

// static method: alloc
_MDL_INLINE MDL::MaterialProperty* MDL::MaterialProperty::alloc()
{
    return NS::Object::alloc<MDL::MaterialProperty>(_MDL_PRIVATE_CLS(MDLMaterialProperty));
}

// method: initWithName:semantic:
_MDL_INLINE MDL::MaterialProperty* MDL::MaterialProperty::init(const NS::String* name, MaterialSemantic semantic)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(initWithName_semantic_), name, semantic);
}

// method: initWithName:semantic:float2
_MDL_INLINE MDL::MaterialProperty* MDL::MaterialProperty::init(const NS::String* name, MaterialSemantic semantic, vector_float2 value)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(initWithName_semantic_float2_), name, semantic, value);
}

// method: initWithName:semantic:float3
_MDL_INLINE MDL::MaterialProperty* MDL::MaterialProperty::init(const NS::String* name, MaterialSemantic semantic, vector_float3 value)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(initWithName_semantic_float3_), name, semantic, value);
}

// method: initWithName:semantic:float4
_MDL_INLINE MDL::MaterialProperty* MDL::MaterialProperty::init(const NS::String* name, MaterialSemantic semantic, vector_float4 value)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(initWithName_semantic_float4_), name, semantic, value);
}

// method: initWithName:semantic:matrix4x4:
_MDL_INLINE MDL::MaterialProperty* MDL::MaterialProperty::init(const NS::String* name, MaterialSemantic semantic, matrix_float4x4 value)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(initWithName_semantic_matrix4x4_), name, semantic, value);
}

// method: initWithName:semantic:URL:
_MDL_INLINE MDL::MaterialProperty* MDL::MaterialProperty::init(const NS::String* name, MaterialSemantic semantic, const NS::URL* URL)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(initWithName_semantic_URL_), name, semantic, URL);
}

// method: initWithName:semantic:string:
_MDL_INLINE MDL::MaterialProperty* MDL::MaterialProperty::init(const NS::String* name, MaterialSemantic semantic, const NS::String* string)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(initWithName_semantic_string_), name, semantic, string);
}

// method: initWithName:semantic:textureSampler:
_MDL_INLINE MDL::MaterialProperty* MDL::MaterialProperty::init(const NS::String* name, MaterialSemantic semantic, const TextureSampler* textureSampler)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(initWithName_semantic_textureSampler_), name, semantic, textureSampler);
}

// method: initWithName:semantic:color:
_MDL_INLINE MDL::MaterialProperty* MDL::MaterialProperty::init(const NS::String* name, MaterialSemantic semantic, CGColorRef color)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(initWithName_semantic_color_), name, semantic, color);
}

// static method: setProperties:
_MDL_INLINE void MDL::MaterialProperty::setProperties(const MaterialProperty * property)
{
    return Object::sendMessage<void>(_MDL_PRIVATE_CLS(MDLTexture), _MDL_PRIVATE_SEL(setProperties_), property);
}

// property: semantic
_MDL_INLINE MDL::MaterialSemantic MDL::MaterialProperty::semantic() const
{
    return Object::sendMessage<MaterialSemantic>(this, _MDL_PRIVATE_SEL(semantic));
}
// write method: setSemantic:
_MDL_INLINE void MDL::MaterialProperty::setSemantic(MaterialSemantic semantic)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setSemantic_), semantic);
}

// property: type
_MDL_INLINE MDL::MaterialPropertyType MDL::MaterialProperty::type() const
{
    return Object::sendMessage<MaterialPropertyType>(this, _MDL_PRIVATE_SEL(type));
}
// write method: setType:
_MDL_INLINE void MDL::MaterialProperty::setType(MaterialPropertyType type)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setType_), type);
}

// property: name
_MDL_INLINE NS::String* MDL::MaterialProperty::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}
// write method: setName:
_MDL_INLINE void MDL::MaterialProperty::setName(const NS::String* name)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setName_), name);
}

// property: stringValue
_MDL_INLINE NS::String* MDL::MaterialProperty::stringValue() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(stringValue));
}
// write method: setStringValue:
_MDL_INLINE void MDL::MaterialProperty::setStringValue(const NS::String* stringValue)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setStringValue_), stringValue);
}

// property: URLValue
_MDL_INLINE NS::URL* MDL::MaterialProperty::URLValue() const
{
    return Object::sendMessage<NS::URL*>(this, _MDL_PRIVATE_SEL(URLValue));
}
// write method: setURLValue:
_MDL_INLINE void MDL::MaterialProperty::setURLValue(const NS::URL* URLValue)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setURLValue_), URLValue);
}

// property: textureSamplerValue
_MDL_INLINE MDL::TextureSampler* MDL::MaterialProperty::textureSamplerValue() const
{
    return Object::sendMessage<TextureSampler*>(this, _MDL_PRIVATE_SEL(textureSamplerValue));
}
// write method: setTextureSamplerValue:
_MDL_INLINE void MDL::MaterialProperty::setTextureSamplerValue(const TextureSampler* textureSamplerValue)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setTextureSamplerValue_), textureSamplerValue);
}

// property: color
_MDL_INLINE CGColorRef MDL::MaterialProperty::color() const
{
    return Object::sendMessage<CGColorRef>(this, _MDL_PRIVATE_SEL(color));
}
// write method: setColor:
_MDL_INLINE void MDL::MaterialProperty::setColor(CGColorRef color)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setColor_), color);
}

// property: floatValue
_MDL_INLINE float MDL::MaterialProperty::floatValue() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(floatValue));
}
// write method: setFloatValue:
_MDL_INLINE void MDL::MaterialProperty::setFloatValue(float floatValue)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloatValue_), floatValue);
}

// property: float2Value
_MDL_INLINE vector_float2 MDL::MaterialProperty::float2Value() const
{
    return Object::sendMessage<vector_float2>(this, _MDL_PRIVATE_SEL(float2Value));
}
// write method: setFloat2Value:
_MDL_INLINE void MDL::MaterialProperty::setFloat2Value(vector_float2 float2Value)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloat2Value_), float2Value);
}

// property: float3Value
_MDL_INLINE vector_float3 MDL::MaterialProperty::float3Value() const
{
    return Object::sendMessage<vector_float3>(this, _MDL_PRIVATE_SEL(float3Value));
}
// write method: setFloat3Value:
_MDL_INLINE void MDL::MaterialProperty::setFloat3Value(vector_float3 float3Value)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloat3Value_), float3Value);
}

// property: float4Value
_MDL_INLINE vector_float4 MDL::MaterialProperty::float4Value() const
{
    return Object::sendMessage<vector_float4>(this, _MDL_PRIVATE_SEL(float4Value));
}
// write method: setFloat4Value:
_MDL_INLINE void MDL::MaterialProperty::setFloat4Value(vector_float4 float4Value)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloat4Value_), float4Value);
}

// property: matrix4x4
_MDL_INLINE matrix_float4x4 MDL::MaterialProperty::matrix4x4() const
{
    return Object::sendMessage<matrix_float4x4>(this, _MDL_PRIVATE_SEL(matrix4x4));
}
// write method: setMatrix4x4:
_MDL_INLINE void MDL::MaterialProperty::setMatrix4x4(matrix_float4x4 matrix4x4)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setMatrix4x4_), matrix4x4);
}

// property: luminance
_MDL_INLINE float MDL::MaterialProperty::luminance() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(luminance));
}
// write method: setLuminance:
_MDL_INLINE void MDL::MaterialProperty::setLuminance(float luminance)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setLuminance_), luminance);
}

// MARK: Class MaterialPropertyConnection

// static method: alloc
_MDL_INLINE MDL::MaterialPropertyConnection* MDL::MaterialPropertyConnection::alloc()
{
    return NS::Object::alloc<MDL::MaterialPropertyConnection>(_MDL_PRIVATE_CLS(MDLMaterialPropertyConnection));
}

// method: initWithOutput:input:
_MDL_INLINE MDL::MaterialPropertyConnection* MDL::MaterialPropertyConnection::init(const MaterialProperty* output,
                                                                                   const MaterialProperty* input)
{
    return Object::sendMessage<MaterialPropertyConnection*>(this, _MDL_PRIVATE_SEL(initWithOutput_input_), output, input);
}

// property: output
_MDL_INLINE MDL::MaterialProperty* MDL::MaterialPropertyConnection::output() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(output));
}

// property: input
_MDL_INLINE MDL::MaterialProperty* MDL::MaterialPropertyConnection::input() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(input));
}

// MARK: Class MaterialPropertyNode

// static method: alloc
_MDL_INLINE MDL::MaterialPropertyNode* MDL::MaterialPropertyNode::alloc()
{
    return NS::Object::alloc<MDL::MaterialPropertyNode>(_MDL_PRIVATE_CLS(MDLMaterialPropertyNode));
}

// method: initWithInputs:outputs:evaluationFunction:
_MDL_INLINE MDL::MaterialPropertyNode* MDL::MaterialPropertyNode::init(const class MaterialProperty* inputs,
                                                                       // !!!: Uncertain
                                                                       const class MaterialProperty* outputs,
                                                                       void (^function)(const MaterialPropertyNode*))
{
    return Object::sendMessage<MaterialPropertyNode*>(this,
                                                      _MDL_PRIVATE_SEL(initWithInputs_outputs_evaluationFunction_),
                                                      inputs, outputs, function);
}

// TODO: Implement the `evaluationFunction`
// property: evaluationFunction
//_MDL_INLINE void MDL::MaterialPropertyNode::evaluationFunction()
//{
//    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(evaluationFunction));
//}

// property: inputs
_MDL_INLINE NS::Array* MDL::MaterialPropertyNode::inputs() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(inputs));
}

// property: outputs
_MDL_INLINE NS::Array* MDL::MaterialPropertyNode::outputs() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(outputs));
}

// MARK: Class MaterialPropertyGraph

// static method: alloc
_MDL_INLINE MDL::MaterialPropertyGraph* MDL::MaterialPropertyGraph::alloc()
{
    return NS::Object::alloc<MDL::MaterialPropertyGraph>(_MDL_PRIVATE_CLS(MDLMaterialPropertyGraph));
}

// method: initWithNodes:connections:
_MDL_INLINE MDL::MaterialPropertyGraph* MDL::MaterialPropertyGraph::init(const NS::Array* nodes,
                                                                         const NS::Array* connections)
{
    return Object::sendMessage<MaterialPropertyGraph*>(this, _MDL_PRIVATE_SEL(initWithNodes_connections_), nodes, connections);
}

// method: evaluate
_MDL_INLINE void MDL::MaterialPropertyGraph::evaluate()
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(evaluate));
}

// property: nodes
_MDL_INLINE NS::Array* MDL::MaterialPropertyGraph::nodes() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(nodes));
}

// property: connections
_MDL_INLINE NS::Array* MDL::MaterialPropertyGraph::connections() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(connections));
}

// MARK: Class ScatteringFunction

// static method: alloc
_MDL_INLINE MDL::ScatteringFunction* MDL::ScatteringFunction::alloc()
{
    return NS::Object::alloc<MDL::ScatteringFunction>(_MDL_PRIVATE_CLS(MDLScatteringFunction));
}

// method: init
_MDL_INLINE MDL::ScatteringFunction* MDL::ScatteringFunction::init()
{
    return NS::Object::init<MDL::ScatteringFunction>();
}

// property: name
_MDL_INLINE NS::String* MDL::ScatteringFunction::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}
// write method: setName:
_MDL_INLINE void MDL::ScatteringFunction::setName(const NS::String* name)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setName_), name);
}

// property: baseColor
_MDL_INLINE MDL::MaterialProperty* MDL::ScatteringFunction::baseColor() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(baseColor));
}

// property: emission
_MDL_INLINE MDL::MaterialProperty* MDL::ScatteringFunction::emission() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(emission));
}

// property: specular
_MDL_INLINE MDL::MaterialProperty* MDL::ScatteringFunction::specular() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(specular));
}

// property: materialIndexOfRefraction
_MDL_INLINE MDL::MaterialProperty* MDL::ScatteringFunction::materialIndexOfRefraction() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(materialIndexOfRefraction));
}

// property: interfaceIndexOfRefraction
_MDL_INLINE MDL::MaterialProperty* MDL::ScatteringFunction::interfaceIndexOfRefraction() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(interfaceIndexOfRefraction));
}

// property: normal
_MDL_INLINE MDL::MaterialProperty* MDL::ScatteringFunction::normal() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(normal));
}

// property: ambientOcclusion
_MDL_INLINE MDL::MaterialProperty* MDL::ScatteringFunction::ambientOcclusion() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(ambientOcclusion));
}

// property: ambientOcclusionScale
_MDL_INLINE MDL::MaterialProperty* MDL::ScatteringFunction::ambientOcclusionScale() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(ambientOcclusionScale));
}

// MARK: Class PhysicallyPlausibleScatteringFunction

// static method: alloc
_MDL_INLINE MDL::PhysicallyPlausibleScatteringFunction* MDL::PhysicallyPlausibleScatteringFunction::alloc()
{
    return NS::Object::alloc<MDL::PhysicallyPlausibleScatteringFunction>(_MDL_PRIVATE_CLS(MDLPhysicallyPlausibleScatteringFunction));
}

// method: init
_MDL_INLINE MDL::PhysicallyPlausibleScatteringFunction* MDL::PhysicallyPlausibleScatteringFunction::init()
{
    return NS::Object::init<MDL::PhysicallyPlausibleScatteringFunction>();
}

// property: version
_MDL_INLINE NS::Integer MDL::PhysicallyPlausibleScatteringFunction::version() const
{
    return Object::sendMessage<NS::Integer>(this, _MDL_PRIVATE_SEL(version));
}

// property: subsurface
_MDL_INLINE MDL::MaterialProperty* MDL::PhysicallyPlausibleScatteringFunction::subsurface() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(subsurface));
}

// property: metallic
_MDL_INLINE MDL::MaterialProperty* MDL::PhysicallyPlausibleScatteringFunction::metallic() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(metallic));
}

// property: specularAmount
_MDL_INLINE MDL::MaterialProperty* MDL::PhysicallyPlausibleScatteringFunction::specularAmount() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(specularAmount));
}

// property: specularTint
_MDL_INLINE MDL::MaterialProperty* MDL::PhysicallyPlausibleScatteringFunction::specularTint() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(specularTint));
}

// property: roughness
_MDL_INLINE MDL::MaterialProperty* MDL::PhysicallyPlausibleScatteringFunction::roughness() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(roughness));
}

// property: anisotropic
_MDL_INLINE MDL::MaterialProperty* MDL::PhysicallyPlausibleScatteringFunction::anisotropic() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(anisotropic));
}

// property: anisotropicRotation
_MDL_INLINE MDL::MaterialProperty* MDL::PhysicallyPlausibleScatteringFunction::anisotropicRotation() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(anisotropicRotation));
}

// property: sheen
_MDL_INLINE MDL::MaterialProperty* MDL::PhysicallyPlausibleScatteringFunction::sheen() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(sheen));
}

// property: sheenTint
_MDL_INLINE MDL::MaterialProperty* MDL::PhysicallyPlausibleScatteringFunction::sheenTint() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(sheenTint));
}

// property: clearcoat
_MDL_INLINE MDL::MaterialProperty* MDL::PhysicallyPlausibleScatteringFunction::clearcoat() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(clearcoat));
}

// property: clearcoatGloss
_MDL_INLINE MDL::MaterialProperty* MDL::PhysicallyPlausibleScatteringFunction::clearcoatGloss() const
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(clearcoatGloss));
}

// MARK: Class Material

// static method: alloc
_MDL_INLINE MDL::Material* MDL::Material::alloc()
{
    return NS::Object::alloc<MDL::Material>(_MDL_PRIVATE_CLS(MDLMaterial));
}

// method: initWithName:scatteringFunction:
_MDL_INLINE MDL::Material* MDL::Material::init(const NS::String* name, const ScatteringFunction* scatteringFunction)
{
    return Object::sendMessage<Material*>(this, _MDL_PRIVATE_SEL(initWithName_scatteringFunction_), name, scatteringFunction);
}

// method: setProperty:
_MDL_INLINE void MDL::Material::setProperty(const MaterialProperty* property)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setProperty_), property);
}

// method: removeProperty:
_MDL_INLINE void MDL::Material::removeProperty(const MaterialProperty* property)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(removeProperty_), property);
}

// method: propertyNamed:
_MDL_INLINE MDL::MaterialProperty* MDL::Material::propertyNamed(const NS::String* name)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(propertyNamed_), name);
}

// method: propertyWithSemantic:
_MDL_INLINE MDL::MaterialProperty* MDL::Material::propertyWithSemantic(MaterialSemantic semantic)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(propertyWithSemantic_), semantic);
}

// method: propertiesWithSemantic:
_MDL_INLINE NS::Array* MDL::Material::propertiesWithSemantic(MaterialSemantic semantic)
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(propertiesWithSemantic_), semantic);
}

// method: removeAllProperties
_MDL_INLINE void MDL::Material::removeAllProperties()
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(removeAllProperties));
}

// method: resolveTexturesWithResolver:
_MDL_INLINE void MDL::Material::resolveTexturesWithResolver(const class AssetResolver* resolver)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resolveTexturesWithResolver_), resolver);
}

// method: loadTexturesUsingResolver:
_MDL_INLINE void MDL::Material::loadTexturesUsingResolver(const class AssetResolver* resolver)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(loadTexturesUsingResolver_), resolver);
}

// property: scatteringFunction
_MDL_INLINE MDL::ScatteringFunction* MDL::Material::scatteringFunction() const
{
    return Object::sendMessage<ScatteringFunction*>(this, _MDL_PRIVATE_SEL(scatteringFunction));
}

// property: name
_MDL_INLINE NS::String* MDL::Material::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}
// write method: setName:
_MDL_INLINE void MDL::Material::setName(const NS::String* name)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setName_), name);
}

// property: baseMaterial
_MDL_INLINE MDL::Material* MDL::Material::baseMaterial() const
{
    return Object::sendMessage<Material*>(this, _MDL_PRIVATE_SEL(baseMaterial));
}
// write method: setBaseMaterial:
_MDL_INLINE void MDL::Material::setBaseMaterial(const Material* baseMaterial)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setBaseMaterial_), baseMaterial);
}

// method: objectAtIndexedSubscript:
_MDL_INLINE MDL::MaterialProperty* MDL::Material::objectAtIndexedSubscript(NS::UInteger idx)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(objectAtIndexedSubscript_), idx);
}

// method: objectForKeyedSubscript:
_MDL_INLINE MDL::MaterialProperty* MDL::Material::objectForKeyedSubscript(const NS::String* name)
{
    return Object::sendMessage<MaterialProperty*>(this, _MDL_PRIVATE_SEL(objectForKeyedSubscript_), name);
}

// property: count
_MDL_INLINE NS::UInteger MDL::Material::count() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(count));
}

// property: materialFace
_MDL_INLINE MDL::MaterialFace MDL::Material::materialFace() const
{
    return Object::sendMessage<MaterialFace>(this, _MDL_PRIVATE_SEL(materialFace));
}
// write method: setMaterialFace:
_MDL_INLINE void MDL::Material::setMaterialFace(MaterialFace materialFace)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setMaterialFace_), materialFace);
}









// MARK: - Original Header

////#import <Foundation/Foundation.h>
////#import <CoreGraphics/CoreGraphics.h>
////#import <simd/simd.h>
////#import <ModelIO/ModelIOExports.h>
////#import <ModelIO/MDLTypes.h>
////#import <ModelIO/MDLTransform.h>
////#import <ModelIO/MDLAssetResolver.h>
////
////NS_ASSUME_NONNULL_BEGIN
////
////@class MDLTexture;
//
///**
// MDLMaterialSemantic
// 
// @summary The material semantics are identifiers for material properties
//            formally identified by one of the standard material descriptors.
// 
// @discussion When files containing material properties are loaded and translated
//             by ModelIO, an appropriate standard material descriptor will be
//             chosen, and any properties translated from the loaded file can be
//             retrieved using one of these semantics.
// 
// MDLMaterialSemanticBaseColor
//    The inherent color of a surface to be used as a modulator during shading.
//    Default is 50% gray
// 
// MDLMaterialSemanticSubsurface,
//    The degree to which light scatters under the surface of a material
// 
// MDLMaterialSemanticMetallic
//    A blend between a material behaving as a dielectric material at zero, and a
//    metal at one.
// 
// MDLMaterialSemanticSpecular
//    Specular response to incident light
// 
// MDLMaterialSemanticSpecularExponent
//    Power of the specular exponent in the case that a Blinn/Phong BSDF is in use.
// 
// MDLMaterialSemanticSpecularTint
//    At zero, the specular highlight will use the hue, saturation, and intensity
//    of incoming light to color the specular response; at one, the material's
//    base color, and the light's intensity will be used.
// 
// MDLMaterialSemanticRoughness
//    Controls diffuse and specular response. A value of zero is smooth and shiny.
//    At one, a diffuse material will retroreflect, and the specular highlight
//    will be very spread out.
// 
// MDLMaterialSemanticAnisotropic
//    The degree to which the specular highlight is elongated in the direction of
//    the local tangent basis. A mesh that does not have a tangent basis will not
//    respond to this parameter.
// 
// MDLMaterialSemanticAnisotropicRotation
//    The degree to which the anisotropy is rotated relative to the direction of the
//    local tangent basis. Values from zero to one are mapped to zero to two PI.
// 
// MDLMaterialSemanticSheen
//    A specular tint that appears at glancing angles on an object
// 
// MDLMaterialSemanticSheenTint
//    At zero, the specular highlight will use the hue, saturation, and intensity
//    of incoming light to color the specular response; at one, the material's
//    base color, and the light's intensity will be used.
// 
// MDLMaterialSemanticClearcoat
//    A second specular highlight, much like the gloss that results from a clear
//    coat on an automotive finish
// 
// MDLMaterialSemanticClearcoatGloss
//    The glossiness of the clear coat highlight.
//
// MDLMaterialSemanticEmission
//    A value that is to be emitted as radiance by a surface
// 
// MDLMaterialSemanticBump
//    A value that perturbs surface normals according to the local gradient of
//    the property
// 
// MDLMaterialSemanticOpacity
//    The opacity of the surface
// 
// MDLMaterialSemanticInterfaceIndexOfRefraction
//    n1 in Schlick's equation, typically 1.0 for air
// 
// MDLMaterialSemanticMaterialIndexOfRefraction
//    n2 in Schlick's equation
//
// MDLMaterialSemanticObjectSpaceNormal
//    A value that perturbs surface normals in object space
// 
// MDLMaterialSemanticTangentSpaceNormal
//    A value that perturbs surface normals in a local tangent space
//
// MDLMaterialSemanticDisplacement
//    Displacement of a surface relative to surface normal
// 
// MDLMaterialSemanticDisplacementScale
//    Scaling factor for displacement
// 
// MDLMaterialSemanticAmbientOcclusion
//    Ambient occlusion describes the accessibility of the surface to the
//    surrounding radiant environment and is typically used to attenuate it. It is
//    not intended to attenuate direct illumination sources.
// 
// MDLMaterialSemanticAmbientOcclusionScale
//    The degree to which the ambient occlusion values are applied
// 
// MDLMaterialSemanticUserDefined = 0x8000
//    Properties with this value are created when material properties are
//    translated for which no known semantic applies.
//    Semantics defined at greater than this value are available to be user defined.
//    The first value is also used to indicate
//
// */
//
////typedef NS_ENUM(NSUInteger, MDLMaterialSemantic) {
////    MDLMaterialSemanticBaseColor = 0,
////    MDLMaterialSemanticSubsurface,
////    MDLMaterialSemanticMetallic,
////    MDLMaterialSemanticSpecular,
////    MDLMaterialSemanticSpecularExponent,
////    MDLMaterialSemanticSpecularTint,
////    MDLMaterialSemanticRoughness,
////    MDLMaterialSemanticAnisotropic,
////    MDLMaterialSemanticAnisotropicRotation,
////    MDLMaterialSemanticSheen,
////    MDLMaterialSemanticSheenTint,
////    MDLMaterialSemanticClearcoat,
////    MDLMaterialSemanticClearcoatGloss,
////
////    MDLMaterialSemanticEmission,
////    MDLMaterialSemanticBump,
////    MDLMaterialSemanticOpacity,
////    MDLMaterialSemanticInterfaceIndexOfRefraction,
////    MDLMaterialSemanticMaterialIndexOfRefraction,
////    MDLMaterialSemanticObjectSpaceNormal,
////    MDLMaterialSemanticTangentSpaceNormal,
////    MDLMaterialSemanticDisplacement,
////    MDLMaterialSemanticDisplacementScale,
////    MDLMaterialSemanticAmbientOcclusion,
////    MDLMaterialSemanticAmbientOcclusionScale,
////    
////    MDLMaterialSemanticNone = 0x8000,
////    MDLMaterialSemanticUserDefined = 0x8001
////};
////
////typedef NS_ENUM(NSUInteger, MDLMaterialPropertyType) {
////    MDLMaterialPropertyTypeNone = 0, // default resulting from [MDLMaterialProperty init]
////    MDLMaterialPropertyTypeString,
////    MDLMaterialPropertyTypeURL,
////    MDLMaterialPropertyTypeTexture,
////    MDLMaterialPropertyTypeColor,
////    MDLMaterialPropertyTypeFloat,
////    MDLMaterialPropertyTypeFloat2,
////    MDLMaterialPropertyTypeFloat3,
////    MDLMaterialPropertyTypeFloat4,
////    MDLMaterialPropertyTypeMatrix44,
////    MDLMaterialPropertyTypeBuffer
////};
////
/////**
//// Texture filtering
//// */
////
////typedef NS_ENUM(NSUInteger, MDLMaterialTextureWrapMode) {
////    MDLMaterialTextureWrapModeClamp,
////    MDLMaterialTextureWrapModeRepeat,
////    MDLMaterialTextureWrapModeMirror,
////};
////
////typedef NS_ENUM(NSUInteger, MDLMaterialTextureFilterMode) {
////    MDLMaterialTextureFilterModeNearest,
////    MDLMaterialTextureFilterModeLinear,
////};
////
////typedef NS_ENUM(NSUInteger, MDLMaterialMipMapFilterMode) {
////    MDLMaterialMipMapFilterModeNearest,
////    MDLMaterialMipMapFilterModeLinear,
////};
//
////API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
////MDL_EXPORT
////@interface MDLTextureFilter : NSObject
////@property (nonatomic, assign) MDLMaterialTextureWrapMode sWrapMode;
////@property (nonatomic, assign) MDLMaterialTextureWrapMode tWrapMode;
////@property (nonatomic, assign) MDLMaterialTextureWrapMode rWrapMode;
////@property (nonatomic, assign) MDLMaterialTextureFilterMode minFilter;
////@property (nonatomic, assign) MDLMaterialTextureFilterMode magFilter;
////@property (nonatomic, assign) MDLMaterialMipMapFilterMode mipFilter;
////@end
////
////API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
////MDL_EXPORT
////@interface MDLTextureSampler : NSObject
////
////@property (nonatomic, retain, nullable) MDLTexture *texture;
////@property (nonatomic, retain, nullable) MDLTextureFilter *hardwareFilter;
////@property (nonatomic, retain, nullable) MDLTransform *transform;
////
////@end
//
//
///**
// If a color is encoded in a floatN property, it is to be interpreted as
// a Rec 709 color.
// */
//
////API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
////MDL_EXPORT
////@interface MDLMaterialProperty : NSObject<MDLNamed, NSCopying>
////
////- (instancetype)init NS_UNAVAILABLE;
////
////- (instancetype)initWithName:(NSString *)name semantic:(MDLMaterialSemantic)semantic NS_DESIGNATED_INITIALIZER;
////- (instancetype)initWithName:(NSString *)name semantic:(MDLMaterialSemantic)semantic float:(float)value;
////- (instancetype)initWithName:(NSString *)name semantic:(MDLMaterialSemantic)semantic float2:(vector_float2)value;
////- (instancetype)initWithName:(NSString *)name semantic:(MDLMaterialSemantic)semantic float3:(vector_float3)value;
////- (instancetype)initWithName:(NSString *)name semantic:(MDLMaterialSemantic)semantic float4:(vector_float4)value;
////- (instancetype)initWithName:(NSString *)name semantic:(MDLMaterialSemantic)semantic matrix4x4:(matrix_float4x4)value;
////- (instancetype)initWithName:(NSString *)name semantic:(MDLMaterialSemantic)semantic URL:(nullable NSURL*)URL;
////- (instancetype)initWithName:(NSString *)name semantic:(MDLMaterialSemantic)semantic string:(nullable NSString *)string;
////- (instancetype)initWithName:(NSString *)name semantic:(MDLMaterialSemantic)semantic textureSampler:(nullable MDLTextureSampler*)textureSampler;
////- (instancetype)initWithName:(NSString *)name semantic:(MDLMaterialSemantic)semantic color:(CGColorRef)color;
////
////- (void)setProperties:(MDLMaterialProperty *)property;
//
////@property (nonatomic, assign) MDLMaterialSemantic semantic;
////@property (nonatomic, assign) MDLMaterialPropertyType type;
////
/////** @see MDLNamed */
////@property (nonatomic, copy) NSString *name;
////
////@property (nonatomic, copy, nullable) NSString *stringValue;
////@property (nonatomic, copy, nullable) NSURL *URLValue;
////@property (nonatomic, retain, nullable) MDLTextureSampler *textureSamplerValue;
////@property (nullable, nonatomic) CGColorRef color;
////@property (nonatomic, assign) float floatValue;
////@property (nonatomic, assign) vector_float2 float2Value;
////@property (nonatomic, assign) vector_float3 float3Value;
////@property (nonatomic, assign) vector_float4 float4Value;
////@property (nonatomic, assign) matrix_float4x4 matrix4x4;
////@property (nonatomic, assign) float luminance;
////
////@end
//
////API_AVAILABLE(macos(10.12), ios(10.0), tvos(10.0))
////MDL_EXPORT
////@interface MDLMaterialPropertyConnection : NSObject<MDLNamed>
////
////- (instancetype)init NS_UNAVAILABLE;
////
/////** Connects the output to the input */
////- (instancetype)initWithOutput:(MDLMaterialProperty*)output
////                         input:(MDLMaterialProperty*)input;
////
////@property (nonatomic, weak, readonly) MDLMaterialProperty *output;
////@property (nonatomic, weak, readonly) MDLMaterialProperty *input;
////
////@end
//
////API_AVAILABLE(macos(10.12), ios(10.0), tvos(10.0))
////MDL_EXPORT
////@interface MDLMaterialPropertyNode : NSObject<MDLNamed>
////
////- (instancetype)init NS_UNAVAILABLE;
////
////- (instancetype)initWithInputs:(NSArray<MDLMaterialProperty*>*)inputs
////                       outputs:(NSArray<MDLMaterialProperty*>*)outputs
////            evaluationFunction:(void(^)(MDLMaterialPropertyNode*))function;
////
////@property (nonatomic, copy) void(^evaluationFunction)(MDLMaterialPropertyNode*);
////
////@property (nonatomic, readonly) NSArray<MDLMaterialProperty*> *inputs;
////@property (nonatomic, readonly) NSArray<MDLMaterialProperty*> *outputs;
////
////@end
//
///**
// @discussion inputs and outputs will contain all of the inputs and outputs
//             external to the graph, which are all the inputs and outputs not
//             internally connected to something
// */
////API_AVAILABLE(macos(10.12), ios(10.0), tvos(10.0))
////MDL_EXPORT
////@interface MDLMaterialPropertyGraph : MDLMaterialPropertyNode
////
////- (instancetype)init NS_UNAVAILABLE;
////
////- (instancetype)initWithNodes:(NSArray<MDLMaterialPropertyNode*>*)nodes
////                  connections:(NSArray<MDLMaterialPropertyConnection*>*)connections;
////
////- (void)evaluate;
////
////@property (nonatomic, readonly) NSArray<MDLMaterialPropertyNode*> *nodes;
////@property (nonatomic, readonly) NSArray<MDLMaterialPropertyConnection*> *connections;
////
////@end
//
///**
// The base scattering function is Lambertian, with a Blinn-Phong specular response.
// Specular power for Blinn-Phong can be derived from the roughness property using
// an approximation.
// */
//
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLScatteringFunction : NSObject<MDLNamed>
//
///** @see MDLNamed */
//@property (nonatomic, copy) NSString *name;
//
//@property (nonatomic, readonly, retain) MDLMaterialProperty *baseColor;
//@property (nonatomic, readonly, retain) MDLMaterialProperty *emission;
//@property (nonatomic, readonly, retain) MDLMaterialProperty *specular;
//@property (nonatomic, readonly, retain) MDLMaterialProperty *materialIndexOfRefraction;
//@property (nonatomic, readonly, retain) MDLMaterialProperty *interfaceIndexOfRefraction;
//@property (nonatomic, readonly, retain) MDLMaterialProperty *normal;
//@property (nonatomic, readonly, retain) MDLMaterialProperty *ambientOcclusion;
//@property (nonatomic, readonly, retain) MDLMaterialProperty *ambientOcclusionScale;
//
//@end

//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLPhysicallyPlausibleScatteringFunction : MDLScatteringFunction
//
//@property (nonatomic, readonly) NSInteger version; // currently 1
//
//@property (nonatomic, readonly, retain) MDLMaterialProperty *subsurface;           // diffuse shape
//@property (nonatomic, readonly, retain) MDLMaterialProperty *metallic;             // 0 = dielectric, 1 = metallic
//@property (nonatomic, readonly, retain) MDLMaterialProperty *specularAmount;       // specular value
//@property (nonatomic, readonly, retain) MDLMaterialProperty *specularTint;         // bias towards surface color
//@property (nonatomic, readonly, retain) MDLMaterialProperty *roughness;            // diffuse and specular response
//@property (nonatomic, readonly, retain) MDLMaterialProperty *anisotropic;          // shape of specular highlight
//@property (nonatomic, readonly, retain) MDLMaterialProperty *anisotropicRotation;  // shape of specular highlight
//@property (nonatomic, readonly, retain) MDLMaterialProperty *sheen;                // like velvet
//@property (nonatomic, readonly, retain) MDLMaterialProperty *sheenTint;            // bias towards surface color
//@property (nonatomic, readonly, retain) MDLMaterialProperty *clearcoat;            // like clear acrylic on a car
//@property (nonatomic, readonly, retain) MDLMaterialProperty *clearcoatGloss;       // 0 = satin, 1 = glossy
//
//@end
//
//typedef NS_ENUM(NSUInteger, MDLMaterialFace) {
//    MDLMaterialFaceFront = 0,
//    MDLMaterialFaceBack,
//    MDLMaterialFaceDoubleSided
//};

//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLMaterial : NSObject<MDLNamed, NSFastEnumeration>
//
//- (instancetype)initWithName:(NSString*)name scatteringFunction:(MDLScatteringFunction*)scatteringFunction;
//
//- (void)setProperty:(MDLMaterialProperty*)property;
//- (void)removeProperty:(MDLMaterialProperty*)property;
//
//- (nullable MDLMaterialProperty*)propertyNamed:(NSString*)name;
//
//// Returns the first occurence of the property that matches the semantic.
//// Not recommended to use when there are multiple properties with same semantic.
//- (nullable MDLMaterialProperty*)propertyWithSemantic:(MDLMaterialSemantic)semantic;
//
//// Returns the complete list of properties that match the semantic (e.g. Kd & Kd_map)
//- (NSArray<MDLMaterialProperty *> *)propertiesWithSemantic:(MDLMaterialSemantic)semantic API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//- (void)removeAllProperties;
//
//// Iterates all material properties. If they are string values, they are resolved into
//// valid paths as NSURL values.
//// @param resolver If non-nil, the resolver can be invoked to convert stringValues
////                 to NSURLs for loading.
//- (void)resolveTexturesWithResolver:(id<MDLAssetResolver>)resolver API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));

// Iterates all material properties. If they are string values or NSURL values, and
// can be resolved as textures, then the string and NSURL values will be replaced by
// MDLTextureSampler values. The transforms on the samplers will be identity, the
// wrap modes will be clamp, and the filter modes will be linear.
// @param resolver If non-nil, the resolver can be invoked to convert stringValues
//                 to NSURLs for loading.
//- (void)loadTexturesUsingResolver:(id<MDLAssetResolver>)resolver API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//
//@property (nonatomic, readonly, retain) MDLScatteringFunction *scatteringFunction;
//
///** @see MDLNamed */
//@property (nonatomic, copy) NSString *name;
//
//// If a property is not found by propertyForKey and baseMaterial is not nil,
//// propertyForKey will invoke propertyForKey on baseMaterial.
//// All other selectors disregard baseMaterial.
//@property (nonatomic, retain, nullable) MDLMaterial *baseMaterial;
//
//- (nullable MDLMaterialProperty *)objectAtIndexedSubscript:(NSUInteger)idx;
//- (nullable MDLMaterialProperty *)objectForKeyedSubscript:(NSString*)name;
//@property (nonatomic, readonly) NSUInteger count;
//
//// Default is MDLMaterialFaceFront
//@property (nonatomic) MDLMaterialFace materialFace;
//
//@end
//
//NS_ASSUME_NONNULL_END
