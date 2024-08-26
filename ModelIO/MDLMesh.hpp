/*!
 @header MDLMesh.hpp
 @framework ModelIO
 @abstract Structures for describing meshes for rendering
 @copyright Treata Norouzi on 8/18/24.
 */


#include "MDLTypes.hpp"
#include "MDLLight.hpp"
#include "MDLTransform.hpp"
#include "MDLSubmesh.hpp"
#include "MDLMeshBuffer.hpp"
#include "MDLVertexDescriptor.hpp"

namespace MDL
{
class VertexAttributeData : public NS::Referencing<VertexAttributeData>
{
public:
    static class VertexAttributeData*   alloc();
    
    class VertexAttributeData*          init();
    
    MeshBufferMap*                      map() const;
    void                                setMap(const MeshBufferMap* map);
    
    void*                               dataStart() const;
    void                                setDataStart(const void* dataStart);
    
    NS::UInteger                        stride() const;
    void                                setStride(NS::UInteger stride);
    
    VertexFormat                        format() const;
    void                                setFormat(VertexFormat format);
    
    NS::UInteger                        bufferSize() const;
    void                                setBufferSize(NS::UInteger bufferSize);
};

class Mesh : public NS::Referencing<MDL::Object>
{
public:
    static class Mesh*  alloc();
    
    // initWithBufferAllocator:
    class Mesh*         init(class MeshBufferAllocator* bufferAllocator);
    
    // initWithVertexBuffer:vertexCount:descriptor:submeshes:
    class Mesh*         init(class MeshBuffer* vertexBuffer,
                             NS::UInteger vertexCount,
                             const VertexDescriptor* descriptor,
                             const NS::Array* submeshes);
    
    // initWithVertexBuffers:vertexCount:descriptor:submeshes:
    class Mesh*         init(const NS::Array* vertexBuffers,
                             NS::UInteger vertexCount,
                             const VertexDescriptor* descriptor,
                             const NS::Array* submeshes);
    
    // vertexAttributeDataForAttributeNamed:
    VertexAttributeData*    vertexAttributeDataForAttributeNamed(const NS::String* name);
    
    // vertexAttributeDataForAttributeNamed:asFormat:
    VertexAttributeData*    vertexAttributeDataForAttributeNamed(const NS::String* name,
                                                                 VertexFormat format);
    
    AxisAlignedBoundingBox  boundingBox() const;
    
    // Read&Write
    VertexDescriptor*   vertexDescriptor() const;
    void                setVertexDescriptor(const VertexDescriptor* vertexDescriptor);
    
    NS::UInteger        vertexCount() const;
    void                setVertexCount(NS::UInteger vertexCount);
    
    NS::Array*          vertexBuffers() const;
    void                setVertexBuffers(const NS::Array* vertexBuffers);
    
    // !!!: NSMutableArray is not ported to Cpp!
    // copy
//    NS::MutableArray*   submeshes() const;
//    void                setsubmeshes(const NS::MutableArray* submeshes);
    
    class MeshBufferAllocator*  allocator() const;
    
    // MARK: - Modifiers
    
    // addAttributeWithName:format:
    void                addAttributeWithName(const NS::String* name,
                                             VertexFormat format);
    
    // addAttributeWithName:format:type:data:stride:
    void                addAttributeWithName(const NS::String* name,
                                             VertexFormat format,
                                             const NS::String* type,
                                             const NS::Data* data,
                                             NS::Integer stride);
    
    // addAttributeWithName:format:type:data:stride:time:
    void                addAttributeWithName(const NS::String* name,
                                             VertexFormat format,
                                             const NS::String* type,
                                             const NS::Data* data,
                                             NS::Integer stride,
                                             NS::TimeInterval time);
    
    // addNormalsWithAttributeNamed:creaseThreshold:
    void                addNormalsWithAttributeNamed(const NS::String* attributeName, 
                                                     float creaseThreshold);
    
    // TODO: Find a better name for these two
    // addTangentBasisForTextureCoordinateAttributeNamed:tangentAttributeNamed:bitangentAttributeNamed:
    void                addTangentBasisForTextureCoordinateAttributeNamed1(const NS::String* textureCoordinateAttributeName,
                                                                           const NS::String* tangentAttributeName,
                                                                           const NS::String* bitangentAttributeName);
    
    // addTangentBasisForTextureCoordinateAttributeNamed:normalAttributeNamed:tangentAttributeNamed:
    void                addTangentBasisForTextureCoordinateAttributeNamed2(const NS::String* textureCoordinateAttributeName,
                                                                           const NS::String* normalAttributeName,
                                                                           const NS::String* tangentAttributeName);
    
    // addOrthTanBasisForTextureCoordinateAttributeNamed:normalAttributeNamed:tangentAttributeNamed:
    void                addOrthTanBasisForTextureCoordinateAttributeNamed(const NS::String* textureCoordinateAttributeName,
                                                                          const NS::String* normalAttributeName,
                                                                          const NS::String* tangentAttributeName);
    
    // addUnwrappedTextureCoordinatesForAttributeNamed:
    void                addUnwrappedTextureCoordinatesForAttributeNamed(const NS::String* textureCoordinateAttributeName);
    
    // flipTextureCoordinatesInAttributeNamed:
    void                flipTextureCoordinatesInAttributeNamed(const NS::String* textureCoordinateAttributeName);
    
    void                makeVerticesUnique();
    
    // makeVerticesUniqueAndReturnError:
    BOOL                makeVerticesUniqueAndReturnError(NS::Error** error);
    
    // replaceAttributeNamed:
    void                replaceAttributeNamed(const NS::String* name,
                                              const VertexAttributeData* newData);
    
    // updateAttributeNamed:
    void                updateAttributeNamed(const NS::String* name,
                                             const VertexAttributeData* newData);
    
    // removeAttributeNamed:
    void                removeAttributeNamed(const NS::String* name);
    
    // MARK: - Generators
    
    // initBoxWithExtent:segments:inwardNormals:geometryType:allocator:
    class Mesh*         initBoxWithExtent(vector_float3 extent,
                                          vector_uint3 segments,
                                          BOOL inwardNormals,
                                          GeometryType geometryType,
                                          class MeshBufferAllocator* allocator);
    
    // initSphereWithExtent:segments:inwardNormals:geometryType:allocator:
    class Mesh*         initSphereWithExtent(vector_float3 extent,
                                             vector_uint2 segments,
                                             BOOL inwardNormals,
                                             GeometryType geometryType,
                                             class MeshBufferAllocator* allocator);
    
    // initHemisphereWithExtent:segments:inwardNormals:cap:geometryType:allocator:
    class Mesh*         initHemisphereWithExtent(vector_float3 extent,
                                                 vector_uint2 segments,
                                                 BOOL inwardNormals,
                                                 BOOL cap,
                                                 GeometryType geometryType,
                                                 class MeshBufferAllocator* allocator);
    
    // initCylinderWithExtent:segments:inwardNormals:topCap:bottomCap:geometryType:allocator:
    class Mesh*         initCylinderWithExtent(vector_float3 extent,
                                               vector_uint2 segments,
                                               BOOL inwardNormals,
                                               BOOL topCap,
                                               BOOL bottomCap,
                                               GeometryType geometryType,
                                               class MeshBufferAllocator* allocator);
    
    // initCapsuleWithExtent:cylinderSegments:hemisphereSegments:inwardNormals:geometryType:allocator:
    class Mesh*         initCapsuleWithExtent(vector_float3 extent,
                                              vector_uint2 segments,
                                              int hemisphereSegments,
                                              BOOL inwardNormals,
                                              GeometryType geometryType,
                                              class MeshBufferAllocator* allocator);
    
    // initConeWithExtent:segments:inwardNormals:geometryType:allocator:
    class Mesh*         initConeWithExtent(vector_float3 extent,
                                           vector_uint2 segments,
                                           BOOL inwardNormals,
                                           BOOL cap,
                                           GeometryType geometryType,
                                           class MeshBufferAllocator* allocator);
    
    // initPlaneWithExtent:segments:geometryType:allocator:
    class Mesh*         initPlaneWithExtent(vector_float3 extent,
                                            vector_uint2 segments,
                                            GeometryType geometryType,
                                            class MeshBufferAllocator* allocator);
    
    // initIcosahedronWithExtent:segments:geometryType:allocator:
    class Mesh*         initIcosahedronWithExtent(vector_float3 extent,
                                                  BOOL inwardNormals,
                                                  GeometryType geometryType,
                                                  class MeshBufferAllocator* allocator);
    
    // initMeshBySubdividingMesh:submeshIndex:subdivisionLevels:allocator:
    class Mesh*         initMeshBySubdividingMesh(const Mesh* mesh,
                                                  int submeshIndex,
                                                  unsigned int subdivisionLevels,
                                                  class MeshBufferAllocator* allocator);
    
    // newBoxWithDimensions:segments:geometryType:inwardNormals:allocator:
    static class Mesh*  newBoxWithDimensions(vector_float3 dimensions,
                                             vector_uint3 segments,
                                             GeometryType geometryType,
                                             BOOL inwardNormals,
                                             class MeshBufferAllocator* allocator);
    
    // newEllipsoidWithRadii:radialSegments:verticalSegments:geometryType:inwardNormals:hemisphere:allocator:
    static class Mesh*  newEllipsoidWithRadii(vector_float3 radii,
                                              NS::UInteger radialSegments,
                                              NS::UInteger verticalSegments,
                                              GeometryType geometryType,
                                              BOOL inwardNormals,
                                              BOOL hemisphere,
                                              class MeshBufferAllocator* allocator);
    
