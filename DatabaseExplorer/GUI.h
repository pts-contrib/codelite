//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: GUI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef CL_DATABASEEXPLORER_GUI_BASE_CLASSES_H
#define CL_DATABASEEXPLORER_GUI_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/pen.h>
#include <wx/aui/auibar.h>
#include <map>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/splitter.h>
#include <wx/stc/stc.h>
#include <wx/grid.h>
#include <wx/treectrl.h>
#include <wx/notebook.h>
#include <wx/imaglist.h>
#include <wx/filepicker.h>
#include <wx/listctrl.h>
#include <wx/listbox.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/gbsizer.h>
#include <wx/radiobox.h>
#include <wx/infobar.h>
#include <wx/dataview.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class _ImageExportDialog : public wxDialog
{
protected:
    wxStaticText* m_staticText34;
    wxTextCtrl* m_textCtrlPath;
    wxButton* m_button29;
    wxRadioButton* m_radioBtnDefaultScale;
    wxRadioButton* m_radioBtnScaleCustom;
    wxTextCtrl* m_textCtrlScale;
    wxCheckBox* m_checkBoxBackground;
    wxStdDialogButtonSizer* m_sdbSizer2;
    wxButton* m_button126;
    wxButton* m_button127;

protected:
    virtual void OnInit(wxInitDialogEvent& event) { event.Skip(); }
    virtual void OnBowseClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateCustomScale(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText34() { return m_staticText34; }
    wxTextCtrl* GetTextCtrlPath() { return m_textCtrlPath; }
    wxButton* GetButton29() { return m_button29; }
    wxRadioButton* GetRadioBtnDefaultScale() { return m_radioBtnDefaultScale; }
    wxRadioButton* GetRadioBtnScaleCustom() { return m_radioBtnScaleCustom; }
    wxTextCtrl* GetTextCtrlScale() { return m_textCtrlScale; }
    wxCheckBox* GetCheckBoxBackground() { return m_checkBoxBackground; }
    _ImageExportDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Export image"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~_ImageExportDialog();
};


class _ThumbPane : public wxPanel
{
protected:

protected:

public:
    _ThumbPane(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300), long style = wxTAB_TRAVERSAL);
    virtual ~_ThumbPane();
};


class _SqlCommandPanel : public wxPanel
{
public:
    enum {
        ID_INSERT_TEMPLATE = 1001,
        ID_SQL_HISTORY = 1002,
    };
protected:
    wxAuiToolBar* m_auibar167;
    std::map<int, wxMenu*> m_dropdownMenus;
    wxMenu* m_menu183;
    wxMenu* m_menu184;
    wxSplitterWindow* m_splitter1;
    wxPanel* m_panel13;
    wxStyledTextCtrl* m_scintillaSQL;
    wxPanel* m_panel14;
    wxGrid* m_gridTable;
    wxStaticText* m_labelStatus;

protected:
    virtual void OnLoadClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSaveClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnExecuteClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnTemplatesBtnClick(wxAuiToolBarEvent& event) { event.Skip(); }
    virtual void OnHistoryToolClicked(wxAuiToolBarEvent& event) { event.Skip(); }
    virtual void OnGridCellRightClick(wxGridEvent& event) { event.Skip(); }

public:

    virtual void ShowAuiToolMenu(wxAuiToolBarEvent& event);
    wxAuiToolBar* GetAuibar167() { return m_auibar167; }
    wxStyledTextCtrl* GetScintillaSQL() { return m_scintillaSQL; }
    wxPanel* GetPanel13() { return m_panel13; }
    wxGrid* GetGridTable() { return m_gridTable; }
    wxStaticText* GetLabelStatus() { return m_labelStatus; }
    wxPanel* GetPanel14() { return m_panel14; }
    wxSplitterWindow* GetSplitter1() { return m_splitter1; }
    _SqlCommandPanel(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxTAB_TRAVERSAL);
    virtual ~_SqlCommandPanel();
};


