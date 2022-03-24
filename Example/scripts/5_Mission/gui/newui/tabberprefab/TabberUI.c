/**
* TabberUI.c 
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

modded class TabberUI extends ScriptedWidgetEventHandler
{
	override void SelectTabControl(int index)
	{
		Widget tab_control = m_TabControls.Get(index);
		if(tab_control)
		{
			Widget tab_title = TextWidget.Cast(tab_control.FindAnyWidget(tab_control.GetName() + "_Title"));
			
			int color_title = UIColor;
			int color_backg = ARGB(255, 0, 0 ,0);
			
			tab_title.SetColor(color_title);
			tab_control.SetColor(color_backg);
		};
	};

	override bool OnMouseEnter(Widget w, int x, int y)
	{
		int index = m_TabControls.GetKeyByValue(w);
		if(m_SelectedIndex == index)
		{
			return false;
		}
		
		Widget tab_control = m_TabControls.Get(index);
		if(tab_control)
		{			
			Widget tab_title = TextWidget.Cast(tab_control.FindAnyWidget(tab_control.GetName() + "_Title"));
			tab_title.SetColor(UIColor);
			tab_control.SetColor(ARGB(255, 0, 0 ,0));
		};
		
		return false;
	};
};