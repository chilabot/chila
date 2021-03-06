#ifndef CHILA_CONNECTIONTOOLS_LIB_OTHER_FILEDEBUG__LOGFILE_HPP
#define CHILA_CONNECTIONTOOLS_LIB_OTHER_FILEDEBUG__LOGFILE_HPP

#include "fwd.hpp"
#include <fstream>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/function.hpp>
#include <chila/lib/misc/util.hpp>
#include <chila/lib/misc/exceptions.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <chila/lib/misc/SinkInserter.hpp>
#include <chila/lib/misc/RepeatText.hpp>
#include <chila/lib/misc/PThreadKeyPtr.hpp>

#include "macros.fgen.hpp"

MY_NSP_START
{
    class LogFile
    {
        public:
            typedef boost::mutex::scoped_lock FileLock;

            mutable boost::mutex fileMutex;
            std::ofstream file;
            const unsigned tNameMaxSize, maxFileSizeKB, maxOldFiles;
            const boost::filesystem::path path;
            bool append;

            struct Indent;
            chila::lib::misc::PThreadKeyPtr<unsigned> indent;

            LogFile(const boost::filesystem::path &path, unsigned tNameMaxSize, unsigned maxOldFiles, unsigned maxFileSizeKB, bool append);

            using ArgMap = std::map<std::string, std::string>;
            using Function = std::function<void()>;


            void writeFunction(const std::string &name, const ArgMap &args, bool showArguments,
                const std::string &comments, const Function &fun);

            void write(const std::string &text, const Function &fun);

        private:
            unsigned pid;

            void checkFile();
            void removeLastFiles();
            void openNewFile();
            void closeFile();
    };

}
MY_NSP_END

#include "macros.fgen.hpp"

#endif
