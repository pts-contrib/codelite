//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : findreplacedlg.cpp
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
#include "findreplacedlg.h"
#include <wx/msgdlg.h>
#include "editor_config.h"
#include <wx/gbsizer.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include "macros.h"

DEFINE_EVENT_TYPE(wxEVT_FRD_FIND_NEXT)
DEFINE_EVENT_TYPE(wxEVT_FRD_CLOSE)
DEFINE_EVENT_TYPE(wxEVT_FRD_REPLACE)
DEFINE_EVENT_TYPE(wxEVT_FRD_REPLACEALL)
DEFINE_EVENT_TYPE(wxEVT_FRD_BOOKMARKALL)
DEFINE_EVENT_TYPE(wxEVT_FRD_CLEARBOOKMARKS)

BEGIN_EVENT_TABLE(FindReplaceDialog, wxDialog)
	EVT_CLOSE(FindReplaceDialog::OnClose)
	EVT_CHAR_HOOK(FindReplaceDialog::OnKeyDown)
END_EVENT_TABLE()

#define VALIDATE_FINDWHAT(){\
	if(m_findString->GetValue().Trim().IsEmpty()){\
			wxMessageBox(wxT("'Find What' is empty"));\
			return;\
		}\
}

FindReplaceDialog::FindReplaceDialog()
		: wxDialog()
		, m_owner(NULL)
		, m_kind(FIND_DLG)
{
}

FindReplaceDialog::FindReplaceDialog(wxWindow* parent,
                                     const FindReplaceData& data,
                                     wxWindowID id,
                                     const wxString& caption,
                                     const wxPoint& pos,
                                     const wxSize& size,
                                     long style)
{
	Create(parent, data, id, caption, pos, size, style | wxWANTS_CHARS);
}

bool FindReplaceDialog::Create(wxWindow* parent,
                               const FindReplaceData& data,
                               wxWindowID id,
                               const wxString& caption,
                               const wxPoint& pos,
                               const wxSize& size,
                               long style)
{
	m_kind = FIND_DLG;
	if ( !wxDialog::Create(parent, id, caption, pos, size, style) )
		return false;

	m_data = data;
	m_owner = NULL;

	CreateGUIControls();
	ConnectEvents();

	GetSizer()->Fit(this);
	Centre();

	m_findString->SetFocus();
	return true;
}

FindReplaceDialog::~FindReplaceDialog()
{
}