    // newCylinderWithHeight:radii:radialSegments:verticalSegments:geometryType:inwardNormals:allocator:
    static class Mesh*  newCylinderWithHeight(float height,
                                              vector_float2 radii,
                                              NS::UInteger radialSegments,
                                              NS::UInteger verticalSegments,
                                              GeometryType geometryType,
                                              BOOL inwardNormals,
                                              class MeshBufferAllocator* allocator);
    
    // newCapsuleWithHeight:radii:radialSegments:verticalSegments:hemisphereSegments:geometryType:inwardNormals:allocator:
    static class Mesh*  newCapsuleWithHeight(float height,
                                             vector_float2 radii,
                                             NS::UInteger radialSegments,
                                             NS::UInteger verticalSegments,
                                             NS::UInteger hemisphereSegments,
                                             GeometryType geometryType,
                                             BOOL inwardNormals,
                                             class MeshBufferAllocator* allocator);
    
    // newEllipticalConeWithHeight:radii:radialSegments:verticalSegments:geometryType:inwardNormals:allocator:
    static class Mesh*  newEllipticalConeWithHeight(float height,
                                                    vector_float2 radii,
                                                    NS::UInteger radialSegments,
                                                    NS::UInteger verticalSegments,
                                                    GeometryType geometryType,
                                                    BOOL inwardNormals,
                                                    class MeshBufferAllocator* allocator);
    
    // newPlaneWithDimensions:segments:geometryType:allocator:
    static class Mesh*  newPlaneWithDimensions(vector_float2 dimensions,
                                               vector_uint2 segments,
                                               GeometryType geometryType,
                                               class MeshBufferAllocator* allocator);
    
    // newIcosahedronWithRadius:inwardNormals:geometryType:allocator:
    static class Mesh*  newIcosahedronWithRadius(float radius,
                                                 BOOL inwardNormals,
                                                 GeometryType geometryType,
                                                 class MeshBufferAllocator* allocator);
    
    // newIcosahedronWithRadius:inwardNormals:allocator:
    static class Mesh*  newIcosahedronWithRadius(float radius,
                                                 BOOL inwardNormals,
                                                 class MeshBufferAllocator* allocator);
    
    // newSubdividedMesh:submeshIndex:subdivisionLevels:
    static class Mesh*  newSubdividedMesh(const Mesh* mesh,
                                          NS::UInteger submeshIndex,
                                          NS::UInteger subdivisionLevels);
    
    // MARK: - LightBaking
    
    // generateAmbientOcclusionTextureWithSize:raysPerSample:attenuationFactor:objectsToConsider:vertexAttributeNamed:materialPropertyNamed:
    BOOL                generateAmbientOcclusionTextureWithSize(vector_int2 textureSize,
                                                                NS::UInteger raysPerSample,
                                                                float attenuationFactor,
                                                                const NS::Array* objectsToConsider,
                                                                const NS::String* vertexAttributeName,
                                                                const NS::String* materialPropertyName);
    
    // generateAmbientOcclusionTextureWithQuality:attenuationFactor:objectsToConsider:vertexAttributeNamed:materialPropertyNamed:
    BOOL                generateAmbientOcclusionTextureWithQuality(float bakeQuality,
                                                                   float attenuationFactor,
                                                                   const NS::Array* objectsToConsider,
                                                                   const NS::String* vertexAttributeName,
                                                                   const NS::String* materialPropertyName);
    
    // generateAmbientOcclusionVertexColorsWithRaysPerSample:attenuationFactor:objectsToConsider:vertexAttributeNamed:
    BOOL                generateAmbientOcclusionVertexColorsWithRaysPerSample(NS::Integer raysPerSample,
                                                                              float attenuationFactor,
                                                                              const NS::Array* objectsToConsider,
                                                                              const NS::String* vertexAttributeName);
    
    // generateAmbientOcclusionVertexColorsWithQuality:attenuationFactor:objectsToConsider:vertexAttributeNamed:
    BOOL                generateAmbientOcclusionVertexColorsWithQuality(float bakeQuality,
                                                                        float attenuationFactor,
                                                                        const NS::Array* objectsToConsider,
                                                                        const NS::String* vertexAttributeName);
    
    // generateLightMapTextureWithTextureSize:lightsToConsider:objectsToConsider:vertexAttributeNamed:materialPropertyNamed:
    BOOL                generateLightMapTextureWithTextureSize(vector_int2 textureSize,
                                                               const NS::Array* lightsToConsider,
                                                               const NS::Array* objectsToConsider,
                                                               const NS::String* vertexAttributeName,
                                                               const NS::String* materialPropertyName);
    
    // generateLightMapTextureWithQuality:lightsToConsider:objectsToConsider:vertexAttributeNamed:materialPropertyNamed:
    BOOL                generateLightMapTextureWithQuality(float bakeQuality,
                                                           const NS::Array* lightsToConsider,
                                                           const NS::Array* objectsToConsider,
                                                           const NS::String* vertexAttributeName,
                                                           const NS::String* materialPropertyName);
    
    // generateLightMapVertexColorsWithLightsToConsider:objectsToConsider:vertexAttributeNamed:
    BOOL                generateLightMapVertexColorsWithLightsToConsider(const NS::Array* lightsToConsider,
                                                                         const NS::Array* objectsToConsider,
                                                                         const NS::String* vertexAttributeName);
};

}

// MARK: - Private Sector 

// static method: alloc
_MDL_INLINE MDL::VertexAttributeData* MDL::VertexAttributeData::alloc()
{
    return NS::Object::alloc<MDL::VertexAttributeData>(_MDL_PRIVATE_CLS(MDLVertexAttributeData));
}

// method: init
_MDL_INLINE MDL::VertexAttributeData* MDL::VertexAttributeData::init()
{
    return NS::Object::init<MDL::VertexAttributeData>();
}

// property: map
_MDL_INLINE MDL::MeshBufferMap* MDL::VertexAttributeData::map() const
{
    return Object::sendMessage<MeshBufferMap*>(this, _MDL_PRIVATE_SEL(map));
}
// write method: setMap:
_MDL_INLINE void MDL::VertexAttributeData::setMap(const MeshBufferMap* map)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setMap_), map);
}

// property: dataStart
_MDL_INLINE void* MDL::VertexAttributeData::dataStart() const
{
    return Object::sendMessage<void*>(this, _MDL_PRIVATE_SEL(dataStart));
}
// write method: setDataStart:
_MDL_INLINE void MDL::VertexAttributeData::setDataStart(const void* dataStart)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setDataStart_), dataStart);
}

// property: stride
_MDL_INLINE NS::UInteger MDL::VertexAttributeData::stride() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(stride));
}
// write method: setStride:
_MDL_INLINE void MDL::VertexAttributeData::setStride(NS::UInteger stride)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setStride_), stride);
}

// property: format
_MDL_INLINE MDL::VertexFormat MDL::VertexAttributeData::format() const
{
    return Object::sendMessage<VertexFormat>(this, _MDL_PRIVATE_SEL(format));
}
// write method: setFormat:
_MDL_INLINE void MDL::VertexAttributeData::setFormat(VertexFormat format)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFormat_), format);
}

// property: bufferSize
_MDL_INLINE NS::UInteger MDL::VertexAttributeData::bufferSize() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(bufferSize));
}
// write method: setBufferSize:
_MDL_INLINE void MDL::VertexAttributeData::setBufferSize(NS::UInteger bufferSize)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setBufferSize_), bufferSize);
}

// MARK: Class Mesh

// static method: alloc
_MDL_INLINE MDL::Mesh* MDL::Mesh::alloc()
{
    return NS::Object::alloc<MDL::Mesh>(_MDL_PRIVATE_CLS(MDLMesh));
}

// method: initWithBufferAllocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::init(class MeshBufferAllocator* bufferAllocator)
{
    return Object::sendMessage<Mesh*>(this, _MDL_PRIVATE_SEL(initWithBufferAllocator_), bufferAllocator);
}

// method: initWithVertexBuffer:vertexCount:descriptor:submeshes:
_MDL_INLINE MDL::Mesh* MDL::Mesh::init(class MeshBuffer* vertexBuffer,
                                       NS::UInteger vertexCount,
                                       const VertexDescriptor* descriptor,
                                       const NS::Array* submeshes)
{
    return Object::sendMessage<Mesh*>(this, 
                                      _MDL_PRIVATE_SEL(initWithVertexBuffer_vertexCount_descriptor_submeshes_),
                                      vertexBuffer, vertexCount, descriptor, submeshes);
}

// method: initWithVertexBuffers:vertexCount:descriptor:submeshes:
_MDL_INLINE MDL::Mesh* MDL::Mesh::init(const NS::Array* vertexBuffers,
                                       NS::UInteger vertexCount,
                                       const VertexDescriptor* descriptor,
                                       const NS::Array* submeshes)
{
    return Object::sendMessage<Mesh*>(this,
                                      _MDL_PRIVATE_SEL(initWithVertexBuffers_vertexCount_descriptor_submeshes_),
                                      vertexBuffers, vertexCount, descriptor, submeshes);
}

// method: vertexAttributeDataForAttributeNamed:
_MDL_INLINE MDL::VertexAttributeData* MDL::Mesh::vertexAttributeDataForAttributeNamed(const NS::String* name)
{
    return Object::sendMessage<VertexAttributeData*>(this, _MDL_PRIVATE_SEL(vertexAttributeDataForAttributeNamed_), name);
}

