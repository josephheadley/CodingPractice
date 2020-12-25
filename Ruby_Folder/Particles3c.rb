K = 9*10**9
G = 6.67*10**-11
require "ostruct"

Electron = OpenStruct.new(name:"electron", charge:-1.6*10**-19, mass_kg:9.1*10**-31)
Electron.mass_eV = 500000
f1 = File.new("electron.txt", "w")
f1.puts("The #{Electron.name} is a negatively charged particle of #{Electron.charge} volts with a mass of #{Electron.mass_kg} kilograms (or #{Electron.mass_eV} electron volts).")
f1.close

Proton = OpenStruct.new(name:"proton", charge:1.6*10**-19, mass_kg:1.7*10**-27)
Proton.mass_eV = 938000000
f2 = File.new("proton.txt", "w")
f2.puts("The #{Proton.name} is a positively charged particle of #{Proton.charge} volts with a mass of #{Proton.mass_kg} kilograms (or #{Proton.mass_eV} electron volts).")
f2.close

Neutron = OpenStruct.new(name:"neutron", charge:0, mass_kg:1.7*10**-27)
Neutron.mass_eV = 939000000
f3 = File.new("neutron.txt", "w")
f3.puts("The #{Neutron.name} is a neutrally charged particle of #{Neutron.charge} volts with a mass of #{Neutron.mass_kg} kilograms (or #{Neutron.mass_eV} electron volts).")
f3.close

puts File.read("electron.txt")
print "\n"
puts File.read("proton.txt")
print "\n"
puts File.read("neutron.txt")
print "\n"

print "Please input the distance between the two selected particles: "
distance = gets.chomp.to_i()
print "\n"
eforce = lambda {puts (K*Electron.charge*Proton.charge)/distance**2}
#eforce = ->() {puts (G*Electron.charge*Proton.charge)/distance**2}
gforce = lambda {puts (G*Electron.mass_kg*Proton.mass_kg)/distance**2}

puts "This is the amount of electrical force, in Newtons, exerted between a proton and an electron at a distance of #{distance} meters:"
eforce.call
puts "This is the amount of gravitational force, in Newtons, exerted between a proton and an electron at a distance of #{distance} meters:"
gforce.call
print "\n"

File.open("electron.txt", "a+"){
    |file| file.puts("Apparently for a particle this small the force due to electromagnetism is much larger than the force due to gravity")
}
File.open("proton.txt", "a+"){
    |file| file.puts("Apparently for a particle this small the force due to electromagnetism is much larger than the force due to gravity")
}
puts File.read("electron.txt")
print "\n"
puts File.read("proton.txt")
print "\n"