void FindReplaceDialog::CreateGUIControls()
{
	wxBoxSizer *hMainSzier = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *btnSizer = new wxBoxSizer(wxVERTICAL);
	gbSizer = new wxGridBagSizer();
	SetSizer(hMainSzier);

	hMainSzier->Add(gbSizer, 1, wxEXPAND | wxALL, 5);
	hMainSzier->Add(btnSizer, 0, wxALL, 5);

	wxStaticText* itemStaticText;
	itemStaticText = new wxStaticText( this, wxID_STATIC, wxT("Find What:"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	gbSizer->Add(itemStaticText, wxGBPosition(0, 0), wxDefaultSpan, wxALL | wxEXPAND, 5 );

	m_findString = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1));
	gbSizer->Add(m_findString, wxGBPosition(0, 1), wxDefaultSpan, wxALL | wxEXPAND, 5 );

	m_replaceWithLabel = new wxStaticText( this, wxID_STATIC, wxT("Replace With:"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	gbSizer->Add(m_replaceWithLabel, wxGBPosition(1, 0), wxDefaultSpan, wxALL | wxEXPAND, 5 );

	m_replaceString = new wxComboBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition);
	gbSizer->Add(m_replaceString, wxGBPosition(1, 1), wxDefaultSpan, wxALL | wxEXPAND, 5 );

	sz = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Options"));
	gbSizer->Add(sz, wxGBPosition(2, 0), wxGBSpan(1, 2),  wxALL | wxEXPAND, 5 );

	m_matchCase = new wxCheckBox(this, wxID_ANY, wxT("&Match case"));
	sz->Add(m_matchCase, 1, wxALL | wxEXPAND, 5 );

	m_matchWholeWord = new wxCheckBox(this, wxID_ANY, wxT("Match &whole word"));
	sz->Add(m_matchWholeWord, 1, wxALL | wxEXPAND, 5 );

	m_regualrExpression = new wxCheckBox(this, wxID_ANY, wxT("Regular &expression"));
	sz->Add(m_regualrExpression, 1, wxALL | wxEXPAND, 5 );

	m_searchUp = new wxCheckBox(this, wxID_ANY, wxT("Search &up"));
	sz->Add(m_searchUp, 1, wxALL | wxEXPAND, 5 );

	m_selectionOnly = new wxCheckBox(this, wxID_ANY, wxT("Search / Replace in selec&ted text"));
	sz->Add(m_selectionOnly, 1, wxALL | wxEXPAND, 5 );

	// Add the buttons

	m_find = new wxButton(this, wxID_ANY, wxT("&Find Next"));
	btnSizer->Add(m_find, 1, wxALL | wxEXPAND, 5 );

	m_replace = new wxButton(this, wxID_ANY, wxT("&Replace"));
	btnSizer->Add(m_replace, 1, wxALL | wxEXPAND, 5 );

	m_replaceAll = new wxButton(this, wxID_ANY, wxT("Replace &All"));
	btnSizer->Add(m_replaceAll, 1, wxALL | wxEXPAND, 5 );

	m_markAll = new wxButton(this, wxID_ANY, wxT("&Bookmark All"));
	btnSizer->Add(m_markAll, 1, wxALL | wxEXPAND, 5 );

	m_clearBookmarks = new wxButton(this, wxID_ANY, wxT("&Clear Bookmarks"));
	btnSizer->Add(m_clearBookmarks, 1, wxALL | wxEXPAND, 5 );

	m_cancel = new wxButton(this, wxID_ANY, wxT("Close"));
	btnSizer->Add(m_cancel, 1, wxALL | wxEXPAND, 5 );

	m_replacementsMsg = new wxStaticText(this, wxID_ANY, wxEmptyString);
	btnSizer->Add(m_replacementsMsg, 1, wxALL | wxEXPAND, 5 );
	//gbSizer->Add(m_replacementsMsg, wxGBPosition(3, 0), wxGBSpan(1, 2), wxALL | wxEXPAND, 5);
	SetReplacementsMessage(frd_dontshowzeros);

	//set values
	SetFindReplaceData(m_data, true);
}

void FindReplaceDialog::SetFindReplaceData(FindReplaceData &data, bool focus)
{
	m_findString->Freeze();

	m_findString->Clear();
	m_findString->Append(data.GetFindStringArr());
	m_findString->SetValue(data.GetFindString());

	m_findString->Thaw();

	m_replaceString->Freeze();

	m_replaceString->Clear();
	m_replaceString->Append(data.GetReplaceStringArr());
	m_replaceString->SetValue(data.GetReplaceString());

	m_replaceString->Thaw();

	m_matchCase->SetValue(data.GetFlags() & wxFRD_MATCHCASE ? true : false);
	m_matchWholeWord->SetValue(data.GetFlags() & wxFRD_MATCHWHOLEWORD ? true : false);
	m_regualrExpression->SetValue(data.GetFlags() & wxFRD_REGULAREXPRESSION ? true : false);
	m_searchUp->SetValue(data.GetFlags() & wxFRD_SEARCHUP ? true : false);
	m_selectionOnly->SetValue(data.GetFlags() & wxFRD_SELECTIONONLY ? true : false);

	//set the focus to the find string text control
	if(focus) {
		m_findString->SetFocus();
		m_findString->SetSelection(-1, -1); // select all
	}
}

void FindReplaceDialog::OnClick(wxCommandEvent &event)
{
	wxObject *btnClicked = event.GetEventObject();
	size_t flags = m_data.GetFlags();
	m_data.SetFindString( m_findString->GetValue() );
	m_data.SetReplaceString( m_replaceString->GetValue() );

	// disable the 'Find/Replace' buttons when the 'Selection only' is enabled
	if ( m_selectionOnly->IsChecked() ) {
		m_find->Enable(false);
		m_replace->Enable(false);
	} else {
		m_find->Enable(true);
		m_replace->Enable(true);
	}

	if (btnClicked == m_find) {
		VALIDATE_FINDWHAT();
		SendEvent(wxEVT_FRD_FIND_NEXT);
	} else if (btnClicked == m_replace) {
		VALIDATE_FINDWHAT();
		SendEvent(wxEVT_FRD_REPLACE);
	} else if (btnClicked == m_replaceAll) {
		VALIDATE_FINDWHAT();
		SendEvent(wxEVT_FRD_REPLACEALL);
	} else if (btnClicked == m_markAll) {
		VALIDATE_FINDWHAT();
		SendEvent(wxEVT_FRD_BOOKMARKALL);
	} else if (btnClicked == m_clearBookmarks) {
		SendEvent(wxEVT_FRD_CLEARBOOKMARKS);
	} else if (btnClicked == m_cancel) {
		// Fire a close event
		SendEvent(wxEVT_FRD_CLOSE);
		// Hide the dialog
		Hide();
	} else if (btnClicked == m_matchCase) {
		if (m_matchCase->IsChecked()) {
			flags |= wxFRD_MATCHCASE;
		} else {
			flags &= ~(wxFRD_MATCHCASE);
		}
	} else if (btnClicked == m_matchWholeWord) {
		if (m_matchWholeWord->IsChecked()) {
			flags |= wxFRD_MATCHWHOLEWORD;
		} else {
			flags &= ~(wxFRD_MATCHWHOLEWORD);
		}
	} else if (btnClicked == m_regualrExpression) {
		if (m_regualrExpression->IsChecked()) {
			flags |= wxFRD_REGULAREXPRESSION;
		} else {
			flags &= ~(wxFRD_REGULAREXPRESSION);
		}
	} else if (btnClicked == m_searchUp) {
		if (m_searchUp->IsChecked()) {
			flags |= wxFRD_SEARCHUP;
		} else {
			flags &= ~(wxFRD_SEARCHUP);
		}
	} else if (btnClicked == m_selectionOnly) {
		if (m_selectionOnly->IsChecked()) {
			flags |= wxFRD_SELECTIONONLY;
		} else {
			flags &= ~(wxFRD_SELECTIONONLY);
		}
	}

	// Set the updated flags, unless it was ReplaceAll which does this itself
	if (btnClicked != m_replaceAll) {
		m_data.SetFlags(flags);
	}
	
	// update the data of the find/replace dialog, in particular, 
	// update the history of the Find What / replace with controls
	SetFindReplaceData(m_data, false);
}

void FindReplaceDialog::OnClose(wxCloseEvent &event)
{
	wxUnusedVar(event);

	// Fire a close event
	SendEvent(wxEVT_FRD_CLOSE);
	Hide();
}
void FindReplaceDialog::OnKeyDown(wxKeyEvent &event)
{
	if (event.GetKeyCode() == WXK_RETURN || event.GetKeyCode() == WXK_NUMPAD_ENTER) {
		// start the search
		size_t flags = m_data.GetFlags();
		m_data.SetFindString( m_findString->GetValue() );
		m_data.SetReplaceString( m_replaceString->GetValue() );
		SendEvent(wxEVT_FRD_FIND_NEXT);
		// Set the updated flags
		m_data.SetFlags(flags);
		event.Skip(false);
		return;
	} // if(event.GetKeyCode() == WXK_RETURN)

	if (event.GetKeyCode() == WXK_ESCAPE) {
		//hide the find/replace dialog
		if (IsShown()) {
			Hide();
			event.Skip(false);
			return;
		}
	}
	event.Skip();
}

void FindReplaceDialog::ConnectEvents()
{
	// Connect buttons
	m_find->Connect(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindReplaceDialog::OnClick), NULL, this);
	m_replace->Connect(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindReplaceDialog::OnClick), NULL, this);
	m_replaceAll->Connect(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindReplaceDialog::OnClick), NULL, this);
	m_markAll->Connect(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindReplaceDialog::OnClick), NULL, this);
	m_cancel->Connect(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindReplaceDialog::OnClick), NULL, this);
	m_clearBookmarks->Connect(wxID_ANY, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FindReplaceDialog::OnClick), NULL, this);

	// connect options
	m_matchCase->Connect(wxID_ANY, wxEVT_COMMAND_CHECKBOX_CLICKED , wxCommandEventHandler(FindReplaceDialog::OnClick), NULL, this);
	m_matchWholeWord->Connect(wxID_ANY, wxEVT_COMMAND_CHECKBOX_CLICKED , wxCommandEventHandler(FindReplaceDialog::OnClick), NULL, this);
	m_regualrExpression->Connect(wxID_ANY, wxEVT_COMMAND_CHECKBOX_CLICKED , wxCommandEventHandler(FindReplaceDialog::OnClick), NULL, this);
	m_searchUp->Connect(wxID_ANY, wxEVT_COMMAND_CHECKBOX_CLICKED , wxCommandEventHandler(FindReplaceDialog::OnClick), NULL, this);
	m_selectionOnly->Connect(wxID_ANY, wxEVT_COMMAND_CHECKBOX_CLICKED , wxCommandEventHandler(FindReplaceDialog::OnClick), NULL, this);
}