// method: vertexAttributeDataForAttributeNamed:asFormat:
_MDL_INLINE MDL::VertexAttributeData* MDL::Mesh::vertexAttributeDataForAttributeNamed(const NS::String* name,
                                                                                      VertexFormat format)
{
    return Object::sendMessage<VertexAttributeData*>(this,
                                                     _MDL_PRIVATE_SEL(vertexAttributeDataForAttributeNamed_asFormat_),
                                                     name, format);
}

// property: boundingBox
_MDL_INLINE MDL::AxisAlignedBoundingBox MDL::Mesh::boundingBox() const
{
    return Object::sendMessage<AxisAlignedBoundingBox>(this, _MDL_PRIVATE_SEL(boundingBox));
}

// property: vertexDescriptor
_MDL_INLINE MDL::VertexDescriptor* MDL::Mesh::vertexDescriptor() const
{
    return Object::sendMessage<VertexDescriptor*>(this, _MDL_PRIVATE_SEL(vertexDescriptor));
}
// write method: setVertexDescriptor:
_MDL_INLINE void MDL::Mesh::setVertexDescriptor(const VertexDescriptor* vertexDescriptor)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setVertexDescriptor_), vertexDescriptor);
}

// property: vertexCount
_MDL_INLINE NS::UInteger MDL::Mesh::vertexCount() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(vertexCount));
}
// write method: setVertexCount:
_MDL_INLINE void MDL::Mesh::setVertexCount(NS::UInteger vertexCount)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setVertexCount_), vertexCount);
}

// property: vertexBuffers
_MDL_INLINE NS::Array* MDL::Mesh::vertexBuffers() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(vertexBuffers));
}
// write method: setVertexBuffers:
_MDL_INLINE void MDL::Mesh::setVertexBuffers(const NS::Array* vertexBuffers)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setVertexBuffers_), vertexBuffers);
}

// property: allocator
_MDL_INLINE MDL::MeshBufferAllocator* MDL::Mesh::allocator() const
{
    return Object::sendMessage<MeshBufferAllocator*>(this, _MDL_PRIVATE_SEL(allocator));
}

// MARK: Mesh-Modifiers

// method: addAttributeWithName:format:
_MDL_INLINE void MDL::Mesh::addAttributeWithName(const NS::String* name,
                                                 VertexFormat format)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(addAttributeWithName_format_), name, format);
}

// method: addAttributeWithName:format:type:data:stride:
_MDL_INLINE void MDL::Mesh::addAttributeWithName(const NS::String* name,
                                                 VertexFormat format,
                                                 const NS::String* type,
                                                 const NS::Data* data,
                                                 NS::Integer stride)
{
    return Object::sendMessage<void>(this, 
                                     _MDL_PRIVATE_SEL(addAttributeWithName_format_type_data_stride_),
                                     name, format, type, data, stride);
}

// method: addAttributeWithName:format:type:data:stride:time:
_MDL_INLINE void MDL::Mesh::addAttributeWithName(const NS::String* name,
                                                 VertexFormat format,
                                                 const NS::String* type,
                                                 const NS::Data* data,
                                                 NS::Integer stride,
                                                 NS::TimeInterval time)
{
    return Object::sendMessage<void>(this,
                                     _MDL_PRIVATE_SEL(addAttributeWithName_format_type_data_stride_time_),
                                     name, format, type, data, stride, time);
}


// method: addNormalsWithAttributeNamed:creaseThreshold:
_MDL_INLINE void MDL::Mesh::addNormalsWithAttributeNamed(const NS::String* attributeName,
                                                         float creaseThreshold)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(addNormalsWithAttributeNamed_creaseThreshold_), attributeName, creaseThreshold);
}

// method: addTangentBasisForTextureCoordinateAttributeNamed:tangentAttributeNamed:bitangentAttributeNamed:
_MDL_INLINE void MDL::Mesh::addTangentBasisForTextureCoordinateAttributeNamed1(const NS::String* textureCoordinateAttributeName,
                                                                              const NS::String* tangentAttributeName,
                                                                              const NS::String* bitangentAttributeName)
{
    return Object::sendMessage<void>(this, 
                                     _MDL_PRIVATE_SEL(addTangentBasisForTextureCoordinateAttributeNamed_tangentAttributeNamed_bitangentAttributeNamed_),
                                     textureCoordinateAttributeName, tangentAttributeName, bitangentAttributeName);
}

// method: addTangentBasisForTextureCoordinateAttributeNamed:normalAttributeNamed:tangentAttributeNamed:
_MDL_INLINE void MDL::Mesh::addTangentBasisForTextureCoordinateAttributeNamed2(const NS::String* textureCoordinateAttributeName,
                                                                              const NS::String* normalAttributeName,
                                                                              const NS::String* tangentAttributeName)
{
    return Object::sendMessage<void>(this,
                                     _MDL_PRIVATE_SEL(addTangentBasisForTextureCoordinateAttributeNamed_normalAttributeNamed_tangentAttributeNamed_),
                                     textureCoordinateAttributeName, normalAttributeName, tangentAttributeName);
}

// method: addOrthTanBasisForTextureCoordinateAttributeNamed:normalAttributeNamed:tangentAttributeNamed:
_MDL_INLINE void MDL::Mesh::addOrthTanBasisForTextureCoordinateAttributeNamed(const NS::String* textureCoordinateAttributeName,
                                                                              const NS::String* normalAttributeName,
                                                                              const NS::String* tangentAttributeName)
{
    return Object::sendMessage<void>(this,
                                     _MDL_PRIVATE_SEL(addOrthTanBasisForTextureCoordinateAttributeNamed_normalAttributeNamed_tangentAttributeNamed_),
                                     textureCoordinateAttributeName, normalAttributeName, tangentAttributeName);
}

// method: addUnwrappedTextureCoordinatesForAttributeNamed:
_MDL_INLINE void MDL::Mesh::addUnwrappedTextureCoordinatesForAttributeNamed(const NS::String* textureCoordinateAttributeName)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(addUnwrappedTextureCoordinatesForAttributeNamed_), textureCoordinateAttributeName);
}

// method: flipTextureCoordinatesInAttributeNamed:
_MDL_INLINE void MDL::Mesh::flipTextureCoordinatesInAttributeNamed(const NS::String* textureCoordinateAttributeName)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(flipTextureCoordinatesInAttributeNamed_), textureCoordinateAttributeName);
}

// method: makeVerticesUnique
_MDL_INLINE void MDL::Mesh::makeVerticesUnique()
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(makeVerticesUnique));
}

// method: makeVerticesUniqueAndReturnError:
_MDL_INLINE BOOL MDL::Mesh::makeVerticesUniqueAndReturnError(NS::Error** error)
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(makeVerticesUniqueAndReturnError_), error);
}

// method: replaceAttributeNamed:
_MDL_INLINE void MDL::Mesh::replaceAttributeNamed(const NS::String* name,
                                                  const VertexAttributeData* newData)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(replaceAttributeNamed_), name, newData);
}

// method: updateAttributeNamed:
_MDL_INLINE void MDL::Mesh::updateAttributeNamed(const NS::String* name,
                                                  const VertexAttributeData* newData)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(updateAttributeNamed_), name, newData);
}

// method: removeAttributeNamed:
_MDL_INLINE void MDL::Mesh::removeAttributeNamed(const NS::String* name)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(removeAttributeNamed_), name);
}

// MARK: Mesh-Generators

// method: initBoxWithExtent:segments:inwardNormals:geometryType:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::initBoxWithExtent(vector_float3 extent,
                                                    vector_uint3 segments,
                                                    BOOL inwardNormals,
                                                    GeometryType geometryType,
                                                    class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(this,
                                      _MDL_PRIVATE_SEL(initBoxWithExtent_segments_inwardNormals_geometryType_allocator_),
                                      extent, segments, inwardNormals, geometryType, allocator);
}

// method: initSphereWithExtent:segments:inwardNormals:geometryType:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::initSphereWithExtent(vector_float3 extent,
                                                       vector_uint2 segments,
                                                       BOOL inwardNormals,
                                                       GeometryType geometryType,
                                                       class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(this,
                                      _MDL_PRIVATE_SEL(initSphereWithExtent_segments_inwardNormals_geometryType_allocator_),
                                      extent, segments, inwardNormals, geometryType, allocator);
}

// method: initHemisphereWithExtent:segments:inwardNormals:cap:geometryType:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::initHemisphereWithExtent(vector_float3 extent,
                                                           vector_uint2 segments,
                                                           BOOL inwardNormals,
                                                           BOOL cap,
                                                           GeometryType geometryType,
                                                           class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(this,
                                      _MDL_PRIVATE_SEL(initHemisphereWithExtent_segments_inwardNormals_cap_geometryType_allocator_),
                                      extent, segments, inwardNormals, cap, geometryType, allocator);
}

// method: initCylinderWithExtent:segments:inwardNormals:topCap:bottomCap:geometryType:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::initCylinderWithExtent(vector_float3 extent,
                                                         vector_uint2 segments,
                                                         BOOL inwardNormals,
                                                         BOOL topCap,
                                                         BOOL bottomCap,
                                                         GeometryType geometryType,
                                                         class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(this,
                                      _MDL_PRIVATE_SEL(initCylinderWithExtent_segments_inwardNormals_topCap_bottomCap_geometryType_allocator_),
                                      extent, segments, inwardNormals, topCap, bottomCap, geometryType, allocator);
}

