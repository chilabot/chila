// ******************************************************************
// *                 This is auto-generated code                    *
// *                    - DO NOT MODIFY -                           *
// ******************************************************************

#ifndef CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__FORWARDER_HPP
#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__FORWARDER_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#undef FUSION_MAX_VECTOR_SIZE
#undef BOOST_MPL_LIMIT_VECTOR_SIZE
#define FUSION_MAX_VECTOR_SIZE 50
#define BOOST_MPL_LIMIT_VECTOR_SIZE 50
#include <boost/call_traits.hpp>
#include <boost/function.hpp>
#include <chila/lib/misc/MemFnExecuter.hpp>
#include <chila/lib/misc/Path.hpp>
#include <string>

#include <chila/connectionTools/lib/codegen/FunctionSigCreator.hpp>
#include <chila/connectionTools/lib/codegen/EventExecuter.hpp>
#include <chila/connectionTools/lib/codegen/Connector.hpp>
#include <chila/connectionTools/lib/other/macrosExp.hpp>
#include <chila/connectionTools/lib/codegen/macrosDef.hpp>
#include <chila/lib/misc/macrosExp.hpp>

#define MY_BIND_ACTION(name) \
        CHILA_CONNECTIONTOOLS_LIB_CODEGEN__BIND_ACTION(target, name)
#define DEF_CONNECTOR_ARGUMENT CHILA_CONNECTIONTOOLS_LIB_CODEGEN__DEF_CONNECTOR_ARGUMENT
#define DEF_CONNECTOR_FUNCTION CHILA_CONNECTIONTOOLS_LIB_CODEGEN__DEF_CONNECTOR_FUNCTION
#define DEF_ARG_ALIAS CHILA_CONNECTIONTOOLS_LIB_CODEGEN__DEF_ARG_ALIAS
#define DEF_ARG_ALIAS_LINK CHILA_CONNECTIONTOOLS_LIB_CODEGEN__DEF_ARG_ALIAS_LINK

// Arguments defines
#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_ARGS_Forwarder \
    (object) \
    (errorMsg)

// Event defines
#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_EVENTS_Forwarder \
    (launcher_starting) \
    (launcher_started) \
    (launcher_deactivating) \
    (launcher_deactivated) \
    (launcher_finishing) \
    (launcher_finished) \
    (fatalError) \
    (forwarded)

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_EVENT_ARGS_Forwarder_launcher_starting \

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_EVENT_ARGS_Forwarder_launcher_started \

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_EVENT_ARGS_Forwarder_launcher_deactivating \

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_EVENT_ARGS_Forwarder_launcher_deactivated \

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_EVENT_ARGS_Forwarder_launcher_finishing \

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_EVENT_ARGS_Forwarder_launcher_finished \

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_EVENT_ARGS_Forwarder_fatalError \
    (errorMsg)
#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_EVENT_ARGS_Forwarder_forwarded \
    (object)

// Action defines
#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_ACTIONS_Forwarder \
    (launcher_start) \
    (launcher_deactivate) \
    (launcher_finish) \
    (take)

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_ACTION_ARGS_Forwarder_launcher_start \

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_ACTION_ARGS_Forwarder_launcher_deactivate \

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_ACTION_ARGS_Forwarder_launcher_finish \

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_ACTION_ARGS_Forwarder_take \
    (object)

// Actions' called events
#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_ACTION_EVCALLED_Forwarder_launcher_start \
    (launcher_started)(fatalError)

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_ACTION_EVCALLED_Forwarder_launcher_deactivate \
    (launcher_deactivated)(fatalError)

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_ACTION_EVCALLED_Forwarder_launcher_finish \
    (launcher_finished)(fatalError)

#define CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN__CONNECTOR_ACTION_EVCALLED_Forwarder_take \
    (forwarded)(fatalError)


CHILA_LIB_MISC__DEF_NAMESPACE(6, (chila,connectionTools,lib,common,connectors,gen))
{
    /** This class serves as a event and action connector for the connector.
      * Connectors should hold an instance of this class and connect their actions
      * in the constructor.
      */
    template <typename _ArgTypes>
    struct Forwarder final: public chila::connectionTools::lib::codegen::ConnectorImpl<Forwarder<_ArgTypes>>
    {
        static chila::lib::misc::Path path() { return "chila.connectionTools.lib.common.connectors.gen.Forwarder"; }

        typedef Forwarder Connector;
        typedef _ArgTypes ArgTypes;

        // Arguments
        struct Arguments
        {
            CHILA_CONNECTIONTOOLS_LIB_CODEGEN__DEF_CONNECTOR_ARGUMENTS( \
                CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN, Forwarder)
        };
        // Events
        struct Events
        {
            CHILA_CONNECTIONTOOLS_LIB_CODEGEN__DEF_CONNECTOR_FUNCTIONS(
                CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN, EVENT, Forwarder)

            CHILA_CONNECTIONTOOLS_LIB_CODEGEN__DEF_CONNECTOR_FUN_FUSIONSEQ(
                CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN, EVENT, Forwarder)
        } events;

        // Actions
        struct Actions
        {
            CHILA_CONNECTIONTOOLS_LIB_CODEGEN__DEF_CONNECTOR_FUNCTIONS(
                CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN, ACTION, Forwarder)

            CHILA_CONNECTIONTOOLS_LIB_CODEGEN__DEF_CONNECTOR_FUN_FUSIONSEQ(
                CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN, ACTION, Forwarder)

            Actions(Connector &connector) :
                CHILA_CONNECTIONTOOLS_LIB_CODEGEN__ACTIONS_INIT(
                    CHILA_CONNECTIONTOOLS_LIB_COMMON_CONNECTORS_GEN, Forwarder) {}
        } actions;


        Forwarder() : actions(*this) {}

        // Binds the actions to 'target'
        template <typename Target>
        void bindActions(Target &target)
        {
            MY_BIND_ACTION(launcher_start);
            MY_BIND_ACTION(launcher_deactivate);
            MY_BIND_ACTION(launcher_finish);
            MY_BIND_ACTION(take);
        }
    };
}}}}}}


#undef MY_BIND_ACTION
#undef DEF_CONNECTOR_ARGUMENT
#undef DEF_CONNECTOR_FUNCTION
#undef DEF_ARG_ALIAS
#undef DEF_ARG_ALIAS_LINK

#endif
