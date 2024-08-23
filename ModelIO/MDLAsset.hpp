/*!
 @header MDLAsset.hpp
 @framework ModelIO
 @abstract Structures for representing contents of 3d model files
 @copyright Treata Norouzi on 8/18/24.
 */


#include "ModelIOExports.hpp"
#include "MDLAssetResolver.hpp"
#include "MDLObject.hpp"
#include "MDLVertexDescriptor.hpp"
#include "MDLMeshBuffer.hpp"
#include "MDLAnimation.hpp"
#import "Foundation/NSURL.hpp"
#import <simd/simd.h>

namespace MDL
{
class Asset : public NS::Copying<NS::FastEnumeration>
{
public:
    static class Asset* alloc();
    
    // initWithURL:
    class Asset*        init(const NS::URL* URL);
    
    // initWithURL:vertexDescriptor:bufferAllocator:
    class Asset*        init(const NS::URL* URL,
                             const VertexDescriptor* vertexDescriptor,
                             const class MeshBufferAllocator* bufferAllocator);
    
    // initWithBufferAllocator:
    class Asset*        init(const class MeshBufferAllocator* bufferAllocator);
    
    // initWithURL:vertexDescriptor:bufferAllocator:preserveTopology:error:
    class Asset*        init(const NS::URL* URL,
                             const VertexDescriptor* vertexDescriptor,
                             const class MeshBufferAllocator* bufferAllocator,
                             BOOL preserveTopology,
                             // !!!: Uncertain
                             NS::Error** error);
    
    // exportAssetToURL:
    BOOL                exportAssetToURL(const NS::URL* URL);
    
    // exportAssetToURL:error:
    BOOL                exportAssetToURL(const NS::URL* URL, NS::Error** error);
    
    // objectAtPath:
    MDL::Object*        objectAtPath(const NS::String* path);
    
    // canImportFileExtension:
    static BOOL         canImportFileExtension(const NS::String* extention);
    
    // canExportFileExtension:
    static BOOL         canExportFileExtension(const NS::String* extention);
    
    // childObjectsOfClass:
    NS::Array*          childObjectsOfClass(Class objectClass);
    
    void                loadTextures();
    
    // boundingBoxAtTime:
    AxisAlignedBoundingBox  boundingBoxAtTime(NS::TimeInterval time);
    
    AxisAlignedBoundingBox  boundingBox() const;
    
    // Read&Write
    NS::TimeInterval    frameInterval() const;
    void                setFrameInterval(NS::TimeInterval frameInterval);
    
    NS::TimeInterval    startTime() const;
    void                setStartTime(NS::TimeInterval startTime);
    
    NS::TimeInterval    endTime() const;
    void                setEndTime(NS::TimeInterval endTime);
    
    vector_float3       upAxis() const;
    void                setUpAxis(vector_float3 upAxis);
    
    NS::URL*            URL() const;
    
    class AssetResolver*    resolver() const;
    void                    setResolver(const class AssetResolver* resolver);
    
    class MeshBufferAllocator*  bufferAllocator() const;
    
    VertexDescriptor*   vertexDescriptor() const;
    
    // addObject:
    void                addObject(const MDL::Object* object);
    
    // removeObject:
    void                removeObject(const MDL::Object* object);
    
    NS::UInteger        count() const;
    
    // objectAtIndexedSubscript:
    class MDL::Object*      objectAtIndexedSubscript(NS::UInteger index);
    
    // objectAtIndex:
    MDL::Object*            objectAtIndex(NS::UInteger index);
    
    class ObjectContainerComponent* masters() const;
    void                            setMasters(const class ObjectContainerComponent* masters);
    
    class ObjectContainerComponent* originals() const;
    void                            setOriginals(const class ObjectContainerComponent* originals);
    
    class ObjectContainerComponent* animations() const;
    void                            setAnimations(const class ObjectContainerComponent* animations);
    
};

// Protocol
class LightProbeIrradianceDataSource : public NS::Referencing<LightProbeIrradianceDataSource>
{
public:
    AxisAlignedBoundingBox      boundingBox() const;
    void                        setBoundingBox(AxisAlignedBoundingBox boundingBox);
    