// method: initCapsuleWithExtent:cylinderSegments:hemisphereSegments:inwardNormals:geometryType:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::initCapsuleWithExtent(vector_float3 extent,
                                                        vector_uint2 segments,
                                                        int hemisphereSegments,
                                                        BOOL inwardNormals,
                                                        GeometryType geometryType,
                                                        class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(this,
                                      _MDL_PRIVATE_SEL(initCapsuleWithExtent_cylinderSegments_hemisphereSegments_inwardNormals_geometryType_allocator_),
                                      extent, segments, hemisphereSegments, inwardNormals, geometryType, allocator);
}

// method: initConeWithExtent:segments:inwardNormals:geometryType:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::initConeWithExtent(vector_float3 extent,
                                                     vector_uint2 segments,
                                                     BOOL inwardNormals,
                                                     BOOL cap,
                                                     GeometryType geometryType,
                                                     class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(this,
                                      _MDL_PRIVATE_SEL(initConeWithExtent_segments_inwardNormals_geometryType_allocator_),
                                      extent, segments, inwardNormals, cap, geometryType, allocator);
}

// method: initPlaneWithExtent:segments:geometryType:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::initPlaneWithExtent(vector_float3 extent,
                                                      vector_uint2 segments,
                                                      GeometryType geometryType,
                                                      class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(this,
                                      _MDL_PRIVATE_SEL(initPlaneWithExtent_segments_geometryType_allocator_),
                                      extent, segments, geometryType, allocator);
}

// method: initIcosahedronWithExtent:segments:geometryType:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::initIcosahedronWithExtent(vector_float3 extent,
                                                            BOOL inwardNormals,
                                                            GeometryType geometryType,
                                                            class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(this,
                                      _MDL_PRIVATE_SEL(initIcosahedronWithExtent_segments_geometryType_allocator_),
                                      extent, inwardNormals, geometryType, allocator);
}

// method: initMeshBySubdividingMesh:submeshIndex:subdivisionLevels:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::initMeshBySubdividingMesh(const Mesh* mesh,
                                                            int submeshIndex,
                                                            unsigned int subdivisionLevels,
                                                            class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(this,
                                      _MDL_PRIVATE_SEL(initMeshBySubdividingMesh_submeshIndex_subdivisionLevels_allocator_),
                                      mesh, submeshIndex, subdivisionLevels, allocator);
}

// static method: newBoxWithDimensions:segments:geometryType:inwardNormals:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::newBoxWithDimensions(vector_float3 dimensions,
                                                       vector_uint3 segments,
                                                       GeometryType geometryType,
                                                       BOOL inwardNormals,
                                                       class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(_MDL_PRIVATE_CLS(MDLMesh),
                                      _MDL_PRIVATE_SEL(newBoxWithDimensions_segments_geometryType_inwardNormals_allocator_),
                                      dimensions, segments, geometryType, allocator);
}

// static method: newEllipsoidWithRadii:radialSegments:verticalSegments:geometryType:inwardNormals:hemisphere:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::newEllipsoidWithRadii(vector_float3 radii,
                                                        NS::UInteger radialSegments,
                                                        NS::UInteger verticalSegments,
                                                        GeometryType geometryType,
                                                        BOOL inwardNormals,
                                                        BOOL hemisphere,
                                                        class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(_MDL_PRIVATE_CLS(MDLMesh),
                                      _MDL_PRIVATE_SEL(newEllipsoidWithRadii_radialSegments_verticalSegments_geometryType_inwardNormals_hemisphere_allocator_),
                                      radii, radialSegments, verticalSegments, geometryType, inwardNormals, hemisphere, allocator);
}

// static method: newCylinderWithHeight:radii:radialSegments:verticalSegments:geometryType:inwardNormals:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::newCylinderWithHeight(float height,
                                                        vector_float2 radii,
                                                        NS::UInteger radialSegments,
                                                        NS::UInteger verticalSegments,
                                                        GeometryType geometryType,
                                                        BOOL inwardNormals,
                                                        class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(_MDL_PRIVATE_CLS(MDLMesh),
                                      _MDL_PRIVATE_SEL(newCylinderWithHeight_radii_radialSegments_verticalSegments_geometryType_inwardNormals_allocator_),
                                      height, radii, radialSegments, verticalSegments, geometryType, inwardNormals, allocator);
}

// static method: newCapsuleWithHeight:radii:radialSegments:verticalSegments:hemisphereSegments:geometryType:inwardNormals:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::newCapsuleWithHeight(float height,
                                                       vector_float2 radii,
                                                       NS::UInteger radialSegments,
                                                       NS::UInteger verticalSegments,
                                                       NS::UInteger hemisphereSegments,
                                                       GeometryType geometryType,
                                                       BOOL inwardNormals,
                                                       class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(_MDL_PRIVATE_CLS(MDLMesh),
                                      _MDL_PRIVATE_SEL(newCapsuleWithHeight_radii_radialSegments_verticalSegments_hemisphereSegments_geometryType_inwardNormals_allocator_),
                                      height, radii, radialSegments, verticalSegments, hemisphereSegments, geometryType, inwardNormals, allocator);
}

// static method: newEllipticalConeWithHeight:radii:radialSegments:verticalSegments:geometryType:inwardNormals:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::newEllipticalConeWithHeight(float height,
                                                              vector_float2 radii,
                                                              NS::UInteger radialSegments,
                                                              NS::UInteger verticalSegments,
                                                              GeometryType geometryType,
                                                              BOOL inwardNormals,
                                                              class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(_MDL_PRIVATE_CLS(MDLMesh),
                                      _MDL_PRIVATE_SEL(newEllipticalConeWithHeight_radii_radialSegments_verticalSegments_geometryType_inwardNormals_allocator_),
                                      height, radii, radialSegments, verticalSegments, geometryType, inwardNormals, allocator);
}

// static method: newPlaneWithDimensions:segments:geometryType:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::newPlaneWithDimensions(vector_float2 dimensions,
                                                         vector_uint2 segments,
                                                         GeometryType geometryType,
                                                         class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(_MDL_PRIVATE_CLS(MDLMesh),
                                      _MDL_PRIVATE_SEL(newPlaneWithDimensions_segments_geometryType_allocator_),
                                      dimensions, segments, geometryType, allocator);
}

// static method: newIcosahedronWithRadius:inwardNormals:geometryType:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::newIcosahedronWithRadius(float radius,
                                                           BOOL inwardNormals,
                                                           GeometryType geometryType,
                                                           class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(_MDL_PRIVATE_CLS(MDLMesh),
                                      _MDL_PRIVATE_SEL(newIcosahedronWithRadius_inwardNormals_geometryType_allocator_),
                                      radius, inwardNormals, geometryType, allocator);
}

// static method: newIcosahedronWithRadius:inwardNormals:allocator:
_MDL_INLINE MDL::Mesh* MDL::Mesh::newIcosahedronWithRadius(float radius,
                                                           BOOL inwardNormals,
                                                           class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<Mesh*>(_MDL_PRIVATE_CLS(MDLMesh),
                                      _MDL_PRIVATE_SEL(newIcosahedronWithRadius_inwardNormals_allocator_),
                                      radius, inwardNormals, allocator);
}

// static method: newSubdividedMesh:submeshIndex:subdivisionLevels:
_MDL_INLINE MDL::Mesh* MDL::Mesh::newSubdividedMesh(const Mesh* mesh,
                                                    NS::UInteger submeshIndex,
                                                    NS::UInteger subdivisionLevels)
{
    return Object::sendMessage<Mesh*>(_MDL_PRIVATE_CLS(MDLMesh),
                                      _MDL_PRIVATE_SEL(newSubdividedMesh_submeshIndex_subdivisionLevels_),
                                      mesh, submeshIndex, subdivisionLevels);
}

// MARK: Mesh-LighBaking

// method: generateAmbientOcclusionTextureWithSize:raysPerSample:attenuationFactor:objectsToConsider:vertexAttributeNamed:materialPropertyNamed:
_MDL_INLINE BOOL MDL::Mesh::generateAmbientOcclusionTextureWithSize(vector_int2 textureSize,
                                                                    NS::UInteger raysPerSample,
                                                                    float attenuationFactor,
                                                                    const NS::Array* objectsToConsider,
                                                                    const NS::String* vertexAttributeName,
                                                                    const NS::String* materialPropertyName)
{
    return Object::sendMessage<BOOL>(this,
                                     _MDL_PRIVATE_SEL(generateAmbientOcclusionTextureWithSize_raysPerSample_attenuationFactor_objectsToConsider_vertexAttributeNamed_materialPropertyNamed_),
                                     textureSize, raysPerSample, attenuationFactor, objectsToConsider, vertexAttributeName, materialPropertyName);
}

// method: generateAmbientOcclusionTextureWithQuality:attenuationFactor:objectsToConsider:vertexAttributeNamed:materialPropertyNamed:
_MDL_INLINE BOOL MDL::Mesh::generateAmbientOcclusionTextureWithQuality(float bakeQuality,
                                                                       float attenuationFactor,
                                                                       const NS::Array* objectsToConsider,
                                                                       const NS::String* vertexAttributeName,
                                                                       const NS::String* materialPropertyName)
{
    return Object::sendMessage<BOOL>(this,
                                     _MDL_PRIVATE_SEL(generateAmbientOcclusionTextureWithQuality_attenuationFactor_objectsToConsider_vertexAttributeNamed_materialPropertyNamed_),
                                     bakeQuality, attenuationFactor, objectsToConsider, vertexAttributeName, materialPropertyName);
}