void FindReplaceDialog::SendEvent(wxEventType type)
{
	wxCommandEvent event(type, GetId());
	event.SetEventObject(this);

	if ( GetEventOwner() == NULL ){
		GetEventHandler()->ProcessEvent( event );
	}else{
		// If an event owner was provided, pass it the event
		GetEventOwner()->ProcessEvent( event );
	}
}

bool FindReplaceDialog::Show(int kind)
{
	if ( IsShown() ) {
		if (m_kind == kind) {
			return true;
		}
		//change the dialog
		ShowReplaceControls(true);
		return true;
	}

	if(kind == FIND_DLG) {
		ShowReplaceControls(false);
	}else{
		ShowReplaceControls(true);
	}

	// call Show() here
	bool res = wxDialog::Show();

	// and now call the focus methods
	SetFindReplaceData(m_data, true);
	m_findString->SetSelection(-1, -1); // select all
	m_findString->SetFocus();
	return res;
}

void FindReplaceDialog::ShowReplaceControls(bool show)
{
	//detach the find string & its label from the gridbag sizer
	bool isFindDlg(false);
	isFindDlg = gbSizer->GetItemPosition(sz) == wxGBPosition(1, 0);
	if (show == false) {
		//is this dialog is already a 'Find' dialog?
		if (isFindDlg) {
			return;
		}

		//remove 'Replace' dialog items
		gbSizer->Detach(m_replaceWithLabel);
		gbSizer->Detach(m_replaceString);

		//reposition the options static sizer
		gbSizer->Detach(sz);
		gbSizer->Add(sz, wxGBPosition(1, 0), wxGBSpan(1, 2),  wxALL | wxEXPAND, 5 );
		
	} else {
		// is this dialog is already a 'Replace' dialog?
		if (!isFindDlg) {
			return;
		}

		//remmove the 'Options' item frmo pos 1,0
		gbSizer->Detach(sz);
		gbSizer->Add(m_replaceWithLabel, wxGBPosition(1, 0), wxDefaultSpan, wxALL | wxEXPAND, 5 );
		gbSizer->Add(m_replaceString, wxGBPosition(1, 1), wxDefaultSpan, wxALL | wxEXPAND, 5 );
		gbSizer->Add(sz, wxGBPosition(2, 0), wxGBSpan(1, 2),  wxALL | wxEXPAND, 5 );
	}
	
	wxString label = show ? wxT("Replace") : wxT("Find");
	m_replace->Show(show);
	m_replaceAll->Show(show);
	m_replaceString->Show(show);
	m_replacementsMsg->Show(show);
	m_replaceWithLabel->Show(show);
	m_selectionOnly->Show(show);
	
	SetLabel(label);
	this->Fit();
	GetSizer()->Layout();
}