class _AdapterSelectDlg : public wxDialog
{
protected:
    wxButton* m_btnSqlite;
    wxButton* m_btnMySql;
    wxButton* m_button24;

protected:
    virtual void OnSqliteClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMysqlClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPostgresClick(wxCommandEvent& event) { event.Skip(); }

public:
    wxButton* GetBtnSqlite() { return m_btnSqlite; }
    wxButton* GetBtnMySql() { return m_btnMySql; }
    wxButton* GetButton24() { return m_button24; }
    _AdapterSelectDlg(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Select dbAdapter"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~_AdapterSelectDlg();
};


class _DbViewerPanel : public wxPanel
{
protected:
    wxAuiToolBar* m_auibar;
    wxTreeCtrl* m_treeDatabases;

protected:
    virtual void OnDnDStart(wxTreeEvent& event) { event.Skip(); }
    virtual void OnItemActivate(wxTreeEvent& event) { event.Skip(); }
    virtual void OnItemSelectionChange(wxTreeEvent& event) { event.Skip(); }
    virtual void OnContextMenu(wxTreeEvent& event) { event.Skip(); }
    virtual void OnItemRightClick(wxTreeEvent& event) { event.Skip(); }

public:
    wxAuiToolBar* GetAuibar() { return m_auibar; }
    wxTreeCtrl* GetTreeDatabases() { return m_treeDatabases; }
    _DbViewerPanel(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(200,100), long style = wxTAB_TRAVERSAL);
    virtual ~_DbViewerPanel();
};


class _DBSettingsDialog : public wxDialog
{
protected:
    wxNotebook* m_notebook2;
    wxPanel* m_Sqlite;
    wxStaticText* m_staticText11;
    wxFilePickerCtrl* m_filePickerSqlite;
    wxListCtrl* m_listCtrlRecentFiles;
    wxPanel* m_MySqlPanel;
    wxStaticText* m_staticText10;
    wxTextCtrl* m_txName;
    wxStaticText* m_staticText1;
    wxTextCtrl* m_txServer;
    wxStaticText* m_staticText2;
    wxTextCtrl* m_txUserName;
    wxStaticText* m_staticText3;
    wxTextCtrl* m_txPassword;
    wxListBox* m_listBox2;
    wxPanel* m_PostgrePanel;
    wxStaticText* m_staticText101;
    wxTextCtrl* m_txPgName;
    wxStaticText* m_staticText12;
    wxTextCtrl* m_txPgServer;
    wxStaticText* m_staticText35;
    wxTextCtrl* m_txPgPort;
    wxStaticText* m_staticText21;
    wxTextCtrl* m_txPgUserName;
    wxStaticText* m_staticText31;
    wxTextCtrl* m_txPgPassword;
    wxStaticText* m_staticText24;
    wxTextCtrl* m_txPgDatabase;
    wxListBox* m_listBoxPg;
    wxButton* m_button36;
    wxButton* m_button35;

protected:
    virtual void OnItemActivated(wxListEvent& event) { event.Skip(); }
    virtual void OnItemSelected(wxListEvent& event) { event.Skip(); }
    virtual void OnItemKeyDown(wxListEvent& event) { event.Skip(); }
    virtual void OnMySqlPassKeyDown(wxKeyEvent& event) { event.Skip(); }
    virtual void OnHistoryClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnHistoryDClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnHistoruUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnPgSqlKeyDown(wxKeyEvent& event) { event.Skip(); }
    virtual void OnPgHistoryClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPgHistoryDClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDlgOK(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText11() { return m_staticText11; }
    wxFilePickerCtrl* GetFilePickerSqlite() { return m_filePickerSqlite; }
    wxListCtrl* GetListCtrlRecentFiles() { return m_listCtrlRecentFiles; }
    wxPanel* GetSqlite() { return m_Sqlite; }
    wxStaticText* GetStaticText10() { return m_staticText10; }
    wxTextCtrl* GetTxName() { return m_txName; }
    wxStaticText* GetStaticText1() { return m_staticText1; }
    wxTextCtrl* GetTxServer() { return m_txServer; }
    wxStaticText* GetStaticText2() { return m_staticText2; }
    wxTextCtrl* GetTxUserName() { return m_txUserName; }
    wxStaticText* GetStaticText3() { return m_staticText3; }
    wxTextCtrl* GetTxPassword() { return m_txPassword; }
    wxListBox* GetListBox2() { return m_listBox2; }
    wxPanel* GetMySqlPanel() { return m_MySqlPanel; }
    wxStaticText* GetStaticText101() { return m_staticText101; }
    wxTextCtrl* GetTxPgName() { return m_txPgName; }
    wxStaticText* GetStaticText12() { return m_staticText12; }
    wxTextCtrl* GetTxPgServer() { return m_txPgServer; }
    wxStaticText* GetStaticText35() { return m_staticText35; }
    wxTextCtrl* GetTxPgPort() { return m_txPgPort; }
    wxStaticText* GetStaticText21() { return m_staticText21; }
    wxTextCtrl* GetTxPgUserName() { return m_txPgUserName; }
    wxStaticText* GetStaticText31() { return m_staticText31; }
    wxTextCtrl* GetTxPgPassword() { return m_txPgPassword; }
    wxStaticText* GetStaticText24() { return m_staticText24; }
    wxTextCtrl* GetTxPgDatabase() { return m_txPgDatabase; }
    wxListBox* GetListBoxPg() { return m_listBoxPg; }
    wxPanel* GetPostgrePanel() { return m_PostgrePanel; }
    wxNotebook* GetNotebook2() { return m_notebook2; }
    wxButton* GetButton36() { return m_button36; }
    wxButton* GetButton35() { return m_button35; }
    _DBSettingsDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Connection settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~_DBSettingsDialog();
};


class _ErdPanel : public wxPanel
{
protected:
    wxAuiToolBar* m_toolBarErd;

protected:
    virtual void OnMouseWheel(wxMouseEvent& event) { event.Skip(); }

public:
    wxAuiToolBar* GetToolBarErd() { return m_toolBarErd; }
    _ErdPanel(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(640,480), long style = wxTAB_TRAVERSAL);
    virtual ~_ErdPanel();
};


class _CreateForeignKey : public wxDialog
{
protected:
    wxStaticText* m_staticText15;
    wxTextCtrl* m_txSrcTable;
    wxStaticText* m_staticText17;
    wxChoice* m_cmbSrcCol;
    wxRadioBox* m_radioRelation;
    wxRadioBox* m_radioOnDelete;
    wxRadioBox* m_radioOnUpdate;
    wxStaticText* m_staticText16;
    wxTextCtrl* m_txDstTable;
    wxStaticText* m_staticText18;
    wxChoice* m_cmbDstCol;
    wxButton* m_btnCancel;
    wxButton* m_btnOK;

protected:
    virtual void OnCancelClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOKClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOKUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText15() { return m_staticText15; }
    wxTextCtrl* GetTxSrcTable() { return m_txSrcTable; }
    wxStaticText* GetStaticText17() { return m_staticText17; }
    wxChoice* GetCmbSrcCol() { return m_cmbSrcCol; }
    wxRadioBox* GetRadioRelation() { return m_radioRelation; }
    wxRadioBox* GetRadioOnDelete() { return m_radioOnDelete; }
    wxRadioBox* GetRadioOnUpdate() { return m_radioOnUpdate; }
    wxStaticText* GetStaticText16() { return m_staticText16; }
    wxTextCtrl* GetTxDstTable() { return m_txDstTable; }
    wxStaticText* GetStaticText18() { return m_staticText18; }
    wxChoice* GetCmbDstCol() { return m_cmbDstCol; }
    wxButton* GetBtnCancel() { return m_btnCancel; }
    wxButton* GetBtnOK() { return m_btnOK; }
    _CreateForeignKey(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Create foreign key"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~_CreateForeignKey();
};


class _LogDialog : public wxDialog
{
protected:
    wxTextCtrl* m_textCtrl11;
    wxButton* m_button18;

protected:
    virtual void OnCloseClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnCloseUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxTextCtrl* GetTextCtrl11() { return m_textCtrl11; }
    wxButton* GetButton18() { return m_button18; }
    _LogDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Database log"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(640,460), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX);
    virtual ~_LogDialog();
};


class _ViewSettings : public wxDialog
{
protected:
    wxStaticText* m_staticText19;
    wxTextCtrl* m_txName;
    wxStyledTextCtrl* m_scintilla2;
    wxButton* m_btnOK;

protected:
    virtual void OnOKClick(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText19() { return m_staticText19; }
    wxTextCtrl* GetTxName() { return m_txName; }
    wxStyledTextCtrl* GetScintilla2() { return m_scintilla2; }
    wxButton* GetBtnOK() { return m_btnOK; }
    _ViewSettings(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("View settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(650,450), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX);
    virtual ~_ViewSettings();
};


class _ClassGenerateDialog : public wxDialog
{
protected:
    wxStaticText* m_staticText30;
    wxTextCtrl* m_txPrefix;
    wxStaticText* m_staticText31;
    wxTextCtrl* m_txPostfix;
    wxStaticText* m_staticText28;
    wxDirPickerCtrl* m_dirPicker;
    wxStaticText* m_staticText34;
    wxTextCtrl* m_txVirtualDir;
    wxButton* m_btnBrowseVirtualDir;
    wxStaticText* m_staticText36;
    wxChoice* m_choiceTemplates;
    wxStaticText* m_staticText29;
    wxTextCtrl* m_textLog;
    wxButton* m_button26;
    wxButton* m_button25;

protected:
    virtual void OnBtnBrowseClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnCancelClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnGenerateClick(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText30() { return m_staticText30; }
    wxTextCtrl* GetTxPrefix() { return m_txPrefix; }
    wxStaticText* GetStaticText31() { return m_staticText31; }
    wxTextCtrl* GetTxPostfix() { return m_txPostfix; }
    wxStaticText* GetStaticText28() { return m_staticText28; }
    wxDirPickerCtrl* GetDirPicker() { return m_dirPicker; }
    wxStaticText* GetStaticText34() { return m_staticText34; }
    wxTextCtrl* GetTxVirtualDir() { return m_txVirtualDir; }
    wxButton* GetBtnBrowseVirtualDir() { return m_btnBrowseVirtualDir; }
    wxStaticText* GetStaticText36() { return m_staticText36; }
    wxChoice* GetChoiceTemplates() { return m_choiceTemplates; }
    wxStaticText* GetStaticText29() { return m_staticText29; }
    wxTextCtrl* GetTextLog() { return m_textLog; }
    wxButton* GetButton26() { return m_button26; }
    wxButton* GetButton25() { return m_button25; }
    _ClassGenerateDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Class generator dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~_ClassGenerateDialog();
};


class _CodePreviewDialog : public wxDialog
{
protected:
    wxStyledTextCtrl* m_scintilla3;
    wxButton* m_button14;

protected:
    virtual void OnOKClick(wxCommandEvent& event) { event.Skip(); }

public:
    wxStyledTextCtrl* GetScintilla3() { return m_scintilla3; }
    wxButton* GetButton14() { return m_button14; }
    _CodePreviewDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("SQL Preview"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,470), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~_CodePreviewDialog();
};


class _TableSettings : public wxDialog
{
protected:
    wxInfoBar* m_infobar;
    wxStaticText* m_staticText23;
    wxTextCtrl* m_textName;
    wxSplitterWindow* m_splitter27;
    wxPanel* m_splitterPage31;
    wxStaticText* m_staticText55;
    wxAuiToolBar* m_auibar39;
    wxDataViewListCtrl* m_dvColumns;
    wxPanel* m_splitterPage35;
    wxStaticText* m_staticText57;
    wxAuiToolBar* m_auibar45;
    wxDataViewListCtrl* m_dvKeys;
    wxStaticText* m_staticText125;
    wxChoice* m_choiceLocalCol;
    wxStaticText* m_staticText131;
    wxChoice* m_choiceRefTable;
    wxStaticText* m_staticText135;
    wxChoice* m_choiceRefCol;
    wxRadioBox* m_radioOnUpdate;
    wxRadioBox* m_radioOnDelete;
    wxButton* m_button51;
    wxButton* m_button53;

protected:
    virtual void OnInit(wxInitDialogEvent& event) { event.Skip(); }
    virtual void OnAddColumnClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRemoveColumnClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateColumns(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnMoveUpClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateMoveUp(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnMoveDownClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateMoveDown(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnColumnChanged(wxDataViewEvent& event) { event.Skip(); }
    virtual void OnAddKeyClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRemoveKeyClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateKeys(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnKeySelected(wxDataViewEvent& event) { event.Skip(); }
    virtual void OnKeyChanged(wxDataViewEvent& event) { event.Skip(); }
    virtual void OnLocalColSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRefTableSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRefColSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRadioUpdateSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRadioDeleteSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnCancelClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOKClick(wxCommandEvent& event) { event.Skip(); }

public:
    wxInfoBar* GetInfobar() { return m_infobar; }
    wxStaticText* GetStaticText23() { return m_staticText23; }
    wxTextCtrl* GetTextName() { return m_textName; }
    wxStaticText* GetStaticText55() { return m_staticText55; }
    wxAuiToolBar* GetAuibar39() { return m_auibar39; }
    wxDataViewListCtrl* GetDvColumns() { return m_dvColumns; }
    wxPanel* GetSplitterPage31() { return m_splitterPage31; }
    wxStaticText* GetStaticText57() { return m_staticText57; }
    wxAuiToolBar* GetAuibar45() { return m_auibar45; }
    wxDataViewListCtrl* GetDvKeys() { return m_dvKeys; }
    wxStaticText* GetStaticText125() { return m_staticText125; }
    wxChoice* GetChoiceLocalCol() { return m_choiceLocalCol; }
    wxStaticText* GetStaticText131() { return m_staticText131; }
    wxChoice* GetChoiceRefTable() { return m_choiceRefTable; }
    wxStaticText* GetStaticText135() { return m_staticText135; }
    wxChoice* GetChoiceRefCol() { return m_choiceRefCol; }
    wxRadioBox* GetRadioOnUpdate() { return m_radioOnUpdate; }
    wxRadioBox* GetRadioOnDelete() { return m_radioOnDelete; }
    wxPanel* GetSplitterPage35() { return m_splitterPage35; }
    wxSplitterWindow* GetSplitter27() { return m_splitter27; }
    wxButton* GetButton51() { return m_button51; }
    wxButton* GetButton53() { return m_button53; }
    _TableSettings(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Table settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~_TableSettings();
};

#endif
