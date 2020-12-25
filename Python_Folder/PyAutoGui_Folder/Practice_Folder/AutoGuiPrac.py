"""
Python program for learning the basics of the pyautogui module
and practicing how to write clean and efficient Python code.

- Note: Save files in snake case from now on.
"""

import pyautogui as pyag

#print(pyag.position()) //function that prints out the current coordiate position of the mouse
#(141,85) //function output for coordinate position of Google Chrome search bar
#when browser is full screen


def gotomychrome():
    """
    This function opens a Chrome browser, through the use of my Macbook dock and a user specified
    keyboard shortcut and as such is customized for my specific Macbook setup to open a Chrome
    browser.
    """
    pyag.hotkey("option", "2")
    pyag.typewrite(["tab"])
    pyag.typewrite(["enter"])

def returndockspot():
    """
    This function returns the dock cursor to its initial position starting at the finder
    to ensure this program's reusability.
    """
    pyag.hotkey("option", "2")
    pyag.hotkey("shift", "tab")
    pyag.typewrite(["esc"])

def gotochrome():
    """This function opens a Chrome browser, through the use of Spotlight Search"""
    pyag.hotkey("command", "space")
    pyag.typewrite("Chrome")
    pyag.typewrite(["enter"])

def copyurl():
    """
    This function c̶l̶i̶c̶k̶s̶ o̶n̶ navigates to the search bar of an open Google Chrome browser
    and copies the current link in the search bar.
    """
    #pyag.click(141,85) -Mouse Implementation, unnecessary as depending on the browser orientation
    #might become inaccurate, kept in script as comment to remind myself of its usage
    pyag.hotkey("command", "l")
    pyag.hotkey("command", "c")

def getsearchbar():
    """
    This function creates a new tab in the Google Chrome browser and again c̶l̶i̶c̶k̶s̶ o̶n̶
    navigates to the search bar.
    """
    pyag.hotkey("command", "t")
    pyag.hotkey("command", "l")
    #pyag.click(141,85)

def pasteurl():
    """
    This function pastes the previously copied url link in the search bar and "presses enter"
    to execute a search in the search bar of the Chrome browser.
    """
    pyag.hotkey("command", "v")
    pyag.typewrite(["enter"])

def main():
    """This function is a main method which executes all the functions above."""
    #gotoMYChrome()
    #returndockspot()
    gotochrome()
    copyurl()
    getsearchbar()
    pasteurl()

if __name__ == '__main__':
    main()