void FindReplaceDialog::SetReplacementsMessage( enum frd_showzero showzero /*= frd_showzeros*/ )
{
	if ( showzero==frd_dontshowzeros && GetReplacedCount()==0 ) { // Don't show a count of 0 before any replacement has started
		m_replacementsMsg->SetLabel(wxString::Format(wxT("Replacements:")));
	} else {
		m_replacementsMsg->SetLabel(wxString::Format(wxT("Replacements: %u"), GetReplacedCount() ));
	}
}

void FindReplaceDialog::ResetSelectionOnlyFlag()
{
	size_t flags = GetData().GetFlags();
	GetData().SetFlags( flags & ~(wxFRD_SELECTIONONLY) );
}

//---------------------------------------------------------------
// FindReplaceData
//---------------------------------------------------------------

void FindReplaceData::SetReplaceString(const wxString& str)
{
	
	int where = m_replaceString.Index(str);
	if (where != wxNOT_FOUND) {
		m_replaceString.RemoveAt(where);
	}
	m_replaceString.Insert(str, 0);
	
	long max_value(10);
	EditorConfigST::Get()->GetLongValue(wxT("MaxItemsInFindReplaceDialog"), max_value);
	TruncateArray(m_replaceString, (size_t)max_value);
}

void FindReplaceData::Serialize(Archive& arch)
{
	arch.Write(wxT("m_findString"), m_findString);
	arch.Write(wxT("m_replaceString"), m_replaceString);
	arch.Write(wxT("m_flags"), (long)m_flags);
}

