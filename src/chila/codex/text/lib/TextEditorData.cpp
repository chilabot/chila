/* Copyright 2011-2015 Roberto Daniel Gimenez Gamarra (chilabot@gmail.com)
 * (C.I.: 1.439.390 - Paraguay)
 */

#include "TextEditorData.hpp"
#include <chila/lib/qt/util.hpp>
#include <QQmlProperty>

#include "macros.fgen.hpp"

MY_NSP_START
{
//    inline bool isIdChar(char c)
//    {
//        return (c >= 'a' && c <= 'z') ||
//               (c >= 'A' && c <= 'Z') ||
//               (c >= '0' && c <= '9') ||
//               (c == '_');
//    }
//
    TextEditorData::TextEditorData(FileIdSCPtr id, std::string type, QObject &textArea, boost::any eventExecuter) :
        id(rvalue_cast(id)),
        type(rvalue_cast(type)),
        textArea(textArea),
        eventExecuter(rvalue_cast(eventExecuter))
    {
//        tChangedProp

//        qtSigConns.textChanged = clMisc::toSharedPtr(clQt::connectSignal<0>(textArea, SIGNAL("textChanged()")));

//        textArea.setProperty("text", QString("test"));

//        clQt::showChildren(textArea);

//        textArea.

//        addPredefinedTags();
    }
//
//    TextEditorData::TextTagPtr TextEditorData::createTag(double red, double green, double blue)
//    {
//        auto tag = Gtk::TextTag::create();
//
//        Gdk::Color color;
//        color.set_rgb_p(red, green, blue);
//        tag->property_background_gdk() = color;
//
//        return tag;
//    }
//
    std::string TextEditorData::getContents() const
    {
        auto text = textArea.property("text");

        return text.value<QString>().toStdString();
    }

    void TextEditorData::setContents(const std::string &text)
    {
        textArea.setProperty("text", QString(text.c_str()));
    }


//    void TextEditorData::addAction(const BufferActionBaseSPtr &action)
//    {
//        if (bActionIt != bActionList.end())
//            bActionList.erase(bActionIt, bActionList.end());
//
//        bActionList.push_back(action);
//        bActionIt = bActionList.end();
//    };
//
//    void TextEditorData::undo()
//    {
//        if (!bActionList.empty() && bActionIt != bActionList.begin())
//        {
//            auto blocker = slots.buffer.blocker();
//            (*--bActionIt)->undo(textView.get_buffer());
//        }
//    }
//
//    void TextEditorData::redo()
//    {
//        if (bActionIt != bActionList.end())
//        {
//            auto blocker = slots.buffer.blocker();
//            (*bActionIt++)->redo(textView.get_buffer());
//        }
//    }
//
//    void TextEditorData::clearActions()
//    {
//        bActionList.clear();
//        bActionIt = bActionList.end();
//    }
//
//    void TextEditorData::addAction(BufferAction::Type type, unsigned pos, const Glib::ustring &text, const ModifyTextFun &modifyText)
//    {
//        auto action = std::make_shared<BufferAction>(type, pos, text);
//
//        if (bActionList.empty() || text.size() > 1)
//        {
//            addAction(action);
//        }
//        else
//        {
//            auto lastAction = std::dynamic_pointer_cast<BufferAction>(*(bActionList.end() - 1));
//
//            if (text.size() == 1 && lastAction && type == lastAction->type)
//            {
//                char c = *text.begin();
//                auto lastActionChar = *lastAction->text.begin();
//
//                auto cond = (isIdChar(c) && isIdChar(lastActionChar)) || (c == ' ' && lastActionChar == ' ');
//
//                if (!cond || (cond && !modifyText(pos, *lastAction)))
//                    addAction(action);
//            }
//            else addAction(action);
//        }
//    }
//
//    Gtk::TextIter TextEditorData::insertText(const Gtk::TextIter &it, const std::string &text)
//    {
//        auto buffer = textView.get_buffer();
//        auto pos = std::distance(buffer->begin(), it);
//        auto ret = buffer->insert(it, text);
//        addAction(std::make_shared<BufferAction>(BufferAction::Type::INSERT, pos, text));
//
//        return ret;
//    }
//
//    Gtk::TextIter TextEditorData::eraseText(const Gtk::TextIter &begin, const Gtk::TextIter &end)
//    {
//        auto buffer = textView.get_buffer();
//        auto pos = std::distance(buffer->begin(), begin);
//        auto text = std::string(begin, end);
//        auto ret = buffer->erase(begin, end);
//        addAction(std::make_shared<BufferAction>(BufferAction::Type::ERASE, pos, text));
//
//        return ret;
//    }
//
//    std::pair<Gtk::TextIter, Gtk::TextIter> TextEditorData::replace(const Gtk::TextIter &begin, const Gtk::TextIter &end, const std::string &text)
//    {
//        auto buffer = textView.get_buffer();
//        auto pos = std::distance(buffer->begin(), begin);
//        auto erasedText = std::string(begin, end);
//        auto erasedIt = buffer->erase(begin, end);
//        auto endIt = buffer->insert(erasedIt, text);
//
//        auto &aGroup = addActionGroup();
//
//        aGroup.add(std::make_shared<lib::BufferAction>(lib::BufferAction::Type::ERASE, pos, erasedText));
//        aGroup.add(std::make_shared<lib::BufferAction>(lib::BufferAction::Type::INSERT, pos, text));
//
//        auto startIt = endIt;
//        std::advance(startIt, -text.size());
//
//        return { startIt, endIt };
//    }
//
//    void TextEditorData::addPredefinedTags()
//    {
//        auto tagTable = textView.get_buffer()->get_tag_table();
//
//        tagTable->add(highlightTag);
//        tagTable->add(selFindTag);
//    }
}
MY_NSP_END
