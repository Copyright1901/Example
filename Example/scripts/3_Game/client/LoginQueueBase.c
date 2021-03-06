/**
* LoginQueueBase.c 
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

modded class LoginQueueBase extends UIScriptedMenu
{
	private TextWidget m_RandomMessage;
	private TextWidget m_txtlabel;

	override Widget Init()
	{		
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Example/gui/layouts/dialog_queue_position.layout");
		
		m_txtPosition = TextWidget.Cast(layoutRoot.FindAnyWidget("txtPosition"));
		m_txtlabel = TextWidget.Cast(layoutRoot.FindAnyWidget("txtlabel"));
		m_txtNote = TextWidget.Cast(layoutRoot.FindAnyWidget("txtNote"));
		m_btnLeave = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnLeave"));
		m_txtNote.Show(true);
		layoutRoot.FindAnyWidget("notification_root").Show(false);

        ImageWidget background = ImageWidget.Cast(layoutRoot.FindAnyWidget("Background"));
        background.LoadImageFile(0, QueueGame.GetRandomElement());  

		//Message Random
		if(ShowMessage)
		{
			m_RandomMessage = TextWidget.Cast(layoutRoot.FindAnyWidget("RandomText"));
			m_RandomMessage.SetText(RandomMessage.GetRandomElement());
			m_RandomMessage.SetColor(UIColorText);
			m_RandomMessage.Show(true);
		};

		//Add Color to some text.
		m_txtlabel.SetColor(UIColorText);

		return layoutRoot;
	};
};
