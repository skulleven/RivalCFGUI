#include "wx-3.2-unofficial/wx/wxprec.h"
#include "wx-3.2-unofficial/wx/button.h"
#include "wx-3.2-unofficial/wx/wx.h"
#include "wx-3.2-unofficial/wx/textctrl.h"
#include "iostream"

class App: public wxApp
{
public:
    virtual bool OnInit();
};


class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    wxStaticText *batteryText;
    wxStaticText *hzText;
    wxStaticText *battery;
    wxStaticText *DPILabelText;
    wxButton *button125;
    wxButton *button250;
    wxButton *button500;
    wxButton *button1000;
    wxTextCtrl *dpiTextBox;
    wxButton *resetButton;
    wxStaticText *ButtonCustomizationLabelText;
    wxTextCtrl *button1;
    wxTextCtrl *button2;
    wxTextCtrl *button3;
    wxTextCtrl *button4;
    wxTextCtrl *button5;
    wxButton *buttonApply;
private:
    void OnAbout(wxCommandEvent& event);
    void OnHzButtonPress(wxCommandEvent& event);
    void On250HzButtonPress(wxCommandEvent& event);
    void On500HzButtonPress(wxCommandEvent& event);
    void On1000HzButtonPress(wxCommandEvent& event);
    void OndpiEnter(wxCommandEvent& event);
    void OnResetButtonPress(wxCommandEvent& event);
    void OnButtonApply(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_About = 1,
    ID_BatteryText = 2,
    ID_HzText = 3,
    ID_Battery = 4,
    ID_Button125 = 5,
    ID_Button250 = 6,
    ID_Button500 = 7,
    ID_Button1000 = 8,
    ID_DPITextBox = 9,
    ID_DPILabelText = 10,
    ID_ResetButton = 11,
    ID_ButtonCusLabel = 12,
    ID_Button1TextBox = 13,
    ID_Button2TextBox = 14,
    ID_Button3TextBox = 15,
    ID_Button4TextBox = 16,
    ID_Button5TextBox = 17,
    ID_ButtonApply = 18
};
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_About, MainFrame::OnAbout)
    EVT_BUTTON(ID_Button125, MainFrame::OnHzButtonPress)
    EVT_BUTTON(ID_Button250, MainFrame::On250HzButtonPress)
    EVT_BUTTON(ID_Button500, MainFrame::On500HzButtonPress)
    EVT_BUTTON(ID_Button1000, MainFrame::On1000HzButtonPress)
    EVT_BUTTON(ID_ButtonApply, MainFrame::OnButtonApply)
    EVT_TEXT_ENTER(ID_DPITextBox, MainFrame::OndpiEnter)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(App);
