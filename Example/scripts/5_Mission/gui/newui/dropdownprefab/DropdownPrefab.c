/**
* DropdownPrefab.c 
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

modded class DropdownPrefab extends ScriptedWidgetEventHandler
{
	int AddElement(string text, Widget content = null)
	{
		ButtonWidget element = ButtonWidget.Cast(GetGame().GetWorkspace().CreateWidgets("Example/gui/layouts/new_ui/dropdown_prefab/dropdown_element.layout", m_ContentContainer));
		element.SetText(text);
		
		if(content)
		{
			element.AddChild(content, false);
		}
		m_ContentContainer.Update();
		m_Root.Update();
		
		m_Content.Insert(element);
		return m_Content.Count() - 1;
	};
};
