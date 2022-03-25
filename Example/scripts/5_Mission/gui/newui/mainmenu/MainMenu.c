/**
* MainMenu.c 
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

modded class MainMenu extends UIScriptedMenu
{
	protected ButtonWidget m_Discord;
	protected ButtonWidget m_Steam;
	protected ButtonWidget m_Facebook;
	protected ButtonWidget m_Twitter;
	protected ButtonWidget m_Reddit;
	protected ButtonWidget m_Youtube;
	protected ButtonWidget m_PayPal;
	protected ButtonWidget m_TikTok;
	protected ButtonWidget m_GitHub;
	protected ButtonWidget m_Instagram;
	protected ButtonWidget m_Twitch;

	protected ImageWidget m_DiscordImage;
	protected ImageWidget m_SteamImage;
	protected ImageWidget m_FacebookImage;
	protected ImageWidget m_Twitterimage;
	protected ImageWidget m_RedditImage;
	protected ImageWidget m_YoutubeImage;
	protected ImageWidget m_PayPalImage;
	protected ImageWidget m_TikTokImage;
	protected ImageWidget m_GitHubImage;
	protected ImageWidget m_InstagramImage;
	protected ImageWidget m_TwitchImage;

	protected TextWidget m_SteamID;
	protected TextWidget m_CustomVersion;
	protected TextWidget m_PlayerInfo;
	protected ImageWidget m_Logotipo;

	protected Widget m_ExitDialog;
	protected ButtonWidget m_Yes;
	protected ButtonWidget m_No;

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Example/gui/layouts/new_ui/main_menu.layout");

		m_Discord = ButtonWidget.Cast(layoutRoot.FindAnyWidget("DiscordButton"));
		m_Steam = ButtonWidget.Cast(layoutRoot.FindAnyWidget("SteamButton"));
		m_Facebook = ButtonWidget.Cast(layoutRoot.FindAnyWidget("FacebookButton"));
		m_Twitter = ButtonWidget.Cast(layoutRoot.FindAnyWidget("TwitterButton"));
		m_Reddit = ButtonWidget.Cast(layoutRoot.FindAnyWidget("RedditButton"));
		m_Youtube = ButtonWidget.Cast(layoutRoot.FindAnyWidget("YoutubeButton"));
		m_PayPal = ButtonWidget.Cast(layoutRoot.FindAnyWidget("PayPalButton"));
		m_TikTok = ButtonWidget.Cast(layoutRoot.FindAnyWidget("TikTokButton"));
		m_GitHub = ButtonWidget.Cast(layoutRoot.FindAnyWidget("GithubButton"));
		m_Instagram = ButtonWidget.Cast(layoutRoot.FindAnyWidget("InstagramButton"));
		m_Twitch = ButtonWidget.Cast(layoutRoot.FindAnyWidget("TwitchButton"));

		m_DiscordImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("DiscordButton_image"));
		m_SteamImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("SteamButton_image"));
		m_FacebookImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("FacebookButton_image"));
		m_Twitterimage = ImageWidget.Cast(layoutRoot.FindAnyWidget("TwitterButton_image"));
		m_RedditImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("RedditButton_image"));
		m_YoutubeImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("YoutubeButton_image"));
		m_PayPalImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("PayPal_image"));
		m_TikTokImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("TikTok_image"));
		m_GitHubImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("Github_image"));
		m_InstagramImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("Instagram_image"));
		m_TwitchImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("Twitch_image"));

		m_SteamID = TextWidget.Cast(layoutRoot.FindAnyWidget("SteamID"));
		m_PlayerInfo = TextWidget.Cast(layoutRoot.FindAnyWidget("PlayerName"));

		m_Yes = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonYes"));
		m_No = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ButtonNo"));
		m_ExitDialog = layoutRoot.FindAnyWidget("ExitPanel");
		
		m_Play = layoutRoot.FindAnyWidget("play");
		m_ChooseServer = layoutRoot.FindAnyWidget("choose_server");
		m_CustomizeCharacter = layoutRoot.FindAnyWidget("customize_character");
		m_PlayVideo = layoutRoot.FindAnyWidget("play_video");
		m_Tutorials = layoutRoot.FindAnyWidget("tutorials");
		m_TutorialButton = layoutRoot.FindAnyWidget("tutorial_button");
		m_MessageButton = layoutRoot.FindAnyWidget("message_button");
		m_SettingsButton = layoutRoot.FindAnyWidget("settings_button");
		m_Exit = layoutRoot.FindAnyWidget("exit_button");
		m_PrevCharacter = layoutRoot.FindAnyWidget("prev_character");
		m_NextCharacter = layoutRoot.FindAnyWidget("next_character");

		m_Version = TextWidget.Cast(layoutRoot.FindAnyWidget("version"));
		m_ModdedWarning = TextWidget.Cast(layoutRoot.FindAnyWidget("ModdedWarning"));
		m_CharacterRotationFrame = layoutRoot.FindAnyWidget("character_rotation_frame");

		m_LastPlayedTooltip = layoutRoot.FindAnyWidget("last_server_info");
		m_LastPlayedTooltip.Show(false);
		m_LastPlayedTooltipLabel = m_LastPlayedTooltip.FindAnyWidget("last_server_info_label");
		m_LastPlayedTooltipName = TextWidget.Cast(m_LastPlayedTooltip.FindAnyWidget("last_server_info_name"));
		m_LastPlayedTooltipIP = TextWidget.Cast(m_LastPlayedTooltip.FindAnyWidget("last_server_info_ip"));
		m_LastPlayedTooltipPort = TextWidget.Cast(m_LastPlayedTooltip.FindAnyWidget("last_server_info_port"));

		m_Logotipo = ImageWidget.Cast(layoutRoot.FindAnyWidget("dayz_logo"));
		m_Logotipo.Show(ShowLogo);
		m_Logotipo.LoadImageFile(0, logotipo);

		m_Discord.Show(DiscordLinkShow);
		m_DiscordImage.LoadImageFile(0, DiscordLinkImage);

		m_Steam.Show(SteamLinkShow);
		m_SteamImage.LoadImageFile(0, SteamLinkImage);

		m_Facebook.Show(FacebookLinkShow);
		m_FacebookImage.LoadImageFile(0, FacebookLinkImage);

		m_Twitter.Show(TwitterLinkShow);
		m_Twitterimage.LoadImageFile(0, TwitterLinkImage);

		m_Reddit.Show(RedditLinkShow);
		m_RedditImage.LoadImageFile(0, RedditLinkImage);

		m_Youtube.Show(YoutubelInkShow);
		m_YoutubeImage.LoadImageFile(0, YoutubeLinkImage);

		m_PayPal.Show(PayPalLinkShow);
		m_PayPalImage.LoadImageFile(0, PayPalLinkImage);

		m_Twitch.Show(TwitchLinkShow);
		m_TwitchImage.LoadImageFile(0, TwitchLinkImage);

		m_Instagram.Show(InstagramLinkShow);
		m_InstagramImage.LoadImageFile(0, InstagramLinkImage);

		m_GitHub.Show(GitHubLinkShow);
		m_GitHubImage.LoadImageFile(0, GitHubLinkImage);

		m_TikTok.Show(TikTokLinkShow);
		m_TikTokImage.LoadImageFile(0, TikTokLinkImage);
	
		m_LastPlayedTooltipTimer = new WidgetFadeTimer();
		m_Stats = new MainMenuStats(layoutRoot.FindAnyWidget("character_stats_root"));
		m_Mission = MissionMainMenu.Cast(GetGame().GetMission());
		m_LastFocusedButton = m_Play;
		m_ScenePC = m_Mission.GetIntroScenePC();
		
		if(m_ScenePC)
		{
			m_ScenePC.ResetIntroCamera();
		};
		
		m_PlayVideo.Show(false);
		m_PlayerName = TextWidget.Cast(layoutRoot.FindAnyWidget("character_name_text"));
		
		string version;
		GetGame().GetVersion(version);
		m_Version.SetText("#main_menu_version" + " " + version);

		GetGame().GetUIManager().ScreenFadeOut(0);

		SetFocus(null);
		Refresh();
		LoadMods();
		GetDayZGame().GetBacklit().MainMenu_OnShow();
	
		g_Game.SetLoadState(DayZLoadState.MAIN_MENU_CONTROLLER_SELECT);

		SteamID64();
		SetPlayerName();	

		return layoutRoot;
	};
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT && w == m_Discord)
		{
			GetGame().OpenURL(DiscordLink);
			return true;
		}
		else if (button == MouseState.LEFT && w == m_Steam)
		{
			GetGame().OpenURL(SteamLink);
			return true;
		}
		else if (button == MouseState.LEFT && w == m_Facebook)
		{
			GetGame().OpenURL(FacebookLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Twitter)
		{
			GetGame().OpenURL(TwitterLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Reddit)
		{
			GetGame().OpenURL(RedditLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Youtube)
		{
			GetGame().OpenURL(YoutubeLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_PayPal)
		{
			GetGame().OpenURL(PayPalLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_TikTok)
		{
			GetGame().OpenURL(TikTokLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_GitHub)
		{
			GetGame().OpenURL(GitHubLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Instagram)
		{
			GetGame().OpenURL(InstagramLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Twitch)
		{
			GetGame().OpenURL(TwitchLink);
			return false;
		}
		else if (w == m_ExitDialog)
		{
			Exit();
			return true;
		}
		else if (w == m_Yes)
		{
			GetGame().RequestExit(1);
			return true;
		}
		else if (w == m_No)
		{
			m_ExitDialog.Show(false);
			return true;
		}

		return super.OnClick(w, x, y, button);
	};

	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if(w == m_Discord)
		{
			m_DiscordImage.LoadImageFile(0, DiscordLinkImage_hover);
		}
		else if (w == m_Steam)
		{
			m_SteamImage.LoadImageFile(0, SteamLinkImage_hover);
		}
		else if (w == m_Facebook)
		{
			m_FacebookImage.LoadImageFile(0, FacebookLinkImage_hover);
		}
		else if (w == m_Twitter)
		{
			m_Twitterimage.LoadImageFile(0, TwitterLinkImage_hover);
		}
		else if (w == m_Reddit)
		{
			m_RedditImage.LoadImageFile(0, RedditLinkImage_hover);
		}
		else if (w == m_Youtube)
		{
			m_YoutubeImage.LoadImageFile(0, YoutubeLinkImage_hover);
		}
		else if (w == m_PayPal)
		{
			m_PayPalImage.LoadImageFile(0, PayPalLinkImage_hover);
		}
		else if (w == m_TikTok)
		{
			m_TikTokImage.LoadImageFile(0, TikTokLinkImage_hover);
		}
		else if (w == m_GitHub)
		{
			m_GitHubImage.LoadImageFile(0, GitHubLinkImage_hover);
		}
		else if (w == m_Twitch)
		{
			m_TwitchImage.LoadImageFile(0, TwitchLinkImage_hover);
		}
		else if (w == m_Instagram)
		{
			m_InstagramImage.LoadImageFile(0, InstagramLinkImage_hover);
		}
		return false;
	};
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if(w == m_Discord)
		{
			m_DiscordImage.LoadImageFile(0, DiscordLinkImage);
		}
		else if (w == m_Steam)
		{
			m_SteamImage.LoadImageFile(0, SteamLinkImage);
		}
		else if (w == m_Facebook)
		{
			m_FacebookImage.LoadImageFile(0, FacebookLinkImage);
		}
		else if (w == m_Twitter)
		{
			m_Twitterimage.LoadImageFile(0, TwitterLinkImage);
		}
		else if (w == m_Reddit)
		{
			m_RedditImage.LoadImageFile(0, RedditLinkImage);
		}
		else if (w == m_Youtube)
		{
			m_YoutubeImage.LoadImageFile(0, YoutubeLinkImage);
		}
		else if (w == m_PayPal)
		{
			m_PayPalImage.LoadImageFile(0, PayPalLinkImage);
		}
		else if (w == m_TikTok)
		{
			m_TikTokImage.LoadImageFile(0, TikTokLinkImage);
		}
		else if (w == m_GitHub)
		{
			m_GitHubImage.LoadImageFile(0, GitHubLinkImage);
		}
		else if (w == m_Twitch)
		{
			m_TwitchImage.LoadImageFile(0, TwitchLinkImage);
		}
		else if (w == m_Instagram)
		{
			m_InstagramImage.LoadImageFile(0, InstagramLinkImage);
		}
		return false;
	};

	override void OnChangeCharacter(bool create_character = true)
	{
		if (m_ScenePC && m_ScenePC.GetIntroCharacter())
		{
			int charID = m_ScenePC.GetIntroCharacter().GetCharacterID();
			if (create_character)
			{
				m_ScenePC.GetIntroCharacter().CreateNewCharacterById(charID);
			}
			
			Widget w = m_CustomizeCharacter.FindAnyWidget(m_CustomizeCharacter.GetName() + "_label");
			
			if (w)
			{
				TextWidget text = TextWidget.Cast(w);
				
				if(m_ScenePC.GetIntroCharacter().IsDefaultCharacter())
				{
					text.SetText("#th_character");
				}
				else
				{
					text.SetText("#th_character");
				}
			}
			if (m_ScenePC.GetIntroCharacter().GetCharacterObj())
			{
				if (m_ScenePC.GetIntroCharacter().GetCharacterObj().IsMale())
					m_ScenePC.GetIntroCharacter().SetCharacterGender(ECharGender.Male);
				else
					m_ScenePC.GetIntroCharacter().SetCharacterGender(ECharGender.Female);
			}
			
			//update character stats
			m_Stats.UpdateStats();
		};
	};

	override void ColorHighlight(Widget w)
	{
		if(!w)
			return;
		
		
		int color_pnl = ARGB(255, 0, 0, 0);
		int color_lbl = UIColor;
		int color_img = ARGB(255, 255, 255, 255);;
		
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);
	};

	void SteamID64()
	{
	    if (GetGame().GetUserManager() && GetGame().GetUserManager().GetTitleInitiator()){
	        string player_id = GetGame().GetUserManager().GetTitleInitiator().GetUid();
	        m_SteamID.SetText(player_id);
	    };
	};

	void SetPlayerName()
	{
		if (m_PlayerName)
		{
			string name;
			GetCLIParam("name", name);
			if (!name) name = "Survivor";

			m_PlayerName.SetText("Welcome Back, " + name);
			m_PlayerInfo.SetText(name);
		};
	};

	override void Exit() 
	{
		m_ExitDialog.Show(true);
	};
};
