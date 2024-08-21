/*!
 @header MDLAssetResolver.hpp
 @framework ModelIO
 @abstract Structures for representing contents of 3d model files
 @copyright Treata Norouzi on 8/12/24.
 */


#include "ModelIOExports.hpp"
//#include "MDLAsset.hpp"   class Asset
#import "Foundation/Foundation.hpp"

namespace MDL
{
// MARK: AssetResolver
// Protocol
class AssetResolver : public NS::Referencing<AssetResolver>
{
public:
    BOOL                    canResolveAssetNamed(const NS::String* name);
    
    NS::URL*                resolveAssetNamed(const NS::String* name);
};

class Asset;

// MARK: RelativeAssetResolver

class RelativeAssetResolver : public NS::Referencing<AssetResolver>
{
public:
    static class RelativeAssetResolver*     alloc();
    
    // initWithAsset:asset
    MDL::RelativeAssetResolver*             init(const MDL::Asset* asset);
    
    // Read&Write
    class Asset*                            asset() const;
    void                                    setAsset(const MDL::Asset* asset);
};

// MARK: PathAssetResolver

class PathAssetResolver : public NS::Referencing<AssetResolver>
{
public:
    static class PathAssetResolver*     alloc();

    // initWithPath:
    MDL::PathAssetResolver*             init(const NS::String* path);
    
    // Read&Write
    NS::String*                         path() const;
    void                                setPath(const NS::String* path);
};

// MARK: BundleAssetResolver

class BundleAssetResolver : public NS::Referencing<AssetResolver>
{
public:
    static class BundleAssetResolver*   alloc();
    
    // initWithBundle:
    MDL::BundleAssetResolver*           init(const NS::String* path);
    
    // Read&Write
    NS::String*                         path() const;
    void                                setPath(const NS::String* path);
};

}

// MARK: - Private Sector

// MARK: Protocol AssetResolver
// method: canResolveAssetNamed:
_MDL_INLINE BOOL MDL::AssetResolver::canResolveAssetNamed(const NS::String* name)
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(canResolveAssetNamed_), name);
}

// method: resolveAssetNamed:
_MDL_INLINE NS::URL* MDL::AssetResolver::resolveAssetNamed(const NS::String* name)
{
    return Object::sendMessage<NS::URL*>(this, _MDL_PRIVATE_SEL(resolveAssetNamed_), name);
}

// MARK: Class RelativeAssetResolver

// static method: alloc
_MDL_INLINE MDL::RelativeAssetResolver* MDL::RelativeAssetResolver::alloc()
{
    return NS::Object::alloc<MDL::RelativeAssetResolver>(_MDL_PRIVATE_CLS(MDLRelativeAssetResolver));
}

// method: initWithAsset:
_MDL_INLINE MDL::RelativeAssetResolver* MDL::RelativeAssetResolver::init(const MDL::Asset* asset)
{
    return Object::sendMessage<MDL::RelativeAssetResolver*>(this, _MDL_PRIVATE_SEL(initWithAsset_), asset);
}

// property: asset
_MDL_INLINE MDL::Asset* MDL::RelativeAssetResolver::asset() const
{
    return Object::sendMessage<MDL::Asset*>(this, _MDL_PRIVATE_SEL(asset));
}
// write method: setAsset:
_MDL_INLINE void MDL::RelativeAssetResolver::setAsset(const MDL::Asset* asset)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setAsset_), asset);
}

// MARK: PathAssetResolver

// static method: alloc
_MDL_INLINE MDL::PathAssetResolver* MDL::PathAssetResolver::alloc()
{
    return NS::Object::alloc<MDL::PathAssetResolver>(_MDL_PRIVATE_CLS(MDLPathAssetResolver));
}

// method: initWithPath:
_MDL_INLINE MDL::PathAssetResolver* MDL::PathAssetResolver::init(const NS::String* path)
{
    return Object::sendMessage<MDL::PathAssetResolver*>(this, _MDL_PRIVATE_SEL(initWithPath_), path);
}

// property: path
_MDL_INLINE NS::String* MDL::PathAssetResolver::path() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(path));
}
// write method: setPath:
_MDL_INLINE void MDL::PathAssetResolver::setPath(const NS::String* path)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setPath_), path);
}

// MARK: BundleAssetResolver

// static method: alloc
_MDL_INLINE MDL::BundleAssetResolver* MDL::BundleAssetResolver::alloc()
{
    return NS::Object::alloc<MDL::BundleAssetResolver>(_MDL_PRIVATE_CLS(MDLBundleAssetResolver));
}

// method: initWithBundle:
_MDL_INLINE MDL::BundleAssetResolver* MDL::BundleAssetResolver::init(const NS::String* path)
{
    return Object::sendMessage<MDL::BundleAssetResolver*>(this, _MDL_PRIVATE_SEL(initWithBundle_), path);
}

// property: path
_MDL_INLINE NS::String* MDL::BundleAssetResolver::path() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(path));
}
// write method: setPath:
_MDL_INLINE void MDL::BundleAssetResolver::setPath(const NS::String* path)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setPath_), path);
}




// MARK: - Original objC APIs

//#import <ModelIO/ModelIOExports.h>
//#import <Foundation/Foundation.h>
//
//NS_ASSUME_NONNULL_BEGIN

//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//@protocol MDLAssetResolver <NSObject>
//
//- (BOOL)canResolveAssetNamed:(NSString*)name;
//- (NSURL*)resolveAssetNamed:(NSString*)name;
//
//@end

//@class MDLAsset;

/*!
 @class MDLRelativeAssetResolver
 
 @abstract The relative asset resolver searches for referenced files
 by checking the location of the asset for sibling files
 satisfying the requested name.
 */

// MARK: - RelativeAssetResolver

//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLRelativeAssetResolver : NSObject <MDLAssetResolver>
//
//- (instancetype)initWithAsset:(MDLAsset*)asset;

//@property (nonatomic, readwrite, weak) MDLAsset *asset;
//
//@end

// MARK: - PathAssetResolver

/*!
 @class MDLPathAssetResolver
 
 @abstract The path asset resolver searches for referenced files
 by prepending path.
 
 @discussion Path should resolve to a well formed URI. A file system
 path might take the form @"file:///path/to/all/assets/
 
 A trailing slash is automatically appended to path if
 not provided.
 */

//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLPathAssetResolver : NSObject <MDLAssetResolver>
//
//- (instancetype)initWithPath:(NSString*)path;

//@property (nonatomic, readwrite, copy) NSString *path;
//
//@end


// MARK: - BundleAssetResolver

//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLBundleAssetResolver : NSObject <MDLAssetResolver>
//
//- (instancetype)initWithBundle:(NSString*)path;

//@property (nonatomic, readwrite, copy) NSString *path;
//
//@end
//
//NS_ASSUME_NONNULL_END

