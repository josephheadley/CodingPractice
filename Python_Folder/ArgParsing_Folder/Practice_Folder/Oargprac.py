import argparse

"""
The two types of arguments one can add to a parser are the positional arguments and the optional arguments.
The dashes in front of the first argument in the add_argument function indicate these arguments are optional arguments.
Whereas the absence of said dashes in front of those arguments would indicate them as positional arguments.

Positional arguments are recognized by the position in which you attribute their argument. 
In other words, the value you ascribe to an argument is inferred based on the order through which you feed its arguments.
Furthermore you cannot skip/exclude positional arguments. All positional arguments must be used.

Optional arguments, on the other hand, rely upon explicit calls to assign its arguments and not on position.
Also unlike positional arguments since optional arguments are not inferred arguments you can place these arguments in any order or even skip arguments.

For example in this program you can run it as such:
argprac.py --number2 4 --number1 20
The above format rearranges the number order and excludes the operation argument entirely.

Lastly, the choices parameter in the last "add_argument" statement restricts the user to inputing just the strings shown in the list passed to the choices parameter.
"""

parser = argparse.ArgumentParser()
parser.add_argument("--number1", help="first number")
parser.add_argument("--number2", help="second number")
parser.add_argument("--operation", help="operation", choices=["add","subtract","multiply"])

args = parser.parse_args() 

print(args.number1)
print(args.number2)
print(args.operation) 

n1 = int(args.number1)
n2 = int(args.number2)
result = None

if args.operation == "add":
    result = n1+n2
elif args.operation == "subtract":
    result = n1-n2
elif args.operation == "multiply":
    result = n1*n2
else:
    result = "unsupported operation"

print(result)