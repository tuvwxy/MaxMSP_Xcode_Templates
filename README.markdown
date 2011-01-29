Xcode Project Templates for Building Max/MSP Externals
======================================================

Prerequisites
-------------

1.  Download Max5 SDK from <http://cycling74.com/products/sdk/>
2.  Copy the frameworks `MaxAPI.framework` and `MaxAudioAPI.framework` to `/Library/Frameworks`. You can find `MaxAPI.framework` in `c74support/max-includes` and `MaxAudioAPI.framework` in `c74support/msp-includes`.

Installation
------------

Copy the `MaxMSP` folder to `/Library/Application Support/Developer/Shared/Xcode/Project Templates/` or `~/Library/Application Support/Developer/Shared/Xcode/Project Templates/`. You will need to create the directories if they don't exist. 

How to use the templates
------------------------

1.  Open Xcode and create a new project. (Cmd-Shift-N)
2.  On the left side of the window, you should see "User Templates" and "MaxMSP" underneath. Select it.
3.  You have four options: `Max C External`, `MSP C External`, `Max C++ Extneral`, or `MSP C++ External`. Pick the appropriate template depending on your language preference and external type. If you are designing an audio signal processing object, choose one of the MSP externals.
4.  Type in the project name. ***Important***: project name should be *exactly* the same as the object name. For MSP objects, you should postfix the name with "~", e.g. "filter~".
5.  The project should compile as is. (Cmd-B)
6.  Once the code compile, you're ready to make your external!
