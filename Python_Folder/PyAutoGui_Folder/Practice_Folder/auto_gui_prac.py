"""
Python file made to further build upon the skills acquired in AutoGuiPrac.py,
Oargparc.py and Pargprac.py files as well general Python coding skills and proper style.
"""

import argparse as ap
import pyautogui as pyag
import AutoGuiPrac as agpr
# YT and STOF website searchbar at position (394,163)

pyag.PAUSE = 1.5

def parse():
    parser = ap.ArgumentParser()

    parser.add_argument("site", help="Website name that user wants to be directed to.")
    parser.add_argument("command", help="Action that the program will take depending on the site it visits.",
    choices=["search", "check", "subscriptions"])
    parser.add_argument("--text", help="Text that the programs inputs should the user choose the 'search' command.")

    args = parser.parse_args()
    return args.site.lower() + ".com", args.command, args.text

def navigate(ste):
        agpr.gotochrome()
        pyag.hotkey("command", "t")
        pyag.hotkey("command", "l")
        pyag.typewrite(ste)
        pyag.typewrite(["enter"])

def execute(ste, cmd, txt):
    if cmd == "search":
        search(ste, txt)
    elif cmd == "check":
        pyag.click(715,450)
    elif cmd == "subscriptions" and ste == "youtube.com":
        pyag.click(100, 307)

def search(ste, txt):
    if txt is not None:
        if ste in ("youtube.com", "stackoverflow.com"):
            pyag.click(394,163)
            pyag.typewrite(txt)
            pyag.typewrite(["enter"])
        else:
            pyag.typewrite(txt)
            pyag.typewrite(["enter"])

""" class Automate:
    def __init__(self, ste, cmd, *txt):
        self.site = ste
        self.cmd = cmd
        self.text = txt

    def navigate(self, ste):
        agpr.gotochrome()
        pyag.hotkey("command", "t")
        pyag.hotkey("command", "l")
        pyag.typewrite(ste)
        pyag.typewrite(["enter"])

    def execute(self, ste, cmd, txt):
        if cmd == "search":
            Automate(ste,cmd,txt).search(ste, txt)
        elif cmd == "check":
            pyag.click(715,450)
        elif cmd == "subscriptions" and ste == "youtube.com":
            pyag.click(100, 307)

    def search(self, ste, txt):
        if txt is not None:
            if ste in ("youtube.com", "stackoverflow.com"):
                pyag.click(394,163)
                pyag.typewrite(txt)
                pyag.typewrite(["enter"])
            else:
                pyag.typewrite(txt)
                pyag.typewrite(["enter"]) """

def main():
    ste, cmd, txt = parse()
    navigate(ste)
    execute(ste, cmd, txt)
    """ task = Automate(ste, cmd, txt)
    task.navigate(task.site)
    task.execute(task.site, task.cmd, task.text) """
    

if __name__ == '__main__':
    main()
        