    NS::UInteger                sphericalHarmonicsLevel() const;
    void                        setSphericalHarmonicsLevel(NS::UInteger sphericalHarmonicsLevel);
    
    // sphericalHarmonicsCoefficientsAtPosition:
    NS::Data*                   sphericalHarmonicsCoefficientsAtPosition(vector_float3 position);
    
    // MARK: LightBaking
    
    // placeLightProbesWithDensity:usingIrradianceDataSource:
    static class NS::Array*     placeLightProbesWithDensity(float value,
                                                            const class LightProbeIrradianceDataSource* dataSource);
};

}

// MARK: - Private Sector

// static method: alloc
_MDL_INLINE MDL::Asset* MDL::Asset::alloc()
{
    return NS::Object::alloc<MDL::Asset>(_MDL_PRIVATE_CLS(MDLAsset));
}

// method: initWithURL:
_MDL_INLINE MDL::Asset* MDL::Asset::init(const NS::URL* URL)
{
    return Object::sendMessage<Asset*>(this, _MDL_PRIVATE_SEL(initWithURL_), URL);
}

// method: initWithURL:vertexDescriptor:bufferAllocator:
_MDL_INLINE MDL::Asset* MDL::Asset::init(const NS::URL* URL,
                                         const VertexDescriptor* vertexDescriptor,
                                         const class MeshBufferAllocator* bufferAllocator)
{
    return Object::sendMessage<Asset*>(this,
                                       _MDL_PRIVATE_SEL(initWithURL_vertexDescriptor_bufferAllocator_),
                                       URL, vertexDescriptor, bufferAllocator);
}

// method: initWithBufferAllocator:
_MDL_INLINE MDL::Asset* MDL::Asset::init(const class MeshBufferAllocator* bufferAllocator)
{
    return Object::sendMessage<Asset*>(this, _MDL_PRIVATE_SEL(initWithBufferAllocator_), bufferAllocator);
}

// method: initWithURL:vertexDescriptor:bufferAllocator:preserveTopology:error:
_MDL_INLINE MDL::Asset* MDL::Asset::init(const NS::URL* URL,
                                         const VertexDescriptor* vertexDescriptor,
                                         const class MeshBufferAllocator* bufferAllocator,
                                         BOOL preserveTopology,
                                         // !!!: Uncertain
                                         NS::Error** error)
{
    return Object::sendMessage<Asset*>(this,
                                       _MDL_PRIVATE_SEL(initWithURL_vertexDescriptor_bufferAllocator_preserveTopology_error_),
                                       URL, vertexDescriptor, bufferAllocator, preserveTopology, error);
}

// method: exportAssetToURL:
_MDL_INLINE BOOL MDL::Asset::exportAssetToURL(const NS::URL* URL)
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(exportAssetToURL_), URL);
}

// method: exportAssetToURL:error:
_MDL_INLINE BOOL MDL::Asset::exportAssetToURL(const NS::URL* URL, NS::Error** error)
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(exportAssetToURL_error_), URL, error);
}

// method: objectAtPath:
_MDL_INLINE MDL::Object* MDL::Asset::objectAtPath(const NS::String* path)
{
    return Object::sendMessage<MDL::Object*>(this, _MDL_PRIVATE_SEL(objectAtPath_), path);
}

// static method: canImportFileExtension:
_MDL_INLINE BOOL MDL::Asset::canImportFileExtension(const NS::String* extention)
{
    return Object::sendMessage<BOOL>(_MDL_PRIVATE_CLS(MDLAsset), _MDL_PRIVATE_SEL(canImportFileExtension_), extention);
}

// static method: canExportFileExtension:
_MDL_INLINE BOOL MDL::Asset::canExportFileExtension(const NS::String* extention)
{
    return Object::sendMessage<BOOL>(_MDL_PRIVATE_CLS(MDLAsset), _MDL_PRIVATE_SEL(canExportFileExtension_), extention);
}

// method: childObjectsOfClass:
_MDL_INLINE NS::Array* MDL::Asset::childObjectsOfClass(Class objectClass)
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(childObjectsOfClass_), objectClass);
}

