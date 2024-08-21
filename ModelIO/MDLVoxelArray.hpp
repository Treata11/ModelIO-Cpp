/*!
 @header MDLVoxelArray.hpp
 @framework ModelIO
 @abstract Structures for describing volumetric data obtained from 3d assets
 @copyright Treata Norouzi on 8/16/24.
 */


#include "MDLTypes.hpp"
#include "MDLMeshBuffer.hpp"
#include "MDLObject.hpp"
#include "MDLAssetResolver.hpp"
#include <simd/simd.h>

namespace MDL
{
// !!!: Uncertain
using VoxelIndex = vector_int4;

struct VoxelIndexExtent
{
    VoxelIndex minimumExtent;
    VoxelIndex maximumExtent;
};

class Mesh; // Forward-declaration

class VoxelArray : public NS::Referencing<Object>
{
    static class VoxelArray*        alloc();
    
    // initWithAsset:divisions:patchRadius:
    class VoxelArray*               init(const MDL::Asset* asset, int divisions, float patchRadius);
    
    // initWithData:boundingBox:voxelExtent:
    class VoxelArray*               init(const NS::Data* voxelData,
                                         MDL::AxisAlignedBoundingBox boundingBox,
                                         float voxelExtent);
    
    // initWithAsset:divisions:interiorShells:exteriorShells:patchRadius:
    class VoxelArray*               init(const MDL::Asset* asset,
                                         int divisions,
                                         int interiorShells,
                                         int exteriorShells,
                                         float patchRadius);
    
    // - Readonly
    NS::UInteger                    count() const;
    
    VoxelIndexExtent                voxelIndexExtent() const;
    
    // voxelExistsAtIndex:allowAnyX:allowAnyY:allowAnyZ:allowAnyShell:
    BOOL                            voxelExistsAtIndex(VoxelIndex index,
                                                       BOOL allowAnyX, BOOL allowAnyY, BOOL allowAnyZ,
                                                       BOOL allowAnyShell);
    
    
    // voxelsWithinExtent:
    NS::Data*                       voxelsWithinExtent(VoxelIndexExtent extent);
    
    NS::Data*                       voxelIndices();
    
    // setVoxelAtIndex:
    void                            setVoxelAtIndex(VoxelIndex index);
    
    // setVoxelsForMesh:divisions:patchRadius:
    void                            setVoxelsForMesh(const Mesh* mesh, int divisions, float patchRadius);
    
    // setVoxelsForMesh:divisions:interiorShells:exteriorShells:patchRadius:
    void                            setVoxelsForMesh(const Mesh* mesh, 
                                                     int divisions,
                                                     int interiorShells,
                                                     int exteriorShells,
                                                     float patchRadius);
    
    // setVoxelsForMesh:divisions:interiorNBWidth:exteriorNBWidth:patchRadius:
    void                            setVoxelsForMesh(const Mesh* mesh,
                                                     int divisions,
                                                     float interiorNBWidth,
                                                     float exteriorNBWidth,
                                                     float patchRadius);
    
    // unionWithVoxels:
    void                            unionWithVoxels(const VoxelArray* voxels);
    
    // intersectWithVoxels:
    void                            intersectWithVoxels(const VoxelArray* voxels);
    
    // differenceWithVoxels:
    void                            differenceWithVoxels(const VoxelArray* voxels);
    
    AxisAlignedBoundingBox          boundingBox() const;
    
    // indexOfSpatialLocation:
    VoxelIndex                      indexOfSpatialLocation(vector_float3 location);
    
    // spatialLocationOfIndex:
    vector_float3                   spatialLocationOfIndex(VoxelIndex index);
    
    // voxelBoundingBoxAtIndex:
    AxisAlignedBoundingBox          voxelBoundingBoxAtIndex(VoxelIndex index);
    
    // convertToSignedShellField
    void                            convertToSignedShellField();
    
    BOOL                            isValidSignedShellField() const;
    
    float                           shellFieldInteriorThickness() const;
    void                            setShellFieldInteriorThickness(float shellFieldInteriorThickness);
    
