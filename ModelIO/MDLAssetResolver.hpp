/*!
 @header MDLAssetResolver.h
 @framework ModelIO
 @abstract Structures for representing contents of 3d model files
 @copyright Treata Norouzi on 8/12/24.
 */


#include "ModelIOExports.hpp"
#import "Foundation/Foundation.hpp"

namespace MDL
{
class AssetResolver : public NS::Referencing<AssetResolver>
{
public:
    static class AssetResolver*     alloc();
    
    class AssetResolver*            init();
    
    bool                            canResolveAssetNamed(NS::String* name);
    
    NS::URL*                        resolveAssetNamed(NS::String* name);
};

class Asset;

// MARK: - RelativeAssetResolver

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

// MARK: - PathAssetResolver

class PathAssetResolver : public NS::Referencing<AssetResolver>
{
public:
    static class PathAssetResolver*     alloc();

    // initWithPath:path
    MDL::PathAssetResolver*             init(const NS::String* path);
    
    // Read&Write
    NS::String*                         path() const;
    void                                setPath(const NS::String* path);
};

// MARK: - BundleAssetResolver

class BundleAssetResolver : public NS::Referencing<AssetResolver>
{
public:
    static class BundleAssetResolver*   alloc();
    
    // initWithBundle:path
    MDL::BundleAssetResolver*           init(const NS::String* path);
    
    // Read&Write
    NS::String*                         path() const;
    void                                setPath(const NS::String* path);
};

}

// TODO: Private-sector Implementations -





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

