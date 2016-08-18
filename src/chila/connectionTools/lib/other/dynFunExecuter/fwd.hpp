/* Copyright 2011-2015 Roberto Daniel Gimenez Gamarra
 * (C.I.: 1.439.390 - Paraguay)
 *
 * This file is part of 'chila.connectionTools.lib.other'
 *
 * 'chila.connectionTools.lib.other' is free software: you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * 'chila.connectionTools.lib.other' is distributed in the hope that
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with 'chila.connectionTools.lib.other'. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CHILA_CONNECTIONTOOLS_LIB_OTHER_DYNFUNEXECUTER__FWD_HPP
#define CHILA_CONNECTIONTOOLS_LIB_OTHER_DYNFUNEXECUTER__FWD_HPP

#include <chila/lib/misc/fwd.hpp>
#include <map>
#include <chila/lib/misc/Path.hpp>

#include "macros.fgen.hpp"

MY_NSP_START
{
    using ArgumentStrMap = std::map<std::string, std::string>;

    CHILA_LIB_MISC__FWDEC_TYPE(ExecuterMap);

    CHILA_LIB_MISC__NAMED_TUPLE(XMLResult, 1,
        ((chila::lib::misc::Path)(path))
        ((ArgumentStrMap)(arguments))
    );

}
MY_NSP_END

#include "macros.fgen.hpp"

#undef FWDEC_TYPE
#endif
