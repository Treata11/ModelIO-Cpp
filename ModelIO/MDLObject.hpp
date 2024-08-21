/*!
 @header MDLObject.hpp
 @framework ModelIO
 @abstract Base structures for representing components of 3d assets
 @copyright Created by Treata Norouzi on 8/12/24.
 */


#include "MDLTypes.hpp"
#include "MDLTransform.hpp"

namespace MDL
{
//class wth: public NS::Referencing<MDL::Named> {};

class ObjectContainer : public NS::Referencing<MDL::ObjectContainerComponent>
{
public:
    static class ObjectContainer*   alloc();
    
    class ObjectContainer*          init();
};

}

// MARK: - Private Sector

// MARK: Object

// static method: alloc
_MDL_INLINE MDL::Object* MDL::Object::alloc()
{
    return NS::Object::alloc<MDL::Object>(_MDL_PRIVATE_CLS(MDLObject));
}

// method: init
_MDL_INLINE MDL::Object* MDL::Object::init()
{
    return NS::Object::init<MDL::Object>();
}

// property: components
_MDL_INLINE NS::Array* MDL::Object::components() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(components));
}

// method: setComponent:forProtocol:
_MDL_INLINE void MDL::Object::setComponent(const MDL::Component* component, const Protocol* protocol)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setComponent_forProtocol_), component, protocol);
}

// method: componentConformingToProtocol:
_MDL_INLINE MDL::Component* MDL::Object::componentConformingToProtocol(const Protocol* protocol)
{
    return Object::sendMessage<MDL::Component*>(this, _MDL_PRIVATE_SEL(componentConformingToProtocol_), protocol);
}

// method: objectForKeyedSubscript:
_MDL_INLINE MDL::Component* MDL::Object::objectForKeyedSubscript(const Protocol* key)
{
    return Object::sendMessage<MDL::Component*>(this, _MDL_PRIVATE_SEL(objectForKeyedSubscript_), key);
}

// method: setObject:forKeyedSubscript:
_MDL_INLINE MDL::Component* MDL::Object::setObject(const MDL::Component* obj, const Protocol* key)
{
    return Object::sendMessage<MDL::Component*>(this, _MDL_PRIVATE_SEL(setObject_forKeyedSubscript_), obj, key);
}

// property: parent
_MDL_INLINE MDL::Object* MDL::Object::parent() const
{
    return Object::sendMessage<MDL::Object*>(this, _MDL_PRIVATE_SEL(parent));
}

// property: instance
_MDL_INLINE MDL::Object* MDL::Object::instance() const
{
    return Object::sendMessage<MDL::Object*>(this, _MDL_PRIVATE_SEL(instance));
}

// property: path
_MDL_INLINE NS::String* MDL::Object::path() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(path));
}

// method: objectAtPath:
_MDL_INLINE MDL::Object* MDL::Object::objectAtPath(const NS::String* path)
{
    return Object::sendMessage<MDL::Object*>(this, _MDL_PRIVATE_SEL(objectAtPath_), path);
}

// method: enumerateChildObjectsOfClass:root:usingBlock:stopPointer:
_MDL_INLINE void MDL::Object::enumerateChildObjectsOfClass(
   const Class objectClass,
   const MDL::Object* root,
   // !!!: Uncertain
   const void (^block)(const MDL::Object* object, const BOOL* stop),
   const BOOL* stopPointer
) {
    return Object::sendMessage<void>(this,
                                     _MDL_PRIVATE_SEL(enumerateChildObjectsOfClass_root_usingBlock_stopPointer_),
                                     objectClass, root, block, stopPointer);
}

// property: transform
_MDL_INLINE MDL::TransformComponent* MDL::Object::transform() const
{
    return Object::sendMessage<MDL::TransformComponent*>(this, _MDL_PRIVATE_SEL(transform));
}
// write method: setTransform:
_MDL_INLINE void MDL::Object::setTransform(const MDL::TransformComponent* transform)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setTransform_), transform);
}

// property: children
_MDL_INLINE MDL::ObjectContainerComponent* MDL::Object::children() const
{
    return Object::sendMessage<MDL::ObjectContainerComponent*>(this, _MDL_PRIVATE_SEL(children));
}
// write method: setChildren:
_MDL_INLINE void MDL::Object::setChildren(const MDL::ObjectContainerComponent* children)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setChildren_), children);
}

// property: hidden
_MDL_INLINE BOOL MDL::Object::hidden() const
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(hidden));
}
// write method: setHidden:
_MDL_INLINE void MDL::Object::setHidden(const BOOL hidden)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setHidden_), hidden);
}

// method: addChild:
_MDL_INLINE void MDL::Object::addChild(const MDL::Object* child)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(addChild_), child);
}

// method: boundingBoxAtTime:
_MDL_INLINE MDL::AxisAlignedBoundingBox MDL::Object::boundingBoxAtTime(const NS::TimeInterval time)
{
    return Object::sendMessage<MDL::AxisAlignedBoundingBox>(this, _MDL_PRIVATE_SEL(boundingBoxAtTime_), time);
}

// MARK: ObjectContainer

// static method: alloc
_MDL_INLINE MDL::ObjectContainer* MDL::ObjectContainer::alloc()
{
    return NS::Object::alloc<MDL::ObjectContainer>(_MDL_PRIVATE_CLS(MDLObjectContainer));
}