// method: generateAmbientOcclusionVertexColorsWithRaysPerSample:attenuationFactor:objectsToConsider:vertexAttributeNamed:
_MDL_INLINE BOOL MDL::Mesh::generateAmbientOcclusionVertexColorsWithRaysPerSample(NS::Integer raysPerSample,
                                                                                  float attenuationFactor,
                                                                                  const NS::Array* objectsToConsider,
                                                                                  const NS::String* vertexAttributeName)
{
    return Object::sendMessage<BOOL>(this,
                                     _MDL_PRIVATE_SEL(generateAmbientOcclusionVertexColorsWithRaysPerSample_attenuationFactor_objectsToConsider_vertexAttributeNamed_),
                                     raysPerSample, attenuationFactor, objectsToConsider, vertexAttributeName);
}

// method: generateAmbientOcclusionVertexColorsWithQuality:attenuationFactor:objectsToConsider:vertexAttributeNamed:
_MDL_INLINE BOOL MDL::Mesh::generateAmbientOcclusionVertexColorsWithQuality(float bakeQuality,
                                                                            float attenuationFactor,
                                                                            const NS::Array* objectsToConsider,
                                                                            const NS::String* vertexAttributeName)
{
    return Object::sendMessage<BOOL>(this,
                                     _MDL_PRIVATE_SEL(generateAmbientOcclusionVertexColorsWithQuality_attenuationFactor_objectsToConsider_vertexAttributeNamed_),
                                     bakeQuality, attenuationFactor, objectsToConsider, vertexAttributeName);
}

// method: generateLightMapTextureWithTextureSize:lightsToConsider:objectsToConsider:vertexAttributeNamed:materialPropertyNamed:
_MDL_INLINE BOOL MDL::Mesh::generateLightMapTextureWithTextureSize(vector_int2 textureSize,
                                                                   const NS::Array* lightsToConsider,
                                                                   const NS::Array* objectsToConsider,
                                                                   const NS::String* vertexAttributeName,
                                                                   const NS::String* materialPropertyName)
{
    return Object::sendMessage<BOOL>(this,
                                     _MDL_PRIVATE_SEL(generateLightMapTextureWithTextureSize_lightsToConsider_objectsToConsider_vertexAttributeNamed_materialPropertyNamed_),
                                     textureSize, lightsToConsider, objectsToConsider, vertexAttributeName, materialPropertyName);
}

// method: generateLightMapTextureWithQuality:lightsToConsider:objectsToConsider:vertexAttributeNamed:materialPropertyNamed:
_MDL_INLINE BOOL MDL::Mesh::generateLightMapTextureWithQuality(float bakeQuality,
                                                               const NS::Array* lightsToConsider,
                                                               const NS::Array* objectsToConsider,
                                                               const NS::String* vertexAttributeName,
                                                               const NS::String* materialPropertyName)
{
    return Object::sendMessage<BOOL>(this,
                                     _MDL_PRIVATE_SEL(generateLightMapTextureWithQuality_lightsToConsider_objectsToConsider_vertexAttributeNamed_materialPropertyNamed_),
                                     bakeQuality, lightsToConsider, objectsToConsider, vertexAttributeName, materialPropertyName);
}

// method: generateLightMapVertexColorsWithLightsToConsider:objectsToConsider:vertexAttributeNamed:
_MDL_INLINE BOOL MDL::Mesh::generateLightMapVertexColorsWithLightsToConsider(const NS::Array* lightsToConsider,
                                                                             const NS::Array* objectsToConsider,
                                                                             const NS::String* vertexAttributeName)
{
    return Object::sendMessage<BOOL>(this,
                                     _MDL_PRIVATE_SEL(generateLightMapVertexColorsWithLightsToConsider_objectsToConsider_vertexAttributeNamed_),
                                     lightsToConsider, objectsToConsider, vertexAttributeName);
}





 






// MARK: - Original Header

//////#import <ModelIO/MDLTypes.h>
//////#import <ModelIO/MDLLight.h>
//////#import <ModelIO/MDLTransform.h>
//////#import <ModelIO/MDLSubmesh.h>
//////#import <ModelIO/MDLMeshBuffer.h>
//////#import <ModelIO/MDLVertexDescriptor.h>
//////
//////NS_ASSUME_NONNULL_BEGIN
//////
///////*!
////// @class MDLVertexAttributeData
////// @abstract convenience object to quickly access vertex attribute data
////// @discussion created by MDLMesh's vertexAttributeData selector
//////             Setting values on this object has no effect on the
//////             underlying objects.
////// */
//////
//////API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//////MDL_EXPORT
//////@interface MDLVertexAttributeData : NSObject
//////
//////@property (nonatomic, retain) MDLMeshBufferMap *map;
//////@property (nonatomic) void *dataStart;
//////@property (nonatomic) NSUInteger stride;
//////@property (nonatomic) MDLVertexFormat format;
//////@property (nonatomic) NSUInteger bufferSize API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//////
//////@end
////
////
/////////*!
//////// @class MDLMesh
//////// @abstract A vertex buffer with info to interpret vertex data
//////// @discussion Includes a collection of submeshs which have indexbuffer and
////////             material information
//////// */
////////API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
////////MDL_EXPORT
////////@interface MDLMesh : MDLObject
////////
/////////*!
//////// @method initWithAllocator:
//////// @abstract Initialize a mesh with an allocator
//////// @return An empty mesh
////////*/
////////
////////- (instancetype)initWithBufferAllocator:(nullable id<MDLMeshBufferAllocator>)bufferAllocator;
////////
/////////*!
//////// @method initWithVertexBuffer:vertexCount:descriptor:submeshes:
//////// @abstract Initialize object with a vertex buffer and a collection of submeshes
//////// @return Initialized mesh or nil if descriptor's layout array does not describe
////////         a single buffer
//////// @param vertexBuffer MDLMeshBuffer object containing all vertex data for the mesh
//////// @param vertexCount Number of vertices in the vertexBuffer
//////// @param descriptor VertexDescriptor specifying how to interpret vertex data
//////// @param submeshes Array of submeshes with index buffers referencing vertex data
////////        and/or materials to be applied to mesh
//////// */
////////- (instancetype)initWithVertexBuffer:(id<MDLMeshBuffer>)vertexBuffer
////////                         vertexCount:(NSUInteger)vertexCount
////////                          descriptor:(MDLVertexDescriptor *)descriptor
////////                           submeshes:(NSArray<MDLSubmesh*> *)submeshes;
////////
/////////*!
//////// @method initWithVertexBuffer:vertexCount:descriptor:submeshes:
//////// @abstract Initialize object with an array of vertex buffers (Structure of
////////           Arrays) and a collection of submeshes
//////// @return Initialized mesh or nil if descriptor's layout array is incompatible
////////         with vertexBuffers array
//////// @param vertexCount Number of vertices in vertexBuffers
//////// @param descriptor VertexDescriptor specifying how to interpret vertex data
//////// @param submeshes Array of submeshes with index buffers referencing vertex data
////////        and/or materials to be applied to mesh
//////// @discussion Allows initialization with the layout of the vertexBuffers in a
////////        structure-of-arrays form, in other words, non-interleaved vertex attributes
//////// */
////////- (instancetype)initWithVertexBuffers:(NSArray<id<MDLMeshBuffer>> *)vertexBuffers
////////                          vertexCount:(NSUInteger)vertexCount
////////                           descriptor:(MDLVertexDescriptor *)descriptor
////////                            submeshes:(NSArray<MDLSubmesh*> *)submeshes;
////////
/////////*!
//////// @method vertexAttributeDataForAttributeNamed:
//////// @abstract convenience selector to get quick access to vertex attribute data
//////// @discussion the vertex buffer will remain mapped until the MDLVertexAttributeData
////////             is freed.
//////// */
////////- (nullable MDLVertexAttributeData*)vertexAttributeDataForAttributeNamed:(NSString*)name;
////////
/////////*!
//////// @method vertexAttributeDataForAttributeNamed:asFormat
//////// @abstract convenience selector to get quick access to vertex attribute data
////////           reformatted to the requested format if necessary.
//////// @discussion If the desired format has less elements than the source attribute
////////             elements, excess elements will be discarded. If the desired format
////////             has more elements than the source attribute, then the destination
////////             elements will be set to zero.
////////             The vertex buffer will remain mapped until the MDLVertexAttributeData
////////             is freed.
//////// */
////////- (nullable MDLVertexAttributeData*)vertexAttributeDataForAttributeNamed:(NSString*)name
////////                                                                asFormat:(MDLVertexFormat)format;
////////
/////////*!
//////// @property boundingBox
//////// @abstract Bounding box encompasing the mesh
//////// @discussion Calculated by iterating through MDLVertexAttributePosition to find
////////             min and max bounds. If no attribute is named MDLVertexAttributePosition
////////             this will be a invalid bounds where maxBounds is less than minBounds.
//////// */
////////@property (nonatomic, readonly) MDLAxisAlignedBoundingBox boundingBox;
////////
/////////*!
//////// @property vertexDescriptor
//////// @abstract Immutable vertex descriptor for interpreting data in vertexBuffers
//////// @discussion Setting this applies the new layout in 'vertexBuffers' thus is a
////////             heavyweight operation as structured copies of almost all vertex
////////             buffer data could be made.  Additionally, if the new vertexDescriptor
////////             does not have an attribute in the original vertexDescriptor, that
////////             attribute will be deleted.  If the original vertexDescriptor does
////////             not have an attribute in the new vertexDescriptor, the data for the
////////             added attribute set as the added attribute's initializationValue
////////             property.
////////
////////             The allocator associated with each original meshbuffer is used to
////////             reallocate the corresponding resultant meshbuffer.
//////// */
////////@property (nonatomic, readwrite, copy) MDLVertexDescriptor *vertexDescriptor;
//////
///////*!
////// @property vertexCount
////// @abstract Number of vertices in the vertexBuffers
////// @discussion The size of vertex data in each buffer can be computed by multiplying
//////             this value with the stride of the buffer in the vertexDescriptor's
//////             layout
////// */
//////@property (nonatomic, readwrite) NSUInteger vertexCount;
//////
///////*!
////// @property vertexBuffers
////// @abstract Array of buffers containing vertex data
////// @discussion The vertex buffers in this array are indexed by the vertex descriptor.
////// */
//////@property (nonatomic, readwrite, retain) NSArray<id<MDLMeshBuffer>> *vertexBuffers;
//////
///////*!
////// @property submeshes
////// @abstract Array of submeshes containing an indexbuffer referencing the vertex
//////           data and material to be applied when the mesh is rendered
////// */
//////@property (nonatomic, copy, nullable) NSMutableArray<MDLSubmesh*> *submeshes;
//////
///////*!
////// @property allocator
////// @abstract allocator used to allocate contained mesh buffers
////// */
//////@property (nonatomic, readonly, retain) id<MDLMeshBufferAllocator> allocator;
//////
//////@end
////
////
//////@interface MDLMesh (Modifiers)
//////
///////*!
////// @method addAttributeWithName:format
////// @abstract Convenience method to add an attribute
////// @discussion The mesh's allocator will be used to create storage for the new
//////             attribute.
////// */
//////- (void)addAttributeWithName:(NSString*)name
//////                      format:(MDLVertexFormat)format;
//////
///////*!
////// @method addAttributeWithName:format:type:data:stride
////// @abstract Create a new vertex attribute including an associated buffer with
//////           a copy of the supplied data, and update the vertex descriptor accordingly
////// @param name The name the attribute can be found by
////// @param format Format of the data, such as MDLVertexFormatFloat3
////// @param type The usage of the attribute, such as MDLVertexAttributePosition
////// @param data Object containing the data to be used in the new vertex buffer
////// @param stride The increment in bytes from the start of one data entry to
//////        the next.
////// */
//////-(void)addAttributeWithName:(NSString *)name
//////                     format:(MDLVertexFormat)format
//////                       type:(NSString *)type
//////                       data:(NSData *)data
//////                     stride:(NSInteger)stride;
//////
///////*!
////// @method addAttributeWithName:format:type:data:stride:time
////// @abstract Create a new vertex attribute including an associated buffer with
//////           a copy of the supplied data, and update the vertex descriptor accordingly
////// @param name The name the attribute can be found by
////// @param format Format of the data, such as MDLVertexFormatFloat3
////// @param type The usage of the attribute, such as MDLVertexAttributePosition
////// @param data Object containing the data to be used in the new vertex buffer
////// @param stride The increment in bytes from the start of one data entry to
//////        the next.
////// @param time The time the attribute is to be invoked at.
////// @discussion Adding an attribute, such as position data, at multiple times will
//////             result in attributes being created for each of those times.
//////             Attributes corresponding to multiple times can be retrieved from
//////             the vertex descriptor.
////// */
//////-(void)addAttributeWithName:(NSString *)name
//////                     format:(MDLVertexFormat)format
//////                       type:(NSString *)type
//////                       data:(NSData *)data
//////                     stride:(NSInteger)stride
//////                       time:(NSTimeInterval)time;
//////
///////*!
////// @method addNormalsWithAttributeNamed:creaseThreshold:
////// @abstract Calculate and add vertex normal data
////// @param attributeName Name is the attribute name of vertex normal attribute.  If nil, vertex normals
//////        will be added with the MDLVertexAttributeNormal name string
////// @param creaseThreshold Threshold of the dot product between the 2 triangles after which
//////                        their face normal will be smoothed out. Therefore, a threshold of 0 will
//////                        smooth everything and a threshold of 1 won't smooth anything.
////// @discussion Uses the attribute named MDLVertexAttributePosition to calculate
//////             vertex normals. If the mesh does not have an attribute with
//////             'attributeName', it will be added, otherwise the attribute name will
//////             be overwritten with vertex normal data. 'vertexDescriptor' will be
//////             updated to reflect the new attribute.
////// */
//////- (void)addNormalsWithAttributeNamed:(nullable NSString *)attributeName
//////                     creaseThreshold:(float)creaseThreshold;
//////
//////
/*!
 @method addTangentBasisForTextureCoordinateAttributeNamed:tangentAttributeNamed:bitangentAttributeNamed
 @abstract Create a shader basis where the tangent and bitangent span the uv -> object space transform
 @param textureCoordinateAttributeName Name of texture coordinates to use in calculations
 @param tangentAttributeName Name of vertex tangent attribute.
 @param bitangentAttributeName Name of vertex bitangent attribute.
 @discussion Uses the attribute named MDLVertexAttributePosition and
             textureCoordinateAttributeName to calculate tangent and bitangent
             attributes. The mesh's vertexDescriptor will be updated to reflect
             the new attributes if necessary. The basis may not be orthogonal; to gaurantee an orthogonal
              tangent basis please use addOrthTanBasisForTextureCoordinateAttibuteNamed selector.
 */
