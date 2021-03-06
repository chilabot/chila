/* Copyright 2011-2015 Roberto Daniel Gimenez Gamarra (chilabot@gmail.com)
 * (C.I.: 1.439.390 - Paraguay)
 */

#ifndef CHILA_CONNECTIONTOOLS_LIB_TREE__TYPES_HPP
#define CHILA_CONNECTIONTOOLS_LIB_TREE__TYPES_HPP

#include "fwd.hpp"
#include <chila/lib/misc/macrosExp.hpp>
#include <chila/lib/node/MapOfTyped.hpp>
#include <chila/lib/node/VectorOfTyped.hpp>
#include <chila/lib/node/StructNode.hpp>
#include <chila/lib/node/TypedNode.hpp>
#include <chila/lib/node/Reference.hpp>
#include <chila/lib/node/VoidNode.hpp>
#include <chila/lib/node/util.hpp>
#include "macrosDef.hpp"

#define FWDEC_TYPE CHILA_LIB_MISC__FWDEC_TYPE

#define DEF_MAP(Type) \
    using Type##Map = TypedNodeMap<Type>

#define DEF_VECTOR(Type) \
    using Type##Vector = TypedNodeVector<Type>

#define NWP(Type) chila::lib::node::NodeWithParent<Type>

#define REF_METHODS CHILA_META_NODE__DEF_REFERENCE_NODE_METHODS

