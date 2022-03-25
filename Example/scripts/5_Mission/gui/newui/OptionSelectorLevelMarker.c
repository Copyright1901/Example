/**
* OptionSelectorLevelMarker.c 
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

modded class OptionSelectorLevelMarker extends OptionSelectorSliderSetup
{
	void OptionSelectorLevelMarker(Widget parent, float value, ScriptedWidgetEventHandler parentMenu, bool disabled, float min, float max)
	{
		m_Slider.SetColor(UIColor);
		m_Slider2.SetColor(ARGB(255,0,0,0));
	};

	override bool OnMouseEnter(Widget w, int x, int y)
	{
		m_Slider.SetColor(UIColor);
		m_Slider2.SetColor(ARGB(255,0,0,0));
		
		return true;
	};

	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		m_Slider.SetColor(UIColor);
		m_Slider2.SetColor(ARGB(255,0,0,0));
			
		return true;
	};
};