    float                           shellFieldExteriorThickness() const;
    void                            setShellFieldExteriorThickness(float shellFieldExteriorThickness);
    
    // !!!: Uncertain about the next 3
    // coarseMesh:
    class Mesh*                     coarseMesh();
    
    // coarseMeshUsingAllocator:
    class Mesh*                     coarseMeshUsingAllocator(const class MeshBufferAllocator* allocator);
    
    // meshUsingAllocator:
    class Mesh*                     meshUsingAllocator(const class MeshBufferAllocator* allocator);
    
};

}

// MARK: - Private Sector

// static method: alloc
_MDL_INLINE MDL::VoxelArray* MDL::VoxelArray::alloc()
{
    return NS::Object::alloc<MDL::VoxelArray>(_MDL_PRIVATE_CLS(MDLVoxelArray));
}

// method: initWithAsset:divisions:patchRadius:
_MDL_INLINE MDL::VoxelArray* MDL::VoxelArray::init(const MDL::Asset* asset, int divisions, float patchRadius)
{
    return Object::sendMessage<MDL::VoxelArray*>(this, _MDL_PRIVATE_SEL(initWithAsset_divisions_patchRadius_), asset, divisions, patchRadius);
}

// method: initWithData:boundingBox:voxelExtent:
_MDL_INLINE MDL::VoxelArray* MDL::VoxelArray::init(const NS::Data* voxelData, MDL::AxisAlignedBoundingBox boundingBox, float voxelExtent)
{
    return Object::sendMessage<MDL::VoxelArray*>(this, _MDL_PRIVATE_SEL(initWithData_boundingBox_voxelExtent_), voxelData, boundingBox, voxelExtent);
}

// initWithAsset:divisions:interiorShells:exteriorShells:patchRadius:
_MDL_INLINE MDL::VoxelArray* MDL::VoxelArray::init(const MDL::Asset* asset,
                                                   int divisions,
                                                   int interiorShells,
                                                   int exteriorShells,
                                                   float patchRadius)
{
    return Object::sendMessage<MDL::VoxelArray*>(this,
                                                 _MDL_PRIVATE_SEL(initWithAsset_divisions_interiorShells_exteriorShells_patchRadius_),
                                                 asset, divisions, interiorShells, exteriorShells, patchRadius);
}

// property: count
_MDL_INLINE NS::UInteger MDL::VoxelArray::count() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(count));
}

// property: voxelIndexExtent
_MDL_INLINE MDL::VoxelIndexExtent MDL::VoxelArray::voxelIndexExtent() const
{
    return Object::sendMessage<VoxelIndexExtent>(this, _MDL_PRIVATE_SEL(voxelIndexExtent));
}

// method: voxelExistsAtIndex:allowAnyX:allowAnyY:allowAnyZ:allowAnyShell:
_MDL_INLINE BOOL MDL::VoxelArray::voxelExistsAtIndex(VoxelIndex index,
                                                     BOOL allowAnyX, BOOL allowAnyY, BOOL allowAnyZ,
                                                     BOOL allowAnyShell)
{
    return Object::sendMessage<BOOL>(this,
                                     _MDL_PRIVATE_SEL(voxelExistsAtIndex_allowAnyX_allowAnyY_allowAnyZ_allowAnyShell_),
                                     index,
                                     allowAnyX, allowAnyY, allowAnyZ,
                                     allowAnyShell);
}

// method: voxelsWithinExtent:
_MDL_INLINE NS::Data* MDL::VoxelArray::voxelsWithinExtent(VoxelIndexExtent extent)
{
    return Object::sendMessage<NS::Data*>(this, _MDL_PRIVATE_SEL(voxelsWithinExtent_), extent);
}

// method: voxelIndices
_MDL_INLINE NS::Data* MDL::VoxelArray::voxelIndices()
{
    return Object::sendMessage<NS::Data*>(this, _MDL_PRIVATE_SEL(voxelIndices));
}

