#include "pch.h"
#include "RLTrainingHub.h"
#include "ImGui/imgui_internal.h"
#include "wtypes.h"

bool boi = true;
bool* p_open = &boi;

static void ShowExampleAppConstrainedResize(bool* p_open);
bool ShowAppConstrainedResize = false;



bool renderOverlay = false;
bool openTrainingMenu = false;
bool openBoomerTrainingMenu = false;
bool openCatchesTrainingMenu = false;

bool openFirstMenu = true;
    bool openMechanicsMenu = false;
        bool openGeneralMenu = false;
            bool openInfiniteDribblingMenu = false;
    bool openDefenseMenu = false;
        bool openGoalLineMenu = false;
        bool openMidfieldMenu = false;
            bool openRegularCornerSpecificMenu = false;
    bool openVsBotMenu = false;
        bool openDecisionMakingMenu = false;
            bool openWhoHasBallMenu = false;
        bool openOneVsOneMenu = false;

//how the game knows to start training
bool beginTraining = false;

//Settings from mechanics menu
bool aerialOffense1 = false;
bool groundOffense1 = false;
bool movement1 = false;

//settings from general menu
bool infDribGround1 = false;
bool infDribAerial1 = false;
bool keepItCloseGame1 = false;
bool catches1 = false;
bool movementGame1 = false;

//settings from goal line menu
bool quickSaves1 = false;
bool blocking50s1 = false;
bool awkwardClears1 = false;
//regular or corner specifc?
bool regular1 = false;
bool cornerSpecific1 = false;

//settings from midfield menu
bool challenges1 = false;
bool firstMan1 = false;

//settings from decision-making menu from vs bot
bool midfield1 = false;
bool backCorners1 = false;
bool farCorners1 = false;
//who has ball?
bool youHaveTheBall1 = false;
bool opponentHasTheBall1 = false;

//settings from 1v1 menu from vs bot
bool offense1 = false;
bool defense1 = false;


void GetDesktopResolution(int& horizontal, int& vertical)
{
    RECT dsktp;

    const HWND hDsktp = GetDesktopWindow();

    GetWindowRect(hDsktp, &dsktp);

    horizontal = dsktp.right;
    vertical = dsktp.bottom;
}