#define DEF_BASE_MAP_GROUP(Name) \
        CHILA_META_NODE__DEF_MAP_OF_TYPED(Name##Map, Name##Base,); \
        \
        CHILA_META_NODE__DEF_STRUCT_NODE(Name##Base,, (), \
        ); \
        \
        CHILA_META_NODE__DEF_STRUCT_NODE(Name##Group, (Name##Base)(Element)(virtual chila::lib::node::IContainerOfTyped)(virtual Group), \
            ( \
                using ElementType = Name; \
                using MapType = Name##Map; \
                \
                CHILA_META_NODE__DEF_CHECK_BASES((Element)(BOOST_PP_CAT(Name, Base)), 0) \
                \
                bool canTakeChildFrom(chila::lib::node::IContainerOfTyped &from) const override { return elements().canTakeChildFrom(from); } \
                chila::lib::node::Node &takeChild(chila::lib::node::IContainerOfTyped &from, const std::string &name) override \
                { \
                    return elements().takeChild(from, name); \
                } \
            ), \
            ((Name##Map)(elements)) \
        );

#include "nspDef.hpp"

MY_NSP_START
{
    using chila::lib::node::Reference;
    using chila::lib::node::NodeWithChildren;
    using namespace chila::lib::node::typed;

    CHILA_META_NODE__DEF_NODE(Description, (String), ());

    CHILA_META_NODE__DEF_STRUCT_NODE(Element,, (CHILA_META_NODE__DEF_CHECK),
        ((Description)(description))
    );

    struct NspElement { virtual ~NspElement() {}; };
    struct Group { virtual ~Group() {}; };

    CHILA_META_NODE__DEF_MAP_OF_TYPED(Namespace, NspElement, (virtual NspElement));

    namespace connector
    {
        CHILA_META_NODE__DEF_MAP_OF_TYPED(ArgRefMap, ArgRef,);
        CHILA_META_NODE__DEF_MAP_OF_TYPED(EventRefMap, EventRef,);

        DEF_BASE_MAP_GROUP(Argument);

        CHILA_META_NODE__DEF_STRUCT_NODE(Argument, (Element)(ArgumentBase),
            (
                CHILA_META_NODE__DEF_CHECK_BASES((Element)(NodeWithChildren), 0)
            ),
        );


        CHILA_META_NODE__DEF_REFERENCE_VNODE(ArgRef, Argument, ArgumentMap);


        DEF_BASE_MAP_GROUP(Event)
        DEF_BASE_MAP_GROUP(Action)

        CHILA_META_NODE__DEF_STRUCT_NODE(Function, (Element),
            (
                CHILA_META_NODE__DEF_CHECK_BASES((Element)(NodeWithChildren), 0)
            ),
            ((ArgRefMap)(arguments))
        );

        CHILA_META_NODE__DEF_STRUCT_NODE(Event, (Function)(EventBase), (),
        );

        CHILA_META_NODE__DEF_STRUCT_NODE(Action, (Function)(ActionBase), (),
            ((EventRefMap)(events))
        );

        CHILA_META_NODE__DEF_REFERENCE_VNODE(EventRef, Event, EventMap);

        CHILA_META_NODE__DEF_STRUCT_NODE(Connector, (Element)(NspElement),
            (
                CHILA_META_NODE__DEF_CHECK_BASES((Element)(NodeWithChildren), 0)
            ),
            ((ArgumentMap)(arguments))
            ((EventMap)(events))
            ((ActionMap)(actions))
        );
    }

    namespace cPerformer
    {
        CHILA_META_NODE__DEF_MAP_OF_TYPED(ConnectorAliasMap, ConnectorAlias,);
        CHILA_META_NODE__DEF_MAP_OF_TYPED(CAArgAliasMap, CAArgAlias,);
        CHILA_META_NODE__DEF_MAP_OF_TYPED(ArgVRefMap, ArgVRef,);
        CHILA_META_NODE__DEF_MAP_OF_TYPED(EventCallMap, EventCall,);
        CHILA_META_NODE__DEF_MAP_OF_TYPED(APCRefMap, APCRef,);
        CHILA_META_NODE__DEF_VECTOR_OF_TYPED(ActionInstanceVec, ActionInstance);

        DEF_BASE_MAP_GROUP(Argument)
        CHILA_META_NODE__DEF_MAP_OF_TYPED(EventAliasMap, EventAlias,);
        CHILA_META_NODE__DEF_MAP_OF_TYPED(ActionAliasMap, ActionAlias,);

        CHILA_META_NODE__DEF_STRUCT_NODE(Argument, (Element)(ArgumentBase),
            (
                CHILA_META_NODE__DEF_CHECK_BASES((Element)(ArgumentBase), 0)
            ),
            ((Boolean)(unique))
        );

        CHILA_META_NODE__DEF_REFERENCE_VNODE(ArgVRef, Argument, ArgumentMap);
        CHILA_META_NODE__DEF_REFERENCE_TNODE(ArgTRef, chila::lib::misc::Path, Argument, ArgumentMap);

        CHILA_META_NODE__DEF_STRUCT_NODE(CAArgAlias, (Element)(Reference<connector::Argument>),
            (
                REF_METHODS(connector::ArgumentMap)
                CHILA_META_NODE__DEF_CHECK_BASES((Element)(Reference<connector::Argument>)(NodeWithChildren), 0)
            ),
            ((ArgTRef)(cpRef))
        );

        CHILA_META_NODE__DEF_STRUCT_NODE(EventAlias, (Element)(Reference<connector::Event>),
            (
                REF_METHODS(connector::EventMap)
                CHILA_META_NODE__DEF_CHECK_BASES((Element)(Reference<connector::Event>)(NodeWithChildren), 1)
            ),
        );

        CHILA_META_NODE__DEF_STRUCT_NODE(ActionAlias, (Element)(Reference<connector::Action>),
            (
                REF_METHODS(connector::ActionMap)
                CHILA_META_NODE__DEF_CHECK_BASES((Element)(Reference<connector::Action>)(NodeWithChildren), 1)
            ),
        );

        // TODO The check of this node is not being called
        CHILA_META_NODE__DEF_REFERENCE_TNODE(ConnectorRef, chila::lib::misc::Path, connector::Connector, Namespace);


        CHILA_META_NODE__DEF_STRUCT_NODE(ConnectorAlias, (Element),
            (
                CHILA_META_NODE__DEF_CHECK_BASES((Element)(NodeWithChildren), 0)
            ),
            ((ConnectorRef)(connector))
            ((CAArgAliasMap)(arguments))
            ((EventAliasMap)(events))
            ((ActionAliasMap)(actions))
        );


        CHILA_META_NODE__DEF_REFERENCE_TNODE(ConnectorAliasRef, std::string, ConnectorAlias, ConnectorAliasMap);

        DEF_BASE_MAP_GROUP(AProviderCreator)

        CHILA_META_NODE__DEF_STRUCT_NODE(AProviderCreator, (Element)(AProviderCreatorBase),
            (
                CHILA_META_NODE__DEF_CHECK_BASES((Element)(AProviderCreatorBase), 0)
            ),
            ((ArgVRefMap)(requires))
            ((ArgVRefMap)(provides))
        );


        CHILA_META_NODE__DEF_REFERENCE_VNODE(APCRef, AProviderCreator, AProviderCreatorMap);

        CHILA_META_NODE__DEF_REFERENCE_TNODE(ActionRef, chila::lib::misc::Path, connector::Action, connector::ActionMap);
        CHILA_META_NODE__DEF_REFERENCE_TNODE(ConnectorInstanceRef, chila::lib::misc::Path, ConnectorInstance, ConnectorInstanceMap);

//        CHILA_META_NODE__DEF_STRUCT_NODE(DeterminesOrder, (Boolean), (),
//        );

        CHILA_META_NODE__DEF_STRUCT_NODE(ActionInstance, (Element), (CHILA_META_NODE__DEF_CHECK),
            ((ConnectorInstanceRef)(connInstance))
            ((ActionRef)(action))
            ((Boolean)(determinesOrder))
        );

        CHILA_META_NODE__DEF_STRUCT_NODE(EventCall, (Element)(Reference<connector::Event>),
                (
                    REF_METHODS(connector::EventMap)
                    CHILA_META_NODE__DEF_CHECK_BASES((Element)(Reference<connector::Event>)(NodeWithChildren), 1)
                ),
            ((APCRefMap)(aProvCreators))
            ((ActionInstanceVec)(actions))
        );

        DEF_BASE_MAP_GROUP(ConnectorInstance)

        CHILA_META_NODE__DEF_STRUCT_NODE(ConnectorInstance, (ConnectorInstanceBase)(Element),
            (
                CHILA_META_NODE__DEF_CHECK_BASES((Element)(ConnectorInstanceBase), 0)
            ),

            ((ConnectorAliasRef)(connAlias))
            ((EventCallMap)(events))
        );

        CHILA_META_NODE__DEF_STRUCT_NODE(ConnectionPerformer, (Element)(virtual NspElement), (CHILA_META_NODE__DEF_CHECK),
            ((ArgumentMap)(arguments))
            ((AProviderCreatorMap)(aProvCreators))
            ((ConnectorAliasMap)(connectorAliases))
            ((ConnectorInstanceMap)(connInstances))
        );




    }

}
MY_NSP_END

#include "nspUndef.hpp"

#undef REF_METHODS
#undef DEF_MAP
#undef DEF_VECTOR
#undef NWP

#endif

