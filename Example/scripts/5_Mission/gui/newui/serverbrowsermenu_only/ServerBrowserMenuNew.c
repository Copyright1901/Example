v/**
* ServerBrowserMenuNew.c 
* 
* TH
* www.thebritto.com.br 
* © 2019 - 2021 TH 
* 
* Last Modified: 24/11/2021 
* Modified By: TH
* Created: 07/09/2019
* 
* This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/. 
* This work is property of TH. You do not have permissions to edit/distribute any of this content without written permission from the content author (TH). 
* Failure to adhere to the content license(s) above will result in actions from Bohemia Interactive Studios and/or Valve.
* 
*/

/*
modded class ServerBrowserMenuNew extends UIScriptedMenu
{
	private ButtonWidget m_Server_01;
	private TextWidget m_Server_01_name;
	private TextWidget m_Server_01_map;
	private TextWidget m_Server_01_version;

	private ButtonWidget m_Server_02;
	private TextWidget m_Server_02_name;
	private TextWidget m_Server_02_map;
	private TextWidget m_Server_02_version;

	private ButtonWidget m_Server_03;
	private TextWidget m_Server_03_name;
	private TextWidget m_Server_03_map;
	private TextWidget m_Server_03_version;

	protected ref GetServersResultRow m_ServerData;

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "Example/gui/layouts/new_ui/server_browser_only/pc/server.layout" );

		//Server 01
		m_Server_01 = ButtonWidget.Cast(layoutRoot.FindAnyWidget("Server_01"));
		m_Server_01_name = TextWidget.Cast(layoutRoot.FindAnyWidget("Server01_name"));
		m_Server_01_map = TextWidget.Cast(layoutRoot.FindAnyWidget("Server01_map"));
		m_Server_01_version = TextWidget.Cast(layoutRoot.FindAnyWidget("Server01_version"));

		//Server 02
		m_Server_02 = ButtonWidget.Cast(layoutRoot.FindAnyWidget("Server_02"));
		m_Server_02_name = TextWidget.Cast(layoutRoot.FindAnyWidget("Server02_name"));
		m_Server_02_map = TextWidget.Cast(layoutRoot.FindAnyWidget("Server02_map"));
		m_Server_02_version = TextWidget.Cast(layoutRoot.FindAnyWidget("Server02_version"));

		//Server 03
		m_Server_03 = ButtonWidget.Cast(layoutRoot.FindAnyWidget("Server_03"));
		m_Server_03_name = TextWidget.Cast(layoutRoot.FindAnyWidget("Server03_name"));
		m_Server_03_map = TextWidget.Cast(layoutRoot.FindAnyWidget("Server03_map"));
		m_Server_03_version = TextWidget.Cast(layoutRoot.FindAnyWidget("Server03_version"));

		GetVersion();
		return layoutRoot;
	};

	void GetVersion()
	{
		string version;
		GetGame().GetVersion( version );

		m_Server_01_version.SetText( "Version: " + version );
		m_Server_02_version.SetText( "Version: " + version );
		m_Server_03_version.SetText( "Version: " + version );
	}

	override bool OnClick( Widget w, int x, int y, int button )
	{
		if ( button == MouseState.LEFT )
		{
			if ( w == m_Server_01 )
			{
				g_Game.ConnectFromServerBrowser("103.152.196.33", 2302, "");
				return true;
			}
			else if ( w == m_Server_02 )
			{
				g_Game.ConnectFromServerBrowser("103.152.196.22", 2302, "");
				return true;
			}
			else if ( w == m_Server_03 )
			{
				g_Game.ConnectFromServerBrowser("103.193.80.83", 2302, "");
				return true;
			}
		};
		return false;
	};

	void OnShow()
	{
		super.OnShow();
		PPEffects.SetBlurMenu(0.3);
	};

	void OnHide()
	{
		super.OnHide();
		PPEffects.SetBlurMenu(0);
	};
};