// method: loadTextures
_MDL_INLINE void MDL::Asset::loadTextures()
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(loadTextures));
}

// method: boundingBoxAtTime:
_MDL_INLINE MDL::AxisAlignedBoundingBox MDL::Asset::boundingBoxAtTime(NS::TimeInterval time)
{
    return Object::sendMessage<AxisAlignedBoundingBox>(this, _MDL_PRIVATE_SEL(boundingBoxAtTime_), time);
}

// property: boundingBox
_MDL_INLINE MDL::AxisAlignedBoundingBox MDL::Asset::boundingBox() const
{
    return Object::sendMessage<AxisAlignedBoundingBox>(this, _MDL_PRIVATE_SEL(boundingBox));
}

// property: frameInterval
_MDL_INLINE NS::TimeInterval MDL::Asset::frameInterval() const
{
    return Object::sendMessage<NS::TimeInterval>(this, _MDL_PRIVATE_SEL(frameInterval));
}
// write method: setFrameInterval:
_MDL_INLINE void MDL::Asset::setFrameInterval(NS::TimeInterval frameInterval)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFrameInterval_), frameInterval);
}

// property: startTime
_MDL_INLINE NS::TimeInterval MDL::Asset::startTime() const
{
    return Object::sendMessage<NS::TimeInterval>(this, _MDL_PRIVATE_SEL(startTime));
}
// write method: setStartTime:
_MDL_INLINE void MDL::Asset::setStartTime(NS::TimeInterval startTime)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setStartTime_), startTime);
}

// property: endTime
_MDL_INLINE NS::TimeInterval MDL::Asset::endTime() const
{
    return Object::sendMessage<NS::TimeInterval>(this, _MDL_PRIVATE_SEL(endTime));
}
// write method: setEndTime:
_MDL_INLINE void MDL::Asset::setEndTime(NS::TimeInterval endTime)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setEndTime_), endTime);
}

// property: upAxis
_MDL_INLINE vector_float3 MDL::Asset::upAxis() const
{
    return Object::sendMessage<vector_float3>(this, _MDL_PRIVATE_SEL(upAxis));
}
// write method: setUpAxis:
_MDL_INLINE void MDL::Asset::setUpAxis(vector_float3 upAxis)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setUpAxis_), upAxis);
}

// property: URL
_MDL_INLINE NS::URL* MDL::Asset::URL() const
{
    return Object::sendMessage<NS::URL*>(this, _MDL_PRIVATE_SEL(URL));
}

// property: resolver
_MDL_INLINE MDL::AssetResolver* MDL::Asset::resolver() const
{
    return Object::sendMessage<AssetResolver*>(this, _MDL_PRIVATE_SEL(resolver));
}
// write method: setResolver:
_MDL_INLINE void MDL::Asset::setResolver(const class AssetResolver* resolver)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setResolver_), resolver);
}

// property: bufferAllocator
_MDL_INLINE MDL::MeshBufferAllocator* MDL::Asset::bufferAllocator() const
{
    return Object::sendMessage<MeshBufferAllocator*>(this, _MDL_PRIVATE_SEL(bufferAllocator));
}

// property: vertexDescriptor
_MDL_INLINE MDL::VertexDescriptor* MDL::Asset::vertexDescriptor() const
{
    return Object::sendMessage<VertexDescriptor*>(this, _MDL_PRIVATE_SEL(vertexDescriptor));
}

// method: addObject:
_MDL_INLINE void MDL::Asset::addObject(const MDL::Object* object)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(addObject_), object);
}

// method: removeObject:
_MDL_INLINE void MDL::Asset::removeObject(const MDL::Object* object)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(removeObject_), object);
}

// property: count
_MDL_INLINE NS::UInteger MDL::Asset::count() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(count));
}

// method: objectAtIndexedSubscript:
_MDL_INLINE MDL::Object* MDL::Asset::objectAtIndexedSubscript(NS::UInteger index)
{
    return Object::sendMessage<MDL::Object*>(this, _MDL_PRIVATE_SEL(objectAtIndexedSubscript_), index);
}