// method: setVoxelAtIndex
_MDL_INLINE void MDL::VoxelArray::setVoxelAtIndex(VoxelIndex index)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setVoxelAtIndex_), index);
}

// method: setVoxelsForMesh:divisions:patchRadius:
_MDL_INLINE void MDL::VoxelArray::setVoxelsForMesh(const Mesh* mesh, int divisions, float patchRadius)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setVoxelsForMesh_divisions_patchRadius_), index);
}

// method: setVoxelsForMesh:divisions:interiorShells:exteriorShells:patchRadius:
_MDL_INLINE void MDL::VoxelArray::setVoxelsForMesh(const Mesh* mesh,
                                                   int divisions,
                                                   int interiorShells,
                                                   int exteriorShells,
                                                   float patchRadius)
{
    return Object::sendMessage<void>(this,
                                     _MDL_PRIVATE_SEL(setVoxelsForMesh_divisions_interiorShells_exteriorShells_patchRadius_),
                                     mesh, divisions, interiorShells, exteriorShells, patchRadius);
}

// method: setVoxelsForMesh:divisions:interiorNBWidth:exteriorNBWidth:patchRadius:
_MDL_INLINE void MDL::VoxelArray::setVoxelsForMesh(const Mesh* mesh,
                                                   int divisions,
                                                   float interiorNBWidth,
                                                   float exteriorNBWidth,
                                                   float patchRadius)
{
    return Object::sendMessage<void>(this,
                                     _MDL_PRIVATE_SEL(setVoxelsForMesh_divisions_interiorNBWidth_exteriorNBWidth_patchRadius_),
                                     mesh, divisions, interiorNBWidth, exteriorNBWidth, patchRadius);
}

// method: unionWithVoxels:
_MDL_INLINE void MDL::VoxelArray::unionWithVoxels(const VoxelArray* voxels)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(unionWithVoxels_), voxels);
}

// method: intersectWithVoxels:
_MDL_INLINE void MDL::VoxelArray::intersectWithVoxels(const VoxelArray* voxels)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(intersectWithVoxels_), voxels);
}

// method: differenceWithVoxels:
_MDL_INLINE void MDL::VoxelArray::differenceWithVoxels(const VoxelArray* voxels)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(differenceWithVoxels_), voxels);
}

// property: boundingBox
_MDL_INLINE MDL::AxisAlignedBoundingBox MDL::VoxelArray::boundingBox() const
{
    return Object::sendMessage<AxisAlignedBoundingBox>(this, _MDL_PRIVATE_SEL(boundingBox));
}

// method: indexOfSpatialLocation:
_MDL_INLINE MDL::VoxelIndex MDL::VoxelArray::indexOfSpatialLocation(vector_float3 location)
{
    return Object::sendMessage<VoxelIndex>(this, _MDL_PRIVATE_SEL(indexOfSpatialLocation_), location);
}

// method: spatialLocationOfIndex:
_MDL_INLINE vector_float3 MDL::VoxelArray::spatialLocationOfIndex(VoxelIndex index)
{
    return Object::sendMessage<vector_float3>(this, _MDL_PRIVATE_SEL(spatialLocationOfIndex_), index);
}

// method: voxelBoundingBoxAtIndex:
_MDL_INLINE MDL::AxisAlignedBoundingBox MDL::VoxelArray::voxelBoundingBoxAtIndex(VoxelIndex index)
{
    return Object::sendMessage<AxisAlignedBoundingBox>(this, _MDL_PRIVATE_SEL(voxelBoundingBoxAtIndex_), index);
}

// method: convertToSignedShellField:
_MDL_INLINE void MDL::VoxelArray::convertToSignedShellField()
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(convertToSignedShellField_));
}

// property: isValidSignedShellField
_MDL_INLINE BOOL MDL::VoxelArray::isValidSignedShellField() const
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(isValidSignedShellField));
}

