/*!
 @header MDLSubmesh.hpp
 @framework ModelIO
 @abstract Structures for describing renderable elements of a mesh
 @copyright Treata Norouzi on 8/17/24.
 */


#include "MDLTypes.hpp"
#include "MDLMaterial.hpp"
#include "MDLMeshBuffer.hpp"

namespace MDL
{
class Submesh; // Forward-declaration of Submesh

class SubmeshTopology : public NS::Referencing<SubmeshTopology>
{
public:
    static class SubmeshTopology*   alloc();
    
    // initWithSubmesh:
    class SubmeshTopology*          init(const Submesh* submesh);
    
    class MeshBuffer*               faceTopology() const;
    void                            setFaceTopology(const class MeshBuffer* faceTopology);
    
    NS::UInteger                    faceCount() const;
    void                            setFaceCount(NS::UInteger faceCount);
    
    class MeshBuffer*               vertexCreaseIndices() const;
    void                            setVertexCreaseIndices(const class MeshBuffer* vertexCreaseIndices);
    
    class MeshBuffer*               vertexCreases() const;
    void                            setVertexCreases(const class MeshBuffer* vertexCreases);
    
    NS::UInteger                    vertexCreaseCount() const;
    // !!!: Unnecessary probably
    void                            setVertexCreaseCount(NS::UInteger vertexCreaseCount);
    
    class MeshBuffer*               holes() const;
    void                            setHoles(const class MeshBuffer* holes);
    
    NS::UInteger                    holeCount() const;
    // !!!: Unnecessary probably
    void                            setHoleCount(NS::UInteger holeCount);
};

class Submesh : public NS::Referencing<MDL::Named>
{
public:
    static class Submesh*   alloc();
    
    // initWithName:indexBuffer:indexCount:indexType:geometryType:material:
    class Submesh*          init(const NS::String* name,
                                 const class MeshBuffer* indexBuffer,
                                 NS::UInteger indexCount,
                                 IndexBitDepth indexType,
                                 GeometryType geometryType,
                                 const Material* material);
    
    // initWithIndexBuffer:indexCount:indexType:geometryType:material:
    class Submesh*          init(const NS::String* name,
                                 NS::UInteger indexCount,
                                 IndexBitDepth indexType,
                                 GeometryType geometryType,
                                 const Material* material);
    
    // initWithName:indexBuffer:indexCount:indexType:geometryType:material:topology:
    class Submesh*          init(const NS::String* name,
                                 const class MeshBuffer* indexBuffer,
                                 NS::UInteger indexCount,
                                 IndexBitDepth indexType,
                                 GeometryType geometryType,
                                 const Material* material,
                                 const SubmeshTopology* topology);
    
    // initWithMDLSubmesh:indexType:geometryType:
    class Submesh*          init(const Submesh* submesh,
                                 IndexBitDepth indexType,
                                 GeometryType geometryType);
    
    // - Readonly
    class MeshBuffer*       indexBuffer() const;
    
    // indexBufferAsIndexType:
    class MeshBuffer*       indexBufferAsIndexType(IndexBitDepth indexType);
    
    NS::UInteger            indexCount() const;
    
    IndexBitDepth           indexType() const;
    
    GeometryType            geometryType() const;
    
    Material*               material() const;
    void                    setMaterial(const Material* material);
    
    SubmeshTopology*        topology() const;
    void                    setTopology(const SubmeshTopology* topology);
    
    NS::String*             name() const;
    void                    setName(const NS::String* name);
};

}

// MARK: - Private Sector

// static method: alloc
_MDL_INLINE MDL::SubmeshTopology* MDL::SubmeshTopology::alloc()
{
    return NS::Object::alloc<MDL::SubmeshTopology>(_MDL_PRIVATE_CLS(MDLSubmeshTopology));
}

// method: initWithSubmesh:
_MDL_INLINE MDL::SubmeshTopology* MDL::SubmeshTopology::init(const Submesh* submesh)
{
    return Object::sendMessage<SubmeshTopology*>(this, _MDL_PRIVATE_SEL(initWithSubmesh_), submesh);
}