// method: init
_MDL_INLINE MDL::ObjectContainer* MDL::ObjectContainer::init()
{
    return NS::Object::init<MDL::ObjectContainer>();
}


// MARK: - Original objC APIs

//#import <ModelIO/MDLTypes.h>
//#import <ModelIO/MDLTransform.h>
//
//NS_ASSUME_NONNULL_BEGIN
//
//@protocol MDLTransformComponent;
///*!
// @class MDLObject
// @abstract Base class for object in a ModelIO asset hierarchy
// @discussion Includes transformation and bounds info, links to parent and
//             children in the hierachy
// */
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLObject : NSObject<MDLNamed>
//
///*!
// @property components
// @abstract Allows applications to introspect the components on the objects.
// */
//@property (nonatomic, readonly, copy) NSArray<id<MDLComponent>> *components;

/*!
 @method setComponent:forProtocol:
 @abstract Extensible component support that allows user of ModelIO to customize
           MDLObjects to fit their format and workflow.
 */
//- (void)setComponent:(id<MDLComponent>)component forProtocol:(Protocol *)protocol;
//
///*!
// @method componentConformingToProtocol:
// @abstract Extensible component support that allows user of ModelIO to customize
//           MDLObjects to fit their format and workflow.
// */
//- (nullable id<MDLComponent>)componentConformingToProtocol:(Protocol *)protocol;
//
///*!
// @method objectForKeyedSubscript:
// @abstract Allows shorthand [key] syntax for componentConformingToProtocol:.
// @param key The protocol that the component conforms to.
// @see componentConformingToProtocol:
// */
//- (nullable id<MDLComponent>)objectForKeyedSubscript:(Protocol *)key;

/*!
 @method setObject:forKeyedSubscript:
 @abstract Allows shorthand [key] syntax for setComponent:forProtocol:.
 @param key The protocol that the component conforms to.
 @see setComponent:forProtocol:
 */
//- (void)setObject:(nullable id<MDLComponent>)obj forKeyedSubscript:(Protocol *)key;
//
///*!
// @property parent
// @abstract Parent object. Nil if no parent.
// @discussion Set to nil when you remove this from an object container inside the
//             parent object.
// */
//@property (nonatomic, weak, nullable) MDLObject* parent;

/*!
 @property instance
 @abstract Instance object
 @discussion nil, unless this object refers to original data to be instanced. The
             original data object can be any MDLObject that does not have a parent.
             If an MDLAsset has been created from a data file, any original objects
             parsed from that file will be found in the originals property.
             A typical use of a original and instance might be to have one original
             chair MDLObject, and instance six chairs around a table. The
             transform of each chair would be found on the parent MDLObject, but
             the various items making up the chair would be found in the original
             object.
 */
//@property (nonatomic, nullable, retain) MDLObject* instance;
//
///*!
// @property path
// @abstract a string representing a path to the object
// @discussion a path is of the form /path/to/object where the path is formed by
//             concatenating the names of the objects up the parent chain.
//             Requesting a path will force any unnamed objects to became uniquely
//             named. Any characters outside of [A-Z][a-z][0-9][:-_.] will be
//             forced to underscore.
// */
//@property (nonatomic, readonly) NSString* path;

/*!
 @abstract Return the object at the specified path, or nil if none exists there
 */
//- (MDLObject*)objectAtPath:(NSString*)path;
//
//
//- (void)enumerateChildObjectsOfClass:(Class)objectClass
//                                root:(MDLObject*)root
//                          usingBlock:( void(^)(MDLObject* object, BOOL *stop))block
//                         stopPointer:(BOOL *)stopPointer API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));


/*!
 @property transform
 @abstract Short hand property for the MDLTransformComponent.
 @discussion The default value is nil
 
 @see MDLTransformComponent
 */
//@property (nonatomic, nullable, retain) id<MDLTransformComponent> transform;
//
//
///*!
// @property children
// @abstract Short hand property for the MDLObjectContainerComponent.
// @discussion The default value is an empty MDLObjectContainer
// 
// @see MDLObjectContainerComponent
// */
//@property (nonatomic, retain) id<MDLObjectContainerComponent> children;

/*!
 @property hidden
 @abstract Visibility of the node
 @discussion default is NO
 */

//@property (nonatomic) BOOL hidden;
//
///*!
// @method addChild:
// @abstract Short hand for adding a child to the current container component and
//           setting the parent to this object.
// @discussion  It will create a default container if none exists. If children are
//              explicitly disallowed for an object, then add a container component
//              that throws on addition.
// 
// @see MDLObjectContainer
// */
//- (void)addChild:(MDLObject *)child;

/*!
 @method boundingBoxAtTime:
 @abstract Bounds ob object at the specified time
 */
//- (MDLAxisAlignedBoundingBox)boundingBoxAtTime:(NSTimeInterval)time;
//
//@end

/*!
 @class MDLObjectContainer
 @abstract Default container object
 @discussion Subclass the object container to support custom containers. Such
             custom containers might reference in memory representations, offline
             databases, and so on.
 */
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLObjectContainer : NSObject<MDLObjectContainerComponent>
//
//@end
//
//NS_ASSUME_NONNULL_END