// property: shellFieldInteriorThickness
_MDL_INLINE float MDL::VoxelArray::shellFieldInteriorThickness() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(shellFieldInteriorThickness));
}
// write method: setShellFieldInteriorThickness:
_MDL_INLINE void MDL::VoxelArray::setShellFieldInteriorThickness(float shellFieldInteriorThickness)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setShellFieldInteriorThickness_), shellFieldInteriorThickness);
}

// property: shellFieldExteriorThickness
_MDL_INLINE float MDL::VoxelArray::shellFieldExteriorThickness() const
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(shellFieldExteriorThickness));
}
// write method: setShellFieldExteriorThickness:
_MDL_INLINE void MDL::VoxelArray::setShellFieldExteriorThickness(float shellFieldExteriorThickness)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setShellFieldExteriorThickness_), shellFieldExteriorThickness);
}

// method: coarseMesh
_MDL_INLINE MDL::Mesh* MDL::VoxelArray::coarseMesh()
{
    return Object::sendMessage<MDL::Mesh*>(this, _MDL_PRIVATE_SEL(coarseMesh));
}

// method: coarseMeshUsingAllocator:
_MDL_INLINE MDL::Mesh* MDL::VoxelArray::coarseMeshUsingAllocator(const class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<MDL::Mesh*>(this, _MDL_PRIVATE_SEL(coarseMeshUsingAllocator_), allocator);
}

// method: meshUsingAllocator:
_MDL_INLINE MDL::Mesh* MDL::VoxelArray::meshUsingAllocator(const class MeshBufferAllocator* allocator)
{
    return Object::sendMessage<MDL::Mesh*>(this, _MDL_PRIVATE_SEL(meshUsingAllocator_), allocator);
}






// MARK: - Original Header

//#import <ModelIO/MDLTypes.h>
//#import <ModelIO/MDLMeshBuffer.h>
//#import <ModelIO/MDLObject.h>
//#import <simd/simd.h>
//
//NS_ASSUME_NONNULL_BEGIN
//
//@class MDLAsset;
//@class MDLMesh;

/**
 MDLVoxelIndex is a four component voxel index.
 @discussion The index's x, y, and z components correspond to the voxel grid's
 x, y, and z indices. The w component corresponds to the voxel grid shell level.
 A shell level of zero corresponds to a voxel on the surface of an object.
 A positive shell index corresponds to a shell on the exterior of the object,
 and a negative index corresponds to a shell on the interior. A shell index of
 one is immediately adjacent to the zero shell, two is immediately adjacent
 one, and so on.
 */
//typedef vector_int4 MDLVoxelIndex;
//
///**
// MDLVoxelIndexExtent is the index space bounds of the voxel grid.
// */
//typedef struct {
//    MDLVoxelIndex minimumExtent;
//    MDLVoxelIndex maximumExtent;
//} MDLVoxelIndexExtent;

/**
 @class MDLVoxelArray
 @summary Voxel data represented on a three dimensional grid. Voxel data can
          include voxels considered to be on the surface of an object, and a
          series of shells on the outside and inside of the surface.
 */

//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLVoxelArray : MDLObject

/**
 Initialize a voxel grid from an MDLAsset. Attempts to create a closed volume
 model by applying "patches" of radius patchRadius to any holes found in the
 orginal mesh. Choose a patch radius that will be large enough to fill in the largest
 hole in the model.
 */
//- (instancetype)initWithAsset:(MDLAsset*)asset divisions:(int)divisions patchRadius:(float)patchRadius;

/**
 Initialize a voxel grid from an NSData containing an array of MDLVoxelIndex values.
 
 @param boundingBox The bounds defining the extent of the volume model in Cartesian space
 @param voxelExtent The extent of a single voxel
 */
//- (instancetype)initWithData:(NSData*)voxelData
//                 boundingBox:(MDLAxisAlignedBoundingBox)boundingBox
//                 voxelExtent:(float)voxelExtent;

