#include "wx-3.2-unofficial/wx/wxprec.h"
#include "wx-3.2-unofficial/wx/button.h"
#include "wx-3.2-unofficial/wx/wx.h"
#include "wx-3.2-unofficial/wx/textctrl.h"
#include "iostream"
#include "frame.h"
#include "utils.h"

const int size[2] = {500, 350};

bool App::OnInit()
{
    std::string batterpercantage = exec("rivalcfg --battery-level");
    std::cout<<batterpercantage;
    MainFrame *frame = new MainFrame("Da App", wxPoint(50, 50), wxSize(size[0], size[1]));
    frame->Show(true);
    frame->EnableMaximizeButton(false);
    frame->SetSize(size[0], size[1]);
    frame->SetMinSize(wxSize(size[0], size[1]));
    frame->SetMaxSize(wxSize(size[0], size[1]));
    frame->resetButton = new wxButton(frame, ID_ResetButton, "Reset", wxPoint(110, 10));
    frame->batteryText = new wxStaticText(frame, ID_BatteryText, "Battery", wxPoint(125, 50), wxDefaultSize, 0);
    frame->hzText = new wxStaticText(frame, ID_HzText, "Mouse Hz", wxPoint(115, 110), wxDefaultSize, 0);
    frame->batteryText = new wxStaticText(frame, ID_Battery, batterpercantage, wxPoint(50, 70), wxDefaultSize, 0);
    frame->button125 = new wxButton(frame, ID_Button125, "125", wxPoint(10, 130), wxSize(60, 35), 0);
    frame->button250 = new wxButton(frame, ID_Button250, "250", wxPoint(80, 130), wxSize(60, 35), 0);
    frame->button500 = new wxButton(frame, ID_Button500, "500", wxPoint(150, 130), wxSize(60, 35), 0);
    frame->button1000 = new wxButton(frame, ID_Button1000, "1000", wxPoint(220, 130), wxSize(60, 35), 0);
    frame->dpiTextBox = new wxTextCtrl(frame, ID_DPITextBox, wxEmptyString, wxPoint(100, 200), wxDefaultSize, wxTE_PROCESS_ENTER);
    frame->DPILabelText = new wxStaticText(frame, ID_DPILabelText, "DPI", wxPoint(135, 180), wxDefaultSize, 0);
    frame->ButtonCustomizationLabelText = new wxStaticText(frame, ID_ButtonCusLabel, "Buttons", wxPoint(360, 10), wxDefaultSize ,0);
    frame->button1 = new wxTextCtrl(frame, ID_Button1TextBox, wxEmptyString, wxPoint(340, 40), wxDefaultSize, 0);
    frame->button2 = new wxTextCtrl(frame, ID_Button2TextBox, wxEmptyString, wxPoint(340, 80), wxDefaultSize, 0);
    frame->button3 = new wxTextCtrl(frame, ID_Button3TextBox, wxEmptyString, wxPoint(340, 120), wxDefaultSize, 0);
    frame->button4 = new wxTextCtrl(frame, ID_Button4TextBox, wxEmptyString, wxPoint(340, 160), wxDefaultSize, 0);
    frame->button5 = new wxTextCtrl(frame, ID_Button5TextBox, wxEmptyString, wxPoint(340, 200), wxDefaultSize, 0);
    frame->buttonApply = new wxButton(frame, ID_ButtonApply, "Apply", wxPoint(345, 240), wxDefaultSize, 0);
    return true;
};
MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL,wxID_ANY, title, pos, size)
{
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(ID_About, "About\tCtrl-A");
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuHelp, "About");
    SetMenuBar(menuBar);
}
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxLogMessage("Made by Skulleven on GitHub\nThis program uses rivalcfg which is made by flozz on GitHub");
}
void MainFrame::OnHzButtonPress(wxCommandEvent& event)
{
    system("rivalcfg -p 125");
}
void MainFrame::On250HzButtonPress(wxCommandEvent& event)
{
    system("rivalcfg -p 250");
}
void MainFrame::On500HzButtonPress(wxCommandEvent& event)
{
    system("rivalcfg -p 500");
}
void MainFrame::On1000HzButtonPress(wxCommandEvent& event)
{
    system("rivalcfg -p 1000");
}
void MainFrame::OndpiEnter(wxCommandEvent& event)
{
    system("rivalcfg -s " + dpiTextBox->GetLineText(0));
}
void MainFrame::OnButtonApply(wxCommandEvent& event)
{
    wxString finalshit[5];
    finalshit[0] = button1->GetLineText(0);
    finalshit[1] = button2->GetLineText(0);
    finalshit[2] = button3->GetLineText(0);
    finalshit[3] = button4->GetLineText(0);
    finalshit[4] = button5->GetLineText(0);
    if(finalshit[0] == wxEmptyString)
    {
        finalshit[0] = "button1";
    }
    if(finalshit[1] == wxEmptyString)
    {
        finalshit[1] = "button2";
    }
    if(finalshit[2] == wxEmptyString)
    {
        finalshit[2] = "button3";
    }
    if(finalshit[3] == wxEmptyString)
    {
        finalshit[3] = "button4";
    }
    if(finalshit[4] == wxEmptyString)
    {
        finalshit[4] = "button5";
    }

    system("rivalcfg --buttons='buttons(layout=qwerty; button1=" + finalshit[0] + "; button2=" + finalshit[1] + "; button3=" + finalshit[2] + "; button4=" + finalshit[3] + "; button5=" + finalshit[4] + "; button6=DPI)'");
}
