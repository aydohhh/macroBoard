README
-steps to compile and flash firmware-

1. in the following directory:
	qmk_firmware/keboards/planck/keymaps/macros
	edit the keymap.c file

2. compile with this command, back in the qmk_firmware dir:
	make planck/rev6:macros
	- takes a long ass time for some reason

3. Put planck into boot mode (reset button on back)

4. Open QMK toolbox
	go into .build (the dir where there the *bin file is)
	click flash


planck makes little noise when flashed.



-Testing compiled c code on windows-

1. launch visual studio installer for the build tools command prompt
2. > notepad test.c
	- edit the file
3. dir is ls
4. >cl test.c  #compiles
5. >test  	#runs



-Autohotkey-
edit the file with vim
https://www.autohotkey.com/docs/v2/Hotkeys.htm
double click on the file after editing to 'run' it shows up in the task tray
menu thing

this is what points to the python scripts