/**
 Initialize a voxel grid from an MDLAsset and dilate the resulting voxels by
 a number of interior and exterior shells.
 Routine will attempt to create a closed volume model by applying patches of
 a given radius to any holes it may find in the asset.
 
 @param divisions The number of divisions to divide the vertical extent of the
 model by.
 @param interiorShells The number of shells to compute inside the surface shell
 @param exteriorShells The number of shells to compute outside the surface shell
 @param patchRadius The radius of the largest model mending patch in world space units
 */
//- (instancetype)initWithAsset:(MDLAsset*)asset
//                    divisions:(int)divisions
//               interiorShells:(int)interiorShells
//               exteriorShells:(int)exteriorShells
//                  patchRadius:(float)patchRadius NS_DEPRECATED(10_11, 10_12, NA, NA);

/**
 Initialize a voxel grid from an MDLAsset and dilate the resulting voxels by
 a spatial distance in the interior and exterior directions.
 Routine will attempt to create a closed volume model by applying "patches" of
 a given radius to any holes it may find in the asset.
 
 @param divisions The number of divisions to divide the vertical extent of the
 model by.
 @param interiorNBWidth The interior narrow band width in world space units
 @param exteriorNBWidth The exterior narrow band width in world space units
 @param patchRadius The radius of the largest model mending patch in world space units
 */
//- (instancetype)initWithAsset:(MDLAsset*)asset
//                    divisions:(int)divisions
//              interiorNBWidth:(float)interiorNBWidth
//              exteriorNBWidth:(float)exteriorNBWidth
//                  patchRadius:(float)patchRadius NS_DEPRECATED(10_11, 10_12, NA, NA);

/**
 The number of voxels in the grid
 */
//@property (nonatomic, readonly) NSUInteger count;
//
///**
// The extent of the voxel grid in index space
// */
//@property (nonatomic, readonly) MDLVoxelIndexExtent voxelIndexExtent;

/**
 Determine if a sample exists at the specified index
 @discussion the allowAny parameters can be used to wildcard any dimensions. This
 is useful to perform queries such as determining if any voxel
 exists on the XY plane at a certain Z, or if any voxel exists at
 any X, Y, Z, or a particular shell, and so on.
 */
//- (BOOL)voxelExistsAtIndex:(MDLVoxelIndex)index
//                 allowAnyX:(BOOL)allowAnyX allowAnyY:(BOOL)allowAnyY allowAnyZ:(BOOL)allowAnyZ
//             allowAnyShell:(BOOL)allowAnyShell;

/**
 Returns an NSData containing the indices of all voxels found in the extent
 */
//- (nullable NSData *)voxelsWithinExtent:(MDLVoxelIndexExtent)extent;
//
///**
// Returns an NSData containing the indices of all voxels in the voxel grid
// */
//- (nullable NSData *)voxelIndices;
//
///**
// Set a sample at the specified index
// @discussion the extent, bounds, and shell properties may be modified
// */
//- (void)setVoxelAtIndex:(MDLVoxelIndex)index;

/**
 Set voxels corresponding to a mesh.
 Routine will attempt to create a closed volume model by applying "patches" of
 a given radius to any holes it may find in the mesh.
 */
//- (void)setVoxelsForMesh:(nonnull MDLMesh*)mesh divisions:(int)divisions patchRadius:(float)patchRadius;

/**
 Set voxels corresponding to a mesh
 Routine will attempt to create a closed volume model by applying "patches" of
 a given radius to any holes it may find in the mesh.
 
 @param divisions The number of divisions to divide the vertical extent of the
 model by.
 @param interiorShells The number of shells to compute inside the surface shell
 @param exteriorShells The number of shells to compute outside the surface shell
 @param patchRadius The radius of the largest model mending patch in world space units
 */
//- (void)setVoxelsForMesh:(nonnull MDLMesh*)mesh
//               divisions:(int)divisions
//          interiorShells:(int)interiorShells
//          exteriorShells:(int)exteriorShells
//             patchRadius:(float)patchRadius NS_DEPRECATED(10_11, 10_12, NA, NA);


