#pragma once

#include "GuiBase.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "version.h"
constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);


class RLTrainingHub: public BakkesMod::Plugin::BakkesModPlugin
	,public SettingsWindowBase // Uncomment if you wanna render your own tab in the settings menu
	,public PluginWindowBase // Uncomment if you want to render your own plugin window
{

	//std::shared_ptr<bool> enabled;

	//temporary
	void getPositionOfCarAndBall();
	void record();
	void logThoseArrays();

	//Boilerplate
	void onLoad() override;
	void putPlayerInFreeplay();

	void shotPackSelect();
	void saveBallCarLocation();
	void botPreview();
	void packsAndShots();
	void previousPack();
	void nextPack();
	void previousShot();
	void nextShot();

	void loadHooks();
	void loadHooksFromSettingsAndWindows();
	//void onUnload() override; // Uncomment and implement if you need a unload method

public:
	void RenderSettings() override; // Uncomment if you wanna render your own tab in the settings menu
	void RenderWindow() override; // Uncomment if you want to render your own plugin window
	
	//void TrainingOverlay();
	//void TrainingMenu();

	void FirstMenu();
	void MechanicsMenu();
		void GeneralMenu();
			void InfiniteDribblingMenu();
	void DefenseMenu();
		void GoalLineMenu();
			void RegularCornerSpecificMenu();
		void MidfieldMenu();
	void VsBotMenu();
		void DecisionMakingMenu();
			void WhoHasBallMenu();
		void OneVsOneMenu();

	//void onRender();
};