//- (void)addTangentBasisForTextureCoordinateAttributeNamed:(NSString*)textureCoordinateAttributeName
//                                    tangentAttributeNamed:(NSString *)tangentAttributeName
//                                  bitangentAttributeNamed:(nullable NSString *)bitangentAttributeName;
//
///*!
// @method addTangentBasisForTextureCoordinateAttributeNamed:normalAttributeNamed:tangentAttributeNamed
// @abstract Create tangents which are orthogonal to the normal
// @param textureCoordinateAttributeName texture coordinates to use in calculations
// @param normalAttributeName normals to use in calculations
// @param tangentAttributeName Name of a four component vertex tangent attribute.
// @discussion Uses the attribute named MDLVertexAttributePosition and
//             textureCoordinateAttributeName and the specified normals to calculate
//             tangent information. The mesh's vertexDescriptor will be updated to
//             reflect the new attribute if necessary.
//             Note that this method does NOT produce a T.w component which is used in B = (N x T) * T.w
//             Please use addOrthTanBasisForTextureCoordinateAttributeNamed.
// */
//- (void)addTangentBasisForTextureCoordinateAttributeNamed:(NSString*)textureCoordinateAttributeName
//                                     normalAttributeNamed:(NSString*)normalAttributeName
//                                    tangentAttributeNamed:(NSString *)tangentAttributeName;

