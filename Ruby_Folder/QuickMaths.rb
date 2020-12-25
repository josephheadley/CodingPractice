=begin
QuickMaths by Joseph
This code is practice with some of the basic features of Ruby such as the gets method, integer and string 
conversion methods, and if-else and case statements. This code can essentially serve as a glorified simple
calculator of sorts.
=end

puts "Alright so what two numbers do you want to use?"
a = gets.chomp 
b = gets.chomp

puts "So your first number is #{a} and your second number is #{b}? Ok noted!" 
a = a.to_i()
b = b.to_i()
sum = (a+b).to_s()
difference = (a-b).to_s()
product = (a*b).to_s() 
exponent = (a**b).to_s()
if a > b
    quotient = (a/b).to_s()
    remainder = (a%b).to_s()
elsif a < b
    quotient = (b/a).to_s()
    remainder = (b%a).to_s()
else
    quotient = (a/b).to_s()
    remainder = (a%b).to_s() 
end

puts "Well what do you want to know about these numbers? Their sum (s), their difference (d), their product (p), their quotient (q), or their exponentiation (e)?"
response = gets.chomp
case response
when "s"
    puts "Sum: #{sum}"
when "d"
    puts "Difference: #{difference}"
when "p"
    puts "Product: #{product}"
when "q"
    puts "Quotient: #{quotient} & Remainder: #{remainder}"
when "e"
    puts "Exponentiation: #{exponent}"
else
    puts "Come back to me when you actually want to do some quick maths." 
end