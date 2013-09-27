//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : context_manager.cpp
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#include <wx/tokenzr.h>
#include "context_manager.h"
#include "context_cpp.h"
#include "context_diff.h"
#include "context_base.h"
#include "context_html.h"
#include "generic_context.h"
#include "editor_config.h"

ContextManager::ContextManager()
{
    // register available contexts
    m_contextPool["c++"]  = new ContextCpp();
    m_contextPool["diff"] = new ContextDiff();
    m_contextPool["html"] = new ContextHtml();

    // load generic lexers
    EditorConfig::ConstIterator iter = EditorConfigST::Get()->LexerBegin();
    for(; iter != EditorConfigST::Get()->LexerEnd(); iter++) {
        LexerConfPtr lex = iter->second;
        if (m_contextPool.find(lex->GetName()) == m_contextPool.end()) {
            m_contextPool[lex->GetName()] = new ContextGeneric(lex->GetName());
        }
    }

    // make sure there is a "fallback" lexer for unrecognized file types
    if (m_contextPool.find("text") == m_contextPool.end()) {
        m_contextPool[wxT("text")] = new ContextGeneric(wxT("text"));
    }
}

ContextManager::~ContextManager()
{
}

ContextBasePtr ContextManager::NewContext(LEditor *parent, const wxString &lexerName)
{
    // this function is actually a big switch ....
    wxString lex_name = lexerName;
    lex_name.MakeLower();
    std::map<wxString, ContextBasePtr>::iterator iter = m_contextPool.find(lex_name);
    if( iter == m_contextPool.end()) {
        return m_contextPool["text"]->NewInstance(parent);
    }

    return iter->second->NewInstance( (LEditor*)parent );
}

ContextBasePtr ContextManager::NewContextByFileName (LEditor *parent, const wxFileName &fileName)
{
    LexerConfPtr lexer = EditorConfigST::Get()->GetLexerForFile(fileName.GetFullName());
    if ( !lexer ) {
        // could not locate a lexer for this file name, return the default text lexer
        return ContextManager::Get()->NewContext ( parent, wxT ( "Text" ) );
    }
    return ContextManager::Get()->NewContext ( parent, lexer->GetName() );
}