// property: faceTopology
_MDL_INLINE MDL::MeshBuffer* MDL::SubmeshTopology::faceTopology() const
{
    return Object::sendMessage<MeshBuffer*>(this, _MDL_PRIVATE_SEL(faceTopology));
}
// write method: setFaceTopology:
_MDL_INLINE void MDL::SubmeshTopology::setFaceTopology(const class MeshBuffer* faceTopology)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFaceTopology_), faceTopology);
}

// property: faceCount
_MDL_INLINE NS::UInteger MDL::SubmeshTopology::faceCount() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(faceCount));
}
// write method: setFaceCount:
_MDL_INLINE void MDL::SubmeshTopology::setFaceCount(NS::UInteger faceCount)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFaceCount_), faceCount);
}

// property: vertexCreaseIndices
_MDL_INLINE MDL::MeshBuffer* MDL::SubmeshTopology::vertexCreaseIndices() const
{
    return Object::sendMessage<MeshBuffer*>(this, _MDL_PRIVATE_SEL(vertexCreaseIndices));
}
// write method: setVertexCreaseIndices:
_MDL_INLINE void MDL::SubmeshTopology::setVertexCreaseIndices(const class MeshBuffer* vertexCreaseIndices)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setVertexCreaseIndices_), vertexCreaseIndices);
}

// property: vertexCreases
_MDL_INLINE MDL::MeshBuffer* MDL::SubmeshTopology::vertexCreases() const
{
    return Object::sendMessage<MeshBuffer*>(this, _MDL_PRIVATE_SEL(vertexCreases));
}
// write method: setVertexCreases:
_MDL_INLINE void MDL::SubmeshTopology::setVertexCreases(const class MeshBuffer* vertexCreases)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setVertexCreases_), vertexCreases);
}

// property: vertexCreaseCount
_MDL_INLINE NS::UInteger MDL::SubmeshTopology::vertexCreaseCount() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(vertexCreaseCount));
}
// write method: setVertexCreaseCount:
_MDL_INLINE void MDL::SubmeshTopology::setVertexCreaseCount(NS::UInteger vertexCreaseCount)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setVertexCreaseCount_), vertexCreaseCount);
}

// property: holes
_MDL_INLINE MDL::MeshBuffer* MDL::SubmeshTopology::holes() const
{
    return Object::sendMessage<MeshBuffer*>(this, _MDL_PRIVATE_SEL(holes));
}
// write method: setHoles:
_MDL_INLINE void MDL::SubmeshTopology::setHoles(const class MeshBuffer* holes)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setHoles_), holes);
}

// property: holeCount
_MDL_INLINE NS::UInteger MDL::SubmeshTopology::holeCount() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(holeCount));
}
// write method: setHoleCount:
_MDL_INLINE void MDL::SubmeshTopology::setHoleCount(NS::UInteger holeCount)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setHoleCount_), holeCount);
}

// MARK: Class Submesh

// static method: alloc
_MDL_INLINE MDL::Submesh* MDL::Submesh::alloc()
{
    return NS::Object::alloc<MDL::Submesh>(_MDL_PRIVATE_CLS(MDLSubmesh));
}

// method: initWithName:indexBuffer:indexCount:indexType:geometryType:material:
_MDL_INLINE MDL::Submesh* MDL::Submesh::init(const NS::String* name,
                                             const class MeshBuffer* indexBuffer,
                                             NS::UInteger indexCount,
                                             IndexBitDepth indexType,
                                             GeometryType geometryType,
                                             const Material* material)
{
    return Object::sendMessage<Submesh*>(this,
                                         _MDL_PRIVATE_SEL(initWithName_indexBuffer_indexCount_indexType_geometryType_material_),
                                         name, indexBuffer, indexCount, indexType, geometryType, material);
}