// method: objectAtIndex:
_MDL_INLINE MDL::Object* MDL::Asset::objectAtIndex(NS::UInteger index)
{
    return Object::sendMessage<MDL::Object*>(this, _MDL_PRIVATE_SEL(objectAtIndex_), index);
}

// property: masters
_MDL_INLINE MDL::ObjectContainerComponent* MDL::Asset::masters() const
{
    return Object::sendMessage<ObjectContainerComponent*>(this, _MDL_PRIVATE_SEL(masters));
}
// write method: setMasters:
_MDL_INLINE void MDL::Asset::setMasters(const class ObjectContainerComponent* masters)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setMasters_), masters);
}

// property: originals
_MDL_INLINE MDL::ObjectContainerComponent* MDL::Asset::originals() const
{
    return Object::sendMessage<ObjectContainerComponent*>(this, _MDL_PRIVATE_SEL(originals));
}
// write method: setOriginals:
_MDL_INLINE void MDL::Asset::setOriginals(const class ObjectContainerComponent* originals)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setOriginals_), originals);
}

// property: animations
_MDL_INLINE MDL::ObjectContainerComponent* MDL::Asset::animations() const
{
    return Object::sendMessage<ObjectContainerComponent*>(this, _MDL_PRIVATE_SEL(animations));
}
// write method: setAnimations:
_MDL_INLINE void MDL::Asset::setAnimations(const class ObjectContainerComponent* animations)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setAnimations_), animations);
}

// MARK: Protocol LightProbeIrradianceDataSource

// property: boundingBox
_MDL_INLINE MDL::AxisAlignedBoundingBox MDL::LightProbeIrradianceDataSource::boundingBox() const
{
    return Object::sendMessage<AxisAlignedBoundingBox>(this, _MDL_PRIVATE_SEL(boundingBox));
}
// write method: setBoundingBox:
_MDL_INLINE void MDL::LightProbeIrradianceDataSource::setBoundingBox(AxisAlignedBoundingBox boundingBox)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setBoundingBox_), boundingBox);
}

// property: sphericalHarmonicsLevel
_MDL_INLINE NS::UInteger MDL::LightProbeIrradianceDataSource::sphericalHarmonicsLevel() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(sphericalHarmonicsLevel));
}
// write method: setSphericalHarmonicsLevel:
_MDL_INLINE void MDL::LightProbeIrradianceDataSource::setSphericalHarmonicsLevel(NS::UInteger sphericalHarmonicsLevel)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setSphericalHarmonicsLevel_), sphericalHarmonicsLevel);
}

// method: sphericalHarmonicsCoefficientsAtPosition:
_MDL_INLINE NS::Data* MDL::LightProbeIrradianceDataSource::sphericalHarmonicsCoefficientsAtPosition(vector_float3 position)
{
    return Object::sendMessage<NS::Data*>(this, _MDL_PRIVATE_SEL(sphericalHarmonicsCoefficientsAtPosition_), position);
}

// static method: placeLightProbesWithDensity:usingIrradianceDataSource:
_MDL_INLINE NS::Array* MDL::LightProbeIrradianceDataSource::placeLightProbesWithDensity(float value,
                                                                                        const class LightProbeIrradianceDataSource* dataSource)
{                                      // FIXME: PRIVATE_PRO perhaps ...
    return Object::sendMessage<NS::Array*>(_MDL_PRIVATE_CLS(MDLLightProbeIrradianceDataSource),
                                           _MDL_PRIVATE_SEL(placeLightProbesWithDensity_usingIrradianceDataSource_),
                                           value, dataSource);
}


// MARK: - Original Header

