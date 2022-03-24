/**
* MissionGameplay.c 
* 
* TH
* www.thebritto.com.br 
* © 2019 - 2021 TH 
* 
* Last Modified: 24/11/2021 
* Modified By: TH
* 
* This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/. 
* This work is property of TH. You do not have permissions to edit/distribute any of this content without written permission from the content author (TH). 
* Failure to adhere to the content license(s) above will result in actions from Bohemia Interactive Studios and/or Valve.
* 
*/

modded class MissionGameplay
{
	private ref Widget LogoRootWidget;
	private ref ImageWidget LogoWidget;
	private ref FileSerializer DataFile;

	private bool LogoEnabled;
	private string OverlayDataPath = "$profile:LogoOverlay.bin";

	void MissionGameplay()
    {
        DataFile = new FileSerializer();
        if (!FileExist(OverlayDataPath))
        {
            LogoEnabled = true;
            SaveOverlayData();
            return;
        }

        LoadOverlayData();
    };

	void ~MissionGameplay()
	{
		delete LogoRootWidget;
		delete LogoWidget;
		delete DataFile;
	};

	override void OnMissionStart()
    {
        super.OnMissionStart();

		LogoRootWidget = GetGame().GetWorkspace().CreateWidgets("Example/gui/layouts/day_z_logotipo.layout");
		LogoWidget = ImageWidget.Cast(LogoRootWidget.FindAnyWidget("logoWidget"));
		LogoWidget.LoadImageFile(0, logotipo);
    };

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		if (!LogoRootWidget || !LogoWidget) return;

		if (GetGame().GetInput().LocalPress("ZB_ToggleLogo", true))
		{
			LogoEnabled = !LogoWidget.IsVisible();
			SaveOverlayData();
		};

		if (IsControlDisabled() || IsPaused() || m_Hud.IsHideHudPlayer() || !m_Hud.GetHudState() || !LogoEnabled || !GetGame().GetPlayer())
		{
			LogoWidget.Show(false);
			return;
		};

		LogoWidget.Show(true);
	};

	private void LoadOverlayData()
    {
        if (DataFile.Open(OverlayDataPath, FileMode.READ))
        {
            DataFile.Read(LogoEnabled);
            DataFile.Close();
        };
    };

    private void SaveOverlayData()
    {
        if (DataFile.Open(OverlayDataPath, FileMode.WRITE))
        {
            DataFile.Write(LogoEnabled);
            DataFile.Close();
        };
    };
};