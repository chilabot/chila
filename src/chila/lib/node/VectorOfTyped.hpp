/* Copyright 2011-2015 Roberto Daniel Gimenez Gamarra (chilabot@gmail.com)
 * (C.I.: 1.439.390 - Paraguay)
 */

#ifndef CHILA_LIB_NODE__VECTOROFTYPED_HPP
#define CHILA_LIB_NODE__VECTOROFTYPED_HPP

#include "ContainerOfTyped.hpp"
#include <limits>
#include "fwd.hpp"
#include <chila/lib/misc/util.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/utility.hpp>

#define FWDEC_SPTR  CHILA_LIB_MISC__FWDEC_SPTR

#define CHILA_META_NODE__DEF_VECTOR_OF_TYPED(Name, Type) \
    struct Name: public chila::lib::node::VectorOfTyped<Type> \
    { \
        friend chila::lib::node::Node; \
        public: \
            static std::unique_ptr<Name> create(std::string name) \
            { \
                return Node::createNamed<Name>(rvalue_cast(name)); \
            } \
    }; \

#include "nspDef.hpp"

MY_NSP_START
{
    struct NodeVector: public virtual NodeWithChildren
    {
    };

    template <typename Type>
    class VectorOfTyped: public ContainerOfTyped<Type>, public NodeVector
    {
        public:
            VectorOfTyped() : nextId(0) {}

            template <typename Derived = Type>
            Derived &add()
            {
                return static_cast<Derived&>(NodeWithChildren::add(Derived::create(boost::lexical_cast<std::string>(nextId++))));
            }

            bool canTakeChildFrom(IContainerOfTyped &from) const override
            {
                return dynamic_cast<VectorOfTyped<Type>*>(&from);
            }

            Node &takeChild(VectorOfTyped<Type> &from, const std::string &name)
            {
                auto newName = boost::lexical_cast<std::string>(nextId++);
                return NodeWithChildren::add(newName, from.removeNode(name));
            }

            Node &takeChild(IContainerOfTyped &from, const std::string &name) override
            {
                return takeChild(dynamic_cast<VectorOfTyped<Type>&>(from), name);
            }

            void remove(const std::string &name) override
            {
                removeNode(name);
            }

        private:
            unsigned nextId;

            std::unique_ptr<Type> removeNode(const std::string &name);
    };

    template <typename Type>
    std::unique_ptr<Type> VectorOfTyped<Type>::removeNode(const std::string &name)
    {
        auto nodes = removeAll();
        std::unique_ptr<Type> ret;

        nextId = 0;
        for (auto &node : nodes)
        {
            if (node->name() == name)
                ret = std::unique_ptr<Type>(chila::lib::misc::checkNotNull(dynamic_cast<Type*>(node.release())));
            else
                NodeWithChildren::add(boost::lexical_cast<std::string>(nextId++), rvalue_cast(node));
        }

        return rvalue_cast(ret);
    }

}
MY_NSP_END

#include "nspUndef.hpp"
#undef FWDEC_SPTR
#endif
