=begin
CommonMults by Joseph
This Ruby program asks the user for four number inputs, the first two being the numbers that it finds common
multiples for and the second two being how many multiples of the first two numbers you want to generate. After 
the user picks their four numbers, the program converts them to integers, adds the first two numbers to 
separate arrays, and sets two new variables equal to the first two numbers. The program then runs two separate 
for loops using the last two user numbers as the upper bound in the loops' ranges to generate two arrays of 
the multiples of the first two numbers and then prints them. Finally a third array is creating using the &
operator that contains only the numbers found in both of the other two arrays. 
=end

puts "Ok give me two numbers that you want to find common multiples of."
a = gets.chomp
b = gets.chomp

puts "Now how many multiples of each number do you want to generate?"
c = gets.chomp
d = gets.chomp

puts "So your first number is #{a}, generating #{c} multiples, and your second number is #{b}, generating #{d} multiples? Alright noted!"
print "\n"
a1 = a.to_i()
b1 = b.to_i()
c1 = c.to_i()
d1 = d.to_i()
arr1 = [a1] 
arr2 = [b1]
e = a1
f = b1

for i in (1...c1)
    e += a1
    arr1 << e 
end
puts "Here is an array for the first #{c1} multiples of #{a1}:"
print arr1
print "\n"
print "\n"

for j in (1...d1)
    f += b1
    arr2 << f
end
puts "Here is an array for the first #{d1} multiples of #{b1}:"
print arr2
print "\n" 
print "\n"

arr3 = arr1 & arr2
puts "And here is an array of their common multiple(s):"
print arr3
print "\n"