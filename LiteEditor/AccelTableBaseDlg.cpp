//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: AccelTableBaseDlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "AccelTableBaseDlg.h"


// Declare the bitmap loading function
extern void wxCFD7DInitBitmapResources();

static bool bBitmapLoaded = false;


AccelTableBaseDlg::AccelTableBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCFD7DInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* bSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizer1);
    
    wxBoxSizer* bSizer5 = new wxBoxSizer(wxHORIZONTAL);
    
    bSizer1->Add(bSizer5, 0, wxEXPAND, 5);
    
    m_staticText1 = new wxStaticText(this, wxID_ANY, _("Filter:"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    bSizer5->Add(m_staticText1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlFilter = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_textCtrlFilter->SetToolTip(_("Type here to find an entry by its action"));
    m_textCtrlFilter->SetFocus();
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlFilter->SetHint(wxT(""));
    #endif
    
    bSizer5->Add(m_textCtrlFilter, 1, wxALL, 5);
    
    wxBoxSizer* bSizer4 = new wxBoxSizer(wxHORIZONTAL);
    
    bSizer1->Add(bSizer4, 1, wxEXPAND, 5);
    
    m_dataview = new wxDataViewCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(300,-1), wxDV_VERT_RULES|wxDV_ROW_LINES|wxDV_SINGLE);
    
    m_dataviewModel = new KeyboardAcceleModel;
    m_dataviewModel->SetColCount( 2 );
    m_dataview->AssociateModel(m_dataviewModel.get() );
    
    bSizer4->Add(m_dataview, 1, wxALL|wxEXPAND, 5);
    
    m_dataview->AppendTextColumn(_("Action"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
    m_dataview->AppendTextColumn(_("Keyboard Shortcut"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
    wxBoxSizer* bSizer3 = new wxBoxSizer(wxVERTICAL);
    
    bSizer4->Add(bSizer3, 0, wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_buttonEdit = new wxButton(this, wxID_ANY, _("&Edit..."), wxDefaultPosition, wxSize(-1, -1), 0);
    
    bSizer3->Add(m_buttonEdit, 0, wxALL, 5);
    
    m_buttonDefault = new wxButton(this, wxID_ANY, _("&Defaults"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    bSizer3->Add(m_buttonDefault, 0, wxALL, 5);
    
    m_stdBtnSizer6 = new wxStdDialogButtonSizer();
    
    bSizer1->Add(m_stdBtnSizer6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_button8 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button8->SetDefault();
    m_stdBtnSizer6->AddButton(m_button8);
    
    m_button10 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer6->AddButton(m_button10);
    m_stdBtnSizer6->Realize();
    
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_textCtrlFilter->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AccelTableBaseDlg::OnText), NULL, this);
    m_dataview->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(AccelTableBaseDlg::OnDVItemActivated), NULL, this);
    m_buttonEdit->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AccelTableBaseDlg::OnEditButton), NULL, this);
    m_buttonEdit->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(AccelTableBaseDlg::OnEditUI), NULL, this);
    m_buttonDefault->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AccelTableBaseDlg::OnButtonDefaults), NULL, this);
    m_button8->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AccelTableBaseDlg::OnButtonOk), NULL, this);
    
}

AccelTableBaseDlg::~AccelTableBaseDlg()
{
    m_textCtrlFilter->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(AccelTableBaseDlg::OnText), NULL, this);
    m_dataview->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(AccelTableBaseDlg::OnDVItemActivated), NULL, this);
    m_buttonEdit->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AccelTableBaseDlg::OnEditButton), NULL, this);
    m_buttonEdit->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(AccelTableBaseDlg::OnEditUI), NULL, this);
    m_buttonDefault->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AccelTableBaseDlg::OnButtonDefaults), NULL, this);
    m_button8->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AccelTableBaseDlg::OnButtonOk), NULL, this);
    
}
