/**
* KeybindingsMenu.c 
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

modded class KeybindingsMenu extends UIScriptedMenu
{
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Example/gui/layouts/new_ui/options/pc/keybinding_menu.layout", null);
		
		m_Version = TextWidget.Cast(layoutRoot.FindAnyWidget("version"));
		m_Apply = ButtonWidget.Cast(layoutRoot.FindAnyWidget("apply"));
		m_Back = ButtonWidget.Cast(layoutRoot.FindAnyWidget("back"));
		m_Undo = ButtonWidget.Cast(layoutRoot.FindAnyWidget("reset"));
		m_Defaults = ButtonWidget.Cast(layoutRoot.FindAnyWidget("defaults"));
		
		m_Tabs = new array<ref KeybindingsGroup>;
		layoutRoot.FindAnyWidget("Tabber").GetScript(m_Tabber);
		
		string version;
		GetGame().GetVersion(version);
		version = "#main_menu_version" + " " + version;
		m_Version.SetText(version);

		Input input	= GetGame().GetInput();
		int group_count = input.GetActionGroupsCount();
		
		for(int i = 0; i < group_count; i++)
		{
			AddGroup(i, input);
		}
		
		m_Tabber.SelectTabControl(0);
		m_Tabber.SelectTabPanel(0);
		g_Game.SetKeyboardHandle(this);
		
		ColorDisabled(m_Apply);
		m_Apply.SetFlags(WidgetFlags.IGNOREPOINTER);
		ColorDisabled(m_Undo);
		m_Undo.SetFlags(WidgetFlags.IGNOREPOINTER);
		ColorWhite(m_Defaults, null);
		m_Defaults.ClearFlags(WidgetFlags.IGNOREPOINTER);
		
		return layoutRoot;
	};

	override bool OnMouseEnter(Widget w, int x, int y)
	{
	    ColorHighlight (w);
	    return true;
	}

	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
	    ColorNormal (w);
	    return true;
	}

	protected void ColorHighlight(Widget w)
	{
	    if (!w)
	        return;

	    ButtonSetColor(w, ARGB(0, 0, 0, 0));
	    ButtonSetTextColor(w, UIColor);
	};

	protected void ColorNormal(Widget w)
	{
	    if (!w)
	        return;

	    ButtonSetColor(w, ARGB(0, 0, 0, 0));
	    ButtonSetTextColor(w, ARGB(255, 255, 255, 255));
	};

	protected void ButtonSetColor(Widget w, int color)
	{
	    if (!w)
	        return;
	            
	    Widget panel = w.FindWidget(w.GetName() + "_panel");

	    if (panel)
	    {
	        panel.SetColor(color);
	    };
	};

	protected void ButtonSetTextColor(Widget w, int color)
	{
	    if (!w)
	        return;

	    TextWidget label = TextWidget.Cast(w.FindAnyWidget(w.GetName() + "_label"));
	                    
	    if (label)
	    {
	        label.SetColor(color);
	    };
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