////////#import <ModelIO/ModelIOExports.h>
////////#import <ModelIO/MDLAssetResolver.h>
////////#import <ModelIO/MDLObject.h>
////////#import <ModelIO/MDLVertexDescriptor.h>
////////#import <ModelIO/MDLMeshBuffer.h>
////////#import <ModelIO/MDLAnimation.h>
////////#import <Foundation/NSURL.h>
////////#import <simd/simd.h>
////////
////////@class MDLLightProbe;
////////@class MDLTexture;
//////
//////NS_ASSUME_NONNULL_BEGIN
//////
///////*!
////// @class MDLAsset
////// 
////// @abstract An MDLAsset represents the contents of a model file.
////// 
////// @discussion Each asset contains a collection of hierarchies of objects, where
//////             each object in the asset is the top level of a hierarchy. Objects
//////             include transforms, lights, cameras, and meshes.
////// 
////// MDLAssets are typically instantiated from NSURLs that refer to a model resource.
//////
////// The model resource may represented timed information, for example, a series of
////// mesh morphs. If the asset is timed, then the framerate will be non-zero, and the
////// firstFrame and lastFrame properties will indicate the range for which sample
////// data exists. Samples before or after that range will be clamped. Some model
////// resource representations allow continuous sampling, others are discrete. In the
////// discrete case, if a requested sample time is not on a discrete boundary the
////// returned sample will be the sample exactly on the sample time, or if no such is
////// available, the immediately preceding sample. If no time is specified for a
////// sample, the first data will be returned.
////// 
////// An asset's bounding box can be queried without traversing the hierarchy of
////// objects.
////// 
////// Fast enumeration of an MDLAsset iterates the top level objects contained within.
////// */
//////
//////
//////
//////API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//////MDL_EXPORT
//////@interface MDLAsset : NSObject <NSCopying, NSFastEnumeration>
//////
///////*!
////// @method initWithURL:
////// @abstract Initialize an MDLAsset using the contents of the resource located at
//////           the indicated URL
////// @discussion Vertex layout (i.e. vertexDescriptor) will be specified by ModelIO
//////             depending on attributes of the resource.  Buffers will be allocated
//////             using a default NSData based allocator
//////
//////             Submeshes will be converted to triangle topology.
////// */
//////- (instancetype)initWithURL:(NSURL *)URL;
///////*!
////// @method initWithURL:vertexDescriptor:bufferAllocator:
////// @abstract Initialize an MDLAsset using the contents of the resource located at
//////           URL, ensuring that the asset conforms to the supplied vertexDescriptor,
//////           and buffers are allocated in the supplied allocator
////// 
////// @discussion The default behavior is to triangulate any discovered meshes and to
//////             conform the mesh to the supplied vertexDescriptor.
////// 
//////             If nil is passed as the vertexDescriptor, then a vertexDescriptor
//////             will be created according to the attributes of the resource.
////// 
//////             If nil is passed as the bufferAllocator, buffers will be allocated
//////             using a default NSData based allocator.
////// 
//////             Submeshes will be converted to triangle topology.
//////  */
//////- (instancetype)initWithURL:(nullable NSURL *)URL
//////           vertexDescriptor:(nullable MDLVertexDescriptor*)vertexDescriptor
//////            bufferAllocator:(nullable id<MDLMeshBufferAllocator>)bufferAllocator;
//////
///////*!
////// @method initWithBufferAllocator:
////// @abstract Initialize an empty MDLAsset with a buffer allocator to be used during
//////           other operations.
////// */
//////- (instancetype)initWithBufferAllocator:(nullable id<MDLMeshBufferAllocator>)bufferAllocator;
//////
///////*!
////// @method initWithURL:vertexDescriptor:bufferAllocator:preserveTopology:error:
////// @abstract Same as initWithURL:vertexDescriptor:bufferAllocator: except that
//////           if preserveTopology is YES, a topology buffer might be created on the
//////           submeshes.
////// 
////// @discussion If all faces in a submesh have the same vertex count, then the
//////             submesh will a geometry type corresponding to that vertex count.
//////             For example, if all faces have four vertices, then the geometry
//////             type will be MDLGeometryTypeQuads. If faces have a varying number
//////             of vertices, then the the submesh type will be
//////             MDLGeometryTypeVariableTopology, and a faceTopologyBuffer will be
//////             created.
////// */
//////- (instancetype)initWithURL:(NSURL *)URL
//////           vertexDescriptor:(nullable MDLVertexDescriptor*)vertexDescriptor
//////            bufferAllocator:(nullable id<MDLMeshBufferAllocator>)bufferAllocator
//////           preserveTopology:(BOOL)preserveTopology
//////                      error:(NSError * __nullable * __nullable)error;
//////
///////*!
////// @method exportAssetToURL:
////// @abstract Export an asset to the specified URL.
////// @return YES is returned if exporting proceeded successfully,
////// */
//////- (BOOL)exportAssetToURL:(NSURL *)URL NS_SWIFT_UNAVAILABLE("Use exportAssetToURL:error");
////
/////*!
//// @method exportAssetToURL:error:
//// @abstract Export an asset to the specified URL.
//// @return YES is returned if exporting proceeded successfully,
//// */
////- (BOOL)exportAssetToURL:(NSURL *)URL error:(NSError * __nullable * __nullable)error;
////
/////*!
//// @abstract Return the object at the specified path, or nil if none exists there
//// */
////- (MDLObject*)objectAtPath:(NSString*)path API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
////
/////*!
//// @method canImportFileExtension:
//// @abstract Indicates whether MDLAsset object can be initialized with resource
////           with the given extension
//// @return YES is returned if MDLAsset is able to load and represent assets with
////           the given extension
//// */
////+ (BOOL)canImportFileExtension:(NSString *)extension;
////
/////*!
//// @method canImportFileExtension:
//// @abstract Indicates whether MDLAsset object can export asset to resource with
////           the given extension
//// @return YES is returned if MDLAsset is able is able to export assets to
////         resources with the given extension
//// */
////+ (BOOL)canExportFileExtension:(NSString *)extension;
////
/////*!
//// @method childObjectsOfClass:
//// @abstract Inspects an asset's hierarchy for objects of the specified class type
//// @return returns an NSArray of all objects in the asset matching the requested class
//// @discussion This can be used to get references to all MDLMesh objects, MDLLights,
////             etc. if objectClass is not a subclass of MDLObject, an exception will be
////             raised.
//// */
////- (NSArray<MDLObject*>*)childObjectsOfClass:(Class)objectClass;
////
/////*!
//// @method loadTextures
//// @abstract Iterates over all material properties on all materials. If they are string
////           values or NSURL values, and can be resolved as textures, then the string
////           and NSURL values will be replaced by MDLTextureSampler values.
//// */
////- (void)loadTextures API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
////
/////*!
//// @method boundingBoxAtTime:
//// @abstract The bounds of the MDLAsset at the specified time
//// */
////- (MDLAxisAlignedBoundingBox)boundingBoxAtTime:(NSTimeInterval)time;
////
/////*!
//// @property boundingBox
//// @abstract The bounds of the MDLAsset at the earliest time sample
//// */
////@property (nonatomic, readonly) MDLAxisAlignedBoundingBox boundingBox;
//
///*!
// @property frameInterval
// @abstract Inherent frame rate of an asset
// @discussion If no framerate was specified by resource or resource uncapable of
//             specifying framerate, this value defaults to 0
// */
//@property (nonatomic, readwrite) NSTimeInterval frameInterval;
//
///*!
// @property startTime
// @abstract Start time bracket of animation data
// @discussion If no animation data was specified by resource or resource incapable
//             of specifying animation data, this value defaults to 0. If startTime
//             was set explicitly, then the value of startTime will be the lesser
//             of the set value and the animated values.
// */
//@property (nonatomic, readwrite) NSTimeInterval startTime;
//
///*!
// @property endTime
// @abstract End time bracket of animation data
// @discussion If no animation data was specified by resource or resource incapable
//             of specifying animation data, this value defaults to 0. If the
//             endTime was set explicitly, then the value of endTime will be the
//             greater of the set value and the animated values.
// */
//@property (nonatomic, readwrite) NSTimeInterval endTime;
//
///*!
// @property upAxis
// @abstract Scene up axis
// @discussion Some imported formats specify a scene up axis. By default Y-axis (0, 1, 0) is used
// but other values are supported.
// */
//@property (nonatomic, readwrite) vector_float3 upAxis API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//
///*!
// @property URL
// @abstract URL used to create the asset
// @discussion If the asset was not created with a URL, nil will be returned.
// */
//@property (nonatomic, readonly, retain, nullable) NSURL *URL;
//
///*!
// @property AssetResolver
// @abstract Resolver asset that helps find associated files
// @discussion The default asset resolver is the RelativeAssetResolver
// */
//@property (nonatomic, retain, nullable) id<MDLAssetResolver> resolver API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//
//
///*!
// @property bufferAllocator
// @abstract  Allocator used to create vertex and index buffers
// */
//@property (nonatomic, readonly, retain) id<MDLMeshBufferAllocator> bufferAllocator;
//
///*!
// @property vertexDescriptor
// @abstract Vertex descriptor set upon asset initialization
// @discussion Will be nil if there was no descriptor set
// */
//@property (nonatomic, readonly, retain, nullable) MDLVertexDescriptor *vertexDescriptor;
//
///*!
// @method addObject:
// @abstract Add a top level object to an asset.
// @discussion If the object was already in the asset, this has no effect.
// */
//- (void)addObject:(MDLObject *)object;
//
///*!
// @method removeObject:
// @abstract Remove a top level object from an asset.
// @discussion If the object not in the asset, this has no effect.
// */
//- (void)removeObject:(MDLObject *)object;
//
///*!
// @property count
// @abstract The number of top level objects
// */
//@property (nonatomic, readonly) NSUInteger count;
//
///*!
// @method objectAtIndexedSubscript:
// @abstract return the indexed top level object
// */
//- (nullable MDLObject *)objectAtIndexedSubscript:(NSUInteger)index;

