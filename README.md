# Important update
KJ tries to prohibit the use of automation tools with THUD integration. So no warranty that this will last.
This is just a bad workaround which i happened to find. This will most likely break once THUD update is necessary.
Also Sader macro has been added. Use with ForceMove on Mousewheel for decent animation cancelling.
Credits go to [ZyRaNex](https://github.com/ZyRaNex/) for creating this piece of software!

# ZyHelper
This programm automates button presses. \
Download at
[ZyHelperBeta](https://github.com/ZyRaNex/ZyHelper/releases) 

If you have questions, ask on Zy's [Discord](https://discord.gg/F8wcvzd), or me patrick#2194

![ZyHelperBeta](https://i.imgur.com/rXbsHQW.png)

# Install
Put the ZyHelperBetaAdapter.cs file into \th\plugins\Zy in your TurboHUD folder and the .exe somewhere else.

Start Zyhelper then start TurboHUD (You always have to start them in this order).

# How to use:

Per skill there are 2 Boxes:\
The Enabled Checkbox which enables/disables the skill.\
Note that the skill wont get casted if its not equipped.\
The Hotkey Field which contains the hotkey thats going to get pressed by the program.\
Here '1-9' 'a-z' mean their respective letters, while 'R' / 'L' mean the left / right mouse button.\
For force stand still the additional hotkeys "shift", "alt" and "space" work.\
The Nacro has some additional features:\
'Second Sim' makes sim and land cast after 10-20 seconds so there is always a sim active if you play in a party.\
Hexing Pants makes you move around while idle to always keep them up. For this you need Forcemove bound to Mouse3 (pressing the mousewheel).

# Wiz macro:

Now has custom delay. No implemented in config though.
There are 3 hotkeys you need to use:

- Macro button:
It presses electrocute -> meteor -> channel -> archon.\
So, if you want to shoot meteors, you hold down this button.

- Channelling button:
This one presses Ray of Frost in a way that it doesn't fuck up the macro.\
So, if you want to channel to generate / proc zodiac, you hold this button.\
But for example, if you get wormholed, you can release this button, walk back and the resume holding it.

So, in a normal rotation, you start holding the channeling key and the macro key when you're almost out of archon, then it should do the macro till you're back in Archon.\
If you get wormholed and have enough cdr to miss some zodiac procs, you let go of the channelling hotkey while still holding the macro key, move back into the pull and then resume holding the channelling key.

- Oculus button:
When you spawn an oculus with the first meteor you can save the position of the oculus by pressing the oculus key while pointing at it.\
if you have done that, the macro will walk into the oculus after shooting the arcane meteor.\
For this to work you need to set the 'Force move hotkey' to your forcemove key.

# Sader macro:

Sader macro is pretty straight forward. This automates the sader BK.\

It keeps up your Fist of Heavens stacks and casts Heavens Fury when macro key is held down.\
It always casts judgment/shield glare before the holy COE. For speeds, cast manually when engaging pack.\


# other stuff 
The source code is open source under the Apache License 2.0 at [ZyHelperBeta](https://github.com/ZyRaNex/ZyHelper) \
Press F10 to pause the helper entirely (turns off all autocasts and disables the mage macro). You can press F10 again to resume.\
You can donate if you want at:

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=X3F8VW4Q54LX4)