void RLTrainingHub::RenderSettings()
{
	ImGui::TextUnformatted("cool thing");
	if (ImGui::Button("load shotp "))
	{
		gameWrapper->Execute([this](GameWrapper* gw) {
			cvarManager->executeCommand("hub");
			});
	}
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("yoo");
	}
	if (ImGui::Button("MainMenu"))
        ImGui::OpenPopup("my_file_popup");
        if (ImGui::BeginPopup("my_file_popup", ImGuiWindowFlags_MenuBar))
        {
            if (ImGui::BeginMenuBar())
            {
                if (ImGui::BeginMenu("File"))
                {
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Edit"))
                {
                    ImGui::MenuItem("Dummy");
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }
            ImGui::Text("Hello from popup!");
            ImGui::Button("This is a dummy button..");
            ImGui::EndPopup();
        }
}

void RLTrainingHub::FirstMenu()
{
    int horiz, vert = 0;
    GetDesktopResolution(horiz, vert);
    ImGui::SetNextWindowSizeConstraints(ImVec2(horiz, vert), ImVec2(horiz, vert));
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::Begin("", &boi, 1);
    ImGui::InvisibleButton("f", ImVec2(10         , 2 * vert / 5.0));
    ImGui::InvisibleButton("f", ImVec2(horiz / 5.0, 10            ));
    ImGui::SameLine();
    if (ImGui::Button("Mechanics", ImVec2(horiz / 5.0, vert / 5.0)))
    {
        openFirstMenu = false;
        openMechanicsMenu = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("Defense", ImVec2(horiz / 5.0, vert / 5.0)))
    {
        openFirstMenu = false;
        openDefenseMenu = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("Vs. Bot", ImVec2(horiz / 5.0, vert / 5.0)))
    {
        openFirstMenu = false;
        openVsBotMenu = true;
    }
    ImGui::InvisibleButton("f", ImVec2(horiz / 5.0, 10));
    ImGui::SameLine();
    if (ImGui::SmallButton("close"))
    {
        cvarManager->executeCommand("togglemenu RLTrainingHub");
    }
    ImGui::End();
}

void RLTrainingHub::MechanicsMenu()
{
    int horiz, vert = 0;
    GetDesktopResolution(horiz, vert);
    ImGui::SetNextWindowSizeConstraints(ImVec2(horiz, vert), ImVec2(horiz, vert));
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::Begin("fnef", &boi, 1);
    ImGui::InvisibleButton("f", ImVec2(10         , vert / 4.0));
    ImGui::InvisibleButton("f", ImVec2(horiz / 4.0, 10        ));
    ImGui::SameLine();
    if (ImGui::Button("Aerial Offense", ImVec2(horiz / 4.0, vert / 4.0)))
    {
        cvarManager->executeCommand("togglemenu RLTrainingHub");
        aerialOffense1 = true;
        beginTraining = true;
        //openTrainingMenu = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("Ground Offense", ImVec2(horiz / 4.0, vert / 4.0)))
    {
        cvarManager->executeCommand("togglemenu RLTrainingHub");
        groundOffense1 = true;
        beginTraining = true;
    }
    ImGui::InvisibleButton("f", ImVec2(horiz / 4.0, 10));
    ImGui::SameLine();
    if (ImGui::Button("Movement", ImVec2(horiz / 4.0, vert / 4.0)))
    {
        cvarManager->executeCommand("togglemenu RLTrainingHub");
        movement1 = true;
        beginTraining = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("General", ImVec2(horiz / 4.0, vert / 4.0)))
    {
        openMechanicsMenu = false;
        openGeneralMenu = true;
    }
    ImGui::InvisibleButton("f", ImVec2(10, vert / 16.0));
    ImGui::InvisibleButton("f", ImVec2(horiz / 2 - vert / 16.0, 10));
    ImGui::SameLine();
    if (ImGui::Button("back", ImVec2(2 * vert / 16.0, 2 * vert / 16.0)))
    {
        openMechanicsMenu = false;
        openFirstMenu = true;
    }
    ImGui::End();
}
    void RLTrainingHub::GeneralMenu()
    {
        int horiz, vert = 0;
        GetDesktopResolution(horiz, vert);
        ImGui::SetNextWindowSizeConstraints(ImVec2(horiz, vert), ImVec2(horiz, vert));
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::Begin("fnef", &boi, 1);
        ImGui::InvisibleButton("f", ImVec2(10, vert / 4.0));
        ImGui::InvisibleButton("f", ImVec2(horiz / 4.0, 10));
        ImGui::SameLine();
        if (ImGui::Button("Infinite Dribbling", ImVec2(horiz / 4.0, vert / 4.0)))
        {
            openGeneralMenu = false;
            openInfiniteDribblingMenu = true;
        }
        ImGui::SameLine();
        if (ImGui::Button("Keep-It-Close Game", ImVec2(horiz / 4.0, vert / 4.0)))
        {
            cvarManager->executeCommand("togglemenu RLTrainingHub");
            keepItCloseGame1 = true;
            beginTraining = true;
        }
        ImGui::InvisibleButton("f", ImVec2(horiz / 4.0, 10));
        ImGui::SameLine();
        if (ImGui::Button("Catches", ImVec2(horiz / 4.0, vert / 4.0)))
        {
            cvarManager->executeCommand("togglemenu RLTrainingHub");
            catches1 = true;
            beginTraining = true;
        }
        ImGui::SameLine();
        if (ImGui::Button("Movement Game", ImVec2(horiz / 4.0, vert / 4.0)))
        {
            cvarManager->executeCommand("togglemenu RLTrainingHub");
            movementGame1 = true;
            beginTraining = true;
        }
        ImGui::InvisibleButton("f", ImVec2(10, vert / 16.0));
        ImGui::InvisibleButton("f", ImVec2(horiz / 2 - vert / 16.0, 10));
        ImGui::SameLine();
        if (ImGui::Button("back", ImVec2(2 * vert / 16.0, 2 * vert / 16.0)))
        {
            openGeneralMenu = false;
            openMechanicsMenu = true;
        }
        ImGui::End();
    }
        void RLTrainingHub::InfiniteDribblingMenu()
        {
            int horiz, vert = 0;
            GetDesktopResolution(horiz, vert);
            ImGui::SetNextWindowSizeConstraints(ImVec2(horiz, vert), ImVec2(horiz, vert));
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::Begin("fnef", &boi, 1);
            ImGui::InvisibleButton("f", ImVec2(10         , 2 * vert / 5.0));
            ImGui::InvisibleButton("f", ImVec2(horiz / 4.0,             10));
            ImGui::SameLine();
            if (ImGui::Button("Aerial", ImVec2(horiz / 4.0, vert / 5.0)))
            {
                cvarManager->executeCommand("togglemenu RLTrainingHub");
                infDribAerial1 = true;
                beginTraining = true;
            }
            ImGui::SameLine();
            if (ImGui::Button("Ground", ImVec2(horiz / 4.0, vert / 5.0)))
            {
                cvarManager->executeCommand("togglemenu RLTrainingHub");
                infDribGround1 = true;
                beginTraining = true;
            }
            ImGui::InvisibleButton("f", ImVec2(10, 0.155 * vert + vert / 16.0));
            ImGui::InvisibleButton("f", ImVec2(horiz / 2 - vert / 16.0, 10));
            ImGui::SameLine();
            if (ImGui::Button("back", ImVec2(2 * vert / 16.0, 2 * vert / 16.0)))
            {
                openInfiniteDribblingMenu = false;
                openGeneralMenu = true;
            }
            ImGui::End();
        }
void RLTrainingHub::DefenseMenu()
{
    int horiz, vert = 0;
    GetDesktopResolution(horiz, vert);
    ImGui::SetNextWindowSizeConstraints(ImVec2(horiz, vert), ImVec2(horiz, vert));
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::Begin("", &boi, 1);
    ImGui::InvisibleButton("f", ImVec2(10, 2 * vert / 5.0));
    ImGui::InvisibleButton("f", ImVec2(horiz / 4.0, 10));
    ImGui::SameLine();
    if (ImGui::Button("Goal Line", ImVec2(horiz / 4.0, vert / 5.0)))
    {
        openDefenseMenu = false;
        openGoalLineMenu = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("Midfield", ImVec2(horiz / 4.0, vert / 5.0)))
    {
        openDefenseMenu = false;
        openMidfieldMenu = true;
    }
    ImGui::InvisibleButton("f", ImVec2(10, 0.155 * vert + vert / 16.0));
    ImGui::InvisibleButton("f", ImVec2(horiz / 2 - vert / 16.0, 10));
    ImGui::SameLine();
    if (ImGui::Button("back", ImVec2(2 * vert / 16.0, 2 * vert / 16.0)))
    {
        openDefenseMenu = false;
        openFirstMenu = true;
    }
    ImGui::End();
}
    void RLTrainingHub::GoalLineMenu()
    {
        int horiz, vert = 0;
        GetDesktopResolution(horiz, vert);
        ImGui::SetNextWindowSizeConstraints(ImVec2(horiz, vert), ImVec2(horiz, vert));
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::Begin("", &boi, 1);
        ImGui::InvisibleButton("f", ImVec2(10, 2 * vert / 5.0));
        ImGui::InvisibleButton("f", ImVec2(horiz / 5.0, 10));
        ImGui::SameLine();
        if (ImGui::Button("Quick Saves", ImVec2(horiz / 5.0, vert / 5.0)))
        {
            quickSaves1 = true;
            openGoalLineMenu = false;
            openRegularCornerSpecificMenu = true;
        }
        ImGui::SameLine();
        if (ImGui::Button("Blocking 50s", ImVec2(horiz / 5.0, vert / 5.0)))
        {
            cvarManager->executeCommand("togglemenu RLTrainingHub");
            blocking50s1 = true;
            beginTraining = true;
        }
        ImGui::SameLine();
        if (ImGui::Button("Awkward Clears", ImVec2(horiz / 5.0, vert / 5.0)))
        {
            awkwardClears1 = true;
            openGoalLineMenu = false;
            openRegularCornerSpecificMenu = true;
        }
        ImGui::InvisibleButton("f", ImVec2(10, 0.155 * vert + vert / 16.0));
        ImGui::InvisibleButton("f", ImVec2(horiz / 2 - vert / 16.0, 10));
        ImGui::SameLine();
        if (ImGui::Button("back", ImVec2(2 * vert / 16.0, 2 * vert / 16.0)))
        {
            openGoalLineMenu = false;
            openDefenseMenu = true;
        }
        ImGui::End();
    }
        void RLTrainingHub::RegularCornerSpecificMenu()
        {
            int horiz, vert = 0;
            GetDesktopResolution(horiz, vert);
            ImGui::SetNextWindowSizeConstraints(ImVec2(horiz, vert), ImVec2(horiz, vert));
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::Begin("fnef", &boi, 1);
            ImGui::InvisibleButton("f", ImVec2(10, 2 * vert / 5.0));
            ImGui::InvisibleButton("f", ImVec2(horiz / 4.0, 10));
            ImGui::SameLine();
            if (ImGui::Button("Regular", ImVec2(horiz / 4.0, vert / 5.0)))
            {
                cvarManager->executeCommand("togglemenu RLTrainingHub");
                regular1 = true;
                beginTraining = true;
            }
            ImGui::SameLine();
            if (ImGui::Button("Corner Specific", ImVec2(horiz / 4.0, vert / 5.0)))
            {
                cvarManager->executeCommand("togglemenu RLTrainingHub");
                cornerSpecific1 = true;
                beginTraining = true;
            }
            ImGui::InvisibleButton("f", ImVec2(10, 0.155 * vert + vert / 16.0));
            ImGui::InvisibleButton("f", ImVec2(horiz / 2 - vert / 16.0, 10));
            ImGui::SameLine();
            if (ImGui::Button("back", ImVec2(2 * vert / 16.0, 2 * vert / 16.0)))
            {
                openRegularCornerSpecificMenu = false;
                openGoalLineMenu = true;
            }
            ImGui::End();
        }
    void RLTrainingHub::MidfieldMenu()
    {
        int horiz, vert = 0;
        GetDesktopResolution(horiz, vert);
        ImGui::SetNextWindowSizeConstraints(ImVec2(horiz, vert), ImVec2(horiz, vert));
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::Begin("fnef", &boi, 1);
        ImGui::InvisibleButton("f", ImVec2(10, 2 * vert / 5.0));
        ImGui::InvisibleButton("f", ImVec2(horiz / 4.0, 10));
        ImGui::SameLine();
        if (ImGui::Button("Challenges", ImVec2(horiz / 4.0, vert / 5.0)))
        {
            cvarManager->executeCommand("togglemenu RLTrainingHub");
            challenges1 = true;
            beginTraining = true;
        }
        ImGui::SameLine();
        if (ImGui::Button("First Man", ImVec2(horiz / 4.0, vert / 5.0)))
        {
            cvarManager->executeCommand("togglemenu RLTrainingHub");
            firstMan1 = true;
            beginTraining = true;
        }
        ImGui::InvisibleButton("f", ImVec2(10, 0.155 * vert + vert / 16.0));
        ImGui::InvisibleButton("f", ImVec2(horiz / 2 - vert / 16.0, 10));
        ImGui::SameLine();
        if (ImGui::Button("back", ImVec2(2 * vert / 16.0, 2 * vert / 16.0)))
        {
            openMidfieldMenu = false;
            openDefenseMenu = true;
        }
        ImGui::End();
    }
void RLTrainingHub::VsBotMenu()
{
    int horiz, vert = 0;
    GetDesktopResolution(horiz, vert);
    ImGui::SetNextWindowSizeConstraints(ImVec2(horiz, vert), ImVec2(horiz, vert));
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::Begin("fnef", &boi, 1);
    ImGui::InvisibleButton("f", ImVec2(10, 2 * vert / 5.0));
    ImGui::InvisibleButton("f", ImVec2(horiz / 4.0, 10));
    ImGui::SameLine();
    if (ImGui::Button("Decision-Making", ImVec2(horiz / 4.0, vert / 5.0)))
    {
        openVsBotMenu = false;
        openDecisionMakingMenu = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("1v1", ImVec2(horiz / 4.0, vert / 5.0)))
    {
        openVsBotMenu = false;
        openOneVsOneMenu = true;
    }
    ImGui::InvisibleButton("f", ImVec2(10, 0.155 * vert + vert / 16.0));
    ImGui::InvisibleButton("f", ImVec2(horiz / 2 - vert / 16.0, 10));
    ImGui::SameLine();
    if (ImGui::Button("back", ImVec2(2 * vert / 16.0, 2 * vert / 16.0)))
    {
        openVsBotMenu = false;
        openFirstMenu = true;
    }
    ImGui::End();
}
    void RLTrainingHub::DecisionMakingMenu()
    {
        int horiz, vert = 0;
        GetDesktopResolution(horiz, vert);
        ImGui::SetNextWindowSizeConstraints(ImVec2(horiz, vert), ImVec2(horiz, vert));
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::Begin("", &boi, 1);
        ImGui::InvisibleButton("f", ImVec2(10, 2 * vert / 5.0));
        ImGui::InvisibleButton("f", ImVec2(horiz / 5.0, 10));
        ImGui::SameLine();
        if (ImGui::Button("Midfield", ImVec2(horiz / 5.0, vert / 5.0)))
        {
            midfield1 = true;
            openDecisionMakingMenu = false;
            openWhoHasBallMenu = true;
        }
        ImGui::SameLine();
        if (ImGui::Button("Back Corners", ImVec2(horiz / 5.0, vert / 5.0)))
        {
            backCorners1 = true;
            openDecisionMakingMenu = false;
            openWhoHasBallMenu = true;
        }
        ImGui::SameLine();
        if (ImGui::Button("Far Corners", ImVec2(horiz / 5.0, vert / 5.0)))
        {
            farCorners1 = true;
            openDecisionMakingMenu = false;
            openWhoHasBallMenu = true;
        }
        ImGui::InvisibleButton("f", ImVec2(10, 0.155 * vert + vert / 16.0));
        ImGui::InvisibleButton("f", ImVec2(horiz / 2 - vert / 16.0, 10));
        ImGui::SameLine();
        if (ImGui::Button("back", ImVec2(2 * vert / 16.0, 2 * vert / 16.0)))
        {
            openDecisionMakingMenu = false;
            openVsBotMenu = true;
        }
        ImGui::End();
    }
        void RLTrainingHub::WhoHasBallMenu()
        {
            int horiz, vert = 0;
            GetDesktopResolution(horiz, vert);
            ImGui::SetNextWindowSizeConstraints(ImVec2(horiz, vert), ImVec2(horiz, vert));
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::Begin("fnef", &boi, 1);
            ImGui::InvisibleButton("f", ImVec2(10, 2 * vert / 5.0));
            ImGui::InvisibleButton("f", ImVec2(horiz / 4.0, 10));
            ImGui::SameLine();
            if (ImGui::Button("You Have the Ball", ImVec2(horiz / 4.0, vert / 5.0)))
            {
                cvarManager->executeCommand("togglemenu RLTrainingHub");
                youHaveTheBall1 = true;
                beginTraining = true;
            }
            ImGui::SameLine();
            if (ImGui::Button("Opponent Has the Ball", ImVec2(horiz / 4.0, vert / 5.0)))
            {
                cvarManager->executeCommand("togglemenu RLTrainingHub");
                opponentHasTheBall1 = true;
                beginTraining = true;
            }
            ImGui::InvisibleButton("f", ImVec2(10, 0.155 * vert + vert / 16.0));
            ImGui::InvisibleButton("f", ImVec2(horiz / 2 - vert / 16.0, 10));
            ImGui::SameLine();
            if (ImGui::Button("back", ImVec2(2 * vert / 16.0, 2 * vert / 16.0)))
            {
                openWhoHasBallMenu = false;
                openDecisionMakingMenu = true;
            }
            ImGui::End();
        }
    void RLTrainingHub::OneVsOneMenu()
    {
        int horiz, vert = 0;
        GetDesktopResolution(horiz, vert);
        ImGui::SetNextWindowSizeConstraints(ImVec2(horiz, vert), ImVec2(horiz, vert));
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::Begin("fnef", &boi, 1);
        ImGui::InvisibleButton("f", ImVec2(10, 2 * vert / 5.0));
        ImGui::InvisibleButton("f", ImVec2(horiz / 4.0, 10));
        ImGui::SameLine();
        if (ImGui::Button("Offense", ImVec2(horiz / 4.0, vert / 5.0)))
        {
            cvarManager->executeCommand("togglemenu RLTrainingHub");
            offense1 = true;
            beginTraining = true;
        }
        ImGui::SameLine();
        if (ImGui::Button("Defense", ImVec2(horiz / 4.0, vert / 5.0)))
        {
            cvarManager->executeCommand("togglemenu RLTrainingHub");
            defense1 = true;
            beginTraining = true;
        }
        ImGui::InvisibleButton("f", ImVec2(10, 0.155 * vert + vert / 16.0));
        ImGui::InvisibleButton("f", ImVec2(horiz / 2 - vert / 16.0, 10));
        ImGui::SameLine();
        if (ImGui::Button("back", ImVec2(2 * vert / 16.0, 2 * vert / 16.0)))
        {
            openOneVsOneMenu = false;
            openVsBotMenu = true;
        }
        ImGui::End();
    }

void RLTrainingHub::RenderWindow()
{
    ImGui::TextUnformatted("(This menu is not part of the thing. Just drag one of the corners to make this window as small as possible and put it in a corner somewhere)");

    if (openFirstMenu)
        FirstMenu();

    //Mechanics Section
    if (openMechanicsMenu)
        MechanicsMenu();
    if (openGeneralMenu)
        GeneralMenu();
    if (openInfiniteDribblingMenu)
        InfiniteDribblingMenu();

    //Defense Section
    if (openDefenseMenu)
        DefenseMenu();
    if (openGoalLineMenu)
        GoalLineMenu();
    if (openRegularCornerSpecificMenu)
        RegularCornerSpecificMenu();
    if (openMidfieldMenu)
        MidfieldMenu();

    //Vs. Bot Section
    if (openVsBotMenu)
        VsBotMenu();
    if (openDecisionMakingMenu)
        DecisionMakingMenu();
    if (openWhoHasBallMenu)
        WhoHasBallMenu();
    if (openOneVsOneMenu)
        OneVsOneMenu();

    if (openTrainingMenu);
        //FirstMenu(); // CHANGE LATER
}

void RLTrainingHub::loadHooksFromSettingsAndWindows()
{
    gameWrapper->HookEventPost("Function Engine.PlayerController.IsPrimaryPlayer",
        [this](std::string eventName) {
            if (beginTraining)
            {
                if (aerialOffense1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_aerial_offense");
                    aerialOffense1 = false;
                }
                if (groundOffense1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_ground_offense");
                    groundOffense1 = false;
                }
                if (movement1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_movement");
                    movement1 = false;
                }
                if (infDribAerial1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_inf_drib_aerial");
                    infDribAerial1 = false;
                }
                if (infDribGround1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_inf_drib_ground");
                    infDribGround1 = false;
                }
                if (keepItCloseGame1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_keep_it_close_game");
                    keepItCloseGame1 = false;
                }
                if (catches1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_catches");
                    catches1 = false;
                }
                if (movementGame1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_movement_game");
                    movementGame1 = false;
                }
                if (quickSaves1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_quick_saves");
                    if (regular1)
                    {
                        cvarManager->executeCommand("RLTrainingHub::set_regular");
                        regular1 = false;
                    }
                    else if (cornerSpecific1)
                    {
                        cvarManager->executeCommand("RLTrainingHub::set_corner_sepcific");
                        cornerSpecific1 = false;
                    }
                    quickSaves1 = false;
                }
                if (blocking50s1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_blocking_50s");
                    blocking50s1 = false;
                }
                if (awkwardClears1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_awkward_clears");
                    if (regular1)
                    {
                        cvarManager->executeCommand("RLTrainingHub::set_regular");
                        regular1 = false;
                    }
                    else if (cornerSpecific1)
                    {
                        cvarManager->executeCommand("RLTrainingHub::set_corner_specific");
                        cornerSpecific1 = false;
                    }
                    awkwardClears1 = false;
                }
                if (challenges1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_challenges");
                    challenges1 = false;
                }
                if (firstMan1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_first_man");
                    firstMan1 = false;
                }
                if (midfield1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_midfield");
                    if (youHaveTheBall1)
                    {
                        cvarManager->executeCommand("RLTrainingHub::you_have_ball");
                        youHaveTheBall1 = false;
                    }
                    else if (opponentHasTheBall1)
                    {
                        cvarManager->executeCommand("RLTrainingHub::opponent_has_ball");
                        opponentHasTheBall1 = false;
                    }
                    midfield1 = false;
                }
                if (backCorners1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_back_corners");
                    if (youHaveTheBall1)
                    {
                        cvarManager->executeCommand("RLTrainingHub::you_have_ball");
                        youHaveTheBall1 = false;
                    }
                    else if (opponentHasTheBall1)
                    {
                        cvarManager->executeCommand("RLTrainingHub::opponent_has_ball");
                        opponentHasTheBall1 = false;
                    }
                    backCorners1 = false;
                }
                if (farCorners1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_far_corners");
                    if (youHaveTheBall1)
                    {
                        cvarManager->executeCommand("RLTrainingHub::you_have_ball");
                        youHaveTheBall1 = false;
                    }
                    else if (opponentHasTheBall1)
                    {
                        cvarManager->executeCommand("RLTrainingHub::opponent_has_ball");
                        opponentHasTheBall1 = false;
                    }
                    farCorners1 = false;
                }
                if (offense1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_offense(1v1)");
                    offense1 = false;
                }
                if (defense1)
                {
                    cvarManager->executeCommand("RLTrainingHub::open_defense(1v1)");
                    defense1 = false;
                }
                beginTraining = false;
                renderOverlay = true;
            }
        });
}