///*!
// @method objectAtIndex:
// @abstract return the indexed top level object
// */
//- (MDLObject *)objectAtIndex:(NSUInteger)index;
//
//
//@property (nonatomic, retain) id<MDLObjectContainerComponent> masters
//API_DEPRECATED_WITH_REPLACEMENT("originals", ios(10.0,15.0), tvos(10.0,15.0), macos(10.12,12.0));
//
///*!
// @property originals
// @abstract Original objects that can be instanced into the asset's object hierarchy
// @see MDLObjectContainerComponent
// */
//@property (nonatomic, retain) id<MDLObjectContainerComponent> originals
//API_AVAILABLE(macos(12.0), tvos(15.0), ios(15.0));
//
///*!
// @property animations
// @abstract Animations that can be bound to MDLObjects (@see MDLAnimationBindComponent)
// @see MDLObjectContainerComponent
// */
//@property (nonatomic, retain) id<MDLObjectContainerComponent> animations API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//
//@end

//@protocol MDLLightProbeIrradianceDataSource <NSObject>
///**
// Bounding box of the source scene for which you are adding light probes.
// */
//@property MDLAxisAlignedBoundingBox boundingBox;
//
//@optional
///**
// Spherical harmonics level used to calculate the spherical harmonics coefficients.
// */
//@property NSUInteger sphericalHarmonicsLevel;
//
///**
// Given a position in the source scene, returns the spherical harmonics coefficients
// at that point.
// 
// The data returned is an array of 32-bit floating-point values, containing three non-interleaved
// data sets corresponding to the red, green, and blue sets of coefficients. The array’s length is
// determined by the sphericalHarmonicsLevel property.
// */
//-(NSData *)sphericalHarmonicsCoefficientsAtPosition:(vector_float3)position;
//@end

/**
 Given a light probe density, method places light probes in the scene according to the
 passed in placement heuristic type. The higher the density, the greater the number of
 light probes placed in the scene.
 
 Using the placement heuristic MDLProbePlacementUniformGrid places the light probes in the
 scene as a uniform grid. The placement heuristic MDLProbePlacementIrradianceDistribution
 places the light probes in areas of greatest irradiance change.
 */
//@interface MDLAsset (MDLLightBaking)
//+ (NSArray<MDLLightProbe *> *)placeLightProbesWithDensity:(float)value heuristic:(MDLProbePlacement)type
//                                usingIrradianceDataSource:(id<MDLLightProbeIrradianceDataSource>)dataSource;
//@end
//
//NS_ASSUME_NONNULL_END