// method: initWithIndexBuffer:indexCount:indexType:geometryType:material:
_MDL_INLINE MDL::Submesh* MDL::Submesh::init(const NS::String* name,
                                             NS::UInteger indexCount,
                                             IndexBitDepth indexType,
                                             GeometryType geometryType,
                                             const Material* material)
{
    return Object::sendMessage<Submesh*>(this,
                                         _MDL_PRIVATE_SEL(initWithIndexBuffer_indexCount_indexType_geometryType_material_),
                                         name, indexCount, indexType, geometryType, material);
}

// method: initWithName:indexBuffer:indexCount:indexType:geometryType:material:topology:
_MDL_INLINE MDL::Submesh* MDL::Submesh::init(const NS::String* name,
                                             const class MeshBuffer* indexBuffer,
                                             NS::UInteger indexCount,
                                             IndexBitDepth indexType,
                                             GeometryType geometryType,
                                             const Material* material,
                                             const SubmeshTopology* topology)
{
    return Object::sendMessage<Submesh*>(this,
                                         _MDL_PRIVATE_SEL(initWithName_indexBuffer_indexCount_indexType_geometryType_material_topology_),
                                         name, indexBuffer, indexCount, indexType, geometryType, material, topology);
}

// method: initWithMDLSubmesh:indexType:geometryType:
_MDL_INLINE MDL::Submesh* MDL::Submesh::init(const Submesh* submesh,
                                             IndexBitDepth indexType,
                                             GeometryType geometryType)
{
    return Object::sendMessage<Submesh*>(this,
                                         _MDL_PRIVATE_SEL(initWithMDLSubmesh_indexType_geometryType_),
                                         submesh, indexType, geometryType);
}

// property: indexBuffer
_MDL_INLINE MDL::MeshBuffer* MDL::Submesh::indexBuffer() const
{
    return Object::sendMessage<MeshBuffer*>(this, _MDL_PRIVATE_SEL(indexBuffer));
}

// method: indexBufferAsIndexType:
_MDL_INLINE MDL::MeshBuffer* MDL::Submesh::indexBufferAsIndexType(IndexBitDepth indexType)
{
    return Object::sendMessage<MeshBuffer*>(this, _MDL_PRIVATE_SEL(indexBufferAsIndexType_), indexType);
}

// property: indexCount
_MDL_INLINE NS::UInteger MDL::Submesh::indexCount() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(indexCount));
}

// property: indexType
_MDL_INLINE MDL::IndexBitDepth MDL::Submesh::indexType() const
{
    return Object::sendMessage<IndexBitDepth>(this, _MDL_PRIVATE_SEL(indexType));
}

// property: geometryType
_MDL_INLINE MDL::GeometryType MDL::Submesh::geometryType() const
{
    return Object::sendMessage<GeometryType>(this, _MDL_PRIVATE_SEL(geometryType));
}

// property: material
_MDL_INLINE MDL::Material* MDL::Submesh::material() const
{
    return Object::sendMessage<MDL::Material*>(this, _MDL_PRIVATE_SEL(material));
}
// write method: setMaterial:
_MDL_INLINE void MDL::Submesh::setMaterial(const Material* material)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setMaterial_), material);
}

// property: topology
_MDL_INLINE MDL::SubmeshTopology* MDL::Submesh::topology() const
{
    return Object::sendMessage<MDL::SubmeshTopology*>(this, _MDL_PRIVATE_SEL(topology));
}
// write method: setTopology:
_MDL_INLINE void MDL::Submesh::setTopology(const SubmeshTopology* topology)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setTopology_), topology);
}

// property: name
_MDL_INLINE NS::String* MDL::Submesh::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}
// write method: setName:
_MDL_INLINE void MDL::Submesh::setName(const NS::String* name)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setName_), name);
}

// MARK: - Original Header

