/* Copyright 2011-2015 Roberto Daniel Gimenez Gamarra (chilabot@gmail.com)
 * (C.I.: 1.439.390 - Paraguay)
 */

#ifndef CHILA_CONNECTIONTOOLS_DESIGNER_APP_IMPL_CONNECTION__ARGPROVIDERS_HPP
#define CHILA_CONNECTIONTOOLS_DESIGNER_APP_IMPL_CONNECTION__ARGPROVIDERS_HPP

#include <boost/mpl/map.hpp>
#include <boost/make_shared.hpp>
#include <chila/lib/misc/MemFnExecuter.hpp>
#include <chila/connectionTools/lib/codegen/macrosDef.hpp>


#include "macros.fgen.hpp"

MY_NSP_START
{
    template <typename ArgAliases>
    struct ModuleNameProvider
    {
        using ResultOfMap = boost::mpl::map
        <
            boost::mpl::pair<typename ArgAliases::moduleName, const std::string&>
        >;

        std::string moduleName;

        ModuleNameProvider(const std::string &moduleName) : moduleName(moduleName) {}

        const std::string &getArgument(typename ArgAliases::moduleName) const { return moduleName; }
    };

    template <typename ArgAliases>
    struct ModuleNameProviderCreator
    {
        using result_type = ModuleNameProvider<ArgAliases>;
        std::string moduleName;

        ModuleNameProviderCreator(const std::string &moduleName) : moduleName(moduleName) {}

        result_type operator()() const { return ModuleNameProvider<ArgAliases>(moduleName); }
    };

}
MY_NSP_END

#include "macros.fgen.hpp"

#endif
