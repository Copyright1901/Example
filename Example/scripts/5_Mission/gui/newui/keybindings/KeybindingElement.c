/**
* KeybindingElement.c 
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

modded class KeybindingElement extends ScriptedWidgetEventHandler
{
	string GetLayoutName()
	{
		return "Example/gui/layouts/new_ui/options/keybindings_selectors/keybinding_option.layout";
	}

	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if(w == m_PrimaryBindButton || w == m_PrimaryClear)
		{
			m_PrimaryBindButton.SetColor(UIColor);
			m_PrimaryClear.Show(true);
			m_PrimaryClear.Update();
			m_AlternativeClear.Show(false);
			return true;
		}
		else if(w == m_AlternativeBindButton || w == m_AlternativeClear)
		{
			m_AlternativeBindButton.SetColor(UIColor);
			m_PrimaryClear.Show(false);
			m_AlternativeClear.Show(true);
			m_AlternativeClear.Update();
			return true;
		}
		else
		{
			m_PrimaryBindButton.SetColor(ARGB(255,255,255,255));
			m_AlternativeBindButton.SetColor(ARGB(255,255,255,255));
			m_PrimaryClear.Show(false);
			m_AlternativeClear.Show(false);
		}
		return false;
	};
};
