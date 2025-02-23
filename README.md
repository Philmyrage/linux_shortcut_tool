# Overview
The application will be a simple CLI application that will take the executable and generate a .desktop file in either the global or user home directory for .desktop files on Ubuntu its $HOME/.local/share/applications for user only or /usr/share/applications for global desktop apps

# Edge cases

if the application is passed the -g command and the executable is installed in the home directory throw an error.

if the -g is not given, default to the home directory for .desktop files.

if no commands are passed generate to some defaults with just the executable passed as argument.

essentially the only required thing passed should be the executable, it can be passed from it's directory and use the file system to get its path for the .desktop file or can be passed as a path.

using the file system validate it exist's and give feedback if it doesn't.

# Commands

[Global] -g: will create the .desktop file globally for every account on the machine\
[Image] -img: path to the icon\
[Terminal] -te: should this application launch with a console?\
[Comment] -c: give a comment\
[Type] -typ: give the type for this shortcut\
# Future plans

also add a GUI at some point, but I want a deeper understanding of CLI applications and tools.

Add in the GUI interface a way to manage .desktop files, and open them with a user specific editor, such as vscode or neovim