//#import <ModelIO/MDLTypes.h>
//#import <ModelIO/MDLMaterial.h>
//#import <ModelIO/MDLMeshBuffer.h>
//
//NS_ASSUME_NONNULL_BEGIN
//
//@class MDLSubmesh;
//
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLSubmeshTopology : NSObject
//
///*!
// @method initWithSubmesh:
// @abstract create a topology object corresponding to the topology in the submesh
// */
//- (instancetype) initWithSubmesh:(MDLSubmesh*)submesh;
//
///*!
// @property faceTopologyBuffer
// @abstract A buffer of 8 bit unsigned integer values, where each entry corresponds
// to the number of vertices making up a face.
// 
// @discussion A submesh containing two triangles, a four sided polygon, and a
// line, would contain the data 3 3 4 2.
// If geometryType is of a fixed type, such as triangles, the buffer
// is optional, and will be created on demand if read.
// 
// Indices to the vertex buffer will be stored in the index buffer
// correspondingly. In the example above, the indices would be stored
// in order, three indices for the first triangle, followed by three
// for the second, followed by four for the polygon, and finally two
// indices for the line.
// */
//@property (nonatomic, retain, nullable) id<MDLMeshBuffer> faceTopology;
//
///*!
// @property faceCount
// @abstract The number of faces encoded in faceTopologyBuffer
// */
//@property (nonatomic) NSUInteger faceCount;
//
///*! A crease value at a vertex to be applied during subdivision. Vertex creases
// A zero value is smooth, a one value is peaked. It is intended to be used
// with an index buffer, where the index buffer entries are vertex indices.
// The corresponding values in the corner sharpness attribute indicate the
// corner sharpness of those vertices. The index buffer is sparse. If a mesh
// has three sharp vertices, then the index buffer will have three entries.
// Since the number of entries in this vertex buffer is likely to be different
// than the number of entries in any other vertex buffer, it shouldn't be
// interleaved with other data.
// */
//@property (nonatomic, retain, nullable) id<MDLMeshBuffer> vertexCreaseIndices;
//@property (nonatomic, retain, nullable) id<MDLMeshBuffer> vertexCreases;
//
///*!
// @property vertexCreaseCount
// @abstract The number of vertex creases encoded in vertexCreases
// */
//@property (nonatomic) NSUInteger vertexCreaseCount;
//
///*! A crease value at an edge to be applied during subdivision. Edge creases
// A zero value is smooth, a one value is peaked. It is intended to be used
// with an index buffer, where the index buffer entries are edge index pairs.
// Accordingly, there will be two index entries for each edge sharpness entry,
// and the sharpness entry corresponds to the edge itself.
// The corresponding values in the edge sharpness attribute indicate the
// edge sharpness of those edges.  The index buffer is sparse. If a mesh
// has three sharp edges, then the index buffer will have six entries.
// Since the number of entries in this vertex buffer is likely to be different
// than the number of entries in any other vertex buffer, it shouldn't be
// interleaved with other data.
// */
//@property (nonatomic, retain, nullable) id<MDLMeshBuffer> edgeCreaseIndices;
//@property (nonatomic, retain, nullable) id<MDLMeshBuffer> edgeCreases;
//
///*!
// @property edgeCreaseCount
// @abstract The number of edge creases encoded in edgeCreases
// */
//@property (nonatomic) NSUInteger edgeCreaseCount;
//
///*! The hole attribute is a vertex attribute of single integer values where
// each integer is an index of a face that is to be used as a hole. If there
// are two holes in a mesh, then the vertex buffer will have two entries.
// Since the number of entries in this vertex buffer is likely to be different
// than the number of entries in any other vertex buffer, it shouldn't be
// interleaved with other data.
// */
//@property (nonatomic, retain, nullable) id<MDLMeshBuffer> holes;
//
///*!
// @property holeCount
// @abstract The number of holes encoded in holes
// */
//@property (nonatomic) NSUInteger holeCount;
//
//@end