/**
 Set voxels corresponding to a mesh
 Routine will attempt to create a closed volume model by applying "patches" of
 a given radius to any holes it may find in the mesh.
 
 @param divisions The number of divisions to divide the vertical extent of the
 model by.
 @param interiorNBWidth The interior narrow band width in world space units
 @param exteriorNBWidth The exterior narrow band width in world space units
 @param patchRadius The radius of the largest model mending patch in world space units
 */
//- (void)setVoxelsForMesh:(nonnull MDLMesh*)mesh
//               divisions:(int)divisions
//         interiorNBWidth:(float)interiorNBWidth
//         exteriorNBWidth:(float)exteriorNBWidth
//             patchRadius:(float)patchRadius NS_DEPRECATED(10_11, 10_12, NA, NA);

/**
 Union modifies the voxel grid to be the merger with the supplied voxel grid.
 It is assumed that the spatial voxel extent of one voxel in the supplied grid is the same as that of the voxel grid.
 Note that the shell level data will be cleared.
 */
//- (void)unionWithVoxels:(MDLVoxelArray*)voxels;

/**
 Intersection modifies the voxel grid so that only voxels that are also in the supplied voxel grid are retained.
 It is assumed that the spatial voxel extent of one voxel in the supplied grid is the same as that of the voxel grid.
 Note that the shell level data will be cleared.
 */
//- (void)intersectWithVoxels:(MDLVoxelArray*)voxels;

/**
 Difference modifies the voxel grid so that voxels also in the supplied voxel grid are removed.
 It is assumed that the spatial voxel extent of one voxel in the supplied grid is the same as that of the voxel grid.
 Note that the shell level data will be cleared.
 */
//- (void)differenceWithVoxels:(MDLVoxelArray*)voxels;

/**
 The extent of the voxel grid in Cartesian space
 */
//@property (nonatomic, readonly) MDLAxisAlignedBoundingBox boundingBox;
//
///**
// Return the voxel index corresponding to a point in space
// */
//- (MDLVoxelIndex)indexOfSpatialLocation:(vector_float3)location;

/**
 Return the spatial location of the center of the indexed voxel
 */
//- (vector_float3)spatialLocationOfIndex:(MDLVoxelIndex)index;

/**
 The bounding box of an indexed voxel
 */
//- (MDLAxisAlignedBoundingBox)voxelBoundingBoxAtIndex:(MDLVoxelIndex)index;

/**
 Converts volume grid into a signed shell field by surrounding the surface voxels, which have shell
 level values of zero, by an inner layer of voxels with shell level values of negative one and an
 outer layer of voxels with shell level values of positive one.
 
 The volume model must be closed in order to generate a signed shell field.
 */
//- (void)convertToSignedShellField;

/**
 Returns whether or not the volume grid is in a valid signed shell field form.
 
 This property will be set to YES after calling generateSignedShellField. All other
 methods that modify the voxel grid will cause this property to be set to NO. Setting
 shellFieldInteriorThickness and shellFieldExteriorThickness will not affect the value
 of this property.
 */
//@property (nonatomic, readonly) BOOL isValidSignedShellField;

/**
 If voxel grid is in a valid signed shell field form, sets the interior thickness to the desired width,
 as measured from the model surface. If the voxel grid is not in a valid signed shell field form, the
 value of this property is zero.
 */
//@property (nonatomic) float shellFieldInteriorThickness;

/**
 If voxel grid is in a valid signed shell field form, sets the exterior thickness to the desired width,
 as measured from the model surface. If the voxel grid is not in a valid signed shell field form, the
 value of this property is zero.
 */
//@property (nonatomic) float shellFieldExteriorThickness;

/**
 Creates a coarse mesh from the voxel grid
 */
//- (nullable MDLMesh*)coarseMesh;
//- (nullable MDLMesh*)coarseMeshUsingAllocator:(nullable id<MDLMeshBufferAllocator>)allocator;

/**
 Creates a smooth mesh from the voxel grid
 */
//- (nullable MDLMesh*)meshUsingAllocator:(nullable id<MDLMeshBufferAllocator>)allocator;
//
//
//@end
//
//NS_ASSUME_NONNULL_END