void FindReplaceData::DeSerialize(Archive& arch)
{
	arch.Read(wxT("m_findString"), m_findString);
	arch.Read(wxT("m_replaceString"), m_replaceString);
	arch.Read(wxT("m_flags"), (long&)m_flags);
	
	long max_value(10);
	EditorConfigST::Get()->GetLongValue(wxT("MaxItemsInFindReplaceDialog"), max_value);
	TruncateArray(m_findString, (size_t)max_value);
	TruncateArray(m_replaceString, (size_t)max_value);
}

void FindReplaceData::SetFindString(const wxString& str)
{
	int where = m_findString.Index(str);
	if (where != wxNOT_FOUND) {
		m_findString.RemoveAt(where);
	}
	m_findString.Insert(str, 0);
	
	long max_value(10);
	EditorConfigST::Get()->GetLongValue(wxT("MaxItemsInFindReplaceDialog"), max_value);
	TruncateArray(m_findString, (size_t)max_value);
}

wxString FindReplaceData::GetReplaceString() const
{
	if (m_replaceString.IsEmpty()) {
		return wxEmptyString;
	} else {
		return m_replaceString.Item(0);
	}
}

wxString FindReplaceData::GetFindString() const
{
	if (m_findString.IsEmpty()) {
		return wxEmptyString;
	} else {
		return m_findString.Item(0);
	}
}

void FindReplaceData::TruncateArray(wxArrayString& arr, size_t maxSize)
{
	while(arr.GetCount() > maxSize && arr.GetCount() > 0) {
		arr.RemoveAt(arr.GetCount()-1);
	}
}