///////*
//////@method addOrthTanBasisForTextureCoordinateAttributeNamed:normalAttributeNamed:tangentAttributeNamed
//////@abstract Create an orthonormal tangent basis with tangent specified
//////@param textureCoordinateAttributeName texture coordinates to use in calculations
//////@param normalAttributeName normals to use in calculations
//////@param tangentAttributeName Name of a three/four component vertex tangent attribute.
//////@discussion Uses the attribute named MDLVertexAttributePosition and
//////            textureCoordinateAttributeName and the specified normals to calculate
//////            tangent information. The mesh's vertexDescriptor will be updated to
//////            reflect the new attribute if necessary.
//////            Note that the bitangent can be calculated from the normal and
//////            tangent by B = (N x T) * T.w
//////*/
//////- (void)addOrthTanBasisForTextureCoordinateAttributeNamed:(NSString *)textureCoordinateAttributeName
//////                                     normalAttributeNamed:(NSString *)normalAttributeName
//////                                    tangentAttributeNamed:(NSString *)tangentAttributeName API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//////
///////*!
////// @method addTextureCoordinatesForAttributeNamed:textureCoordinateAttributeName
////// @abstract Creates texture coordinates by unwrapping the mesh
////// @param textureCoordinateAttributeName texture coordinates to modify or create
////// @discussion Uses the attribute named MDLVertexAttributePosition and if available,
//////             the attribute named MDLVertexAttributeNormal to calculate texture coordinates
////// */
//////- (void)addUnwrappedTextureCoordinatesForAttributeNamed:(NSString*)textureCoordinateAttributeName;
//////
//////
///////*!
////// @method flipTextureCoordinatesInAttributeNamed:
////// @abstract Flips texture coordinates by performing the operation (u,v) = (u, 1-v)
////// @param textureCoordinateAttributeName texture coordinates to modify
////// @discussion Many application generate model files with texture coordinate mapping
//////             assuming a bottom left bitmap origin. It can be more convenient to
//////             have texture coordinates corresponding to an upper left bitmap origin.
//////             This selector will perform the flip operation if the requested texture
//////             coordinate attribute exists on the mesh. An exception will be raised if
//////             the attribute cannot be found
////// */
//////- (void)flipTextureCoordinatesInAttributeNamed:(NSString*)textureCoordinateAttributeName API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//////
///////*!
////// @method makeVerticesUnique:
////// @abstract Deindexes the vertex array
////// @discussion If any vertices are shared on multiple faces, duplicate those
//////             vertices so faces do not share vertices. The vertex buffer and index
//////             buffers on submeshes may grow to accomadate any vertices added.
////// */
//////- (void)makeVerticesUnique NS_DEPRECATED(10.11,10.13,9.0,11.0);
////
////
/////*!
//// @method makeVerticesUniqueAndReturnError:
//// @abstract Deindexes the vertex array
//// @discussion If any vertices are shared on multiple faces, duplicate those
//// vertices so faces do not share vertices. The vertex buffer and index
//// buffers on submeshes may grow to accomadate any vertices added.
//// */
//////- (BOOL)makeVerticesUniqueAndReturnError:(NSError **)error API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//////
///////*!
////// @method replaceAttributeNamed:withData
////// @abstract replace existing attribute data with new attribute data retaining
////// the format of the replacement data.
////// @discussion If the specified attribute does not already exist, it will be
////// created.
////// */
//////- (void)replaceAttributeNamed:(NSString*)name
//////                     withData:(nonnull MDLVertexAttributeData*)newData;
//////
///////*!
////// @method updateAttributeNamed:withData
////// @abstract update existing attribute data with new attribute data retaining
////// the format of the existing data.
////// @discussion If the specified attribute does not already exist, it will be
////// created with the same format as the newData.
////// */
//////- (void)updateAttributeNamed:(NSString*)name
//////                    withData:(nonnull MDLVertexAttributeData*)newData;
//////
///////*!
////// @method removeAttributeNamed:
////// @abstract remove an attribute
////// @discussion if the named attribute does not exist, nothing happens.
////// */
//////- (void)removeAttributeNamed:(NSString*)name;
//////
//////
//////@end
////
////
////
////@interface MDLMesh (Generators)
////
/////*!
//// @method initBoxMeshWithExtent:segments:inwardNormals:geometryType:allocator:
//// @abstract Factory method for generating a mesh with a cube shape
//// @return MDLMesh box with desired attributes
//// @param extent size of the box in each dimension
//// @param segments Number of slices in each dimension
//// @param inwardNormals Generated Normal point inward
//// @param geometryType Can be MDLGeometryTypeLines, MDLGeometryTypeQuads, or MDLGeometryTypeTriangles
//// @param allocator A mesh buffer allocator used to allocate memory to back buffers
////        for the returned mesh.  If nil, a default allocator will be used
//// @discussion Assembled with triangle or quad primitives.  Specifying inward
////             normals is useful for generating a skybox. The center of the box
////             is at(0, 0, 0).
////             Will raise an exception if an unsupported geometry type is passed in.
//// */
////- (instancetype)initBoxWithExtent:(vector_float3)extent
////                             segments:(vector_uint3)segments
////                        inwardNormals:(BOOL)inwardNormals
////                         geometryType:(MDLGeometryType)geometryType
////                            allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////
////
/////*!
//// @method initSphereWithExtent:segments:inwardNormals:geometryType:allocator
//// @abstract Factory method for generating a mesh with an ellipsoid shape
//// @return MDLMesh epllipsoid with desired attributes
//// @param geometryType Must be MDLGeometryTypeTriangles or MDLGeometryTypeLines
//// @param inwardNormals If true, generated normals will face inwards. Useful for
////        generating a skydome.
////        actual nubmer of vertical slices will be half of 'vertical' segments
//// @param allocator A mesh buffer allocator used to allocate memory to back buffers
////        for the returned mesh.  If nil, a default allocator will be used
//// @discussion Specifying inward normals and hemisphere is useful for generating a skydome.
////             Specifying equal X, Y, and Z radii will generate a sphere.
////             Specifying a y radius of 0.0 will generate a disc.
////             Will raise an exception if radialSegments is < 3, verticalSegments is < 2,
////             or an unsupported geometry type is passed in.
//// */
////- (instancetype)initSphereWithExtent:(vector_float3)extent
////                            segments:(vector_uint2)segments
////                       inwardNormals:(BOOL)inwardNormals
////                        geometryType:(MDLGeometryType)geometryType
////                           allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////- (instancetype)initHemisphereWithExtent:(vector_float3)extent
////                                segments:(vector_uint2)segments
////                           inwardNormals:(BOOL)inwardNormals
////                                     cap:(BOOL)cap
////                            geometryType:(MDLGeometryType)geometryType
////                               allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////
/////*!
//// @method initCylinderWithExtent:segments:inwardNormals:topCap:bottomCap:geometryType:allocator
//// @abstract Factory method for generating a mesh with a cylindrical shape
//// @return MDLMesh cylinder with desired attributes
//// @param geometryType Must be MDLGeometryTypeTriangles or MDLGeometryTypeLines
//// @param inwardNormals Normals point toward center of cylinder
//// @param allocator A mesh buffer allocator used to allocate memory to back buffers
////        for the returned mesh.  If nil, a default allocator will be used
//// @discussion Center of cylinder at (0, 0, 0) with a top at +Y and bottom at -Y.
////             Specifying equal X and Z radia will generate a true cylinder.
////             Specifying a height of 0.0 and verticalSegments of 0 will generate
////             a disc.
////             Will raise an exception if radialSegments is < 3 or if an unsupported
////             geometry type is passed in.
////             Generated texture coordinates are laid out as follows:
////                                                      ___
////                                                     /   \   <- T texcoord = 0.0
////                 Texture for top of cylinder   ---> [     ]
////                                                     \___/
////                                                    [     ]  <- T texcoord = 0.3333
////                                                    [     ]
////                 Texture for sides of cylinder ---> [     ]
////                                                    [_____]  <- T texcoord = 0.6666
////                                                     /   \
////                 Texture for base of cylinder  ---> [     ]
////                                                     \___/   <- T texcoord = 1.0
//// */
////- (instancetype)initCylinderWithExtent:(vector_float3)extent
////                              segments:(vector_uint2)segments
////                         inwardNormals:(BOOL)inwardNormals
////                                topCap:(BOOL)topCap
////                             bottomCap:(BOOL)bottomCap
////                          geometryType:(MDLGeometryType)geometryType
////                             allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
//
///*!
// @method initCapsuleWithExtent:cylinderSegments:hemisphereSegments:inwardNormals:geometryType:allocator
// @abstract Factory method for generating a mesh with a capsule shape; a cylinder
//           with hemispheres for caps.
// @return MDLMesh capsule with desired attributes
// @param extent Dimension of bounding box for capsule.
// @param hemisphereSegments Number of slices through hemisphere caps along Y axis
// @param geometryType Must be MDLGeometryTypeTriangles or MDLGeometryTypeLines
// @param inwardNormals Normals point toward center of cylinder
// @param allocator A mesh buffer allocator used to allocate memory to back buffers
//        for the returned mesh.  If nil, a default allocator will be used
// @discussion Center of capsule at (0, 0, 0) with a top at +Y and bottom at -Y.
//             The height of hemisphere cap is specified by the minimum of X and Z
//             Specifying equal X and Z radii will generate a true capsule.
//             Specifying a height that is less than the twice of min of the X and Z
//             radii or verticalSegments of 0 will generate a sphere. The full height
//             of the capsule will also incorporate the hemisphere caps.
//             Will raise an exception if radialSegments is < 3 or if hemisphereSegments < 1
//             or if an unsupported geometry type is specified.
//             Generated texture coordinates for top and bottom caps are wrapped
//             in a similar manner as for asphere, laid out as follows:
//                                      ___
//                                     /   \   <- T texcoord = 0.0
// Texture for top of cylinder   ---> [-----]
//                                    [     ]  <- T texcoord = extent.x/extent.y
//                                    [     ]
// Texture for sides of cylinder ---> [     ]
//                                    [_____]  <- T texcoord = 1.0 - extent.x/extent.y
// Texture for base of cylinder  ---> [     ]
//                                     \___/   <- T texcoord = 1.0
//*/
////- (instancetype)initCapsuleWithExtent:(vector_float3)extent
////                     cylinderSegments:(vector_uint2)segments
////                   hemisphereSegments:(int)hemisphereSegments
////                        inwardNormals:(BOOL)inwardNormals
////                         geometryType:(MDLGeometryType)geometryType
////                            allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////
/////*!
//// @method initConeWithExtent:segments:inwardNormals:cap:geometryType:allocator
//// @abstract Factory method for generating a mesh with an ellipticalCone shape.
//// @return MDLMesh cone with desired attributes
//// @param geometryType Must be MDLGeometryTypeTriangles or MDLGeometryTypeLines
//// @param inwardNormals Normals point toward center of ellipticalCone
//// @param allocator A mesh buffer allocator used to allocate memory to back buffers
////        for the returned mesh.  If nil, a default allocator will be used
//// @discussion Point of cone at (0, 0, 0) while base of cone is -Y.
////             Will raise an exception if radialSegments is < 3, or verticalSegments is < 1,
////             or if an unsupported geometry type is passed in.
////             Generated texture coordinates are laid out as follows:
////                                                 _____
////                                                [     ]  <- T texcoord = 0.0
////                                                [     ]
////                 Texture for sides of cone ---> [     ]
////                                                [     ]
////                                                [_____]  <- T texcoord = 0.6666
////                                                 /   \
////                 Texture for base of cone  ---> [     ]
////                                                 \___/   <- T texcoord = 1.0
//// */
////- (instancetype)initConeWithExtent:(vector_float3)extent
////                          segments:(vector_uint2)segments
////                     inwardNormals:(BOOL)inwardNormals
////                               cap:(BOOL)cap
////                      geometryType:(MDLGeometryType)geometryType
////                         allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////
/////*!
//// @method initPlaneWithExtent:segments:geometryType:allocator
//// @abstract Factory method for generating a mesh with an planar shape
//// @return MDLMesh plane with desired attributes
//// @param extent extent of the plane
//// @param segments Number of segements in the X and Y dimensions
//// @param geometryType Can be MDLGeometryTypeLines, MDLGeometryTypeQuads, or MDLGeometryTypeTriangles
//// @param allocator A mesh buffer allocator used to allocate memory to back buffers
////        for the returned mesh.  If nil, a default allocator will be used
//// @discussion Creates a plane spanning the greatest dimensions of extent.
////             Will raise an exception if an unsupported geometry type is passed in.
//// */
////- (instancetype)initPlaneWithExtent:(vector_float3)extent
////                           segments:(vector_uint2)segments
////                       geometryType:(MDLGeometryType)geometryType
////                          allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////
/////*!
//// @method initIcosahedronWithExtent:inwardNormals:geometryType:allocator
//// @abstract Factory method for generating a mesh icosahedron
//// @return MDLMesh icosahedron with desired attributes
//// @param inwardNormals Generated normals will face towards the center of the mesh
//// @param allocator A mesh buffer allocator used to allocate memory to back buffers
////        for the returned mesh.  If nil, a default allocator will be used
//// @discussion  Creates an icosahedron with center at (0, 0, 0).
//// */
////- (instancetype)initIcosahedronWithExtent:(vector_float3)extent
////                            inwardNormals:(BOOL)inwardNormals
////                             geometryType:(MDLGeometryType)geometryType
////                                allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
//
///*!
// @method initMeshBySubdividingMesh:submeshIndex:subdivisionLevels:allocator
// @abstract Factory method that generates a subdivided mesh from a source mesh
// @param mesh Mesh from which to generate a subdivided mesh
// @param submeshIndex Index of submesh in Mesh's submesh array from which to
//        generate a subdivided mesh
// @param subdivisionLevels The number of levels to subdivide mesh
// @discussion Subdivision levels over four are likely to generate more triangles
//             than can be reasonably displayed. Index and vertex data will use
//             the same allocator used for the source mesh. Loading an asset
//             using the topology preservation flag set to YES will result in the
//             best subdivision results.
// @return Returns a mesh subdivided to index level, unless subdivision is
//         impossible.
// */
////- (instancetype)initMeshBySubdividingMesh:(MDLMesh*)mesh
////                             submeshIndex:(int)submeshIndex
////                        subdivisionLevels:(unsigned int)subdivisionLevels
////                                allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////
////+ (instancetype)newBoxWithDimensions:(vector_float3)dimensions
////                            segments:(vector_uint3)segments
////                        geometryType:(MDLGeometryType)geometryType
////                       inwardNormals:(BOOL)inwardNormals
////                           allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////+ (instancetype)newEllipsoidWithRadii:(vector_float3)radii
////                       radialSegments:(NSUInteger)radialSegments
////                     verticalSegments:(NSUInteger)verticalSegments
////                         geometryType:(MDLGeometryType)geometryType
////                        inwardNormals:(BOOL)inwardNormals
////                           hemisphere:(BOOL)hemisphere
////                            allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////+ (instancetype)newCylinderWithHeight:(float)height
////                                radii:(vector_float2)radii
////                       radialSegments:(NSUInteger)radialSegments
////                     verticalSegments:(NSUInteger)verticalSegments
////                         geometryType:(MDLGeometryType)geometryType
////                        inwardNormals:(BOOL)inwardNormals
////                            allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////+ (instancetype)newCapsuleWithHeight:(float)height
////                               radii:(vector_float2)radii
////                      radialSegments:(NSUInteger)radialSegments
////                    verticalSegments:(NSUInteger)verticalSegments
////                  hemisphereSegments:(NSUInteger)hemisphereSegments
////                        geometryType:(MDLGeometryType)geometryType
////                       inwardNormals:(BOOL)inwardNormals
////                           allocator:(nullable id<MDLMeshBufferAllocator>)allocator API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
////+ (instancetype)newEllipticalConeWithHeight:(float)height
////                                      radii:(vector_float2)radii
////                             radialSegments:(NSUInteger)radialSegments
////                           verticalSegments:(NSUInteger)verticalSegments
////                               geometryType:(MDLGeometryType)geometryType
////                              inwardNormals:(BOOL)inwardNormals
////                                  allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////+ (instancetype)newPlaneWithDimensions:(vector_float2)dimensions
////                              segments:(vector_uint2)segments
////                          geometryType:(MDLGeometryType)geometryType
////                             allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////+ (instancetype)newIcosahedronWithRadius:(float)radius
////                           inwardNormals:(BOOL)inwardNormals
////                            geometryType:(MDLGeometryType)geometryType
////                               allocator:(nullable id<MDLMeshBufferAllocator>)allocator API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
////+ (instancetype)newIcosahedronWithRadius:(float)radius
////                           inwardNormals:(BOOL)inwardNormals
////                               allocator:(nullable id<MDLMeshBufferAllocator>)allocator;
////+ (nullable instancetype)newSubdividedMesh:(MDLMesh*)mesh
////                              submeshIndex:(NSUInteger)submeshIndex
////                         subdivisionLevels:(NSUInteger)subdivisionLevels;
////
////@end
//
//
//@interface MDLMesh (MDLLightBaking)
//
///*!
// @method generateAmbientOcclusionTextureWithSize:
// @abstract Creates an Ambient Occlusion texture, returns true upon success, false
//           upon failure
// @param textureSize Texture Size in which to bake the ambient occlusion
// @param raysPerSample Number of rays to be sent out of every texture texel against
//        the object for potential occlusion.
// @param attenuationFactor Float between 0 to 1 that defines how to attenuate the
//        AO value. 0 doesn't change it, and at 1, all AO values are white except
//        if they are originally completely black. Quadratic attenuation in between.
// @param objectsToConsider NSArray of MDLMeshes containing the objects to raytrace against
// @param vertexAttributeName NSString of the MDLVertexAttribute where the vertex
//        texture UVs will be stored. Creates it if it doesn't exist, otherwise
//        overwrites current values.
// @param materialPropertyName NSString of the MDLMaterialProperty that will store
//        the texture in the Mesh.
// @result Success or failure of the baking process.
// */
//- (BOOL)generateAmbientOcclusionTextureWithSize:(vector_int2)textureSize
//                                  raysPerSample:(NSInteger)raysPerSample
//                              attenuationFactor:(float)attenuationFactor
//                              objectsToConsider:(NSArray<MDLObject*>*)objectsToConsider
//                           vertexAttributeNamed:(NSString *)vertexAttributeName
//                          materialPropertyNamed:(NSString *)materialPropertyName;