/*!
 @class MDLSubmesh
 @abstract A drawable subset of an MDLMesh, with its own material
 */
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLSubmesh : NSObject<MDLNamed>
//
///*!
// @method initWithName:indexBuffer:indexCount:indexType:geometryType:material:
// @abstract Initialize submesh with all data necessary to make properties valid
// */
//- (instancetype)initWithName:(NSString *)name
//                 indexBuffer:(id<MDLMeshBuffer>)indexBuffer
//                  indexCount:(NSUInteger)indexCount
//                   indexType:(MDLIndexBitDepth)indexType
//                geometryType:(MDLGeometryType)geometryType
//                    material:(nullable MDLMaterial *)material;
//
///*!
// @method initWithIndexBuffer:indexCount:indexType:geometryType:material:
// @abstract Initialize submesh with all data necessary to make properties valid
// */
//- (instancetype)initWithIndexBuffer:(id<MDLMeshBuffer>)indexBuffer
//                         indexCount:(NSUInteger)indexCount
//                          indexType:(MDLIndexBitDepth)indexType
//                       geometryType:(MDLGeometryType)geometryType
//                           material:(nullable MDLMaterial *)material;
//
///*!
// @method initWithIndexBuffer:indexCount:indexType:faceTopologyBuffer:geometryType:material:
// @abstract Initialize submesh with all data necessary to make properties valid
// 
// @discussion The geometry type will typically be MDLGeometryTypeVariableTopology,
//             if other types are used the faceTopologyBuffer contents should
//             reflect that.
// */
//- (instancetype)initWithName:(NSString *)name
//                 indexBuffer:(id<MDLMeshBuffer>)indexBuffer
//                  indexCount:(NSUInteger)indexCount
//                   indexType:(MDLIndexBitDepth)indexType
//                geometryType:(MDLGeometryType)geometryType
//                    material:(nullable MDLMaterial *)material
//                    topology:(nullable MDLSubmeshTopology *)topology;
//
///*!
// @method initWithMDLSubmesh:indexType:geometryType:
// @abstract Initialize submesh using another submesh as input.
// @discussion the resulting submesh will have a new index type if necessary.
//  If a conversion from the source submesh's geometry type to the requested
//  geometry type is possible, conversion will be performed. Otherwise nil will
//  be returned.
// */
//- (nullable instancetype)initWithMDLSubmesh:(nonnull MDLSubmesh*)submesh
//                                  indexType:(MDLIndexBitDepth)indexType
//                               geometryType:(MDLGeometryType)geometryType;

/*!
 @property indexBuffer
 @abstract Index data referencing vertex data in parent mesh
 */
//@property (nonatomic, readonly, retain) id<MDLMeshBuffer> indexBuffer;
//
//- (id<MDLMeshBuffer>)indexBufferAsIndexType:(MDLIndexBitDepth)indexType;
//
///*!
// @property indexCount
// @abstract Number of indices in the indexBuffer
// */
//@property (nonatomic, readonly) NSUInteger indexCount;
//
///*!
// @property indexType
// @abstract Data type of indices in indexBuffer
// @discussion Support 8, 16, and 32 bit unsigned integer values
// */
//@property (nonatomic, readonly) MDLIndexBitDepth indexType;
//
///*!
// @property geometryType
// @abstract Type of primitive that vertices referenced by the indexBuffer are
//           assembled into
// */
//@property (nonatomic, readonly) MDLGeometryType geometryType;
//
///*!
// @property material
// @abstract Material to apply when rendering this object
// */
//@property (nonatomic, retain, nullable) MDLMaterial *material;
//
///*!
// @property topology
// @abstract Topology data structure for use with MDLGeometryTypeVariableTopology
// 
// @discussion ignored for geometry types other than MDLGeometryTypeVariableTopology.
//             A submesh of type MDLGeometryTypeVariableTopology with no topology
//             data is an empty submesh.
//*/
//@property (nonatomic, retain, nullable) MDLSubmeshTopology *topology;
//
///*!
// @property name
// @abstract Identifying name for this object
// */
//@property (nonatomic, copy) NSString *name;
//
//@end
//
//NS_ASSUME_NONNULL_END

