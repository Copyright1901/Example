/**
* LoadingScreen.c 
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

modded class LoadingScreen
{
	private TextWidget 		m_RandomMessage;
	
	override void Show()
	{
		super.Show();

		Widget lIcon = m_ImageBackground;
		Widget pText = m_ProgressLoading;

        ImageWidget background = ImageWidget.Cast(m_WidgetRoot.FindAnyWidget("ImageBackground"));
        		
		m_ImageWidgetBackground.LoadImageFile(0, LoadingGame.GetRandomElement()); 
		m_ImageWidgetBackground.LoadMaskTexture("");
		
		m_ProgressLoading.SetCurrent(0.0);
		m_ImageBackground.SetMaskProgress(0.0);

		//Message Random
		if(ShowMessage)
		{
			m_RandomMessage = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("RandomText"));
			m_RandomMessage.SetText(RandomMessage.GetRandomElement());
			m_RandomMessage.SetColor(UIColorText);
			m_RandomMessage.Show(true);
		};

		ProgressAsync.SetProgressData(pText);
		ProgressAsync.SetUserData(lIcon);
	};

	void LoadingScreen(DayZGame game)
	{
		m_DayZGame = game;
		
		m_WidgetRoot = game.GetLoadingWorkspace().CreateWidgets("Example/gui/layouts/dialog_loading.layout");

		Class.CastTo(m_ImageLogoMid, m_WidgetRoot.FindAnyWidget("ImageLogoMid"));
		Class.CastTo(m_ImageLogoCorner, m_WidgetRoot.FindAnyWidget("ImageLogoCorner"));
		
		Class.CastTo(m_TextWidgetTitle, m_WidgetRoot.FindAnyWidget("TextWidget"));
		Class.CastTo(m_TextWidgetStatus, m_WidgetRoot.FindAnyWidget("StatusText"));
		Class.CastTo(m_ImageWidgetBackground, m_WidgetRoot.FindAnyWidget("ImageBackground"));
		Class.CastTo(m_ImageLoadingIcon, m_WidgetRoot.FindAnyWidget("ImageLoadingIcon"));
		Class.CastTo(m_ModdedWarning, m_WidgetRoot.FindAnyWidget("ModdedWarning"));
		
		m_ImageBackground = ImageWidget.Cast(m_WidgetRoot.FindAnyWidget("ImageBackground"));
		m_ProgressLoading = ProgressBarWidget.Cast(m_WidgetRoot.FindAnyWidget("LoadingBar"));
		m_ProgressLoading.SetColor(UIColor);

		string tmp;
		m_ProgressText = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("ProgressText"));
		if (GetGame())
		{
			m_ProgressText.Show(GetGame().CommandlineGetParam("loadingTest", tmp));
		}
		
		m_ModdedWarning.Show(g_Game.ReportModded());
		m_ImageLogoMid.Show(true);
		m_ImageLogoCorner.Show(false);
		
		m_ImageWidgetBackground.Show(true);		
		m_Counter = 0;
				
		game.GetBacklit().LoadingAnim();
		
		ProgressAsync.SetProgressData(m_ProgressLoading);
		ProgressAsync.SetUserData(m_ImageBackground);
	};
};