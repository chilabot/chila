/* Copyright 2011-2015 Roberto Daniel Gimenez Gamarra (chilabot@gmail.com)
 * (C.I.: 1.439.390 - Paraguay)
 */

#ifndef CHILA_LIB_NODE__VOIDNODE_HPP
#define CHILA_LIB_NODE__VOIDNODE_HPP

#include "Node.hpp"
#include "fwd.hpp"
#include <chila/lib/misc/RepeatText.hpp>
#include <chila/lib/misc/util.hpp>
#include <boost/call_traits.hpp>

#define CHILA_META_NODE__DEF_VOID_NODE_BASE(r, data, elem) , public elem

#define CHILA_META_NODE__DEF_VOID_NODE(Name, Bases, Methods) \
    struct Name: public chila::lib::node::VoidNode BOOST_PP_SEQ_FOR_EACH(CHILA_META_NODE__DEF_VOID_NODE_BASE,, Bases) \
    { \
        friend chila::lib::node::Node; \
        using This = Name; \
        public: \
            static std::shared_ptr<Name> create(std::string name) \
            { \
                auto ret = std::make_shared<Name>(); \
                ret->_name = name; \
                return ret; \
            } \
            \
            BOOST_PP_SEQ_CAT(Methods) \
            \
            chila::lib::node::NodeSPtr clone(const std::string &newName = "") const override \
            { \
                auto ret = std::make_shared<Name>(*this); \
                if (!newName.empty()) ret->_name = newName; \
                return ret; \
            } \
            bool compare(const Node &node) const override \
            { \
                return name() == node.name() && clMisc::dcast<Name>(&node); \
            }\
            virtual bool isSameType(const chila::lib::node::Node &rhs) const override \
            { \
                return dynamic_cast<const Name*>(&rhs); \
            } \
    }


#include "nspDef.hpp"

MY_NSP_START
{
    struct VoidNode: public Node
    {
        operator const std::string&() const { return name(); }

        void stream(std::ostream &out, unsigned indent) const
        {
            out << chila::lib::misc::repeatText(indent, "    ") << name() << std::endl;
        }
   };
}
MY_NSP_END

#include "nspUndef.hpp"

#endif
