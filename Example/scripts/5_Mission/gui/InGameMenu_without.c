/**
* InGameMenu.c 
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

/*
modded class InGameMenu extends UIScriptedMenu
{
	protected Widget m_Painel;
	protected ButtonWidget m_Discord;
	
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Example/gui/layouts/day_z_ingamemenu_without.layout");
				
		m_ContinueButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("continuebtn"));
		m_ExitButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("exitbtn"));
		m_RestartButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("restartbtn"));
		m_RespawnButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("respawn_button"));
		m_RestartDeadRandomButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("respawn_button_random"));
		m_RestartDeadCustomButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("respawn_button_custom"));
		m_OptionsButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("optionsbtn"));
		m_ModdedWarning = TextWidget.Cast(layoutRoot.FindAnyWidget("ModdedWarning"));
		m_HintPanel = new UiHintPanel(layoutRoot.FindAnyWidget("hint_frame"));
		m_ServerInfoPanel = layoutRoot.FindAnyWidget("server_info");
		m_ServerIP = TextWidget.Cast(layoutRoot.FindAnyWidget("server_ip"));
		m_ServerPort = TextWidget.Cast(layoutRoot.FindAnyWidget("server_port"));
		m_ServerName = TextWidget.Cast(layoutRoot.FindAnyWidget("server_name"));
		m_FavoriteImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("favorite_image"));
		m_UnfavoriteImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("unfavorite_image"));
		m_CopyInfoButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("copy_button"));
		
		m_Painel = layoutRoot.FindAnyWidget("painelbtn");
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

		#ifdef SERVERPANEL
			m_Painel.Show(true);
		#else
			m_Painel.Show(false);
		#endif

		if (GetGame().IsMultiplayer())
		{
			ButtonSetText(m_RestartButton, "#main_menu_respawn");
		}
		else
		{
			ButtonSetText(m_RestartButton, "#main_menu_restart");
		}		
		
		HudShow(false);
		SetGameVersion();
		SetServerInfoVisibility(SetServerInfo() && g_Game.GetProfileOption(EDayZProfilesOptions.SERVERINFO_DISPLAY));
		m_ModdedWarning.Show(g_Game.ReportModded());
		
		return layoutRoot;
	};

	protected void ColorHighlight(Widget w)
    {
        if (!w)
            return;

        ButtonSetTextColor(w, UIColor);
    };

	override void OnShow()
    {
        super.OnShow();
        PPEffects.SetBlurInventory(0.3);
    };

    override void OnHide()
    {
        super.OnHide();
        PPEffects.SetBlurInventory(0);
    };

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);

		if (w == m_Discord)
		{
			GetGame().OpenURL(DiscordLink);
			return true;
		}
		#ifdef SERVERPANEL
		else if (w == m_Painel)
		{
			EnterScriptedMenu(SERVER_PANEL);
			return true;
		}
		#endif
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
		return false;
	};

	override bool OnMouseEnter(Widget w, int x, int y)
	{
		ColorHighlight(w);

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
		ColorNormal(w);

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
};