/*!
 @method generateAmbientOcclusionTextureWithQuality:
 @abstract Creates an Ambient Occlusion texture, returns true upon success, false
           upon failure
 @param bakeQuality Float between 0 and 1 that defines quality of the bake process.
        0 is of lower quality but bakes faster and uses less memory, where 1 is
        of higher quality.
 @param attenuationFactor Float between 0 to 1 that defines how to attenuate the
        AO value. 0 doesn't change it, and at 1, all AO values are white except
        if they are originally completely black. Quadratic attenuation in between.
 @param objectsToConsider NSArray of MDLMeshes containing the objects to raytrace
        against
 @param vertexAttributeName NSString of the MDLVertexAttribute where the vertex
        texture UVs will be stored. Creates it if it doesn't exist, otherwise
        overwrites current values.
 @param materialPropertyName NSString of the MDLMaterialProperty that will store
        the texture in the Mesh.
 @result Success or failure of the baking process.
  */
//- (BOOL)generateAmbientOcclusionTextureWithQuality:(float)bakeQuality
//                                 attenuationFactor:(float)attenuationFactor
//                                 objectsToConsider:(NSArray<MDLObject*>*)objectsToConsider
//                              vertexAttributeNamed:(NSString *)vertexAttributeName
//                             materialPropertyNamed:(NSString *)materialPropertyName;

//- (BOOL)generateAmbientOcclusionVertexColorsWithRaysPerSample:(NSInteger)raysPerSample
//                                            attenuationFactor:(float)attenuationFactor
//                                            objectsToConsider:(NSArray<MDLObject*>*)objectsToConsider
//                                         vertexAttributeNamed:(NSString *)vertexAttributeName;

//- (BOOL)generateAmbientOcclusionVertexColorsWithQuality:(float)bakeQuality
//                                      attenuationFactor:(float)attenuationFactor
//                                      objectsToConsider:(NSArray<MDLObject*>*)objectsToConsider
//                                   vertexAttributeNamed:(NSString *)vertexAttributeName;

//- (BOOL)generateLightMapTextureWithTextureSize:(vector_int2)textureSize
//                              lightsToConsider:(NSArray<MDLLight*>*)lightsToConsider
//                             objectsToConsider:(NSArray<MDLObject*>*)objectsToConsider
//                          vertexAttributeNamed:(NSString *)vertexAttributeName
//                         materialPropertyNamed:(NSString *)materialPropertyName;

//- (BOOL)generateLightMapTextureWithQuality:(float)bakeQuality
//                          lightsToConsider:(NSArray<MDLLight*>*)lightsToConsider
//                         objectsToConsider:(NSArray<MDLObject*>*)objectsToConsider
//                      vertexAttributeNamed:(NSString *)vertexAttributeName
//                     materialPropertyNamed:(NSString *)materialPropertyName;

//- (BOOL)generateLightMapVertexColorsWithLightsToConsider:(NSArray<MDLLight*>*)lightsToConsider
//                                       objectsToConsider:(NSArray<MDLObject*>*)objectsToConsider
//                                    vertexAttributeNamed:(NSString *)vertexAttributeName;
//
//@end
//
//NS_ASSUME_NONNULL_END

